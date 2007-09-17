/********************************************************************
 *   		utils.cpp
 *   Created on Mon May 22 2006 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include <misc_utils.h>

#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <ext/stdio_filebuf.h>

#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <errno.h>

// FeedbackError E_UTILS_PIPE("Failed to create pipe");
DEFINE_FEEDBACK_ERROR(E_UTILS_PIPE, "Failed to create pipe")
// FeedbackError E_UTILS_CREATE("Failed to launch and/connect to child process");
DEFINE_FEEDBACK_ERROR(E_UTILS_CREATE, "Failed to launch and/connect to child process")
// FeedbackError E_UTILS_FD("Failed assing unix file descriptor to stl stream");
DEFINE_FEEDBACK_ERROR(E_UTILS_FD, "Failed assing unix file descriptor to stl stream")

typedef __gnu_cxx::stdio_filebuf<char> TFileBuf;

/********************************************************************
 *   This is a nasty hack, but we need to assign the fd to the
 *   currently open stream.  There is apparently no support for this
 *   in the standard.  It probably leaks memory too... but we need to
 *   allocate, otherwise the buffer will go out of scope and be
 *   destroyed.
 *******************************************************************/
template<class STR> int
ReplaceStreamFd_int(STR &s, int nFd, std::ios_base::openmode m)
{
  Feedback fb("ReplaceStreamFd utility routine");

  typename STR::__streambuf_type *pBufOrig = s.std::basic_ios<char>::rdbuf();
  TFileBuf *pFilebufOrig = dynamic_cast<TFileBuf*>(pBufOrig);
  if (pFilebufOrig)
  {
    int nFdOrig = pFilebufOrig->fd();
    fb.Info(3) << "Closing original file descriptor " << nFdOrig << " for stream " << pFilebufOrig << ".";
    close(nFdOrig);
  }
//     return fb.Error(E_UTILS_FD) << ", couldn't get file buffer.";

  TFileBuf *pBufNew = new TFileBuf(nFd, m);
  s.std::basic_ios<char>::rdbuf (pBufNew);

      // This delete causes segmentation fault.  ..not so good.
//   if (pBufOrig)
//     delete pBufOrig;

  return 0;
}


int
ReplaceStreamFd(std::istream &s, int nFd)
{
  return ReplaceStreamFd_int<std::istream>(s, nFd, std::ios_base::in);
}


int
ReplaceStreamFd(std::ostream &s, int nFd)
{
  return ReplaceStreamFd_int<std::ostream>(s, nFd, std::ios_base::out);
}


int
ReplaceStreamFd(std::istream &is, std::ostream &os, int *pFds)
{
  if (int nRet = ReplaceStreamFd(is, pFds[0]))
    return nRet;
  return ReplaceStreamFd(os, pFds[1]);
}


int
CreatePipe(int *fildes)
{
  Feedback fb("CreatePipe utility routine");

  if (!fildes)
    return fb.Error(E_UTILS_PIPE) << ". No storage for pipe file descriptors provided.";

  if (pipe(fildes))
  {
    std::string sErrMsg = strerror(errno);
    return fb.Error(E_UTILS_PIPE) << ". System error message: " << sErrMsg << ".";
  }

  return 0;
}
  

int
CreateArgumentVector(const std::string &sArgLine, std::vector<std::string> &argv)
{
  std::stringstream ssArgs(sArgLine);
  while (!ssArgs.eof())
  {
    std::string sArg;
    ssArgs >> sArg;
    argv.push_back(sArg);
  }
  return 0;
}


int 
ConnectProcess(const std::string &sFile, const std::string &sArgs, 
                   std::istream *pRead, std::ostream *pWrite, std::istream *pError,
                   pid_t *pChildPid, int *pnFileDescriptors)
{
  Feedback fb("ConnectProcess utility routine");
  std::vector<std::string> argVec;
  if (CreateArgumentVector(sArgs, argVec))
    return fb.Error(E_UTILS_CREATE) << ": Failed to parse child process argument line.";
  argVec.insert(argVec.begin(), sFile);
  return ConnectProcess(argVec, pRead, pWrite, pError, pChildPid, pnFileDescriptors);
}


int 
ConnectProcess(const std::vector<std::string> &argVec, 
               std::istream *pRead, std::ostream *pWrite, std::istream *pError,
               pid_t *pChildPid, int *pnFileDescriptors)
{
  Feedback fb("ConnectProcess utility routine");
  
  int nChildStdIn[2], nChildStdOut[2], nChildStdErr[2];
  
  if (CreatePipe(nChildStdIn) 
      || CreatePipe(nChildStdOut)
      || CreatePipe(nChildStdErr))
    return fb.Error(E_UTILS_CREATE) << ": Unable to establish communication channel with child process.";
  
  pid_t nPid = fork();
  if (pChildPid && nPid)
    *pChildPid = nPid;

  if (nPid == -1)
    return fb.Error(E_UTILS_CREATE) << ": Failed to fork. System error message: " << strerror(errno) << ".";

  if (nPid)
  {
    if (pRead)
      ReplaceStreamFd(*pRead, nChildStdOut[0]);
    else
      close(nChildStdOut[0]);

    if (pWrite)
      ReplaceStreamFd(*pWrite, nChildStdIn[1]);
    else
      close(nChildStdIn[1]);

    if (pError)
      ReplaceStreamFd(*pError, nChildStdErr[0]);
    else
      close(nChildStdErr[0]);

    close(nChildStdIn[0]);
    close(nChildStdOut[1]);
    close(nChildStdErr[1]);
  }
  else
  {
    if ((pRead && dup2(nChildStdIn[0], 0) == -1)
        || (pWrite && dup2(nChildStdOut[1], 1) == -1)
        || (pError && dup2(nChildStdErr[1], 2) == -1))
      return fb.Error(E_UTILS_CREATE) << ": Failed to connect pipes for I/O communication "
                                          << "with parent process to stdio descriptors.";
    close(nChildStdIn[0]);
    close(nChildStdIn[1]);
    close(nChildStdOut[0]);
    close(nChildStdOut[1]);
    close(nChildStdErr[0]);
    close(nChildStdErr[1]);

    std::vector<char*> argv(argVec.size() + 1, 0);
    for (size_t n = 0; n < argVec.size(); n++)
      argv[n] = const_cast<char*>(argVec[n].c_str());

    if (execvp(argv[0],&(argv[0])) == -1)
      return fb.Error(E_UTILS_CREATE) << ": Failed to change process image (execvp) in child process to " 
                                      << argv[0] << ". System error message: " << strerror(errno) << ".";
  }

  if (pnFileDescriptors)
  {
    pnFileDescriptors[0] = nChildStdIn[1];
    pnFileDescriptors[1] = nChildStdOut[0];
    pnFileDescriptors[2] = nChildStdErr[0];
  }

  return 0;
}


void 
KillProcess(pid_t pid, const std::string &sChildName, Feedback &fb)
{
  if (pid)
  {
    fb.Info(3) << "Killing process " << pid << ", aka " << sChildName << ".";

    int nStat;
    pid_t wp = waitpid( pid, &nStat, WNOHANG);
        // wp == 0: The child is running normally.  wp == p:
        // Process status available for the child.  Check if this
        // means the process has terminated, either normally or
        // due to a signal
    if (wp != pid || (!WIFEXITED(nStat) && !WIFSIGNALED(nStat)))
    {
      kill(pid, SIGINT);
      sleep(1);
      wp = waitpid( pid, &nStat, WNOHANG);
      if (wp != pid || (!WIFEXITED(nStat) && !WIFSIGNALED(nStat)))
      {
        kill( pid, SIGKILL );
        sleep(1);
        wp = waitpid( pid, &nStat, WNOHANG);
        if (wp != pid || (!WIFEXITED(nStat) && !WIFSIGNALED(nStat)))
        {
          static const int name_len = 1024;
          char szHostName[name_len];
          std::string sHostDesc;
          if (!gethostname(szHostName, name_len))
            sHostDesc = std::string("on host ") + szHostName;
          else
            sHostDesc = "(Failed to get host name)";
          fb.Warning() << "The process (" << sChildName << ", pid " << pid
                       << ") apparently survived SIGKILL " << sHostDesc
                       << "! The user should log in and kill it manually.";
        }
      }
    }
  }
}
