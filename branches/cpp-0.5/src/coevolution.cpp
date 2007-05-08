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

#include "coevolution.h"
string Halloffame::pp()
{
  stringstream ss;
  ss << "games: "<<games<<" n: " << n << " halloffame size: " << halloffame->size() 
     << " perm size: " << perm->size() << endl;
  for(unsigned int i=0;i<halloffame->size();i++){
    ss << "\t" << (i+1)  << ". id: " << halloffame->at(i)->getID() 
       << " fitnesss: " << halloffame->at(i)->getFitness()  << endl;
  }
  return ss.str();
}
/*
  This assumes the population members are sorted.
*/
void Halloffame::update(Population * p)
{
  Phenotypes * newmembers = p->getMembers();
  unsigned int n2 = (unsigned int)n;
  if(first){
    for(unsigned int i=0;i<n2&&i<newmembers->size();i++)
      halloffame->push_back(new Phenotype(newmembers->at(i)->getGenome()->duplicate(1)));
    first = false;
    return;
  }
  int nmc = 0;

  for(unsigned int i=0;i<n2&&i<halloffame->size();i++){
    if(newmembers->at(nmc)->getFitness()>halloffame->at(i)->getFitness()){
      delete halloffame->at(i);
      halloffame->at(i) = new Phenotype(newmembers->at(nmc)->getGenome()->duplicate(newmembers->at(nmc)->getGenome()->getID()));
      halloffame->at(i)->setFitness(newmembers->at(nmc)->getFitness());
      halloffame->at(i)->transferFitness();
      nmc++;
    }
  }
      
}

void Halloffame::evaluate(Phenotypes * p)
{
  // Phenotypes * members = p->getMembers();
  
  double sum=0;
  Phenotype * first = NULL; Phenotype * second = NULL;
  //  cout<<"in hof eval psize: " << p->size() << " permsize: " << perm->size() << " fepointeraddr: " << fe << endl;
  for(unsigned int i=0;i<p->size();i++){
    sum = 0;
    for(unsigned int i3=0;i3<perm->size();i3++){
	fe->f(p->at(i));
	fe->f(perm->at(i3));
    }
    for(int i2=0;i2<n;i2++){

      if(randdouble()<0.5){
	first = halloffame->at(i2); second = p->at(i);
      } else {
	second = halloffame->at(i2); first = p->at(i);
      }
      fe->f(first);fe->f(second);
      sum += p->at(i)->getFitness();
    }
    if(sum<=0){
      sum = 0.0001;
    }
    p->at(i)->setFitness(sum/(double)(n+perm->size()));
    p->at(i)->transferFitness();
  }


}

void Halloffame::print(ostream& os) const //, const Halloffame * h)
{
  os << "HALLOFFAMESTART" << endl;
  for(unsigned int i=0;i<(unsigned int)n&&i<halloffame->size();i++)
    os << "genome" << endl << halloffame->at(i)->getGenome();
  os << "HALLOFFAMEEND" << endl;
}
void Halloffame::read(istream& is) const //, Halloffame * h)
{
 
  string s;
  is >> s;
  //  cerr << "in hof read\n s:" <<s << endl ;
  if(s.find("HALLOFFAMESTART")==string::npos)
    return;
  is >> s;
  Genome * g = NULL;
  while(s.find("HALLOFFAMEEND")==string::npos&&s.find("genome")!=string::npos){
    g = new Genome(tfs);
    is >> g;
    //    cerr << "read in genome: " << g->getID()<<endl;
    halloffame->push_back(new Phenotype(g));
    //    cerr << "converted to phenotype, genome: " << g->getID()<<endl;
    is >> s;
  }
}
