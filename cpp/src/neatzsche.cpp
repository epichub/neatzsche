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
#include <sys/types.h>
#include <unistd.h>
#include <sstream>
#include <sys/stat.h>

#include "genome.h"
#include "neuralmath.h"
#include "settings.h"
#include "evolution.h"
#include "evoops.h"
#include "dataset.h"
#include "gowrapper.h"
#include "coevolution.h"
#include "runner.h"

using namespace std;
void master(char ** args, int argc, Neatzsche_MPI * comm,
	    NEATsettings * set, TransferFunctions * tfs,
	    Coevolution * coevo, FitnessEvaluator * fe, Evaluator * ev, 
	    int generations, int runs);

void slave(char ** argv, int argc, Neatzsche_MPI * comm,
	   TransferFunctions * tfs, Coevolution * c, 
	   FitnessEvaluator * fe, Evaluator * e, int maxgen);
Interruptcallback * icb = new Interruptcallback();
void signalhandler(int sig) {
  addToAllSignals(signalhandler);
  icb->operator()(sig);
}
void runfilesignalhandler(int sig) {
  addToAllSignals(runfilesignalhandler);
  cerr << "i runfilesignalhandler exiting.." << endl;
  writeRunfile(true,icb->run->basefile,icb->run->infoline,icb->run->pid);
  exit(0);
}
int main(int argc,char *args[]){
  //neatmaster code!

  //check argument count..
  int n = 7;
  if(argc!=n){
    neatzscheUsage(args[0]);
    exit(1);
  }
  //setup the random seed, load from console or seed fresh from time
  int rands = 0;
  rands = atoi(args[1]);
  if(rands!=0)
    srand(rands);
  else{
    rands = time(0);
    srand(rands);
    cerr << "ny seed: " << rands << endl;
  }
  //1. load the example file
  NEATsettings * set = new NEATsettings();
  ifstream ifs(args[2],ios::in);
  ifs>>set;
  ifs.close();

  Neatzsche_MPI * nmpi = new Neatzsche_MPI(argc,args);

  //2. generate the pop
  TransferFunctions * tfs = new TransferFunctions(set);

  //5. 
  Coevolution * coevo = NULL;
  FitnessEvaluator * fe = makeFitnessEvaluator(args[5],coevo);
  Evaluator * ev = new Evaluator(fe); 

  //7. stopping condition (usually generation counter, should support
  //   key interrupt)
  vector<string> * stopv = split(args[6]," ");
  int generations = 0;
  int runs = 0;
  if(stopv->at(0).find("count")!=string::npos){
    if(stopv->size()!=3){
      cerr << "not enough arguments for generation stopper" << endl;
      masterUsage(args[0]);
      exit(1);
    }
    generations = atoi(stopv->at(1).c_str());
    runs = atoi(stopv->at(2).c_str());
  }else if(stopv->at(0).find("key")!=string::npos){
    cout << "heh, key!?" << endl;
  }else{
    cout << "no stop condition exiting" << endl;
    exit(1);
  }
    


  if(nmpi->getRank()==0)
    master(args,argc,nmpi,set,tfs,coevo,fe,ev,generations,runs);
  else
    slave(args,argc,nmpi,tfs,coevo,fe,ev,generations);
  delete set; delete tfs; delete coevo; delete fe; delete stopv;
  delete nmpi;
  exit(0);//exit with success
}
void master(char ** args, int argc, Neatzsche_MPI * comm,
	    NEATsettings * set, TransferFunctions * tfs,
	    Coevolution * coevo, FitnessEvaluator * fe, Evaluator * ev, 
	    int generations, int runs){
  Population * pop = makePopulation(args[3],set,tfs);

  //3. then the selector
  Selector * sel = makeSelector(args[4]);

//   cout << "checking communicator.." << endl;
//   if(string(args[6]).find("mpi")!=string::npos){
//     cout << "no mpi communicator ending program" << endl;
//     exit(1);
//   }else
//     cout << "comm was right" << endl;

  LocalReproducer * rep = new LocalReproducer();

  //pointers for keeping track and saving all time best genome
  int pid = getpid();
  //files  
  stringstream ssCurrentFile; ssCurrentFile << "results/" << getPureTimeString() << "-" << pid << "/" ;
  mkdir(ssCurrentFile.str().c_str(),0777);
  stringstream sCurrentGraphFile; sCurrentGraphFile << ssCurrentFile.str() << "graph";
  stringstream sCurrentGenomeFile; sCurrentGenomeFile << ssCurrentFile.str() << "curgenome";
  string sSettingsFile = ssCurrentFile.str() + "settings";
  stringstream sCurrentXMLGenomeFile; sCurrentXMLGenomeFile << ssCurrentFile.str() << "curgenome";
  string sFinalGenomeFile = ssCurrentFile.str() + "finalgenome";
  string finalgraphfile = ssCurrentFile.str() + "finalgraph";
  stringstream specgraphfile; specgraphfile << ssCurrentFile.str() << "specgraph";

  //making a copy of settings
  ofstream sfile(sSettingsFile.c_str());
  sfile << set;
  sfile.close();

  icb->fe = fe;
  //calculate how many genomes to eval at the master while slaves are
  //evaluating a slightly bigger batch of genomes
  double mr = set->getValue("masterratio");
  int nodes = comm->getSize()-1;
  int nom = pop->getMembers()->size()/((unsigned int)nodes+1);
  unsigned int mc = (unsigned int)((double)nom*mr);
  cerr << "running for " << generations << " generations over " << runs << " runs " << endl;
  cerr << "running " << mc << " evals on master and " <<  (pop->getMembers()->size()-mc)/nodes << " on the each of the slaves." << endl;
  
  //the running loop itself
  NEATRunner * run = new NEATRunner(generations,runs);
  run->pop = pop; run->sel = sel; 
  run->sCurrentGenomeFile.str(sCurrentGenomeFile.str());
  run->sCurrentGraphFile.str(sCurrentGraphFile.str());
  run->sCurrentXMLGenomeFile.str(sCurrentXMLGenomeFile.str()); 
  run->sFinalGenomeFile = sFinalGenomeFile; run->finalgraphfile = finalgraphfile;
  run->rep = rep; run->coevo = coevo; run->nodes = nodes; run->icb = icb; run->set = set;run->tfs = tfs;
  run->ev = ev;
  run->signalhandler = runfilesignalhandler;
  run->mc = mc;
  //run->pipeio = !pipeio;
  run->basefile = ssCurrentFile.str();
  run->pid = pid;
  run->sgf.str(specgraphfile.str());
  run->comm = comm;
  icb->run = run;

  //make the infoline..
  stringstream iss;
  for(int i=0;i<argc;i++)
    iss << args[i] << " ";

  run->infoline = iss.str();
  addToAllSignals(runfilesignalhandler);//spesific to cluterrunning

  //starting the loop
  run->runLoop();

  //clean up memory

  delete pop;
  delete sel;
  delete rep;
}
void slave(char ** argv, int argc, Neatzsche_MPI * comm,
	   TransferFunctions * tfs, Coevolution * c, 
	   FitnessEvaluator * fe, Evaluator * e, int maxgen){
  bool cont = true,coevo = false;
  int gen=0;
  Phenotypes * p = new Phenotypes();
  if(c == NULL){
    cout << "wtf c er null" << endl;
    exit(1);
  }
  while(cont){ // the drive loop of the slaves, read 
               // in cmd(coevo/std), where coevo expects two genomes
    gen++;
    cont = comm->readPopulation(p,c,tfs);
//     if(!cont){
//       break;
//     }
    if(!coevo && gen==(c->getStartGeneration()+1)){
      coevo = true;
    }
    if(gen==maxgen){
      gen = 0;
      if(coevo)
	coevo = false;
    }

    //evaluate and set the fitness..
    if(coevo)
      c->evaluate(p,p->size());
    else
      e->evaluate(p,p->size());
    comm->outputFitness(p);
    cleanupPopulation(p);
    p = new Phenotypes();
  }
  cleanupPopulation(p);  
}
