/********************************************************************
 *   		master.cpp
 *   Created on Mon Feb 27 2006 by Boye A. Hoeverstad.
 *   
 *   See header file for description.
 *******************************************************************/

#include "master.h"
#include <options.h>

#include <sstream>
#include <memory>

// FeedbackError E_MASTER_EVALUATE("Failed to evaluate data set");
DEFINE_FEEDBACK_ERROR(E_MASTER_EVALUATE, "Failed to evaluate data set")
// FeedbackError E_MASTER_EVALAGAIN("Failed to re-evaluate data missing in the first result set");
DEFINE_FEEDBACK_ERROR(E_MASTER_EVALAGAIN, "Failed to re-evaluate data missing in the first result set")
// FeedbackError E_DISTRIBUTOR_CREATESLAVES("Failed to create slaves");
DEFINE_FEEDBACK_ERROR(E_DISTRIBUTOR_CREATESLAVES, "Failed to create slaves")
// FeedbackError E_DISTRIBUTOR_DESTROY("Failed to destroy distribution system.  Kill it manually");
DEFINE_FEEDBACK_ERROR(E_DISTRIBUTOR_DESTROY, "Failed to destroy distribution system.  Kill it manually")


Master::Master(JobQueue *pJobQueue)
    : m_pJobQueue(pJobQueue), m_fb("Master"), m_nIDCounter(0)
{
}


int
Master::Evaluate(const std::vector<std::string> &data, std::vector<std::string> &results)
{
  static const int info_interval_secs = 10;

  AutoMutex mtx;
  if (m_pJobQueue->AcquireMutex(mtx))
    return m_fb.Error(E_MUTEX_LOCK);

  m_pJobQueue->ResultSet().clear();

      // Map job ID to position in vector
  typedef std::map<std::string, size_t> TJobIDMap;
  TJobIDMap jobIDs, jobIDsBackup;

  for (size_t i = 0; i < data.size(); i++)
  {
    TJobQueueElem job;
    job.sJobData = data[i];
        // Create a system-wide unique job ID.
    std::stringstream ssID;
    ssID << this << "-" << ++m_nIDCounter;
    job.sJobID = ssID.str();
    jobIDs[job.sJobID] = i;
    m_pJobQueue->push_back(job);
    m_fb.Info(3, "Adding job " + job.sJobID + " to job queue: " + job.sJobData);
  }

  if (m_pJobQueue->Signal())
    return m_fb.Error(E_MASTER_EVALUATE) << ", couldn't wake up slaves.";

  while(!m_pJobQueue->empty())
  {
    if (m_pJobQueue->Wait(info_interval_secs))
      return m_fb.Error(E_MASTER_EVALUATE) << ". Wait failed";
    if (!m_pJobQueue->empty())
      m_fb.Info(3) << "Processing... " << m_pJobQueue->size() 
              << " out of " << data.size() << " jobs remaining";
  }

  jobIDsBackup = jobIDs; // This copy is taken in order to check for duplicates in result set.
  TResultSet &rs = m_pJobQueue->ResultSet();
  for(TResultSet::const_iterator itResult = rs.begin(); itResult != rs.end(); itResult++)
  {
    TJobIDMap::iterator itJob = jobIDs.find(itResult->sJobID);
    if (itJob == jobIDs.end())
    {
      TJobIDMap::iterator itJobBackup = jobIDsBackup.find(itResult->sJobID);
      if (itJobBackup != jobIDsBackup.end())
        return m_fb.Error(E_INTERNAL_LOGIC) << "Result set contains duplicates";
      m_fb.Warning() << "Spurious result:  Result ID " << itResult->sJobID << " not found.  Discarded";
      continue;
    }
    results[itJob->second] = itResult->sResults;
    jobIDs.erase(itJob);
  }
  
  mtx.Unlock();
  
  if (!jobIDs.empty())
  {
    m_fb.Warning() << "Not all jobs were successfully evaluated, although the job queue was empty.  "
                   << "Re-evaluating " << jobIDs.size() << " jobs..";
    std::vector<std::string> data2(jobIDs.size()), results2(jobIDs.size());
    int i = 0;
    TJobIDMap::const_iterator itJob = jobIDs.begin();
    for (; itJob != jobIDs.end(); itJob++, i++)
      data2[i] = data[itJob->second];

    if (Evaluate(data2, results2))
      return m_fb.Error(E_MASTER_EVALAGAIN);

    for (itJob = jobIDs.begin(), i = 0; itJob != jobIDs.end(); itJob++, i++)
      results[itJob->second] = results2[i];
  }
  return 0;
}



DistributorLauncher::DistributorLauncher()
    : m_fb("DistributorLauncher")
{

}

DistributorLauncher::~DistributorLauncher()
{
  while (!m_distributors.empty())
    DestroyDistributor(m_distributors.begin()->first);
}



/*static*/ DistributorLauncher&
DistributorLauncher::Instance()
{
  static DistributorLauncher instance;
  return instance;
}


int
DistributorLauncher::CreateDistributor(const std::vector<std::string> &servers, 
                                       const std::vector<std::string> &slavePrograms,
                                       const std::vector<std::string> &slavesArgs,
                                       Master **ppNewMaster)
{
  std::auto_ptr<JobQueue> jobQueue(new JobQueue());
  std::auto_ptr<ThreadBarrier> barrier(new ThreadBarrier());

  TDistributor d;
  d.servers = servers;
  d.slavePrograms = slavePrograms;
  d.slavesArgs = slavesArgs;

  if (SlaveClientFactory::Instance().CreateSlaves(d.servers, d.slavePrograms, d.slavesArgs, d.slaves, jobQueue.get(), barrier.get()))
    return m_fb.Error(E_DISTRIBUTOR_CREATESLAVES);

  *ppNewMaster = new Master(jobQueue.get());

  d.pJobQueue = jobQueue.release();
  d.pBarrier = barrier.release();
  m_distributors[*ppNewMaster] = d;
  return 0;
}

int
DistributorLauncher::CreateDistributor(const std::vector<std::string> &servers, 
                                       const std::string &sSlaveProgram,
                                       const std::string &slaveArgs,
                                       Master **ppNewMaster)
{
  const std::vector<std::string> slavePrograms(servers.size(), sSlaveProgram); 
  const std::vector<std::string> slavesArgs(servers.size(), slaveArgs); 
  return CreateDistributor(servers, slavePrograms, slavesArgs, ppNewMaster);
}


int
DistributorLauncher::CreateDistributor(Master **ppNewMaster, int nNumSlaves)
{
//   if (Options::Instance().Option("slave-count", nNumSlaves))
//     return m_fb.Error(E_DISTRIBUTOR_CREATESLAVES);

  std::vector<std::string> servers(nNumSlaves);
  for (int nSlave = 0; nSlave < nNumSlaves; nSlave++)
  {
    std::stringstream ssServerID;
    ssServerID << "server-" << nSlave;
    servers[nSlave] = ssServerID.str();
  }

  std::string sSlave, sSlaveArgs;
  if (Options::Instance().Option("slave-program", sSlave) 
      || Options::Instance().Option("slave-arguments", sSlaveArgs))
    return m_fb.Error(E_DISTRIBUTOR_CREATESLAVES) << ": Failed to get slave-program and/or slave-arguments option(s).";

  return CreateDistributor(servers, sSlave, sSlaveArgs, ppNewMaster);
}


int
DistributorLauncher::DestroyDistributor(Master *pMaster)
{
  TDistributorSet::iterator itDist = m_distributors.find(pMaster);
  if (itDist == m_distributors.end())
    return m_fb.Error(E_DISTRIBUTOR_DESTROY) << "Trying to destroy a distributor set with an invalid pointer";
  else
  {
    TDistributor &d = itDist->second;
    if (d.pJobQueue->Close()
        || d.pJobQueue->Signal())
      return m_fb.Error(E_DISTRIBUTOR_DESTROY);

    for (std::vector<SlaveClient*>::iterator sit = d.slaves.begin();
         sit != d.slaves.end(); sit++)
      (*sit)->Terminate();

        // Send shutdown message from here before blocking to wait for
        // slaves.
    if (MessagePasser::SendShutdownMessage())
      return m_fb.Error(E_DISTRIBUTOR_DESTROY);

    while (!d.pBarrier->empty())
    {
      d.pBarrier->WaitEmpty(10);
      if (!d.pBarrier->empty())
        m_fb.Info(2) << "Waiting for slave clients to complete... " << d.pBarrier->size() << " slave clients still running.";
    }
    m_fb.Info(1) << "All slaves have completed successfully.";

        // Delete slaves
    for (std::vector<SlaveClient*>::iterator sit = d.slaves.begin();
         sit != d.slaves.end(); sit++)
      delete (*sit);

    delete itDist->first;
    delete d.pJobQueue;
    delete d.pBarrier;
    m_distributors.erase(itDist);
  }
  return 0;
}


