#include "eval.h"
#include "iface.h"
extern "C" {
  FitnessEvaluator *maker(char * str)
  {
    FitnessEvaluator * ret;
    vector<string> * sv = split(str," ");
    if(sv->at(0).find("dataset")!=string::npos) {
      if(sv->size()!=4){
      cerr << "wrong arguments to eye eval should be: \"dataset <datasetfile> [classification at start[0/1]] [testration]\"" << endl;
	exit(1);
      }
      bool classAtStart = (atoi(sv->at(2).c_str()) == 1) ? true : false;
      double testratio = atof(sv->at(3).c_str());
      DataSet * ds = new DataSet(classAtStart,sv->at(1),testratio);
      ret = new DatasetEvaluator(ds);
      return ret;
    }else
      cerr << "wrong arguments to eye eval should be: \"dataset <datasetfile> [classification at start[0/1]] [testration]\"" << endl;
      return NULL;
  }
}

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
//   cout << "f->getGenome(): " << f->getGenome() << endl;
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
  //cout << "testing: " << c << endl;
  //  if(c!=4)
  //    runTest(f);
  return c==4;
}
