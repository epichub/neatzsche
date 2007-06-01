#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "genome.h"
#include "neuralmath.h"
#include "settings.h"
#include "evolution.h"
#include "evoops.h"
#include "dataset.h"
#include <sstream>
#include "iface.h"
#include "gowrapper.h"

int main(int argc,char *args[]){
  int n = 4;
  if(argc!=n){
    cout << "wrong number for arguments("<<argc<<")" << endl;
    playgameUsage(args[0]);
    exit(1);
  }

  int rands = 0;
  rands = atoi(args[1]);
  if(rands!=0)
    srand(rands);
  else{
    rands = time(0);
    srand(rands);
    cout << "ny seed: " << rands << endl;
  }
  cout << "reading from genome: " << args[2] << endl;
  
  NEATsettings * goset = new NEATsettings();
  ifstream goifs("settings/settings-gnugo",ios::in);
  goifs >> goset;
  goifs.close();
  NEATsettings * set = new NEATsettings();
  ifstream sifs("settings/settings-go",ios::in);
  sifs >> set;
  sifs.close();
  TransferFunctions * tfs = new TransferFunctions(set);
  Genome * g = new Genome(tfs);
  ifstream ifs(args[2],ios::in);
  ifs>>g;
  ifs.close();
  bool easy = atoi(args[3]) == 1;
  cout << "easy: " << easy << " args3: " << args[3] << endl;
  int size = (int)goset->getValue("size");
  double outsidev = goset->getValue("outsidevalue");
  double komi = goset->getValue("komi");
  int level = (int)goset->getValue("level");
  int eyesize = (int)goset->getValue("eyesize");
  int maxlooksteps = (int)goset->getValue("maxlooksteps");
  int csize = 500;
  int cqsize = 500;
  gw::GoWrapper * gw = new gw::CachingGoWrapper(size,true,outsidev,
						komi,level,eyesize,maxlooksteps,
						100,csize,cqsize);
  GoEvaluator * fe = NULL;
  if(!easy)
    fe = new GoEvaluator(gw,0,1,1,goset);
  else
    fe = new EasyGoEvaluator(gw,0,1,1,goset);
  Phenotype * p = new Phenotype(g);

  cout << "game:" << endl;
  if(!easy)
    cout << fe->show(p);
  else
    cout << ((EasyGoEvaluator*)fe)->getFinishedBoard(p);
  cout << "fitness:" << fe->f(p) << endl;
  delete fe;
  delete p;

}
