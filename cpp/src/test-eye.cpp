#include <iostream>
#include <iomanip>
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
#include "lightsim/paintwindow.h"
#include <QApplication>


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
  int n = 7;
  cerr << "argc:"<<argc<<endl;
  if(argc!=n){
    eyetestUsage(args[0]);
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

  unsigned int lsnum=s->getValue("number_of_lightsources");
  unsigned int ymax=s->getValue("ymax");
  unsigned int xmax=s->getValue("xmax");;

  FitnessEvaluator * ls2de = new LightsimEvaluator(s,xmax,ymax,lsnum);
  Evaluator * ev = new Evaluator(ls2de); 
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

  /*
  QApplication app(argc,args);
  PaintWindow *pw=new PaintWindow(800,800,100,0.5,NULL);
  */
  Lightsim2D *ls2d;

  for(int i2=0;i2<iter;i2++){
    cout <<"Iteration: "<<i2<<"\n";
    gc = 0;
    best = NULL;
    startt = time(0);
    for(int i=0;i<g;i++){
      cout << "Generation: "<<i<<"\n";
      gc++;
      //      cout << "species before eval : " << pop->getSpecies()->size() << endl;
      ev->evaluate(pop->getMembers(),pop->getMembers()->size());
      if((unsigned int)pop->getOriginalSize()!=pop->getMembers()->size()) {
	cout << "error: size not right after eval.." << endl;
	exit(1);
      }
      ss=pop->getSpecies()->size();
      pop->updateSpeciesStats();
      pop->sortmembers();
      pop->sortspecies();
      cbest = pop->getCopyOfCurrentBest();
      ls2de->f(cbest);
      //      cout << "generation " << i << " : ";
      if(best==NULL){
	best = cbest;
	// 	cout << "setting first best ("<<best->getFitness()<<"):"<<best->getID() << endl;
	// 	cout << "genome:" << best->getGenome();
      }else if(cbest->getFitness()>best->getFitness()){
	delete best;
	best = cbest;
	//	cout << "setting new best ("<<best->getFitness()<<"):"<<best->getID() << endl;
	//	cout << "genome:" << best->getGenome();
      }else{
	//	cout << "cbest not good enough: " << cbest->getFitness() << " :" << cbest->getID() << endl;
	delete cbest;
      }
      
      //Writing best ls2d to disk
      ls2d=new Lightsim2D(0.5,best,xmax,ymax,lsnum);
      ls2d->createVectors();
      ls2d->pruneBlockedVectors();

      /*
      pw->updateLS(ls2d);
      pw->paintWorld();
      pw->show();
      app.exec();
      */

      ofstream fil("data/bestls2d"); 
      fil << ls2d;
      fil.close();
	
      delete ls2d;

      //      cerr << i << ": maxfitness: " << pop->getHighestFitness() << endl;
      sel->select(pop,0);
      rp->reproduce(pop);
      //cout << "species after repro : " << pop->getSpecies()->size() << endl;
      //    if(pop->getHighestFitness()>15.8)
      //      if( ((DatasetEvaluator*)de)->xorDone(pop->getBest()) )
      //	i = g;
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
    /*    if(rightStruct(best)||gc==300){
      // if(best->getGenome()->getGenes()->size()!=7){
// 	cout << "found the wrong structure..fitness: "<<best->getFitness()<<" ..1 hidden node:" << endl;
	cout << best->getGenome();
	((DatasetEvaluator*)de)->runTest(best);
//       }
      rs++;

    }
    */
//     exit(0);
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
