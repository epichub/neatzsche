/********************************************************************
 *   		master_stdio.h
 *   Created on Mon May 22 2006 by Boye A. Hoeverstad.
 *   
 *   TODO: Insert description here.
 *******************************************************************/

#if !defined(__MASTER_STDIO_H__)
#define __MASTER_STDIO_H__

#include <feedback.h>

// extern FeedbackError E_MASTERMAIN_LOOPSETUP;
DECLARE_FEEDBACK_ERROR(E_MASTERMAIN_LOOPSETUP)
// extern FeedbackError E_MASTERMAIN_LOOP;
DECLARE_FEEDBACK_ERROR(E_MASTERMAIN_LOOP)
// extern FeedbackError E_MASTERMAIN_SETUP;
DECLARE_FEEDBACK_ERROR(E_MASTERMAIN_SETUP)

 
int 
master_main(int argc, char *argv[]);

#endif
