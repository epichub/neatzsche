#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>


using namespace std;
//void mytryrun()
int main(int argc,char *args[]){
  stringstream ss;
  string s;
  long size;
  char *buf;
  char *ptr;
  size = pathconf(".", _PC_PATH_MAX);
  if ((buf = (char *)malloc((size_t)size)) != NULL)
    ptr = getcwd(buf, (size_t)size);
  ss << "node-" << getpid() << ".inp";
  cerr << "in dir " << ptr << "writing to file: " << ss.str() << endl;
  cin >> s;  
  ofstream ofs(ss.str().c_str());
  ofs << s<<endl;
  while(s.find("NODESTOP")==string::npos){
    cin >> s;
    ofs << s << endl;
  }
  ofs.close();
  return 0;
}
