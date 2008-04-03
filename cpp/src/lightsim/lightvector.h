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
  Lightvector(Lightsource* ls, LSC* lsc) { this->ls=ls; this->lsc=lsc; nvec=new nVector(lsc->getX(),lsc->getY(),ls->getX(),ls->getY()); }
  ~Lightvector() {
    delete nvec;
  }
  Lightsource* getLightsource() { return ls; }
  LSC* getLSC() { return lsc; }
  nVector* getnVector() { return nvec; }
};

#endif
