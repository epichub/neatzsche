#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void chomp(istream &is, ostream &os)
{
  char inc;
  while(is.get(inc))
    if(inc != 13)
      os.put(inc);
}


int main(int argc, char **argv)
{
  ifstream ifs;
  ofstream ofs;

  char outname[256];
  char command[256];

  if (argc==1)
    chomp(cin, cout);
  else for(int i=1; i<argc; i++) {
    ifs.open(argv[i]);
    sprintf(outname, "%s.tmp", argv[i]);
    ofs.open(outname);
    chomp(ifs, ofs);
    ifs.close();
    ofs.close();
    sprintf(command, "mv %s %s", outname, argv[i]);
    system(command);
  }
  return 0;
}
