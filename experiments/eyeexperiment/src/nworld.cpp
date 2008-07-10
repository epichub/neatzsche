#include "nworld.h"

nPoint::nPoint(nVector & v, double mult)
{
  init(); coords->push_back(v.vec->at(0)*mult); coords->push_back(v.vec->at(1)*mult);
}
nPoint::nPoint(nVector & v, nPoint & p)
{
  init();
  coords->push_back((p.coords)->at(0)+(v.vec)->at(0));
  coords->push_back((p.coords)->at(1)+(v.vec)->at(1));
}

bool nVector::twodHasPoint(int x, int y,double margin) {
  nVector *pointvec=new nVector(start->at(0),start->at(1),x,y);
  //    int dxPoint=x-start->at(0); int dyPoint=y-start->at(1);
  double tmpX=pointvec->vec->at(0)*(vec->at(1)/vec->at(0));  
  double tmpY=pointvec->vec->at(1)*(vec->at(0)/vec->at(1));
  double avgDelta=(tmpX+tmpY)/2;
  if(avgDelta>(pointvec->vec->at(1)-margin) && avgDelta<(pointvec->vec->at(1)+margin)) { 
    if(scalarValue(*this) >= scalarValue(*pointvec)) {
      return true; 
    }
    else { return false; }
  }
  else { return false; }
}

double nVector::scalarValue(nVector & linevector)
{
  double ret=0;
  for(unsigned int i=0;i<linevector.vec->size();i++)
    ret += pow(linevector.vec->at(i),2);
  return sqrt(ret);
}


nVector * nVector::orthogonal(nPoint & p, nVector & l)
{
  orthogonal(p.at(0),p.at(1),l);
}

nVector * nVector::orthogonal(int x3, int y3, nVector &l) {
  double x1 = l.start->at(0);
  double y1 = l.start->at(1);
  double x2 = l.start->at(0)+l.vec->at(0);
  double y2 = l.start->at(1)+l.vec->at(1);
  double len = scalarValue(l);
  double u = (((x3-x1)*(x2-x1))+((y3-y1)*(y2-y1)))/pow(len,2);
  double x = x1+(u*(x2-x1));
  double y = y1+(u*(y2-y1));
  return new nVector(x3,y3,x,y);
}


double nVector::orthogonalLength(int x3, int y3, nVector &l) {
  double x1 = l.start->at(0);
  double y1 = l.start->at(1);
  double x2 = l.start->at(0)+l.vec->at(0);
  double y2 = l.start->at(1)+l.vec->at(1);
  double len = scalarValue(l);
  double u = (((x3-x1)*(x2-x1))+((y3-y1)*(y2-y1)))/pow(len,2);
  double x = x1+(u*(x2-x1));
  double y = y1+(u*(y2-y1));
  if(l.vec->at(0)>0) { 
    if(x>x2||x<x1) {
      return -1;
    }
  }
  else {
    if(x<x2||x>x1) {
      return -1;
    }
  }
  return sqrt(pow(x-x3,2)+pow(y-y3,2));
  //  return new nVector(x3,y3,x,y);
}
