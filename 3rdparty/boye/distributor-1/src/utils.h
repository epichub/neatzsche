/********************************************************************
 *   		utils.h
 *   Created on Mon May 22 2006 by Boye A. Hoeverstad.
 *   
 *   Miscellaneous utilities that relate to the distribution
 *   subsystem, and that I'm unable to find a better name for...
 *******************************************************************/

#if !defined(__UTILS_H__)
#define __UTILS_H__

#include <misc_utils.h>
#include <feedback.h>

// extern FeedbackError E_UTILS_READJOB;
DECLARE_FEEDBACK_ERROR(E_UTILS_READJOB)
// extern FeedbackError E_UTILS_WRITEJOB;
DECLARE_FEEDBACK_ERROR(E_UTILS_WRITEJOB)

/********************************************************************
 *   Read and write job data to/from child process, using the
 *   input/output mode specified.
 *******************************************************************/
int ReadJobData(Feedback &fb, std::istream &s, const std::string &sChildOutputMode, std::string &sData);
int WriteJobData(Feedback &fb, std::ostream &s, const std::string &sChildInputMode, std::string sData);

#endif
