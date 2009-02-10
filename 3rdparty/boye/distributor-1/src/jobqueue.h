/********************************************************************
 *   		jobqueue.h
 *   Created on Mon Feb 27 2006 by Boye A. Hoeverstad.
 *   
 *   Contains a queue meant to store jobs pending evaluation.  The
 *   queue has functions to provide exclusive access (through a
 *   mutex), and waiting on full/empty/any signal (semaphores).
 *******************************************************************/

#if !defined(__JOBQUEUE_H__)
#define __JOBQUEUE_H__

#include <syncutils.h>
#include <feedback.h>

#include <pthread.h>
#include <stdexcept>
#include <string>
#include <set>
#include <list>

// extern FeedbackError E_JOBQUEUE_CLOSE;
DECLARE_FEEDBACK_ERROR(E_JOBQUEUE_CLOSE)
// extern FeedbackError E_JOBQUEUE_SIGNAL;
DECLARE_FEEDBACK_ERROR(E_JOBQUEUE_SIGNAL)

// Forward declaration
// class SlaveClient; 

/********************************************************************
 *   Elements in the queue.  An XML string keeping the job
 *   specification, an ID given by the master, and a set keeping
 *   pointers to all slaves working on the job.  Job IDs should be a
 *   unique identifier for the job, as this is used for operator<.
 *******************************************************************/
typedef struct TJobQueueElemVar
{
  std::string sJobID;
  std::string sJobData;
  std::string sResults;
  time_t timeLastStart;
  std::set<class SlaveClient*> workers;
  bool operator<(const TJobQueueElemVar &rhs) const
  { return sJobID < rhs.sJobID; }
} TJobQueueElem;


typedef std::set<TJobQueueElem> TResultSet;

/********************************************************************
 *   Queue of jobs pending evaluation.  The plan was to inherit from
 *   std::queue, but this class lacks the necessary erase
 *   capabilities.  So it is a list, but treat it as a queue.
 *******************************************************************/
class JobQueue : public std::list<TJobQueueElem>, public LockableObject
{
protected:
  pthread_cond_t *m_pSemaphore;
  bool m_bClosed;
  Feedback m_fb;
  TResultSet m_resultSet;
  size_t m_nNumJobsPerSend;
  bool m_bAutoNumJobsPerSend;

  JobQueue(const JobQueue &q);
//       : m_fb("JobQueue")
//   { 
//     throw std::logic_error("Copy constructor not implemented"); 
//   }
public:
  JobQueue();
  ~JobQueue();
  
  bool Closed() const;
  int Close();

  int Wait(double dTimeoutSecs = 0);
  int Signal();

  const TResultSet& ResultSet() const;
  TResultSet& ResultSet();
  size_t NumJobsPerSend() const;
};
  

#endif
