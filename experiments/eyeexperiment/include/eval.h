#ifndef EYEEVAL_H_
#define EYEEVAL_H_
#include "evaluator.h"
#include "lightsim.h"
#include "iface.h"
class LightsimEvaluator : public FitnessEvaluator {
private:
  NEATsettings * settings;
  double cellsize;
  unsigned int ls_distance;
  unsigned int xmax;
  unsigned int ymax;
  unsigned int lsnum;
  Lightsim2D *ls2d;
public:
  LightsimEvaluator(NEATsettings * set, unsigned int xmax, unsigned int ymax, unsigned int lsnum, double cellsize, unsigned int ls_distance){settings=set; this->xmax=xmax; this->ymax=ymax; this->lsnum=lsnum; this->cellsize=cellsize; this->ls_distance=ls_distance; };
  ~LightsimEvaluator(){delete settings;}
  virtual double f(Phenotype * f);
  unsigned int getXmax() { return xmax; }
  unsigned int getYmax() { return ymax; }
  double f(Lightsim2D * ls2d);
  virtual void nextGen(){return;} // no need for this here..
};
#endif
