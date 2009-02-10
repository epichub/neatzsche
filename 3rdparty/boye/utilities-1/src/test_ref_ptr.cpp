/********************************************************************
 *   		test_ref_ptr.cpp
 *   Created on Mon Mar 19 2007 by Boye A. Hoeverstad.
 *   
 *   Test that the ref_ptr class behaves as it should.  There were
 *   some problems with assignment to self, which may (will) happen
 *   during a call to random_shuffle.
 *
 *   Run with no arguments, and check that the counter behaves as it
 *   should (may need some debug output in the ref_ptr class).
 *
 *******************************************************************/

#include <iostream>
#include <ref_ptr.h>
#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ref_ptr<int> p(new int);
  *p = 12;

  cerr << "\nAssign to self:\n";
  p = p;

  cerr << "\nFilling vector:\n";
  vector<ref_ptr<int> > v;
  v.push_back(p);
  v.push_back(p);

  cerr << "\nswap diff:\n";
  iter_swap(v.begin(), v.begin() + 1);
  cerr << "\nswap same:\n";
  iter_swap(v.begin(), v.begin());

  cerr << "\nshuffle:\n";
  random_shuffle(v.begin(), v.end());

  cerr << "\nFilling list:\n";
  list<ref_ptr<int> > l, el;
  l.push_back(p);
  l.push_back(p);

  cerr << "\nFilling deque:\n";
  deque<ref_ptr<int> > d;
  d.push_back(p);
  d.push_back(p);

  cerr << "\nswap diff:\n";
  iter_swap(d.begin(), d.begin() + 1);
  cerr << "\nswap same:\n";
  iter_swap(d.begin(), d.begin());

  cerr << "\nshuffle deque:\n";
  random_shuffle(d.begin(), d.end());

  cerr << "\nDone.\n\n";

  for (size_t i = 0; i < v.size(); i++)
    cout << *(v[i]) << "\t";
  cout << "\n";
  return 0;
}
