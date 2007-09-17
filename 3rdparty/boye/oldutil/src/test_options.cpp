/********************************************************************
 *   		test_options.cpp
 *   Created on Tue May 23 2006 by Boye A. Hoeverstad.
 *   
 *   Test program for the options parsing class.
 *******************************************************************/

#include <options.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  static const string process_name = "masterstub";

  Feedback fb("Options test program");

  Options::Instance().Append("info-level", TOptionData("Level of verbosity for informational output", false, "2"));
  Options::Instance().Append("master-program", TOptionData("The name of the process to be loaded on the master side", true, ""));
  Options::Instance().Append("master-arguments", TOptionData("Arguments sent to master process", false, ""));
  Options::Instance().Append("slave-program", TOptionData("The name of the process to be loaded on the slave side", true, ""));
  Options::Instance().Append("slave-arguments", TOptionData("Arguments sent to the slave process", false, ""));

  if (argc != 2 || !strcasecmp(argv[1], "-?") || !strcasecmp(argv[1], "--help") || !strcasecmp(argv[1], "-h"))
  {
    cerr << "Usage: " << argv[0] << " config-file\n"
         << "Where \"config-file\" is a file with configuration options, written as lines of key:value pairs.  "
         << "The available options are as follows:\n"
         << Options::Instance().PrettyPrint() << "\n";
    return 1;
  }

  cerr << "Before reading options file.  Current options are:\n"
       << Options::Instance().PrettyPrint() << "\n\n";

  ifstream ifOptions(argv[1]);
  if (!ifOptions)
  {
    cerr << "Failed to open config-file " << argv[1] << " for reading.  Run " 
         << argv[0] << " --help for further options.";
    return 1;
  }
  Options::Instance().Read(ifOptions);

  cerr << "File read.  Current options are:\n"
       << Options::Instance().PrettyPrint() << "\n\n";

  int nInfoLevel;
  if (Options::Instance().Option("info-level", nInfoLevel))
    fb.Warning("Failed to get option info-level.\n");
  else
    fb.Info(1) << "info-level is \"" << nInfoLevel << "\".";

  string sMaster, sMasterArgs, sSlave, sSlaveArgs;
  if (Options::Instance().Option("master-program", sMaster))
    fb.Warning("Failed to get option master-program.");
  else
    fb.Info(1) << "master-program is \"" << sMaster << "\".";

  if (Options::Instance().Option("master-arguments", sMasterArgs))
    fb.Warning("Failed to get option master-arguments.");
  else
    fb.Info(1) << "master-arguments is \"" << sMasterArgs << "\".";

  if (Options::Instance().Option("slave-program", sSlave))
    fb.Warning("Failed to get option slave-program.");
  else
    fb.Info(1) << "slave-program is \"" << sSlave << "\".";

  if (Options::Instance().Option("slave-arguments", sSlaveArgs))
    fb.Warning("Failed to get option slave-arguments.");
  else
    fb.Info(1) << "slave-arguments is \"" << sSlaveArgs << "\".";

  return 0;
}
