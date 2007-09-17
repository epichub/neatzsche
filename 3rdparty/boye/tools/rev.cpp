/********************************************************************
 *   		rev.cpp
 *   Created on Tue Feb 21 2006 by Boye A. Høverstad.
 *   
 *   Prints byte-by-byte reverse of standard input on standard output.
 *   Written because this utility is missing on Solaris.
 *******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  if ( argc != 1 )
  {
    cout << "\tUsage: rev.\n\tWill print standard input in reverse on standard output, byte-by-byte.  Written by Boye because this utility seems to be missing on Solaris.\n";
    return -1;
  }

  vector<char> buf;

  char c;
  while (cin.read(&c, 1))
    buf.push_back(c);

      // Chomp last newline from output
  assert(buf.back() == '\n');
  if (buf.back() == '\n')
    buf.pop_back();

  for (vector<char>::reverse_iterator it = buf.rbegin(); it != buf.rend(); it++)
    cout.write(&(*it), 1);

  return 0;  
}
