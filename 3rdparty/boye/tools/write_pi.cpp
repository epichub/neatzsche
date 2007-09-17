/********************************************************************
 *   		write_pi.cpp
 *   Created on Fri Jun 09 2006 by Boye A. Hoeverstad.
 *   
 *   Write out the value of PI.
 *******************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
      // By default, cout will only print a few decimals (~10?).
      // If using cout.presiction, the cout operator will print a
      // slightly different value than the one defined.  That's
      // why we use STRINGIZE.

#define DOSTRINGIZE(a) #a
#define STRINGIZE(a) DOSTRINGIZE(a)
  cout << "PI is #defined as M_PI in cmath and math.h with the value " 
       << STRINGIZE(M_PI) << ".\n";
  return 0;
}


