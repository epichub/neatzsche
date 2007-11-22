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
  nPoint point = p;
  nVector linevector = l;
  bool trans = false;
  if(fabs(linevector.vec->at(0))> fabs(linevector.vec->at(1))){
    nPoint * p2 = p.twodTransPose();
    point = *p2;
    nVector * l2 = l.twodTransPose();
    linevector = *l2;
    trans = true;
  }

  if(point.size()!=linevector.vec->size()){
    return NULL;
  }

  nVector * ret = new nVector();
  ret->vec->insert(ret->vec->end(),linevector.vec->size(),0);
  double abValue = scalarValue(linevector);

  double b[2];
  b[0] = 0; b[1] = abValue;

  double c[2];
  c[0] = (point.at(0)-linevector.vec->at(0));
  c[1] = b[1] + (point.at(1)-linevector.vec->at(1));

  double j = (point.at(1)/b[1]);

  if(j>1.0){ //not orthogonal
    return NULL;
  }
  double d[2];
  d[0] = 0; d[1] = c[1];
  ret->start = new nPoint();
  ret->start->push_back(d[0]);
  ret->start->push_back(d[1]);
  ret->vec = new std::vector<double>();
  ret->vec->push_back(c[0]);
  ret->vec->push_back(c[1]-d[1]);
  if(trans){
    nVector * heh = ret;
    ret = heh->twodTransPose();
    delete heh;
  }
  return ret;
}

