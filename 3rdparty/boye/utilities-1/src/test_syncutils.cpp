/********************************************************************
 *   		test_syncutils.cpp
 *   Created on Thu Mar 15 2007 by Boye A. Hoeverstad.
 *   
 *   Producer/consumer program to test MemoryPipe (which in turn tests
 *   the Condition class).  Reads from stdin, streams via MemoryPipe,
 *   and writes to stdout.
 *
 *   Run as follows:
 *
 *   c=check_syncutils.txt; for f in *.cpp *.h; do ./test-syncutils <$f >$c; if [ -z "`diff $f $c`" ]; then echo "Passed: $f."; else echo "TEST FAILED: $f:"; diff $f $c; fi; done; rm $c
 *
 *******************************************************************/

#include <syncutils.h>
#include <misc_utils.h>
#include <iostream>
#include <cassert>

using namespace std;

const int bufsizePipe = 10;
const int bufsizeRead = 17;
const int bufsizeWrite = 8;

MemoryPipe mpipe(bufsizePipe);

vector<char> produce(int nBufSize)
{
//   vector<char> v(nBufSize);
//   cin.read(&(v[0]), nBufSize);
//   v.resize(cin.gcount());
  string s;
  cin >> s;
  vector<char> v(s.size());
  copy(s.begin(), s.end(), v.begin());
  return v;
}

void append(const vector<char> &v)
{
  mpipe.Write(&(v[0]), v.size());
}

vector<char> take(int nBufSize)
{
  vector<char> v(nBufSize);
  ssize_t nRead = mpipe.Read(&(v[0]), nBufSize);
  v.resize(nRead);
  return v;
}

void consume(const vector<char> &v)
{
  for (size_t i = 0; i < v.size(); i++)
    cout.put(v[i]);
}

void* producer(void*)
{
  while (cin)
  {
    vector<char> v = produce(bufsizeRead);
    if (!cin && v.empty())
      break;
    append(v);
  }
  mpipe.Close();
  return 0;
}


void* consumer(void*)
{
  while(true)
  {
    vector<char> v = take(bufsizeWrite);
    if (v.size() == 0)
    {
      assert(!mpipe.IsOpen());
      break;
    }
    consume(v);
  }
  return 0;
}


int main(int argc, char *argv[])
{
  pthread_t tid1, tid2;
//  std::cerr << "Creating threads.\n";
  pthread_create(&tid1, 0, producer, 0);
  pthread_create(&tid2, 0, consumer, 0);

  pthread_join(tid1, 0);
  pthread_join(tid2, 0);

  return 0;    
}

