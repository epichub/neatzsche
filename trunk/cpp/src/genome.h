#ifndef _GENOME_H_
#define _GENOME_H_
#include "gene.h"
#include "ann.h"
#include "neuralmath.h"
#include "settings.h"
#include "genetics.h"
#include <sstream>
#include <iostream>
#define GCC_VERSION (__GNUC__ * 10000 \
                               + __GNUC_MINOR__ * 100 \
                               + __GNUC_PATCHLEVEL__)
#if GCC_VERSION >= 40300
#include <algorithm>
#endif

typedef vector< Gene * > Genes;

class ANN_genome {
private:
public:
  nodeVector getNodes();
  linkVector getLinks();
  ANN_genome mutate(double p);
  ANN_genome crossover(ANN_genome g);
};

class Genome : ANN_genome {
private:
  Genes * genes;
  nodeVector * nodes; // to keep track of all the nodes.
  int input;
  int output;
  int id;
  NEATsettings * set;
  Innovations * innov;
  bool debug;
  TransferFunctions * tfs;
public:
  Genome(TransferFunctions * itfs);
  Genome(int iid);
  Genome(const Genome&);
  Genome(int genomeid, Genes * igenes, nodeVector * inodes, int inp, int out,
	 NEATsettings * settings, Innovations * is, TransferFunctions * itfs);
  Genome(int new_id,int i, int o, int n,int nmax, bool r, double linkprob, NEATsettings * settings, Innovations * is, TransferFunctions * itfs);
  ~Genome();
  int getID(){return id;}
  nodeVector * getNodes(){return nodes; };
  nodeVector getConstantNodes();
  //  linkVector * getLinks(){};
  Genome * duplicate(int id);
  void mutatew(bool coldg);
  void mutatetoggle(int genes);//genes to toggle
  void mutatereenable();
  void mutateaddlink(int tries);
  void mutateaddnode(int &cnodeid);
  Genome * crossover(Genome * g, bool avg, double f1, double f2, int genomeid, bool sp);
  int getLastInnov(){if(genes->size()==0) return 0; 
    sort(genes->begin(),genes->end(),genemarkercomp);
    return genes->at(genes->size()-1)->getMarker();}
  int getLastNodeID(){if(nodes->size()==0) return 0; 
    sort(nodes->begin(),nodes->end(),nodeidcomp);
    return nodes->at(nodes->size()-1)->getID();}
  void setdebug(){debug=true;}
  void setSettings(NEATsettings * iset){set=iset;}
  void setInnovations(Innovations * iinnov){innov=iinnov;}
  void setTfs(TransferFunctions * itfs)
  {
    tfs=itfs;
    for(unsigned int i=0;i<nodes->size();i++){
      nodes->at(i)->setTransferFunctions(tfs);
      nodes->at(i)->initTFunc();
    }
  }
  void addNode(int &cnodeid);
  void augmentNodes(NeuralNode * n, bool rearrange);
  void addLink(int tries);
  void randomize(int i, int o, int n,int nmax, double r, double linkprob);
  string print();
  bool equal(Genome * g);
  NeuralNode * getNode(int id);
  NeuralNode * getNode(nodeVector * n, int id);
  Network * genesis();
  double compare(Genome * g);
  bool geneSanity(Genes * g, Gene * g);
  bool findAdd(NeuralNode * fnode, NeuralNode * tnode, nodeVector *newnodes, Gene * gene);
  int getInput(){return input;}
  int getOutput(){return output;}
  NEATsettings * getSettings(){return set;}
  Innovations * getInnovations(){return innov;}
  TransferFunction * getTransferFunction(){return nodes->at(0)->getTFunc();}
  Genes * getGenes(){return genes;}
  int countHidden();
  int extrons();
  friend ostream& operator<< (ostream& os, const Genome *thegenome);
  friend istream& operator>> (istream& is, Genome *thegenome);
};
static inline bool isIn(Gene * g, Genome * go)
{
  Genes * ge = go->getGenes();
  for(unsigned int i=0;i<ge->size();i++)
    if(&ge->at(i)==&g)
      return true;
  return false;
}
static inline bool checkforoutput(nodeVector * nodes)
{
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::OUTPUT)
      return true;
  return false;
}
#endif // _GENOME_H_
