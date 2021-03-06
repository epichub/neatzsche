#include "evoops.h"
static Phenotypes * alive(Phenotypes * p)
{
  Phenotypes * ret = new Phenotypes();
  for(unsigned int i=0;i<p->size();i++)
    if(!p->at(i)->isDead())
      ret->push_back(p->at(i));
  return ret;
}
int Selector::suswheel(int n, Species * s, int elitism, bool debug)
{
  if(n==0)
    return 0;
  double sum = 0;
  s->fsort();
  Phenotypes * omembers = alive(s->getMembers());
  Phenotypes * members = new Phenotypes();
  members->insert(members->begin(),omembers->begin(),omembers->end());
  delete omembers;

  if(members->size()==0)
    return 0;
  bool dbg = false;
  if(elitism>0){
    dbg = true;
  }
//   cout << "elitism: " << elitism << endl;
  for(int i=(elitism-1);i>=0;i--){
//     cout << "giving elitism to id: " << members->at(i)->getID() << endl;
    members->at(i)->incClones();
  }

  n -= elitism;
  int taken = 0;int n2 =0;double tmp = 0, space = 0;
  random_shuffle(members->begin(),members->end());

  if(n>(signed int)members->size())
    n2 = members->size();
  else
    n2 = n;

  while(taken<n){
    for(unsigned int i=0;i<members->size();i++){
      sum += this->eval(members->at(i),i);
    }
    space = sum/(double)n2;//equal spaces..
    sum = 0;
    tmp = 0;
    unsigned int i2=0;

    for(int i=0;i<n2;i++){//for each marker
      tmp += space;
      for(;sum<tmp&&i2<members->size();i2++)
	sum += this->eval(members->at(i2),i2);

      if(i2==members->size())
	i2--;
//       if(members->at(i2)->getGenome()->getGenes()->size()>0){
	members->at(i2)->incEOffspring();
	taken++;
//       }
    }
    if((taken+n2)>n)
      n2 = n-taken;
  }
  delete members;
  return taken+elitism;
}
Population * FitnessProp::select(Population * p,  int elitism)
{
  Selector::select(p,elitism);
  speciesVector * s = p->getSpecies();
  for(unsigned int i = 0 ; i<s->size();i++){
    if(i==speciesforelitism)
      elitism = 0;
    suswheel(s->at(i)->getExpected(),s->at(i),elitism,false);
  }
  return p;
}
void SigmaScaling::calcstddev(Species * sp)
{
  double sum=0;
  m = sp->getAvgFitness();
  Phenotypes * members = sp->getMembers();
  for(unsigned int i=0;i<members->size();i++)
    sum += pow(members->at(i)->getFitness()-m,2);
  s = sqrt(sum/members->size());
}
double SigmaScaling::eval(Phenotype * p, int i)
{
  if(s==0)
    return 1.0;
  else
    return 1 + ((p->getFitness()-m) / (2.0 * s));
}
Population * SigmaScaling::select(Population * p,  int elitism)
{
  //  cout << "sigmaselect elitism: " <<  elitism << endl;
  Selector::select(p,elitism);
  speciesVector * s = p->getSpecies();
  for(unsigned int i = 0 ; i<s->size();i++){
    calcstddev(s->at(i));
    suswheel(s->at(i)->getExpected(),s->at(i),elitism+s->at(i)->getSpecialClones(),true);
    if(s->at(i)->getSpecialClones()>0)
      s->at(i)->setSpecialClones(0);
  }
  return p;
}
double RankSelection::eval(Phenotype * p, int i)
{
  return (((2-s)/n) + 
	  (
	   (2*(n-i-1)*(s-1))/
	   (n*(n-1))
	   )
	  );
}
Population * RankSelection::select(Population * p, int elitism)
{
  Selector::select(p,elitism);
  speciesVector * s = p->getSpecies();
  for(unsigned int i = 0 ; i<s->size();i++){
    if(i==speciesforelitism)
      elitism = 0;
    n = s->at(i)->getExpected();  
    suswheel((int)n,s->at(i),elitism,true);
  }
  return p;
}

Population * LocalReproducer::reproduce(Population * p)
{
  speciesVector * s = p->getSpecies();
  unsigned int size = s->size();
  for(unsigned int i=0;i<size;i++){
    s->at(i)->reproduce();
  }
  int c=0;
  for(unsigned int i=0;i<s->size();i++)
    c += s->at(i)->getChildren()->size();
  
  for(unsigned int i=0;i<s->size();i++)
    s->at(i)->transferChildren();
  p->postepoch();
  return p;
}
