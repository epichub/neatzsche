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
#include "neatmpi.h"

int main(int argc, char *args[])
{
  int n = 4;
  cerr << "argc:"<<argc<<endl;
  if(argc!=n){
    mpitestusage(args[0]);
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
  Neatzsche_MPI * nmpi = new Neatzsche_MPI(argc,args);
  Genome * g = new Genome(tfs);
  
  Population * pop = makePopulation(args[3],s,tfs);
  if(nmpi->getRank()==0){
    nmpi->outputPopulation(pop,nmpi->getSize()-1,NULL,0,true);
    nmpi->readFitness(pop,0);
    MPI_Finalize();
    exit(EXIT_SUCCESS);
  }else{
    Phenotypes * p = new Phenotypes();
    nmpi->readPopulation(p,NULL,tfs);
    for(int i=0;i<p->size();i++){
      p->at(i)->setFitness(randdouble());
    }
    nmpi->outputFitness(p);
    //send the fitnesses back..
    MPI_Finalize();
    exit(EXIT_SUCCESS);
  }
  return 0;
}
