/********************************************************************
 *   		syncutils.cpp
 *   Created on Mon Mar 27 2006 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include <syncutils.h>
#include <cassert>

AutoMutex::AutoMutex(pthread_mutex_t *pLockedMutex /*=0*/, std::string sMutexDesc /*=""*/)
    : m_fb("AutoMutex")
    , m_pLockedMutex(pLockedMutex), m_sMutexDesc(sMutexDesc)
      
{
}


AutoMutex::~AutoMutex() 
{
  if (m_pLockedMutex)
    Unlock();
}


void 
AutoMutex::SetLockedMutex(pthread_mutex_t *pLockedMutex, std::string sMutexDesc /*=""*/) 
{
  m_pLockedMutex = pLockedMutex;
  if (!sMutexDesc.empty())
    m_sMutexDesc = sMutexDesc;
}

  
pthread_mutex_t*
AutoMutex::GetLockedMutex() const 
{
  return m_pLockedMutex;
}


int
AutoMutex::Unlock()
{
//   if (m_sMutexDesc.empty())
//     m_fb.Info(5) << "Unlocking mutex " << m_pLockedMutex << ".";
//   else
//     m_fb.Info(5) << "Unlocking mutex " << m_sMutexDesc << " (" << m_pLockedMutex << ").";


  if (m_pLockedMutex)
  {
        // Note: Set to 0 before actually unlocking the mutex,
        // otherwise the test above may fail, if two threads call Unlock simultaneously.
    pthread_mutex_t *pMutex = m_pLockedMutex;
    m_pLockedMutex = 0;
        //!!- No error handling.
    int nRet = pthread_mutex_unlock(pMutex);
    return m_fb.ErrorIfNonzero(nRet, E_MUTEX_UNLOCK);
  }
  return m_fb.Error(E_MUTEX_UNLOCK_TWICE);
}
    

LockableObject::LockableObject(std::string sMutexDesc /*=""*/)
    : m_fb("LockableObject")
    , m_pMutex(new pthread_mutex_t), m_sMutexDesc(sMutexDesc)
{
      //!!- No error handling.  Problems will arise if
      //initialization fails.  Consider moving to separate class
      //with automatic creation/destructio and initialization.
  int nInit = pthread_mutex_init(m_pMutex, 0);
  assert(nInit == 0 || !m_fb.Error(E_MUTEX_INIT));
}


LockableObject::~LockableObject()
{
      //!!- The mutex should be unlocked now.
  int nDest = pthread_mutex_destroy(m_pMutex);
  assert(nDest == 0 || !m_fb.Error(E_MUTEX_DESTROY));
  delete m_pMutex;
}


/********************************************************************
 *   Lock and acquire a mutex.  This function will block until the
 *   mutex is available.  The mutex, in locked state, is returned in
 *   the AutoMutex mtx.  Returns 0 on success.  Will fail if
 *   phtread_mutex_lock fails.
 *******************************************************************/
int
LockableObject::AcquireMutex(AutoMutex &mtx)
{
  assert(m_pMutex != 0);
  assert(!mtx.GetLockedMutex());

//   std::stringstream ssMtxID;
//   if (m_sMutexDesc.empty())
//     ssMtxID << m_pMutex;
//   else
//     ssMtxID << m_sMutexDesc << " (" << m_pMutex << ")";
//   m_fb.Info(5) << "Attempting to lock mutex " << ssMtxID.str() << "...";

  if (pthread_mutex_lock(m_pMutex))
    return m_fb.Error(E_MUTEX_LOCK);
    
//   m_fb.Info(5) << "Mutex " << ssMtxID.str() << " successfully locked.";

  mtx.SetLockedMutex(m_pMutex, m_sMutexDesc);
  return 0;
}


pthread_mutex_t* 
LockableObject::GetMutexPtr() const
{
  return m_pMutex;
}
