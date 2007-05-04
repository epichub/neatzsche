/*
  Copyright 2007 Bjørn Magnus Mathisen
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

#ifndef EVOLUTION_H_
#define EVOLUTION_H_
#include "genome.h"
#include "settings.h"

//#include "evoops.h"

using namespace std;

class Species;

class Phenotype{
private:
  Genome * g;
  double f;
  double of;
  double eoffspring;
  Network * net;
  Species * spec;
  bool died;
  bool specchamp;
  int popchampclones;
  int clones;
public:
  Phenotype(Genome * ig){
    g=ig;net = g->genesis();
    died=false;popchampclones=clones=0;specchamp=false;f=0;eoffspring=0;spec=NULL;of=0;}
  ~Phenotype(){
    delete net;
    delete g;
  }
  void genesis(){net = g->genesis();}
  void cleanup(){delete net;}
  void setPopulationChampClones(int c){popchampclones = c;}
  int getPopulationChampClones(){return popchampclones;}
  void decPopulationChampClones(){popchampclones--;}
  Network * getNet(){return net;}
  void cleanNet(){net->cleanup();}
  Genome * getGenome(){return g;}
  void setGenome(Genome * ig){g=ig;}
  vector< double > react(vector<double> inp){return net->runnet(inp);}
  double getFitness(){return f;}
  void setFitness(double fi){f = fi;}
  void augmentFitness(double c){f *= c;}
  double getOrigFitness(){return of;}
  void transferFitness(){of=f;}
  string outputFType(){stringstream ss; ss << "lvl: " << net->getOutput()->getDepth() << " ftype: " << net->getOutput()->getFType() << " type: " << net->getOutput()->getType(); return ss.str();}
  void updatePhenotype(){delete net; net = g->genesis();}
  int getID(){return g->getID();}
  void setSpecies(Species * ispec);
  Species * getSpecies(){return spec;}
  void markDead(){died = true;}
  bool isDead(){return died;}
  void setSpeciesChamp(){specchamp = true;}
  bool getSpeciesChamp(){return specchamp;}
  double getExpected(){return eoffspring;}
  void setEOffspring(double i){eoffspring = i;}
  void incEOffspring(){eoffspring++;}
  void decEOffspring(){eoffspring--;}
  void incClones(){clones++;}
  void addToClones(int add){clones += add;}
  void decClones(){clones--;}
  int getClones(){return clones;}
  void setOffspringToAvg(double avg){eoffspring = f/avg;}
};

inline bool phenocomp(Phenotype * p1, Phenotype * p2){return p1->getOrigFitness() > p2->getOrigFitness();}

typedef vector<Phenotype *> Phenotypes;
class Population;
class Species {
private:
  Phenotypes * members;
  Phenotypes * children;
  int id;
  int age;
  int lastimprov;
  int expectedoffspring;
  double avgf;
  double maxf;
  double minf;
  double globalmaxf;
  double historicaltopf;
  double sumf;
  Phenotype * first;
  Phenotype * champ;
  NEATsettings * set;
  Population * p;
public:
  Species(int iid, NEATsettings * iset, Population * ip)
  {
    p=ip;set=iset;avgf=maxf=globalmaxf=historicaltopf=0;id = iid;
    members = new Phenotypes();expectedoffspring=0;age=0;
    lastimprov=0;champ=NULL;children = new Phenotypes();sumf=0;first=NULL;}
  ~Species();
  void incAge(){age++;}
  Phenotype * findCenter(Phenotype * ofirst);
  Phenotype * findBest(Phenotype * ofirst);
  void addPhenotype(Phenotype * p){if(first==NULL)first=p;
    members->push_back(p);p->setSpecies(this);}
  void addChild(Phenotype * p){
    children->push_back(p);p->setSpecies(this);}
  void transferChildren();
  void removePhenotype(Phenotype * p);
  void fsort();//sorts the species on fitness.
  Phenotypes * getMembers(){return members;}//for faster lookup
  Phenotypes * getChildren(){return children;}
  Phenotype * firstMember(){return first;}//as done in kens kode.
  Phenotype * getChamp(){return champ;}
  void adjustFitness(NEATsettings *set);
  void updateavgf();
  double getAvgFitness(){return avgf;}
  void updatemaxminf();
  double getSumFitness(){return sumf;}
  void updatesumf(bool dead);
  double getMaxFitness(){return maxf;}
  double getMinFitness(){return minf;}
  double countoffspring(double skim);
  void reproduce();
  int getExpected(){return expectedoffspring;}
  int getID(){return id;}
  void setExpected(int off){expectedoffspring = off;}
  void incExpected(int off){expectedoffspring += off;}
  int getAge(){return age;}
  void setLastImprovement(int ilast){lastimprov = ilast;}
  int getLastImprovement(){return lastimprov;}
  void removeDead();
};

inline bool speciescomp(Species * s1, Species * s2){return s1->getMaxFitness() > s2->getMaxFitness();}
typedef vector<Species * > speciesVector;

class Population {
private:
  Innovations * in;
  speciesVector * species;
  Phenotypes * members;
  NEATsettings * set;
//   TransferFunction * f;//have one for every pop...
//   TransferFunction * ifunc;//have one for every pop...
  TransferFunctions * tfs;
  double highestf;
  int highestlastchanged;
  int curgenome;
  int curspec;
  int curgen;
  int bestspecnum;//for debug reasons
  int debug;
  int size;
  int steal;
  int dropoffage;
  Phenotype * bestmember;
  int originalinitialelitism;
  Genome * originalseed;
  double ocomp;
  double compmod;
  void setvars(){spectarget = (int)set->getValue("species_target_size");
    dropoffage = (int)set->getValue("dropoff_age");
    steal = (int)set->getValue("steal");
    if(ocomp==-1)
      ocomp = set->getValue("compat_threshold");
    compmod = ocomp/10.0;

  }
public:
  Population(NEATsettings * iset, TransferFunctions * itfs)
  {ocomp=-1;set = iset; resetVars();
    setvars();
    tfs = itfs;
  }
  Population(NEATsettings * iset,double iocomp, TransferFunctions * itfs)
  {
    set = iset; resetVars();
    ocomp=iocomp;
    setvars();
    tfs = itfs;
  }
  ~Population();

  unsigned int spectarget;

  void resetVars(){
    in = new Innovations((int)set->getValue("number_of_innovations")); species = new speciesVector(); members = new Phenotypes();
    highestf=0;highestlastchanged=curgenome=curspec=curgen=bestspecnum=debug=size=0;
    bestmember=NULL;
    }
  void genesis(Genome * g, int isize, int initialelitism);
  TransferFunctions * getTfs(){return tfs;}
  void speciate();
  void deletespecies();
  void sortspecies();
  void sortmembers();
  void preepoch();
  void postepoch();
  void setDebug(int id){debug = id;}
  bool getDebug(){return debug;}
  Innovations * getInnovations(){return in;}
  int getAndIncID(){int tmp = curgenome; curgenome++; return tmp;}
  int getAndIncSpecID(){return ++curspec;}
  void randomSpawn(int pops,int i, int o, int n,int nmax, double linkprob, 
		  double r);
  Phenotypes * getMembers(){return members;}
  Phenotype * getBest(){return bestmember;}
  Phenotype * getCopyOfCurrentBest(){Phenotype * ret = new Phenotype(members->at(0)->getGenome()->duplicate(members->at(0)->getGenome()->getID())); ret->setFitness(members->at(0)->getOrigFitness()); return ret;}
  speciesVector * getSpecies(){return species;}
  double getHighestFitness(){return highestf;}
  Phenotype * getByID(int id);
  int getGeneration(){return curgen;}
  int getOriginalSize(){return size;}
  void updateSpeciesStats();
  void resetGenesis();
  void populationCleanup();
  Genome * getOriginalSeed(){return originalseed;}
  int getOriginalInitialElitism(){return originalinitialelitism;}
  double calcAvgFitness();
  double getOcomp(){return ocomp;}
  TransferFunction * sotfunc;
  TransferFunction * sitfunc;
  TransferFunction * gtfunc;
  TransferFunction * parfunc;
  TransferFunction * tafunc;
};
static inline Genome * mutate(Genome * g, NEATsettings * set, int & cnodeid){
  if(randdouble()<set->getValue("mutate_add_node_prob")){
    g->mutateaddnode(cnodeid);
  }else if(randdouble()<set->getValue("mutate_add_link_prob")){
    g->addLink((int)set->getValue("newlink_tries"));
  }else{//no structural mutation, only small mutations
    if(randdouble()<set->getValue("mutate_link_weights_prob")){
      bool coldg = (set->getValue("coldgaussian_weight_mutate") == 0) ? false : true;
      g->mutatew(coldg);
    }
    if(randdouble()<set->getValue("mutate_toggle_enable_prob")){
      g->mutatetoggle(1);
    }
    if(randdouble()<set->getValue("mutate_gene_reenable_prob")){
      g->mutatereenable();
    }
  }
  return g;
}
static inline speciesVector * addToSpeciesCollection(speciesVector * v, Phenotype * p, 
						     Population *pop, NEATsettings * set, bool debug)
{
  if(debug)
    cout << "!!! in addToSpeciesCollection p:" << p->getID() << endl;
  Genome * compmember = 0;
  double comp = set->getValue("compat_threshold");
  bool found = false;
  int si = 0;double bestcomp=comp;
  for(unsigned int i=0;i<v->size();i++){
    if(v->at(i)->getMembers()->size()!=0
       &&v->at(i)->firstMember()!=NULL){
//       if(v->at(i)->firstMember()->getGenome()!=NULL&&debug)
// 	cout << "firsmembers getgenome er ikke null"<<endl;
//       else if(debug)
// 	cout << "firsmembers getgenome er null"<<endl;

      compmember = v->at(i)->firstMember()->getGenome();
      if(debug&&compmember==0)
	cout << "compmember er 0 wtf??" << endl;
//       if(compmember->getGenes()!=NULL&&debug)
// 	cout << "firsmember(id:"<<compmember->getID()<<") getgenome->genes er ikke null"<<endl;
//       else if(debug)
// 	cout << "firsmember(id:"<<compmember->getID()<<") getgenome->genes er null"<<endl;
//      cout << "comparing to species " << v->at(i)->getID()<<endl;
      double tcomp = p->getGenome()->compare(compmember);
      if(tcomp<comp){
	found = true;
	if(tcomp<bestcomp){
	  bestcomp = tcomp;
	  si = i;
	}
	compmember = 0;
	break;
      }
    }
    if(debug&&v->at(i)->firstMember()!=NULL)
      cout << "firstmember er null....." << endl;
    if(debug&&v->at(i)->getMembers()->size())
      cout << "species membersize er 0....." << endl;
    // else if(debug)
//       cout << "i:"<<i <<"s size var null eller firsmember var null" << endl;
  }
  if(found){
    v->at(si)->addChild(p);
    //cout << "adding phenotype "<<p->getID()<<" to species" << v->at(si)->getID() << endl;
    return v;
  }
  if(debug&&compmember!=0)
    cout << "fant ingen species compmember ikke 0 og vsize: " << v->size() << " found: " << found << endl;
  if(debug&&compmember==0)
    cout << "fant ingen species compmember er 0 og vsize: " << v->size() << " found: " << found << endl;
  if(!found&&(compmember != 0||v->size()==0)){//test shouldnt bee here, the species shouldnt have 0 members!!

    Species * news = NULL;
    v->push_back(news = new Species(pop->getAndIncSpecID(),set,pop));
    news->addPhenotype(p);
    //    cout << "adding phenotype "<<p->getID()<<" to new species"<< news->getID() << endl;
    //    p->setSpecies(news);
  }
  
  return v;
}
static inline speciesVector * copyAndSort(speciesVector * v)
{
  for(unsigned int i=0;i<v->size();i++)
    v->at(i)->updatemaxminf();

  speciesVector * ret = new speciesVector(v->begin(),v->end());//deep copy?? we dont want deep copy

  sort(ret->begin(),ret->end(),speciescomp);
  return ret;
}
static inline void printFitness(Phenotypes * p)
{
  for(unsigned int i=0;i<p->size();i++)
    cout << "pid: " << p->at(i)->getID() << " f:" << p->at(i)->getFitness() << endl; 
}

#endif
