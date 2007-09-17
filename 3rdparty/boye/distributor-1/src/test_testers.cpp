/********************************************************************
 *              test_testers.cpp
 *   Created on Thu May 25 2006 by Boye A. Hoeverstad.
 *   
 *   Launch with the same arguments as test-master.  
 *   Will hook test-master up with test-slave.
 * 
 *   Obsolete, use pipeio instead.  Also, doesn't compile on
 *   norgrid, because mpiCC uses the Intel compiler, which in
 *   turn links to its own stl libraries, not gnu, so
 *   <ext/stdio_filebuf.h> is not found.
 *******************************************************************/

#include "utils.h"
#include <errno.h>
#include <iostream>
#include <vector>
#include <fstream>
// #include <ext/stdio_filebuf.h>

using namespace std;

int main(int argc, char *argv[])
{
//   string sArgs = (argc >= 3 ? argv[2] : "");
//   sArgs += " -v";
//   ConnectProcess("./test-slave", sArgs, &cin, &cout, 0, 0, 0);
  
//   dup2(static_cast<__gnu_cxx::stdio_filebuf<char>*>(cin.basic_ios<char>::rdbuf())->fd(), 0);
//   dup2(static_cast<__gnu_cxx::stdio_filebuf<char>*>(cout.basic_ios<char>::rdbuf())->fd(), 1);
  
//   std::vector<char*> v(argc + 1, char(0));
//   for (int arg = 0; arg < argc; arg++)
//     v[arg] = argv[arg];
//   if (execvp("./test-master", &(v[0])) == -1)
//     std::cerr << ": Failed to change process image (execvp) in master process. System error message: " << strerror(errno) << ".";

  cerr << "This program is obsolete.  Use pipeio instead: pipeio './test-master [args]' './test-slave [args]'.\n";
  return 0;
}
