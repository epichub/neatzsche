#ifndef LIGHTVECTOR_H_
#define LIGHTVECTOR_H_

#include "lightsource.h"
#include "lsc.h"
#include "nworld.h"

class Lightvector {

private:
  Lightsource *ls;
  LSC *lsc;
  nVector *nvec;
public:
  Lightvector(LSC* lsc, Lightsource* ls) { this->ls=ls; this->lsc=lsc; nvec=new nVector(lsc->getX(),lsc->getY(),ls->getX(),ls->getY()); }
  Lightvector(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) { nvec=new nVector(x1,y1,x2,y2); }
  ~Lightvector() {
    delete nvec;
  }
  Lightsource* getLightsource() { return ls; }
  LSC* getLSC() { return lsc; }
  nVector* getnVector() { return nvec; }
};

#endif
