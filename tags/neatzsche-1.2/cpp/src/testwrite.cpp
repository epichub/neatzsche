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
  if(rands!=0){
    srand(rands);
    srand48(rands);
  }else{
    randnull=true;
    rands = time(0);
    srand(rands);
    srand48(rands);
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
      genomeo = new Genome(1,29,5,1,1,set->getValue("spawn_recur_prob"),0.5,set,in,tfs);
      testp = new Phenotype(genomeo);
      r = fe->f(testp);
//       cerr << "showgame original: " << endl << fe->show(testp);
      cerr << "r: " << r << " puts: " << gw->getPuts() << " gwmoves: " << gw->getMoves() <<  endl;
//       if(gw->getMoves()==4)
// 	exit(0);
//       c++;
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
  Phenotype * clone = new Phenotype(genomeo->duplicate(8));

//   testp->cleanNet();
//   p->cleanNet();
//   cerr << "original state: " << printvector(testp->getState()) << endl;
//   cerr << "read state: " << printvector(p->getState()) << endl;


//   testp->cleanNet();
//   gw->reset();
//   cerr << "react original2: "  << printvector(testp->react(gw->getSensoryInput(true)));

//   p->cleanNet();
//   gw->reset();
//   cerr << "react read2: "  << printvector(p->react(gw->getSensoryInput(true)));
//   testp->cleanNet();
//   gw->reset();
//   cerr << "react original3: "  << printvector(testp->react(gw->getSensoryInput(true)));  
//   cerr << genomeo;

  cerr << "showgame original: " << endl << fe->show(testp);
  cerr << "showgame read: " << endl << fe->show(p);

  testp->cleanNet();
  gw->reset();
  cerr << "\n\nreact original: "  << printvector(testp->react(gw->getSensoryInput(true)));

  p->cleanNet();
  gw->reset();
  cerr << "\n\nreact read: "  << printvector(p->react(gw->getSensoryInput(true)));

  clone->cleanNet();
  gw->reset();
  cerr << "\n\nreact clone: "  << printvector(clone->react(gw->getSensoryInput(true)));

  ((GoEvaluator*)fe)->detrm = true;

  cerr << "orig fitness:" << fe->f(testp) << endl;
  cerr << "netinpsum: "<<sumvector(((GoEvaluator*)fe)->netinp) << endl;
  cerr << "orig fitness2:" << fe->f(testp) << endl;
  cerr << "netinpsum: "<<sumvector(((GoEvaluator*)fe)->netinp) << endl;
  cerr << "read fitness:" << fe->f(p) << endl;
  cerr << "netinpsum: "<<sumvector(((GoEvaluator*)fe)->netinp) << endl;
  cerr << "read fitness2:" << fe->f(p) << endl;
  cerr << "netinpsum: "<<sumvector(((GoEvaluator*)fe)->netinp) << endl;
  cerr << "clone fitness:" << fe->f(clone) << endl;
  cerr << "netinpsum: "<<sumvector(((GoEvaluator*)fe)->netinp) << endl;
  cerr << "clone fitness2:" << fe->f(clone) << endl;
  cerr << "netinpsum: "<<sumvector(((GoEvaluator*)fe)->netinp) << endl;
  p->cleanNet();testp->cleanNet();clone->cleanNet();
  cerr << "osum: "<< sumvector(testp->getState()) << " readsum: " << sumvector(p->getState()) << " clonesum: " << sumvector(clone->getState()) << endl;
  cerr << "checkvector o read: " << checkvector(testp->getState(),p->getState(),true) << endl;
  cerr << "checkvector o clone: " << checkvector(testp->getState(),clone->getState(),true) << endl;
  delete fe;
  delete p;
  delete clone;
  delete testp;
  cerr << "seed: " << rands << endl;
}
