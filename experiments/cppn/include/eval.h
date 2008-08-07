#ifndef CPPNEVAL_H_
#define CPPNEVAL_H_

#include "evaluator.h"
extern "C" {
// #include "image.h"
}
class PictureEvaluator : public FitnessEvaluator {
private:
  vector<double> picdata;
  int picoffset;
  int * sizes;
public:
  PictureEvaluator(std::string filename);
  virtual ~PictureEvaluator(){};
  virtual double f(Phenotype * f);
  virtual string show(Phenotype *f){return "";}
  double f2(Phenotype * f);
  void runTest(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
};
#endif
