/********************************************************************
 *   		slave_stdio.h
 *   Created on Mon May 22 2006 by Boye A. Hoeverstad.
 *   
 *   Stub to launch the slave server.
 *
 *******************************************************************/

#if !defined(__SLAVE_STDIO_H__)
#define __SLAVE_STDIO_H__

#include <feedback.h>

// extern FeedbackError E_SLAVEMAIN_RECV;
DECLARE_FEEDBACK_ERROR(E_SLAVEMAIN_RECV)
// extern FeedbackError E_SLAVEMAIN_SEND;
DECLARE_FEEDBACK_ERROR(E_SLAVEMAIN_SEND)
// extern FeedbackError E_SLAVEMAIN_MSG;
DECLARE_FEEDBACK_ERROR(E_SLAVEMAIN_MSG)
// extern FeedbackError E_SLAVEMAIN_OPEN;
DECLARE_FEEDBACK_ERROR(E_SLAVEMAIN_OPEN)
// extern FeedbackError E_SLAVEMAIN_LAUNCH;
DECLARE_FEEDBACK_ERROR(E_SLAVEMAIN_LAUNCH)
// extern FeedbackError E_SLAVEMAIN_JOBSEND;
DECLARE_FEEDBACK_ERROR(E_SLAVEMAIN_JOBSEND)
// extern FeedbackError E_SLAVEMAIN_SETUP;
DECLARE_FEEDBACK_ERROR(E_SLAVEMAIN_SETUP)

int 
slave_main(int argc, char *argv[]);


#endif
