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
#include "ann.h"
#include <iostream>
using namespace std;
Network::Network(vector< vector<double> > *v)
{
//   nodeVector * layer;
//   for(int i=0;i<q;v->size()){
//     layer = new nodeVector();
//     for(int i2=0;i2<q;i2++){
//     }

//   }
}
static bool samedepthcheck(Link * link, NeuralNode * n, bool deletable){
  if(
     (
      (link->isFrom(n)&&link->getTo()->getDepth()==n->getDepth())||
      (link->isTo(n)&&link->getFrom()->getDepth()==n->getDepth())
      )
     &&((link->getDeletable()==deletable)||link->getFrom()==link->getTo())
     )
    return true;
  return false;
}
void Network::cleanup()
{
  for(unsigned int i=0;i<net->size();i++)
    for(unsigned int i2=0;i2<net->at(i)->size();i2++)
      net->at(i)->at(i2)->cleanup();
}
Network::Network(int i, int o)
{
  inp = i;
  out = o;
}
vector< double > Network::getWeights()
{
  vector<double> ret;
  for(unsigned int i=0;i<net->size();i++){
    for(unsigned int i2=0;i2<net->at(i)->size();i2++){
      linkVector * lv = net->at(i)->at(i2)->getInputLinks();
      for(unsigned int i3=0;i3<lv->size();i3++){
	ret.push_back(lv->at(i3)->getWeight());
      }
      delete lv;
    }
  }
  return ret;
}
vector< double > Network::getStates()
{
  vector<double> ret;
  for(unsigned int i=0;i<net->size();i++){
    for(unsigned int i2=0;i2<net->at(i)->size();i2++){
      ret.push_back(net->at(i)->at(i2)->getState());
    }
  }
  return ret;
}
NeuralNode * findOutput2(nodeVector * nodes)
{
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::OUTPUT)
      return nodes->at(i);
  return NULL;
}
int findBIAS(nodeVector * nodes)
{
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::BIAS)
      return i;
  return -1;
}
void sortBIAS(nodeVector * inputl)
{
  if(inputl->at(inputl->size()-1)->getType()==NeuralNode::BIAS)
    return;
  nodeVector::iterator it = inputl->begin();
  while(it!=inputl->end()&&(*it)->getType()!=NeuralNode::BIAS)
    it++;
  if(it==inputl->end())
    cerr << "inputlayer without any bias..nice" << endl;
  cerr << "moving bias to end of layer...current type at end of layer: " << inputl->at(inputl->size()-1)->getType() << " id: " << inputl->at(inputl->size()-1)->getID() << endl;
  inputl->erase(it);
  inputl->push_back(*it);
}
void Network::addNodes(nodeVector * nodes, bool debug)
{
  int c=0;
  int den=0;
  for(unsigned int i=0;i<nodes->size();i++){
    if(nodes->at(i)->getDepth()>c){
      c = nodes->at(i)->getDepth();
    }
  }

  den = c;
  net = new vector< nodeVector * >();

  for(int i=0;i<=den;i++)//for each level
    net->push_back(new nodeVector());

  for(unsigned int i2=0;i2<nodes->size();i2++){
    net->at(nodes->at(i2)->getDepth())->push_back(nodes->at(i2));
  }

  output = new nodeVector();
  nodeVector * lastlayer = net->at(net->size()-1);
  for(unsigned int i=0;i<lastlayer->size();i++)
    if(lastlayer->at(i)->getType()==NeuralNode::OUTPUT)
      output->push_back(lastlayer->at(i));

  ret.insert(ret.begin(),output->size(),0);
}
bool anncheckforoutput(vector< nodeVector * >  * net)
{
  for(unsigned int i=0;i<net->size();i++){
    for(unsigned int i2=0;i2<net->at(i)->size();i2++){
      if(net->at(i)->at(i2)->getType()==NeuralNode::OUTPUT){
	return true;
      }
    }
  }
  return false;
}
void printnodes(nodeVector * nodes)
{
  for(unsigned int i=0;i<nodes->size();i++)
    cerr << nodes->at(i) << endl;
}
//TODO: change this to be a sorted update with respects to the ID
vector<double> Network::runnet(vector<double> inp)
{
  for(unsigned int i=0;i<inp.size();i++){
    if(net->at(0)->at(i)->getType()==NeuralNode::BIAS)
      cerr << "input node was bias.." << endl;
    net->at(0)->at(i)->setInput(inp.at(i));
  }

  for(unsigned int i=1;i<net->size();i++)
    for(unsigned int i2=0;i2<net->at(i)->size();i2++)
      net->at(i)->at(i2)->update();

  for(unsigned int i=0;i<output->size();i++){
    ret[i] = output->at(i)->getValue();
    if(isnan(ret[i])){
      cout << "ret " << i+1 << " is nan printing network info:" << endl;
      for(unsigned int i2=0;i2<net->size();i2++)
	for(unsigned int i3=0;i3<net->at(i2)->size();i3++)
	  net->at(i2)->at(i3)->printInfo();
    }
  }
  return ret;
}
//should go through and delete the links(only thing not connected to the
//genome!)
Network::~Network()
{
  for(unsigned int i=0;i<net->size();i++){
    for(unsigned int i2=0;i2<net->at(i)->size();i2++){
      net->at(i)->at(i2)->deletelinks();
    }
  }
  for(unsigned int i=0;i<net->size();i++)
    delete net->at(i);

  delete net;
  delete output;
}
NeuralNode::NeuralNode(TransferFunction * func, int iid, char t, int d)
{
  links = new linkVector();
  tFunc = func;
  id = iid;
  valueFromOther = 0;
  input = 0;
  cache = 0;
  bias = false;
  type = t;
  depth = d;
  outputset=false;
}

/*
  These two only support one kind of activation function(must be changed in code)
*/
ostream& operator<< (ostream& os, const NeuralNode *n)
{
  os << "node " << n->id << " " << n->type 
     << " " << n->depth << " " << n->tFunc->ftype<<endl;
  
  return os;
}
istream& operator>> (istream& is, NeuralNode *n)
{
  NeuralNodeSmall * ns = new NeuralNodeSmall();
  string s;
  is >> s;
  ns->id = atoi(s.c_str());
  is >> s;
  ns->type = s[0];
  is >> s;
  ns->depth = atoi(s.c_str());
  is >> s;
  n->fromSmall(ns,s);
  delete ns;

  return is;
}
void NeuralNode::fromSmall(NeuralNodeSmall * ns, string inftype)
{
  id = ns->id; type = ns->type;
  if(type == NeuralNode::BIAS)
    setOutput(1);
  depth = ns->depth;
  initTFunc(inftype);
}
void NeuralNode::initTFunc(string ftype)//helper function for >> operator
{
  tFunc = tfs->getFunction(ftype);//easier :)

}
NeuralNode::~NeuralNode()
{
  delete links;
}

void NeuralNode::update(){
  valueFromOther = 0;
  for(unsigned int i=0;i<links->size();i++){

    valueFromOther += links->at(i)->getOther(this);
  }
}
void NeuralNode::deletelinks()
{
  for(unsigned int i=0;i<links->size();i++){
    if( 
       (links->at(i)->isTo(this)&&(links->at(i)->getFrom()->getDepth()<depth))||
       samedepthcheck(links->at(i),this,true)||
       (links->at(i)->isFrom(this)&&(links->at(i)->getTo()->getDepth()<depth)))
      {
	delete links->at(i);
      }
    else if(samedepthcheck(links->at(i),this,false))
      links->at(i)->setDeletable();
  }

}
void NeuralNode::addLink(Link * link){
  links->push_back(link);
}
linkVector * NeuralNode::getInputLinks()
{
  linkVector * ret = new linkVector();
  for(unsigned int i=0;i<links->size();i++)
    if(links->at(i)->isTo(this))
      ret->push_back(links->at(i));
  return ret;
}
Link * NeuralNode::getLinkTo(NeuralNode * node){
  for(unsigned int i=0;i<links->size();i++)
    if(links->at(i)->isIn(node))
      return links->at(i);
  return 0;
}
void NeuralNode::removeLink(Link * l){
  linkVector::iterator it = links->begin();
  while(it!=links->end() && &(*it)!= &l)
    it++;
  links->erase(it);
}

Link::Link(bool unDir, NeuralNode * first, NeuralNode * second, double w)
{
  uniDir = unDir;
  from = first;
  to = second;
  weight = w;
  first->addLink(this);
  if(&*first!=*&second)
    second->addLink(this);
  deletable = false;
}

Link::~Link()
{
}

double Link::getOther(NeuralNode * calling){
  if(&*calling==&*to){
    return weight*from->getValue();
  }else if(uniDir){
    return weight*to->getValue();
  }else{
    return 0;
  }
}
NeuralNode *  Link::getOtherNode(NeuralNode * calling){
  if(&*calling==&*to){
    return from;
  }else if(uniDir)
    return to;
  else{
    return 0;
  }
}
bool Link::isIn(NeuralNode * testNode)
{
  if(&*testNode==&*from||&*testNode==&*to){
    return true;
  }
  return false;
}
bool Link::isTo(NeuralNode * calling)
{
  if(&*calling==&*to)
    return true;
  return false;
}
bool Link::isFrom(NeuralNode * calling)
{
  if(&*calling==&*from)
    return true;
  return false;
}
