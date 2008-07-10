#ifndef LIGHTSIM2D_H_
#define LIGHTSIM2D_H_

#include <iostream>
#include <fstream>
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
  unsigned int xmax;
  unsigned int ymax;
  std::vector<Lightvector*> *lightvectors;
  std::vector<Lightvector*> *deletedLightvectors;
  double cellsize;
  unsigned int ls_distance;
public:
  friend std::istream& operator>>(std::istream& i, Lightsim2D &ls);
  friend std::ostream& operator<<(ostream& os, Lightsim2D *ls);
  Lightsim2D();
  Lightsim2D(double cellsize);
  Lightsim2D(double cellsize, unsigned int ** twodmap,unsigned int xmax,unsigned int ymax);
  Lightsim2D(double cellsize, Phenotype * f, unsigned int xmax, unsigned int ymax, unsigned int lsnum, unsigned int ls_dist);
  ~Lightsim2D();
  void clear();
  void reset();
  void init(double cellsize);
  void init(double cellsize,unsigned int xmax,unsigned int ymax);
  void init(double cellsize, Phenotype *f, unsigned int xmax, unsigned int ymax, unsigned int lsnum, unsigned int ls_dist);
  void setLsdist(unsigned int ls_dist) { ls_distance=ls_dist;}
  unsigned int getLsdist() { return ls_distance; }
  void setXmax(unsigned int xmax) { this->xmax=xmax; }
  unsigned int getXmax() { return xmax; }
  void setYmax(unsigned int ymax) { this->ymax=ymax; }
  unsigned int getYmax() { return ymax; }
  std::vector<Lightsource*>* getLightsources() { return lightsources; }
  std::vector<Opaquecell*>* getOpaquecells() { return opaquecells; }
  std::vector<LSC*>* getLSCs() { return LSCs; }
  std::vector<Lightvector*>* getLightvectors() { return lightvectors; }
  std::vector<Lightvector*>* getDeletedLightvectors() { return deletedLightvectors; }
  void print();
  void readFromFile(string filename);
  void createVectors();
  void pruneBlockedVectors();
};

#endif
