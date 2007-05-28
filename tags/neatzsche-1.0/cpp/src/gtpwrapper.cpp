#include "gtpwrapper.h"
#include <sys/poll.h>
#include <math.h>
//dir: 1=up 2=down 3=left 4=right
bool GTPWrapper::checkBounds(bool first, int dir) 
{
  int * pos = getpos(first);
  if(dir==0&pos[0]==1)
    return false;
  if(dir==2&&pos[0]==bsize)
    return false;  
  if(dir==3&&pos[1]==1)
    return false;
  if(dir==1&&pos[1]==bsize)
    return false;
  return true;
}
static inline boost::dynamic_bitset<> * twistit(boost::dynamic_bitset<> * v,  int h, int rowsize)
{
  boost::dynamic_bitset<> * ret = new boost::dynamic_bitset<>((int)pow(rowsize,2)*2);
  //  cout << "twisting heading: " << h << endl;
  if(h==1){
//     cout << "twisting right" << endl;
    for(int i=0;i<rowsize;i++){
      for(int j=0;j<rowsize;j++){
	//	cout << "i:" << i << " j:" << j << " setting to: " << v[(j*rowsize)+((rowsize-1)-i)) << endl;
	(*ret)[(j*rowsize*2)+(2*i)] = (*v)[(i*rowsize*2)+(2*j)];
	(*ret)[(j*rowsize*2)+(2*i)+1] = (*v)[(i*rowsize*2)+(2*j)+1];
      }
    }
  }else if(h==3){
//     cout << "twisting left" << endl;
    for(int i=0;i<rowsize;i++){
      for(int j=0;j<rowsize;j++){
	//	cout << "i:" << i << " j:" << j << " setting to: " << v[(j*rowsize)+((rowsize-1)-i)) << endl;
	(*ret)[(j*rowsize*2)+(2*((rowsize-1)-i))] = (*v)[(i*rowsize*2)+(2*j)];
	(*ret)[(j*rowsize*2)+(2*((rowsize-1)-i))+1] = (*v)[(i*rowsize*2)+(2*j)+1];
      }
    }
  }else{
//     cout << "twisting down" << endl;
    //vector<double> tmp(v.begin(),v.end());
    for(int i=0;i<rowsize;i++){
      for(int j=0;j<rowsize;j++){
	(*ret)[(i*rowsize*2)+(2*j)] = (*v)[(j*rowsize*2)+(2*i)];
	(*ret)[(i*rowsize*2)+(2*j)+1] = (*v)[(j*rowsize*2)+(2*i)+1];
      }
    }
    //    cout << "after first transpose:" << endl << printvector(tmp,rowsize);
//     for(int i=0;i<rowsize;i++)
//       for(int j=0;j<rowsize;j++)
// 	ret[((rowsize-i-1)*rowsize)+(rowsize-j-1)) = tmp[(i*rowsize)+j);
//     cout << "after second transpose:" << endl << printvector(ret,rowsize);
  }
  return ret;
}
//returns a vector with 9 doubles representing the sensory
//input to the network..
boost::dynamic_bitset<> * GTPWrapper::sqlook(int * pos, bool first)
{
  //int * pos = getPos(first);
  //  cout << "in eye: pos0(height): " << pos[0] << " pos1: " << pos[1] << endl;
  boost::dynamic_bitset<> * ret = new boost::dynamic_bitset<>((int)pow(eyesize,2)*2);
//   cout << "creating addr: " << ret << endl;
  //  ret.insert(ret.begin(),);
  int ah = 0, aw = 0;
  int d = (int)floor(eyesize/2);
//   cout << "======= sqlook start ========= " << endl;
  for(int i=0;i<eyesize;i++){
    for(int i2=0;i2<eyesize;i2++){
      ah = pos[0]+i-d-1;
      aw = pos[1]+i2-d-1;
      
      if( ah<0 || aw<0 || ah==bsize || aw==bsize)//(((bsize-(ah+1))*bsize)+(2*aw))<0 || (unsigned int)(((bsize-(ah+1))*bsize)+(aw*2)+1)>=board.size() || ((2*aw)+1)>=(bsize*2) )
	{
//  	  cout << "adding ovalue: i:"<<i<<" i2:"<<i2<<" pos0: " 
//  	       << pos[0] << " pos1: " << pos[1] 
//  	       << " ah: " << ah << " aw: " << aw 
//  	       << " bsize: " << bsize << " the calc to coord " << (i*eyesize*2)+(i2*2) << "," << (i*eyesize*2)+(i2*2)+1 << endl;

	  (*ret)[(i*eyesize*2)+(i2*2)] = 1;
	  (*ret)[(i*eyesize*2)+(i2*2)+1] = 1;
// 	  cout << "ret now: " << *ret<<endl;
	} 
      else 
	{
// 	  cout << "adding goodvalue: i:"<<i<<" i2:"<<i2<<" pos0: " 
//  	       << pos[0] << " pos1: " << pos[1] 
//  	       << " ah: " << ah << " aw: " << aw << " the calc: " << ((bsize-(ah+1))*bsize)+(aw*2) << "," << ((bsize-(ah+1))*bsize)+(aw*2)+1
// 	       << " value: " << board[((bsize-(ah+1))*bsize)+(aw*2)] << "," << board[((bsize-(ah+1))*bsize)+(aw*2)+1] 
// 	       << " at coords: " << (i*2*eyesize)+(i2*2) << "," << (i*2*eyesize)+(i2*2)+1 << endl;
//    	  cout << "adding value ("<<ah<<","
//    	       <<aw<<"): " << board.at(((bsize-(ah+1))*bsize)+aw) << endl;
	  (*ret)[(i*eyesize*2)+(i2*2)] = board[((bsize-(ah+1))*bsize*2)+(aw*2)];
	  (*ret)[(i*eyesize*2)+(i2*2)+1] = board[((bsize-(ah+1))*bsize*2)+(aw*2)+1];
// 	  if(board[((bsize-(ah+1))*bsize)+(aw*2)]||board[((bsize-(ah+1))*bsize)+(aw*2)+1])
// 	    cout << "one of them over 0 printing: " << ret << endl;
	}
    }
  }
  int * heading = getHeading(first);
//         cout << "before:" <<endl << printvector(ret,eyesize);
  //  if(headingsupport){
  if(*heading!=0){
    boost::dynamic_bitset<> * tmp = ret;
    if(*heading==1)
      ret = twistit(ret,*heading,eyesize);
    else if(*heading==2)
      ret = twistit(ret,*heading,eyesize);
    else if(*heading==3)
      ret = twistit(ret,*heading,eyesize);
    delete tmp;
  }
//   else
//     cout << "not twisting.. " << endl;
//   cout << "returning addr: " << ret << " print: " << *ret << endl;
  return ret;
}
int* GTPWrapper::countPieces(boost::dynamic_bitset<> * look)
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
vector<double> GTPWrapper::getLongrange(bool first)
{
  vector<double> ret;
  int *tpos = new int[2];
  int d = (int)floor(eyesize/2)+1;
  //sone above..
  tpos = relativeFrontPos(first,tpos,d);
  int * t = countPieces(sqlook(tpos,first));
  ret.push_back(t[0]);
  ret.push_back(t[1]);
  delete[] t;
  //sone left.. 
  tpos = relativeLeftPos(first,tpos,d);
  t = countPieces(sqlook(tpos,first));
  ret.push_back(t[0]);
  ret.push_back(t[1]);
  delete[] t;
  //sone right..
  tpos = relativeRightPos(first,tpos,d);
  t = countPieces(sqlook(tpos,first));
  ret.push_back(t[0]);
  ret.push_back(t[1]);
  delete[] t;
  //sone behind..
  tpos = relativeBackPos(first,tpos,d);
  t = countPieces(sqlook(tpos,first));
  ret.push_back(t[0]);
  ret.push_back(t[1]);
  delete[] t;
  delete[] tpos;
  return ret;
}
int GTPWrapper::getInputCount()
{
  return (int)(pow(eyesize,2)*2) + 11 ;
}
vector<double> GTPWrapper::getSensoryInput(bool first)
{
  //int * fpos = getpos(first);
  //cout << "fpos: " << fpos[0] << " , " << fpos[1] << endl;
  //get all the data..
  boost::dynamic_bitset<> * oslook = sqlook(first);
  vector<double> lrange = getLongrange(first);

  int * pos = getpos(first);
  int l = islegal(first);//(board.at(((bsize-(pos[0]+1))*bsize)+pos[1]) == 0 ) ? true : false;// islegal(first); TODO make this back ... or not?
  //cout << "pos: " << pos[0] << " , " << pos[1] << endl;
  //now convert the look to black and white bools..
  vector<double> slook;
  //int c2=0;
  vector<double> ret;
  for(unsigned int i=0;i<(*oslook).size();i++)
    ret.push_back((*oslook)[i]);
  delete oslook;
//   int c=0;
//   for(unsigned int i=0;i<slook.size();i++)
//     if(slook.at(i)!=0.0)
//       c++;
//   if(c!=0)
//     cout << c << " not null points in slook vector" << endl;
  //concat the vectors...that is for a later time
  //cause now my battery is running empty and I
  //am on a bus heading home for crhistmas! :D
  //...and also, dunno this syntax, need web :p
  //vector<double> ret(slook.begin(),slook.end());
  //  ret.insert(ret.end(),lrange.begin(),lrange.end());
  for(unsigned int i=0;i<lrange.size();i++)
    ret.push_back(ret.at(i));
  ret.push_back((double)pos[0]/(double)bsize);
  ret.push_back((double)pos[1]/(double)bsize);
  ret.push_back(l);
  return ret;
}
//returns true for limit pass, pass or put, false for movement or 
// .. inp: a,b,c,d,e,f,g :
// a: forward, b: back, c: left, d: right,
// e: put, f: pass, g: pause
bool GTPWrapper::doThis(bool first, vector<double> inp)
{
  //  cout << "dothis inp: " << printvector(inp);
  //check for limits if within inc counter..
  if(first){
    if(fcount>=thinksteps){
      setPass(first);
      return true;
    }else 
      fcount++;
  }
  if(!first){
    if(scount>=thinksteps){
      setPass(first);
      return true;
    }else
      scount++;
  }

  //needs conflict resolution
  //first check for movement(default in kens code)
  //default in con  flicts; back & forward => forward, left & righ ->left
  bool forward,back,west,east;
  forward=back=west=east=false;
  bool moving = false;
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
  bool turned = false;
  if(inp.at(1)>0.5){//turn left
    turnleft(first);
    turned = true;
  }else if(inp.at(2)>0.5){//right..
    turnright(first);
    turned = true;
  }
  
  if(!moving&&!turned){
    int ind = 5;
    int n = 5;
//     if(headingsupport)
//       n++;
    double max=0.5;
    for(int i=3;i<n;i++){
      if(inp.at(i)>max){
	ind = i;
	max = inp.at(i);
      }
    }
    if(ind==5){//default
      //      cout << "doing nothing.." << endl;
      return false;
    }
    if(ind==3){
//       if(!justput)
      //cout << "putting " << getColoredCoord(first) << endl; 

//       if(justput)
// 	secondput = true;
//       justput = true;
//       if(justmoved && secondput)
// 	cout << "!!!! second put " << getColoredCoord(first) << endl;
      if(put(first)){//regardless of illegal move?? heh
	moves++;
// 	if(moves>4)
// 	cout<<"four moves!!!: " << endl << getLocalBoardAscii();
	unsetPass(first);
	unsetCount(first);
      }else{
	setPass(first);
	unsetCount(first);
      }
      return true;
    }else if(ind==4){
      //      cout << "passing" << endl;
      setPass(first);
      unsetCount(first);
      return true;
    }
//     else if(headingsupport&&ind==7){
//       //      cout << "turning around!!" << endl;
      
//       unsetPass(first);
//       return false;
//     }
  }else{
//     if(!justmoved)
    //cout << "fpass:"<<fpass<<" spass:" << spass << " moving(fc:"<<fcount<<" sc:"<<scount<<")" << "forward: " << forward << " back: "<<back<<" west: "<<west<<"  east:" << east<< endl;
    unsetPass(first);
//     justmoved = true;
    //    unsetCount(first);
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

string GTPWrapper::getColoredCoord(bool first)
{
  stringstream cm;
  int * pos = getpos(first);
//   cout << "getcoloredcoord: pos0:" << pos[0] << " pos1:" 
//        << pos[1] << " getColCharpos1:" << getColChar(pos[1]) << endl;
  if(first){
    cm << "black ";
  }else{
    cm << "white ";
  }
  cm << getColChar(pos[1]);
  cm << (bsize-pos[0]+1);
  return cm.str();
}
bool GTPWrapper::put(bool first)
{
  //int * pos = getpos(first);
  string cmd = getColoredCoord(first);
//    cout << "cmd: \"" << cmd << "\""
//         << " pos0: "<<pos[0]<<" pos1: " << pos[1] << endl;
  //  int fanda;
  //  cin >> fanda;
  //int p = first+1;

  bool r = doMove(cmd);
  //bool r = (board.at(((bsize-(pos[0]+1))*bsize)+pos[1]) == 0 ) ? true : false;
  if(r)
    updateFromGnuGo();

//   cout << "black put at: " << cmd << " p:" << p 
//        << " pos0: "<<pos[0]<<" pos1: " << pos[1] << endl;
//   cout << "board is:" << endl << printvector(board,bsize);
  return r;
}
GTPWrapper::GTPWrapper(int bs, bool isp, double iovalue, 
		     double ikomi, int ilvl, int ieyesize, int tsteps)
{
  //  unstuckgnugno = true;
  //  headingsupport = iheadingsupport;
  fheading = new int; sheading = new int;
  *fheading = 0; *sheading=0;
  thinksteps = tsteps;
  eyesize = ieyesize;
  ovalue = iovalue;
  pos1 = new int[2];
  pos2 = new int[2];

  sp = isp;
  komi = ikomi;
  lvl = ilvl;
  // for pure gnugo(production)
  //   p1 = "--mode gtp --boardsize ";
  //with logging enabled, for debugging
  //  p1 = "--input-log gnugo_log_i.txt --output-log gnugo_log_o.txt --error-log gnugo_log_e.txt gnugo --mode gtp --boardsize ";
  p1 = "--mode gtp --boardsize ";
  //dunno :P boyes test code
  //   p1 = "-i /dev/ttyp6 -o /dev/ttyp6 -e /dev/ttyp6 gnugo --mode gtp --boardsize ";
  stringstream ss1;
  ss1 << p1;
  //setting up the cmdline for right boardsize.
  ss1 << bs << " --level " << lvl << " --komi " << komi;
  p1 = ss1.str();
  bsize = bs;
  resetPos();
  cout << "bsize: "<<bsize<<" pos1-0:"<<pos1[0]<<" pos2-0:" << pos2[0]<<endl;
  //board.insert(board.begin(),(bsize*bsize),0);
  board = state((int)pow(bsize,2)*2);
  //   for(int i=0;i<(bsize*bsize);i++)//setting up the board..
  //     board.push_back(0);
  pipe(nPipeIn);
  pipe(nPipeOut);
  //  runit();
  toGnugo = new fdostream();
  fromGnugo = new fdistream();

  nChildFds = new int[3];
  //  string file = "logio";
  //   if (ConnectProcess("gnugo", p1, &fraGnugo, &tilGnugo, 0, 0, 0))
  pid_t * nPid = new pid_t();
  if (ConnectProcess(string("gnugo"), p1, toGnugo, fromGnugo, NULL, nPid, nChildFds))
    {
      cerr << "Failed to change process image (execvp) in parent process to " 
	   << "gnugo" << ". System error message: " << strerror(errno) << "\n.";
      //return 1;
    }

}
void GTPWrapper::genmove(bool first)
{
  
  if(moves==1&&bsize==5&&!first&&board[24]==0&&board[25]==1) {//kens trick
    if(doMove("white B3")) {board[22]=1;board[23]=0;
      //      board.at(11) = 1;//cout << "setting white at b3.."<<endl;
      moves++; return;} 
    else{//cout << "could not white at b3.."<<endl; 
      setPass(first); return;}
  }
  // to make gnugo play through a 5x5 match..
  string r = (first) ? doCmd("genmove black") : doCmd("genmove white");
  //int s = first+1;
  //  cout << "r: " << r << endl;

  if(r.find("?")!=string::npos)
    return;
  if(r.find("PASS")!=string::npos){
    //    string s = (first) ? "black" : "white";
    //cout << ((first) ? "black" : "white") << " passed board: "<< endl << getLocalBoardAscii();
    setPass(first);
    return;
  }
  moves++;
//   r = r.substr(r.find(" ")+1,r.length());
//   r = r.substr(0,r.length());
//   int x = getCol(r[0]); int y = atoi(r.substr(1,r.length()).c_str()); y--; x++;
//   //   cout << "white moved to" << endl;   cout << "x:"<<x<<" y:"<<y<<"   r: " << r << " s:" << s << " first:" << first <<  endl; 
//   //  cout << "setting board at: " << ((bsize-x)*bsize)+y << " to " << s<<endl;
//   board.at(((bsize-x)*bsize)+y)  = s;
  updateFromGnuGo();
  //  int fanda;
  //  cin >> fanda;
  //  cout << "board at: " << ((x-bsize)*bsize)+y << ": " << board.at((x*bsize)+y) <<endl;
  //  cout << getBoardAscii() << endl;
}
double GTPWrapper::countBlack(state bboard){
  double ret=0;
  for(unsigned int i=0;i<(bboard.size()/2);i++)
    if(bboard[2*i]==0 && bboard[(2*i)+1]==1)
      ret++;
  return ret;
}
double GTPWrapper::countWhite(state bboard){
  double ret=0;
  for(unsigned int i=0;i<(bboard.size()/2);i++)
    if(bboard[2*i]==1 && bboard[(2*i)+1]==0)
      ret++;
  return ret;

}
bool GTPWrapper::islegal(bool first)
{
  stringstream ss;
  string s = getColoredCoord(first);
  //  cout << "s: \"" << s << "\""<<endl;
  ss << "is_legal " << s;
   
  string r = doCmd(ss.str());
  //    cout << "r: \"" << r << "\"" << endl;
  r = r.substr(r.find(" ")+1,r.length());
  r = r.substr(0,r.length());
  return atof(r.c_str());
}
double GTPWrapper::score(bool first, bool final)
{
  stringstream ss;
  string s = (final) ? "estimate_score " : "final_score ";
  ss << s;
  if(first)
    ss << " black";
  else
    ss << " white";
   
  string r = doCmd(ss.str());
  bool w = true;
  if(r.find("W")){
    r = r.substr(r.find("W")+1,r.length());
    r = r.substr(0,r.find(" "));
  }else{
    r = r.substr(r.find("B")+1,r.length());
    r = r.substr(0,r.find(" "));    
    w = false;
  }
  double tmp = atof(r.c_str());
  if(first&&w)
    tmp *= -1;
  else if(!first&&!w)
    tmp *= -1;

  return 361+tmp;
}
string GTPWrapper::doCmd(string cmd)
{
  string ret;
  string tmp;
  *toGnugo << cmd << endl << flush;
  //  cerr << "Command: " << cmd << endl;
  if(cmd.find("quit")!=string::npos)
    return "";
  if (getline(*fromGnugo, tmp)){
    ret += tmp;
    getline(*fromGnugo, tmp);
    ret += tmp;
  }
  return ret;
}
bool GTPWrapper::doMove(string move)
{
  string t = doCmd(move);
  return (t.find("?")==string::npos) ? true : false;
}

string GTPWrapper::pollCmd(string cmd) // includes endl
{
  string ret;
  string tmp;

  *toGnugo << cmd << endl << flush;
  //  cerr << "Command: " << cmd << endl;

  //   while(ret.find("\n")==string::npos)
  
  //   char c;
  //   while (fromGnugo->get(c).gcount() > 0)
  //     ret += c;

  if (!getline(*fromGnugo, ret))
    return ret;

  struct pollfd pfd = { nChildFds[1], POLLIN, 0 };
  bool bCont = true;
  while (bCont)
    {
      switch(poll(&pfd, 1, 1000))
	{
	case -1:
	  cerr << "Poll failed.\n";
	  break;
	case 0:
	  //           cerr << "Nothing more available, waiting for input...\n";
	  bCont = false;
	  break;
	default:
	  {
	    string s;
	    if (!getline(*fromGnugo, s))
	      bCont = false;
	    else
	      ret += "\n" + s;
	  }
	}
    }
  //   *fromGnugo >> ret;
  //   tmp = ret;
  //   int c=0;
  //   cout << "stream good:" << fromGnugo->good() << endl;
  //   while(fromGnugo->good()&&(fromGnugo->peek()!=-1)){
  //     cout << "stream good:" << fromGnugo->good() << " peek:" << fromGnugo->peek() << endl;
  //     *fromGnugo >> tmp;
  //     ret += tmp;
  //   }

  return ret;
}  
GTPWrapper::~GTPWrapper()
{
  
}
string GTPWrapper::getLocalBoardAscii(state bboard)
{
  stringstream ret;
  ret << "X: Black\nO: White\n\n";
  ret << " ";
  for(int i=1;i<=bsize;i++)
    ret << " " << getColChar(i);
  ret << endl;

  for(int i=1;i<=bsize;i++){
    ret << (bsize-i+1);
    for(int i2=0;i2<(bsize);i2++){
//       cout << "localboardascii checking i:"<<i<<" i2:"<<i2<<" " << ((bsize-i)*bsize*2)+(2*i2) << " and " << ((bsize-i)*bsize*2)+(2*i2)+1;
      ret << " " ; 
      if(bboard[((bsize-i)*bsize*2)+(2*i2)]==0 && bboard[((bsize-i)*bsize*2)+(2*i2)+1]==1){
	ret << "X";
// 	cout << "added x";
      }else if(bboard[((bsize-i)*bsize*2)+(2*i2)]==1 && bboard[((bsize-i)*bsize*2)+(2*i2)+1]==0){
	ret << "O";
// 	cout << "added o" ;
      }else
	ret << ".";
    }
    ret << " " << (bsize-i+1);
    ret << endl;
  }
  ret << " " ;
  for(int i=1;i<=bsize;i++)
    ret << " " << getColChar(i);
  ret << endl;
  return ret.str();
}
void GTPWrapper::updateFromGnuGo()
{
  string ret;
  string tmp;
  int rs = bsize + 4;
  *toGnugo << "showboard" << endl << flush;
  bool bigboard = (bsize>10);
  //  cerr << "Command: " << cmd << endl;
  for(int i=0;i<rs;i++){
    //    cout << "reading line.. i: "<< i << endl;
//     if (getline(*fromGnugo, tmp)){
//       ret += tmp;
//       cout << "read line:.. tmp: "<< tmp << endl;
    getline(*fromGnugo, tmp);
    if(!bigboard && (i==bsize || i==(bsize+1))){
      tmp = tmp.substr(0,(bsize*2)+4);
    }
    if(bigboard && (i==10 || i == 11))
      tmp = tmp.substr(0,(bsize*2)+4);
    ret += tmp;
    //ret += "\n";
    //    }
//     cout << "read line:.. tmp: \""<< tmp << "\""<< endl;
  }
//   cout << "read board from gnugo: "
//        << endl << "\"" << ret << "\""<<endl;
  //  return;
  int i = 0;
  int boardc2=0;
  int totalc=4+(bsize*2);
  char c;
  bool twodigits = false;
  if(bsize>9)
    twodigits = true;
  for(;i<bsize;i++){
    boardc2=0;
    totalc += 3;
    for(int i2=3;i2<((bsize*2)+2);i2+=2){
      c = ret[totalc];
      //      cout << "i2: "<<i2<<" totalc: "<<totalc<<" read in c: " << c << endl;
      if(c=='X'){
	board[((bsize-(i+1))*bsize*2)+(2*boardc2)] = 0; board[((bsize-(i+1))*bsize*2)+(2*boardc2)+1] = 1;
      }else if(c=='O'){
	board[((bsize-(i+1))*bsize*2)+(2*boardc2)] = 1; board[((bsize-(i+1))*bsize*2)+(2*boardc2)+1] = 0;
      }else{
	board[((bsize-(i+1))*bsize*2)+(2*boardc2)] = 0; board[((bsize-(i+1))*bsize*2)+(2*boardc2)+1] = 0;
      }
      boardc2++;
      totalc += 2;
    }
    if(twodigits&&(bsize-i)>9)
      totalc++;
    totalc++;
  }
//   cout << "read " << test << " spots.." << endl;
}
void CachingGTPWrapper::genmove(bool first)
{
//   cout << "in caching genmove..."<<endl;
  StateChange * ss = scs->get(board);
  state oldboard = board;
  if(ss==NULL&&moves==1&&bsize==5&&!first&&board[24]==0&&board[25]==1) {//kens trick
    if(doMove("white B3")) {board[22]=1;board[23]=0;
      //scs->add(oldboard,board);
      //      board.at(11) = 1;//cout << "setting white at b3.."<<endl;
      moves++; return;} 
    else{//cout << "could not white at b3.."<<endl; 
      setPass(first); return;}
  }
  
  if(ss==NULL){
//     cout << "ss null" << endl;
//     cout << getGnuGoAscii();
    string r = (first) ? doCmd("genmove black") : doCmd("genmove white");
//     cout << getGnuGoAscii();
    if(r.find("?")!=string::npos){
//       cout << "fikk spmtegn" << endl;
      return;
    }if(r.find("PASS")!=string::npos){
//       cout << "fikk pass" << endl;
      setPass(first);
      return;
    }else{
      updateFromGnuGo();
//       if(countWhite(oldboard)==2&&countWhite(board)==1){
// // 	cout << getLocalBoardAscii(oldboard);
// // 	cout << getLocalBoardAscii(board);
// // 	cout << "exiting countWhite(board): " << countWhite(board) << " countWhite(oldboard) " << countWhite(oldboard) << endl;
// 	// exit(1);
//       }
      r = r.substr(r.find(" ")+1,r.length());
      r = r.substr(0,r.length());
      int y = getCol(r[0]); int x = atoi(r.substr(1,r.length()).c_str()); //y--; x++;
      state fcoord = convertToBits(x);
      state scoord = convertToBits(y);
      scs->add(oldboard,board,fcoord,scoord,first);
//       cout << "adding: x: "<<x<<" y: "<<y<<" xbits: "<<fcoord<<" ybits: " << scoord << endl; 
//       cout << "adding fra("<<countWhite(oldboard)<<"):\n " << printvector(convertlook(&oldboard),bsize);
//       cout << "adding til("<<countWhite(board)<<"):\n " << printvector(convertlook(&board),bsize);
      //      cout << "added:" << endl;
      //      cout << scs->prettyprint();
//       if(countWhite(oldboard)==2&&countWhite(board)==1)
// 	exit(1);
    }
    miss++;
  }else{
    hit++;
//     cout << "ss ikke null.." << endl;
    //cout << "scs pp: " << endl << scs->prettyprint();
//     cout << "fra:\n " << printvector(convertlook(&oldboard),bsize);
    //cout << "til:\n " << printvector(convertlook(ss),bsize);
    stringstream cmd;
    //    string color = 
    cmd << (first ? "black ":"white ");
    int h = convertFromBits(ss->getFirstCoord());
    int h2 = convertFromBits(ss->getSecondCoord());
//     cout << "fbits:"<<ss->getFirstCoord()<<" fint: " << h << endl;
//     cout << "sbits:"<<ss->getSecondCoord()<<" sint: " << h2 << endl;
    cmd << getColChar(h2);
    cmd << h;
//     cout << "doing cmd from the sc: " << cmd.str() << endl;
    doCmd(cmd.str());
    board = ss->getTo();
  }
  moves++;
}
string GTPWrapper::getGnuGoAscii(){
  string ret;
  string tmp;
  int rs = bsize + 4;
  *toGnugo << "showboard" << endl << flush;
  bool bigboard = (bsize>10);
  //  cerr << "Command: " << cmd << endl;
  for(int i=0;i<rs;i++){
    //    cout << "reading line.. i: "<< i << endl;
//     if (getline(*fromGnugo, tmp)){
//       ret += tmp;
//       cout << "read line:.. tmp: "<< tmp << endl;
    getline(*fromGnugo, tmp);
    if(!bigboard && (i==bsize || i==(bsize+1))){
      tmp = tmp.substr(0,(bsize*2)+4);
    }
    if(bigboard && (i==10 || i == 11))
      tmp = tmp.substr(0,(bsize*2)+4);
    ret += tmp;
    ret += "\n";
    //ret += "\n";
    //    }
//     cout << "read line:.. tmp: \""<< tmp << "\""<< endl;
  }
  return ret;
}
