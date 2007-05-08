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
