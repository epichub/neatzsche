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
#include <iomanip>
#include "image.h"

double LightsimEvaluator::f(Phenotype * f)
{
  /*
  unsigned int ** twodmap;
  double tmpstrength=0;
  int tmpwinner=0;
  vector <double> tmpin;
  vector <double> tmpout;
  twodmap=new unsigned int*[xmax];
  for(unsigned int i=0;i<xmax;i++) {
    twodmap[i]=new unsigned int[ymax];
    for(unsigned int j=0;j<ymax;j++) {
      tmpin.push_back(i);
      tmpin.push_back(j);
      tmpout=f->react(tmpin);
      tmpstrength=0;
      tmpwinner=0;
      for(unsigned int k=0;k<tmpout.size();k++){
	if(tmpout.at(k)>tmpstrength&&tmpout.at(k)>0.3) {
	  tmpwinner=k+2;
	  tmpstrength=tmpout.at(k);
	}
      }
      tmpin.clear();
      //cout << "winner of "<<i<<","<<j<<" is "<<tmpwinner<<"\n";
      twodmap[i][j]=tmpwinner;
    }
    //      cout <<"done with "<<i<<"\n";
  }
  //    cout << "one phenotype done!\n";

  for(unsigned int i=0;i<ymax;i+=((int)(ymax/lsnum))) {
    twodmap[0][i]=1;
    //    cout << "creating a new LS at 0,"<<i<<"\n";
  }

  Lightsim2D *ls2d=new Lightsim2D(0.5,twodmap,xmax,ymax);
  */

  //  time_t t1=time(NULL);
  //  time_t t2=time(NULL);

  /*
  for(unsigned int i=0;i<xmax;i++) {
    for(unsigned int j=0;j<ymax;j++) {
      //free(twodmap[i][j]);
    }
    delete[](twodmap[i]);
  }
  delete[](twodmap);
  */

  f->cleanNet();

  ls2d=new Lightsim2D(cellsize,f,xmax,ymax,lsnum,ls_distance);

  ls2d->createVectors();

  int clo=clock();
  ls2d->pruneBlockedVectors();
  int clo2=clock();


  f->setFitness(LightsimEvaluator::f(ls2d));

  delete(ls2d);

  return f->getFitness();

}

double LightsimEvaluator::f(Lightsim2D *ls2d) {

  double fitness=0.00001;


  if(((int)settings->getValue("fitness_mode")) == 0) {
    //TODO: Need tom implement prec and recall correctly!
    double precision=1;
    double recall=1;
    double fMeasure=2*(precision*recall)/(precision+recall);
    fitness=fMeasure;
  }
  else if(((int)settings->getValue("fitness_mode")) == 1) {

    unsigned int lsNum=ls2d->getLightsources()->size();
    unsigned int lscNum=ls2d->getLSCs()->size();
    //cerr <<lsNum <<" "<<lscNum<<" ";
    //Big problem here!
    if(lsNum != 0 && lscNum != 0 && (lsNum/2)<=lscNum) {
      double e=0;
      double numerator=0;
      double denominator=0;
      double LscToLsRatio=lscNum/lsNum;
      //double LsToLscRatio=lsNum/lscNum;
      //LsToLscRatio = (LsToLscRatio != 0) ? LsToLscRatio : 1;
      unsigned int centerX=ls_distance+(xmax/2);
      unsigned int centerY=ymax/2;
      unsigned int hOpt=floor(LscToLsRatio+0.5); //The Ratio rounded to closest. Can be 0...
      unsigned int tmpNum=lscNum-hOpt;
      unsigned int eMax=hOpt < tmpNum ? tmpNum : hOpt; //Find the biggest error,
      unsigned int cellNum=ls2d->getLSCs()->size()+ls2d->getOpaquecells()->size();
      double avgLengthFromCenter=0;
      double maxLengthFromCenter=sqrt(pow(xmax-(centerX-ls_distance),2)+pow(ymax-centerY,2)); 

      //cout <<"hOpt: "<< hOpt << " cellNum: " << cellNum <<" emax: "<<eMax<< " LscToLsRatio: "<<LscToLsRatio<< " lsnum: "<< lsnum<<" ls_dist: "<<ls_distance<<" xmax: "<<xmax<<" ymax: "<<ymax<<endl;

      double favorLessNum=1-((double)cellNum/((xmax*ymax)*1.5));
      if(favorLessNum>1||favorLessNum<0) { cerr <<"out of bounds favorLessNum: "<<favorLessNum; ls2d->print(); exit(1); }
      //cout << "favorlessnum: 1-"<<cellNum<<"/("<<xmax*ymax<<"-"<<ls2d->getLightsources()->size()<<")*2"<<" = "<< favorLessNum<<endl;

      //cout <<"max error is: "<<eMax<<endl;
      double e2;
      for(unsigned int i=0;i<lsNum;i++) {
	if(ls2d->getLightsources()->at(i)->getCellSize()>0) {
	  //cout << "hopt: "<<hOpt<<" hits: "<<ls2d->getLightsources()->at(i)->getNumHits()<<endl;
	  e2=0;
	  for(unsigned int j=0;j<ls2d->getLightsources()->at(i)->getCellSize();j++) {
	    //e2+=(1/(log(10*ls2d->getLightsources()->at(i)->getCell(j)->getNumHits())*(LscToLsRatio)+1.5));
	    e2+=(1/(ls2d->getLightsources()->at(i)->getCell(j)->getNumHits()));
	  }
	  e+=(1-(fabs(hOpt-(double)ls2d->getLightsources()->at(i)->getCellSize())/eMax))
	    *(e2/ls2d->getLightsources()->at(i)->getCellSize());
	}
	else { e+=0; }
      }
      numerator=(e/((double)lsNum));
      //cout << numerator;
      if(numerator>1||numerator < 0) { cerr << "out of bounds num: "<<numerator<<" e2: " << e2 << " e: " <<  e << " hOpt: "<< hOpt << " cellNum: " << cellNum <<" emax: "<<eMax<< " LscToLsRatio: "<<LscToLsRatio<< " lsnum: "<< lsnum<<" xmax: "<<xmax<<" ymax: "<<ymax<<endl; exit(1); }
      
      for(unsigned int i=0;i<ls2d->getLSCs()->size();i++) {
	if(ls2d->getLSCs()->at(i)->getNumHits()>0) {
	  avgLengthFromCenter+=sqrt(pow(ls2d->getLSCs()->at(i)->getX()-(double)centerX,2)+pow(ls2d->getLSCs()->at(i)->getY()-(double)centerY,2));
	  denominator+=(1/ls2d->getLSCs()->at(i)->getNumHits());
	}
      }
      denominator=denominator/(double)lscNum;
      if(denominator>1||denominator<0) { cerr << "out of bounds denom"<<denominator; exit(1); }

      for(unsigned int i=0;i<ls2d->getOpaquecells()->size();i++) {
	avgLengthFromCenter+=sqrt(pow(ls2d->getOpaquecells()->at(i)->getX()-(double)centerX,2)+pow(ls2d->getOpaquecells()->at(i)->getY()-(double)centerY,2));
      }
      
      //cout <<"maxlfc: "<<maxLengthFromCenter<<endl;
      //cout <<"totallfc: "<<avgLengthFromCenter<<endl;
      avgLengthFromCenter=avgLengthFromCenter/(ls2d->getLSCs()->size()+ls2d->getOpaquecells()->size());
      //cout <<"avglfc: "<<avgLengthFromCenter<<endl;
      //cout << avgLengthFromCenter<< " " << maxLengthFromCenter << " ";
      double favorCloserNum=1-(pow(avgLengthFromCenter,2)/pow(maxLengthFromCenter,2));
      if(favorCloserNum>1||favorCloserNum<0) { cerr << "out of bounds favorCloserNum"<<favorCloserNum; exit(1); }

      //cout <<"favorCloserNum: "<<favorCloserNum<<endl;

      fitness+=numerator*denominator;
      //      cout << "favorLessNum: "<<favorLessNum<<" favorCloserNum: "<<favorCloserNum<<endl;
      fitness=fitness*favorLessNum*favorCloserNum;
    }

  }
  else if(((int)settings->getValue("fitness_mode")) == 2) {
    fitness=(ls2d->getLightvectors()->size());
  }
  else {
    cerr << "Error: Wrong fitness mode";
    exit(1);
  }
  //cout << "Fitness is: "<<setprecision(4)<<fitness<<"   \t";
  //cout <<"Pruningtime: "<<setprecision(3)<<(clo2-clo)/(double)CLOCKS_PER_SEC<<" secs --> ";
  //  cout <<"Pruningtime: "<<difftime(t2,t1)<<" secs --> ";
  //ls2d->print();

  //cout << "fitness: "<<fitness<<" ";

  return fitness;

}

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
//   if(pow(ds->getTrainings()-esum,2.0)==0)
//     cerr << "pow(ds->getTrainings()-esum,2.0) was zero!!"<<endl;  
//   if(pow(ds->getTrainings()-esum,2.0)>20){
//     cerr << "esum: " << esum << endl;
//     cerr << "v0: " << v.at(0) << endl;
//     // cerr << "phenotype outputftype: " << f->outputFType() << endl;
//     cerr << "pow(ds->getTrainings()-esum,2.0) was over 20!!"<<endl;  
//     cerr << "genome: " << f->getGenome() << endl;
//     cerr << "state: " << printvector(f->getState()) << endl;
//     f->cleanNet();
//     cerr << "state: " << printvector(f->getState()) << endl;
//   }
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
//   cerr << "before game puts: " << g->getPuts() << endl;
//   cerr << "f: " << f << endl;
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
//    int tmpputs=0;
  while(!g->done()){
//     tmpputs = g->getPuts();
    if(c){
      while(!g->doThis(first,c->react(sense))){
// 	if(g->shoulda&&tmpputs==g->getPuts())//should have put but didnt
// 	  exit(0);
	sense = g->getSensoryInput(first);
      }
      g->resetRound(c);
    }else{
      g->gw_genmove(first);
    }

    if(moves<g->getPuts()){
      moves=g->getPuts();
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

  if(g->getPuts()==0)
    ftmp -= 0.1;
  else
    ftmp += .15 * g->getPuts();

  if(ftmp < fmin)
    fmin = ftmp;
  if(ftmp > fmax)
    fmax = ftmp;
//   ftmp = 100-g->score();
  ftmp = g->score(true);

  if(g->getPuts()==0)
    ftmp -= 0.1;
  else
    ftmp += .15 * g->getPuts();

  if(ftmp<=0)
    ftmp = 0.0001;
  if(stmp<=0)
    stmp = 0.0001;
  if(!secondnull){
    
    f->setFitness(ftmp);
  }if(st==1){
//     cerr << "setting last("<< last->getID()<<") to stmp" << stmp << endl;
    last->setFitness(stmp);
  }

  if(st==1 && last!=f){
    last = NULL;
  }
  if(ftmp>0.5){
//     cerr << "fitness over 0.5: " << ftmp << endl;
//     cerr << "board:\n " << g->getLocalBoardAscii();
  }
//   }else
//     cerr << "<id: " << f->getID()  << " " << ftmp << "> " << flush;
  return ftmp;
}
double GoEvaluator::debugeval(Phenotype * f)
{
//   bool secondnull = false;
//   if(st==1&&last==NULL){
//     last = f;
//     return 0;
//   }else if(st==1&&last!=NULL&&f==NULL){
//     secondnull = true;
//   }

//   g->reset();
//   if(st==0||(st==1&&f!=NULL))
//     f->cleanNet();
//   if(st==1&&last!=NULL)
//     last->cleanNet();

//   double tsum = 0;
//   vector<double> sense;
//   vector<double> reaction;
//   Phenotype ** players = new Phenotype * [2];
//   if(st==1&&!secondnull){ players[0] = f; players[1] = last;}
//   if(secondnull) { players[0] = last; players[1] = NULL;}
//   else { players[0] = f; players[1] = NULL;}
//   Phenotype * c = players[0];
//   int count=0, moves=0; bool first = true;
//   sense = g->getSensoryInput(first);
//   reaction = c->react(sense);
//   g->fakeThis(first,reaction);
//   double hmm=0;
//   while(!g->done()){
// //     rounds++;
//     if(c){

//       while(!g->doThis(first,reaction)){
// 	cerr << "sense: " << printvector(sense);
// 	if(hmm!=sumvector(reaction))
// 	  cerr << "!!! whoot whoot reaction changed: " << hmm/sumvector(reaction) << endl;
// 	cerr << "reaction: " << printvector(reaction);
// 	sense = g->getSensoryInput(first);
// 	hmm = sumvector(reaction);
// 	reaction = c->react(sense);
// 	g->fakeThis(first,reaction);
//       }
//       g->resetRound(c);
//     }else{
//       g->gw_genmove(first);
//     }
//     if(moves<g->getMoves()){
//       cerr << g->getLocalBoardAscii(); 
//       moves=g->getMoves();
//       tsum += g->score();
//       cerr << "tsum: " << tsum<<endl;
//     }
//     first = !first;
//     c = players[++count%2];


//   }
//   if(moves==0)
//     moves = 1;
//   updateStats();
//   cerr << "tsum before ftmp: " << tsum<<endl;
//   double finalscore = g->score();
//   double ftmp = 100-(((tsum*2.0)/(double)moves)+finalscore);
//   double stmp = (((tsum*2.0)/(double)moves)+finalscore);
//   cerr << "ftmp: " << ftmp << endl;
//   if(ftmp<=0)
//     ftmp = 0.0001;
//   if(stmp<=0)
//     stmp = 0.0001;
//   if(!secondnull)
//     f->setFitness(ftmp);
//   if(st==1)
//     last->setFitness(stmp);
//   delete[] players;
//   if(st==1 && last!=f){
//     last = NULL;
//   }
//   cerr << "fmax: "<< fmax << " fmin: " << fmin << endl;
//   return ftmp;
  return 0;
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
    f->setFitness(1.0+g->getPuts());
    return (1.0+g->getPuts());
  }else if(m==3){
    f->setFitness(1.0+g->crockedLineFitness());
    return (1.0+g->crockedLineFitness());
  }else{
    f->setFitness(1.0);
    return 1.0;
  }
  
  return 1.0;
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

      ss << g->getLocalBoardAscii();
    }
    first = !first;
    c = players[++count%2];
  }
  if(moves==0)
    moves = 1;


  return ss.str();
}
PictureEvaluator::PictureEvaluator(std::string filename)
{
  double * img;
  sizes = new int [2];
  cout << "readimg: " << read_image(img,filename.c_str(),sizes) <<endl;
  cout<<"sizes[0]: " << sizes[0] << " sizes[1]:" << sizes[1] << endl;
  picoffset = (sizes[0]*sizes[1]);
  for(int i=0;i<picoffset;i++){
    picdata.push_back(img[i]);
  }
  write_image_coords ( "data/test.tiff" , img , sizes[0] , sizes[1] );

}
double PictureEvaluator::f(Phenotype *f)
{
  double wrong=0;
  vector<double> reaction;
  vector<double> inp;inp.push_back(0);inp.push_back(0);inp.push_back(0);
//   cout<<"inp size: " << inp.size() << endl;
  int xmax = sizes[0];
  int ymax = sizes[1];
  for(int x=0;x<xmax;x++){
    for(int y=0;y<ymax;y++){
      inp.at(0) = (double)x/(double)xmax;
      inp.at(1) = (double)y/(double)ymax;
      inp.at(2) = sqrt(pow(((double)x)-((double)xmax),2));
      reaction = f->react(inp);
      if(reaction.at(0) > 1.0) reaction.at(0) = .9999;
      else if(reaction.at(0) < 0) reaction.at(0) = 0;
      wrong += sqrt(pow(picdata.at((ymax*x)+y)-reaction.at(0),2));
    }
  }
  double fi = (double)(picoffset-wrong+1)/((double)picoffset);
  f->setFitness(fi);

  return fi;
}
void PictureEvaluator::runTest(Phenotype * f)
{
  double * oimg = (double*)calloc(sizes[0]*sizes[1],sizeof(double));
  vector<double> inp;inp.push_back(0);inp.push_back(0);// inp.push_back(0);
  int xmax = sizes[0];
  int ymax = sizes[1];
  for(int x=0;x<sizes[0];x++){
    for(int y=0;y<sizes[1];y++){
      inp.at(0) = (double)x/(double)sizes[0];
      inp.at(1) = (double)y/(double)sizes[1];
//       inp.at(2) = sqrt((x-(xmax/2))^2 + (y-(ymax/2))^2);
      oimg[(x*sizes[1])+y] = f->react(inp).at(0);
    }
  }
  write_image_coords ( "out.tiff" , oimg , sizes[0] , sizes[1] );
}
double PictureEvaluator::f2(Phenotype *f)
{
  int wrong=0;
  vector<double> reaction;
  for(int x=0;x<ROWS;x++){
    for(int y=0;y<COLS;y++){
      picdata.at(picoffset) = x;
      picdata.at(picoffset) = y;
      reaction = f->react(picdata);
      wrong += (reaction.at(0)==picdata.at((COLS*x)+y)) ? 0 : 1;
    }
  }
  double fi = (double)wrong/((double)COLS*ROWS);
  f->setFitness(fi);
  return fi;
}
double HyperNEAT::f(Phenotype * f)
{
  unsigned int mx,my,mx2,my2;
  int d = 0;
  vector<nodeVector*> * layers = new vector<nodeVector*>();
  vector<double> inp; 
  inp.push_back(0); inp.push_back(0); inp.push_back(0); inp.push_back(0);
  
  layers->push_back(new nodeVector());
  mx = subs->at(0)[0];
  my = subs->at(0)[0];
  int id = 0;

  for(unsigned int i=0;i<(mx*my);i++)
    layers->at(0)->push_back(new NeuralNode(tfs->getTA(),id++,NeuralNode::INPUT,0));
  NeuralNode * bias = new NeuralNode(tfs->getTA(),id++,NeuralNode::BIAS,0);
  layers->at(0)->push_back(bias);
  double w=0;
  for(unsigned int i=1;i<subs->size();i += 2){
    layers->push_back(new nodeVector());
    mx = subs->at(i-1)[0];
    my = subs->at(i-1)[0];
    mx2 = subs->at(i)[0];
    my2 = subs->at(i)[0];
    for(unsigned int i2=0;i2<(mx2*my2);i2++){//create the next layer
      layers->at(i)->push_back(new NeuralNode(tfs->getSigmoid(),id++,NeuralNode::HIDDEN,d));
      //make bias link??
      //new Link(false,bias,layers->at(i)->at(i2),1);
    }
    for(unsigned int x;x<mx;x++){
      for(unsigned int y;y<my;y++){
	for(unsigned int x2;x2<mx2;x2++){
	  for(unsigned int y2;y2<my2;y2++){
	    inp.at(0) = x; inp.at(1) = y; inp.at(2) = x2; inp.at(3) = y2;
	    //	    w = f->react(inp).at(i-1);
	    new Link(false,layers->at(i-1)->at((x*y)+y),layers->at(i-1)->at((x2*y2)+y2),f->react(inp).at(i-1));
	  }      	  
	}      
      }      
    }
    d++;
  }
  return 0;
  //run the damn thing on a task at hand, woopdedo (i'll let that be a task for my polymorphic children)
}
