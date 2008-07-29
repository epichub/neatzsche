#include "eval.h"
extern "C" {
  FitnessEvaluator *maker(char * str)
  {
    FitnessEvaluator * ret;
    vector<string> * sv = split(str," ");
    if(sv->at(0).find("eye")!=string::npos) {
      if(sv->size()!=2){
      cout << "wrong arguments to eye eval should be: \"eye <settingsfile>\"" << endl;
	exit(1);
      }
      NEATsettings * set = new NEATsettings();
      ifstream ifs(sv->at(1).c_str(),ios::in);
      ifs >> set;
      ifs.close();
      unsigned int lsnum=set->getValue("number_of_lightsources");
      unsigned int ymax=set->getValue("ymax");
      unsigned int xmax=set->getValue("xmax");
      unsigned int ls_dist=set->getValue("ls_distance");
      double cellsize=set->getValue("cellsize");
      ret = new LightsimEvaluator(set,xmax,ymax,lsnum,cellsize,ls_dist);
      return ret;
    }else
      cout << "wrong arguments to eye eval should be: \"eye <settingsfile>\"" << endl;
  }
}
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

  //  int clo=clock();
  ls2d->pruneBlockedVectors();
  //  int clo2=clock();


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
