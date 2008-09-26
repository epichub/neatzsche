#ifndef DATAEVAL_H_
#define DATAEVAL_H_

#include "evaluator.h"
#include "dataset.h"

class DatasetEvaluator : public FitnessEvaluator {
private:
  DataSet *ds;
public:
  DatasetEvaluator(DataSet * s){ds=s;};
  virtual ~DatasetEvaluator(){};
  virtual FitnessEvaluator *  makeFitnessEvaluator(vector<string> * sv){return NULL;};
  virtual string help(){return "";}
  virtual double f(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
  virtual string show(Phenotype * p) {return "";}
  void runTest(Phenotype * f);
  bool xorDone(Phenotype * f);
  virtual bool stop(Phenotype * f){return xorDone(f);}
  virtual void setResultdir(string dir){}
};

#endif
