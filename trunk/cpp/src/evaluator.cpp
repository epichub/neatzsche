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

#include "evaluator.h"
double DatasetEvaluator::f(Phenotype * f)
{
  double esum = 0;
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    v = f->react(*ds->getTrain(i));
    f->cleanNet();
    esum += sqrt(pow(ds->getClass(true,i)-(v.at(0)),2));
  }
  double r = pow(ds->getTrainings()-esum,2.0);
  f->setFitness(r);
  //   cerr << "pid: " << f->getID() << " new fitness: " << pow(ds->getTrainings()-esum,2.0) 
  //       << " getfitness: " << f->getFitness() << endl;
  if(pow(ds->getTrainings()-esum,2.0)==0)
    cerr << "pow(ds->getTrainings()-esum,2.0) was zero!!"<<endl;  
  if(pow(ds->getTrainings()-esum,2.0)>20){
    cerr << "esum: " << esum << endl;
    cerr << "v0: " << v.at(0) << endl;
    // cerr << "phenotype outputftype: " << f->outputFType() << endl;
    cerr << "pow(ds->getTrainings()-esum,2.0) was over 20!!"<<endl;  
    cerr << "genome: " << f->getGenome() << endl;
    cerr << "state: " << printvector(f->getState()) << endl;
    f->cleanNet();
    cerr << "state: " << printvector(f->getState()) << endl;
  }
  return r;
}
void DatasetEvaluator::runTest(Phenotype * f)
{
  //f->genesis();
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    v = f->react(*ds->getTrain(i));
    f->cleanNet();
    cerr << "input: " << printvector(*ds->getTrain(i))
	 << " output: " << v.at(0) 
	 << " should have been: " << ds->getClass(true,i) << endl;
  }
  //  f->cleanup();
}
bool DatasetEvaluator::xorDone(Phenotype * f)
{
  //  f->genesis();
  vector<double> v;
  int c=0;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
    v = f->react(*ds->getTrain(i));
    if(ds->getClass(true,i) == 0.9 && v.at(0)>0.5) c++; 
    if(ds->getClass(true,i) == 0.1 && v.at(0)<0.5) c++;
  }
  //  f->cleanup();
  return c==4;
}
void GoEvaluator::nextGen()
{

  gen++;
  if(gen>=pg){
    st = 1;
  }else
    st=0;

}
double GoEvaluator::f(Phenotype * f)
{
  bool secondnull = false;
  if(st==1&&last==NULL){
    last = f;
    return 0;
  }else if(st==1&&last!=NULL&&f==NULL){
    secondnull = true;
  }

  g->reset();

  if(st==0||(st==1&&f!=NULL))
    f->cleanNet();
  if(st==1&&last!=NULL)
    last->cleanNet();
  netinp = vector<double>();
  fsum = 0;
  ssum = 0;
  moves = 0;	      

  if(st==1&&!secondnull){ players[0] = f; players[1] = last;}
  if(secondnull) { players[0] = last; players[1] = NULL;}
  else { players[0] = f; players[1] = NULL;}
  c = players[0];
  count=0; first = true;
  sense = g->getSensoryInput(first);

  while(!g->done()){
    if(c){
      while(!g->doThis(first,c->react(sense))){
	sense = g->getSensoryInput(first);
      }
      g->resetRound(c);
    }else{
      g->gw_genmove(first);
    }

    if(moves<g->getMoves()){
      moves=g->getMoves();
      fsum += g->score(true);
      ssum += g->score(false);
    }
    first = !first;
    c = players[++count%2];
  }
  if(moves==0)
    moves = 1;
  updateStats();
  ftmp = ((2.0*fsum)+g->score(true))/((2*moves)+1);
  stmp = ((2.0*ssum)+g->score(false))/((2*moves)+1);

  if(g->puts==0)
    ftmp -= 0.1;

  if(ftmp < fmin)
    fmin = ftmp;
  if(ftmp > fmax)
    fmax = ftmp;

  if(ftmp<=0)
    ftmp = 0.0001;
  if(stmp<=0)
    stmp = 0.0001;
  if(!secondnull)
    f->setFitness(ftmp);
  if(st==1)
    last->setFitness(stmp);

  if(st==1 && last!=f){
    last = NULL;
  }

  return ftmp;
}
double GoEvaluator::debugeval(Phenotype * f)
{
  bool secondnull = false;
  if(st==1&&last==NULL){
    last = f;
    return 0;
  }else if(st==1&&last!=NULL&&f==NULL){
    secondnull = true;
  }

  g->reset();
  if(st==0||(st==1&&f!=NULL))
    f->cleanNet();
  if(st==1&&last!=NULL)
    last->cleanNet();

  double tsum = 0;
  vector<double> sense;
  vector<double> reaction;
  Phenotype ** players = new Phenotype * [2];
  if(st==1&&!secondnull){ players[0] = f; players[1] = last;}
  if(secondnull) { players[0] = last; players[1] = NULL;}
  else { players[0] = f; players[1] = NULL;}
  Phenotype * c = players[0];
  int count=0, moves=0; bool first = true;
  sense = g->getSensoryInput(first);
  reaction = c->react(sense);
  g->fakeThis(first,reaction);
  double hmm=0;
  while(!g->done()){
//     rounds++;
    if(c){

      while(!g->doThis(first,reaction)){
	cerr << "sense: " << printvector(sense);
	if(hmm!=sumvector(reaction))
	  cerr << "!!! whoot whoot reaction changed: " << hmm/sumvector(reaction) << endl;
	cerr << "reaction: " << printvector(reaction);
	sense = g->getSensoryInput(first);
	hmm = sumvector(reaction);
	reaction = c->react(sense);
	g->fakeThis(first,reaction);
      }
      g->resetRound(c);
    }else{
      g->gw_genmove(first);
    }
    if(moves<g->getMoves()){
      cerr << g->getLocalBoardAscii(); 
      moves=g->getMoves();
      tsum += g->score();
      cerr << "tsum: " << tsum<<endl;
    }
    first = !first;
    c = players[++count%2];


  }
  if(moves==0)
    moves = 1;
  updateStats();
  cerr << "tsum before ftmp: " << tsum<<endl;
  double finalscore = g->score();
  double ftmp = 100-(((tsum*2.0)/(double)moves)+finalscore);
  double stmp = (((tsum*2.0)/(double)moves)+finalscore);
  cerr << "ftmp: " << ftmp << endl;
  if(ftmp<=0)
    ftmp = 0.0001;
  if(stmp<=0)
    stmp = 0.0001;
  if(!secondnull)
    f->setFitness(ftmp);
  if(st==1)
    last->setFitness(stmp);
  delete[] players;
  if(st==1 && last!=f){
    last = NULL;
  }
  cerr << "fmax: "<< fmax << " fmin: " << fmin << endl;
  return ftmp;
}
string GoEvaluator::getFinishedBoard(Phenotype * p)
{

  int ost = st;
  st = 0;
  f(p);
  string r = g->getLocalBoardAscii();
  st = ost;
  return r;
}
bool comp(vector<double> v)
{
  if(v.size()!=sensecomp.size())
    return false;
  for(unsigned int i=0;i<v.size();i++)
    if(v.at(i)!=sensecomp.at(i))
      return false;
  return true;
}
double EasyGoEvaluator::f(Phenotype * f)
{
  //g->simplereset();
  f->cleanNet();
  g->reset();
  //g->justmoved = false; g->justput = false; g->secondput = false;
  //  g->currentplayerid = f->getID();
  //bool putbeforemove = false;
  vector<double> sense;
  sense = g->getSensoryInput(true);
  int tryc=0;
  int it = (int)s->getValue("easygoiterations");
  int m = (int)s->getValue("easygomode");
  double s=0;
  while(tryc<it){
    if(m==4){
      g->gw_genmove(false);
      s += g->nexttonew();
    }
    while(!g->doThis(true,f->react(sense))){
      sense = g->getSensoryInput(true);
    }
    g->resetRound(f);
    tryc++;
  }

  //   if((double)g->easyCount()>=2)
  //     cerr << "ID: "<<f->getID()<<" over 1 i easycount("
  // 	 <<(double)g->easyCount()<<") outputter brettet:" << endl
  // 	 << g->getLocalBoardAscii();
  updateStats();
//   cerr << "goset sin size: " << s->getValue("size") << endl;
  if(m==4){
    f->setFitness(1.0+s);
    return 1.0+s;
  }if(m==2){
     f->setFitness(1.0+(double)g->straightLineFitness());
     return (1.0+(double)g->straightLineFitness());
  }else if(m==1){
     f->setFitness(1.0+g->puts);
     return (1.0+g->puts);
  }else if(m==3){
     f->setFitness(1.0+g->crockedLineFitness());
     return (1.0+g->crockedLineFitness());
  }else{
    f->setFitness(1.0);
    return 1.0;
  }
  
//   return 1.0;
}
string EasyGoEvaluator::show(Phenotype * p)
{
  stringstream sRet;
  double v = EasyGoEvaluator::f(p);
  string r = g->getLocalBoardAscii();
  sRet  << r; sRet << "\nfitness: " << v << endl;
  return sRet.str();
}
void GoEvaluator::interact(Phenotype * f)
{
  g->reset();
  f->cleanNet();
  vector<double> sense;
  sense = g->getSensoryInput(true);
  string sCMD;
  char c; int i=0,j=0;double score = 0;
  while(!g->done()){
      while(!g->doThis(true,f->react(sense))){
	sense = g->getSensoryInput(true);
      }
      g->updateFromGnuGo();
      cerr << g->getLocalBoardAscii();
      cerr << "input coord, e.g. \"C4\", q to quit: ";
      cin >> sCMD;
      if(sCMD=="q")
	break;
      c = sCMD[0];
      j = ((int)c)-65;
      i = atoi(sCMD.substr(1,sCMD.length()-1).c_str());
      i = g->bsize-i;
      g->mput(i,j,gg::WHITE);
      g->updateFromGnuGo();
      cerr << g->getLocalBoardAscii();
      score = g->score();
      cerr << "score: w: " << score 
	   << " b(100-w): " << (100-score) << endl;
  }
  
}
string GoEvaluator::show(Phenotype * f)
{
  stringstream ss;
  bool secondnull = false;
  if(st==1&&last==NULL){
    last = f;
    return 0;
  }else if(st==1&&last!=NULL&&f==NULL){
    secondnull = true;
  }

  g->reset();

  if(st==0||(st==1&&f!=NULL))
    f->cleanNet();
  if(st==1&&last!=NULL)
    last->cleanNet();
  netinp = vector<double>();
  fsum = 0;
  ssum = 0;
  moves = 0;	      

  if(st==1&&!secondnull){ players[0] = f; players[1] = last;}
  if(secondnull) { players[0] = last; players[1] = NULL;}
  else { players[0] = f; players[1] = NULL;}
  c = players[0];
  count=0; first = true;
  sense = g->getSensoryInput(first);

  while(!g->done()){
    if(c){
      while(!g->doThis(first,c->react(sense))){
	sense = g->getSensoryInput(first);
      }
      g->resetRound(c);
    }else{
      g->gw_genmove(first);
    }

    if(moves<g->getMoves()){
      moves=g->getMoves();
      fsum += g->score(true);
      ssum += g->score(false);
      ss << g->getLocalBoardAscii();
    }
    first = !first;
    c = players[++count%2];
  }
  if(moves==0)
    moves = 1;
  updateStats();
  ftmp = ((2.0*fsum)+g->score(true))/((2*moves)+1);
  stmp = ((2.0*ssum)+g->score(false))/((2*moves)+1);

  if(g->puts==0)
    ftmp -= 0.1;

  if(ftmp < fmin)
    fmin = ftmp;
  if(ftmp > fmax)
    fmax = ftmp;

  if(ftmp<=0)
    ftmp = 0.0001;
  if(stmp<=0)
    stmp = 0.0001;
  if(!secondnull)
    f->setFitness(ftmp);
  if(st==1)
    last->setFitness(stmp);

  if(st==1 && last!=f){
    last = NULL;
  }

  return ss.str();
}
