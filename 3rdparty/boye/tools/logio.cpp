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
#include <ext/stdio_filebuf.h>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <misc_utils.h>
#include <syncutils.h>

using namespace std;

typedef struct TLogVar {
  bool bLog;
  string sFileName;
} TLog;

static TLog logs[3] = { {false, ""}, {false, ""} , {false, ""} };
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
 
//   logs[0].bLog = logs[1].bLog = false;
 
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

typedef struct TShuffleDataVar
{
  istream &input;
  ostream &output;
  bool bLog;
  string sLogFileName;
  string sDirection;
  pthread_mutex_t *pOutputMtx;
  int nFileDes;
  TShuffleDataVar(istream &in, ostream &out, bool bL, 
                  string sLog, string sDir, pthread_mutex_t *pMtx, int nfd = -1)
      : input(in), output(out), bLog(bL), sLogFileName(sLog)
      , sDirection(sDir), pOutputMtx(pMtx), nFileDes(nfd)
  {
  }
} TShuffleData;


void*
ShuffleData(void *pArg)
{
  TShuffleData &d = *(static_cast<TShuffleData*>(pArg));
  
  if (bVeryVerbose)
  {
    pthread_mutex_lock(d.pOutputMtx);
    AutoMutex mtx(d.pOutputMtx);
    cerr << sProgramName << ": Loaded data shuffler for " << d.sDirection
         << " in " << (bBinary ? "binary" : "text") << " mode.\n";
  }

  ofstream fLog;
  if (d.bLog)
  {
    if (bZip)
    {
      int fd[2];
      pipe(fd);
      if (!fork())
      {
        close(fd[1]);
        dup2(fd[0], 0);
        int nFdOut = open(d.sLogFileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 
                          S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        if (nFdOut == -1)
        {
          cerr << "Failed to open " << d.sDirection << " log file " << d.sLogFileName
               << ". System error message: " << strerror(errno) << ".";
          return 0;
        }
        dup2(nFdOut, 1);
        char *argv[] = { "gzip", "-c", 0 };

        if (execvp(argv[0], argv) == -1)
        {
          cerr << "Failed to load gzip for compressing output. System error message: "
               << strerror(errno) << ".";
          return 0;
        }
      }
      else
      {
        close(fd[0]);
        ReplaceStreamFd(fLog, fd[1]);
      }
    }
    else
    {
      fLog.open(d.sLogFileName.c_str());
      if (!fLog.is_open())
      {
        pthread_mutex_lock(d.pOutputMtx);
        AutoMutex mtx(d.pOutputMtx);
        cerr << "Failed to open " << d.sDirection << " log file " << d.sLogFileName << ".\n";
        return 0;
      }
      if (bVerbose)
      {
        pthread_mutex_lock(d.pOutputMtx);
        AutoMutex mtx(d.pOutputMtx);
        cerr << sProgramName << ": Logging " << d.sDirection << " data to " << d.sLogFileName << ".\n";
      }
    }
  }

  string s;
  while (getline(d.input, s))
  {
    pthread_mutex_lock(d.pOutputMtx);
    AutoMutex mtx(d.pOutputMtx);

    if (bVeryVerbose)
      cerr << sProgramName << ": Read " << d.sDirection << " line: " << s << ".\n";

    if (d.bLog)
      fLog << s << "\n" << flush;
    d.output << s << "\n" << flush;

  }
  if (bVerbose)
  {
    pthread_mutex_lock(d.pOutputMtx);
    AutoMutex mtx(d.pOutputMtx);
    cerr << sProgramName << ": \"getline\" of " << d.sDirection << " failed, logging complete.\n";
  }

  if (bVerbose)
  {
    pthread_mutex_lock(d.pOutputMtx);
    AutoMutex mtx(d.pOutputMtx);
    cerr << sProgramName << ": Data shuffler for " << d.sDirection << " completed.\n";
  }

  if (d.nFileDes != -1)
  {
    if (bVerbose)
    {
      pthread_mutex_lock(d.pOutputMtx);
      AutoMutex mtx(d.pOutputMtx);
      cerr << sProgramName << ": Data shuffler for " << d.sDirection << " closing output.\n";
    }
    close(d.nFileDes);
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
  
  if (bVerbose)
  {
    cerr << sProgramName << ": Loading the logged process as follows:\n\t";
    copy(argVec.begin(), argVec.end(), ostream_iterator<string>(cerr, " "));
    cerr << "\n";
  }

  ifstream processOut, processErr;
  ofstream processIn;
  int nfd[3];

  if (ConnectProcess(argVec, &processOut, &processIn, &processErr, 0, nfd))
  {
    cerr << "Failed to connect to the logged process.\n";
    return 1;
  }
  
  pthread_mutex_t outputMtx = PTHREAD_MUTEX_INITIALIZER;

      // Shuffler 1: Reads from own stdin and writes to process stdin
  TShuffleData d1(cin, processIn, logs[0].bLog, logs[0].sFileName, "input", &outputMtx, nfd[0]);
      // Shuffler 2: Reads from process stdout and writes to own stdout
  TShuffleData d2(processOut, cout, logs[1].bLog, logs[1].sFileName, "output", &outputMtx);
      // Shuffler 3: Reads from process stderr and writes to own stderr
  TShuffleData d3(processErr, cerr, logs[2].bLog, logs[2].sFileName, "error", &outputMtx);

  pthread_t ptid1, ptid2;
  if (pthread_create(&ptid1, 0, ShuffleData, &d1) || pthread_create(&ptid2, 0, ShuffleData, &d3))
  {
    cerr << "Failed to launch data shuffling threads.\n";
    return 1;
  }

      // When the process has closed stdout and stderr, it is assumed
      // to be dead. If stdin is closed the shuffler will close stdin
      // of the process as well.  Otherwise, don't bother with the
      // stdin reader.
  ShuffleData(&d2);
  pthread_join(ptid2, 0);
  return 0;
}
