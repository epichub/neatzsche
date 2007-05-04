#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>


#include "settings.h"



int main(int argc,char *args[]){
  NEATsettings * s = new NEATsettings();
  ifstream ifs(args[1],ios::in);
  ifs>>s;
  ifs.close();
  s->setValue("dropoff_age",20);
  s->addTopComment("new top comment");
  ofstream ofs("comments2",ios::out);
  ofs<<s;
  ofs.close();  
}
