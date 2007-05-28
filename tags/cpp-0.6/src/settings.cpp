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
#include "settings.h"

using namespace std;
void NEATsettings::addTopComment(string s)
{
  s = "#" + s;
  file.insert(file.begin(),s);
}
double NEATsettings::getValue(string key)
{
  return values[key];
}

ostream& operator<< (ostream& os, NEATsettings *g)
{
  settingsMap::iterator pos = (g->values).begin();
  for(unsigned int i=0;i<g->file.size();i++){
    if(g->file.at(i).find("#")!=string::npos)
      os << g->file.at(i) << endl;
    else
      os << g->file.at(i) << " " << g->values[g->file.at(i)] << endl;
  }
  return os;
}

istream& operator>> (istream& is, NEATsettings *g)
{
  string tmp = "";
  string key = "";
  int msize = 255;
  char chararr[msize];
  while(!is.eof()){
    is >> key;
    if(key.find("#")!=string::npos){
      //this config file line seems to be a comment
      is.getline(chararr,msize);//read to end of line
      tmp = key; tmp += string(chararr);
      g->file.push_back(tmp);
    }else{
      g->file.push_back(key);
      is >> tmp;
      g->values[key] = atof(tmp.c_str());
    }
  }
  g->file.pop_back();
  //  }
  return is; 
}
void NEATsettings::setIfNotSet(string key, double v)
{
  if(values.count(key)>0)
    return;
  values[key] = v;
}
void NEATsettings::setValue(string key, double v)
{
  values[key] = v;
}
NEATsettings::NEATsettings()
{
  //there should be default settings here..(or in a default file?)
  structmutcount = 0;
}
NEATsettings::NEATsettings(NEATsettings * set)
{
  for(unsigned int i=0;i<set->file.size();i++){
    if(set->file.at(i).find("#")!=string::npos)
      file.push_back(set->file.at(i));
    else{
      file.push_back(set->file.at(i));
      values[set->file.at(i)] = set->getValue(set->file.at(i));
    }
  }
}
void NEATsettings::prettyprint()
{
  settingsMap::iterator pos = values.begin();
  for (; pos != values.end(); ++pos)
    cerr << pos->first << " = " << pos->second<<endl;
}
