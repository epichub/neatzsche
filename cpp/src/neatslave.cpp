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
#include "iface.h"
#include "gowrapper.h"
using namespace std;
//void mytryrun()
int main(int argc,char *args[]){
  cerr << "slave initiated.." << endl;
  int n = 4;
  if(argc!=n){
    slaveUsage(args[0]);
    exit(1);
  }
  int rands = 0;
  rands = atoi(args[1]);
  if(rands!=0)
    srand(rands);
  else{
    rands = time(0);
    srand(rands);
    //cerr << "ny seed: " << rands << endl;
  }
  NEATsettings * set = new NEATsettings();
  ifstream ifs(args[2],ios::in);
  ifs>>set;
  ifs.close();

  //1. get the fitness evaluator type
  //  cout << "neatslave test0" << endl;
  Coevolution * c = NULL;
  FitnessEvaluator * f = makeFitnessEvaluator(args[3],c);
  c->setFitnessEvaluator(f);

  Phenotypes * p = new Phenotypes();
  Evaluator * e = new Evaluator(f);
  
  TransferFunctions * tfs = new TransferFunctions(set);
  c->setTfs(tfs);
  bool coevo = false;
  string s;
  //  cout << "neatslave test1" << endl;
  bool cont = true;
  int gen=0;

  while(cont){ // the drive loop of the slaves, read 
               // in cmd(coevo/std), where coevo expects two genomes
    gen++;
    readPopulation(p,c,tfs);
    if(gen==c->getStartGeneration())
      coevo = true;
    ifstream ifs2("curbest");
    Genome * best;
    Phenotype * pbest = new Phenotype(best);
    ifs2 >> best;
    ifs2.close();
    cerr << getpid() << "-slave: bestf: " << f->f(pbest) << endl;
    //evaluate and set the fitness..
    if(coevo)
      c->evaluate(p);
    else
      e->evaluate(p,p->size());

    //    cerr << "coevo size: " << c->size() << endl;
    outputFitness(p);
    cleanupPopulation(p);
//     cont = readExitToken();
    //exit(0);
  }
  delete f;
  delete p;
  delete e;
  delete c;
  
  exit(0);
}

