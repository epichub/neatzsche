/********************************************************************
 *   		errorcodes_common.cpp
 *   Created on Sun Aug 06 2006 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include "errorcodes_common.h"

// FeedbackError E_INTERNAL_LOGIC("Internal logical error");
DEFINE_FEEDBACK_ERROR(E_INTERNAL_LOGIC, "Internal logical error")
// FeedbackError E_INIT_OPTIONS("Failed to initialize correctly from user-supplied options");
DEFINE_FEEDBACK_ERROR(E_INIT_OPTIONS, "Failed to initialize correctly from user-supplied options")
