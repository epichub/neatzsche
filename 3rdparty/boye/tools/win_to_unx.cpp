#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void chomp(istream &is, ostream &os)
{
  char c;
  while (is.get(c))
    if (c != 13) os.put(c);
}

int main(int argc, char **argv)
{
  if (argc==1) chomp(cin, cout);
  else
    for (int i=1; i<argc; i++){
      ifstream inf;
      ofstream outf;
      char outfname[256];
      sprintf(outfname, "%s.tmp", argv[i]);
      inf.open(argv[i]);
      outf.open(outfname);
      cout << "Editing file " << argv[i] << endl;
      chomp(inf, outf);
      cout << "Done editing file " << argv[i] << ". New file saved in " << outfname << endl;
      inf.close();
      outf.close();
      char command[516];
      sprintf(command, "mv %s %s", outfname, argv[i]);
      cout << "Renaming file " << outfname << " to " << argv[i] << endl;
      system(command);
    }

  return 0;
}
