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
#include "dataset.h"
void printVector(vector< double > * v){
  for(unsigned int i=0;i<v->size();i++)
    cout << " " << v->at(i);
  cout << endl;
}
string * getNext(string inp){
  if(inp.length()==0)
    return 0;
  string * retStr = 0;
  if(inp.find(",")!=string::npos)
    retStr = new string(inp.substr(0,inp.find(",")));
  else
    retStr = new string(inp);
  return retStr;
}
string getRest(string inp){
  if(inp.find(",")==string::npos)
    return "";
  return inp.substr(inp.find(",")+1,inp.length());	
}
string * getLast(string inp){
  if(inp.find_last_of(",")==string::npos)
    return 0;
  string * retStr = new string(inp.substr(inp.find_last_of(",")+1,inp.length()));
  return retStr;
}
string getRestEnd(string inp){
  if(inp.find_last_of(",")==string::npos)
    return 0;
  return inp.substr(0,inp.find_last_of(",")) ;	
}
bool isIn(vector<string> * v, string str){
  for(unsigned int i=0;i<v->size();i++)
    if(v->at(i).find(str)!=string::npos)
      return true;
  return false;	
}
DataSet::DataSet(bool classAtStart, string file, double ratio)
{
  name = file;
  uniqueClasses=0;
  //int classC=0;
  classes = new vector<string>;
  data = new vector< vector<double>* >;
  ifstream ifs(file.c_str());
  if(!ifs.good())
    return;
  char buf[4096];
  string strBuf;
  string * tmpStr;
  while(!ifs.eof()){
    ifs.getline(buf,sizeof buf);
    strBuf = buf;
    if(strBuf.length()==0)
      break;
    if(classAtStart){
      if(!isIn(classes,*getNext(strBuf)))
	uniqueClasses++;
      classes->push_back(*getNext(strBuf));
      strBuf = getRest(strBuf);
    }else{
      if(!isIn(classes,*getLast(strBuf)))
	uniqueClasses++;
      classes->push_back(*getLast(strBuf));
      strBuf = getRestEnd(strBuf);
    }
    vector<double> * intvector = new vector<double>;
    while((tmpStr = getNext(strBuf)) != 0){
      intvector->push_back(atof(tmpStr->c_str()));
      strBuf = getRest(strBuf);
    }
    data->push_back(intvector);
  }
  ifs.close();
  cerr << "read "<<data->size()<<" datapoints, with "<<data->at(0)->size()<<" paramaters  classes: "<<classes->size()<<" unique:"<<uniqueClasses<<"\n";
  tests = (int)(data->size()*ratio);
  trainings = data->size()-tests;
  Dummy myDummy;
  int ** tmpCoord = myDummy.randomCoords(data->size(),0);
  trainCoords = new int [trainings];
  testCoords = new int [tests];
  int c = 0;
  for(;c<tests;c++)
    testCoords[c] = tmpCoord[c][0];
	
  for(;c<(tests+trainings);c++)
    trainCoords[(c-tests)] = tmpCoord[c][0];

  cerr << "tests: "<<tests<<" trainings: "<<trainings<<endl;
}
DataSet::~DataSet()
{
	
}
bool DataSet::checkTextual(string inp){
  if(inp.length()*100>=data->size()/2)//we have a textual class!
    return true;
  return false;
}
double fromTextual(string str, int unique){
  return 0;	
}
double DataSet::getClass(bool train, int i){
  double ret=-1;
  string tmp;
  if(train)
    tmp = classes->at(trainCoords[i]);	
  else
    tmp = classes->at(testCoords[i]);
	
  ret = atof(tmp.c_str());
  return ret;
}
void DataSet::print(){
  cerr << "\ntest cases: \n\n";
  for(int i=0;i<tests;i++){
    int coord = testCoords[i];
    cerr << classes->at(coord) << " : ";
    printVector(data->at(coord));
  }
  cerr << "\ntraining cases: \n\n";
  for(int i=0;i<trainings;i++){
    int coord = trainCoords[i];
    cerr << classes->at(coord) << " : ";
    printVector(data->at(coord));
  }
	
}

