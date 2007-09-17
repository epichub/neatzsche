//  #if defined(LINUX)
#include <time.h>
//  #else
//  #include <sys/time.h>
//  #endif
#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char **argv)
{
  char command[256] = "make";
  if (argc > 1)
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--h") ||
	!strcmp(argv[1], "-?") || !strcmp(argv[1], "--?") ||
	!strcmp(argv[1], "--help")){
      std::cout << "Timed version of make.  See \"make\" for all other options.\n";
      return 0;
    } else
      for (int arg=1; arg<argc; arg++)
	std::sprintf(command, "%s %s", command, argv[arg]);

  std::cout << command << std::endl;

  time_t start = time(0);
  system(command);
  time_t end = time(0);

  std::cout << "Time for make: " << end - start << " seconds.\n";
  return 0;
}
