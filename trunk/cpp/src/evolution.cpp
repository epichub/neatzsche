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

#include "evolution.h"
#include "evaluator.h"

void Population::updateSpeciesStats()
{
  for(unsigned int i=0;i<species->size();i++){//update species stats
    species->at(i)->updateavgf();
    species->at(i)->updatemaxminf();
  }
}

//this method should be run after every population member is evaluated
//and given a fitness. This method will go through the species,
//assigning a number of offpsring to each species, preparing
//for selection within the species and finally reproduction.
void Population::preepoch()
{
  //  if(debug)
//     cerr << "prepoch start: curgen:"<<curgen<<" members size: " << members->size() << " species size : " << species->size() << endl;
//     cout << "member0 fitness: " << members->at(0)->getFitness()<<endl;
  double skim = 0;
  double sum = 0;
  unsigned int total_expected = 0;
  double comp = set->getValue("compat_threshold");

  if(spectarget!=0&&curgen>1){
    //do stuff to adjust species towards the target..
    if(species->size()<spectarget)
      set->setValue("compat_threshold",comp-compmod);
    else if(species->size()>spectarget)
      set->setValue("compat_threshold",comp+compmod);
  }

  for(unsigned int i=0;i<species->size();i++){
    species->at(i)->adjustFitness(set);
  }

  for(unsigned int i=0;i<species->size();i++){//update species stats
    sum += species->at(i)->getAvgFitness();
  }

  double tmp = 0,tmp2 = 0;
  for(unsigned int i=0;i<species->size();i++){
    tmp = (species->at(i)->getAvgFitness()/sum)*size;
    if(skim>1.0){
      tmp += 1.0;
      skim--;
    }      
    tmp2 = floor(tmp);
    skim += tmp-tmp2;
//     cerr << "species->at(i)->getAvgFitness(): "<< species->at(i)->getAvgFitness()
// 	 <<" sum: "<<sum
// 	 <<" members: "<< species->at(i)->getMembers()->size()
// 	 <<" setting expected to tmp: " << (int)tmp << endl;
//    cerr << "avgfit: " << species->at(i)->getAvgFitness() <<" tmp:" << tmp << endl;
    species->at(i)->setExpected((int)tmp);
  }
  cerr << "setting special clones for species " <<   members->at(0)->getSpecies()->getID() 
       << " of: " << members->at(0)->getOrigFitness() << endl;
  members->at(0)->getSpecies()->setSpecialClones(1);
  //  exit(0);
  for(unsigned int i=0;i<species->size();i++)
    total_expected += species->at(i)->getExpected();
//   if(total_expected>150)
//     cout << "gen: "<<curgen<<" total expected er over 150: "<<total_expected<<" ..members size: " << members->size() << endl;
  if(total_expected<(unsigned int)size){
    //cout << "smaller than size.. total_expected: " << total_expected << endl;
    int max = 0;
    Species * best = NULL;
    for(unsigned int i=0;i<species->size();i++){   
      if(species->at(i)->getExpected()>max){
	best = species->at(i);
	max = best->getExpected();
      }
    }
    best->incExpected(size-total_expected);
  }
  total_expected = 0;
  for(unsigned int i=0;i<species->size();i++)
    total_expected += species->at(i)->getExpected();

  bestspecnum=species->at(0)->getID();
//   Species * top = species->at(0);
//   Species * bottom = species->at(species->size()-1);
  if(members->at(0)->getOrigFitness()>highestf){
    highestf = members->at(0)->getOrigFitness();
    highestlastchanged=0;
  }else{
    highestlastchanged++;
  }

  if(highestlastchanged>=dropoffage+5){//YAHK(Yet another heuristic from ken)
    highestlastchanged=0;
    int half = size/2;
    Species * best = species->at(0);
    best->setExpected(0);
    best->getChamp()->setPopulationChampClones(half);
    best->setLastImprovement(best->getAge());

    if(species->size()!=1){
      Species * secondbest = species->at(1);
      secondbest->setExpected(0);
      secondbest->getChamp()->setPopulationChampClones(half);
      secondbest->setLastImprovement(secondbest->getAge());
      for(unsigned int i=2;i<species->size();i++)
	species->at(i)->setExpected(0);
    }else{
      best->getChamp()->setPopulationChampClones(size);
      best->setExpected(0);					 
    }
  }
  //the stolen babies...hmmmm :P
  else if(steal>0){
    int taken = 0;
    for(int i=(species->size()-1);i>=0;i--){
      Species * eval = species->at(i);
      if(eval->getAge()>5&&
	 eval->getExpected()>2){
	if((eval->getExpected()-1)>=(taken-steal)){
	  eval->setExpected(eval->getExpected()-(taken-steal));
	  taken += steal;
	}else{
	  taken += eval->getExpected()-1;
	  eval->setExpected(1);
	}
      }
    }
    int give[3] = {(taken/5),(taken/5),(taken/10)};
    int c = 0;
    for(unsigned int i=0;i<species->size();i++){
      Species * curs = species->at(i);
      if(!(curs->getLastImprovement()>dropoffage)&&(taken>=give[c])){
	taken -= give[c];
	curs->getChamp()->setPopulationChampClones(give[c++]);
      }
    }
    if(taken>0){
      Species * best = species->at(0);
      best->getChamp()->setPopulationChampClones(best->getChamp()->getPopulationChampClones()+taken);
      best->setExpected(best->getExpected()+taken);
    }
  }
//   Species * top = species->at(0);
//   Species * bottom = species->at(species->size()-1);
//   cerr << "sorted species.." << endl
//        << "top species("<<top->getID()<<") champ("<<top->getChamp()->getID()<<")f:" << top->getChamp()->getOrigFitness()
//        << " maxf:" << top->getMaxFitness() << " avgf:" << top->getAvgFitness() << " minf:" << top->getMinFitness() 
//        << " s:"<<top->getMembers()->size() << " e:" << top->getExpected() << endl
//        << "bottom species("<<bottom->getID()<<") champ("<<bottom->getChamp()->getID()<<")f:"<<bottom->getChamp()->getOrigFitness()
//        << " maxf:" << bottom->getMaxFitness() << " avgf:" << bottom->getAvgFitness() << " minf:" << bottom->getMinFitness() 
//        << " s:"<<bottom->getMembers()->size() << " e:" << bottom->getExpected() << endl;


  //removing all the pop members with no offspring... sorry .. :P
  Phenotypes * tmpv = new Phenotypes();
  for(unsigned int i=0;i<members->size();i++)
    if(!members->at(i)->isDead())
      tmpv->push_back(members->at(i));

  delete members;
  members = tmpv;
  
  for(unsigned int i=0;i<species->size();i++){
    species->at(i)->incAge();
    species->at(i)->removeDead();
  }
}
void Species::removeDead()
{
  Phenotypes * tmp = new Phenotypes();
  Phenotype * ofirst = NULL;
  for(unsigned int i=0;i<members->size();i++){
    if(!members->at(i)->isDead()){
      tmp->push_back(members->at(i));
    }else{
      if(first == members->at(i))
	ofirst = members->at(i);
      else
	delete members->at(i);
    }
  }
  delete members;
  members = tmp;
  Phenotype * tmpp = ofirst;
  if(ofirst)
    first = findBest(ofirst);

  delete tmpp;
}
Phenotype * Species::findCenter(Phenotype * ofirst)
{
  Phenotype * newFirst = NULL;
  double comp = RAND_MAX;
  for(unsigned int i=0;i<members->size();i++){
    if(comp>ofirst->getGenome()->compare(members->at(i)->getGenome())){
      comp = ofirst->getGenome()->compare(members->at(i)->getGenome());
      newFirst = members->at(i);
    }
  }
  return newFirst;
}
Phenotype * Species::findBest(Phenotype * ofirst)
{
  Phenotype * newFirst = NULL;
  double fit = 0;
  for(unsigned int i=0;i<members->size();i++){
    if(fit<members->at(i)->getFitness()){
      fit = members->at(i)->getFitness();
      newFirst = members->at(i);
    }
  }
  return newFirst;
}
void Population::postepoch()
{
  //delete everyone for the old generation.
  if(debug)
    cerr << "postepoch start: curgen:"<<curgen<<" members size: " << members->size() << " species size : " << species->size() << endl;
  for(unsigned int i=0;i<members->size();i++){
    members->at(i)->getSpecies()->removePhenotype(members->at(i));
    delete members->at(i);
  }
  delete members;
  members = new Phenotypes();

  //removing empty species, adding the new phenotypes from
  //surviving species.
  speciesVector * newspec = new speciesVector();
  for(unsigned int i=0;i<species->size();i++){
    if(species->at(i)->getMembers()->size()==0){
      delete species->at(i);
    }else
      newspec->push_back(species->at(i));
  }

  delete species;
  species = newspec;
  int t = 0;
  for(unsigned int i2=0;i2<species->size();i2++){
    Phenotypes * smembers = species->at(i2)->getMembers();
    for(unsigned int i=0;i<smembers->size();i++){
      t++;
      members->push_back(smembers->at(i));
    }
  }
  //pruning innovations to given size..
  in->prune();
  bool foundbest = false;
  for(unsigned int i=0;i<species->size();i++)
    if(bestspecnum==species->at(i)->getID())
      foundbest = true;

  if(!foundbest)
    cerr << "best species(" << bestspecnum << ")"<< " died.." << endl;
  if(debug)
    cerr << "curgen:"<<curgen<<" members size: " << members->size() << " species size : " << species->size() << endl;
  curgen++;
  sortmembers();

  bestmember = members->at(0);
  if(debug)
    cerr << "postepoch stop: curgen:"<<curgen<<" members size: " << members->size() << " species size : " << species->size() << endl;
}
void Population::populationCleanup()
{
  setvars();
  resetVars();
  deletespecies();
  for(unsigned int i=0;i<members->size();i++)
    delete members->at(i);
  delete members;
  deletespecies();
  setvars();
  resetVars();
}
Population::~Population()
{
  populationCleanup();
  delete in;
}
Species::~Species()
{
  delete members;
  delete children;
}
void Species::transferChildren()
{
  for(unsigned int i=0;i<children->size();i++)
    members->push_back(children->at(i));
  delete children;
  children = new Phenotypes();

}
static Phenotypes * luckyones(Phenotypes * p){
  Phenotypes * ret = new Phenotypes();
  for(unsigned int i=0;i<p->size();i++){
    if(p->at(i)->getExpected()>0)
      ret->push_back(p->at(i));
  }
  return ret;
}
bool checkSpeciesforoutput(Phenotypes * p)
{
  for(unsigned int i=0;i<p->size();i++)
    if(!checkforoutput(p->at(i)->getGenome()->getNodes()))
      return false;
  return true;
}
void Species::reproduce()
{
  if(expectedoffspring<1&&members->at(0)->getPopulationChampClones()==0)
    return;
  unsigned int memberss = members->size()-1;
  Phenotypes * newgeneration = new Phenotypes();
  //do a straight clone of the specieschamp
  if(members->at(0)->getClones()==1){

    newgeneration->push_back(new Phenotype(members->at(0)->getGenome()->duplicate(p->getAndIncID())));
    cerr << "cloning bestmember: " << members->at(0)->getID() << " new id: " << newgeneration->at(0)->getID() 
	 << " compare: " << members->at(0)->getGenome()->compare(newgeneration->at(0)->getGenome())
	 << " of: " << members->at(0)->getOrigFitness() <<  " new fitness: " << p->fe->f(newgeneration->at(0)) << endl;
    members->at(0)->decClones();
  }

  Genome * newgenome = NULL;
  double mutateaddlinkprob = set->getValue("mutate_link_weights_prob");
  bool coldg = false;
  while(members->at(0)->getPopulationChampClones()>0){
    int tf = members->at(0)->getGenome()->getGenes()->at(0)->getFrom()->getID();
    newgenome = members->at(0)->getGenome()->duplicate(p->getAndIncID());
    if(members->at(0)->getPopulationChampClones()>1){
      if((randdouble()<0.8)||
	 (mutateaddlinkprob==0.0)){
	coldg = (set->getValue("coldgaussian_weight_mutate") == 0) ? false : true;
	newgenome->mutatew(coldg);   
      }else if(set->getValue("mutate_add_link_prob")!=0){
	newgenome->addLink((int)set->getValue("newlink_tries"));
      }
    }
    int af = newgenome->getGenes()->at(0)->getFrom()->getID();
    if(tf!=af){
      cerr << "af og if ikke lik i popchampclone\n";
    }
    newgeneration->push_back(new Phenotype(newgenome));
    members->at(0)->decPopulationChampClones();
  }

  Phenotypes * luckymembers = luckyones(members);
  Phenotype * p1 = NULL;
  Phenotype * p2 = NULL;
  int p2n = 0;
  speciesVector * species = NULL;
  //  Species * cspecies = NULL;
  double sr = 0; int sn = 0;
  Phenotype * tmpp = NULL;
  int ip = 0;
//   if(luckymembers->size()==0&&p->getSpecies()->size()==1)
//     cerr << "gen: " << p->getGeneration() << " spec size er 1 id er: "<<id
// 	 <<" expected offspring: "<<expectedoffspring
// 	 <<" og member0 popchamps: "<<members->at(0)->getPopulationChampClones()
// 	 <<" member 0 eoffpsring " <<members->at(0)->getExpected()
// 	 <<" member 0 id: " <<members->at(0)->getID()
// 	 <<" member 0 ofitness: " <<members->at(0)->getOrigFitness()
// 	 <<"luckymembers size er null og age er:" << age << endl;
//commented this out as this has nothing to say as the age is always high
  while(luckymembers->size()!=0){
    ip = (luckymembers->size()==1) ? 0 : randint(0,luckymembers->size()-1);
    p1 = luckymembers->at(ip);

    newgenome = NULL;
    //should just mutate?
    if(randdouble()<set->getValue("mutate_only_prob")){
      newgenome = p1->getGenome()->duplicate(p->getAndIncID());
      mutate(newgenome,set,p->getInnovations()->curnodenum);
    }
    //nope, lets mate'em
    else{
      if(randdouble()>set->getValue("interspecies_mate_rate")
	 ||p->getSpecies()->size()==1){
	//TODO:
	//ARGH, should i pick from whole species or just those that
	//have been appointed offspring??
	if(memberss!=0){
	  p2n = randint(0,memberss);
	}else{
	  p2n = 0;
	}
	p2 = members->at(p2n);
	
      }else{
	species = copyAndSort(p->getSpecies());
	do{
	  sr = box_muller(0.5,0.2);//TODO:good gauss??
	  if(randdouble()<0.56)
	    sr /= 4.0; //_tend_ to go for the top species(top 1/4th)
	  if(sr>1.0) sr = 1.00;
	  if(sr<0.0) sr = 0;
	  sn = (int) floor((sr * (species->size()-1.0)) + 0.5);

	}while(species->at(sn)->getAge()==0);//check that the species picked is was not generated in this reproduction round
	p2 = species->at(sn)->getChamp();
	delete species;//delete the sorted container..
      }
      //ok now we have parent #2 .. lets matdouble e.
      if(randdouble()<set->getValue("mate_multipoint_prob")){
	newgenome = p1->getGenome()->crossover(p2->getGenome(),false,p1->getFitness(),p2->getFitness(),p->getAndIncID(),false);
      }else if(randdouble()<set->getValue("mate_multipoint_avg_prob")){
	newgenome = p1->getGenome()->crossover(p2->getGenome(),true,p1->getFitness(),p2->getFitness(),p->getAndIncID(),false);
      }else{
	newgenome = p1->getGenome()->crossover(p2->getGenome(),false,p1->getFitness(),p2->getFitness(),p->getAndIncID(),true);
      }
      if(randdouble()>set->getValue("mate_only_prob")||
	 p1->getGenome()->getID() == p2->getGenome()->getID() ||
	 p1->getGenome()->compare(p2->getGenome())==0.0){

	mutate(newgenome,set,p->getInnovations()->curnodenum);
      }
    }
    //add to appropriate species..
//     int af = newgenome->getGenes()->at(0)->getFrom()->getID();
//     if(tf!=af){
//       cerr << "tf("<< tf <<"->"<<p1->getGenome()->getGenes()->at(0)->getTo()->getID()
// 	   << "("<<p1->getGenome()->getGenes()->at(0)->getMarker()<<") (p2: " 
// 	   << p2->getGenome()->getGenes()->at(0)->getFrom()->getID() 
// 	   <<"->"<<p2->getGenome()->getGenes()->at(0)->getTo()->getID() 
// 	   << "("<<p2->getGenome()->getGenes()->at(0)->getMarker()<<") id: "<< p2->getGenome()->getID() <<" )"
// 	   <<" id: "<< p1->getGenome()->getID()
// 	   <<"  2.: "<< p1->getGenome()->getGenes()->at(1)->getFrom()->getID() 
// 	   <<"->"<<p1->getGenome()->getGenes()->at(1)->getTo()->getID()
// 	   <<" ) ikke lik af("<< af <<"->"<<newgenome->getGenes()->at(0)->getTo()->getID()
// 	   <<" id: "<< newgenome->getID()
// 	   <<" 2.: "<< newgenome->getGenes()->at(1)->getFrom()->getID() 
// 	   <<"->"<<newgenome->getGenes()->at(1)->getTo()->getID()
// 	   <<" ) i good old repro..type:"<< type <<"\n";
//       cerr << "p1:\n" << p1->getGenome();
//       cerr << "p2:\n" << p1->getGenome();
//      exit(1);
//    }
    //remove the expected offspring from individual..

    tmpp = new Phenotype(newgenome);
    if(p->getDebug()==2)
      cerr << "adding new phenotype at addr: " << tmpp << endl;
    newgeneration->push_back(tmpp);
    p1->decEOffspring();
    delete luckymembers;
    luckymembers = luckyones(members);
  }
  delete luckymembers;
  if(p->getDebug()==1)
    cerr << "newgensize: " << newgeneration->size() << endl;
  for(unsigned int i=0;i<newgeneration->size();i++){
    addToSpeciesCollection(p->getSpecies(),newgeneration->at(i),p,set,(p->getDebug()>0) ? true : false);

  }
  delete newgeneration;
}
void Species::removePhenotype(Phenotype * p)//TODO:maybe rewrite as for?
{
  Phenotypes::iterator it = members->begin();
  while(it!=members->end()&&(*it)->getID()!=p->getID())
    ++it;
  if(it!=members->end())
    members->erase(it);
  if(p==first)
    first = findCenter(p);//because there is no fitness set when this method is called
}
void Population::resetGenesis()
{
  int s = members->size();
  cerr << "memberssize: " << members->size() << endl;
  populationCleanup();
  resetVars();
  genesis(originalseed,s,originalinitialelitism);
}
void Population::genesis(Genome * g, int isize, int initialelitism)
{
  size = isize;
  if(spectarget!=0)
    spectarget = size/spectarget; //calc the number of species to aim
				//for from a better metric, the target
				//species size..
  else
    spectarget = (int)set->getValue("species_target");
  Genome * curg = NULL;
  g->setTfs(tfs);
  originalseed = g;
  originalinitialelitism = initialelitism;
  g->setSettings(set);
  g->setInnovations(in);
  int i = 1;
  Genome * tmp = NULL;
  if(initialelitism!=0){
    for(;i<initialelitism;i++){
      tmp = g->duplicate(getAndIncID());
      members->push_back(new Phenotype(tmp));
    }
  }
  for(;i<=size;i++){
    curg = g->duplicate(getAndIncID());
    curg->mutatew(false);
    members->push_back(new Phenotype(curg));
  }
  in->setNodeNum(g->getLastNodeID());
  in->setInitNum(g->getLastInnov());
  speciate();
}
void Population::resetSpawn(){
  int tsize = members->size();
  populationCleanup();
  randomSpawn(tsize,inodes,onodes,hnodes,hnodes,lprob,rprob);
}
void Population::randomSpawn(int pops, int i, int o, int n,int nmax, double linkprob, 
			     double r)
{
  inodes = i; onodes = o; hnodes = n; lprob = linkprob; rprob = r;
  originalseed = NULL;
  size = pops;
  if(spectarget!=0)
    spectarget = size/spectarget; //calc the number of species to aim
				//for from a better metric, the target
				//species size..
  else
    spectarget = (int)set->getValue("species_target");

  int cid = 1;
  for(int ic=0;ic<pops;ic++){
    members->push_back(new Phenotype(new Genome(cid++,i,o,n,nmax,r,linkprob,set,in,tfs)));
  }
  speciate();
  curgenome = cid;
}
void Population::deletespecies()
{ 
  if(!species)
    return;
  for(unsigned int i=0;i<species->size();i++)
    delete species->at(i);
  delete species;
  species = NULL;
}
void Population::speciate()
{
  speciesVector::iterator it;
  if(species)
    deletespecies();
  species = new speciesVector();
  species->push_back(new Species(++curspec,set,this));
  species->at(0)->addPhenotype(members->at(0));

  for(int i=members->size()-1;i>=1;--i)
    addToSpeciesCollection(species,members->at(i),this,set,false);

  for(unsigned int i=0;i<species->size();i++)
    species->at(i)->transferChildren();
  //TODO: hmm, pop or inv have control over specid??
}
void Species::adjustFitness(NEATsettings * set)
{
  int par=0;
  int agedebt = (age-lastimprov+1)-(int)set->getValue("dropoff_age");
  double age_significance = set->getValue("age_significance");
  double survival_threshold = set->getValue("survival_thresh");
  if(agedebt==0) // what is this? seems to be another unexplained
		 // heuristic from ken :)
    agedebt = 1;
  //go through the members, and adjust the fitness..
  Phenotypes::iterator it;
  Phenotype * p = NULL;
  for(it=members->begin();it!=members->end();it++){
    p = (*it);
    if(agedebt>=1){
      p->augmentFitness(0.0001);
    }
    if(age<=10) p->augmentFitness(age_significance);
    if(p->getFitness()<=0){
      p->setFitness(0.0001);
    }
    p->augmentFitness((1.0/(double)members->size()));
  }
  fsort();
  champ = members->at(0); champ->setSpeciesChamp();
  double topdogf = champ->getFitness();
  if(topdogf>historicaltopf){
    lastimprov = age;
    historicaltopf = topdogf;
  }
  par = (int) floor((survival_threshold*((double)members->size()))+1.0);

  for(unsigned int i=par;i<members->size();i++) { //should it be par-1?
    members->at(i)->markDead();
  }

}
void Species::updateavgf()
{
  sumf = 0;
  unsigned int s = members->size();
  for(unsigned int i=0;i<s;i++){
    sumf += members->at(i)->getOrigFitness();
  }
  avgf = sumf/(double)s;
}
void Species::updatesumf(bool dead)
{
  sumf = 0;
  unsigned int s = members->size();
  for(unsigned int i=0;i<s;i++)
    if(dead||!members->at(i)->isDead())
      sumf += members->at(i)->getFitness();
}
void Species::updatemaxminf()
{
  double tmp=0;
  double tmp2 = (historicaltopf == 0) ? 1000 : historicaltopf;
  for(unsigned int i=0;i<members->size();i++){
    if(tmp<members->at(i)->getOrigFitness())
      tmp = members->at(i)->getOrigFitness();
    if(tmp2>members->at(i)->getOrigFitness())
      tmp2 = members->at(i)->getOrigFitness();
  }
  maxf = tmp;
  minf = tmp2;
}
double Species::countoffspring(double skim)
{
  int membersoffspring = 0;
  double skimfrommember = 0;
  expectedoffspring = 0;
  double cur = 0;int tmp=0;
  for(unsigned int i=0;i<members->size();i++){
    cur = members->at(i)->getExpected();
    membersoffspring = (int) floor(cur);
    skimfrommember = fmod(cur,1.0);
    expectedoffspring += membersoffspring;
    skim += skimfrommember;
    if(skim>1.0){
      tmp = (int)floor(skim);
      expectedoffspring +=tmp;
      skim -= tmp;
    }
  }
  return skim;
}
Phenotype * Population::getByID(int id)
{
  for(unsigned int i=0;i<members->size();i++)
    if(members->at(i)->getID()==id)
      return members->at(i);
  return NULL;
}
void Species::fsort()//sorts the species on fitness.
{
  sort(members->begin(),members->end(),phenocomp);
}
void Population::sortspecies()
{
  sort(species->begin(),species->end(),speciescomp);
}
void Population::sortmembers()
{
  sort(members->begin(),members->end(),phenocomp);
}
void Phenotype::setSpecies(Species * ispec)
{
  spec=ispec;
}

double Population::calcAvgFitness()
{
  double sum=0;
  for(unsigned int i=0;i<species->size();i++)
    sum += species->at(i)->getAvgFitness();
  return sum/(double)species->size();
}
