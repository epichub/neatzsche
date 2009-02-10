/********************************************************************
 *   		syncutils.h
 *   Created on Mon Mar 27 2006 by Boye A. Hoeverstad.
 *   
 *   Utilities to easy synchronization.
 *******************************************************************/

#if !defined(__SYNCUTILS_H__)
#define __SYNCUTILS_H__

#include "feedback.h"

#include <set>
#include <pthread.h>

/********************************************************************
 *   Class to automatically unlock a mutex in destructor.  The mutex sent
 *   in should already be locked.
 *******************************************************************/
class AutoMutex
{
  AutoMutex(AutoMutex &); // Not implemented: No copy semantics.
  Feedback m_fb;
  pthread_mutex_t *m_pLockedMutex;
  std::string m_sMutexDesc;
public:
  AutoMutex(pthread_mutex_t *pLockedMutex = 0, std::string sMutexDesc = "");
  ~AutoMutex();

  void SetLockedMutex(pthread_mutex_t *pLockedMutex, std::string sMutexDesc = "");
  pthread_mutex_t* GetLockedMutex() const;
  int Unlock();
    
};


/********************************************************************
 *   Superclass or utility class for objects that need locking
 *   capabilities, taking advantage of the AutoMutex.
 *******************************************************************/
class LockableObject
{
  LockableObject(LockableObject &); // Not implemented: No copy semantics.
protected:
  Feedback m_fb;
  pthread_mutex_t *m_pMutex;
  std::string m_sMutexDesc;
public:
  LockableObject(std::string sMutexDesc = "");
  ~LockableObject();
  int AcquireMutex(AutoMutex &mtx);
  pthread_mutex_t *GetMutexPtr() const;
};



template<class T> class Barrier
{
  LockableObject m_mtx;
  pthread_cond_t *m_pCond;
  std::set<T> m_data;
  Barrier(const Barrier &); // Not implemented: No copy semantics.
public:
  Barrier()
      : m_pCond(new pthread_cond_t)
  {
    pthread_cond_init(m_pCond, 0);
  }

  ~Barrier()
  {
    pthread_cond_destroy(m_pCond);
    delete m_pCond;
  }

  int Add(const T &t)
  {
    AutoMutex mtx;
    m_mtx.AcquireMutex(mtx);
    m_data.insert(t);
    return 0;
  }

  bool Found(const T &t) const
  {
    return m_data.find(t) != m_data.end();
  }

  int Erase(const T &t)
  {
    AutoMutex mtx;
    m_mtx.AcquireMutex(mtx);
    m_data.erase(t);
    if (m_data.empty())
      pthread_cond_broadcast(m_pCond);
    return 0;
  }

  int WaitSize(size_t nSize, int nTimeoutSecs = 0)
  {
    AutoMutex mtx;
    m_mtx.AcquireMutex(mtx);
    if (m_data.size() == nSize)
      return 0;
    pthread_mutex_t *pMtx = mtx.GetLockedMutex();
    if (nTimeoutSecs > 0)
    {
      time_t cur = time(0);
      timespec ts = { cur + nTimeoutSecs, 0 };
      pthread_cond_timedwait(m_pCond, pMtx, &ts);
    }
    else
      while (m_data.size() != nSize)
        pthread_cond_wait(m_pCond, pMtx);
    return 0;
  }

  int WaitEmpty(int nTimeoutSecs = 0)
  {
    return WaitSize(0, nTimeoutSecs);
  }

  size_t size() 
  {
    AutoMutex mtx;
    m_mtx.AcquireMutex(mtx);
    return m_data.size();    
  }

  bool empty() 
  {
    AutoMutex mtx;
    m_mtx.AcquireMutex(mtx);
    return m_data.empty();    
  }

};

typedef Barrier<pthread_t> ThreadBarrier;

#endif
