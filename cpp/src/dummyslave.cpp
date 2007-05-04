/*
  Copyright 2007 Bjørn Magnus Mathisen
  This file is part of NEATzsche.

  NEATzsche is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  NEATzsche is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NEATzsche; if not, write to the Free Software Foundation,
  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 */
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
