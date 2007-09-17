/********************************************************************
 *   		options.h
 *   Created on Fri Jul 05 2002 by Boye A. Hoeverstad.
 *   
 *   Parses options and settings for the program.  Takes as input two
 *   streams containing key-value lines, separated by a colon (:).
 *   Comments start with a pound sign (#).  The first input stream
 *   should contain all available options, with default values.  The
 *   second strem may contain user-specified option values which will
 *   overwrite the default values.
 *
 *******************************************************************/

#if !defined(__CONTROL_H__)
#define __CONTROL_H__

#include "feedback.h"

#include <iosfwd>
#include <map>
#include <string>
#include <list>

#if defined(DEBUG)
#include <set>
#endif

// extern FeedbackError E_OPTIONS_TYPE;
// extern FeedbackError E_OPTIONS_VALUE;
// extern FeedbackError E_OPTIONS_OPTION;

/********************************************************************
 *   Dummy C function for autoconf to find.
 *******************************************************************/
extern "C" void autotools_dummy ();


typedef struct TOptionDataVar
{
  std::string sDescription; // A user-friendly description of what the option means
  bool bMandatory; // True if the user must supply a value for this option.  False if the default value is enough.
  std::string sDefaultValue;
  std::string sValue;
  TOptionDataVar(const std::string &sDesc, bool bM, const std::string &sDefVal);
  TOptionDataVar();
} TOptionData;


class Options
{
  typedef std::map<std::string, TOptionData> TOptionSet;

# if defined(DEBUG)
  mutable std::set<std::string> used_opts;
# endif

  Feedback m_fb;
  TOptionSet m_opts;

  void Preprocess(std::istream &source, std::ostream &target);
  void ReadPreprocessed(std::istream &stripped, bool bAdd);

  Options();

  template<class T> int GetTypedOption(const std::string &sTypeDesc, const std::string &sKey, T &value) const;
public:
  static const char comment_char;
  static const char separator_char;

//   Options(std::istream &default_opts, std::istream &current_opts);
  static Options &Instance(); 
  ~Options();

      // Assign or append options: Define the available options
      // (keys), together with description and default value.
  void Assign(const std::list<std::pair<std::string, TOptionData> > &options);
  void Append(const std::string &sKey, const TOptionData &option);

      // Read options from stream.  New keys are not created, only
      // existing keys will be assigned new values.
  void Read(std::istream &opts);

  int Option(const std::string &sKey, std::string &sValue) const;
  int Option(const std::string &sKey, int &nValue) const;
  int Option(const std::string &sKey, float &fValue) const;
  int Option(const std::string &sKey, bool &bValue) const;

  std::string PrintValues() const;
  std::string PrettyPrint() const;


# if defined(DEBUG)
  std::string PrintUnused() const;
# endif
};

#endif



