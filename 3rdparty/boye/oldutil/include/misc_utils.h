/********************************************************************
 *   		utils.h
 *   Created on Mon May 22 2006 by Boye A. Hoeverstad.
 *   
 *   Miscellaneous utilities that I'm unable to find a better name
 *   for...
 *******************************************************************/

#if !defined(__MISC_UTILS_H__)
#define __MISC_UTILS_H__

#include <feedback.h>

#include <vector>

// extern FeedbackError E_UTILS_PIPE;
DECLARE_FEEDBACK_ERROR(E_UTILS_PIPE)
// extern FeedbackError E_UTILS_CREATE;
DECLARE_FEEDBACK_ERROR(E_UTILS_CREATE)
// extern FeedbackError E_UTILS_FD;
DECLARE_FEEDBACK_ERROR(E_UTILS_FD)


/********************************************************************
 *   Replace the file descriptor of the stream s with the one provided
 *   in nFd.  The original file descriptor will be closed.
 *******************************************************************/
int ReplaceStreamFd(std::istream &s, int nFd);
int ReplaceStreamFd(std::ostream &s, int nFd);
int ReplaceStreamFd(std::istream &is, std::ostream &os, int *pFds);



/********************************************************************
 *   Create a unix pipe and return the unix file descriptors in
 *   fildes.  Fildes must be a pointer to an array of at least two
 *   integers.
 *******************************************************************/
int CreatePipe(int *fildes);


/********************************************************************
 *   Build an argv-like vector an argument string.  Extremely simple
 *   processing so far.
 *******************************************************************/
int CreateArgumentVector(const std::string &sArgLine, std::vector<std::string> &argv);


/********************************************************************
 *   Load a process and connect standard input, output and error of
 *   the program to the stl streams given as arguments.  All or any of
 *   the stream arguments may be 0.  The first version takes the first
 *   argument of argVec to be the process to load.  The other version
 *   loads sFile, in which case the string sArgs should NOT contain
 *   the program name as first argument.
 *******************************************************************/
int ConnectProcess(const std::vector<std::string> &argVec, 
                   std::istream *pRead, std::ostream *pWrite, std::istream *pError,
                   pid_t *pChildPid, int *pnFileDescriptors);
int ConnectProcess(const std::string &sFile, const std::string &sArgs, 
                   std::istream *pRead, std::ostream *pWrite, std::istream *pError,
                   pid_t *pChildPid, int *pnFileDescriptors);


/********************************************************************
 *   Kill a process.  Try to kill it nicely first. Give it a little
 *   time to go down, then kill it the hard way.
 *******************************************************************/
void KillProcess(pid_t pid, const std::string &sChildName, Feedback &fb);


/********************************************************************
 *   Helper function to be able to send a functor as reference.
 *   Kept for reference, but other and better methods exist: Use
 *   the return from for_each, or check Josuttis p. 298.
 *******************************************************************/
// template<class Op, class Arg, class Ret>
// struct FunctorReference
// {
//   Op &m_op;
//   FunctorReference(Op &op)
//       : m_op(op)
//   {
//   }
  
//   Ret operator()(Arg &arg)
//   {
//     return m_op(arg);
//   }
// };


/********************************************************************
 *   Utility functor which returns a continuously increasing
 *   value.  To be used for instance when initializing index
 *   vectors.
 *******************************************************************/
template<class T = size_t>
struct sequence
{
  T m_nCur;
  const T m_nStep;
  sequence(T nInit = 0, T nStep = 1)
      : m_nCur(nInit), m_nStep(nStep)
  {
  }

  T operator() ()
  {
    T nRet = m_nCur;
    m_nCur += m_nStep;
    return nRet;
  }
};


/********************************************************************
 *   Functor to facilitate streaming in to a sequence with a call to
 *   for_each.
 *******************************************************************/
template<class T, class Stream = std::istream>
struct stream_in
{
  Stream &m_s;
  stream_in(Stream &s)
      : m_s(s)
  {
  }

  void operator()(T &t)
  {
    m_s >> t;
  }
};

#endif
