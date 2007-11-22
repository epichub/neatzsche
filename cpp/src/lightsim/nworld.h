#ifndef NWORLD_H_
#define NWORLD_H_
#include <vector>
#include <stdlib.h>
#include "math.h"
#include <iostream>
// typedef std::vector<double> nPoint;
//<startpoint, vector> => gives full def for a ndimentional vector
// typedef std::pair< nPoint*,std::vector<double>*> nVector;

namespace world
{
  static const int NORTH = 1;
  static const int NORTHdir[2] = {0,1};
  static const int NORTHdeg = 90;
  static const int NORTHEAST = 2;
  static const int NORTHEASTdir[2] = {1,1};
  static const int NORTHEASTdeg = 45;
  static const int EAST = 3;
  static const int EASTdir[2] = {1,0};
  static const int EASTdeg = 0;
  static const int SOUTHEAST = 4;
  static const int SOUTHEASTdir[2] = {1,-1};
  static const int SOUTHEASTdeg = 315;
  static const int SOUTH = 5;
  static const int SOUTHdir[2] = {0,-1};
  static const int SOUTHdeg = 270;
  static const int SOUTHWEST = 6;
  static const int SOUTHWESTdir[2] = {-1,-1};
  static const int SOUTHWESTdeg = 225;
  static const int WEST = 7;
  static const int WESTdir[2] = {-1,0};
  static const int WESTdeg = 180;
  static const int NORTHWEST = 8;
  static const int NORTHWESTdir[2] = {-1,1};
  static const int NORTHWESTdeg = 135;
}
class nVector;
class nPoint
{
public:
  std::vector<double> * coords;
  nPoint(){init();}
  nPoint(double x, double y){init(); coords->push_back(x); coords->push_back(y);}
  nPoint(nVector & v, nPoint & p);
  nPoint(nVector & v, double mult);
  ~nPoint() { delete coords; }
  void init(){coords = new std::vector<double>();}
  void push_back(double a) {coords->push_back(a);}
  size_t size(){return coords->size();}
  double at(size_t i){return coords->at(i);}
  nPoint * twodTransPose(){ return new nPoint(coords->at(1),coords->at(0)); }
  double twodDistanceTo(nPoint & p)
  {
    return sqrt(
		pow(p.at(0)-coords->at(0),2) + 
		pow(p.at(1)-coords->at(1),2)
		);
  }
  bool operator==(const nPoint & p) const {return (coords->at(0) == p.coords->at(0) && coords->at(0) == p.coords->at(0));}
};

class nVector
{
public:
  nPoint * start;
  std::vector<double> * vec;
  nVector(){ init(); }
  nVector(double s1, double s2, double e1, double e2)
  {
    init();
    makeVector(s1,s2,e1,e2);
  }
  nVector(nPoint & p1, nPoint & p2)
  {
    init();
    makeVector(p1.coords->at(0),p1.coords->at(1),p2.coords->at(0),p2.coords->at(1));
  }
  nVector(nVector & v1, double degree, bool round = false)
  {
    init();
    start->push_back(v1.start->at(0)); start->push_back(v1.start->at(1));
    vec->push_back((v1.vec->at(0)*cos(degree))-(v1.vec->at(1)*sin(degree)));
    vec->push_back((v1.vec->at(0)*sin(degree))+(v1.vec->at(1)*cos(degree)));
    if(round){
      vec->at(0) = static_cast<int>(vec->at(0) + 0.5);
    vec->at(1) = static_cast<int>(vec->at(1) + 0.5);
    }
//  vec->push_back(v1->vec->at(1));
//     makeVector(v1.vec->at(0),p1.coords->at(1),p2.coords->at(0),p2.coords->at(1));
  }
  nVector * copy(){nVector * ret = new nVector(); ret->start->push_back(start->at(0)); 
    ret->start->push_back(start->at(1));
    ret->vec->push_back(vec->at(0)); ret->vec->push_back(vec->at(1)); return ret;}
  ~nVector(){delete start; delete vec;}
  void makeVector(double s1, double s2, double e1, double e2)
  {
    start->push_back(s1); start->push_back(s2); 
    vec->push_back(e1-s1); vec->push_back(e2-s2);
  }
  double size(){return sqrt(pow(vec->at(0),2)+pow(vec->at(1),2));}
  void init(){ start = new nPoint(); vec = new std::vector<double>(); }
  nVector * twodTransPose(){ return new nVector(start->at(1),start->at(0),vec->at(1),vec->at(0)); }
  bool twodHasPoint(int x, int y,double margin);
  double scalarValue(nVector & linevector);
  nVector * orthogonal(nPoint & p, nVector & l);
  nVector * orthogonal(nPoint & p) {
    return orthogonal(p,*(this->copy()));
  }
  double scalarValue() { return scalarValue(*this); }
  nPoint* endPoint() 
  {
    nPoint* tmp=new nPoint();
    for(unsigned int i=0;i<vec->size();i++) {
      tmp->coords->push_back(start->coords->at(i)+vec->at(i));
    }
    return tmp;
  }
};

typedef std::vector< nPoint * > nPoints;
typedef std::vector< nVector * > nVectors;

// nVector * orthogonal(nPoint & point, nVector & linevector);
// inline double scalarValue(nVector & linevector);


// inline bool withinEvenVectors(std::vector<nVector*> & vectors, nPoint & point)
// {
//   int neg = 0, pos = 0;
//   nVector * thisV = NULL;
//   for(unsigned int i=0;i<vectors.size();i++){
//     thisV = orthogonal(point,*vectors.at(i));
// //     std::cerr << "sjekker vec: fra ("<< vectors.at(i)->start->at(0)<<","<< vectors.at(i)->start->at(1)
// // 	      <<")=> ["<< vectors.at(i)->vec->at(0)<<","<< vectors.at(i)->vec->at(1)
// // 	      << "] orth: [" << thisV->vec->at(0) << "," << thisV->vec->at(1) << "]" << std::endl;
//     if(thisV->vec->at(0) < 0 || thisV->vec->at(1) < 0)
//       neg++;
//     else if(thisV->vec->at(0) > 0 || thisV->vec->at(1) > 0)
//       pos++;
//     delete thisV;
//   }
// //   std::cerr << "neg: " << neg << " pos: " << pos << std::endl;
//   if(neg==pos)
//     return true;
//   return false;
// }
inline std::vector<nVector*> * makeRectangle(double x1, double y1, double x2, double y2)
{
  nVector * a = new nVector(x1,y1,x1,y2);
//   std::cerr << "lager vektor fra (" << x1 << "," << y1 
// 	    << ") til (" << x1 << "," << y2 << ")" << std::endl; 
  nVector * b = new nVector(x1,y2,x2,y2);
//   std::cerr << "lager vektor fra (" << x1 << "," << y2 
// 	    << ") til (" << x2 << "," << y2 << ")" << std::endl; 
  nVector * c = new nVector(x2,y2,x2,y1);
//   std::cerr << "lager vektor fra (" << x2 << "," << y2
// 	    << ") til (" << x2 << "," << y1 << ")" << std::endl; 
  nVector * d = new nVector(x2,y1,x1,y1);
//   std::cerr << "lager vektor fra (" << x2 << "," << y1
// 	    << ") til (" << x1 << "," << y1 << ")" <<  std::endl; 
  std::vector<nVector*> * ret = new std::vector<nVector*>();
  ret->push_back(a);  ret->push_back(b); ret->push_back(c); ret->push_back(d);
  return ret;
}

class WorldObject
{
public:
  WorldObject(double x, double y){point = new nPoint(x,y);}
  WorldObject(){}
  virtual ~WorldObject(){}
  nPoint * point;
  char wot;
//   void randPos(BBWorld * bbw){
//     int x=0,y=0;
//     do{
//       x = 10+(int)(230*(double)(rand()/RAND_MAX)); y = 10+(int)(230*(double)(rand()/RAND_MAX));
//     }while(bbw->taken(x,y));
//     point->at(0) = x; point->at(1) = y;
//   } 
};

#endif

