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

#ifndef GOWRAPPER_H_
#define GOWRAPPER_H_

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <errno.h>
#include <getopt.h>
#include <ext/stdio_filebuf.h>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "neuralmath.h"
#include "statechanges.h"
#include "evolution.h"

namespace gg{
  extern "C" {
#include "gnugo.h"
  }
}

using namespace std;
namespace gw {

  class GoWrapper {
  protected:
    //dothis tmpvars:
    bool forward,back,west,east;
    bool moving;
    int turned;
    int* heading;
    int ind;
    double domax;
    double dotmp;
    //getSensoryinputvars
    vector<double> lrange;
    int legalmove;
    vector<double> slook;
    vector<double> sensoryret;


    //default put value
    double pfire;
    int ppos[2];

    //sqlook
    int sqd;
    int ah, aw;
    int eyesetsize;

    //longrange
    vector<double> lret;
    int *tpos;
    int lgd;
    state * temps;
    int * lcount;

    bool fpass,spass;
    bool sp;
    bool t;
    //counters
    int fcount;
    int scount;
    int lvl;
    int eyesize;
    int thinksteps;
    int *pos1;
    int *pos2;
    int *lgpos;

    double ovalue;
    double scorevalmax;
    double twoscorevalmax;
    state gwboard;
    bool resignallowed;
    int getCol(char c){return ((int)c)-64;}
    char getColChar(int p){return (char)(p+64);}
    int * getpos(bool first){return (first) ? pos1 : pos2;}
    vector<double> getLongrange(bool first);
    state * sqlook(int *pos, bool first);
    int * countPieces(state * look);
    string getColoredCoord(bool first);
    bool checkBounds(bool first, int dir);
    int *fheading;
    int *sheading;
    int *  getHeading(bool first){return (first) ? fheading : sheading;}
    void unsetPass(bool first) { 
      if(first) fpass = false; 
      else spass = false;}
    void unsetCount(bool first) { 
      if(first) fcount = 0; 
      else scount = 0;} 
    int * relativeLeftPos(bool first, int *tpos, int d){
      int * heading = getHeading(first);
      int * pos = getpos(first);
      tpos[0] = pos[0]; tpos[1] = pos[1];
      if(*heading==0) tpos[1]=-d;
      else if(*heading==1) tpos[0]=-d;
      else if(*heading==2) tpos[1]=+d;
      else if(*heading==3) tpos[0]=+d;
      return tpos;}
    int * relativeRightPos(bool first, int *tpos, int d){
      int * heading = getHeading(first);
      int * pos = getpos(first);
      tpos[0] = pos[0]; tpos[1] = pos[1];
      if(*heading==0) tpos[1]=+d;
      else if(*heading==1) tpos[0]=+d;
      else if(*heading==2) tpos[1]=-d;
      else if(*heading==3) tpos[0]=-d;
      return tpos;}
    int * relativeFrontPos(bool first, int *tpos , int d){
      int * heading = getHeading(first);
      int * pos = getpos(first);
      tpos[0] = pos[0]; tpos[1] = pos[1];
      if(*heading==0) tpos[0]=-d;
      else if(*heading==1) tpos[1]=+d;
      else if(*heading==2) tpos[0]=+d;
      else if(*heading==3) tpos[1]=-d;
      return tpos;}
    int * relativeBackPos(bool first, int *tpos , int d){
      int * heading = getHeading(first);
      int * pos = getpos(first);
      tpos[0] = pos[0]; tpos[1] = pos[1];
      if(*heading==0) tpos[0]=+d;
      else if(*heading==1) tpos[1]=-d;
      else if(*heading==2) tpos[0]=-d;
      else if(*heading==3) tpos[1]=+d;
      return tpos;}
    bool islegal(bool first);
  public:
    GoWrapper(int bs, bool isp, double iovalue, double komi, int lvl, int ieyesize, int tsteps, int mem);//endrer 
    virtual ~GoWrapper();
    void setPass(bool first) { 
      if(first) fpass = true; 
      else spass = true;}
    void turnleft(bool first){int *heading =getHeading(first); *heading = (3+(*heading))%4;}
    void turnright(bool first){int *heading =getHeading(first); *heading = (++(*heading))%4;}
    void updateFromGnuGo();
    int bsize;
    bool dbg;
    bool shoulda;
    int netmoves;
    void setResignAllowed(bool ires){gg::capture_all_dead = !ires; gg::resign_allowed=resignallowed=ires;}
    bool getResignAllowed(){return resignallowed;}
    state * sqlook(bool first)
    {
      int * pos =getpos(first); state * r = sqlook(pos,first); 
      return r;}
    bool up(bool first){if(!checkBounds(first,0)) return false;
      int * pos = getpos(first); pos[0]--;return true;}
    bool down(bool first){if(!checkBounds(first,2)) return false;
      int * pos = getpos(first); pos[0]++; if(pos[0]<0){ cerr << "flyttet pos0 til under0 " << endl; exit(1);}return true;}
    bool left(bool first){if(!checkBounds(first,3)) return false;
      int * pos = getpos(first); pos[1]--; if(pos[1]<0){ cerr << "flyttet pos0 til under0 " << endl; exit(1);}return true;}
    bool right(bool first){if(!checkBounds(first,1)) return false;
      int * pos = getpos(first); pos[1]++;return true;}
    bool put(bool first);
    void pass(bool first);
    void reset(){
      gg::gnugo_clear_board(bsize);
      fpass=spass=false;gwboard.clear(); 
      gwboard = state((int)pow(bsize,2)*2);
      fcount=scount=moves=movedputs=passes=0;
      pfire = 0;
      resetPos();
      *fheading = 0; *sheading = 0;}
    void simplereset(){fpass=spass=false;gwboard.clear(); 
      gwboard = state((int)pow(bsize,2)*2);
      fcount=scount=moves=0;
      resetPos();}
    void resetRound(Phenotype * p){
      pfire = 0;
      resetCount();
      resetPos();
      p->cleanNet();
    }
    void defaultPut(bool first){ 	
      int * p = getpos(first);
      p[0] = ppos[0];
      p[1] = ppos[1];
      put(first);
    }
    void resetCount(){fcount=scount=0;}
    void resetPos(){ 
      pos1[0] = pos1[1] = pos2[0] = pos2[1] = (bsize/2);
    }
    void mput(int i, int j, int color){gg::play_move(POS(i,j),color);}
    void quit(){}
    virtual void gw_genmove(bool first);
    bool done(){return (fpass&&spass);}
    string getLocalBoardAscii(){return getLocalBoardAscii(gwboard);};
    string getLocalBoardAscii(state bboard);
    double score();
    double score(bool first);
    int getInputCount();
    int getOutputCount(){return 7;}
    vector<double> getSensoryInput(bool first);
    bool doThis(bool first, vector<double> inp);
    bool fakeThis(bool first, vector<double> inp);
    bool whitePass(){return spass;}
    bool blackPass(){return fpass;}
    bool easytest(){ return gwboard[24] == 1 && gwboard[16] == 1; }
    double countBlack(state bboard);
    double countBlack(){return countBlack(gwboard);};
    double countWhite(state bboard);
    double easyCount(){
      return gwboard[gwboard.size()-1];
    }
    double straightLineFitness();
    double crockedLineFitness();
    double nexttonew();
    int getMoves(){return moves;}
    int getFCount(){return fcount;}

    //Stats...
    int moves;
    int movedputs;
    int getPuts(){return movedputs;}
    void setPuts(int i){movedputs = i;}
    inline void incPuts(){movedputs++;}
    int passes;
  };
  class CachingGoWrapper : public GoWrapper 
  {
  private:
    StateChanges *scs;
    int hit;
    int miss;
  public:
    CachingGoWrapper(int bs, bool isp, double iovalue, double komi, int lvl, int ieyesize, int tsteps, int mem, int states, int queue) ;
    ~CachingGoWrapper(){delete scs;}
    virtual void gw_genmove(bool first);
    string printHitMiss(){stringstream ss; ss << "hit: " << hit << " miss: " << miss << " ratio: " << ((double)hit/(double)miss) << endl; return ss.str();}
  };

  static inline vector<double> convertlook(state * inp2){
    vector<double> ret;
    state inp = *inp2;
    bool first,second;
    for(state::size_type i=0;i<inp.size();i += 2){
      first = inp[i];
      second = inp[i+1];
      if(first == false && second == true)
	ret.push_back(2.0);
      else if(first == true && second == false)
	ret.push_back(1.0);
      else if(first == true && second == true)
	ret.push_back(0.3);
      else
	ret.push_back(0.0);
    }
    return ret;
  }

  static inline string printBits(state * inp2, int rowsize){
  
    stringstream ret;
    state inp = *inp2;
    int i2=0;
    for(state::size_type i=0;i<inp.size();i+=2){
      ret << " " << inp[i] << inp[i+1];
      if(i2!=0&&(i2+1)%rowsize==0){
	ret << endl;
	i2=0;
      }else
	i2++;
    }
    return ret.str();
  }
};
#endif
