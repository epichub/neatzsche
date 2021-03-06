/*
  Copyright 2007 Bj�rn Magnus Mathisen
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

bool rightStruct(Phenotype * p);
double bestgc();
double beststruct();
double bestgeneral();
double calcgeneral(double gc, double righstruct, double avgh, double conn, NEATsettings * set);
void writebestgc(double v);
void writebeststruct(double v);
void writebestgeneral(double v);
void writexorsettings(string resulttype, double gc, double righstruct, double avgh, 
		   double conn, double genreal, NEATsettings * set, char *args[], int argc);

int main(int argc,char *args[]){
  int n = 8;
//   cerr << "argc:"<<argc<<endl;
  if(argc!=n){
    drawtestUsage(args[0]);
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
  NEATsettings * s = new NEATsettings();
  ifstream ifs(args[2],ios::in);
  ifs>>s;
  ifs.close();  

  //2. generate the pop
  TransferFunctions * tfs = new TransferFunctions(s);
  Population * pop = makePopulation(args[3],s,tfs);
  
  //3. then the selector
  Selector * sel = makeSelector(args[4]);

  int g = atoi(args[5]);
  int iter = atoi(args[6]);

  string picfile = args[7];
  PictureEvaluator * de = new PictureEvaluator(picfile);
  Evaluator * ev = new Evaluator(de); 
  LocalReproducer * rp = new LocalReproducer();
  int gc = 0; double sum=0; double sum2=0; double sum3=0;
  Phenotype * cbest = NULL;
  Phenotype * sbest = NULL;
  Phenotype * best = NULL;
  int osize=pop->getMembers()->size();
  int rs = 0; int ss=0;
  double ocomp=0;
  time_t startt;
  double timesum = 0;
  for(int i2=0;i2<iter;i2++){
    gc = 0;
    best = NULL;
    startt = time(0);
    for(int i=0;i<g;i++){
      gc++;
      ev->evaluate(pop->getMembers(),pop->getMembers()->size());
      if((unsigned int)pop->getOriginalSize()!=pop->getMembers()->size())
	cout << "size not right after eval.." << endl;
      ss=pop->getSpecies()->size();
      pop->updateSpeciesStats();
      pop->sortmembers();
      pop->sortspecies();
      cbest = pop->getCopyOfCurrentBest();
      de->f(cbest);
      if(best==NULL){
	best = cbest;
      }else if(cbest->getFitness()>best->getFitness()){
	delete best;
	best = cbest;
      }else{
	delete cbest;
      }
      sel->select(pop,0);
      rp->reproduce(pop);
      cout << "best: " << best->getFitness() << endl;
      cout << "printing oimg.." << endl;
      ((PictureEvaluator*)de)->runTest(best);
    }
    if(sbest==NULL)
      sbest = best;
    else if(best->getFitness()>sbest->getFitness())
      sbest = best;
    time_t ft = time(0)-startt;
    timesum += ft;
    cout << "run: "<<i2+1<<" gc: "<<gc<<" maxfitness: " << pop->getHighestFitness() 
	 << " sbest fitness: " << sbest->getFitness() << " species: " << ss 
	 << " time: " << ft << " time/gen: " << (double)ft/(double)gc << endl;
    sum += gc;
    sum2 += best->getGenome()->extrons();
    sum3 += best->getGenome()->countHidden();

    if(i2!=iter){
      if(pop->getOriginalSeed()!=NULL){
	Genome * oseed = pop->getOriginalSeed();
	int oelitism = pop->getOriginalInitialElitism();
	ocomp = pop->getOcomp();
	delete pop;
	pop = new Population(s,ocomp,tfs);
	pop->genesis(oseed,osize,oelitism);
      }else{
	pop->resetSpawn();
      }
	
    }
  }
  double dgc = sum/(double)iter;
  double conn = sum2/(double)iter;
  double avgh = sum3/(double)iter;
  double structr = (double)rs/(double)iter;

  cout << endl 
       << "=====================" << endl;
  cout << "avg gc: " << dgc << endl;
  cout << "avg connections: " << conn << endl;
  cout << "avg hidden nodes: " << avgh << endl;
  cout << "correct structure: " << rs << " out of " << iter << endl;
  cout << "avg time: " << timesum/(double)iter << endl;
  cout << "avg time per gen: " << (timesum/(double)iter)/dgc << endl;
  cout << "=====================" << endl << endl;


  cout << "b nodes:" << sbest->getGenome()->getNodes()->size() << " genes:" << sbest->getGenome()->getGenes()->size() << endl;
  ofstream ofs("sbest-net");
  ofs << sbest->getGenome();
  ofs.close();
  if(dgc<bestgc()){
    cout << "NEW BEST GC!!" << endl;
    writebestgc(dgc);
    writexorsettings("bestgc",dgc,structr,avgh,conn,calcgeneral(dgc,structr,avgh,conn,s),s,args,argc);
  }
  if(structr>beststruct()){
    cout << "NEW BEST struct!!" << endl;
    writebeststruct(structr);
    writexorsettings("beststruct",dgc,structr,avgh,conn,calcgeneral(dgc,structr,avgh,conn,s),s,args,argc);
  }
  if(calcgeneral(dgc,structr,avgh,conn,s)>bestgeneral()){
    cout << "NEW BEST GENERAL!!!!" << endl;
    writebestgeneral(calcgeneral(dgc,structr,avgh,conn,s));
    writexorsettings("bestgeneral",dgc,structr,avgh,conn,calcgeneral(dgc,structr,avgh,conn,s),s,args,argc);
  }
  delete pop;
  delete de;
  delete sel;
  delete rp;
  delete s;

  cout << "seed: " << rands << endl;
  
}
bool rightStruct(Phenotype * p)
{
  nodeVector * nodes = p->getGenome()->getNodes();
  int h=0;
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::HIDDEN)
      h++;

  return h == 1 && p->getGenome()->getGenes()->size() <= 7;
}
double calcgeneral(double gc, double righstruct, double avgh, double conn, NEATsettings * set)
{
  return ((1.0/gc)*set->getValue("gc_coeff"))
    +(righstruct*set->getValue("rightstruct_coeff"))
    +(avgh*set->getValue("avgh_coeff"))
    +(conn*set->getValue("conn_coeff"));
}
double bestgc()
{
  double r = 0;
  ifstream ifs(".best-gc",ios::in);
  if(!ifs.good())
    return RAND_MAX;
  ifs >> r;
  ifs.close();
  return r;
}
double beststruct()
{
  double r = 0;
  ifstream ifs(".best-struct",ios::in);
  if(!ifs.good())
    return 0;
  ifs >> r;
  ifs.close();
  return r;
}
double bestgeneral()
{
  double r = 0;
  ifstream ifs(".best-general",ios::in);
  if(!ifs.good())
    return 0;
  ifs >> r;
  ifs.close();
  return r;
}
void writebestgc(double v)
{
  ofstream ofs(".best-gc",ios::out);
  ofs << v;
  ofs.close();
}
void writebeststruct(double v)
{
  ofstream ofs(".best-struct",ios::out);
  ofs << v;
  ofs.close();
}
void writebestgeneral(double v)
{
  ofstream ofs(".best-general",ios::out);
  ofs << v;
  ofs.close();
}
void writexorsettings(string resulttype, double gc, double rightstruct, 
		   double avgh, double conn, double general, NEATsettings * set, char *args[], int argc) 
{
  stringstream file;
  stringstream commentl1;
  stringstream commentl2;
  time_t heh = time(0);
  struct tm * timeval = localtime(&heh);
  
  //  cout << "ctime of time 0 is: " << ctime(heh) << endl;
  
  file << "results/" << resulttype << "-" << (timeval->tm_year+1900) << "."
       << (timeval->tm_mon+1) << "." << timeval->tm_mday << "." << timeval->tm_hour 
       << timeval->tm_min << "." << timeval->tm_sec << ".settings";
  commentl1 << " " << resulttype << " :" ;
  for(int i=0;i<argc;i++)
    commentl1 << " \"" << args[i] << "\"";
  commentl2 << " general: " << general << " gc: " << gc << " rightstruct: " << rightstruct
	    << " avgh: " << avgh << " conn: " << conn; 
  NEATsettings * printfile = set->duplicate();
  printfile->addTopComment(commentl2.str());
  printfile->addTopComment(commentl1.str());
  ofstream ofs(file.str().c_str(),ios::out);
  ofs << printfile;
  ofs.close();
}
