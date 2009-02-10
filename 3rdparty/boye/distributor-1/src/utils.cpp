/********************************************************************
 *   		utils.cpp
 *   Created on Mon May 22 2006 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include "utils.h"

// #include <set>
// #include <vector>
// #include <iostream>
// #include <fstream>
// #include <ext/stdio_filebuf.h>

// #include <sys/types.h>
// #include <signal.h>
// #include <sys/wait.h>
// #include <sys/fcntl.h>
// #include <errno.h>

#include <unistd.h>
#include <algorithm>
#include <functional>

// FeedbackError E_UTILS_READJOB("Failed to read job data from child process");
DEFINE_FEEDBACK_ERROR(E_UTILS_READJOB, "Failed to read job data from child process");
// FeedbackError E_UTILS_WRITEJOB("Failed to write job data to child process");
DEFINE_FEEDBACK_ERROR(E_UTILS_WRITEJOB, "Failed to write job data to child process");



/********************************************************************
 *   Custom substring matching function.  In addition to searching
 *   data for containing delimiter, it also accepts part of the
 *   delimiter iff this is found at the very end of the data string.
 *
 *   The return value is an iterator pointing to the position where a
 *   match starts.  If no match is found, dataEnd is returned.
 *
 *   To see if the entire delimiter is found, compare length of
 *   delimiter to distance(returned iterator, dataEnd).
 *******************************************************************/
template<class it1, class it2>
it1 MatchDelim(it1 dataBegin, it1 dataEnd, it2 delimBegin, it2 delimEnd)
{
  for (; dataBegin != dataEnd; dataBegin++)
  {
    if (*dataBegin == *delimBegin)
    {
      it1 dataCur = dataBegin;
      it2 delimCur = delimBegin;
      while (*dataCur == *delimCur)
      {
        if (++dataCur == dataEnd || ++delimCur == delimEnd)
          return dataBegin;
      }
    }
  }

  return dataEnd;
}


/********************************************************************
 *   Optimized reading function: Read as large chunks as possible each
 *   time.  We can read at most as much as the length of the delimiter
 *   at once.
 *******************************************************************/
int ReadDelimData(Feedback &fb, std::istream &s, std::string &sData, const std::string &sDelim)
{
  if (sDelim.empty())
    return fb.Error(E_UTILS_READJOB) << ": Empty delimiter.";
  
  const size_t nDelimLen = sDelim.size();
  char buf[nDelimLen + 1];
  s.read(buf, nDelimLen);
  if (s.gcount() != std::streamsize(nDelimLen) || s.eof() || !s.good())
    return 1;

  int nCtr = 0;
  char *mit;
  while((mit = MatchDelim(buf, buf + nDelimLen, sDelim.begin(), sDelim.end())) != buf)
  {
    nCtr++;
    sData.append(buf, mit - buf);
    size_t nSubMatch = buf + nDelimLen - mit;
    if (nSubMatch > 0)
      memmove(buf, mit, nSubMatch);
    s.read(buf + nSubMatch, nDelimLen - nSubMatch);
    if (s.gcount() != std::streamsize(nDelimLen - nSubMatch) || s.eof() || !s.good())
    {
      buf[std::max(nDelimLen, nSubMatch + static_cast<size_t>(s.gcount()))] = 0;
      return 1;
    }
  }
  return 0;
}
    

int 
ReadJobData(Feedback &fb, std::istream &s, const std::string &sChildOutputMode, std::string &sData)
{
  std::stringstream ssMode(sChildOutputMode);
  std::string sMode1;
  ssMode >> sMode1;

  sData.clear();
  if (sMode1 == "EOF")
  {
    std::string sLine, sEOF;
    if (!std::getline(s, sEOF))
      return fb.Error(E_UTILS_READJOB) << ": Failed to read leading EOF mark.  No more jobs?";
    if (int nRet = ReadDelimData(fb, s, sData, "\n" + sEOF + "\n"))
      return nRet;
  }
  else if (sMode1 == "BYTES")
  {
    size_t nBytes;
    s.read(reinterpret_cast<char*>(&nBytes), sizeof(nBytes));
    if (s.gcount() != sizeof(nBytes))
      return fb.Error(E_UTILS_READJOB) << ": Failed to read byte count.";
    std::vector<char> v(nBytes);
    s.read(&(v[0]), nBytes);
    sData.resize(nBytes);
    std::copy(v.begin(), v.end(), sData.begin());
   if (s.gcount() != nBytes)
      return fb.Error(E_UTILS_READJOB) << ": Failed to read " << nBytes << " bytes of job data.";
  }
  else if (sMode1 == "BIN-EOF")
  {
    int nTagLen;
    ssMode >> nTagLen;
    std::vector<char> tag(nTagLen);
    s.read(&tag[0], nTagLen);
    if (s.gcount() != nTagLen)
      return fb.Error(E_UTILS_READJOB) << ": Failed to read " << nTagLen << " bytes of leading binary eof tag.";
    if (int nRet = ReadDelimData(fb, s, sData, std::string(&tag[0])))
      return nRet;
  }
  else if (sMode1 == "SIMPLE")
  {
    int nNumLines;
    ssMode >> nNumLines;
    if (nNumLines < 0 || nNumLines > 10000)
      return fb.Error(E_UTILS_READJOB) << "Won't obey instructions to read " << nNumLines << " lines of result data.";

    std::string sLine;
    for (int nLine = 0; nLine < nNumLines; nLine++)
    {
      if (!std::getline(s, sLine))
        return fb.Error(E_UTILS_READJOB) << ": No more jobs?";
      sData += (nLine ? "\n" : "") + sLine;
    }
  }
  else
    return fb.Error(E_UTILS_READJOB) << ": Unknown message mode: " << sMode1 << ".";

  fb.Info(4) << "Read message in " << sChildOutputMode << " mode: " << sData << ".";
  return 0;
}


/********************************************************************
 *   Increment a sequence interpreted as an unsigned number of
 *   any size.  The elements in the sequence MUST be unsigned for
 *   this algorithm to work (but I'm not quite sure how to
 *   enforce that, while still keeping the algorithm as a
 *   template.  A run-time test such as "assert(*itEnd >= 0)"
 *   gives a warning, saying that this test will always be true
 *   for unsigned numbers).
 *******************************************************************/
template<class T>
void IncSequence(T itBegin, T itEnd)
{
  if (itEnd == itBegin)
    return;
  itEnd--;
  ++(*itEnd);
  if (*itEnd == 0)
    IncSequence(itBegin, itEnd);
}


int
WriteJobData(Feedback &fb, std::ostream &s, const std::string &sChildInputMode, std::string sData)
{
  std::stringstream ssMode(sChildInputMode);
  std::string sMode1;
  ssMode >> sMode1;

  std::string sMessage;
  if (sChildInputMode == "EOF")
  {
    std::stringstream ssEOF;
    ssEOF << "EOF";
    while (sData.find(ssEOF.str()) != std::string::npos)
      ssEOF << "-" << rand();
    sMessage = ssEOF.str() + "\n" + sData + "\n" + ssEOF.str() + "\n";
  }
  else if (sMode1 == "SIMPLE")
    sMessage = sData + "\n";
  else if (sChildInputMode == "BYTES")
  {
    size_t nBytes = sData.size();
    std::stringstream ssBytes;
    ssBytes.write(reinterpret_cast<char*>(&nBytes), sizeof(nBytes));
    sMessage = ssBytes.str() + sData;
  }
  else if (sMode1 == "BIN-EOF")
  {
    int nTagLen;
    ssMode >> nTagLen;
    std::vector<unsigned char> tag(nTagLen), tagOrig = tag;
    std::string::iterator mit;
    while ((mit = MatchDelim(sData.begin(), sData.end(), tag.begin(), tag.end()))
           != sData.end() && std::distance(mit, sData.end()) >= static_cast<int>(tag.size()))
    {
      IncSequence(tag.begin(), tag.end());
      if (tag == tagOrig)
        return fb.Error(E_UTILS_WRITEJOB) << ": Failed to find a " << nTagLen 
                                          << " byte delimiter not already present in job data! Data was: " << sData;
    }
    std::string sTag;
    sTag.resize(tag.size());
    std::copy(tag.begin(), tag.end(), sTag.begin());
    sMessage = sTag + sData + sTag;
  }
  else
    return fb.Error(E_UTILS_WRITEJOB) << ": Unknown child input mode: " << sChildInputMode << ".";

  fb.Info(4) << "Writing job data: " << sMessage;
  s.write(sMessage.c_str(), sMessage.size());
  s.flush();
  
//  if (bMaster)
//    fOut2 << sMessage << std::flush;
  
  if (!s.good())
    return fb.Error(E_UTILS_WRITEJOB) << ": Output stream failure.";

  return 0;
}

