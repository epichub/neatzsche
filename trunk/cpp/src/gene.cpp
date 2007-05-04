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
  bool dgb = g->g->getID()==10;
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
