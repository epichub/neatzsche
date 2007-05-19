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

  int rands = 0;
  bool randnull=false;
  rands = atoi(args[1]);
  if(rands!=0)
    srand(rands);
  else{
    randnull=true;
    rands = time(0);
    srand(rands);
    cout << "ny seed: " << rands << endl;
  }
  
  NEATsettings * goset = new NEATsettings();
  ifstream goifs("settings/settings-gnugo",ios::in);
  goifs >> goset;
  goifs.close();
  NEATsettings * set = new NEATsettings();
  ifstream sifs("settings/settings-go",ios::in);
  sifs >> set;
  sifs.close();
  TransferFunctions * tfs = new TransferFunctions(set);
  Genome * genomeo = NULL;
  Phenotype * testp = NULL;
  Innovations * in = new Innovations(600000);
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
  fe = new GoEvaluator(gw,0,1,1,goset);

  double r = 0;
  int c=0;
//   do{
//     c=0;
//     if(randnull){
//       rands = time(0);
//       srand(rands);
//     }
    do{
      if(testp!=NULL)
	delete testp;
      genomeo = new Genome(1,29,5,0,0,set->getValue("spawn_recur_prob"),0.5,set,in,tfs);
      testp = new Phenotype(genomeo);
      r = fe->f(testp);
      cerr << "r: " << r << endl;
      c++;
    }while(r<0.15);
//   }while(c>3&&randnull);
//   if(randnull){
//     cerr << "fant bra seed: " << rands << endl;
//     exit(0);
//   }
  Genome * g = new Genome(tfs);
  ofstream ofs("testg.genome");
  ofs << genomeo;
  ofs.close();
  cerr << "\n\n+++++++++++++++++++++++++++++++++++++\n\n";
//   cerr << "orig fitness: " << fe->f(testp) << endl;
//   cerr << "orig fitness2: " << fe->f(testp) << endl;

  ifstream ifs("testg.genome");
  ifs>>g;
  ifs.close();
  g->setSettings(set);
//   cerr << "compare: " << genomeo->compare(g) << endl;
//   cerr << "compare2: " << g->compare(genomeo) << endl;
  Phenotype * p = new Phenotype(g);


//   testp->cleanNet();
//   p->cleanNet();
//   cerr << "original state: " << printvector(testp->getState()) << endl;
//   cerr << "read state: " << printvector(p->getState()) << endl;
//   cerr << "osum: "<< sumvector(testp->getState()) << " readsum: " << sumvector(p->getState()) << endl;
//   cerr << "checkvector: " << checkvector(testp->getState(),testp->getState(),true) << endl;
  testp->cleanNet();
  gw->reset();
  cerr << "\n\nreact original: "  << printvector(testp->react(gw->getSensoryInput(true)));
//   testp->cleanNet();
//   gw->reset();
//   cerr << "react original2: "  << printvector(testp->react(gw->getSensoryInput(true)));
  p->cleanNet();
  gw->reset();
  cerr << "\n\nreact read: "  << printvector(p->react(gw->getSensoryInput(true)));
//   p->cleanNet();
//   gw->reset();
//   cerr << "react read2: "  << printvector(p->react(gw->getSensoryInput(true)));
//   testp->cleanNet();
//   gw->reset();
//   cerr << "react original3: "  << printvector(testp->react(gw->getSensoryInput(true)));  
//   cerr << genomeo;
//   cerr << "orig fitness:" << fe->f(testp) << endl;
//   cerr << "read fitness:" << fe->f(p) << endl;
  cerr << "showgame original: " << endl << fe->show(testp);
  cerr << "showgame read: " << endl << fe->show(p);
  delete fe;
  delete p;

}
