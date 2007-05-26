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
#ifndef RUNNER_H_
#define RUNNER_H_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <sstream>

#include "genome.h"
#include "neuralmath.h"
#include "settings.h"
#include "evolution.h"
#include "evoops.h"
#include "dataset.h"
#include "iface.h"
#include "gowrapper.h"
#include "coevolution.h"
#include "xmlconvert.h"

using namespace std;

class Interruptcallback;

class NEATRunner{
private:
  double ** smoothdata;
  bool stop;
  SpecGraph * sg;
public:
  NEATRunner(int igens, int iiter)
  {smoothdata = new double * [igens]; 
   for(int i=0;i<igens;i++) smoothdata[i] = new double[3];
   generations=igens; runs=iiter;stop=false;
   currentgraphf=NULL;sbest=NULL; best=NULL; gbest=NULL; sgf = "defaultspecgraphfile.xmlgraph";}
  ofstream * currentgraphf;
  Population * pop;
  Selector * sel;
  Phenotype * sbest;
  Phenotype * best;
  Phenotype * gbest;
  string sCurrentGenomeFile;
  string sCurrentGraphFile;
  string sCurrentXMLGenomeFile;
  string sFinalGenomeFile;
  string finalgraphfile;
  bool output;
  LocalReproducer * rep;
  Coevolution * coevo;
  int nodes;
  bool pipeio;
  unsigned int mc;
  Interruptcallback * icb;
  double avgf;
  int generations;
  int runs;
  int pid;
  string basefile;
  string infoline;
  NEATsettings * set;
  TransferFunctions * tfs;
  Evaluator * ev;
  string sgf;
  void (*signalhandler)(int sig);
  void runLoop();
};

class Interruptcallback{
public:
  Interruptcallback(){fe=NULL; best=NULL;}
  FitnessEvaluator * fe;
  Phenotype * best;
  NEATRunner * run;
  ofstream * currentgraphf;
  //  void operator(){};
  void operator()(int sig);
};

#endif
