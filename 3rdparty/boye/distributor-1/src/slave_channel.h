/********************************************************************
 *   		slave_channel.h
 *   Created on Tue May 09 2006 by Boye A. Hoeverstad.
 *   
 *   Base class for communication channels doing the actual sending
 *   and receiving on the master node.  Implementations using for
 *   instance MPI or PVM should inherit from this class.
 *******************************************************************/

#if !defined(__SLAVE_CHANNEL_H__)
#define __SLAVE_CHANNEL_H__

#include <feedback.h>

#include <iostream>

// extern FeedbackError E_SLAVECHANNELSENDER_THREAD;
DECLARE_FEEDBACK_ERROR(E_SLAVECHANNELSENDER_THREAD)
// extern FeedbackError E_SLAVECHANNELRECEIVER_THREAD;
DECLARE_FEEDBACK_ERROR(E_SLAVECHANNELRECEIVER_THREAD)
// extern FeedbackError E_SLAVECHANNELSENDER_RUN;
DECLARE_FEEDBACK_ERROR(E_SLAVECHANNELSENDER_RUN)
// extern FeedbackError E_SLAVECHANNELRECEIVER_RUN;
DECLARE_FEEDBACK_ERROR(E_SLAVECHANNELRECEIVER_RUN)
// extern FeedbackError E_SLAVECHANNELRECEIVER_WRITE;
DECLARE_FEEDBACK_ERROR(E_SLAVECHANNELRECEIVER_WRITE)
// extern FeedbackError E_SLAVECHANNELSENDER_STOP;
DECLARE_FEEDBACK_ERROR(E_SLAVECHANNELSENDER_STOP)
// extern FeedbackError E_SLAVECHANNELRECEIVER_STOP;
DECLARE_FEEDBACK_ERROR(E_SLAVECHANNELRECEIVER_STOP)

class SlaveChannelSender
{
  Feedback m_fb;
protected:
  std::istream *m_pInChannel;
  pthread_t m_threadId;
  virtual int SendMessage(const std::string &sServer, const std::string &sMessage) = 0;
//   int CheckShutdown(const std::string &sServer, const std::string &sMessage, bool &bShutdown);

  template<class T> friend void* SlaveChannel_thread_func(void *pArg);
public:
  SlaveChannelSender(std::istream *pInChannel);
  virtual ~SlaveChannelSender();
  virtual int Start();
//   virtual int Stop();

  virtual int Run();
  virtual void SetInputChannel(std::istream *pIc);
  pthread_t GetThreadId() const;
};


class SlaveChannelReceiver
{
  Feedback m_fb;
protected:
  std::ostream *m_pOutChannel;
  pthread_t m_threadId;
  virtual int ReceiveMessage(std::string &sServer, std::string &sMessage) = 0;
//   int CheckShutdown(const std::string &sServer, const std::string &sMessage, bool &bShutdown);

  template<class T> friend void* SlaveChannel_thread_func(void *pArg);
public:
  SlaveChannelReceiver(std::ostream *pOutChannel);
  virtual ~SlaveChannelReceiver();
  virtual int Start();
//   virtual int Stop();

  virtual void SetOutputChannel(std::ostream *pOc);
  virtual int Run();
  pthread_t GetThreadId() const;
};

#endif
