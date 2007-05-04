#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <list>
#include <sys/timeb.h>


using namespace std;
//void mytryrun()
int main(int argc,char *args[]){
  //   int nNumNodes = 0;

  //   if (argc != 2 || nNumNodes = atoi(argv[1]) < 1) {
  //     cerr << "Usage: " << argv[0] << " num_nodes\n";
  //     return 1;
  //   }

  struct timeb tp;
  ftime(&tp);
  int nSeed = tp.time + tp.millitm;
  srand48(nSeed);

  while (cin) {
    // Read EOF tag(s) 
    string sEOFBegin;
    string sHOFEnd;
    if ( !(getline(cin, sEOFBegin))) // Indicates cin.fail(), which normally implies cin.eof().
      return 1;
    while (sEOFBegin == "POPULATION")
      if ( !(getline(cin, sEOFBegin))) // Indicates cin.fail(), which normally implies cin.eof().
	return 1;
  
    list<int> ids;

    // Read genome(s)
    string sNet, sLine;
    while (getline(cin, sLine) && sLine != sEOFBegin) {
      if (sLine == "genome") {
	string sID;
	getline(cin, sID);
	stringstream ss(sID);
	int nID;
	ss >> nID;
	ids.push_back(nID);
      }
      cerr << "got line: \"" << sLine << "\"" << endl;
    }
    if (sEOFBegin != sLine || sEOFBegin.empty() || sLine.empty()) {
      cerr << "Error in input: EOF tags don't match or are empty! First tag was \"" 
	   << sEOFBegin << "\", second was \"" << sLine << "\".\n" << flush;
      return 1;
    }
    
    for (list<int>::const_iterator idit = ids.begin(); idit != ids.end(); idit++)
      cout << *idit << "\t" << drand48() << "\t";
    cout << endl << flush;
    
  }
     return 0;
}

