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
  PictureEvaluator(std::string filename, bool img);
  virtual ~PictureEvaluator(){};
  virtual double f(Phenotype * f);
  virtual string show(Phenotype *f){runTest(f); return "printing to tif..";}
  void readimg(std::string filename);
  void readdata(std::string filename);
  double f2(Phenotype * f);
  void runTest(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
  virtual bool stop(Phenotype * f){return false;}
  virtual void setResultdir(string dir){}
};
#endif
