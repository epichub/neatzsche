#ifndef EVOOPS_H_
#define EVOOPS_H_
#include "evolution.h"
#include "neuralmath.h"
#include <stdlib.h>

/*
  this file will contain small, and highly polymorphic
  evolutionary operators(not to be confused with genetic operators)
  
  these should probably ble used within species to retain the 
  NEAT specific algorithmic tricks that should be applied
  in a NEAT implementation

 */

using namespace std;

class Selector
{
protected:
  unsigned int speciesforelitism;
public:
  Selector(int ispeciesforelitism){speciesforelitism = (unsigned int)ispeciesforelitism; };
  virtual ~Selector(){};
  virtual Population * select(Population * p,  int elitism){p->preepoch(); return NULL; }
  virtual double eval(Phenotype * p,int i){return 0.0;}
  virtual int suswheel(int n, Species * s, int elitism, bool debug);
  unsigned int getySpeciesForElitism(){return speciesforelitism;};
};

class FitnessProp : public Selector
{
public:
  FitnessProp(int ispeciesforelitism) : Selector(ispeciesforelitism) {};
  ~FitnessProp(){}
  virtual Population * select(Population * p,  int elitism);
  virtual double eval(Phenotype * p, int i){return p->getFitness();}
};

class SigmaScaling : public Selector
{
private:
  double s,m;
public:
  SigmaScaling(int ispeciesforelitism) : Selector(ispeciesforelitism){s=m=0;};
  ~SigmaScaling(){}
  virtual Population * select(Population * p,  int elitism);
  virtual double eval(Phenotype * p, int i);
  void calcstddev(Species * s);
};

class RankSelection : public Selector
{
private:
    //double ssize;
  double s,n;
public:
  RankSelection(double is, int ispeciesforelitism) : Selector(ispeciesforelitism){s=is;};
  ~RankSelection(){}
  virtual Population * select(Population * p,  int elitism);
  virtual double eval(Phenotype * p, int i);
};

class Reproducer 
{
public:
  Reproducer(){};
  virtual ~Reproducer();
  virtual Population * reproduce(Population * s){return s;};
};
class LocalReproducer 
{
public:
  LocalReproducer(){};
  virtual ~LocalReproducer(){};
  virtual Population * reproduce(Population * s);
};


#endif
