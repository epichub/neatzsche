#ifndef HYPEREVAL_H_
#define HYPEREVAL_H_

#include "evaluator.h"
#include "dataset.h"
#include "dataseteval.h"

class HyperNEAT : public FitnessEvaluator {
protected:
  NEATsettings * settings;
  vector<unsigned int *> * dims;
  TransferFunctions * tfs;
  Network * n;
public:
  HyperNEAT(NEATsettings * set, TransferFunctions * tfs){ this->tfs = tfs;};
  void setDims(vector<unsigned int *> * dims){this->dims = dims;}
  virtual double f(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
  virtual string output(Phenotype * f);
};
class DatasetHyperNEAT : public HyperNEAT {
private:
  DataSet * dataset;
  DatasetEvaluator * d;
public:
  DatasetHyperNEAT(NEATsettings * settings, TransferFunctions * tfs, DataSet * dataset) : HyperNEAT(settings,tfs)
  { this->dataset = dataset; d = new DatasetEvaluator(this->dataset);
    unsigned int * d1 = new unsigned int[2]; d1[0] = dataset->getParams(); d1[1] = 1;
    unsigned int * d2 = new unsigned int[2]; d2[0] = 1; d2[1] = 1;
    unsigned int * d3 = new unsigned int[2]; d3[0] = 1; d3[1] = 1;
    dims = new vector< unsigned int * >();
    dims->push_back(d1);
    dims->push_back(d2);
    dims->push_back(d3); 
    cerr << "params: " << dataset->getParams() << endl;
    cerr << "dims: " << dims->size() << endl;
  };
  virtual double f(Phenotype * f);
  virtual string show(Phenotype * f){return "";}
  bool done(Phenotype *f);
  void runTest(Phenotype *f);
  virtual void nextGen(){return;} // no need for this here..
};
#endif
