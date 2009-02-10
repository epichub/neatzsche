/*
  Copyright 2007 Bj�rn Magnus Mathisen
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
  
//   if(nodes->at(29)->getType()!=NeuralNode::BIAS)
//     cerr << "in addnodes nodetype at 29: " << nodes->at(29)->getType() 
// 	 << " bias at " << findBIAS(nodes) << endl;
  int c=0;
  int den=0;
  for(unsigned int i=0;i<nodes->size();i++){
    if(nodes->at(i)->getDepth()>c){
      //      den++;
      c = nodes->at(i)->getDepth();
    }
  }
  //  cerr << "c: " << c << endl;
  den = c;
  net = new vector< nodeVector * >();
  //bool fuckup = false;
  for(int i=0;i<=den;i++)//for each level
    net->push_back(new nodeVector());
  //  for(int i=0;i<=den;i++){//for each level
    for(unsigned int i2=0;i2<nodes->size();i2++){
      //      if(nodes->at(i2)->getDepth()==i){
//       if(nodes->at(i2)->getType()==NeuralNode::OUTPUT&&nodes->at(i2)->getDepth()!=c){
// 	cerr << "adding output node to layer i:" << nodes->at(i2)->getDepth() << " not equal to c: " << c <<  endl;
// 	fuckup = true;
//       }
//       if(fuckup&nodes->at(i2)->getDepth()==c)
// 	cerr << "node that did have the highest lvl: " << nodes->at(i2);
//       if(nodes->at(i2)->getDepth()<0 || nodes->at(i2)->getDepth() >= net->size())
// 	cerr << "depth er utenfor net size scope; netsize: " << net->size() << " node depth: " << nodes->at(i2)->getDepth() << endl;
      net->at(nodes->at(i2)->getDepth())->push_back(nodes->at(i2));
      //      }
      }
    //  }
    //sortBIAS(net->at(0));
  output = new nodeVector();
  nodeVector * lastlayer = net->at(net->size()-1);
  for(unsigned int i=0;i<lastlayer->size();i++)
    if(lastlayer->at(i)->getType()==NeuralNode::OUTPUT)
      output->push_back(lastlayer->at(i));

//   cerr << "input layer: " << net->at(0)->size() << endl;
//   cerr << "middle layer: " << net->at(1)->size() << endl;
//   cerr << "output layer: " << net->at(2)->size() << endl;
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
  //  cerr << "output in phenotype: " << anncheckforoutput(net) << endl;
//   cerr << "in runnnet... netat0size: "<<net->at(0)->size()<<" inpsize: " << inp.size() << endl;
//   cerr << "inp: " << printvector(inp) << endl;
  if(inp.size()!=net->at(0)->size()-1)
    {
      cerr << "inp("<<inp.size()<<") wasnt aligned with net("<<net->at(0)->size()-1<<").." << endl;
      printnodes(net->at(0));
      return vector<double>();
    }

  for(unsigned int i=0;i<inp.size();i++){
    if(net->at(0)->at(i)->getType()==NeuralNode::BIAS)
      cerr << "input node was bias.." << endl;
    net->at(0)->at(i)->setInput(inp.at(i));//setoutput to avoid the transferfunc..
//     if(inp.at(i)!=0)
//       cerr << "ikke 0 inp: "<< inp.at(i)
// 	   <<" .. nodeid: " << net->at(0)->at(i)->getID() 
// 	   <<" nodetype: " << net->at(0)->at(i)->getType() 
// 	   <<" node links: " << net->at(0)->at(i)->getLinks()->size() << endl;
  }
  for(unsigned int i=1;i<net->size();i++){
    for(unsigned int i2=0;i2<net->at(i)->size();i2++){
      net->at(i)->at(i2)->update();
    }
  }
  vector<double> ret;
  //nodeVector * output = net->at(net->size()-1);
  
  //  if(output->at(0)->getFType().find("so")==string::npos);
    //   cerr << "size of net: "<<net->size() <<" outputsize: " << output->size() 
//        << " size at one lvl further back " << net->at(net->size()-2)->size() <<endl;
  //  cerr << "links to last output node: " << output->at(output->size()-1)->getInputLinks()->size()<<endl;
  for(unsigned int i=0;i<output->size();i++)
    ret.push_back(output->at(i)->getValue());
  return ret;
}
//should go through and delete the links(only thing not connected to the
//genome!)
Network::~Network()
{
  //  cerr << "netsize: " << net->size() << endl;
  //  cerr << "deleting net " << this << endl;
  //  if((&this)==0x696620)
  //    cerr << "deleting " << 0x696620 << endl;
  for(unsigned int i=0;i<net->size();i++){
    //    cerr << "i net destr i:" << i << endl;
    //    if(net->at(i)==NULL)
    //      cerr << "net->at(i) er NULL" << endl;
    //    cerr << "size av net->at(i):" << net->at(i)->size() << endl;
    for(unsigned int i2=0;i2<net->at(i)->size();i2++){
      //      cerr<< "i net destr i2: " << i2 << endl;
      net->at(i)->at(i2)->deletelinks();
    }
  }
  for(unsigned int i=0;i<net->size();i++)
    delete net->at(i);

  delete net;
  delete output;
}
NeuralNode::NeuralNode(TransferFunction * func, int iid, char t, string ft, int d)
{
  links = new linkVector();
  tFunc = func;
  id = iid;
  valueFromOther = 0;
  input = 0;
  bias = false;
  type = t;
  ftype = ft;
  depth = d;
}

/*
  These two only support one kind of activation function(must be changed in code)
*/
ostream& operator<< (ostream& os, const NeuralNode *n)
{
  os << "node " << n->id << " " << n->type 
     << " " << n->depth << " " << n->ftype<<endl;
  return os;
}
istream& operator>> (istream& is, NeuralNode *n)
{
  //  cerr << "in nnode >> operator " << endl;
  int id = 0; char type; int d; string ftype = "";
  string s;
  is >> s;
  // cerr << "id: " << s << endl;
  id = atoi(s.c_str());
  is >> s;
  //  cerr << "type: " << s << endl;
  type = s[0];
  is >> s;
  //  cerr << "d: " << s << endl;
  d = atoi(s.c_str());
  is >> s;
  //  cerr << "ftype: " << s << endl;
  ftype = s;
  //is >> s;cerr << " id: " << s;  is >> type; is >> d; is >> ftype;
  //cerr << "id: " << id << " type: " << type << " d: " << d << " ftype : " << ftype << endl;
  n->id = id; n->type = type; n->depth=d; n->ftype=ftype;
  n->initTFunc();
  return is;
}
void NeuralNode::initTFunc()//helper function for >> operator
{
  //  cerr << "in initFunc()" << endl;
  tFunc = tfs->getFunction(ftype);//easier :)
  //   if(ftype.find("so")!=string::npos){
//     tFunc = new SigmoidTransfer(4.9);//4.9 is NEAT standard
//   }else if(ftype.find("si")!=string::npos){
//     tFunc = new SignumTransfer();
//   }else if(ftype.find("ta")!=string::npos){
//     tFunc = new TransferFunction();
//   }else if(ftype.find("sin")!=string::npos){
//     tFunc = new SinusTransfer();
//   }else if(ftype.find("gauss")!=string::npos){
//     tFunc = new GaussTransfer(0.5,0.15);//TODO: make this some setting or something
//   }
}
NeuralNode::~NeuralNode()
{
  // delete tFunc;
  delete links;
}

void NeuralNode::update(){
  valueFromOther = 0;
  for(unsigned int i=0;i<links->size();i++){
     valueFromOther += links->at(i)->getOther(this);
  }
//   if(type==OUTPUT&&valueFromOther!=0)
//     cerr << "ikke lik nul..." << endl;
//   else if(type==OUTPUT&&valueFromOther==0)
//     cerr << "fikk null inputs er: " << links->size() << endl;
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
  // cerr << "this:" << this << " links:" << links << 
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
