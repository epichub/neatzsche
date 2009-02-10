/********************************************************************
 *   		errorcodes_common.h
 *   Created on Wed Apr 05 2006 by Boye A. Hoeverstad.
 *   
 *   Common error codes
 *******************************************************************/

#if !defined(__ERRORCODES_COMMON_H__)
#define __ERRORCODES_COMMON_H__

#include "feedback.h"

// extern FeedbackError E_INTERNAL_LOGIC;
DECLARE_FEEDBACK_ERROR(E_INTERNAL_LOGIC)
// extern FeedbackError E_INIT_OPTIONS;
DECLARE_FEEDBACK_ERROR(E_INIT_OPTIONS)

#endif
