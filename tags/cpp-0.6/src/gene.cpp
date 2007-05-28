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
  os << "gene" << " " << g->from->getID() << " " << g->to->getID() << " "
     << g->w << " " << g->marker << " " << g->enabled << endl;
  return os;
}
istream& operator>> (istream& is, Gene *g)
{
  int id =0;
  string s;
  is >> s;
  id = atoi(s.c_str());
  g->from = g->g->getNode(id);
  is >> s;
  id = atoi(s.c_str());
  g->to = g->g->getNode(id);
  is >> s; 
  g->w = atof(s.c_str());
  g->mutation=g->w;
  is >> s; 
  g->marker = atoi(s.c_str());
  is >> s;
  if(s.find("0")!=string::npos)
    g->enabled = false;
  else
    g->enabled = true;
  //  cerr << "s: "<<s<<" read in gene: " << g;
  return is;
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
