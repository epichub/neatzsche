#include "eval.h"
#include "iface.h"
extern "C" {
  FitnessEvaluator *maker(char * str)
  {
    FitnessEvaluator * ret;
    vector<string> * sv = split(str," ");
    if(sv->at(0).find("helloworld")!=string::npos) {
      if(sv->size()!=1){
      cerr << "wrong arguments to eye eval should be: \"helloworld\"" << endl;
	exit(1);
      }
      ret = new HelloWorldEvaluator();
      return ret;
    }else
      cerr << "wrong arguments to eye eval should be: \"helloworld\"" << endl;
  }
}

double HelloWorldEvaluator::f(Phenotype * f)
{
  double esum = 0;
  vector<double> v; vector<double> inp; inp.push_back(0);
  for(int i=0;i<goal.length();i++){
    f->cleanNet();
    inp.at(0) = ((double)i/numberofAscii);
    v = f->react(inp);
    esum += fabs(((double)goal[i]/numberofAscii)-(v.at(0)));
  }
  f->setFitness(1.0/esum);
  return 1.0/esum;
}
void HelloWorldEvaluator::runTest(Phenotype * f)
{
  vector<double> v;string result = "";
  vector<double> inp; inp.push_back(0);
  for(int i=0;i<goal.length();i++){
    inp.at(0) = ((double)i/numberofAscii);
    f->cleanNet();
    v = f->react(inp);
    result += translateToChar(v.at(0));
    cerr << "input: " << inp.at(0)
	 << " output: " << v.at(0) 
	 << " should have been: " << ((double)goal[i]/numberofAscii)
	 << " diff: " << fabs(((double)goal[i]/numberofAscii) - v.at(0)) << endl;
  }
  cout << "current string: \"" << result << "\"" << endl;
//   cout << "f->getGenome(): " << f->getGenome() << endl;
}
bool HelloWorldEvaluator::helloDone(Phenotype * f)
{
  vector<double> inp; inp.push_back(0);
  vector<double> v;
  int c=0; string result = ""; double heh = 0;
  for(int i=0;i<goal.length();i++){
    f->cleanNet();
    inp.at(0) = ((double)i/numberofAscii);
    v = f->react(inp);
    heh += v.at(0);
    result += translateToChar(v.at(0));
  }
  string decres = "";
  cout << "heh: " << heh << " fitness: "  << f->getFitness() << endl;
  cout << "current string: \"" ; 
  for(int i =0;i<result.length();i++)
    cout << (char)result[i] << " ";
  cout << "\"" << endl;
  cout << "goal    string: \"";
  for(int i =0;i<goal.length();i++)
    cout << (char)goal[i] << " " ;
  cout << "\"" << endl;
  return result.find(goal.c_str())!=string::npos;
}
