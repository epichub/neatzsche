/********************************************************************
 *   		frontend.cpp
 *   Created on Mon May 22 2006 by Boye A. Hoeverstad.
 *   
 *   Frontend to the distribution module, for use with MPI distributed
 *   processing.  Initializes MPI, and then loads either the master or
 *   the slave module, depending on the process rank.
 *******************************************************************/

#if HAVE_CONFIG_H
#include <config.h>
#endif

// slave_mpi.h must be included before stdio. See comment in slave_mpi.h
#include "slave_mpi.h"
#include "master.h"
#include "slave.h"
#include "utils.h"
#include <options.h>

#include "master_stdio.h"
#include "slave_stdio.h"

#include <mpi.h>
#include <iostream>
#include <fstream>

using namespace std;

class MPILibWrapper
{
public:
  MPILibWrapper(int *argc, char ***argv)
  {
    MPI_Init(argc, argv);
  }

  ~MPILibWrapper()
  {
    MPI_Finalize();
  }
};


int
InitOptions(int argc, char *argv[])
{
  static const string process_name = argv[0]; //"masterstub";

  Options::Instance().Append("verbosity", TOptionData("Level of verbosity for informational output from the master", false, "2"));
  Options::Instance().Append("slave-verbosity", TOptionData("Level of verbosity for informational output from the slaves", false, "0"));
  Options::Instance().Append("master-program", TOptionData("The name of the process to be loaded on the master side", true, ""));
  Options::Instance().Append("master-arguments", TOptionData("Arguments sent to master process", false, ""));
  Options::Instance().Append("slave-program", TOptionData("The name of the process to be loaded on the slave side", true, ""));
  Options::Instance().Append("slave-arguments", TOptionData("Arguments sent to the slave process", false, ""));
  Options::Instance().Append("slave-run-once", TOptionData("The slave process must be killed and reloaded for each new evaluation (true/false).", false, "false"));
  Options::Instance().Append("master-input-mode", TOptionData("How the master expects its input formatted.  Available values are SIMPLE and EOF", false, "SIMPLE"));
  Options::Instance().Append("master-input-lines", TOptionData("If master-input-mode is SIMPLE, this option determines the number of lines read for each input", false, "1"));
  Options::Instance().Append("master-output-mode", TOptionData("Similar to master-input-mode", false, "SIMPLE"));
  Options::Instance().Append("master-output-lines", TOptionData("Similar to master-input-lines", false, "1"));
  Options::Instance().Append("batch-mode", TOptionData("How the master delimits a batch of jobs.  Available values are SIMPLE and EOF", false, "SIMPLE"));
  Options::Instance().Append("batch-size", TOptionData("If batch-mode is SIMPLE, batch-size indicates the number of jobs to process (read from master) before returning results (write to master)", false, "1"));
//   Options::Instance().Append("iterations", TOptionData("The number of iterations (batches) to process.", true, ""));  
//   Options::Instance().Append("slave-count", TOptionData("The number of slaves to spawn", false, "1"));
  Options::Instance().Append("slave-wait-factor", TOptionData("How long a slave waits before taking a job already taken by another slave", false, "10"));
  Options::Instance().Append("jobs-per-send", TOptionData("How many free jobs each slave will take from the queue at once (0 = auto)", false, "1"));
  Options::Instance().Append("verbosity-showonly", TOptionData("If not empty, only verbose output from modules in this comma-separated list will be printed", false, ""));
  Options::Instance().Append("verbosity-dontshow", TOptionData("If not empty, verbose output from modules in this comma-separated list will never be printed", false, ""));

//   Options::Instance().Append("slave-expects-id", TOptionData("", false, "false"));

  if (argc != 2 || !strcasecmp(argv[1], "-?") || !strcasecmp(argv[1], "--help") || !strcasecmp(argv[1], "-h"))
  {
    cerr << "Usage: " << process_name << " config-file\n"
         << "Where \"config-file\" is a file with configuration options, written as lines of key:value pairs.  "
         << "The available options are as follows:\n"
         << Options::Instance().PrettyPrint() << "\n";
    return 1;
  }

  ifstream ifOptions(argv[1]);
  if (!ifOptions)
  {
    cerr << "Failed to open config-file " << argv[1] << " for reading.  Run " 
         << process_name << " --help for further options.\n";
    return 1;
  }
  Options::Instance().Read(ifOptions);

  return 0;
}


int
main(int argc, char *argv[])
{
#if HAVE_STD__IOS__SYNC_WITH_STDIO
      // Disable c++ stl synchronization with C standard i/o
      // routines.  This presumably improves I/O performance (ref
      // libstdc++-v3 HOWTO, chapter 27: Input/Output;
      // http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#8;
      // and configure.ac).
  std::ios::sync_with_stdio(false);
#endif

  MPILibWrapper w(&argc, &argv);
  int nRank, nRet = MPI_Comm_rank(MPI_COMM_WORLD, &nRank);
  if (nRet != MPI_SUCCESS)
  {
    std::cerr << "Failed to get MPI rank (MPI_Comm_rank did not return MPI_SUCCESS).  Abort.\n";
    return 1;
  }

  if ((nRet = InitOptions(argc, argv)))
    return nRet;

  if (nRank == 0)
    return master_main(argc, argv);
  else
    return slave_main(argc, argv);
}
