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
#include "gene.h"
#include "genome.h"

Gene * Gene::duplicate(Genome * g)
{
  Gene * ret = new Gene(this);
  ret->from = g->getNode(from->getID());
  ret->to = g->getNode(to->getID());
  return ret;
}

ostream& operator<< (ostream& os, const Gene *g)
{
  os.precision(20);
//   cout << "in operator << for gene " << endl;
//   if(g->from == NULL)
//     cout << "from pointer is null " << endl;
//   if(g->to == NULL)
//     cout << "to pointer is null " << endl;
  os << "gene" << " " << g->from->getID() << " " << g->to->getID() << " "
     << g->w << " " << g->marker << " " << g->enabled << endl;
  return os;
}
istream& operator>> (istream& is, Gene *g)
{
  int fid =0, tid=0,marker=0;
  double w; bool enabld;
  string s;
  is >> s;
  fid = atoi(s.c_str());
  //  g->from = g->g->getNode(fid);
  is >> s;
  tid = atoi(s.c_str());
  //  g->to = g->g->getNode(tid);
  is >> s; 
  //g->w = atof(s.c_str());
  w = atof(s.c_str());
  //g->mutation=g->w;
  is >> s; 
  //g->marker = atoi(s.c_str());
  marker = atoi(s.c_str());
  is >> s;
  enabld = s.find("0")!=string::npos;
  g->fromData(fid,tid,w,marker,enabld);
//   if(s.find("0")!=string::npos)
//     g->enabled = false;
//   else
//     g->enabled = true;
  //  cerr << "s: "<<s<<" read in gene: " << g;
  return is;
}
void Gene::fromData(int fid, int tid, double w, int marker, bool enbld)
{
  from = g->getNode(fid);
  to = g->getNode(tid);
  this->w = w;
  mutation = w;
  enabled = enbld;  
}
bool Gene::equal(Gene * g)
{
  if(g->from->getID()!=from->getID()){
    cerr << "from id was unequal.." << endl;
    return false;
  }
  if(g->to->getID()!=to->getID()){
    cerr << "to id was unequal.." << endl;
    return false;
  }
  if(g->marker!=marker){
    cerr << "marker was unequal.." << endl;
    return false;
  }
  if(g->enabled!=enabled){
    cerr << "enabled was unequal.." << endl;
    return false;
  }
  if(g->mutation!=mutation){
    cerr << "mutation("<<g->mutation<<"!="<<mutation
	 <<") was unequal.. divtest:"<<g->mutation/mutation 
	 << " wdivtest: " << g->w/w << endl;
    return false;
  }
  if(g->w!=w){
    cerr << "weight("<<g->w<<"!="<<w<<") was unequal.." << endl;
    return false;
  }
  return true;
}
void Gene::fromSmall(GeneSmall * gs, Genome * genome){
  g=genome;
  from = g->getNode(gs->fid);
  if(from==NULL)
    cout << "in gene fromsmall and from pointer is null gs->fid: " << gs->fid << endl;  
  to = g->getNode(gs->tid);
  if(to==NULL)
    cout << "in gene fromsmall and to pointer is null gs->tid: " << gs->tid << endl;
  w = gs->w; mutation = gs->w;
  enabled = gs->enabled;
  
}
