/********************************************************************
 *   		test_master.cpp
 *   Created on Tue May 23 2006 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include "../config.h"
#include "test_master.h"

#include <misc_utils.h>

#include <cassert>
#include <vector>
#include <iostream>
#include <list>

#include <unistd.h>
#include <getopt.h>

using namespace std;

list<int> signals;
int nNumLines = 10;
int nFactor = 7;
int nNumIterations = 50;

typedef enum { eof, simple } eIOMode;
eIOMode inputMode = simple;
eIOMode outputMode = simple;

int
parse_arguments(int argc, char *argv[])
{
  struct option opts[] = {
    {"lines"           , required_argument, 0, 'l'},
    {"factor"          , required_argument, 0, 'f'},
    {"iterations"      , required_argument, 0, 'i'},
    {"job-input-mode"  , required_argument, 0, 'j'},
    {"job-output-mode" , required_argument, 0, 'o'},
    {"signal"          , required_argument, 0, 's'},
    { 0 }};

      // Adding a + to the opstring to avoid permuting the option string.
  int ch;
  while ((ch = getopt_long(argc, argv, "+l:f:j:o:i:s:", opts, 0)) != -1)
  {
    switch (ch)
    {
        case 'l':
          nNumLines = atoi(optarg);
          break;
        case 'f':
          nFactor = atoi(optarg);
          break;
        case 'i':
          nNumIterations = atoi(optarg);
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
        case 's':
          signals.push_back(atoi(optarg));
          break;
//         case 'v':
//           bVerbose = true;
//           break;
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
  cerr << "Master: Signal " << nSig << " received and ignored.\n";
}

int main(int argc, char *argv[])
{
  if (parse_arguments(argc, argv))
  {
    cerr << "Usage: " << argv[0] << " [options]\n"
         << "Write lines of numbers on separate lines to stdout.  "
         << "Expect them returned multiplied by factor on stdin.  "
         << "Repeat the process for a given number of times.  \n\nOptions:\n"
         << "--lines | -l n       Write n lines of numbers at each iteration. Default " << nNumLines << ".\n"
         << "--factor | -f k      Expect each line to be multiplied by k on return. Default " << nFactor << ".\n"
         << "--iterations | -i n  Repeat the write/read process n times. Default " << nNumIterations << ".\n"
         << "--job-[in|out]put-mode | j/o mode Expect/Write input/output of type mode.  Supported modes are 'eof' and 'simple'."
         << "--signal | -s n      Report and ignore signal n.\n";
    return 1;
  }

  for (list<int>::const_iterator itsig = signals.begin(); itsig != signals.end(); itsig++)
  {
    cerr << "Master: Will ignore signal " << *itsig << " if received...\n";
    Signal(*itsig, SignalIgnorer);
  }

  cerr << "Master now writing " << nNumLines << " lines to std out. Expecting them returned multiplied by " 
       << nFactor << ".  Will repeat the process " << nNumIterations << " times...\n";
  
  srand(time(0));
  for (int nIter = 0; nIter < nNumIterations; nIter++)
  {
    std::vector<int> numbers(nNumLines);
    for (int nLine = 0; nLine < nNumLines && cout; nLine++)
    {
      if (outputMode == eof)
        cout << "EOF\n";
      else 
        assert(outputMode == simple);

      //numbers[nLine] = rand();
      numbers[nLine] = nIter*nNumLines + nLine;
      cout << numbers[nLine] << "\n" << flush;
//       sleep(1);

      if (outputMode == eof)
        cout << "EOF\n" << flush;
      else 
        assert(outputMode == simple);
    }
    cout << flush;
    if (!cout)
    {
      cerr << "Standard output failed.  Aborting.\n";
      return 3;
    }

    for (int nLine = 0; nLine < nNumLines && cin; nLine++)
    {
      int nRes, nExpected = numbers[nLine] * nFactor;

      string sEOF1, sEOF2, sChomp;
      if (inputMode == eof)
        getline(cin, sEOF1);
      else 
        assert(inputMode == simple);

      cin >> nRes;
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

      if (nRes != nExpected)
      {
        cerr << "Error on line " << nLine + 1 << " of iteration " << nIter + 1 << "!  "
             << "Expected " << nExpected << " (" << numbers[nLine] << "*" 
             << nFactor << "), got " << nRes << "!  Continuing.\n";
        //return 2;
      }
    }
    if (!cin)
    {
      cerr << "Standard input failed.  Aborting.\n";
      return 3;
    }
    cerr << "Iteration " << nIter + 1 << ": " << nNumLines << " calculations completed successfully.\n";
  }
  cerr << "All " << nNumIterations << " iterations completed. " << nNumLines * nNumIterations << " results successfully returned.\n";
  return 0;
}
