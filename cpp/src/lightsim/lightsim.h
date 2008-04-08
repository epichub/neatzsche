#ifndef LIGHTSIM2D_H_
#define LIGHTSIM2D_H_

#include <iostream>
#include <vector>
#include "cell.h"
#include "opaquecell.h"
#include "lightsource.h"
#include "lightvector.h"
#include "lsc.h"
#include "nworld.h"
#include "evolution.h"

class Lightsim2D {

private:
  std::vector<Lightsource*> *lightsources;
  std::vector<Opaquecell*> *opaquecells;
  std::vector<LSC*> *LSCs;
  unsigned int sizeX;
  unsigned int sizeY;
  std::vector<Lightvector*> *lightvectors;
  std::vector<Lightvector*> *deletedLightvectors;
  double cellsize;
public:
  friend std::istream& operator>>(std::istream& i, Lightsim2D * ls);
  friend std::ostream& operator<<(ostream& os, const Lightsim2D *ls);
  Lightsim2D(double cellsize);
  Lightsim2D(double cellsize, unsigned int ** twodmap,unsigned int xmax,unsigned int ymax);
  Lightsim2D(double cellsize, Phenotype * f, unsigned int xmax, unsigned int ymax, unsigned int lsnum);
  ~Lightsim2D();
  void init(double cellsize);
  unsigned int getSizeX() { return sizeX; }
  unsigned int getSizeY() { return sizeY; }
  std::vector<Lightsource*>* getLightsources() { return lightsources; }
  std::vector<Opaquecell*>* getOpaquecells() { return opaquecells; }
  std::vector<LSC*>* getLSCs() { return LSCs; }
  std::vector<Lightvector*>* getLightvectors() { return lightvectors; }
  std::vector<Lightvector*>* getDeletedLightvectors() { return deletedLightvectors; }
  void print();
  void createVectors();
  void pruneBlockedVectors();
};

#endif
