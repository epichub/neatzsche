#include "statechanges.h"
states::iterator StateChanges::find(state & from)
{
  states::iterator it = sc.begin();  
  while(it!=sc.end()){
    if(*(*it)==from){
      return it;
    }else
      it++;
  }
  return sc.end();
}
states::iterator StateChanges::findInQueue(state & from)
{
  states::iterator it = scq.begin();  
  while(it!=scq.end()){
    if(*(*it)==from){
      return it;
    }else
      it++;
  }
  return scq.end();
}
void StateChanges::upgrade(states::iterator it)
{
  sc.push_back(*it);
  scq.erase(it);
  if(sc.size()>num){
    states::iterator rit = sc.end();
    rit--;
    sc.erase(rit);
    (*rit)->reset();
    scq.push_back((*rit));
  }
}
void StateChanges::add(state & from, state & to, state & firstcoord,
	      state& secondcoord, bool first)
{
  StateChange * newsc = new StateChange(from,to,firstcoord,secondcoord,first);
  scq.push_back(newsc);
  pruneQueue();
}
StateChange * StateChanges::get(state from)
{
  StateChange * ret = NULL;
  states::iterator sq = findInQueue(from);  
  if(sq!=scq.end()){
    (*sq)->inc();
    ret = *sq;
    upgrade(sq);
    return ret;
  }
  states::iterator s = find(from);
  if(s!=sc.end()){
    (*s)->inc();
    StateChange * ss = (*s);
    ret = ss;
    sc.erase(s);
    insertSorted(ss);
  }
  return ret;
}
void StateChanges::pruneQueue()
{
  if(scq.size()>ql){
    delete *scq.begin();
    scq.erase(scq.begin());
  }
}
void StateChanges::insertSorted(StateChange * s)
{
  states::iterator it = sc.begin();
  while(it!=sc.end()&&(*it)->getTimes()>s->getTimes())
    it++;
  if(it==sc.end())//back at the end
    sc.push_back(s);
  else{//upgrade!
    sc.insert(it,s);
  }
}
string StateChanges::prettyprint()
{
  stringstream ss;
  ss << "size: " << num << " queue length " << ql << endl;
  ss << "sorted top list:" << endl;
  for(unsigned int i=0;i<sc.size();i++)
    ss << "\t " << (i+1) << ": " << sc.at(i)->prettyprint() << endl; 
  ss << "queue from front to back:" << endl;
  for(unsigned int i=0;i<scq.size();i++)
    ss << "\t " << (i+1) << ": " << scq.at(i)->prettyprint() << endl;
  return ss.str();
}
StateChanges::~StateChanges()
{
  for(unsigned int i=0;i<sc.size();i++)
    delete sc.at(i);
  for(unsigned int i=0;i<scq.size();i++)
    delete scq.at(i);
}
