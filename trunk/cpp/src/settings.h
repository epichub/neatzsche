#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <stdlib.h>
#include <map>
#include <iostream>
#include <vector>

using namespace std;
typedef map<string,double> settingsMap;
typedef vector<string> settingsFile;

class NEATsettings
{
private:
  settingsMap values;
  settingsFile file;
  int structmutcount;
public:
  NEATsettings();
  NEATsettings(NEATsettings * set);
  ~NEATsettings(){};
  double getValue(string key);
  NEATsettings * duplicate(){return new NEATsettings(this);}
  void setIfNotSet(string key, double v);
  void setValue(string key, double v);
  void prettyprint();
  void addTopComment(string s);
  int getstructmutcount(){return structmutcount;}
  void incstructmutcount(){structmutcount++;}
  friend istream& operator>> (istream& is, NEATsettings *g);      //operators to save to and load from file
  friend ostream& operator<< (ostream& os, NEATsettings *g);      //...
};
#endif
