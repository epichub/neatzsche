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
#include "genome.h"
//generate random genome..
int Genome::countHidden()
{
  int h = 0;
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::HIDDEN)
      h++;
  return h;
}
Genome::Genome(TransferFunctions * itfs)
{
  //kommentar..
  genes = new Genes();
  nodes = new nodeVector();
  debug = false;
  innov = NULL;
  tfs = itfs;
  linksmade = false;
}
Genome::Genome(int iid)
{
  genes = new Genes();
  nodes = new nodeVector();
  debug = false;
  innov = NULL;
  tfs = NULL;
  id = iid;
  linksmade = false;
}
//copy genome from given genome...
Genome::Genome(const Genome & genome)
{
  tfs = NULL;
  linksmade = false;
}
Genome::Genome(int genomeid, Genes * igenes, nodeVector * inodes, int inp, int out,
	       NEATsettings * settings, Innovations * is, TransferFunctions * itfs)
{
  id = genomeid;
  genes = igenes;
  for(unsigned int i=0;i<genes->size();i++)
    genes->at(i)->setGenome(this);
  nodes = inodes;
  debug = false;
  innov = is;
  set = settings;
  tfs = itfs;
  linksmade = false;
}
Genome::Genome(int new_id,int i, int o, int n,int nmax, 
	       double r, double linkprob, NEATsettings * settings,
	       Innovations * is,  TransferFunctions * itfs)
{
  id = new_id;
  input = i;
  output = o;
  set = settings;
  nodes = new nodeVector();
  genes = new Genes();
  debug = false;
  innov = is;
  tfs=itfs;
  linksmade = false;
  randomize(i,o,n,nmax,r,linkprob);
}
/*
  a simple method to create a running network from the gene, able to
  take input and create output
*/
Network * Genome::genesis()
{
  if(!linksmade){
    //setting up links..
    for(unsigned int i=0;i<genes->size();i++)
      if(genes->at(i)->isEnabled())
	new Link(false,genes->at(i)->getFrom(),
		 genes->at(i)->getTo(),
		 genes->at(i)->getWeight());
    linksmade = true;
  }

  //setting up the net...
  Network * ret = new Network(input,output);
  ret->addNodes(nodes,true);
  return ret;
}
//delete all pointer and allocate memory
Genome::~Genome()
{
  //delete this genome`s network..
  for(unsigned int i=0;i<nodes->size();i++)
    delete nodes->at(i);
  delete nodes;
  for(unsigned int i=0;i<genes->size();i++)
    delete genes->at(i);
  delete genes;
}
Genome * Genome::duplicate(int id)
{
  Genome * ret = new Genome(id);
  int tf = genes->at(0)->getFrom()->getID();
  nodeVector * retn = ret->nodes;
  for(unsigned int i=0;i<nodes->size();i++)
    retn->push_back(nodes->at(i)->duplicate());
  Genes * retg = ret->genes;
  for(unsigned int i=0;i<genes->size();i++)
    retg->push_back(genes->at(i)->duplicate(ret));
  ret->input = input;
  ret->output = output;
  ret->set = set;
  ret->innov = innov;
  //   if(tfs==NULL)
  //     cerr << "heh tfs null" << endl;
  //   cerr << "heh tfs:" << tfs << endl;
  ret->tfs = tfs;
  int af = ret->genes->at(0)->getFrom()->getID();
  if(tf!=af)
    cerr << "if ikke lik af i genome duplicate" << endl;
  return ret;
}
/*
  mutate p percentage of the genome
  SOME tricks from ken's code:

  some chance of mutating the weight from the original weight,
  and a small chance of mutating the weight from scratch,
  this is set in the config file.
 
*/
void Genome::mutatew(bool coldg)
{
  Genes::iterator it = genes->begin();
  double r = set->getValue("weightmutation_rate");
  double p = set->getValue("mutate_link_weights_power");
  double sev = set->getValue("severe_mutation_rate");

  int endpart = (int)(genes->size()*0.8);
  bool severe = false;

  //different probability points that moves around depending on where
  //you are in the genome.
  double norm = 0;
  double cold = 0;
  int c=0;
  int gtot = genes->size();
  double rt=0,rt2=0;
  if(randdouble()<sev)
    severe = true;

  for(;it!=genes->end();++it){
    if(severe){norm=0.7;cold=0.9;}
    else if(gtot>10&&c>endpart){norm=0.5;cold=0.7;}
    else{
      if(randdouble()<0.5){norm=r;cold=r+0.1;}
      else{norm=r;cold=r;}
    }
    rt = randsign()*randdouble()*p;
    if(!coldg){
      rt2 = randdouble();
      if(rt2<norm){
	(*it)->setWeight((*it)->getWeight()+rt);
      }else if(rt2<cold)
	(*it)->setWeight(rt);
    }
    else
      (*it)->setWeight(rt);
    c++;
  }
}

void Genome::mutatetoggle(int genen)
{
  if(genes->size()==0)
    return;
  Genes::iterator it;
  int totalgenes = genes->size();
  int r = 0;
  Gene * g = NULL;
  for(int i=0;i<genen;i++){
    r = rand()%totalgenes;
    g = genes->at(r);
    if(!g->isEnabled())
      g->enable();
    else{
      it = genes->begin();
      while(it!=genes->end()&&
	    (((*it)->getFrom()->getID()!=g->getFrom()->getID())||
	     ((*it)->isEnabled()==false)||
	     ((*it)->getMarker()!=g->getMarker())))
	++it;
      if(it!=genes->end())
	g->disable();
    }
  }
}
void Genome::mutatereenable()
{
  Genes::iterator it = genes->begin();
  //find a gene wich is disabled
  while(it!=genes->end()&&(*it)->isEnabled())
    it++;
  if(it!=genes->end()&&!(*it)->isEnabled())
    (*it)->enable();
  
}
void Genome::mutateaddlink(int tries)
{
  addLink(tries);
}
void Genome::mutateaddnode(int &cnodeid)
{
  addNode(cnodeid);
}

/*
  adding a node to the network, splitting a link/gene.
*/
void Genome::addNode(int &cnodeid)
{
  int totalgenes = genes->size()-1;
  Gene * g=NULL;
  Genes::iterator it;
  int tryc = 0,genen=0;
  bool test = false;
  string ftype; TransferFunction * ntfunc;

  if(totalgenes<15){
    while(tryc<20&&!test){
      it = genes->begin();
      while ((((it!=genes->end())
	       &&(!((*it)->isEnabled())))||
	      ((it!=genes->end())
	       &&((*it)->getFrom()->getType()==NeuralNode::BIAS)))
	     ||(it!=genes->end()&&randdouble()<0.3))
	++it;

      //       while (((it!=genes->end())&&
      // 	      (randdouble()<0.3))||
      // 	     ((it!=genes->end())
      // 	      &&((*it)->getFrom()->getType()==NeuralNode::BIAS)))
      // 	++it;
      if(it!=genes->end())
	g = *it;


      if(g!=NULL&&g->isEnabled())
	test = true;
      else
	tryc++;
      
    }
  }else{
    tryc = 0;
    while(tryc<20&&!test){
      genen = randint(0,totalgenes);

      g = genes->at(genen);
      if(g->isEnabled()&&g->getFrom()->getType()!=NeuralNode::BIAS)
	test = true;
      ++tryc;
    }
  }
  if(!test){
    cerr << "didnt find any conns to break up...werd tryc: " << tryc << endl
	 << "genome: " << this << endl;
    return; //maybe a bool here for fault checking?
  }

  NeuralNode * from = g->getFrom();
  //   if(from->getType()==NeuralNode::OUTPUT)//TODO: DEBUG printout, remove before final runs
  //     cerr << "id: "<<id<<" from node is output... " << endl; 
  NeuralNode * to = g->getTo();
  int fromid = from->getID();
  int toid = to->getID();
  int d = 0;
  int high = (from->getDepth()<=to->getDepth()) ? to->getDepth(): from->getDepth();
  int low = (from->getDepth()>to->getDepth()) ? to->getDepth() : from->getDepth();
  bool rearrange = false;
  //setting up possibility for more than one transferfunction.
  bool sin = (set->getValue("enable_sinus_tfunc")==1);
  bool gauss = (set->getValue("enable_gauss_tfunc")==1);
  int tf=1;
  double ur;
  if(sin)
    tf++;
  if(gauss)
    tf++;
  ur = 1.0/(double)tf;

  if(high==0){
    cerr << "wtf should not be a node added to depth 0" << endl;
    cerr << "high = " << high << " low = " << low << endl;
    cerr << "fromtype = " << from->getType() << " totype = " << to->getType() << endl;
    cerr << "gene: " << g;
  }
  if((high-low)>1)
    d = (high+low)/2;
  else if(high == low){
    d = high;
    if(high-1 == 0)
      rearrange = true;
    else
      d = high-1;
  }else if((high-low)==1){
    d = high;
    rearrange = true;
  }
  if(d==0){
    cerr << "wtf should not be a node added to depth 0" << endl;
    cerr << "high = " << high << " low = " << low << endl;
    cerr << "fromtype = " << from->getType() << " totype = " << to->getType() << endl;
    cerr << "gene: " << g;
  }

  test = false;
  innovationVector::iterator iit = innov->begin();
  NeuralNode * n = NULL;

  double w = 1.0;
  int h = (int)set->getValue("keeplink");
  if(h==1)
    w = 0.0;
  else
    g->disable();

  ntfunc = tfs->getRandom();

  while(!test){
    if(iit==innov->end()){
      test = true;
      n = new NeuralNode(ntfunc,++cnodeid,
			 NeuralNode::HIDDEN,
			 d);
      genes->push_back(new Gene(innov->getAndIncInnovNum(),from,n,w,this));
      genes->push_back(new Gene(innov->getAndIncInnovNum(),n,to,w,this));
      innov->addInnovation(new Innovation(fromid,toid,
					  innov->getInnovNum()-2,
					  innov->getInnovNum()-1,
					  n->getID(),g->getMarker()));
    }
    else if((*iit)->getType()==NEWNODE&&
	    (*iit)->getFrom()==fromid&&
	    (*iit)->getTo()==toid&&
	    (*iit)->getOldNum()==g->getMarker()){
      test = true;
      n = new NeuralNode(ntfunc,(*iit)->getNewNodeID(),
			 NeuralNode::HIDDEN,d);
      genes->push_back(new Gene((*iit)->getNum(),from,n,w,this));
      genes->push_back(new Gene((*iit)->getNum2(),n,to,w,this));
    }else
      ++iit;
  }
  if(n==NULL)
    cerr << "n er null ffs!" << endl;
  else
    augmentNodes(n,rearrange);
  set->incstructmutcount();

}
int findNodeWithLevel(int l, nodeVector * nodes)
{
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getDepth()==l)
      return i;
  return -1;
}
/*
  will try to find two nodes that are disjoint
  and connect them by a link.
  will search tries times for disjoint nodepair
*/
void Genome::addLink(int tries)
{
  if(nodes->size()==0)
    return;
  unsigned int firstnoninp = 0;//why does he do this? mayb there is a commonly
  //known fact among ANN wizards that one shouldnt
  //connect a input recurrently?
  while(firstnoninp<nodes->size()&&nodes->at(firstnoninp)->getDepth()==0)
    firstnoninp++;
  int tryc=0,nn1=0,nn2=0;
  NeuralNode * np1=NULL;
  NeuralNode * np2=NULL;
  bool localrecur=false;
  Genes::iterator it;
  bool test = false;
  double r = set->getValue("recurrent_conn_prob");
  double nlwmax = set->getValue("newlink_weight_max");
  double p=0;
  string gfile = "net-";
  debug = false;
  bool docheck = true;
  while(tryc<tries){
    docheck = true;
    if(randdouble()>0.5)
      localrecur = true;
    else
      localrecur = false;
    if(localrecur&&r>0){
      nn1 = randint(firstnoninp,nodes->size()-1);
      nn2 = nn1;
    }else{
      nn1 = randint(0,nodes->size()-1);
      nn2 = randint(firstnoninp-1,nodes->size()-1);
    }

    np1 = nodes->at(nn1);
    np2 = nodes->at(nn2);
#ifdef DEBUG
    cerr << "firstnoninp: "<<firstnoninp<<" nn1: "<<nn1<<"  nn2: "<<nn2<<" np1id: "<<np1->getID()<<" np2id:" << np1->getID() << endl;
#endif
    p = randdouble();
    if(np1->getDepth()>=np2->getDepth())
      if(p<=r)
	docheck = false;
    if(docheck){
      if(debug)
	cerr << "doing checks.." << endl;
      it = genes->begin();
      //search for already existing link.
#ifdef DEBUG
      cerr << "checking link .. "<<(*it);
#endif
      while((it!=genes->end())&&
	    (!(((*it)->getFrom()==np1)&&
	       ((*it)->getTo()==np2)))){
	++it;
#ifdef DEBUG
 	if(it!=genes->end())
 	  cerr << "checking link .. "<<(*it);
#endif
      }

#ifdef DEBUG
      cerr << "id: "<<id<<" p:"<<p<<" node1id:"<<np1->getID()<<" node2id:"<<np2->getID()
	   <<" np1->getDepth():"<<np1->getDepth()<<"np2->getDepth()"
	   <<np2->getDepth()<<endl;
#endif
      if(it!=genes->end()){//found a existing link
#ifdef DEBUG
	cerr << "link already there.." << " genes size: " << genes->size() <<endl;
	cerr << this;
#endif
	tryc++;
      }

      else {
	test = true;
	tryc = tries;
      }
      if(!test){
#ifdef DEBUG
	cerr << "not adding a link" << endl;
#endif
      }else{
#ifdef DEBUG
	cerr << "!!! adding link from id:"<<np1->getID()<<" d:"<<np1->getDepth()<<" id:"<<np2->getID()<<" d:"<<np2->getDepth()<<endl; 
#endif
	set->incstructmutcount();
	test = false;
	innovationVector::iterator init = innov->begin();
	double nw=0;
	while(!test){
	  if(init==innov->end()){
	    nw = randsign()*randdouble()*nlwmax;
	    genes->push_back(new Gene(innov->getInnovNum(),np1,np2,nw,this));
	    innov->addInnovation(new Innovation(nn1,nn2,innov->getInnovNum(),nw));
	    innov->incInnovNum();
	    test=true;
	  }else if((*init)->getType()==NEWLINK&&
		   (*init)->getFrom()==nn1&&
		   (*init)->getTo()==nn2){
	    genes->push_back(new Gene((*init)->getNum(),np1,np2,(*init)->getWeight(),this));      
	    test=true;
	  }else
	    ++init;
	}
      }
    }

  }
}
static inline nodeVector * findOutputs(nodeVector * nodes)
{
  nodeVector * ret = new nodeVector();
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::OUTPUT)
      ret->push_back(nodes->at(i));
  return ret;
}
static inline void incDepth(nodeVector * nodes)
{
  for(unsigned int i=0;i<nodes->size();i++)
    nodes->at(i)->incDepth();
}
static inline void incDepth(nodeVector * nodes, int with)
{
  for(unsigned int i=0;i<nodes->size();i++)
    nodes->at(i)->setDepth(nodes->at(i)->getDepth()+with);
}
void augmentNodevector(nodeVector * nodes, NeuralNode * n, bool rearrange)
{
  int d = n->getDepth();
  if(rearrange)
    for(unsigned int i=0;i<nodes->size();i++)
      if(nodes->at(i)->getDepth()>=d)
	nodes->at(i)->incDepth();
  nodes->push_back(n);
  sort(nodes->begin(),nodes->end(),nodedepthcomp);
}
void Genome::augmentNodes(NeuralNode * n, bool rearrange)
{
  augmentNodevector(nodes,n,rearrange);
}
//cross this genome with the genome g
Genome * Genome::crossover(Genome * g, bool avg, 
			   double f1, double f2, 
			   int genomeid, bool sp)
{
  Genes::iterator it1 = genes->begin();
  Gene * ofirst = genes->at(0);
  Genes::iterator it2 = g->genes->begin();
  Genes::iterator it3;
  bool skip = false, p1best=false, p2best=false, cont=true;
  Gene * gene; int innonum1 = 0, innonum2=0;
  NeuralNode * fnode = NULL; NeuralNode * tnode = NULL;
  Genes * newgenes = new Genes();
  nodeVector * newnodes = new nodeVector();
  //adding the nodes that are static through the generations(input and output nodes)
  nodeVector stat = getConstantNodes();
  NeuralNode * highestd = NULL;
  newnodes->insert(newnodes->begin(),stat.begin(),stat.end());
  nodeVector * o = findOutputs(newnodes);
  if(f1>f2)
    p1best = true;
  else
    p2best = true;

  Genes::iterator stopper=g->genes->end(),it1stopper=genes->end(),it2stopper=g->genes->end();
  int crosspoint=0,genecounter=0;
  if(sp){
    if(genes->size()<(g->genes)->size()){
      if(genes->size()!=1)      
	crosspoint = randint(0,genes->size()-1);
      crosspoint = 0;
    }else{
      if((g->genes)->size()!=1)
	crosspoint = randint(0,(g->genes)->size()-1);
      else
	crosspoint = 0;
      it1 = g->genes->begin();
      it2 = genes->begin();
      it1stopper = g->genes->end();
      it2stopper = genes->end();
      stopper = genes->end();
    }
  }
  int it1c = 0,it2c=0;
  while(!(it1==it1stopper &&
	  it2==it2stopper)&&cont){
    gene = NULL;
    if(sp&&it2==stopper){
      break;
    }

    skip = false;
    if(it1==it1stopper){
      if(!sp&&p1best){ skip=true; cont= false;}
      else{//jump out of loop
	gene = new Gene(*(*it2));
	++it2;
      }
    }else if(it2==it2stopper){
      if(!sp&&p2best){ skip=true; cont= false;}
      else{
	gene = new Gene(*(*it1));
	++it1;
      }
    }else{
      //      if(debug)
      //	cerr << "aligned..";
      //if((*it1)==NULL)
      //      if(it1==it1stopper)
      //	cerr << "it1 er uttafor..";
      //      if(it2==it2stopper)
      //	cerr << "it2 er uttafor..";
      //	cerr << "it1c: " << it1c << " it2c:" << it2c << endl;
      innonum1 = (*it1)->getMarker();
      innonum2 = (*it2)->getMarker();
      if(innonum1 == innonum2){

	if(!avg&&!sp){
	  if(randdouble()<0.5)
	    gene = new Gene(*(*it1));
	  else
	    gene = new Gene(*(*it2));
	}else if(sp&&genecounter!=crosspoint){
	  if(genecounter<crosspoint)
	    gene = new Gene(*(*it1));
	  else
	    gene = new Gene(*(*it2));
	}else{
	  gene = new Gene(innonum1,NULL,NULL,
			  ((*it1)->getWeight()+(*it2)->getWeight())/2.0,
			  this);

	  if(randdouble()<0.5) gene->setFrom((*it1)->getFrom());
	  else gene->setFrom((*it2)->getFrom());
	  
	  if(randdouble()<0.5) gene->setTo((*it1)->getTo());
	  else gene->setTo((*it2)->getTo());
	}
	if((!(*it1)->isEnabled())||(!(*it2)->isEnabled()))
	  if(randdouble()<0.75)
	    gene->disable();
	++it1;
	++it2;
	++it2c;++it1c;
	++genecounter;
      }else if(innonum1<innonum2){
	if(!sp){
	  if(!sp&&!p1best) skip = true;
	  else
	    gene = new Gene(*(*it1));
	  ++it1;
	  ++it1c;

	}else{
	  if(genecounter<crosspoint){
	    gene = new Gene(*(*it1));
	    ++it1;
	    ++it1c;
	    ++genecounter;
	  }else{
	    gene = new Gene(*(*it2));
	    ++it2c;
	    ++it2;
	  }
	  
	}
      }else if(innonum1>innonum2){
	gene = new Gene(*(*it2));
	++it2;
	++it2c;
	if(!sp&&!p2best) skip = true;
      }
    }
    if(skip)
      delete gene;
    else{
      if(!skip){ // do sanity check * SHOUTS GO OUT TO KEN ;)
	skip = !geneSanity(newgenes,gene);
	if(skip){
	  if(debug)
	    cerr << "sanity check has failed!" << endl;
	  delete gene;
	}
      }
      if(!skip){//all is alright, just need to possibly add the nodes
	fnode = gene->getFrom();
	tnode = gene->getTo();
	if(findAdd(fnode,tnode,newnodes,gene)){
	  highestd = (fnode->getDepth()>tnode->getDepth()) ? fnode : tnode;
	  if(highestd->getDepth()==o->at(0)->getDepth())
	    incDepth(o);
	  else if(highestd->getDepth()>o->at(0)->getDepth())
	    incDepth(o,(highestd->getDepth()-o->at(0)->getDepth())+1);
	}
	newgenes->push_back(gene);
      }
    }
  }
  //TODO do i need to do this??
  sort(newnodes->begin(),newnodes->end(),nodedepthcomp);
  delete o;
  Gene * nfirst = newgenes->at(0);
  if(nfirst->getFrom()->getID()!=ofirst->getFrom()->getID()&&nfirst->getFrom()->getType()==NeuralNode::BIAS)
    cerr << "ofirstgetfromid != nfirstgetfromid ntype: bias otype:" << ofirst->getFrom()->getType() << endl;
  return new Genome(genomeid,newgenes,newnodes,input,output,set,innov,tfs);
}

bool Genome::findAdd(NeuralNode * fnode, NeuralNode * tnode,
		     nodeVector *newnodes, Gene * gene)
{
  NeuralNode * nfnode = getNode(newnodes,fnode->getID());
  NeuralNode * ntnode = getNode(newnodes,tnode->getID());
  bool add = false;
  if(!nfnode){
    nfnode = fnode->duplicate();
    newnodes->push_back(nfnode);
    add = true;
  }
  if(!ntnode){
    ntnode = tnode->duplicate();
    newnodes->push_back(ntnode);
    add = true;
  }
  gene->setFrom(nfnode); gene->setTo(ntnode);
  return add;
}
bool Genome::geneSanity(Genes * ge, Gene * g)
{
  Genes::iterator it = ge->begin();
  while ((it!=ge->end())&&
	 (!(((((*it)->getFrom())->getID())==(((g)->getFrom())->getID()))&&
	    ((((*it)->getTo())->getID())==(((g)->getTo())->getID())) ))&&
	 (!(((((*it)->getFrom())->getID())==(((g)->getTo())->getID()))&&
	    ((((*it)->getTo())->getID())==(((g)->getFrom())->getID()))
	    )))
    ++it;
  if(it!=ge->end())
    return false;
  return true;
}
double Genome::compare(Genome * g)
{
  int disj=0;
  int excess=0;
  double mutdiffsum=0;
  int match=0;
  Genes * genes1 = g->genes;
  if(g->genes==NULL)
    cerr << "g sin genes var jo null ffs!?" << endl;
  Genes::iterator it1 = genes1->begin();
  Genes::iterator it2 = genes->begin();
  Gene * g1 = NULL;
  Gene * g2 = NULL;
  int i1c = 0, i2c = 0, num1=0,num2=0;
  while(it1!=genes1->end()||it2!=genes->end())
    {
      //at end of this gene
      if(it2==genes->end()){
	it1++;
	i1c++;
	excess++;
      }else if(it1==genes1->end()){//at the end of the other gene
	it2++;
	i2c++;
	excess++;
      }else{ //not at the end of any of the genes
	g1 = (*it1);
	g2 = (*it2);
	num1 = g1->getMarker();
	num2 = g2->getMarker();
	if(num1==num2){
	  match++;
	  mutdiffsum += fabs(g1->getMutation()-g2->getMutation());
	  it1++;it2++;i1c++;i2c++;
	}else if(num1>num2){
	  disj++;
	  it2++;
	  i2c++;
	}else{
	  disj++;
	  it1++;
	  i1c++;
	}
      }
    }

  return ((set->getValue("disjoint_coeff")*disj)+
	  (set->getValue("excess_coeff")*excess)+
	  (set->getValue("mutdiff_coeff")*(mutdiffsum/(double)match)));
}

/*
  this method should generate a genome with with inpn inputs, outn
  outputs, hid out of hidmax hidden units, and random connectivity.
  If rec is true then recurrent connections will be included.  The
  last input is a bias Linkprob is the probability of a link
*/
void Genome::randomize(int inpn, int outn,
		       int hid, int hidmax,
		       double rec, double linkprob)
{
  int totalnodes = inpn + outn + hid; // total number of nodes
  //   int count = 0; // the "innovation" counter.
  TransferFunction * inpfunc = tfs->getTA();
  TransferFunction * func = NULL;
  int layn = 0;
  //creating all the nodes of this genome
  for(int i=0;i<inpn;i++)
    nodes->push_back(new NeuralNode(inpfunc,(i+1),NeuralNode::INPUT,layn));
  nodes->push_back(new NeuralNode(inpfunc,(inpn+1),NeuralNode::BIAS,layn));
  nodes->at(inpn)->setOutput(1);
  layn++;
  for(int i=0;i<hid;i++){
    func = tfs->getRandom();
    nodes->push_back(new NeuralNode(func,(inpn+i+2),NeuralNode::HIDDEN,layn));
    //old    nodes->push_back(new NeuralNode((func = tfs->getRandom()),(inpn+i+2),NeuralNode::HIDDEN,func->ftype,layn));
  }

  if(hid>0)
    layn++;  
  func = tfs->getSigmoid();//TODO: check if output should always be sigmoid??
  for(int i=0;i<outn;i++)
    nodes->push_back(new NeuralNode(func,(inpn+hid+i+2),NeuralNode::OUTPUT,layn));
  innov->setNodeNum(nodes->size()+1);
  NeuralNode * from = NULL;
  NeuralNode * to = NULL;
  bool test=false;
  double nw=10;
  double nlwmax = set->getValue("newlink_weight_max");
  for(int i=0;i<totalnodes+1;i++){
    for(int i2=0;i2<totalnodes+1;i2++){
      from = nodes->at(i);
      to = nodes->at(i2);
      //       if(from->getType()==NeuralNode::INPUT
      //       cerr << "from er inp to er ikek lvl 0" << endl;
      if(randdouble()<linkprob){//create link
	if(!((from->getDepth()>=to->getDepth()&&randdouble()>=rec))  // if rec and rec is true, or if its not rec
	   && !(from->getDepth()==0 && 
		to->getDepth()==0)){//no links from input to input
	  test=false;
	  innovationVector::iterator init = innov->begin();
	  nw=0;
	  while(!test){
	    if(init==innov->end()){
	      nw = randsign()*randdouble()*nlwmax;
	      genes->push_back(new Gene(innov->getInnovNum(),from,to,nw,this));
	      innov->addInnovation(new Innovation(from->getID(),to->getID(),innov->getInnovNum(),nw));
	      innov->incInnovNum();
	      test=true;
	    }else if((*init)->getType()==NEWLINK&&
		     (*init)->getFrom()==from->getID()&&
		     (*init)->getTo()==to->getID()){
	      genes->push_back(new Gene((*init)->getNum(),from,to,(*init)->getWeight(),this));      
	      test=true;
	    }else{
	      ++init;
	    }
	  }
	  // 	  genes->push_back(new Gene(count,from,
	  // 			      to,
	  // 			      randsign()*randdouble(),this));
	}
      }
    }
  }
  //  innov->setInitNum(genes->size()+1);
}
istream& operator>> (istream& is, Genome *g)
{
  string s;
  is >> g->id;
  is >> s;
  int c=-1;
  string ls;
  if(g->debug)
  cerr << "in genome >> operator s:\"" << s << "\""<< " id: "<< g->id << endl;
  while(s.find("node")!=string::npos){
    NeuralNode * n = new NeuralNode(g->tfs);
    is >> n;
    if(n->getDepth()==0)
      c++;
    g->nodes->push_back(n);
    ls = s;
    is >> s;
  }
  if(g->debug)
  cerr << "after node readin.." << endl;
  g->nodes->at(c)->setInput(1);
  while(s.find("gene")!=string::npos){
    Gene * n = new Gene();
    n->setGenome(g);
    is >> n;
    g->genes->push_back(n);
    s="";
    is >> s;
//     if(g->id==10){
//       cerr << "read gene nr " << ++c2 << " s: " << s <<endl;
//     }
  }
  if(g->debug)
  cerr << "after gene readin.." << endl;
  if(g->innov){
    g->innov->setInitNum(g->genes->size()+1);
    g->innov->setNodeNum(g->nodes->size()+1);
  }
  if(g->debug)
    cerr << "s: "<<s<<" in end of >> operator in genome genes: " << g->genes->size() << " nodes: " << g->nodes->size()  << endl;
  return is;
}
ostream& operator<< (ostream& os, const Genome *g)
{
  //  stringstream ss;
  nodeVector * nodes = g->nodes;
//   os.flush();
  os << g->id<<endl;
  for(unsigned int i=0;i<nodes->size();i++){
    os << nodes->at(i);
//     os.flush();
  }
  Genes * genes = g->genes;
  for(unsigned int i=0;i<genes->size();i++){
    os << genes->at(i);
//     os.flush();
  }
//   os.flush();
  os << "genomeend" << endl;
  return os;
}
string Genome::print()
{
  stringstream ss;
  ss << this;
  return ss.str();
}
bool Genome::equal(Genome * g)
{
  Genes * go = g->genes;
  if(go->size()!=genes->size())
    return false;
  for(unsigned int i=0;i<genes->size();i++){
    if(!genes->at(i)->equal(go->at(i))){
      cerr << "some gene was unequal.." << endl;
      return false;
    }

  }
 
  nodeVector * no = g->nodes;
  if(no->size()!=nodes->size())
    return false;
  for(unsigned int i=0;i<nodes->size();i++){
    if(nodes->at(i)->getID()!=no->at(i)->getID()){
      cerr << "some node was unequal.." << endl;
      return false;
    }
  }
  return true;
}
NeuralNode * Genome::getNode(nodeVector * n, int id)
{
  for(unsigned int i=0;i<n->size();i++)
    if(id==n->at(i)->getID())
      return n->at(i);
  return NULL;
}

NeuralNode * Genome::getNode(int id)
{
  return getNode(nodes,id);
}

nodeVector Genome::getConstantNodes()//should return input and output nodes
{
  nodeVector ret;
  for(unsigned int i=0;i<nodes->size();i++)
    if(nodes->at(i)->getType()==NeuralNode::INPUT
       ||nodes->at(i)->getType()==NeuralNode::OUTPUT
       ||nodes->at(i)->getType()==NeuralNode::BIAS)
      ret.push_back(nodes->at(i)->duplicate());
  return ret;
}
int Genome::extrons()
{
  int c=0;
  for(unsigned int i=0;i<genes->size();i++)
    if(genes->at(i)->isEnabled())
      c++;
  return c;
}
