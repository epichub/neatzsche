#ifndef GOEVAL_H_
#define GOEVAL_H_
#include "evaluator.h"
#include "gowrapper.h"
#include "iface.h"

class GoEvaluator : public FitnessEvaluator {

protected:
  gw::GoWrapper *g;
  double r;

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

  //tmp vars for f calc..
  double fsum;
  double ssum;
  double ftmp;
  double stmp;
  int moves;
  vector<double>sense;
  Phenotype * c;
  Phenotype ** players;
  int count;
  bool first;
  
public:
  GoEvaluator(gw::GoWrapper * ig, int status, int puregnugo, double gnugor, NEATsettings * is)
  {g=ig;st=status; pg=puregnugo; r=gnugor;
    last=NULL;gen=turns=mMoves=mPuts=mPasses=0;
    avgMoves = avgPuts = avgPasses = 0.0;s=is;fmax=0;fmin=RAND_MAX;
    players = new Phenotype * [2];detrm=false;}
  virtual ~GoEvaluator(){delete g;delete s; delete[] players;};
  virtual double f(Phenotype * f);
  virtual double debugeval(Phenotype * f);

  virtual void nextGen();
  virtual string show(Phenotype * f);
  gw::GoWrapper * getGoWrapper(){return g;}
  virtual string getFinishedBoard(Phenotype * p);
  void nullCounters(){avgMoves = avgPuts = avgPasses = 0;}
  void updateStats(){
    turns++;
    avgMoves += g->moves;  avgPuts += g->getPuts(); avgPasses += g->passes;
    if(g->moves>mMoves) mMoves = g->moves;
    if(g->getPuts()>mPuts) mPuts = g->getPuts();
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
  bool detrm;
  vector<double> netinp;
  virtual bool stop(Phenotype * f){return false;}
  virtual void setResultdir(string dir){}
};
class EasyGoEvaluator : public GoEvaluator {
public:
  EasyGoEvaluator(gw::GoWrapper * ig, int status, int puregnugo, double gnugor, NEATsettings * set) : GoEvaluator(ig,status,puregnugo,gnugor,set){}
  //  virtual ~EasyGoEvaluator(){GoEvaluator::~GoEvaluator();};
  virtual double f(Phenotype * f);
  virtual string show(Phenotype * p);
  virtual bool stop(Phenotype * f){return false;}
  virtual void setResultdir(string dir){}
};

#endif
