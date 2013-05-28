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
    double fitness = 0;
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
    v = f->react(*ds->getTrain(i));
    esum += fabs(ds->getClass(true,i)-(v.at(0)));
  }
    fitness=(1.0/(esum*esum));
  f->setFitness(fitness);
    //  f->setFitness(1.0-esum/(double)ds->getTrainings());
  //f->setFitness(fabs(ds->getTrainings()-esum));
   if(f->getFitness()>0.68)
   {
       int iii  = 0;
   }
   // if(esum < 0.8 ){
   //     exit(0);
   // }
  return fitness;
}
void DatasetEvaluator::runTest(Phenotype * f)
{
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
      v = f->react(*ds->getTrain(i));
    //f->cleanNet();
    cerr << "input: " << printvector(*ds->getTrain(i))
	 << " output: " << v.at(0) 
	 << " should have been: " << ds->getClass(true,i) 
	 << " diff: " << fabs(ds->getClass(true,i) - v.at(0)) << endl;
      
  }
    cerr << (f->getGenome());
//   cout << "f->getGenome(): " << f->getGenome() << endl;
}
double limit = 0.1;
bool DatasetEvaluator::xorDone(Phenotype * f)
{
  vector<double> v;
  int c=0;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
    v = f->react(*ds->getTrain(i));
    if(fabs(ds->getClass(true,i) - v.at(0))<limit) c++;
  }
  cout << "testing: " << c << endl;
    if(c==4)
      runTest(f);
    else if(randdouble()>0.9)
        runTest(f);
  return c==4;
}
