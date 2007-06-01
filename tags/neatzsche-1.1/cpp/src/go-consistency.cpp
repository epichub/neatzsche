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
  int n = 5;
  if(argc<n){
    cerr << "wrong number for arguments("<<argc<<")" << endl;
    goconstUsage(args[0]);
    exit(1);
  }
  bool seed = false;
  if(argc==6){
    seed = true;
    cerr << "setting seed to true\n";
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
  cerr << "reading from genome: " << args[2] << endl;

  //  FitnessEvaluator * fe = makeFitnessEvaluator(args[3]);
  NEATsettings * set = new NEATsettings();
  ifstream goifs("settings/settings-gnugo",ios::in);
  goifs >> set;
  goifs.close();
  NEATsettings * rset = new NEATsettings();
  ifstream goifs2("settings/settings-go",ios::in);
  goifs2 >> rset;
  goifs2.close();
  int size = (int)set->getValue("size");
  double outsidev = set->getValue("outsidevalue");
  double komi = set->getValue("komi");
  int level = (int)set->getValue("level");
  int eyesize = (int)set->getValue("eyesize");
  int maxlooksteps = (int)set->getValue("maxlooksteps");
  int csize = 500;
  int cqsize = 500;
  GoWrapper * gw = new CachingGoWrapper(size,true,outsidev,
					komi,level,eyesize,maxlooksteps,
					csize,cqsize);
  GoEvaluator * fe = new GoEvaluator(gw,0,1,1);
  int testsper = atoi(args[2]);
  int pops = atoi(args[3]);
  int respawns = atoi(args[4]);
  cerr << "running " << testsper << " amount of tests" << endl;
  Genome * g = NULL;
  if(seed){
    g = new Genome();
    ifstream ifs(args[5],ios::in);
    ifs>>g;
    ifs.close(); 
  }

  Population * pop = new Population(rset);
  double t;
  double tmp;
  Phenotypes * ps = NULL;
  for(int i3=0;i3<respawns;i3++){
    cerr << "respawning pop...\n";
    if(!seed)
      pop->randomSpawn(pops,29,5,1,1,1.0,new SigmoidTransfer(-4.9),"so",1.0);
    else
      pop->genesis(g,pops,1);
    ps = pop->getMembers();
    for(unsigned int i2=0;i2<ps->size();i2++){
      t=((GoEvaluator*)fe)->f(ps->at(i2));
      cerr << "eval phenotype "<<(i2+1)<<" (fitness: "<<t<<") :\n";
      for(int i=0;i<testsper;i++){
	tmp = ((GoEvaluator*)fe)->f(ps->at(i2));
      if(t!=tmp){
	cerr << "go inconsistency " << t << " not equal to " << tmp << endl;
	exit(0);
      }else
	cerr << (i+1) << " ";
      }
      cerr << endl;
    }
  }
  cerr << endl;
  
  //   delete fe;
  //   delete p;

}
