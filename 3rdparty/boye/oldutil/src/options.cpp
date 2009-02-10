/********************************************************************
 *   		options.cpp
 *   Created on Fri Jul 05 2002 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include <options.h>

#include <sstream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <iostream>
#include <locale>


/********************************************************************
 *   Dummy C function for autoconf to find.
 *******************************************************************/
extern "C" void autotools_dummy () {}

// FeedbackError E_OPTIONS_TYPE("Option cannot be converted to the requested type");
DEFINE_FEEDBACK_ERROR(E_OPTIONS_TYPE, "Option cannot be converted to the requested type")
// FeedbackError E_OPTIONS_VALUE("A mandatory option has not been given a value");
DEFINE_FEEDBACK_ERROR(E_OPTIONS_VALUE, "A mandatory option has not been given a value")
// FeedbackError E_OPTIONS_OPTION("Request for non-existing option");
DEFINE_FEEDBACK_ERROR(E_OPTIONS_OPTION, "Request for non-existing option")


using namespace std;

const char Options::comment_char    = '#';
const char Options::separator_char  = ':';


TOptionDataVar::TOptionDataVar(const std::string &sDesc, bool bM, const std::string &sDefVal)
    : sDescription(sDesc), bMandatory(bM),
      sDefaultValue(sDefVal)
{
}


TOptionDataVar::TOptionDataVar()
    : bMandatory(false)
{
}


// Options::Options(istream &default_opts, istream &current_opts)
//     : m_fb("Options")
// {
//   read_options(default_opts, true);
//   read_options(current_opts, false);
// }

Options::Options()
    : m_fb("Options")
{
}

Options::~Options()
{
}

Options&
Options::Instance()
{
      // Static function variables are always initialized.
      // Static global c++ object variables in shared objects are
      // not correctly constructed on some platforms.
  static Options instance; 

  return instance;
}


void
Options::Assign(const std::list<std::pair<std::string, TOptionData> > &options)
{
  m_opts.clear();
  for (std::list<std::pair<std::string, TOptionData> >::const_iterator opt_it = options.begin();
       opt_it != options.end(); opt_it++)
    Append(opt_it->first, opt_it->second);
}

void
Options::Append(const std::string &sKey, const TOptionData &option)
{
  m_opts[sKey] = option;
}



/********************************************************************
 *   Preprocess a file: Remove trailing blanks, comments, comment
 *   lines and empty lines.  Prepend each line that passes
 *   preprocessing with a number indicating the line number in the
 *   original file, so that the parsing routine may give better
 *   feedback to the user in case of an error.
 *******************************************************************/
void
Options::Preprocess(istream &source, ostream &target)
{
  const char cSpace = ' ';

  std::string sLine;
  int nCurLine = 0;
  while(std::getline(source, sLine))
  {
    nCurLine++;
        // Cut off everything after and including the comment character
    std::string::size_type nCommentPos = sLine.find(comment_char);
    if (nCommentPos != std::string::npos)
      sLine.resize(nCommentPos);

        // Replace all spaces, tabs etc with normal space
    for (size_t i = 0; i < sLine.size(); i++)
      if (isspace(sLine[i])) sLine[i] = cSpace;

        // Remove leading spaces
    std::string::size_type nCharPos = sLine.find_first_not_of(cSpace);
    if (nCharPos == std::string::npos)
      continue;
    sLine = sLine.substr(nCharPos);
    
    if (sLine.empty())
      continue;

        // Remove trailing spaces
    sLine.resize(sLine.find_last_not_of(cSpace) + 1);

    target << nCurLine << "\n" << sLine << endl;
  }
}


void
Options::Read(istream &options)
{
  stringstream stripped;
  Preprocess(options, stripped);

  std::string sLine, sLineNum;
  while(std::getline(stripped, sLineNum) && std::getline(stripped, sLine))
  {
    std::stringstream ssLineNum(sLineNum);
    int nCurLine;
    ssLineNum >> nCurLine;

    string::size_type opt_pos, val_pos;
    if (((opt_pos = sLine.find_first_of(separator_char)) != string::npos)
        && ((val_pos = sLine.find_first_not_of(" ", opt_pos+1)) != string::npos)) {
      string key = sLine.substr(0, opt_pos);
      TOptionSet::iterator key_it = m_opts.find(key);
      if (key_it != m_opts.end())
        key_it->second.sValue = sLine.substr(val_pos, sLine.size() - val_pos);
      else 
        m_fb.Warning() << "Invalid option on line " << nCurLine << " (Does not exist in default options file). Option skipped:\n"
             << sLine << "\n";
    } else 
      m_fb.Warning() << "Erroneous option on line " << nCurLine << " (skipping): \n" << sLine << "\n";
  }
}


int
Options::Option(const string &sKey, string &sValue) const
{
  TOptionSet::const_iterator key_it = m_opts.find(sKey);
  if (key_it == m_opts.end())
    return m_fb.Error(E_OPTIONS_OPTION) << " \"" << sKey << "\".";

# if defined(DEBUG)
  const_cast<set<string>* >(&used_opts)->insert(key_it->first);
# endif

  sValue = key_it->second.sValue;
  if (sValue.empty())
  {
    if (key_it->second.bMandatory)
      return m_fb.Error(E_OPTIONS_VALUE) << ": " << sKey << ".";
    sValue = key_it->second.sDefaultValue;
  }
  return 0;
}


template<class T> int
Options::GetTypedOption(const std::string &sTypeDesc, const string &sKey, T &value) const
{
  std::string sValue;
  if (int nRet = Option(sKey, sValue))
    return nRet;

  if (sValue.empty())
    return m_fb.Error(E_OPTIONS_TYPE) << ": Cannot convert an empty string to "
      + sTypeDesc + " (option: " + sKey + ").";

  std::stringstream ss(sValue);
  ss >> value;
  if (ss.fail() || !ss.eof())
    return m_fb.Error(E_OPTIONS_TYPE) << ": Failed to convert \"" + sValue + "\" to "
      + sTypeDesc + " (option: " + sKey + ").";

  return 0;
}


int
Options::Option(const string &sKey, int &nValue) const 
{
  return GetTypedOption("integer", sKey, nValue);
}


int
Options::Option(const string &sKey, float &fValue) const 
{
  return GetTypedOption("floating point", sKey, fValue);
}


int
Options::Option(const std::string &sKey, bool &bValue) const
{
  std::string sValue;
  if (int nRet = Option(sKey, sValue))
    return nRet;

  if (sValue.empty())
    return m_fb.Error(E_OPTIONS_TYPE) << ": Cannot convert an empty string to boolean (option: "
      + sKey + ").";

  if (sValue != "true" && sValue != "false")
    return m_fb.Error(E_OPTIONS_TYPE) << ": Failed to convert \"" + sValue 
      + "\" to boolean (option: " + sKey + ").";

  bValue = sValue == "true";

  return 0;
//   return GetTypedOption("boolean", sKey, fValue);
}


string
Options::PrintValues() const 
{
  stringstream s;
  ios::fmtflags old_flags = s.flags();
  s.setf(ios::left, ios::adjustfield);
  for (TOptionSet::const_iterator op_it = m_opts.begin(); op_it != m_opts.end(); op_it++)
  {
    s << setw(35) << op_it->first + ":" << "\t";
    if (op_it->second.sValue.empty())
      s << setw(15) << op_it->second.sDefaultValue << "\t(default)\n";
    else
      s << setw(15) << op_it->second.sValue << "\t(user specified)\n";
  }
  s.flags(old_flags);
  return s.str();
}

std::string
Options::PrettyPrint() const
{
  stringstream s;
  ios::fmtflags old_flags = s.flags();
  s.setf(ios::left, ios::adjustfield);
//   s << setw(35) << "Key" << setw(15) << "Value (default)" << setw(10) "Mandatory" << "Description\n";
  for (TOptionSet::const_iterator op_it = m_opts.begin(); op_it != m_opts.end(); op_it++)
  {
    string sOption = (op_it->second.bMandatory ? "" : "[") 
      + op_it->first + (op_it->second.bMandatory ? "" : "]");
    string sDesc = op_it->second.sDescription;
    if (!sDesc.empty() && sDesc[sDesc.size()-1] != '.')
      sDesc += ".";
    s << setw(35) << sOption << "\t" << sDesc << " Default value: \"" << op_it->second.sDefaultValue << "\".\n";
  }
  s.flags(old_flags);
  return s.str();
}


#if defined(DEBUG)
string 
Options::PrintUnused() const 
{
  stringstream unused_ss;
  unused_ss.setf(ios::left, ios::adjustfield);
  for (TOptionSet::const_iterator op_it = m_opts.begin(); op_it != m_opts.end(); op_it++)
    if (used_opts.find(op_it->first) == used_opts.end())
      unused_ss << setw(35) << op_it->first.c_str() << "\t" << op_it->second.sValue << "\n";
  return unused_ss.str();
}
#endif
