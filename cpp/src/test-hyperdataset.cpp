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

/*
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
*/


int main(int argc, char *args[])
{
  int n = 8;
  cerr << "argc:"<<argc<<endl;
  if(argc!=n){
    hyperdatasetUsage(args[0]);
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

  string dfile = args[7];
  DataSet * set = new DataSet(false,dfile,0.0);
  FitnessEvaluator * de = new DatasetHyperNEAT(s,tfs,set);
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
      cout << "before eval.." << endl;
      ev->evaluate(pop->getMembers(),pop->getMembers()->size());
      cout << "after eval.." << endl;
      if((unsigned int)pop->getOriginalSize()!=pop->getMembers()->size())
	cout << "size not right after eval.." << endl;
      ss=pop->getSpecies()->size();
      cout << "before pop juggling.." << endl;
      pop->updateSpeciesStats();
      pop->sortmembers();
      pop->sortspecies();
      cbest = pop->getCopyOfCurrentBest();
      de->f(cbest);
      cout << "before best juggling.." << endl;
      if(best==NULL){
	best = cbest;
      }else if(cbest->getFitness()>best->getFitness()){
	delete best;
	best = cbest;
      }else{
	delete cbest;
      }
      cout << "after best juggling.." << endl;
      if(((DatasetHyperNEAT*)de)->done(best))
	i = g;
      cout << "after xor testing.." << endl;
      sel->select(pop,0);
      rp->reproduce(pop);
      cout << "after select and reproduce.." << endl;
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
	//      oseed->setTfs(pop->getTfs());
	pop->genesis(oseed,osize,oelitism);
      }else{
	pop->resetSpawn();
      }
	
    }
  }

}
