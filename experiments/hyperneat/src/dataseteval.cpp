#include "eval.h"
#include "iface.h"
double DatasetEvaluator::f(Phenotype * f)
{
  double esum = 0;
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
    v = f->react(*ds->getTrain(i));
    esum += fabs(ds->getClass(true,i)-(v.at(0)));
  }
  f->setFitness(ds->getTrainings()-esum);
  return ds->getTrainings()-esum;
}
void DatasetEvaluator::runTest(Phenotype * f)
{
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    v = f->react(*ds->getTrain(i));
    f->cleanNet();
    cerr << "input: " << printvector(*ds->getTrain(i))
	 << " output: " << v.at(0) 
	 << " should have been: " << ds->getClass(true,i) 
	 << " diff: " << fabs(ds->getClass(true,i) - v.at(0)) << endl;
  }
}
bool DatasetEvaluator::xorDone(Phenotype * f)
{
  vector<double> v;
  int c=0;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
    v = f->react(*ds->getTrain(i));
    if(fabs(ds->getClass(true,i) - v.at(0))<0.4) c++; 
  }
  return c==4;
}
