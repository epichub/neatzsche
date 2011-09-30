#ifndef DATAEVAL_H_
#define DATAEVAL_H_

#include "evaluator.h"
#include <stdio.h>
#include <stdlib.h>
string goal = "Hello World!";
double numberofAscii=115;
class HelloWorldEvaluator : public FitnessEvaluator {
private:
  string goaldec;
public:
  HelloWorldEvaluator(){

};
  virtual ~HelloWorldEvaluator(){};
  virtual FitnessEvaluator *  makeFitnessEvaluator(vector<string> * sv){return NULL;};
  virtual string help(){return "";}
  virtual double f(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
  virtual string show(Phenotype * p) {return "";}
  void runTest(Phenotype * f);
  bool helloDone(Phenotype * f);
  virtual bool stop(Phenotype * f){return helloDone(f);}
  virtual void setResultdir(string dir){}

};

char translateToChar(double d)
{
  return (char)(numberofAscii*d);
}
#endif
