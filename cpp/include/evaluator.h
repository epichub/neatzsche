
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

#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include "evolution.h"
#include "dataset.h"
#include "neuralmath.h"
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#ifdef NEATZSCHEOPENMP
#include <omp.h>
#endif

using namespace std;

static vector<double> sensecomp;
class FitnessEvaluator;
class FitnessEvaluator {
protected:
  int st;//0 = singleplayer, 1 = co-evolution
public:
  FitnessEvaluator(){st=0;};
  virtual FitnessEvaluator * makeFitnessEvaluator(vector<string> * sv){return NULL;};
  virtual string help(){}
  virtual double f(Phenotype * f){return 0;}
  virtual double debugeval(Phenotype * f){return 0;}
  virtual ~FitnessEvaluator(){};
  virtual void nexGen(){}; //generational tickers for the evaluators that need this.
  virtual void interact(Phenotype * p){};
  virtual string show(Phenotype * p) = 0;
  virtual void setStatus(int ist){cerr<<"i status set ist:" << ist << endl;st=ist;}
  virtual int getStatus(){return st;}

};


class DatasetEvaluator : public FitnessEvaluator {
private:
  DataSet *ds;
public:
  DatasetEvaluator(DataSet * s){ds=s;};
  virtual ~DatasetEvaluator(){};
  virtual FitnessEvaluator *  makeFitnessEvaluator(vector<string> * sv){return NULL;};
  virtual string help(){}
  virtual double f(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
  void runTest(Phenotype * f);
  bool xorDone(Phenotype * f);
};

class RandomEvaluator : public FitnessEvaluator {
public:
  RandomEvaluator(){}
  virtual ~RandomEvaluator(){};
  virtual FitnessEvaluator *  makeFitnessEvaluator(vector<string> * sv){return NULL;};
  virtual string help(){}
  virtual double f(Phenotype * f){double r = randdouble(); f->setFitness(r); return r;}//muhahaha
  virtual void nextGen(){return;}
};
#ifndef NEATZSCHEOPENMP
class Evaluator {
private:
  FitnessEvaluator * fe;
public:
  Evaluator(FitnessEvaluator * f){fe=f;}
  virtual ~Evaluator(){};
  virtual Phenotypes * evaluate(Phenotypes * ps, unsigned int m)
  {
    for(unsigned int i=0;i<ps->size() && i<m;i++){
      fe->f(ps->at(i));
      ps->at(i)->transferFitness();
    }
    return ps;
  }
  virtual FitnessEvaluator * getFitnessEvaluator(){return fe;}
};
#endif
#ifdef NEATZSCHEOPENMP
class Evaluator {
private:
  FitnessEvaluator * fe;
public:
  Evaluator(FitnessEvaluator * f){fe=f;}
  virtual ~Evaluator(){};
  virtual Phenotypes * evaluate(Phenotypes * ps, unsigned int m)
  {
    int i=0,tid,nthreads,chunk;
//     cerr << "in omp eval" << endl;
#define N m
#define CHUNKSIZE N/10
    chunk = CHUNKSIZE;
#pragma omp parallel shared(m,ps,nthreads,chunk) private(i,tid)
    {
      tid = omp_get_thread_num();
      if (tid == 0)
	{
	  nthreads = omp_get_num_threads();
// 	  cerr << "Number of threads = " << nthreads 
// 	       << "chunksize: " << CHUNKSIZE << "N" << N <<endl;
	}
//       cerr << "Thread "<<tid<<"  starting..." << endl;
#pragma omp for schedule(dynamic,chunk)
      for(i=0;i<N;i++)
	{
	  fe->f(ps->at(i));
	  ps->at(i)->transferFitness();
	}

    }
    return ps;
  }
  virtual FitnessEvaluator * getFitnessEvaluator(){return fe;}
};
#endif
//FitnessEvaluator *maker();

//typedef
FitnessEvaluator *maker_t(char *str);

// our global factory
// extern map<string, maker_t *, less<string> > factory;

//    return new hexapod;
// }

#endif
