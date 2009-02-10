
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

bool open_ok(int file, char *name)
{
  if ( file != -1 ) return true;

  if (errno == EEXIST)
    fprintf(stderr, "File exists: %s\n", name);
  else{
    char buf[64];
    sprintf(buf, "Error creating node %s", name);
    perror(buf);
  }
  return false;
}

bool fdopen_ok(FILE *file)
{
  if ( file != NULL ) return true;

  char buf[64];
  sprintf(buf, "fdopen failed");
  perror(buf);
  return false;
}

void create(char *filename)
{
  char *cpp_name = new char[strlen(filename)+4];
  char *h_name = new char[strlen(filename)+2];
  sprintf(cpp_name, "%s.cpp", filename);
  sprintf(h_name, "%s.h", filename);


  int cfd = open(cpp_name, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  int hfd = open(h_name, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  if (!open_ok(cfd, cpp_name) || !open_ok(hfd, h_name)) return;

  FILE *cf, *hf;
  if (!fdopen_ok((cf = fdopen(cfd, "w"))) || 
      !fdopen_ok((hf = fdopen(hfd, "w")))) return;

  char *CPP_DEF = new char[strlen(filename)+8];
  memset(CPP_DEF, 0, strlen(filename)+8);
  strcpy(CPP_DEF, "__");
  for (int let=0; let<strlen(filename); let++)
    CPP_DEF[strlen(CPP_DEF)] = toupper(filename[let]);
  strcat(CPP_DEF, "_CPP__");

  fprintf(cf, "#if !defined(%s)\n#define %s\n\n", CPP_DEF, CPP_DEF);
  fprintf(cf, "#include \"%s\"\n#include <iostream>\nusing namespace std;\n\n", h_name);
  fprintf(cf, "int main(int argc, char *argv[])\n{\n\n}\n");
  fprintf(cf, "\n\n#endif");
  fclose(cf);

  char *H_DEF = new char[strlen(filename)+6];
  memset(H_DEF, 0, strlen(filename)+6);
  strcpy(H_DEF, "__");
  for (int let=0; let<strlen(filename); let++)
    H_DEF[strlen(H_DEF)] = toupper(filename[let]);
  strcat(H_DEF, "_H__");

  fprintf(hf, "#if !defined(%s)\n#define %s\n\n\n#endif\n", H_DEF, H_DEF);
  fclose(hf);

  delete[] CPP_DEF;
  delete[] H_DEF;
}

int main(int argc, char **argv)
{

  if (argc > 1)
    for (int arg=1; arg<argc; arg++)
      create(argv[arg]);
  else{
    fprintf(stdout, "filename? ");
    const int STRLEN = 256;
    char name[STRLEN];
    read(fileno(stdin), name, STRLEN);;
    create(name);
  }
  return 0;
}
