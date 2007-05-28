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

#ifndef STATECHANGES_H_
#define STATECHANGES_H_
#include <boost/dynamic_bitset.hpp>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
class StateChange;

typedef boost::dynamic_bitset<> state;
typedef vector<StateChange*> states;

class StateChange
{
private:
  state from;
  state to;
  unsigned int times;
  state firstcoord;
  state secondcoord;
  bool first;
public:
  StateChange(state & ifrom, state & ito, state & ifirstcoord,
	      state& isecondcoord, bool ifirst)
  {from=ifrom; to=ito;times=1;firstcoord=ifirstcoord; secondcoord=isecondcoord; first = ifirst;}
  ~StateChange(){};
  void inc(){times++;}
  void reset(){times = 1;}
  unsigned int getTimes(){return times;}
  state & getTo(){return to;}
  state & getFirstCoord(){return firstcoord;}
  state & getSecondCoord(){return secondcoord;}
  friend bool operator==(const StateChange & first, const StateChange & second)
  {return (first.from==second.from);} 
  friend bool operator==(const StateChange & first, const state & from)
  {
    return (first.from==from);} 
  friend bool operator<(const StateChange & first, const StateChange & second)
  {return first.times<second.times;}
  friend ostream& operator<<(ostream& os, const StateChange * sc){ os << "from: " << sc->from << " to: " << sc->to; return os;}
  string prettyprint() {stringstream ss; ss << this << " times: " << times; return ss.str();}
};

class StateChanges
{
private:
  unsigned int num;
  unsigned int ql;
  states sc;
  states scq;
  states::iterator find(state & from);
  states::iterator findInQueue(state & from);
  void upgrade(states::iterator it);
  void insertSorted(StateChange * s);
  void pruneQueue();
public:
  StateChanges(unsigned int inum, unsigned int iql)
  {num=inum;ql=iql;}
  ~StateChanges();
  StateChange * get(state from);
  void add(state & from, state & to, state & ifirstcoord,
	      state& isecondcoord, bool ifirst);
  string prettyprint();
};

#endif
