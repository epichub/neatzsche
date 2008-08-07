#include "eval.h"
#include "iface.h"
extern "C" {
  FitnessEvaluator *maker(char * str)
  {
    FitnessEvaluator * ret;
    vector<string> * sv = split(str," ");
    if(sv->at(0).find("random")!=string::npos) {
      if(sv->size()!=1){
      cerr << "wrong arguments to eye eval should be: \"random\"" << endl;
	exit(1);
      }
      ret = new RandomEvaluator();
      return ret;
    }else
      cerr << "wrong arguments to eye eval should be: \"random\"" << endl;
  }
}
double RandomEvaluator::f(Phenotype * f)
{
  double r = randdouble(); f->setFitness(r); return r;
}
