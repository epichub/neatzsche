/********************************************************************
 *   		logio.cpp
 *   Created on Wed Jun 21 2006 by Boye A. Hoeverstad.
 *   
 *   Log any of standard input, output and/or error of a process to
 *   file.
 *******************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <errno.h>
#include <getopt.h>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <misc_utils.h>
#include <sys/wait.h>

using namespace std;

typedef struct TLogVar {
  bool bLog;
  string sFileName;
  string sDirection;
  auto_ptr<ostream> fLog;
  pid_t nZipPid;
} TLog;

static TLog logs[3] = {
  { false, "", "input", auto_ptr<ostream>(0) },
  { false, "", "output", auto_ptr<ostream>(0) },
  { false, "", "error", auto_ptr<ostream>(0) } };

static bool bVerbose = false;
static bool bVeryVerbose = false;
static string sProgramName;
static bool bBinary = false;
static bool bZip = false;
// static bool bDebug = false;

int
parse_args(int argc, char *argv[])
{
  struct option opts[] = {
    {"input-log"    , required_argument, 0, 'i'},
    {"output-log"   , required_argument, 0, 'o'},
    {"error-log"    , required_argument, 0, 'e'},
    {"binary"       , no_argument, 0, 'b'},
    {"verbose"      , no_argument, 0, 'v'},
    {"very-verbose" , no_argument, 0, 'V'},
    {"zip"          , no_argument, 0, 'z'},
//     {"debug"        , no_argument, 0, 'd'},
    { 0 }};
 
  int ch;
      // Add a + to the opstring to avoid permuting the option string.
      // This is necessary when logging processes with options.
  while ((ch = getopt_long(argc, argv, "+be:i:o:vVz", opts, 0)) != -1)
  {
    switch (ch)
    {
        case 'b':
          bBinary = true;
          break;
//         case 'd':
//           bDebug = true;
//           break;
        case 'e':
          logs[2].bLog = true;
          logs[2].sFileName = optarg;
          break;
        case 'i':
          logs[0].bLog = true;
          logs[0].sFileName = optarg;
          break;
        case 'o':
          logs[1].bLog = true;
          logs[1].sFileName = optarg;
          break;
        case 'v':
          bVerbose = true;
          break;
        case 'V':
          bVerbose = true;
          bVeryVerbose = true;
          break;
        case 'z':
          bZip = true;
          break;
        default:
          cerr << "Unregonized option: " << ch << ".\n";
          return 1;
    }
  }
  return 0;
}


int 
OpenLogs()
{
  for (int nLogIdx = 0; nLogIdx < 3; nLogIdx++)
  {
    TLog &log = logs[nLogIdx];
    if (!log.bLog)
      continue;

    if (bZip)
    {
      int fd[2];
      pipe(fd);
      log.nZipPid = fork();
      if (!log.nZipPid)
      {
            // Create output file for gzip and connect in child.
        close(fd[1]);
        dup2(fd[0], 0);
        int nFdOut = open(log.sFileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 
                          S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        if (nFdOut == -1)
        {
          cerr << "Failed to open gzipped " << log.sDirection << " log file " 
               << log.sFileName << ". System error message: " << strerror(errno) << ".";
          return 1;
        }
        dup2(nFdOut, 1);
        char *argv[] = { "gzip", "-c", 0 };

        if (execvp(argv[0], argv) == -1)
        {
          cerr << "Failed to load gzip for compressing output. System error message: "
               << strerror(errno) << ".";
          return 1;
        }
      }
      else
      {
            // Replace log fd with write end of gzip pipe in parent.
        close(fd[0]);
        log.fLog = auto_ptr<ostream>(new fdostream(fd[1]));
      }
    }
    else
    {
      ofstream *fl = new ofstream(log.sFileName.c_str());
      if (!fl->is_open())
      {
        cerr << "Failed to open " << log.sDirection << " log file " << log.sFileName << ".\n";
        return 1;
      }
      if (bVerbose)
        cerr << sProgramName << ": Logging " << log.sDirection << " data to " << log.sFileName << ".\n";
      log.fLog = auto_ptr<ostream>(fl);
    }
  }
  return 0;
}


int
Shuffle(int nFdIn, int nFdOut, TLog &log)
{
  static const size_t nReadMax = 1024;
  char szBuf[nReadMax];
  ssize_t nNumRead = read(nFdIn, szBuf, nReadMax);
  if (nNumRead > 0)
  {
    if (log.bLog)
    {
      if (!log.fLog->write(szBuf, nNumRead))
      {
        cerr << "Failed to write " << nNumRead << " bytes to " << log.sDirection 
             << " log file " << log.sFileName << ".\n";
        return 1;
      }
    }

    if (write(nFdOut, szBuf, nNumRead) != nNumRead)
    {
      cerr << "Failed to write " << nNumRead << " bytes to " << log.sDirection 
           << ".\n System error message: " << strerror(errno) << ".\n";
      return 1;
    }
  }

  if (nNumRead == -1)
  {
    cerr << "Failed to read from descriptor " << nFdIn
         << " (the data read should have been shuffled on to " << log.sDirection
         << ".\n System error message: " << strerror(errno) << ".\n";
      return 1;
  }
  return 0;
}



int
main(int argc, char *argv[])
{
  sProgramName = argv[0];
  if (parse_args(argc, argv) || argc - optind < 1)
  {
    cerr << "Usage: " << sProgramName << " [options] process [process-specific options]\n"
         << "Log input and/or output of process to file.\n"
         << "\nOptions:\n"
         << "-i, --input-log filename\tLog standard input to process to given file.\n"
         << "-o, --output-log filename\tLog standard output from process to given file.\n"
         << "-e, --error-log filename\tLog standard error from process to given file.\n"
         << "-z, --zip\tCompress logged data with gzip.\n"
         << "-v, --verbose \tPrint some diagnostics.\n"
         << "-V, --very-verbose \tPrint more diagnostics.\n";
//          << "-d, --debug \tPause after launch and print process ID of parent and child processes, so a debugger may be attached.\n";
    return 1;
  }

//   cerr << "Pid is " << getpid() << " .\n";
//   sleep(5);

  vector<string> argVec;
  int nArgIdx = optind;
  while (nArgIdx < argc)
    argVec.push_back(argv[nArgIdx++]);

  if (argVec.empty())
  {
    cerr << "Failed to find process name and optional process-specific arguments on command line.\n";
    return 1;
  }

  if (OpenLogs())
  {
    cerr << "Failed to open logs.\n";
    return 1;
  }
  
  if (bVerbose)
  {
    cerr << sProgramName << ": Loading the logged process as follows:\n\t";
    copy(argVec.begin(), argVec.end(), ostream_iterator<string>(cerr, " "));
    cerr << "\n";
  }

  int nfd[3];

  if (ConnectProcess(argVec, 0, 0, 0, 0, nfd))
  {
    cerr << "Failed to connect to the logged process.\n";
    return 1;
  }

      // Manual says poll is preferred over select.
  static const int nNumPollFds = 6;
  struct pollfd pollFds[nNumPollFds] = {
    { 0, POLLIN | POLLERR | POLLHUP, 0 },
    { 1, POLLERR, 0 }, // Assume writing is always possible (could have been POLLOUT | POLLERR).
    { 2, POLLERR, 0 },
    { nfd[0], POLLERR, 0 },
    { nfd[1], POLLIN | POLLERR | POLLHUP, 0 },
    { nfd[2], POLLIN | POLLERR | POLLHUP, 0 } };

  static const char *szFileDesc[] = { "parent stdin", "parent stdout", "parent stderr",
                                      "child stdin", "child stdout", "child stderr" };
  
  int nPollRet;
  while ((nPollRet = poll(pollFds, nNumPollFds, -1)) >= 0) // Wait indefinitely for input or error
  {
        // First check for available data, so all data is logged
        // even if the child process completes or stdin is
        // closed.
    for (int nFdRead = 0; nFdRead < nNumPollFds; nFdRead++)
    {
      if (pollFds[nFdRead].revents & POLLIN)
      {
        if (bVerbose)
          cerr << "Input available on " << szFileDesc[nFdRead] << ".  Shuffling.\n";

        int nFdIn = pollFds[nFdRead].fd, nFdOut, nDirIdx;
        switch (nFdRead)
        {
              // Read from own stdin and write to child stdin
            case 0:
              nFdOut = nfd[0];
              nDirIdx = 0;
              break;
                  // Read from child stdout and write to own stdout
            case 4:
              nFdOut = 1;
              nDirIdx = 1;
              break;
                  // Read from child stderr and write to own stderr
            case 5:
              nFdOut = 2;
              nDirIdx = 2;
              break;
            default:
              cerr << "ERROR: Read available from unexpected file descriptor index " << nFdRead << "!\n";
              return 1;
        }
        
            // Read all available data by repeatedly polling the
            // descriptor, ignoring errors.
        if (Shuffle(nFdIn, nFdOut, logs[nDirIdx]))
          return 1;
        struct pollfd pollEmp = { nFdIn, POLLIN, 0 };
        while (poll(&pollEmp, 1, 0) > 0 && pollEmp.revents & POLLIN)
        {
          if (bVerbose) 
            cerr << "More input available on " << szFileDesc[nFdRead] << ".  Shuffling again.\n";
          if (Shuffle(nFdIn, nFdOut, logs[nDirIdx]))
            return 1;
          pollEmp.revents = 0;
        }
          
        pollFds[nFdRead].revents = 0;
      }
    }
        // Now check for errors and shut down.  

        // Option 1: Our standard input has closed, in which case
        // we want to pass this message on to the child process.
    //    assert(pollFds[0].fd == 0);
    if (pollFds[0].revents & POLLERR || pollFds[0].revents & POLLHUP)
    {
      if (bVerbose)
        cerr << "Stdin of parent closed, closing stdin of child.\n";
      close(nfd[0]);
      pollFds[0].revents = 0;
    }

        // Option 2: Child has completed processing and closed
        // its standard input.  All logs should have been emptied
        // above, so we can safely shut down.
    for (int nFdErr = 0; nFdErr < nNumPollFds; nFdErr++)
    {
      if (pollFds[nFdErr].revents & POLLERR || pollFds[nFdErr].revents & POLLHUP)
      {
        if (bVerbose)
          cerr << (pollFds[nFdErr].revents & POLLERR ? "Error" : "Hangup")
               << " detected on " << szFileDesc[nFdErr] << ". Closing remaining file descriptors and exiting.\n";
        close(nfd[0]);
        close(nfd[1]);
        close(nfd[2]);

        for (int nLog = 0; nLog < 3; nLog++)
          if (logs[nLog].bLog)
          {
            if (bZip)
            {
              dynamic_cast<fdostream*>(logs[nLog].fLog.get())->flush();
              dynamic_cast<fdostream*>(logs[nLog].fLog.get())->close();
//               close(logs[nLog].nFd); // Explicit close; the above close() on the stream does not necessarily work.
              int nStat;
              if (bVerbose)
                cerr << "Waiting for gzip (pid " << logs[nLog].nZipPid << ") to complete compressing child " << logs[nLog].sDirection << " log.\n";
              waitpid(logs[nLog].nZipPid, &nStat, 0);
              if (bVerbose)
                cerr << "gzip completed.\n";
            }
            else
              dynamic_cast<fstream*>(logs[nLog].fLog.get())->flush();
          }
        return 0;
      }
    }    
  }

  return 0;
}

