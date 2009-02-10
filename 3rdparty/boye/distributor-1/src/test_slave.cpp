/********************************************************************
 *   		test_slave.cpp
 *   Created on Tue May 23 2006 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include "../config.h"
#include "test_slave.h"

#include <misc_utils.h>

#include <vector>
#include <iostream>
#include <list>

#include <unistd.h>
#include <getopt.h>
#include <cassert>
using namespace std;

list<int> signals;
int nFactor = 7;
bool bSlow = false;
bool bVerbose = false;

typedef enum { eof, simple } eIOMode;
eIOMode inputMode = simple;
eIOMode outputMode = simple;

int
parse_arguments(int argc, char *argv[])
{
  struct option opts[] = {
    {"factor"      , required_argument, 0, 'f'},
    {"pause"      , no_argument, 0, 'p'},
    {"job-input-mode"  , required_argument, 0, 'j'},
    {"job-output-mode" , required_argument, 0, 'o'},
    {"signal"      , required_argument, 0, 's'},
    {"verbose"      , no_argument, 0, 'v'},
    { 0 }};

      // Adding a + to the opstring to avoid permuting the option string.
  int ch;
  while ((ch = getopt_long(argc, argv, "+f:j:o:ps:v", opts, 0)) != -1)
  {
    switch (ch)
    {
        case 'f':
          nFactor = atoi(optarg);
          break;
        case 'j':
          if (!strcasecmp(optarg, "eof"))
            inputMode = eof;
          else if (!strcasecmp(optarg, "simple"))
            inputMode = simple;
          else
            cerr << "Unrecognized input mode: " << optarg << ". Ignored.\n";
          break;
        case 'o':
          if (!strcasecmp(optarg, "eof"))
            outputMode = eof;
          else if (!strcasecmp(optarg, "simple"))
            outputMode = simple;
          else
            cerr << "Unrecognized output mode: " << optarg << ". Ignored.\n";
          break;
        case 'p':
          bSlow = true;
          break;
        case 's':
          signals.push_back(atoi(optarg));
          break;
        case 'v':
          bVerbose = true;
          break;
        default:
          std::cerr << "Unregonized option: " << static_cast<char>(optopt) << ".\n";
          return 1;
    }
  }
  return 0;
}

void
SignalIgnorer(int nSig)
{
    static const int name_len = 1024;
    char szHostName[name_len];
    std::stringstream ssHost;
    if (!gethostname(szHostName, name_len))
      ssHost << " on " << szHostName;

    cerr << "Slave " << getpid () << ssHost.str() << ": Signal " << nSig << " received and ignored.\n";
}

int main(int argc, char *argv[])
{
  if (parse_arguments(argc, argv))
  {
    cerr << "Usage: " << argv[0] << " [options]\n"
         << "Write to standard output each line of input multiplied by a factor.  \n\nOptions:\n"
         << "--factor | -f k      Multiply each input line by k. Default " << nFactor << ".\n"
         << "--job-[in|out]put-mode | j/o mode Expect/Write input/output of type mode.  Supported modes are 'eof' and 'simple'."
         << "--signal | -s n      Report and ignore signal n.\n"
         << "--pause | -p         Take breaks, work slowly.\n"
         << "--verbose | -v       Print lots of output.\n";

    return 1;
  }

  for (list<int>::const_iterator itsig = signals.begin(); itsig != signals.end(); itsig++)
  {
    if (bVerbose)
      cerr << "Slave " << getpid() << ": Will ignore signal " << *itsig << " if received...\n";
    Signal(*itsig, SignalIgnorer);
  }

  srand(time(0));

  pid_t nPid = getpid();
  
  if (bSlow)
    cerr << argv[0] << " (" << nPid << ") started in slow mode.\n";

  while (cin)
  {
    string sEOF1, sEOF2, sChomp;
    if (inputMode == eof)
      getline(cin, sEOF1);
    else 
      assert(inputMode == simple);

    int nNum;
    cin >> nNum;
    getline(cin, sChomp);

    if (inputMode == eof)
    {
      getline(cin, sEOF2);
      if (sEOF1 != sEOF2)
      {
        cerr << "Read non-matching EOF marks. Mark 1: " << sEOF1 << ", mark 2: " << sEOF2 << ".\n";
        exit(1);
      }
    }
    else 
      assert(inputMode == simple);

//     int nSleep = (rand() % 10) ? (rand() % 5) : (rand() % 30);
//     int nSleep = rand() % 3;
    int nSleep = 0;
    if (bSlow)
      nSleep = 100;
    if (bVerbose)
      cerr << argv[0] << " (" << nPid << ") received the number " << nNum 
           << ".  Now going to sleep for " << nSleep 
           << " seconds before returning " << nNum * nFactor
           << " (" << nNum << "*" << nFactor << ").\n" << flush;
    sleep(nSleep);
    if (bVerbose)
      cerr << argv[0] << " (" << nPid << ") now returns the number " 
           << nNum * nFactor << " (" << nNum << "*" << nFactor << ").\n" << flush;

      if (outputMode == eof)
        cout << "EOF\n";
      else 
        assert(outputMode == simple);
      cout << nNum * nFactor << "\n" << flush;
      if (outputMode == eof)
        cout << "EOF\n" << flush;
      else 
        assert(outputMode == simple);
  }
  return 0;
}
