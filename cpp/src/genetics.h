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
#ifndef GENETICS_H_
#define GENETICS_H_
#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h> //seems its required in gcc >4.3

using namespace std;

typedef char innovationType;

const static innovationType NEWNODE = 'n';
const static innovationType NEWLINK = 'l';

class Innovation {
private:
  innovationType type;
  int from_id;
  int to_id;
  int innonum;
  int innonum2;
  double neww;
  int nodeid;
  int oldinnonum;
public:
  //Constructor for the new node case
  Innovation(int nfrom_id,int ito_id,int iinnonum,
	     int iinnonum2,int newnodeid, int oldinnov) {
    from_id = nfrom_id; to_id = ito_id; innonum = iinnonum;
    innonum2 = iinnonum2; nodeid = newnodeid; oldinnonum = oldinnov;
    neww = 0.0; type = NEWNODE;
  }
  //Constructor for new link case
  Innovation(int nfrom_id, int ito_id, int iinnonum, double w) {
    from_id = nfrom_id; to_id = ito_id; innonum = iinnonum;
    neww = w; type = NEWLINK;
  }
  Innovation(){};
  int getNum(){return innonum;}
  int getNum2(){return innonum2;}
  int getOldNum(){return oldinnonum;}
  innovationType getType(){return type;}
  int getFrom(){return from_id;}
  int getTo(){return to_id;}
  int getNewNodeID(){return nodeid;}
  double getWeight(){return neww;}
  friend ostream& operator<< (ostream& os, const Innovation *i);
  friend istream& operator>> (istream& is, Innovation *i);
};

typedef vector< Innovation * > innovationVector;
typedef queue< Innovation * > innovationQueue;

class Innovations
{
private:
  innovationVector * q;
  int curspeciesnum;
  int numtokeep;
public:
  int curinnovnum;
  int curnodenum;
  Innovations(int inumtokeep){numtokeep=inumtokeep; q = new innovationVector();curspeciesnum = 0; curinnovnum = 0;curnodenum=0;};
  ~Innovations();
  Innovation * getInnovation(int innovationnumber);
  void addInnovation(Innovation * in){q->push_back(in);}
  //  innovationVector::iterator removeInnovation(innovationVector::iterator it){return v->erase(it);}
  innovationVector::iterator begin(){return q->begin();}
  innovationVector::iterator end(){return q->end();}
  void setInitNum(int n){if(curinnovnum<n)curinnovnum=n;}
  void setNodeNum(int n){if(curnodenum<n)curnodenum=n;}
  void setSpeciesNum(int n){if(curspeciesnum<n)curspeciesnum=n;}
  int size(){return q->size();}
  //friend ostream& operator<< (ostream& os, const Innovations *i);
  friend istream& operator>> (istream& is, Innovations *i);
  void prune();
};
#endif
