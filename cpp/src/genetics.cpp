#include "genetics.h"

Innovation * Innovations::getInnovation(int innovationnumber)
{
  for(unsigned int i=0;i<q->size();i++)
    if(q->at(i)->getNum()==innovationnumber)
      return q->at(i);
  return NULL;
}
Innovations::~Innovations()
{
  for(unsigned int i=0;i<q->size();i++)
    delete q->at(i);
  delete q;
}
ostream& operator<< (ostream& os, const Innovation *i)
{
  os << (char)(i->type) << " " << i->from_id << " " << i->to_id << " " << i->innonum
     << " " << i->innonum2 << " " << i->neww << " " << i->nodeid 
     << " " << i->oldinnonum << endl;
  return os;
}
istream& operator>> (istream& is, Innovation *i)
{
  string s;
  is >> s; i->type = s[0];
  is >> s; i->from_id = atoi(s.c_str());
  is >> s; i->to_id = atoi(s.c_str());
  is >> s; i->innonum = atoi(s.c_str());
  is >> s; i->innonum2 = atoi(s.c_str());
  is >> s; i->neww = atof(s.c_str());
  is >> s; i->nodeid = atoi(s.c_str());
  is >> s; i->oldinnonum = atoi(s.c_str());
  return is;
}
// ostream& operator<< (ostream& os, const Innovations *i)
// {
//   os << "in" << endl;
//   os << i->curinnovnum << endl;
//   for(unsigned int c=0;c<i->q->size();c++)
//     os << "innov " << i->q->at(c) << endl;
//   os << "inend" << endl;
//   return os;
// }
istream& operator>> (istream& is, Innovations *i)
{
  string s;
  is >> s; i->curinnovnum = atoi(s.c_str());
  is >> s;
  while(s.find("innov")!=string::npos){
    Innovation * in = new Innovation();
    is >> in;
    i->addInnovation(in);
    is >> s;
  }
  return is;
}
void Innovations::prune()
{
  //  cout << "in prune..." << endl;
  if(q->size()<=(unsigned int)numtokeep)
    return;
  innovationVector::iterator start = q->begin();
  int c=q->size()-numtokeep;
  while(c--){
    delete *start;
    start = q->erase(start);
  }
}
