#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <list>

using namespace std;

const char def_fname_h[] = "/home/boy/include/wrappers.h";
const char def_fname_cpp[] = "/home/boy/src/wrappers.cpp";
const char def_errtype[] = "-1";

int main(int argc, char *argv[])
{
      /* Get options */
  string proto, errtype, fname_h, fname_cpp, confirm;
  cout << "Function prototype: ";
  getline(cin, proto);
  cout << "\nError return value? (-1, 0, nz (=nonzero)) [" << def_errtype << "]: ";
  getline(cin, errtype);
  cout << "\nAdd to headerfile [" << def_fname_h << "]: ";
  getline(cin, fname_h);
  cout << "\nAdd to source file [" << def_fname_cpp << "]: ";
  getline(cin, fname_cpp);
  cout << "Do it? [y]";
  getline(cin, confirm);
  cout << endl; 
  
  if (confirm != "" && confirm != "y" && confirm!= "Y") return 0;
  if (fname_h == "") fname_h = def_fname_h;
  if (fname_cpp == "") fname_cpp = def_fname_cpp;
  if (errtype == "") errtype = def_errtype;

      /* Open files */
  fstream file_h(fname_h.c_str(), ios::ate | ios::in | ios::out);
  if (!file_h){
    cerr << "unable to open " << fname_h << " for writing and appending\n";
    return -1;
  }
  ofstream file_cpp(fname_cpp.c_str(), ios::app);
  if (!file_cpp){
    cerr << "unable to open " << fname_cpp << " for writing and appending\n";
    return -1;
  }

      /* Parse function name and prototype */
  while ( proto.find("  ") != string::npos )
    proto.replace(proto.find("  "), 2, " ");           // Remove double spaces
  if ( proto.find(";") != string::npos )
    proto.erase(proto.find(";"), 1);                   // Remove trailing semicolon
  string wrapper_proto = proto;
  int proto_name_pos = proto.find(" ")+1;
  wrapper_proto[proto_name_pos] = toupper(proto[proto_name_pos]); // Upcase function name
  string proto_name = proto.substr(proto_name_pos, proto.find("(")-proto_name_pos); // Separate function name
  list<string> proto_args;
  string::size_type arg_start = string::npos, arg_end;
  while( (arg_end = proto.find_last_of(",)", arg_start)) != string::npos){
    arg_start = proto.find_last_of("( *", arg_end);    // Create list of arguments
    proto_args.push_back(proto.substr(arg_start+1, arg_end-(arg_start+1)));
  }
  proto_args.reverse();                                // Reverse arguments to correct order
  
      /* Write header */
  file_h.seekp(-50, ios::end);
  char sztmp[51] = { 0 };                              // Ensure 0-terminated string
  file_h.read(sztmp, 50);                              // File pointer now back at end
  string tmp = sztmp;
  int pos;
  if ( (pos = tmp.find("#endif")) != string::npos ){
    if ( tmp.find("\n#endif") != string::npos )
      pos = tmp.find("\n#endif");
    file_h.seekp(-50+pos, ios::end);                   // Insert above "#endif"
  } else
    std::cerr << "Unable to find \"#endif\", appending to end of file.\n";
  file_h << wrapper_proto << ";\n" << tmp.substr(pos, tmp.size()-pos);

      /* Write source */
  file_cpp << '\n' << wrapper_proto << "\n{\n"
	   << "  VDBP(\"" << proto_name << "(\"";
  for (list<string>::const_iterator arg_it = proto_args.begin(); 
       arg_it != proto_args.end(); arg_it++){
    if (arg_it != proto_args.begin()) file_cpp << " << \", \"";
    file_cpp << " << " << *arg_it;
  }
  file_cpp << " << \")\");\n  " << proto.substr(0, proto.find(" ")) 
	   << " ret = " << proto_name << "(";
  for (list<string>::const_iterator arg_it = proto_args.begin(); 
       arg_it != proto_args.end(); arg_it++){
    if (arg_it != proto_args.begin()) file_cpp << ", ";
    file_cpp << *arg_it;
  }
  file_cpp << ");\n  VDBP(\" returns \" << ret << \".\\n\");\n  ";
  if (errtype == "0") file_cpp << "test_zero_exit(ret, \"" << proto_name << "\");\n";
  if (errtype == "-1") file_cpp << "test_mone_exit(ret, \"" << proto_name << "\");\n";
  if (errtype == "nz") file_cpp << "test_nonzero_exit(ret, \"" << proto_name << "\");\n";
  file_cpp << "  return ret;\n}\n";

  cout << "Done.\n";
  return 0;
}

