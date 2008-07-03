/*
  Copyright 2007 Bj�rn Magnus Mathisen
  This file is part of NEATzsche.

  NEATzsche is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  NEATzsche is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NEATzsche; if not, write to the Free Software Foundation,
  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 */

#ifndef IFACE_H_
#define IFACE_H_

//this should contain general interface code..
#include "evolution.h"
#include "evaluator.h"
#include <vector>
#include "neuralmath.h"
#include "coevolution.h"
#include "neatmpi.h"
//#include "runner.h"

static inline vector<string> * split(char * args, string delim)
{
  string s = args;
  vector<string> * ret = new vector<string>();
  while(s.find(delim)!=string::npos){
    int n = s.find(delim);
    string tmp = s.substr(0,n);
    ret->push_back(tmp);
    s = s.substr(n+1,s.length());
  }
  if(s.length()>0)
    ret->push_back(s);
  return ret;
}

/*
  input:
       spawn [input nodes] [output nodes] [hidden nodes] 
         0         1              2              3
       [link probability] [population size]
               4                 5   
       [transferfunc]
               6  
  eller
       genesis [genome-file] [population size] [elitism]
         0           1                 2          3
 */


static inline string makepopulationUsage()
{
  string s = "\t[pop options] = \"spawn [input nodes] [output nodes] [hidden nodes] [link probability] [population size]\"\n";
  s += "\t[pop options2] = \"genesis [genome-file] [population size] [initial elitism]\"\n";
  return s;
}
static inline Population * makePopulation(char * args, NEATsettings * s, TransferFunctions * tfs)
{
  vector<string> * sv = split(args," ");
  if(sv->size()<4){//minimum of arguments
    cerr << "wrong number of arguments to population setup method" << endl;
    exit(1);
  }
  Population * ret = new Population(s,tfs);
  if(sv->at(0).find("spawn")!=string::npos){
    if(sv->size()!=6){
      cerr << "wrong number of arguments to spawn population setup method" << endl;
      exit(1);
    }
    int input = atoi(sv->at(1).c_str());
    int output = atoi(sv->at(2).c_str());
    int hidden = atoi(sv->at(3).c_str());
    double linkprob = atof(sv->at(4).c_str());
    double spawnrecprob = s->getValue("spawn_recur_prob");
    int pops = atoi(sv->at(5).c_str());
    ret->randomSpawn(pops,input,output,hidden,hidden,linkprob,spawnrecprob);
  }else{
    if(sv->size()!=4){
      cerr << "wrong number of arguments to genesis setup method" << endl;
      exit(1);
    }
    ifstream ifs(sv->at(1).c_str(),ios::in);
    Genome * g = new Genome(ret->getTfs());
    ifs>>g;
    ifs.close();
    int pops = atoi(sv->at(2).c_str());
    ret->genesis(g,pops,1);
  }
  delete sv;
  return ret;
}

/*
  input:
       go [pure gnugo-gens] [ratio of gnugo] 
  eller
       dataset [datasetfile] [class at first] [percentage of test]
  eller
       random
 */
static inline string makefitnessevaluatorUsage(){
  string s = "\t[phenotype eval options] = \"go [pure gnugo-gens] [ratio of gnugo] [coevoopponents] [easygo 0/1] [caching support 0/1] [cache size] [cache queue size] [resign allowed 0/1]\" (PS: needs the gosettings file)\n";
  s += "\t[phenotype eval options2] = \"dataset [datasetfile] [class at first] [percentage of test]\"\n";
  s += "\t[phenotype eval options2] = \"random\"\n";
  return s;
}
static inline FitnessEvaluator * makeFitnessEvaluator(char * args, Coevolution *& coevo)
{
  FitnessEvaluator * ret = NULL;
  vector<string> * sv = split(args," ");
  if(sv->size()<1){
    cerr << "wrong number of arguments to fitness evalator setup method" << endl;
    exit(1);
  }
  if(sv->at(0).find("go")!=string::npos){
    if(sv->size()!=9){
      cerr << "wrong number of arguments to go evalator setup method, got " << sv->size() << " need 9 " << endl;
      exit(1);
    }
    NEATsettings * set = new NEATsettings();
    ifstream ifs("settings/settings-gnugo",ios::in);
    ifs >> set;
    ifs.close();
    int size = (int)set->getValue("size");
    double outsidev = set->getValue("outsidevalue");
    double komi = set->getValue("komi");
    int mem = (int)set->getValue("mem");
    int level = (int)set->getValue("level");
    int eyesize = (int)set->getValue("eyesize");
    int maxlooksteps = (int)set->getValue("maxlooksteps");
    bool caching = atoi(sv->at(5).c_str()) == 1;
    int csize = atoi(sv->at(6).c_str());
    int cqsize = atoi(sv->at(7).c_str());
    bool resign = atoi(sv->at(8).c_str()) == 1;
    gw::GoWrapper * gw = NULL;
    if(caching){
      gw = new gw::CachingGoWrapper(size,true,outsidev,
				komi,level,eyesize,maxlooksteps,mem,csize,cqsize);
    }else{
      gw = new gw::GoWrapper(size,true,outsidev,
			 komi,level,eyesize,maxlooksteps,mem);
    }
    gw->setResignAllowed(resign);
    int pg = atoi(sv->at(1).c_str());
    double r = atof(sv->at(2).c_str());
    int cogames = atoi(sv->at(3).c_str());
    int gnugogames = 1;//atleast one game per round against gnugo.
    gnugogames += (int)(r*cogames);
    cogames -= gnugogames;
    bool easy = atoi(sv->at(4).c_str()) == 1;


    if(!easy){
      ret = new GoEvaluator(gw,0,pg,r,set);
    }else{
      cerr << "making easygoeval!" << endl;
      ret = new EasyGoEvaluator(gw,0,pg,r,set);
    }
    coevo = new Halloffame(cogames,cogames,pg,ret);
    for(int i=0;i<gnugogames;i++){
      ((Halloffame*)coevo)->addPermantent(NULL);//adding NULL as permanent member, defaults to gnugo in this fitness 
    }
  }else if(sv->at(0).find("eye")!=string::npos) {
    if(sv->size()!=2){
      cerr <<  "wrong number of arguments to eye evalator setup method" << endl;
      exit(1);
    }
    NEATsettings * set = new NEATsettings();
    ifstream ifs(sv->at(1).c_str(),ios::in);
    ifs >> set;
    ifs.close();
    unsigned int lsnum=set->getValue("number_of_lightsources");
    unsigned int ymax=set->getValue("ymax");
    unsigned int xmax=set->getValue("xmax");
    unsigned int ls_dist=set->getValue("ls_distance");
    double cellsize=set->getValue("cellsize");
    ret = new LightsimEvaluator(set,xmax,ymax,lsnum,cellsize,ls_dist);
    coevo = new Halloffame(0,0,1000000,ret);
  }else if(sv->at(0).find("random")!=string::npos)
        ret = new RandomEvaluator();
  else if(sv->at(0).find("dataset")!=string::npos){
    if(sv->size()!=4){
      cerr << "wrong number of arguments to dataset evalator setup method" << endl;
      exit(1);
    }
    string file = sv->at(1);
    bool first = (sv->at(2).find("1")!=string::npos) ? true : false ;
    double p = atof(sv->at(3).c_str());
    ret  = new DatasetEvaluator(new DataSet(first,file.c_str(),p));
    coevo = new Halloffame(0,0,1000000,ret);
  }else{
    cerr << "wrong fitness evaluator arguments" << endl;
  }
  delete sv;
  return ret;
}

/*
  input:
       << "\t[selector options] = \"fp [number of top species getting elitism]\""<<endl
       << "\t[selector options2] = \"rank [s] [number of top species getting elitism]\""<<endl
       << "\t[selector options3] = \"sigma\" [number of top species getting elitism]"<<endl
 */
static inline string makeselectorUsage(){
  string s =  "\t[selector options] = \"fp [number of top species getting elitism]\"\n";
  s += "\t[selector options2] = \"rank [s] [number of top species getting elitism]\"\n";
  s += "\t[selector options3] = \"sigma [number of top species getting elitism]\"\n";
  return s;
}
static inline Selector * makeSelector(char * args)
{
  Selector * ret = NULL;
  vector<string> * sv = split(args," ");
  if(sv->size()<2){
    cerr << "wrong number of arguments to selection setup method" << endl;
    exit(1);
  }
  if(sv->at(0).find("fp")!=string::npos){
    if(sv->size()!=2){
      cerr << "wrong number of arguments to fitness proportionate setup method" << endl;
      exit(1);
    }
    int e = atoi(sv->at(1).c_str());
    ret = new FitnessProp(e);
  }else if(sv->at(0).find("sigma")!=string::npos){
    if(sv->size()!=2){
      cerr << "wrong number of arguments to sigma selection setup method" << endl;
      exit(1);
    }
    int e = atoi(sv->at(1).c_str());
    ret = new SigmaScaling(e);
  }else{
    if(sv->size()!=3){
      cerr << "wrong number of arguments to rankselection setup method" << endl;
      exit(1);
    }
    double s = atof(sv->at(1).c_str());
    int e = atoi(sv->at(2).c_str());
    ret = new RankSelection(s,e);
  }
  delete sv;
  return ret;

}
static inline string makecommunicatorUsage(){
  string s =  "\t[communicator options] = \"mpi\"\n";
  s += "\t[communicator options2] = \"boye\"\n";
  return s;
}
static inline Neatzsche_Comm * makeCommunicator(char * args, char **argv, int argc)
{
  vector<string> * sv = split(args," ");
  Neatzsche_Comm * ret = NULL;
  if(sv->at(0).find("mpi")!=string::npos){
    if(sv->size()!=1){
      cerr << "wrong number of arguments to mpi communicator setup method" << endl;
      exit(1);
    }
    ret = new Neatzsche_MPI(argc,argv);
  }else { //boye
    if(sv->size()!=1){
      cerr << "wrong number of arguments to boye communicator setup method" << endl;
      exit(1);
    }
    ret = new Neatzsche_Boye();
  }
  return ret;
}
// input: "<id> <fitness>"

static inline void sendExitToken(bool exit){
  string cmd = (exit) ? "EXIT" : "NOEXIT" ;
  cout << cmd << endl ;
}
static inline bool readExitToken(){
  string s;
  cin >> s;
  if(s.find("NOEXIT")==string::npos)
    return false;
  return true;
}
static inline void cleanupPopulation(Phenotypes * p)
{
  for(unsigned int i=0;i<p->size();i++)
    delete p->at(i);
  delete p;
}
static inline void setChamp(Phenotype *& oldchamp, Phenotype * challenger)
{
  if((&oldchamp == &challenger) || (oldchamp!=NULL && (oldchamp->getID()==challenger->getID() && oldchamp->getFitness() == challenger->getFitness()))){
    delete challenger;
    return;
  }
  if(oldchamp==NULL){
    oldchamp = challenger;
  }else if(oldchamp->getFitness()<challenger->getFitness()){
    delete oldchamp;
    oldchamp = challenger;
  }else{
    delete challenger;
  }
    
}
//"topf avgf minf"
static inline string getStatString(Population * p, double avg)
{
  stringstream ss;
  Phenotypes * ph = p->getMembers();
  ss << ph->at(0)->getFitness() << " " << avg << " "<<  ph->at(ph->size()-1)->getFitness() << endl;
  return ss.str();
}
static inline void updateSmoothData(double ** d, Population *p, double avg, int runs)
{
  Phenotypes * ph = p->getMembers();
  int gen = p->getGeneration();
  d[gen][0] = (d[gen][0]+ph->at(0)->getFitness());
  d[gen][1] = (d[gen][1]+avg);
  d[gen][2] = (d[gen][2]+ph->at(ph->size()-1)->getFitness());
}
static inline void writeRunfile(bool ended, string basefile, string infoline, int pid)
{
  stringstream ss; ss << pid << ".runinfo";
  ofstream rfile(ss.str().c_str());
  rfile << basefile << endl << (ended ? "ended" : "notended") << endl << infoline;
  rfile.close();
}
static inline void neatzscheUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options] [selector option] [phenotype eval] [communicator] [stopcondition]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush
       << makeselectorUsage() << flush
       << makefitnessevaluatorUsage() << flush
       << makecommunicatorUsage() << flush
       << "\t[stop condition1] = \"count [generations] [runs]\""<<endl << flush
       << "\t[stop condition2] = \"key\""<<endl;
}
static inline void masterUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options] [selector option] [nodes] [phenotype eval] [stopcondition] [pipeiomode (0/1)]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush
       << makeselectorUsage() << flush
       << makefitnessevaluatorUsage() << flush
       << makecommunicatorUsage() << flush
       << "\t[stop condition1] = \"count [generations] [runs]\""<<endl << flush
       << "\t[stop condition2] = \"key\""<<endl;
}
static inline void slaveUsage(string progname)
{
  cerr << "usage: " << endl
       << progname << " [seed (0 for new)] [settings] [phenotype eval options] [generations]" << endl
       << "where:" << endl
       << makefitnessevaluatorUsage() << endl
       << makecommunicatorUsage() << flush;
}
static inline void xortestUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options] [selector option] [maxgenerations] [iterations to run benchmark over]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush
       << makeselectorUsage() << flush ; 
}
static inline void hyperdatasetUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options] [selector option] [maxgenerations] [iterations to run benchmark over] [datasetfile]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush
       << makeselectorUsage() << flush ; 
}
static inline void drawtestUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options] [selector option] [maxgenerations] [iterations to run benchmark over] [tiff picture reference file]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush
       << makeselectorUsage() << flush ; 
}
static inline void mpitestusage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush ; 
}
static inline void eyetestUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options] [selector option] [maxgenerations] [iterations to run benchmark over]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush
       << makeselectorUsage() << flush ; 
}
static inline void gotestUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [settings file] [pop options] [selector option] [phenotype eval options] [maxgenerations] [iterations..]" << endl
       << "where:" << endl << flush
       << makepopulationUsage() << flush
       << makeselectorUsage() << flush 
       << makefitnessevaluatorUsage() << flush ; 
}
static inline void playgameUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [go genome] [easymode 0/1]" << endl;
}
static inline void goconstUsage(string progname)
{
  cerr << "usage: (all the node numbers are for the initial generation) " << endl
       << progname << " [seed (0 for new)] [iterations] [pops] [respawns]" << endl;
}
static inline string getTimeString()
{
  stringstream ss;
  time_t heh = time(0);
  struct tm * timeval = localtime(&heh);
  ss << (timeval->tm_year+1900) << "."
     << (timeval->tm_mon+1) << "." << timeval->tm_mday << "." << timeval->tm_hour 
     << timeval->tm_min << "." << timeval->tm_sec ; 
  return ss.str();
}
static inline string getPureTimeString(){
  time_t heh = time(0);
  struct tm * timeval = localtime(&heh);
  stringstream file;
  file << (timeval->tm_year+1900)
       << (timeval->tm_mon+1) << timeval->tm_mday << timeval->tm_hour 
       << timeval->tm_min << timeval->tm_sec;
  return file.str();
}
static inline void writesettings(string resulttype, double result, NEATsettings * set, char *args[], int argc) 
{
  stringstream file;
  stringstream commentl1;
  stringstream commentl2;

  string timestr = getTimeString();
  file << "results/" << resulttype << "-" << timestr << ".settings";
  commentl1 << " " << resulttype << " :" ;
  for(int i=0;i<argc;i++)
    commentl1 << " \"" << args[i] << "\"";
  commentl2 << " resultvalue: " << result;
  NEATsettings * printfile = set->duplicate();
  printfile->addTopComment(commentl2.str());
  printfile->addTopComment(commentl1.str());
  ofstream ofs(file.str().c_str(),ios::out);
  ofs << printfile;
  ofs.close();
}
static inline void addToAllSignals(void (*signalhandler)(int sig))
{
  (void)signal(SIGINT,signalhandler);
  (void)signal(SIGTERM,signalhandler);
  (void)signal(SIGQUIT,signalhandler);
  (void)signal(SIGABRT,signalhandler);
  (void)signal(SIGTTIN,signalhandler);
  (void)signal(SIGTTOU,signalhandler);
  (void)signal(SIGKILL,signalhandler);
}
#endif

