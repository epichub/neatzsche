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
#ifndef _NEURALNET_H_
#define _NEURALNET_H_
#include "neuralmath.h"
#include <iostream>
#include <vector>
using namespace std;
class Link;
class NeuralNode;

typedef vector< Link * > linkVector;
typedef vector< NeuralNode * > nodeVector;

class Network
{
private:
  vector< nodeVector * > * net;
  nodeVector * output;
  int inp;
  int out;
public:
  Network(int inp, int out);
  ~Network();
  vector< double > runnet(vector< double > inp);
  void addNodes(nodeVector * nodes, bool debug);
  vector< nodeVector * > * getNet(){return net;}
  void cleanup();
  NeuralNode * getOutput(){return net->at(net->size()-1)->at(0);}
};

class NeuralNode
{
private:
  int id;
  linkVector * links;
  TransferFunction * tFunc;
  double valueFromOther;
  double input;
  double cache;
  bool bias;
  char type;
  string ftype;
  int depth;
  TransferFunctions * tfs;
  //bool localrecur=false;
public:
  NeuralNode(NeuralNode * n){id = n->id;links=n->links;
    tFunc=n->tFunc;valueFromOther=n->valueFromOther;input=n->input;
    cache=n->cache;bias=n->bias;type=n->type;depth=n->depth;ftype=n->ftype;}
  NeuralNode(TransferFunctions * itfs){links = new linkVector();input = 0; valueFromOther = 0;tfs=itfs;};
  NeuralNode(TransferFunction * func, int iid, char t, string ftype, int d);
  virtual ~NeuralNode();
  NeuralNode * duplicate(){NeuralNode * ret = new NeuralNode(this); ret->links= new linkVector();return ret;}
  void setInput(double inp){input = inp;}
  void addLink(Link * link);
  void update();
  void setTransferFunctions(TransferFunctions * itfs){tfs = itfs;}
  void cleanup(){cache = 0; valueFromOther=0;}
  TransferFunction * getTFunc(){return tFunc;}
  void deletelinks();
  void setDepth(int d){depth=d;}
  void incDepth(){depth++;}
  int getDepth(){return depth;}
  void printInfo(){
    cout << "input: " << input
	 <<" valuefromother: " << valueFromOther
	 <<" links: "<<links->size()<<" cache: "<<cache<<" value: "<<tFunc->y(valueFromOther+input)<<endl;}
  void reset(){input=0;valueFromOther=0;}
  inline double getValue(){if(tFunc==NULL) cerr << "tfunc null i getvalue" << endl; cache = tFunc->y(valueFromOther+input);return cache;}
  void setOutput(double v){cache = v;}
  double getCachedValue(){return cache;}
  Link * getLinkTo(NeuralNode * node);
  linkVector * getInputLinks();
  linkVector * getLinks(){return links;}
  int getID(){return id;}
  void setBias(){bias=true;}
  bool isBias(){return bias;}
  void initTFunc();
  //void setlocalrecur(){harlocalrecur = true;}
  //bool localrecur(){return localrecur;}
  friend ostream& operator<< (ostream& os, const NeuralNode *n);
  friend istream& operator>> (istream& is, NeuralNode *n);

  //to categorize the nodes..i need it to read in from files and
  //because there can be several layers of hidden nodes
  static const char INPUT = 'i';
  static const char BIAS = 'b';
  static const char HIDDEN = 'h';
  static const char OUTPUT = 'o';

  char getType(){return type;}
  string getFType(){return ftype;}
};
inline bool nodedepthcomp(NeuralNode * n1, NeuralNode * n2){
  if(n1->getDepth() == n2->getDepth() ) return n2->getType()==NeuralNode::BIAS;
  else return n1->getDepth() < n2->getDepth();}
inline bool nodeidcomp(NeuralNode * n1, NeuralNode * n2){return n1->getID() < n2->getID();}

class Link
{
private:
  NeuralNode * from;
  NeuralNode * to;
  double weight;
  bool uniDir;
  bool deletable;
public:
  Link(bool unDir, NeuralNode * first, NeuralNode * second, double w);
  virtual ~Link();
  double getOther(NeuralNode * calling);
  NeuralNode * getOtherNode(NeuralNode * calling);
  double getWeight(){return weight;}
  void setWeight(double newW){weight = newW;}
  void changeWeight(double newW){weight += newW;}
  bool isIn(NeuralNode * testNode);
  bool isTo(NeuralNode * calling);
  bool isFrom(NeuralNode * calling);
  NeuralNode * getFrom(){return from;}
  NeuralNode * getTo(){return to;}
  void setDeletable(){deletable = true;}
  bool getDeletable(){return deletable;}
};

#endif //_NEURALNET_H_
