#ifndef RANDEVAL_H_
#define RANDEVAL_H_

#include "evaluator.h"

class RandomEvaluator : public FitnessEvaluator {
public:
  RandomEvaluator(){}
  virtual ~RandomEvaluator(){};
  virtual FitnessEvaluator *  makeFitnessEvaluator(vector<string> * sv){return NULL;};
  virtual string help(){return "";}
  virtual string show(Phenotype * f){return "";}
  virtual double f(Phenotype * f);
  virtual void nextGen(){return;}
};
#endif
