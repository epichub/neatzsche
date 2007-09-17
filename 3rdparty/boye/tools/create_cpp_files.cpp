#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <algorithm>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

using namespace std;

void comment(ofstream &f, const string &filename, bool header_file)
{
  const int line_len = 70;
  char stars[line_len-2], text[256],
    line_start[] = " *   \0", datefmt[64];
  time_t now = time(0);
  strftime(datefmt, 64, "%a %b %d %Y", localtime(&now));
  memset(stars, '*', line_len-3);
  stars[line_len-3] = 0;
  if (header_file)
    sprintf(text, "%s\t\t%s\n%sCreated on %s by Boye A. Hoeverstad.\n%s\n%sTODO: Insert description here.",
            line_start, filename.c_str(), line_start, datefmt, line_start, line_start);
  else
    sprintf(text, "%s\t\t%s\n%sCreated on %s by Boye A. Hoeverstad.\n%s\n%sSee header file for description.",
            line_start, filename.c_str(), line_start, datefmt, line_start, line_start);
  f << "/*" << stars << "\n" << text << "\n " << stars << "/\n\n";
}

void arguments(ofstream &f)
{
  f << "bool bVerbose = false;\n\n"
    << "int\n"
    << "parse_arguments(int argc, char *argv[])\n"
    << "{\n"
    << "  struct option opts[] = {\n"
    << "    {\"arg\"      , required_argument, 0, 'a'},\n"
    << "    {\"noarg\"    , no_argument,       0, 'n'},\n"
    << "    {\"opt\"      , optional_argument, 0, 'o'},\n"
    << "    {\"verbose\"  , no_argument,       0, 'v'},\n"
    << "    { 0 }};\n\n"
    << "      // Adding a + to the opstring to avoid permuting the option string.\n"
    << "  int ch;\n"
    << "  while ((ch = getopt_long(argc, argv, \"+a:no:v\", opts, 0)) != -1)\n"
    << "  {\n"
    << "    switch (ch)\n"
    << "    {\n"
    << "        case 'a':\n"
    << "          break;\n"
    << "        case 'v':\n"
    << "          bVerbose = true;\n"
    << "          break;\n"
    << "        default:\n"
    << "          std::cerr << \"Unregonized option: \" << static_cast<char>(optopt) << \".\\n\";\n"
    << "          return 1;\n"
    << "    }\n"
    << "  }\n"
    << "  return 0;\n"
    << "}\n\n\n";
}

struct supper : unary_function<char, char>
{
  char operator() (const char c)
  {
    return toupper(c);
  }
};


void create(const string &filename)
{
  string cpp_name = filename + ".cpp";
  string h_name = filename + ".h";
  
  std::ifstream cppifile(cpp_name.c_str()), hifile(h_name.c_str());
  if (cppifile.is_open())
  {
    cerr << "File exists: " << cpp_name << ".\n";
    return;
  }

  if (hifile.is_open())
  {
    cerr << "File exists: " << h_name << ".\n";
    return;
  }

  std::ofstream cppfile(cpp_name.c_str()), hfile(h_name.c_str());
  if (!cppfile.is_open())
  {
    cerr << "Failed to create/open " << cpp_name << " for writing.\n";
    return;
  }
  if (!hfile.is_open())
  {
    cerr << "Failed to create/open " << h_name << " for writing.\n";
    return;
  }

  comment(cppfile, cpp_name, false);
  cppfile << "#include \"" << h_name << "\"\n"
          << "#include <iostream>\n"
          << "#include <getopt.h>\n"
          << "using namespace std;\n\n";
  arguments(cppfile);
  cppfile << "int\n"
          << "main(int argc, char *argv[])\n"
          << "{\n"
          << "  if (parse_arguments(argc, argv))\n"
          << "  {\n"
          << "    cerr << \"Usage: \" << argv[0] << \" [--verbose | -v]\\n\";\n"
          << "    return 1;\n"
          << "  }\n\n"
          << "  return 0;\n"
          << "}\n";
  
  cout << "Created file " << cpp_name << ".\n";

  string H_DEF = "__" + filename + "_h__";
  
  transform(H_DEF.begin(), H_DEF.end(), H_DEF.begin(), supper());
  comment(hfile, h_name, true);
  hfile << "#if !defined(" << H_DEF << ")\n"
        << "#define " << H_DEF << "\n\n\n"
        << "#endif\n";

  cout << "Created file " <<  h_name << ".\n";
}

int main(int argc, char **argv)
{
  if (argc > 1)
    for (int arg=1; arg<argc; arg++)
      create(argv[arg]);
  else
  {
    cout << "filename? ";
    string name;
    cin >> name;
    create(name);
  }
  return 0;
}












