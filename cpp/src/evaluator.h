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

#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include "evolution.h"
#include "gowrapper.h"
#include "dataset.h"
#include "neuralmath.h"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

static vector<double> sensecomp;

class FitnessEvaluator {
public:
  FitnessEvaluator(){};
  virtual double f(Phenotype * f){return 0;}
  virtual double debugeval(Phenotype * f){return 0;}
  virtual ~FitnessEvaluator(){};
  virtual void nexGen(){}; //generational tickers for the evaluators that need this.
  virtual void interact(Phenotype * p){};
  virtual string show(Phenotype * p){return "";};
};

class GoEvaluator : public FitnessEvaluator{
protected:
  gw::GoWrapper *g;
  double r;
  int st;//0 = singleplayer, 1 = co-evolution
  int pg;
  int gen;
  double fmax;
  double fmin;
  Phenotype * last;
  double avgMoves;
  double avgPuts;
  double avgPasses;
  int mMoves;
  int mPuts;
  int mPasses;
  int turns;
  NEATsettings * s;
public:
  GoEvaluator(gw::GoWrapper * ig, int status, int puregnugo, double gnugor, NEATsettings * is)
  {g=ig;st=status; pg=puregnugo; r=gnugor;
    last=NULL;gen=turns=mMoves=mPuts=mPasses=0;
    avgMoves = avgPuts = avgPasses = 0.0;s=is;fmax=0;fmin=RAND_MAX;}
  virtual ~GoEvaluator(){delete g;delete s;};
  virtual double f(Phenotype * f);
  virtual double debugeval(Phenotype * f);
  void setStatus(int ist){st=ist;}
  virtual void nextGen();
  virtual string show(Phenotype * f);
  gw::GoWrapper * getGoWrapper(){return g;}
  virtual string getFinishedBoard(Phenotype * p);
  void nullCounters(){avgMoves = avgPuts = avgPasses = 0;}
  void updateStats(){
    turns++;
    avgMoves += g->moves;  avgPuts += g->puts; avgPasses += g->passes;
    if(g->moves>mMoves) mMoves = g->moves;
    if(g->puts>mPuts) mPuts = g->puts;
    if(g->passes>mPasses) mPasses = g->passes;
  }
  string getStats(){
    stringstream ss;
    ss << "moves " << mMoves << " / " << avgMoves/(double)turns
       << " puts: " << mPuts << " / " << avgPuts/(double)turns
       << " passes:" << mPasses << " / " << avgPasses/(double)turns << endl;
    return ss.str();
  }
  virtual void interact(Phenotype * f);
};
class EasyGoEvaluator : public GoEvaluator {
public:
  EasyGoEvaluator(gw::GoWrapper * ig, int status, int puregnugo, double gnugor, NEATsettings * set) : GoEvaluator(ig,status,puregnugo,gnugor,set){}
  //  virtual ~EasyGoEvaluator(){GoEvaluator::~GoEvaluator();};
  virtual double f(Phenotype * f);
  virtual string show(Phenotype * p);
};

class DatasetEvaluator : public FitnessEvaluator {
private:
  DataSet *ds;
public:
  DatasetEvaluator(DataSet * s){ds=s;};
  virtual ~DatasetEvaluator(){};
  virtual double f(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
  void runTest(Phenotype * f);
  bool xorDone(Phenotype * f);
};

class RandomEvaluator : public FitnessEvaluator {
public:
  RandomEvaluator(){}
  virtual ~RandomEvaluator(){};
  virtual double f(Phenotype * f){double r = randdouble(); f->setFitness(r); return r;}//muhahaha
  virtual void nextGen(){return;}
};
class Evaluator {
private:
  FitnessEvaluator * fe;
public:
  Evaluator(FitnessEvaluator * f){fe=f;}
  virtual ~Evaluator(){};
  virtual Phenotypes * evaluate(Phenotypes * ps, unsigned int m)
  {
//     double f=0;
//     time_t startt;
//     double tmp = 0;
//     time_t tmptime;
    cerr << getpid() << " slave starting evaluation " << endl;
    for(unsigned int i=0;i<ps->size() && i<m;i++){
//       startt = time(0);
      fe->f(ps->at(i));
//       tmptime = time(0) - startt;
//       tmp += tmptime;
//       cerr << getpid() << "evaluating genom:" << ps->at(i)->getID() 
// 	   << " : " << f << " time: " << tmptime << endl;
      ps->at(i)->transferFitness();
    }
    cerr << getpid() << " slave done with evaluation " << endl;
//     cerr << "avg time: " << tmp/(double)ps->size() << endl;
    return ps;
  }
  virtual FitnessEvaluator * getFitnessEvaluator(){return fe;}
};

class DistributedEvaluator : public Evaluator {
public:
  DistributedEvaluator(FitnessEvaluator * f) : Evaluator(f) {}
  virtual ~DistributedEvaluator();
  virtual Phenotypes * evaluate(Phenotypes * ps){return NULL;}
};
#endif
