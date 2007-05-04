#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "genome.h"
#include "neuralmath.h"
#include "settings.h"
#include "evolution.h"
#include "evoops.h"
#include <sstream>
#include "gowrapper.h"
#include <boost/dynamic_bitset.hpp>


//     inp[i+1];
//     cerr << "i: " << i << " value: " << first << " neste value: " << second << endl;
//     if(first == false && second == true)
//       ret.push_back(2.0);
//     else if(first == true && second == false)
//       ret.push_back(1.0);
//     else if(first == true && second == true)
//       ret.push_back(0.3);
//     else
//       ret.push_back(0.0);

void run2(gw::CachingGoWrapper * go, int eyes);

void run(gw::GoWrapper * go, int eyes, Genome * g)
{
  Phenotype * p = new Phenotype(g);
  vector<double> put; put.insert(put.begin(),5,0);
  put.at(3) = 0.8;
  vector<double> forward; forward.insert(forward.begin(),5,0);
  forward.at(0) = 0.8;
  vector<double> left; left.insert(left.begin(),5,0);
  left.at(1) = 0.8;
  vector<double> right; right.insert(right.begin(),5,0);
  right.at(2) = 0.8;
  vector<double> pass; pass.insert(pass.begin(),5,0);
  pass.at(4) = 0.8;
  //go->put(true);
  cerr << "putting" << endl;
  go->doThis(true,put);
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "reaction: " << printvector(p->react(go->getSensoryInput(true)));
  //cerr << go->getLocalBoardAscii(); 
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "reaction: " << printvector(p->react(go->getSensoryInput(true)));
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "reaction: " << printvector(p->react(go->getSensoryInput(true)));
  cerr << "turning left.." << endl;
  go->doThis(true,left);
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "reaction: " << printvector(p->react(go->getSensoryInput(true)));
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "putting" << endl;
  go->doThis(true,put);
  go->updateFromGnuGo();
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "after update:" << endl;
  cerr << go->getLocalBoardAscii(); 
  cerr << "turning right.." << endl;
  go->doThis(true,right);
  cerr << "turning right.." << endl;
  go->doThis(true,right);
  cerr << "turning right.." << endl;
  go->doThis(true,right);
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward); 
  cerr << "putting" << endl;
  go->doThis(true,put);
  go->updateFromGnuGo();
  cerr << "after update:" << endl;
  cerr << go->getLocalBoardAscii();
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "reaction: " << printvector(p->react(go->getSensoryInput(true)));
  cerr << "turning left.." << endl;
  go->doThis(true,left);
  cerr << "moving forward" << endl;  
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "putting" << endl;
  go->doThis(true,put);
  go->updateFromGnuGo();
  cerr << "after update:" << endl;
  cerr << go->getLocalBoardAscii();
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "reaction: " << printvector(p->react(go->getSensoryInput(true)));
  cerr << "turning left.." << endl;
  go->doThis(true,left);
  cerr << "moving forward" << endl;  
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "putting" << endl;
  go->doThis(true,put);
  go->updateFromGnuGo();
  cerr << "after update:" << endl;
  cerr << go->getLocalBoardAscii(); 
  cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
  cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "reaction: " << printvector(p->react(go->getSensoryInput(true)));
}


int main(int argc, char *args[]){
  // go test code
  if(argc!=2){
    cerr << "usage: " << args[0] << " go-genome " << endl;
  } 
  string sGenomeFile = args[1];
  NEATsettings * goset = new NEATsettings();
  ifstream goifs("settings/settings-gnugo",ios::in);
  goifs >> goset;
  goifs.close();
  int size = (int)goset->getValue("size");
  double outsidev = goset->getValue("outsidevalue");
  double komi = goset->getValue("komi");
  int level = (int)goset->getValue("level");
  int eyesize = (int)goset->getValue("eyesize");
  int mem = (int)goset->getValue("mem");
  int maxlooksteps = (int)goset->getValue("maxlooksteps");

  gw::CachingGoWrapper * go = new gw::CachingGoWrapper(size,false,outsidev,komi,level,eyesize,maxlooksteps,mem,500,500);
  NEATsettings * set = new NEATsettings();
  ifstream ifsSettings("settings/settings-go");
  ifsSettings >> set;
  ifsSettings.close();
  TransferFunctions * tfs = new TransferFunctions(set);
  Genome * g = new Genome(tfs);
  ifstream ifs(sGenomeFile.c_str());
  ifs >> g;
  ifs.close();

  go->reset();
  run2(go,eyesize);
//  run(go,eyesize,g);
  go->quit();
}


void run2(gw::CachingGoWrapper * go, int eyes)
{
  vector<double> put; put.insert(put.begin(),5,0);
  put.at(3) = 0.8;
  vector<double> forward; forward.insert(forward.begin(),5,0);
  forward.at(0) = 0.8;
  vector<double> left; left.insert(left.begin(),5,0);
  left.at(1) = 0.8;
  vector<double> right; right.insert(right.begin(),5,0);
  right.at(2) = 0.8;
  vector<double> pass; pass.insert(pass.begin(),5,0);
  pass.at(4) = 0.8;
  double tsum = 0;
  int moves = 0;
  //go->put(true);
  cerr << "putting" << endl;
  go->doThis(true,put);
  tsum += go->score(); moves++;
  go->gw_genmove(false);
  tsum += go->score(); moves++;
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << go->getLocalBoardAscii(); 
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "putting" << endl;
  go->doThis(true,put);
  tsum += go->score(); moves++;
  go->gw_genmove(false);
  tsum += go->score(); moves++;
  cerr << go->getLocalBoardAscii(); 
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
  cerr << "putting" << endl;
  go->doThis(true,put);
  tsum += go->score(); moves++;
  go->gw_genmove(false);
  tsum += go->score(); moves++;
  cerr << go->getLocalBoardAscii(); 
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "turning left.." << endl;
  go->doThis(true,left);
  cerr << "turning left.." << endl;
  go->doThis(true,left);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "turning left.." << endl;
  go->doThis(true,left);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "turning right.." << endl;
  go->doThis(true,right);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "moving forward" << endl;
  go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "putting" << endl;
  go->doThis(true,put);
  tsum += go->score(); moves++;
  go->gw_genmove(false);
  tsum += go->score(); moves++;
  go->updateFromGnuGo();
  cerr << "after update:" << endl;
  cerr << go->getLocalBoardAscii(); 

  cerr << "moving forward" << endl;
  go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
  cerr << "putting" << endl;
  go->doThis(true,put);
  go->gw_genmove(false);
  go->updateFromGnuGo();
  cerr << "after update:" << endl;
  cerr << go->getLocalBoardAscii(); 
  double ftmp = 100-(((tsum*2.0)/(double)moves)+go->score());
  cout << "ftmp: " << ftmp << endl ;
//   cerr << "!!beginning fuckup.. turning left.." << endl;
//   go->doThis(true,left);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));

//   cerr << "moving forward" << endl;
//   go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));

//   cerr << "turning left.." << endl;
//   go->doThis(true,left);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));

//   cerr << "moving forward" << endl;
//   go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));

//   cerr << "moving forward" << endl;
//   go->doThis(true,forward);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));

//   cerr << "putting" << endl;
//   go->doThis(true,put);
//   go->gw_genmove(false);
//   go->updateFromGnuGo();

//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));

//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
//   cerr << "after update:" << endl;
//   cerr << go->getLocalBoardAscii(); 
//   go->gw_genmove(false);
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
// //   go->gw_genmove(false);
// //   go->gw_genmove(false);
// //   go->gw_genmove(false);  go->gw_genmove(false);
//   go->updateFromGnuGo();
//   cerr << "after update:" << endl;
//   cerr << go->getLocalBoardAscii();
//   cerr << "eye:\n" << printvector(gw::convertlook(go->sqlook(true)),eyes);
//   cerr << "sensinput: " << printvector(go->getSensoryInput(true));
//   cerr << "go score: b: " << go->score() << endl;
}
