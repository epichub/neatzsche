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

#include "gowrapper.h"
#include <sys/poll.h>
#include <math.h>
namespace gw{
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
  //gets the board directly from gnugos board repr.("Intersection board;" .. )
  string myprintboard(int bsize){
    stringstream ss;
    for(int i=0;i<bsize;i++){
      for(int i2=0;i2<bsize;i2++){
	ss << " " << gg::board[POS(i,i2)];
      }
      ss << endl;
    }
    return ss.str();
  }
  //dir: 1=up 2=down 3=left 4=right
  bool GoWrapper::checkBounds(bool first, int dir) 
  {
    int * pos = getpos(first);
    if(dir==0&&pos[0]==0)
      return false;
    if(dir==2&&pos[0]==(bsize-1))
      return false;  
    if(dir==3&&pos[1]==0)
      return false;
    if(dir==1&&pos[1]==(bsize-1))
      return false;
    return true;
  }
  static inline boost::dynamic_bitset<> * transLRDiag(boost::dynamic_bitset<> & v,  int h, int rowsize){
    boost::dynamic_bitset<> * ret = new boost::dynamic_bitset<>((int)pow(rowsize,2)*2);
    for(int i=0;i<rowsize;i++){
      for(int j=0;j<rowsize;j++){
	(*ret)[(j*rowsize*2)+(2*i)] = v[(i*rowsize*2)+(2*j)];
	(*ret)[(j*rowsize*2)+(2*i)+1] = v[(i*rowsize*2)+(2*j)+1];
      }
    } 
    return ret;
  }
  static inline boost::dynamic_bitset<> * transVertLine(boost::dynamic_bitset<> & v,  int h, int rowsize){
    boost::dynamic_bitset<> * ret = new boost::dynamic_bitset<>((int)pow(rowsize,2)*2);
    for(int i=0;i<rowsize;i++){
      for(int j=0;j<rowsize;j++){
	if(j!=(rowsize-1-j)){
	  (*ret)[(i*rowsize*2)+(2*j)] = v[(i*rowsize*2)+(2*(rowsize-1-j))];
	  (*ret)[(i*rowsize*2)+(2*j)+1] = v[(i*rowsize*2)+(2*(rowsize-1-j))+1];
	}else{
	  (*ret)[(i*rowsize*2)+(2*j)] = v[(i*rowsize*2)+(2*j)];
	  (*ret)[(i*rowsize*2)+(2*j)+1] = v[(i*rowsize*2)+(2*j)+1];
	}
      }
    }
    return ret;
  }
  static inline boost::dynamic_bitset<> * twistit(boost::dynamic_bitset<> * v,  int h, int rowsize)
  {
    boost::dynamic_bitset<> * ret = new boost::dynamic_bitset<>((int)pow(rowsize,2)*2);

    if(h==1){
      delete ret;
      boost::dynamic_bitset<> * tmp = NULL;
      tmp = transVertLine(*v,h,rowsize);
      ret = transLRDiag(*tmp,h,rowsize);
      delete tmp;
    }else if(h==3){
      for(int i=0;i<rowsize;i++){
	for(int j=0;j<rowsize;j++){
	  (*ret)[(j*rowsize*2)+(2*((rowsize-1)-i))] = (*v)[(i*rowsize*2)+(2*j)];
	  (*ret)[(j*rowsize*2)+(2*((rowsize-1)-i))+1] = (*v)[(i*rowsize*2)+(2*j)+1];
	}
      }
    }else{
      //switch around vertical axis..
      delete ret;
      ret = transVertLine(*v,h,rowsize);
      boost::dynamic_bitset<> tmp = *ret;
      for(int i=0;i<rowsize;i++){
	for(int j=0;j<rowsize;j++){
	  if(i!=(rowsize-1-i)){
	    (*ret)[(i*rowsize*2)+(2*j)] = tmp[((rowsize-1-i)*rowsize*2)+(2*j)];
	    (*ret)[(i*rowsize*2)+(2*j)+1] = tmp[((rowsize-1-i)*rowsize*2)+(2*j)+1];
	  }else{
	    (*ret)[(i*rowsize*2)+(2*j)] = tmp[(i*rowsize*2)+(2*j)];
	    (*ret)[(i*rowsize*2)+(2*j)+1] = tmp[(i*rowsize*2)+(2*j)+1];
	  }
	}
      }
    }
    return ret;
  }
  //returns a vector with 9 doubles representing the sensory
  //input to the network..
  boost::dynamic_bitset<> * GoWrapper::sqlook(int * pos, bool first)
  {
    boost::dynamic_bitset<> * ret = new boost::dynamic_bitset<>((int)pow(eyesize,2)*2);
    int ah = 0, aw = 0;
    int d = (int)floor(eyesize/2);
    for(int i=0;i<eyesize;i++){
      for(int i2=0;i2<eyesize;i2++){
	ah = pos[0]+i-d;
	aw = pos[1]+i2-d;
      
	if( ah<0 || aw<0 || ah>=bsize || aw>=bsize)
	  {
	    (*ret)[(i*eyesize*2)+(i2*2)] = 1;
	    (*ret)[(i*eyesize*2)+(i2*2)+1] = 1;
	  } 
	else 
	  {
	    (*ret)[(i*eyesize*2)+(i2*2)] = gwboard[(ah*bsize*2)+(aw*2)];
	    (*ret)[(i*eyesize*2)+(i2*2)+1] = gwboard[(ah*bsize*2)+(aw*2)+1];
	  }
      }
    }
    int * heading = getHeading(first);
    if(*heading!=0){
      boost::dynamic_bitset<> * tmp = ret;
      if(*heading==1){
	ret = twistit(ret,*heading,eyesize);
      }else if(*heading==2){
	ret = twistit(ret,*heading,eyesize);
      }else if(*heading==3){
	ret = twistit(ret,*heading,eyesize);
      }
      delete tmp;
    }
    return ret;
  }
  int* GoWrapper::countPieces(boost::dynamic_bitset<> * look)
  {
    int *r = new int[2];
    for(unsigned int i=0;i<((*look).size()/2);i++){
      if((*look)[2*i]==0&&(*look)[(2*i)+1]==1)
	r[0]++;
      else if((*look)[2*i]==1&&(*look)[(2*i)+1]==0)
	r[1]++;
    }
    return r;
  }
  void inputIt(bool first, vector<double> & ret, int * t){
    if(first){
      ret.push_back(t[0]);
      ret.push_back(t[1]);
    }else{
      ret.push_back(t[1]);
      ret.push_back(t[0]);
    }
  }
  vector<double> GoWrapper::getLongrange(bool first)
  {
    vector<double> ret;
    int *tpos = new int[2];
    int d = (int)floor(eyesize/2)+1;
    //sone above..
    tpos = relativeFrontPos(first,tpos,d);
    state * temps = sqlook(tpos,first);
    int * t = countPieces(temps);
    delete temps;
    inputIt(first,ret,t);
    delete[] t;
    //sone left.. 
    tpos = relativeLeftPos(first,tpos,d);
    temps = sqlook(tpos,first);
    t = countPieces(temps);
    delete temps;
    inputIt(first,ret,t);
    delete[] t;
    //sone right..
    tpos = relativeRightPos(first,tpos,d);
    temps = sqlook(tpos,first);
    t = countPieces(temps);
    delete temps;
    inputIt(first,ret,t);
    delete[] t;
    //sone behind..
    tpos = relativeBackPos(first,tpos,d);
    temps = sqlook(tpos,first);
    t = countPieces(temps);
    delete temps;
    inputIt(first,ret,t);
    delete[] t;
    delete[] tpos;
    return ret;
  }
  int GoWrapper::getInputCount()
  {
    return (int)(pow(eyesize,2)*2) + 11 ;
  }
  vector<double> GoWrapper::getSensoryInput(bool first)
  {
    //get all the data..
    boost::dynamic_bitset<> * oslook = sqlook(first);
    vector<double> lrange = getLongrange(first);

    int * pos = getpos(first);
    int l = islegal(first);

    vector<double> slook;
    vector<double> ret;
    if(first){
      for(unsigned int i=0;i<(*oslook).size();i++)
	ret.push_back((*oslook)[i]);
    }else{//we need to give the network the same kind of inputs when
      //doing coevo and playing white..that way it doesnt need to
      //learn the "concept" of having the pieces it used to play
      //itself, as enemy pieces, the concepts should be ['mine','other'] :)
      for(unsigned int i=0;i<(*oslook).size();i+=2){
	if((*oslook)[i]==1&&(*oslook)[i+1]==1){//outside board, shouldnt change
	  ret.push_back((*oslook)[i]);ret.push_back((*oslook)[i+1]);
	}else{//a piece, just reverse
	  ret.push_back(!(*oslook)[i]);ret.push_back(!(*oslook)[i+1]);
	}
      }
    }
    delete oslook;
    //concat the vectors...that is for a later time
    //cause now my battery is running empty and I
    //am on a bus heading home for christmas! :D
    //...and also, dunno this syntax, need web :p
    for(unsigned int i=0;i<lrange.size();i++)
      ret.push_back(ret.at(i));
    ret.push_back((double)pos[0]/(double)(bsize-1));
    ret.push_back((double)pos[1]/(double)(bsize-1));
    ret.push_back(l);
    return ret;
  }
  //returns true for limit pass, pass or put, false for movement or 
  // .. inp: a,b,c,d,e,f,g :
  // a: forward, b: back, c: left, d: right,
  // e: put, f: pass, g: pause
  bool GoWrapper::doThis(bool first, vector<double> inp)
  {
    if(first){
      if(fcount>=thinksteps){
	moves++;
	setPass(first);
	return true;
      }else 
	fcount++;
    }
    if(!first){
      if(scount>=thinksteps){
	moves++;
	setPass(first);
	return true;
      }else
	scount++;
    }

    //needs conflict resolution
    //first check for movement(default in kens code)
    //default in conflicts; left & righ ->left
    //first check turning, as the eye can move and turn
    //in one move.
    bool forward,back,west,east;
    forward=back=west=east=false;
    bool moving = false;
    bool turned = false;
    if(inp.at(1)>0.5){//turn left
      turnleft(first);
      turned = true;
    }else if(inp.at(2)>0.5){//right..
      turnright(first);
      turned = true;
    } 
    int *heading = getHeading(first);
    if(inp.at(0)>0.5){//forward..
      moving = true;
      if(*heading == 0)
	forward = true;
      else if(*heading == 1)
	east = true;
      else if(*heading == 2)
	back = true;
      else if(*heading == 3)
	west = true;
    }

  
    if(!moving&&!turned){
      int ind = 5;
      int n = 5;
      double max=0.5;
      for(int i=3;i<n;i++){
	if(inp.at(i)>max){
	  ind = i;
	  max = inp.at(i);
	}
      }
      if(ind==5){//default
	return false;
      }
      if(ind==3){

	if(put(first)){//regardless of illegal move?? heh
	  puts++;
	  unsetPass(first);
	  unsetCount(first);
	}else{
	  setPass(first);
	  unsetCount(first);
	}
	return true;
      }else if(ind==4){
	passes++;
	setPass(first);
	unsetCount(first);
	return true;
      }
    }else{
      unsetPass(first);
      if(forward)
	up(first);
      if(back)
	down(first);
      if(west)
	left(first);
      if(east)
	right(first);
      return false;
    }
    return true;
  }

  bool GoWrapper::fakeThis(bool first, vector<double> inp)
  {
    if(first){
      if(fcount>=thinksteps){
	cerr << "thinksteps up setting pass" << endl;
	return true;
      }else {
	cerr << "thinksteps not up incing" << endl;
      }
    }
    if(!first){
      if(scount>=thinksteps){
	cerr << "thinksteps up setting pass" << endl;
	return true;
      }else{
	cerr << "thinksteps not up incing" << endl;
      }
    }
    bool forward,back,west,east;
    forward=back=west=east=false;
    bool moving = false;
    bool turned = false;
    if(inp.at(1)>0.5){//turn left
      cerr << "turning left" << endl;
      turned = true;
    }else if(inp.at(2)>0.5){//right..
      cerr << "turning right" << endl;
      turned = true;
    } 
    int *heading = getHeading(first);
    if(inp.at(0)>0.5){//forward..
      cerr << "relative forward" << endl;
      moving = true;
      if(*heading == 0)
	forward = true;
      else if(*heading == 1)
	east = true;
      else if(*heading == 2)
	back = true;
      else if(*heading == 3)
	west = true;
    }

  
    if(!moving&&!turned){
      int ind = 5;
      int n = 5;
      double max=0.5;
      for(int i=3;i<n;i++){
	if(inp.at(i)>max){
	  ind = i;
	  max = inp.at(i);
	}
      }
      if(ind==5){//default
	return false;
	cerr << "idling" << endl;
      }
      if(ind==3){

	if(put(first)){//regardless of illegal move?? heh
	  cerr << "putting" << endl;
	}else{
	  cerr << "invalid move .. passing" << endl;
	}
	return true;
      }else if(ind==4){
	cerr << "passing" << endl;
	return true;
      }
    }else{
      if(forward)
	cerr << "moving forward pos " << pos1[0] << " , " << pos1[1] << endl;
      if(back)
	cerr << "moving back pos " << pos1[0] << " , " << pos1[1] << endl;
      if(west)
	cerr << "moving west pos " << pos1[0] << " , " << pos1[1] << endl;
      if(east)
	cerr << "moving east pos " << pos1[0] << " , " << pos1[1] << endl;
      return false;
    }
    return true;
  }

  string GoWrapper::getColoredCoord(bool first)
  {
    stringstream cm;
    int * pos = getpos(first);

    if(first){
      cm << "black ";
    }else{
      cm << "white ";
    }
    cm << getColChar(pos[1]);
    cm << (bsize-pos[0]+1);
    return cm.str();
  }
  bool GoWrapper::put(bool first)
  {
    int * pos = getpos(first);
    int to_move = first+1;

    int move = POS(pos[0],pos[1]);
    int board_size = gg::board_size;
    if(gg::is_legal(move, to_move) && ON_BOARD2(pos[0],pos[1])){
      gg::play_move(move, to_move);
    }else
      return false;
    moves++;
    updateFromGnuGo();
    return true;
  }
  GoWrapper::GoWrapper(int bs, bool isp, double iovalue, 
		       double ikomi, int ilvl, int ieyesize, int tsteps, int mem)
  {
    resignallowed = true;
    dbg = false;
    fheading = new int; sheading = new int;
    *fheading = 0; *sheading=0;
    thinksteps = tsteps;
    eyesize = ieyesize;
    ovalue = iovalue;
    pos1 = new int[2];
    pos2 = new int[2];
    lgpos = new int[2];

    sp = isp;
    lvl = ilvl;
    netmoves = 0;
    //making my gowrapper local board repr.
    gwboard = state((int)pow(bsize,2)*2);

    //setting up gnugo!
//     cerr << "bs: "  << bs << endl;
    gg::board_size = bsize = bs;
//     cerr << "gg::board_size: "  << gg::board_size << endl;
//     cerr << "bsize: "  << bsize << endl;
    gg::init_gnugo(mem,1);
//     cerr << "bsize2: "  << bsize << endl;
    gg::gnugo_clear_board(bsize);
#ifdef GGSTABLE
    gg::level = lvl;
#endif
#ifdef GGCVS
    gg::set_level(lvl);
#endif
    gg::komi = ikomi;
    scorevalmax = pow(bsize,2)+ikomi;
    //    scoremin = (-pow(bsize,2))-ikomi;
    twoscorevalmax = 2*scorevalmax;
    resetPos();
  }
  //first: 1 == white, black == 2
  void GoWrapper::gw_genmove(bool first)
  {
    int to_move = first+1;
    int i,j;
#ifdef GGSTABLE
    int move = gg::genmove(&i, &j, to_move);
    int board_size = gg::board_size;
    if(resignallowed && move < 0.0 && ON_BOARD2(i, j) ){
      setPass(first);
      if(dbg)
	cerr << "genmove didnt find any moves..  move: " << move 
	     << " ONBOARD2: " << ON_BOARD2(i, j) << endl;
      return;
    }
    gg::play_move(move, to_move);
#endif

#ifdef GGCVS
    int resign;
    float move_value;
    int move = gg::genmove(to_move, &move_value, &resign);
    int board_size = gg::board_size;
    if(resignallowed && resign ){
      setPass(first);
      if(dbg)
	cerr << "genmove didnt find any moves..  move: " << move 
	     << " ONBOARD2: " << ON_BOARD2(i, j) << endl;
      return;
    }
    gg::gnugo_play_move(move, to_move);
#endif

    moves++;
    updateFromGnuGo();
  }
  double GoWrapper::countBlack(state bboard){
    double ret=0;
    for(unsigned int i=0;i<(bboard.size()/2);i++)
      if(bboard[2*i]==0 && bboard[(2*i)+1]==1)
	ret++;
    return ret;
  }
  double GoWrapper::countWhite(state bboard){
    double ret=0;
    for(unsigned int i=0;i<(bboard.size()/2);i++)
      if(bboard[2*i]==1 && bboard[(2*i)+1]==0)
	ret++;
    return ret;

  }
  bool GoWrapper::islegal(bool first)
  {
    int color = (first) + 1;
    int * pos = getpos(first);
    int move = POS(pos[0],pos[1]);
    return gg::is_legal(move, color);
  }
  double GoWrapper::score()
  {
    float * upper = new float;  float * lower = new float;
    float ret = gg::gnugo_estimate_score(upper,lower); // returns a number pos for white dom, neg for black dom
    return ret;
  } 
  double GoWrapper::score(bool first){
    float * upper = new float;  float * lower = new float;
    float ret = gg::gnugo_estimate_score(upper,lower); // returns a number pos for white dom, neg for black dom
    if(first)
      ret = -ret;
    return (ret+scorevalmax)/twoscorevalmax;
  }
  GoWrapper::~GoWrapper()
  {
    delete fheading; delete sheading; delete[] pos1; delete[] pos2;

  }
  //returns a string containing a prettyprint of the local board
  //repr.
  string GoWrapper::getLocalBoardAscii(state bboard)
  {
    stringstream ret;
    ret << "X: Black\nO: White\n\n";
    ret << " ";
    for(int i=1;i<=bsize;i++)
      ret << " " << getColChar(i);
    ret << endl;

    for(int i=0;i<bsize;i++){
      ret << (bsize-i);
      for(int i2=0;i2<(bsize);i2++){
	ret << " " ; 
	if(bboard[(i*bsize*2)+(2*i2)]==0 && bboard[(i*bsize*2)+(2*i2)+1]==1){
	  ret << "X";
	}else if(bboard[(i*bsize*2)+(2*i2)]==1 && bboard[(i*bsize*2)+(2*i2)+1]==0){
	  ret << "O";
	}else
	  ret << ".";
      }
      ret << " " << (bsize-i);
      ret << endl;
    }
    ret << " " ;
    for(int i=1;i<=bsize;i++)
      ret << " " << getColChar(i);
    ret << endl;
    return ret.str();
  }
  //gets the board from gnugo(this is the part that
  //saves you from coding you own go rules..
  void GoWrapper::updateFromGnuGo()
  {

    for(int i=0;i<bsize;i++){
      for(int i2=0;i2<bsize;i2++){
	if(gg::board[POS(i,i2)] == gg::EMPTY){
	  gwboard[(i*bsize*2)+(2*i2)] = 0; gwboard[(i*bsize*2)+(2*i2)+1] = 0;
	}else if(gg::board[POS(i,i2)] == gg::WHITE){
	  gwboard[(i*bsize*2)+(2*i2)] = 1; gwboard[(i*bsize*2)+(2*i2)+1] = 0;
	}else if(gg::board[POS(i,i2)] == gg::BLACK){
	  gwboard[(i*bsize*2)+(2*i2)] = 0; gwboard[(i*bsize*2)+(2*i2)+1] = 1; }
      }
    }
  }
  CachingGoWrapper::CachingGoWrapper(int bs, bool isp, double iovalue, double komi, int lvl, int ieyesize, 
				     int tsteps, int mem, int states, int queue) : 
    GoWrapper(bs,isp,iovalue,komi,lvl,ieyesize,tsteps,mem)
  {
    scs = new StateChanges(states,queue); hit=0;miss=0;
#ifdef GGSTABLE
    if(bsize==5){//inserting the standard move where gnugo usually
		 //just resigns, 
      state from(50);
      state to(50);
      from[24]=0;from[25]=1;
      to[24]=0;to[25]=1;
      to[26]=1;to[27]=0;
      state fcoord = convertToBits(2);
      state scoord = convertToBits(3);
      scs->add(from,to,fcoord,scoord,false);

    }
#endif
#ifdef GGCVS
    if(bsize==5){//inserting the standard move where gnugo usually
		 //just resigns, 
      state from(50);
      state to(50);
      from[14]=1;from[15]=0;
      from[24]=0;from[25]=1;
      from[34]=0;from[35]=1;
      to[14]=1;to[15]=0;
      to[22]=1;to[23]=0;
      to[24]=0;to[25]=1;
      to[34]=0;to[35]=1;
//       cerr << "adding from: \n" << getLocalBoardAscii(from);
//       cerr << "adding to: \n" << getLocalBoardAscii(to);
      state fcoord = convertToBits(2);
      state scoord = convertToBits(1);
      scs->add(from,to,fcoord,scoord,false);
      from = state(50);
      to = state(50);
      from[14]=1;from[15]=0;
      from[24]=0;from[25]=1;
      from[22]=0;from[23]=1;
      to[14]=1;to[15]=0;
      to[26]=1;to[27]=0;
      to[24]=0;to[25]=1;
      to[22]=0;to[23]=1;
      fcoord = convertToBits(2);
      scoord = convertToBits(3);
//       cerr << "adding from: \n" << getLocalBoardAscii(from);
//       cerr << "adding to: \n" << getLocalBoardAscii(to);
      scs->add(from,to,fcoord,scoord,false);
      from = state(50);
      to = state(50);
      from[14]=1;from[15]=0;
      from[24]=0;from[25]=1;
      from[26]=0;from[27]=1;
      to[14]=1;to[15]=0;
      to[22]=1;to[23]=0;
      to[24]=0;to[25]=1;
      to[26]=0;to[27]=1;
      fcoord = convertToBits(2);
      scoord = convertToBits(1);
//       cerr << "adding from: \n" << getLocalBoardAscii(from);
//       cerr << "adding to: \n" << getLocalBoardAscii(to);
      scs->add(from,to,fcoord,scoord,false);
    }
#endif
  }
  string getPiece(int pos){
    string s;
    switch(gg::board[pos]){
    case gg::EMPTY:
      s = "EMPTY";
    case gg::BLACK:
      s = "BLACK";
    case gg::WHITE:
      s = "WHITE";
    default:
      s = "n/a";
    }
    return s;
  }
  void CachingGoWrapper::gw_genmove(bool first)
  {
    int to_move = first+1;
    StateChange * ss = scs->get(gwboard);//check for cached move
    state oldboard = gwboard;

    if(ss==NULL){//nothing found in cache, generating move
#ifdef GGSTABLE
      int i,j;
      int move = gg::genmove(&i, &j, to_move);
      int board_size = gg::board_size;
      bool resign = resignallowed && ( move < 0.0 && ON_BOARD2(i,j) ); //check for resign..
//       cerr << "move: " << move << " i: " << " j: " << j 
// 	   << " ON_BOARD2(i,j): " << ON_BOARD2(i,j)
// 	   << " resign: " << resign << endl;
      if(resign || !ON_BOARD2(i,j)){ //and other illegal moves
	setPass(first);
	return;
      }else{//move is legit
	gg::gnugo_play_move(i,j, to_move);//play the move
	updateFromGnuGo();//get the board back from gnugo
	if(gg::is_pass(move))
	  setPass(first);
	else{
	  state fcoord = convertToBits(i);
	  state scoord = convertToBits(j);
	  scs->add(oldboard,gwboard,fcoord,scoord,first); //add to cache
	}
      }
#endif

#ifdef GGCVS
      int resign;
      float move_value;
      int move = gg::genmove(to_move, &move_value, &resign);
      int board_size = gg::board_size;
      if(resignallowed && resign){ //and other illegal moves
	setPass(first);
	return;
      }else{//move is legit
	gg::gnugo_play_move(move, to_move);//play the move
	updateFromGnuGo();//get the board back from gnugo
	if(gg::is_pass(move))
	  setPass(first);
	else{
	  state fcoord = convertToBits(I(move));
	  state scoord = convertToBits(J(move));
	  scs->add(oldboard,gwboard,fcoord,scoord,first); //add to cache
	}
      }
#endif

      miss++;
    }else{//found cache entry!
      hit++;
      int i = convertFromBits(ss->getFirstCoord());//extract i
      int j = convertFromBits(ss->getSecondCoord());// .. j

      int move = POS(i,j);//convert to gnugos 1d repr..
//       cerr << "found cache move: " << move << " i: " << i << " j: " << j << endl;
      gg::play_move(move, to_move);//play move
      gwboard = ss->getTo();//set the local repr to the cached move
    }
    moves++;
  }

  // lots of debug code and strange "go" fitness functions..
  double GoWrapper::straightLineFitness()
  {
    double ret=0;
    for(int i=0;i<bsize;i++){
      for(int i2=0;i2<bsize;i2++){
	if(i2 == (bsize/2) && gwboard[(i*bsize*2)+(i2*2)] == 0 && gwboard[(i*bsize*2)+(i2*2)+1] == 1){
	  ret++;
	}
      }
    }
    return ret;
  }
  double GoWrapper::crockedLineFitness()
  {
    double ret=0;
    if(gwboard[(0*bsize*2)+(1*2)] == 0 && gwboard[(0*bsize*2)+(1*2)+1] == 1)
      ret++;
    if(gwboard[(1*bsize*2)+(2*2)] == 0 && gwboard[(1*bsize*2)+(2*2)+1] == 1)
      ret++;
    if(gwboard[(2*bsize*2)+(2*2)] == 0 && gwboard[(2*bsize*2)+(2*2)+1] == 1)
      ret++;
    if(gwboard[(3*bsize*2)+(2*2)] == 0 && gwboard[(3*bsize*2)+(2*2)+1] == 1)
      ret++;
    if(gwboard[(4*bsize*2)+(3*2)] == 0 && gwboard[(4*bsize*2)+(3*2)+1] == 1)
      ret++;
    return ret;
  }

  double GoWrapper::nexttonew()
  {
    double ret=0;
    bool checkwest = true, checkeast = true, checknorth=false, checksouth = false;
    int i = lgpos[0]; int j = lgpos[1];
    if(i==0)
      checknorth = false;
    if(i>=(bsize-1))
      checksouth = false;
    if(j==0)
      checkwest = false;
    if(j>=(bsize-1))
      checkeast = false;
    if(checknorth)
      if(gwboard[((i-1)*bsize*2)+(j*2)] == 0 && gwboard[((i-1)*bsize*2)+(j*2)+1] == 1)
	ret++;
    if(checksouth)
      if(gwboard[((i+1)*bsize*2)+(j*2)] == 0 && gwboard[((i+1)*bsize*2)+(j*2)+1] == 1)
	ret++;
    if(checkwest)
      if(gwboard[((i)*bsize*2)+((j-1)*2)] == 0 && gwboard[((i)*bsize*2)+((j-1)*2)+1] == 1)
	ret++;
    if(checkeast)
      if(gwboard[((i)*bsize*2)+((j+1)*2)] == 0 && gwboard[((i)*bsize*2)+((j+1)*2)+1] == 1)
	ret++;
    return ret;
  }
}
