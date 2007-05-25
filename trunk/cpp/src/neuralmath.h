/*
  Copyright 2007 Bjørn Magnus Mathisen
  This file is part of NEATzsche.

  NEATzsche is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  NEATzsche is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NEATzsche; if not, write to the Free Software Foundation,
  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 */

#ifndef _NEURALMATH_H_
#define _NEURALMATH_H_

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include "settings.h"
#include <string>

#define PI 3.14159
using namespace std;
class TransferFunction;

inline unsigned int randint(unsigned int floor, unsigned int roof)
{
  if(floor==roof)
    return roof;
  int r = rand();
  int diff = roof - floor;
  int tmp = r%diff;
  return (unsigned int)(tmp+floor)+1;
}

class TransferFunction
{
public:
  TransferFunction();
  virtual ~TransferFunction();
  virtual double y(double x){return x;};
  string ftype;
};
class SignumTransfer : public TransferFunction
{
public:
  SignumTransfer();
  virtual ~SignumTransfer();
  virtual double y(double x){return sgn(x);}
  int sgn(double);
};
class SigmoidTransfer : public TransferFunction
{
private:
  double k;
  double con;
public:
  SigmoidTransfer(bool unipolar, double ik);
  virtual ~SigmoidTransfer();
  virtual double y(double x){return sgm(x);}
  double sgm(double inp);
};
class SinusTransfer : public TransferFunction
{
private:
  double sharpness;
  double add;
  double div;
public:
  SinusTransfer(bool unipolar, double isharpness, double iadd, double idiv)
  {sharpness=isharpness; add=iadd; div=idiv;ftype="sin";}
  virtual ~SinusTransfer(){};
  virtual double y(double x){return (sin(sharpness*x)/div)+add;}
};
class ParabelTransfer : public TransferFunction
{
private:
  double sharpness;
  double add;
  double div;
public:
  ParabelTransfer(bool unipolar, double isharpness, double iadd)
  {sharpness=isharpness; add=iadd;ftype="par";};
  virtual ~ParabelTransfer(){};
  virtual double y(double x){return -(pow((sharpness*x),2))+add;}
};
class GaussTransfer : public TransferFunction
{
private:
  double m;
  double d;
public:
  GaussTransfer(bool unipolar, double im, double id)
  {m=im; d=id;ftype="gau";}
  virtual ~GaussTransfer(){};
  virtual double y(double x)
  {return (1/(d*sqrt(2*PI)))*exp(-((pow(x-m,2))/(2*pow(d,2))));}
};

class TransferFunctions
{
private:
  vector<TransferFunction *> * f;
  TransferFunction * ta;
  TransferFunction * sigmoid;
public:
  TransferFunctions(NEATsettings * s);
  ~TransferFunctions();
  TransferFunction * getTA(){return ta;}
  TransferFunction * getSigmoid(){return sigmoid;}
  string prettyprint(){stringstream ss; ss << "tfs size: " << f->size() << endl; return ss.str();}
  TransferFunction * getRandom(){
    if(f->size()==1)
      return sigmoid;
    int ret = randint(0,f->size()-1);
    return f->at(ret);
  }
  TransferFunction * getFunction(string ftype)
  {
//     cerr << "i getfunction ftype er:" << ftype << endl;
    if(ftype=="ta")
      return ta;
    if(ftype=="so")
      return sigmoid;
    for(unsigned int i=0;i<f->size();i++){
      if(f->at(i)->ftype==ftype){
	return f->at(i);
      }

    }
    cerr << "returning null!?" << endl;
    return NULL;
  }
};

class Dummy{
private:
  bool isIn(int ** arr,int length, int x, int y);
public:
  int ** randomCoords(int maxX,int maxY);
  void printBitmap(int ** arr, int x, int y, bool printneg=false);
  void deleteArray(int x,int ** arr);
};

inline double randdouble()
{
  return (double)rand()/(double)RAND_MAX;
}

inline int randsign()
{
  if(0.5<=randdouble())
    return -1;
  return 1;
}

inline double box_muller(double m, double s)
{				        
  double x1, x2, w, y1;
  static double y2;
  static int use_last = 0;
  static double lm,ls;
  
  if (use_last && lm == m && ls == s)
    {
      y1 = y2;
      use_last = 0;
    }
  else
    {
      lm = m; ls = s;
      do {
	x1 = 2.0 * randdouble() - 1.0;
	x2 = 2.0 * randdouble() - 1.0;
	w = x1 * x1 + x2 * x2;
      } while ( w >= 1.0 );

      w = sqrt( (-2.0 * log( w ) ) / w );
      y1 = x1 * w;
      y2 = x2 * w;
      use_last = 1;
    }

  return( m + y1 * s );
}

inline string printvector(vector< double > v)
{
  stringstream ss;
  ss << "< ";
  ss << v.at(0);
  for(unsigned int i=1;i<v.size();i++){
    ss << ", " << v.at(i);
  }
  ss << " >"<<endl;
  return ss.str();
}
inline double sumvector(vector< double > v)
{
  double ret=0;
  for(unsigned int i=1;i<v.size();i++){
    ret += v.at(i);
  }
  return ret;
}
inline bool checkvector(vector< double > v, vector< double > v2, bool printind)
{
  if(v.size()!=v2.size()){
    if(printind)
      cerr << "not equal length"<<endl;
    return false;
  }
  for(unsigned int i=1;i<v.size();i++){
    if(v.at(i)!=v2.at(i)){
      if(printind)
	cerr << "(first)index at fault+1: " << i+1 << endl;
      return false;
    }
  }
  return true;
}
inline string printvector(vector< double > v, int rl)
{
  // cout << "v.size: " << v.size();
  stringstream ss;
  ss << "<";
  ss << v.at(0);
  int i2=1;
  for(int i=0;i<rl;i++){
    for(;i2<rl;i2++)
      ss << ", " << v.at((i*rl)+i2);
    ss << endl;
    i2 = 0;
  }
  ss << " >"<<endl;
  return ss.str();
}
inline string printvector(vector< int > v, int rl)
{
  stringstream ss;
  ss << "< ";
  ss << v.at(0);
  int i2=1;
  for(int i=0;i<rl;i++){
    for(;i2<rl;i2++){
      ss << ", " << v.at((i*rl)+i2); 
    }
    ss << endl;
    i2 = 0;
  }
  ss << " >"<<endl;
  return ss.str();
}
static inline bool myequal(double x, double y){
  static double epsilon = 0.00001;
  return (fabs(x - y) < epsilon * x);
}
#endif //_NEURALMATH_H_
