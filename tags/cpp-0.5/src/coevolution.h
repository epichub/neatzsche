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
#ifndef COEVOLUTION_H_
#define COEVOLUTION_H_

#include "evoops.h"
#include "evolution.h"
#include "evaluator.h"

class Coevolution {
protected:
  int games;
  FitnessEvaluator * fe;
  TransferFunctions * tfs;
  virtual void print(ostream& o) const {};
  virtual void read(istream& i ) const {};
public:
  Coevolution(int igames){games=igames;}
  virtual ~Coevolution(){};
  virtual void update(Population * p){};
  virtual void evaluate(Phenotypes * p){};
  friend ostream& operator<< (ostream& os, const Coevolution * c){c->print(os); return os;};
  friend istream& operator>> (istream& is, Coevolution  * c){c->read(is); return is;};
  virtual int size(){return 0;};
  virtual int getStartGeneration(){return 0;}
  virtual void setTfs(TransferFunctions * itfs){tfs=itfs;}
  virtual void setFitnessEvaluator(FitnessEvaluator * ife){fe=ife;}

};

// inline std::ostream& operator<< (std::ostream& o, const Coevolution * c)
// {
//   c->print(o);
//   return o;
// };
// inline std::ostream& operator>> (std::istream& i, Coevolution * c)
// {
//   c->read(i);
//   return i;
// };

class Halloffame : public Coevolution {
private:
  Phenotypes * halloffame;
  Phenotypes * perm;
  int n;
  int permm;
  int sg;
  bool first;
  virtual void print(std::ostream& o) const ;
  virtual void read(std::istream& i) const ;
public:
  Halloffame(int num, int igames, int isg, FitnessEvaluator * ife) : Coevolution(igames) {halloffame = new Phenotypes(); n = num;first=true; perm = new Phenotypes(); sg = isg; fe = ife;}
  ~Halloffame(){delete halloffame;}
  virtual void update(Population * p);
  virtual void evaluate(Phenotypes * p);
  virtual int size(){return halloffame->size();};
  void addPermantent(Phenotype * permphenotype){perm->push_back(permphenotype);}
  virtual int getStartGeneration(){return sg;}
  string pp();
};

class Pareto : public Coevolution {
private:
  Phenotypes * halloffame;
  int n;
  virtual void print(std::ostream& o) const {};
  virtual void read(std::ostream& i) const {};
public:
  Pareto(int num, int igames) : Coevolution(igames) {halloffame = new Phenotypes(); n = num;}
  ~Pareto(){delete halloffame;}
  virtual void update(Population * p){};
  virtual void evaluate(Phenotypes * p){};
  virtual int size(){return halloffame->size();};
  virtual int getStartGeneration(){return 0;}
};

#endif
