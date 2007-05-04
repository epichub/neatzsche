#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "genome.h"
#include "neuralmath.h"
#include "settings.h"
#include "evolution.h"
#include "evoops.h"
#include "dataset.h"
#include <sstream>
#include "iface.h"
#include "gowrapper.h"

bool rightStruct(Phenotype * p);
double bestgc();
double beststruct();
double bestgeneral();
double calcgeneral(double gc, double righstruct, double avgh, double conn, NEATsettings * set);
void writebestgc(double v);
void writebeststruct(double v);
void writebestgeneral(double v);
void writexorsettings(string resulttype, double gc, double righstruct, double avgh, 
		   double conn, double genreal, NEATsettings * set, char *args[], int argc);

int main(int argc,char *args[]){
  int n = 7;
  cerr << "argc:"<<argc<<endl;
  if(argc!=n){
    xortestUsage(args[0]);
    exit(1);
  }

  int rands = 0;
  rands = atoi(args[1]);
  if(rands!=0)
    srand(rands);
  else{
    rands = time(0);
    srand(rands);
    cout << "ny seed: " << rands << endl;
  }

  //1. load the example file
  NEATsettings * s = new NEATsettings();
  ifstream ifs(args[2],ios::in);
  ifs>>s;
  ifs.close();  

  //2. generate the pop
  TransferFunctions * tfs = new TransferFunctions(s);
  Population * pop = makePopulation(args[3],s,tfs);
  
  //3. then the selector
  Selector * sel = makeSelector(args[4]);

  int g = atoi(args[5]);
  int iter = atoi(args[6]);

  string dfile = "data/xor.data";
  FitnessEvaluator * de = new DatasetEvaluator(new DataSet(false,dfile,0.0));
  Evaluator * ev = new Evaluator(de); 
  LocalReproducer * rp = new LocalReproducer();
  int gc = 0; double sum=0; double sum2=0; double sum3=0;
  Phenotype * cbest = NULL;
  Phenotype * sbest = NULL;
  Phenotype * best = NULL;
  int osize=pop->getMembers()->size();
  int rs = 0; int ss=0;
  double ocomp=0;
  time_t startt;
  double timesum = 0;
  for(int i2=0;i2<iter;i2++){
    gc = 0;
    best = NULL;
    startt = time(0);
    for(int i=0;i<g;i++){
      gc++;
      //      cout << "species before eval : " << pop->getSpecies()->size() << endl;
      ev->evaluate(pop->getMembers(),pop->getMembers()->size());
      if((unsigned int)pop->getOriginalSize()!=pop->getMembers()->size())
	cout << "size not right after eval.." << endl;
      ss=pop->getSpecies()->size();
      pop->updateSpeciesStats();
      pop->sortmembers();
      pop->sortspecies();
      cbest = pop->getCopyOfCurrentBest();
      de->f(cbest);
      //      cout << "generation " << i << " : ";
      if(best==NULL){
	best = cbest;
// 	cout << "setting first best ("<<best->getFitness()<<"):"<<best->getID() << endl;
// 	cout << "genome:" << best->getGenome();
      }else if(cbest->getFitness()>best->getFitness()){
	delete best;
	best = cbest;
	//	cout << "setting new best ("<<best->getFitness()<<"):"<<best->getID() << endl;
	//	cout << "genome:" << best->getGenome();
      }else{
	//	cout << "cbest not good enough: " << cbest->getFitness() << " :" << cbest->getID() << endl;
	delete cbest;
      }
      //      cerr << i << ": maxfitness: " << pop->getHighestFitness() << endl;
      if(((DatasetEvaluator*)de)->xorDone(best))
	i = g;
      sel->select(pop,1);
      rp->reproduce(pop);
      //cout << "species after repro : " << pop->getSpecies()->size() << endl;
      //    if(pop->getHighestFitness()>15.8)
      //      if( ((DatasetEvaluator*)de)->xorDone(pop->getBest()) )
      //	i = g;
    }
    if(sbest==NULL)
      sbest = best;
    else if(best->getFitness()>sbest->getFitness())
      sbest = best;
    time_t ft = time(0)-startt;
    timesum += ft;
    cout << "run: "<<i2+1<<" gc: "<<gc<<" maxfitness: " << pop->getHighestFitness() 
	 << " sbest fitness: " << sbest->getFitness() << " species: " << ss 
	 << " time: " << ft << " time/gen: " << (double)ft/(double)gc << endl;
    sum += gc;
    sum2 += best->getGenome()->extrons();
    sum3 += best->getGenome()->countHidden();
    if(rightStruct(best)){
      // if(best->getGenome()->getGenes()->size()!=7){
// 	cout << "found the wrong structure..fitness: "<<best->getFitness()<<" ..1 hidden node:" << endl;
	cout << best->getGenome();
	((DatasetEvaluator*)de)->runTest(sbest);
//       }
      rs++;
    }
    if(i2!=iter){
      Genome * oseed = pop->getOriginalSeed();
      int oelitism = pop->getOriginalInitialElitism();
      ocomp = pop->getOcomp();
      delete pop;
      pop = new Population(s,ocomp,tfs);
      //      oseed->setTfs(pop->getTfs());
      pop->genesis(oseed,osize,oelitism);
    }
  }
  double dgc = sum/(double)iter;
  double conn = sum2/(double)iter;
  double avgh = sum3/(double)iter;
  double structr = (double)rs/(double)iter;

  cout << endl 
       << "=====================" << endl;
  cout << "avg gc: " << dgc << endl;
  cout << "avg connections: " << conn << endl;
  cout << "avg hidden nodes: " << avgh << endl;
  cout << "correct structure: " << rs << " out of " << iter << endl;
  cout << "avg time: " << timesum/(double)iter << endl;
  cout << "avg time per gen: " << (timesum/(double)iter)/dgc << endl;
  cout << "=====================" << endl << endl;
  //Genome * b = pop->getBest()->getGenome();
  ((DatasetEvaluator*)de)->runTest(sbest);
  cout << "b nodes:" << sbest->getGenome()->getNodes()->size() << " genes:" << sbest->getGenome()->getGenes()->size() << endl;
  ofstream ofs("sbest-net");
  ofs << sbest->getGenome();
  ofs.close();
  if(dgc<bestgc()){
    cout << "NEW BEST GC!!" << endl;
    writebestgc(dgc);
    writexorsettings("bestgc",dgc,structr,avgh,conn,calcgeneral(dgc,structr,avgh,conn,s),s,args,argc);
  }
  if(structr>beststruct()){
    cout << "NEW BEST struct!!" << endl;
    writebeststruct(structr);
    writexorsettings("beststruct",dgc,structr,avgh,conn,calcgeneral(dgc,structr,avgh,conn,s),s,args,argc);
  }
  if(calcgeneral(dgc,structr,avgh,conn,s)>bestgeneral()){
    cout << "NEW BEST GENERAL!!!!" << endl;
    writebestgeneral(calcgeneral(dgc,structr,avgh,conn,s));
    writexorsettings("bestgeneral",dgc,structr,avgh,conn,calcgeneral(dgc,structr,avgh,conn,s),s,args,argc);
  }
  delete pop;
  delete de;
  delete sel;
  delete rp;
  delete s;

  cout << "seed: " << rands << endl;
  
}
bool rightStruct(Phenotype * p)
{
  nodeVector * nodes = p->getGenome()->getNodes();
  int h=0;
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::HIDDEN)
      h++;

  return h == 1 && p->getGenome()->getGenes()->size() <= 7;
}
double calcgeneral(double gc, double righstruct, double avgh, double conn, NEATsettings * set)
{
  return ((1.0/gc)*set->getValue("gc_coeff"))
    +(righstruct*set->getValue("rightstruct_coeff"))
    +(avgh*set->getValue("avgh_coeff"))
    +(conn*set->getValue("conn_coeff"));
}
double bestgc()
{
  double r = 0;
  ifstream ifs(".best-gc",ios::in);
  if(!ifs.good())
    return RAND_MAX;
  ifs >> r;
  ifs.close();
  return r;
}
double beststruct()
{
  double r = 0;
  ifstream ifs(".best-struct",ios::in);
  if(!ifs.good())
    return 0;
  ifs >> r;
  ifs.close();
  return r;
}
double bestgeneral()
{
  double r = 0;
  ifstream ifs(".best-general",ios::in);
  if(!ifs.good())
    return 0;
  ifs >> r;
  ifs.close();
  return r;
}
void writebestgc(double v)
{
  ofstream ofs(".best-gc",ios::out);
  ofs << v;
  ofs.close();
}
void writebeststruct(double v)
{
  ofstream ofs(".best-struct",ios::out);
  ofs << v;
  ofs.close();
}
void writebestgeneral(double v)
{
  ofstream ofs(".best-general",ios::out);
  ofs << v;
  ofs.close();
}
void writexorsettings(string resulttype, double gc, double rightstruct, 
		   double avgh, double conn, double general, NEATsettings * set, char *args[], int argc) 
{
  stringstream file;
  stringstream commentl1;
  stringstream commentl2;
  time_t heh = time(0);
  struct tm * timeval = localtime(&heh);
  
  //  cout << "ctime of time 0 is: " << ctime(heh) << endl;
  
  file << "results/" << resulttype << "-" << (timeval->tm_year+1900) << "."
       << (timeval->tm_mon+1) << "." << timeval->tm_mday << "." << timeval->tm_hour 
       << timeval->tm_min << "." << timeval->tm_sec << ".settings";
  commentl1 << " " << resulttype << " :" ;
  for(int i=0;i<argc;i++)
    commentl1 << " \"" << args[i] << "\"";
  commentl2 << " general: " << general << " gc: " << gc << " rightstruct: " << rightstruct
	    << " avgh: " << avgh << " conn: " << conn; 
  NEATsettings * printfile = set->duplicate();
  printfile->addTopComment(commentl2.str());
  printfile->addTopComment(commentl1.str());
  ofstream ofs(file.str().c_str(),ios::out);
  ofs << printfile;
  ofs.close();
}
