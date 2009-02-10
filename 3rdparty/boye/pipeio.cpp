/********************************************************************
 *   		pipeio.cpp
 *   Created on Wed Jun 21 2006 by Boye A. Hoeverstad.
 *   
 *   Execute two programs and pipe them together.  First arg is taken
 *   to be the first program, second arg is taken to be the second
 *   (including arguments).
 *******************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include <errno.h>

#include <unistd.h>
#include <misc_utils.h>

using namespace std;

int
main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " process1 process2\n"
         << "process1 and process2 will be executed, and their I/O piped together.  "
         << "If the programs need arguments, run as follows:\n"
         << argv[0] << " 'process1 arg1 arg2' \"process2 arg1 arg2\"\n";
    return 1;
  }

  std::string p1 = argv[1], p2 = argv[2];

  std::vector<std::string> argVec1, argVec2;
  if (CreateArgumentVector(p1, argVec1)
      || CreateArgumentVector(p2, argVec2))
  {
    cerr << "Failed to parse input into process names and arguments.\n";
    return 1;
  }

  std::vector<char*> argv1(argVec1.size() + 1, 0), argv2(argVec2.size() + 1, 0);

  for (size_t n = 0; n < argVec1.size(); n++)
    argv1[n] = const_cast<char*>(argVec1[n].c_str());

  for (size_t n = 0; n < argVec2.size(); n++)
    argv2[n] = const_cast<char*>(argVec2[n].c_str());

  int nPipeIn[2], nPipeOut[2];
  pipe(nPipeIn);
  pipe(nPipeOut);

  if (fork())
  {
    close(nPipeIn[1]);
    close(nPipeOut[0]);
    dup2(nPipeIn[0], 0);
    dup2(nPipeOut[1], 1);

    if (execvp(argv1[0],&(argv1[0])) == -1)
    {
      cerr << "Failed to change process image (execvp) in parent process to " 
           << argv1[0] << ". System error message: " << strerror(errno) << "\n.";
      return 1;
    }
  }
  else
  {
    close(nPipeIn[0]);
    close(nPipeOut[1]);
    dup2(nPipeIn[1], 1);
    dup2(nPipeOut[0], 0);

    if (execvp(argv2[0],&(argv2[0])) == -1)
    {
      cerr << "Failed to change process image (execvp) in child process to " 
           << argv2[0] << ". System error message: " << strerror(errno) << "\n.";
      return 1;
    }
  }
  return 0;
}
