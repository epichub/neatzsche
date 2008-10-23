#include "eval.h"
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
//   cout << "in evaluator.." << endl;
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
//   cerr << "sense size:" << sense.size() << endl;
  //    int tmpputs=0;
  int aicount=0;
  while(!g->done()){
    //     tmpputs = g->getPuts();
    if(c){
      aicount++;
      while(!g->doThis(first,c->react(sense))){
	// 	if(g->shoulda&&tmpputs==g->getPuts())//should have put but didnt
	// 	  exit(0);
	sense = g->getSensoryInput(first);

      }
      g->resetRound(c);
    }else{
//       cout << "kjører genmove.." << endl;
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
//   ftmp = g->score(true);
//   stmp = g->score(false);
  ftmp = ((2.0*fsum)+g->score(true))/((2*moves)+1);
  stmp = ((2.0*ssum)+g->score(false))/((2*moves)+1);

//   if(g->getPuts()==0)
//     ftmp -= 0.1;
//   else
//     ftmp += .15 * g->getPuts();
  ftmp = fsum+g->score(true))/aicount;
  stmp = ssum+g->score(false))/aicount;

  if(ftmp < fmin)
    fmin = ftmp;
  if(ftmp > fmax)
    fmax = ftmp;
  //   ftmp = 100-g->score();
  //  ftmp = g->score(true);

//   if(g->getPuts()==0)
//     ftmp -= 0.1;
//   else
//     ftmp += .15 * g->getPuts();

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
//   cout << "in END OF evaluator.." << endl;
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


extern "C" {
FitnessEvaluator *maker(char * str){
  FitnessEvaluator * ret;
  vector<string> * sv = split(str," ");
  if(sv->at(0).find("go")!=string::npos){
    if(sv->size()!=10){
      cerr << "wrong number of arguments to go evalator setup method; \"go <puregenerations> <gnugo-coevo-ratio> <coevo games> <easygo 0/1> <caching 0/1> <cachesize> <cache queue size> <resignation allowed 0/1> <gnugo configfile>\"" << endl;
      exit(1);
    }
    NEATsettings * set = new NEATsettings();
    ifstream ifs(sv->at(9).c_str(),ios::in);
    ifs >> set;
    ifs.close();
    int size = (int)set->getValue("size");
    double outsidev = set->getValue("outsidevalue");
    double komi = set->getValue("komi");
    int mem = (int)set->getValue("mem");
    int level = (int)set->getValue("level");
    int eyesize = (int)set->getValue("eyesize");
    int maxlooksteps = (int)set->getValue("maxlooksteps");
    bool caching = atoi(sv->at(5).c_str()) == 1;
    int csize = atoi(sv->at(6).c_str());
    int cqsize = atoi(sv->at(7).c_str());
    bool resign = atoi(sv->at(8).c_str()) == 1;
    gw::GoWrapper * gw = NULL;
    if(caching){
      gw = new gw::CachingGoWrapper(size,true,outsidev,
				komi,level,eyesize,maxlooksteps,mem,csize,cqsize);
    }else{
      gw = new gw::GoWrapper(size,true,outsidev,
			 komi,level,eyesize,maxlooksteps,mem);
    }
    gw->setResignAllowed(resign);
    int pg = atoi(sv->at(1).c_str());
    double r = atof(sv->at(2).c_str());
    int cogames = atoi(sv->at(3).c_str());
    int gnugogames = 0;//atleast one game per round against gnugo.
    gnugogames += (int)(r*cogames);
    if(gnugogames<=0)
      gnugogames = 1;
    cogames -= gnugogames;
    if(cogames<=0)
      cogames = 0;

    bool easy = atoi(sv->at(4).c_str()) == 1;


    if(!easy){
      ret = new GoEvaluator(gw,0,pg,r,set);
    }else{
      cerr << "making easygoeval!" << endl;
      ret = new EasyGoEvaluator(gw,0,pg,r,set);
    }
//     coevo = new Halloffame(cogames,cogames,pg,ret);
//     for(int i=0;i<gnugogames;i++){
//       ((Halloffame*)coevo)->addPermantent(NULL);//adding NULL as permanent member, defaults to gnugo in this fitness 
//     }
    delete sv;
    return ret;
  }else{
      cerr << "wrong number of arguments to go evalator setup method; \"go <puregenerations> <gnugo-coevo-ratio> <coevo games> <easygo 0/1> <caching 0/1> <cachesize> <cache queue size> <resignation allowed 0/1> <gnugo configfile>\"" << endl;
      delete sv;
  }
  return ret;
}
// class proxy { public:
//    proxy(){
//       // register the maker with the factory
//       factory["goeval"] = maker;
//    }
// };
// // our one instance of the proxy
// proxy p;
}
