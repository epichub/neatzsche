#ifndef GTPWRAPPER_H_
#define GTPWRAPPER_H_
// #include <stdlib.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
//#include <fdstream.h>
#include <errno.h>
#include <getopt.h>
#include <ext/stdio_filebuf.h>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <misc_utils.h>
#include <syncutils.h>
//#include <conio.h>
#include "neuralmath.h"
#include "statechanges.h"
//#include <boost/dynamic_bitset.hpp>

using namespace std;

static inline state convertToBits(int i)
{
  state ret(4);
  static const int mask0 = 1; //0001..
  static const int mask1 = 2; //0010..
  static const int mask2 = 4; //0100..
  static const int mask3 = 8; //1000..
  ret[0] = i & mask0; ret[1] = i & mask1; ret[2] = i & mask2;
  ret[3] = i & mask3;
  return ret;
}
static inline int convertFromBits(state bits)
{
  return (int)bits.to_ulong();
}
class GTPWrapper {
protected:
  string p1;
  int nPipeIn[2], nPipeOut[2];
  bool fpass,spass;
  bool sp;
  bool t;
  //  bool unstuckgnugo;
  int moves;
  int fcount;
  int scount;
  int bsize;
  int lvl;
  int eyesize;
  int thinksteps;
  int *pos1;
  int *pos2;
  //  int nChildFds[3];
  int * nChildFds;
  double komi;
  double ovalue;
  //  int **board;
  state board;
  //vector<int> board; //here goes nothing..
  string pollCmd(string cmd); //includes endl
  string doCmd(string cmd); //includes endl
  bool doMove(string move);
  fdostream *toGnugo;
  fdistream *fromGnugo;
  //  ifstream *errGnugo;
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
  void setPass(bool first) { 
    if(first) fpass = true; 
    else spass = true;}
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
public:
  GTPWrapper(int bs, bool isp, double iovalue, double komi, int lvl, int ieyesize, int tsteps);//endrer 
  virtual ~GTPWrapper();
  static const int GG_WHITE = 1;
  static const int GG_BLACK = 2;
  void turnleft(bool first){int *heading =getHeading(first); *heading = (3+(*heading))%4;}
  void turnright(bool first){int *heading =getHeading(first); *heading = (++(*heading))%4;}
  void updateFromGnuGo();
  bool islegal(bool first);//TODO:move to private after testing
  state * sqlook(bool first)
  {
    int * pos =getpos(first); state * r = sqlook(pos,first); 
    return r;}
  bool up(bool first){if(!checkBounds(first,0)) return false;
    int * pos = getpos(first); pos[0]--;return true;}
  bool down(bool first){if(!checkBounds(first,2)) return false;
    int * pos = getpos(first); pos[0]++; if(pos[0]<0){ cout << "flyttet pos0 til under0 " << endl; exit(1);}return true;}
  bool left(bool first){if(!checkBounds(first,3)) return false;
    int * pos = getpos(first); pos[1]--; if(pos[1]<0){ cout << "flyttet pos0 til under0 " << endl; exit(1);}return true;}
  bool right(bool first){if(!checkBounds(first,1)) return false;
    int * pos = getpos(first); pos[1]++;return true;}
  bool put(bool first);
  void pass(bool first);
  //  string getColoedCoord(bool first);
  void reset(){doCmd("clear_board");fpass=spass=false;board.clear(); 
    board = state((int)pow(bsize,2)*2);
    fcount=scount=moves=0;
    resetPos();
    *fheading = 0; *sheading = 0;}
  void simplereset(){fpass=spass=false;board.clear(); 
    board = state((int)pow(bsize,2)*2);
    fcount=scount=moves=0;
    resetPos();}
  void resetCount(){fcount=scount=0;}
  void resetPos(){pos1[0] = pos1[1] = pos2[0] = pos2[1] = (bsize/2);
  pos1[0]++;pos2[0]++; pos1[1]++;pos2[1]++;}
  void quit(){doCmd("quit");}
  virtual void genmove(bool first);
  bool done(){return (fpass&&spass);}
  //only call at end of game when
  //you are sure gnugo is non-bosy..
  string getBoardAscii(){return pollCmd("showboard");}
  string getLocalBoardAscii(){return getLocalBoardAscii(board);};
  string getLocalBoardAscii(state bboard);
  double score(bool first, bool final);
  int getInputCount();
  int getOutputCount(){return 7;}
  vector<double> getSensoryInput(bool first);
  bool doThis(bool first, vector<double> inp);
  bool whitePass(){return spass;}
  bool blackPass(){return fpass;}
  bool easytest(){ return board[24] == 1 && board[16] == 1; }
  double countBlack(state bboard);
  double countBlack(){return countBlack(board);};
  double countWhite(state bboard);

  string getGnuGoAscii();
  double easyCount(){
    return board[board.size()-1];
//     double r=0; 
//     if(board.at(12) == 2) r++; 
//     if(board.at(13) == 2) r++; 
//     else if(moves>1) r += 0.5; 
//     if(board.at(14) == 2) r++;
//     if(board.at(18) == 2) r++;
//     return r;
  }
  int getMoves(){return moves;}
  int getFCount(){return fcount;}
//   int currentplayerid;
//   bool justmoved;
//   bool justput;
//   bool secondput;
};
class CachingGTPWrapper : public GTPWrapper 
{
private:
  StateChanges *scs;
  int hit;
  int miss;
public:
  CachingGTPWrapper(int bs, bool isp, double iovalue, double komi, int lvl, int ieyesize, int tsteps, int states, int queue) : 
    GTPWrapper(bs,isp,iovalue,komi,lvl,ieyesize,tsteps) { scs = new StateChanges(states,queue); hit=0;miss=0; // cout <<endl << endl<< "!!!! in cachinggowrapper constr!!! .. hit:" << hit << endl<<endl;
  }
  virtual void genmove(bool first);
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
#endif
