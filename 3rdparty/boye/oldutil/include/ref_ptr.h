/********************************************************************
 *   		ref_ptr.h
 *   Created on Thu Sep 07 2006 by Boye A. Hoeverstad.
 *   
 *   A class wrapping a reference counted pointer to object.
 *   Taken from http://www.davethehat.com/articles/smartp.htm.
 *******************************************************************/

#if !defined(__REF_PTR_H__)
#define __REF_PTR_H__

#include <cassert>

template <class T>
class ref_ptr
{

  class counted
  {
  public:
    size_t m_nCount;
    T* const m_pT;
  
    counted(T* pT) 
        : m_nCount(0), m_pT(pT) 
    { 
      assert(pT != 0); 
    }

    ~counted()
    { 
      assert(m_nCount == 0); 
      delete m_pT; 
    }
  

    size_t
    GetRef()  
    { 
      return ++m_nCount; 
    }
    
    size_t
    FreeRef()
    { 
      assert(m_nCount!=0); 
      return --m_nCount; 
    }

  };

public:
  ref_ptr()
      : m_pObject(0) 
  {
  }

  explicit ref_ptr(T* pT)
  {
    m_pObject = new counted(pT);
    m_pObject->GetRef();
  }

  ~ref_ptr()
  {
    UnBind();
  }

  ref_ptr(const ref_ptr<T>& rhs)
  {
    m_pObject = rhs.m_pObject;
    if (!Null())
      m_pObject->GetRef();
  }

  ref_ptr<T>& 
  operator=(const ref_ptr<T>& rhs)
  {
    if (!rhs.Null())
      rhs.m_pObject->GetRef();
    UnBind();
    m_pObject = rhs.m_pObject;
    return *this;
  }
        
  T* 
  operator->()
  {
    return m_pObject->m_pT;
  }

  const T*
  operator->() const
  {
    return m_pObject->m_pT;
  }
  
  T&
  operator *()
  {
    return *(m_pObject->m_pT);
  }

  const T&
  operator *() const
  {
    return *(m_pObject->m_pT);
  }

  bool
  operator==(const ref_ptr<T>& rhs) const
  {
    return m_pObject->m_pT == rhs.m_pObject->m_pT;
  }

  bool
  Null() const 
  {
    return m_pObject == 0;
  };

  void
  SetNull()
  { 
    UnBind(); 
  }

private:
  void UnBind()
  {
    if (!Null() && m_pObject->FreeRef() == 0)       
      delete m_pObject;
    m_pObject = 0;
  }

  counted* m_pObject;

};




#endif
