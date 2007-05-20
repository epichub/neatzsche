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
#include "genome.h"
#include "neuralmath.h"
#include "settings.h"
#include "evolution.h"
#include "evoops.h"
#include "dataset.h"
#include <sstream>
#include <signal.h>
//#include "iface.h"
#include "runner.h"
#include "gowrapper.h"

void puretest();

Interruptcallback * icb = new Interruptcallback();
static void signalhandler(int sig) {
  //resetting signal handlers
  //  cerr << "catching signal: " << sig<<endl;
  addToAllSignals(signalhandler);
  icb->operator()(sig);
}

int main(int argc,char *args[]){
  int n = 8;
  if(argc!=n){
    gotestUsage(args[0]);
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

  //1. load the example file
  NEATsettings * set = new NEATsettings();
  ifstream ifs(args[2],ios::in);
  ifs>>set;
  ifs.close(); 

  //2. generate the pop
  TransferFunctions * tfs = new TransferFunctions(set);
  Population * pop = makePopulation(args[3],set,tfs);
  
  //3. then the selector
  Selector * sel = makeSelector(args[4]);
  Coevolution * coevo = NULL;
  FitnessEvaluator * fe = makeFitnessEvaluator(args[5],coevo);

  int g = atoi(args[6]);
  int iter = atoi(args[7]);
  Evaluator * ev = new Evaluator(fe); 
  LocalReproducer * rep = new LocalReproducer();

  //files  
  stringstream ssCurrentFile; ssCurrentFile << "results/test-go" << getPureTimeString() << "-" << getpid();
  string sCurrentGraphFile = ssCurrentFile.str() + ".graph";
  string sCurrentGenomeFile = ssCurrentFile.str() + "-cur.genome";
  string sCurrentXMLGenomeFile = ssCurrentFile.str() + "-cur.xmlgenome";
  string sFinalGenomeFile = ssCurrentFile.str() + "-final.genome";
  string finalgraphfile = ssCurrentFile.str() + "-final.graph";

  icb->fe = fe;

  NEATRunner * run = new NEATRunner(g,iter);

  int nodes = 0;

  run->pop = pop; run->sel = sel; run->sCurrentGenomeFile = sCurrentGenomeFile;
  run->sCurrentGraphFile = sCurrentGraphFile;
  run->sCurrentXMLGenomeFile = sCurrentXMLGenomeFile; 
  run->sFinalGenomeFile = sFinalGenomeFile; run->finalgraphfile = finalgraphfile;
  run->rep = rep; run->coevo = coevo; run->nodes = nodes; run->icb = icb; run->set = set; run->tfs = tfs;
  run->ev = ev;
  run->signalhandler = signalhandler;
  run->basefile = ssCurrentFile.str();
  run->pid = pid;
  icb->run = run;

  addToAllSignals(signalhandler);

  run->runLoop();

  delete pop;
  delete ev;
  delete fe;
  delete sel;
  delete rep;
  delete set;

  return 0;
}
void puretest(char *args[]){
  // go test code
  //int eyes = atoi(args[6]);
  // GoWrapper * go = new GoWrapper(19,false,0.3,5.5,10,eyes,100,false);
//   go->down(true);  go->down(true); go->right(true); go->right(true);
//   go->put(true);
//   go->genmove(true);
//   go->genmove(false);
//   cout << go->score(true,true)<<endl;
//   go->down(true);
//   cout << go->islegal(true)<<endl;
//   cout << go->getBoardAscii()<<endl;

  //vector<double> v = go->sqlook(true);
  //vector<double> v2 = go->getSensoryInput(true);
  //cout << printvector(v,eyes)<<endl;
  //go->quit();
}
