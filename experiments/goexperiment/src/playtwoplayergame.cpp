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
#include <sstream>
#include "iface.h"
#include "gowrapper.h"
#include "eval.h"
using namespace gw;
int main(int argc,char *args[]){
  int n = 6;
  if(argc!=n){
    cerr << "wrong number for arguments("<<argc<<"): seed settings gnugo-settings genome1 genome2 " << endl;
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
  cerr << "reading from genome: " << args[5] << endl;

  NEATsettings * nset = new NEATsettings();
  ifstream nifs(args[2],ios::in);
  nifs >> nset;
  nifs.close();

  TransferFunctions * tfs = new TransferFunctions(nset);

  Genome * g = new Genome(tfs);
  ifstream ifs(args[4],ios::in);
  ifs>>g;
  ifs.close(); 

  Genome * g2 = new Genome(tfs);
  ifstream ifs2(args[5],ios::in);
  ifs2>>g2;
  ifs2.close();

  NEATsettings * set = new NEATsettings();
  ifstream goifs(args[3],ios::in);
  goifs >> set;
  goifs.close();

  int size = (int)set->getValue("size");
  double outsidev = set->getValue("outsidevalue");
  double komi = set->getValue("komi");
  int level = (int)set->getValue("level");
  int eyesize = (int)set->getValue("eyesize");
  int maxlooksteps = (int)set->getValue("maxlooksteps");
  int csize = 500;
  int cqsize = 500;
  //(int&, bool, double&, double&, int&, int&, int&, int&, int&)
  //(int,  bool, double,  double,  int,  int,  int,  int,  int, int)
  GoWrapper * gw = new CachingGoWrapper(size,true,outsidev,
					komi,level,eyesize,maxlooksteps,20,
					csize,cqsize);
  GoEvaluator * fe = new GoEvaluator(gw,1,1,1,set);
  Phenotype * p = new Phenotype(g);
  Phenotype * p2 = new Phenotype(g2);
  cerr << "game:" << endl;
  fe->show(p);
  cerr << fe->show(p2);
  fe->f(p); fe->f(p2);
  cerr << "fitness 1:" << p->getFitness() << " fitness 2: " << p2->getFitness() << endl;
  delete fe;
  delete p;

}
