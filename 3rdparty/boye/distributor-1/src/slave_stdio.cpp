/********************************************************************
 *   		slave_stdio.cpp
 *   Created on Fri Mar 17 2006 by Boye A. Hoeverstad.
 *   
 *   Stub to launch the slave server.
 *
 *   Upon receiving a CONNECT message, it will fork and try to execute
 *   the given program.
 *
 *   JOB messages will be written to standard output.
 *******************************************************************/

// slave_mpi.h must be included before stdio. See comment in slave_mpi.h
#include "slave_mpi.h"

#include "slave_stdio.h"
//#include "slave_pvm.h"
#include "messages.h"
#include "utils.h"
#include <options.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <iostream>
#include <cassert>

// #include <setjmp.h>

// FeedbackError E_SLAVEMAIN_RECV("Failed to receive message over communications channel");
DEFINE_FEEDBACK_ERROR(E_SLAVEMAIN_RECV, "Failed to receive message over communications channel")
// FeedbackError E_SLAVEMAIN_SEND("Failed to send message over communications channel");
DEFINE_FEEDBACK_ERROR(E_SLAVEMAIN_SEND, "Failed to send message over communications channel")
// FeedbackError E_SLAVEMAIN_MSG("Message malformed");
DEFINE_FEEDBACK_ERROR(E_SLAVEMAIN_MSG, "Message malformed")
// FeedbackError E_SLAVEMAIN_OPEN("Failed to open I/O tty or file");
DEFINE_FEEDBACK_ERROR(E_SLAVEMAIN_OPEN, "Failed to open I/O tty or file")
// FeedbackError E_SLAVEMAIN_LAUNCH("Failed to launch child process to do actual work");
DEFINE_FEEDBACK_ERROR(E_SLAVEMAIN_LAUNCH, "Failed to launch child process to do actual work")
// FeedbackError E_SLAVEMAIN_JOBSEND("Failed to send job data to master");
DEFINE_FEEDBACK_ERROR(E_SLAVEMAIN_JOBSEND, "Failed to send job data to master")
// FeedbackError E_SLAVEMAIN_SETUP("The master failed during system setup");
DEFINE_FEEDBACK_ERROR(E_SLAVEMAIN_SETUP, "The master failed during system setup")

typedef struct TJobDataVar
{
  std::string sJobID;
  std::string sData;
  std::string sResults;
  int nTime;
//   TJobDataVar() 
//   {}
} TJobData;

typedef std::vector<TJobDataVar> TJobDataset;

std::string sChildName;
pid_t child_pid = 0;

void atexit_kill_slave()
{
  Feedback fb("atexit slave killer");
  if (child_pid != 0)
  {
    KillProcess(child_pid, sChildName, fb);
    child_pid = 0;
  }
}

void StopServer()
{
//   kill(getpid(), SIGSTOP);
  while (true)
    sleep(1000);
}

std::string HostName()
{
  static const int name_len = 1024;
  char szHostName[name_len];

  if (gethostname(szHostName, name_len))
    return std::string("[Failed to get host name. Error: " + std::string(strerror(errno)) + "]");

  return std::string(szHostName);
}



/********************************************************************
 *   Pass on selected signals to the slave process.
 *******************************************************************/
static void
SignalPassOn(int nSignal)
{
  Feedback fb("slave signal handler");
  if (child_pid != 0)
  {
    fb.Info(2) << "Received signal " << nSignal << ".  Passing it on to slave with pid " << child_pid << "."; 
    kill(child_pid, nSignal);
  }
  else
    fb.Info(2) << "Received signal " << nSignal << ", but child pid is 0, so it cannot be passed on.";
}



/********************************************************************
 *   Certain signals must be handled by this process.  These
 *   include those that indicate the child has gone down.
 *******************************************************************/
static void 
SignalAbort(int nSignal)
{
  Feedback fb("slave signal handler");
  if (nSignal == SIGPIPE)
  {
    fb.Warning("Received SIGPIPE signal on host ") 
      << HostName() 
      << ". This probably means the slave process has died.  The slave server on this host will now stop.  "
      << "You may have to log in to the host and kill the processes manually.  Slave server pid is " << getpid() 
      << ", child (slave) pid is " << child_pid << ".";
    StopServer();
  }
  else if (nSignal != SIGSTOP)
  {
    fb.Warning("Caught signal ") << nSignal << ". Exiting.";
    exit(nSignal);
  }
}


int 
GetMessage(Feedback &fb, MPICommunicator &comm, std::string &sMessage)
{
  comm(MPI::ANY_SOURCE, MPI::ANY_TAG) >> sMessage;
  if (!comm.good())
    return fb.Error(E_SLAVEMAIN_RECV);
  return 0;
}


int 
CheckConnectMessage(Feedback &fb, std::stringstream &ss, std::string &sServer, 
                    std::string &sSlaveInputMode, std::string &sSlaveOutputMode,
                    std::string &sProgram, std::string &sArgs)
{
  std::string sTag;
  int nVersion;
  ss >> sTag >> sServer >> nVersion;

  if (sTag != "CONNECT")
    return fb.Error(E_SLAVEMAIN_MSG) << ": " << "Expected CONNECT message, got message saying \"" + sTag + "\".";

  const int expected_version = 2;
  if (nVersion != expected_version)
    return fb.Error(E_SLAVEMAIN_MSG) 
      << ": " << "Expected CONNECT message version " 
      << expected_version << ", got version " << nVersion << ".";

  std::getline(ss, sSlaveInputMode); // Chomp newline
  std::getline(ss, sSlaveInputMode);
  std::getline(ss, sSlaveOutputMode);
  if (sSlaveInputMode.empty() || sSlaveOutputMode.empty())
    return fb.Error(E_SLAVEMAIN_MSG) 
      << ": " << "CONNECT message didn't correctly specify slave input/output mode." ;

  std::getline(ss, sProgram);
  std::getline(ss, sArgs);

  if (sProgram.empty())
  if (sSlaveInputMode.empty() || sSlaveOutputMode.empty())
    return fb.Error(E_SLAVEMAIN_MSG) 
      << ": " << "CONNECT message didn't correctly specify slave program." ;
    
  return 0;
}


int 
ConnectSlave(Feedback &fb, MPICommunicator &comm, const std::string &sProgram, const std::string &sArgs,
             fdostream &slaveWriteStdin, fdistream &slaveReadStdout)
{
  sChildName = sProgram;

  if (child_pid != 0)
  {
    KillProcess(child_pid, sChildName, fb);
    child_pid = 0;
  }
      
//   fb.Warning("!!!!!!! Debug: Connecting one slave with extra argument.");
//   if (comm.Get_rank() == 3)
//   {
//     fb.Warning("!!!!!!!!!!!!!!! Debug: Connected slave 3 with extra argument. !!!!!!!!!!!!!!!!!!!!");
//     return ConnectProcess(sProgram, sArgs + " -s", &std::cin, &std::cout, 0, &child_pid, 0);
//   }
      // Close in case the bRunOnce flag is set.
  if (slaveWriteStdin.is_open())
    slaveWriteStdin.close();
  if (slaveReadStdout.is_open())
    slaveReadStdout.close();

  return ConnectProcess(sProgram, sArgs, &slaveWriteStdin, &slaveReadStdout, 0, &child_pid, 0);
}


int 
GetNextJob(Feedback &fb, MPICommunicator &comm, std::string &sMessage, bool &bTerminate)
{
  if (int nRet = GetMessage(fb, comm, sMessage))
    return nRet;

  std::stringstream ss(sMessage);
  std::string sTag;
  std::getline(ss, sTag);

  if (sTag == "TERMINATE")
  {
    bTerminate = true;
    return 0;
  }

  if (sTag == "JOB")
    return 0;

  fb.Info(2) << "Received unexpected message: " << sTag << ". Message discarded.";
  return GetNextJob(fb, comm, sMessage, bTerminate);
}


int 
ExtractJobData(Feedback &fb, const std::string &sMessage, 
               TJobDataset &jobData)
{
  assert(jobData.empty());

  std::stringstream ss(sMessage);
  std::string sServer, sJob, sChomp;
  std::getline(ss, sJob);
  assert(sJob == "JOB"); // Should be checked by GetNextJob.
  std::getline(ss, sServer);
  int nNumJobs;
  ss >> nNumJobs;
  std::getline(ss, sChomp);

  for (int nJob = 0; nJob < nNumJobs; nJob++)
  {
    jobData.push_back(TJobData());
    std::string &sJobID = jobData.back().sJobID;
    std::getline(ss, sJobID);
    int nNumBytes;
    ss.read(reinterpret_cast<char*>(&nNumBytes), sizeof(nNumBytes));
    if (nNumBytes <= 0 || ss.gcount() != sizeof(nNumBytes))
      return fb.Error(E_SLAVEMAIN_MSG) << ". Job message failure. Job ID: " << jobData.back().sJobID 
                                       << ". Failed to read job size indicator.";
    std::vector<char> buf(nNumBytes);
    ss.read(&(buf[0]), buf.size());
    if (ss.gcount() != static_cast<std::streamsize>(buf.size()))
      return fb.Error(E_SLAVEMAIN_MSG) << ". Job message failure. Job ID: " << jobData.back().sJobID 
                                       << ". Failed to read " << buf.size() << " bytes of job data.";

    std::string &sData = jobData.back().sData;
    sData.resize(buf.size());
    std::copy(buf.begin(), buf.end(), sData.begin());
  }

  if (jobData.empty())
    return fb.Error(E_SLAVEMAIN_MSG) << ". Job message failure. No jobs read.";
  
  fb.Info(3) << "Server " << sServer << " received message containing " 
             << jobData.size() << " jobs.";
  return 0;
}


int
SendResults(Feedback &fb, MPICommunicator &comm, int nServerRank, int nTag, 
            const std::string &sServer, 
            const TJobDataset &jobData)
{
  fb.Info(3) << "Server " << sServer << " sending results of " 
             << jobData.size() << " jobs.";
             
  std::stringstream ss;
  ss << "RESULTS\n" 
     << sServer << "\n"
     << jobData.size() << "\n";
  for (TJobDataset::const_iterator jit = jobData.begin(); jit != jobData.end(); jit++)
  {
    ss << jit->sJobID << "\n"
       << jit->nTime << "\n";
    size_t nResSize = jit->sResults.size();
    ss.write(reinterpret_cast<char*>(&nResSize), sizeof(nResSize));
    ss.write(jit->sResults.c_str(), nResSize);
  }

  comm(nServerRank, nTag) << ss.str();

  if (!comm.good())
    return fb.Error(E_SLAVEMAIN_JOBSEND);
 
  return 0;
}



int 
slave_main_int(MPICommunicator &comm, Feedback &fb, int argc, char *argv[])
{
  std::string sRunOnce;
  int nInfoLevel;
  std::string sInfoShow, sInfoHide;
  if (Options::Instance().Option("slave-run-once", sRunOnce)
      || Options::Instance().Option("slave-verbosity", nInfoLevel)
      || Options::Instance().Option("verbosity-showonly", sInfoShow)
      || Options::Instance().Option("verbosity-dontshow", sInfoHide))
    return fb.Error(E_SLAVEMAIN_SETUP) << ": Unable to extract the necessary options.";
  fb.SetInfoLevel(nInfoLevel);
  fb.SetShowHide(sInfoShow, sInfoHide);


  bool bRunOnce = sRunOnce == "true";
  
  int nRet;

  std::string sMessage;
  if ((nRet = GetMessage(fb, comm, sMessage)))
    return nRet;

  int nServerRank, nTag;
  comm.GetLastRecvRankTag(nServerRank, nTag);

  std::string sServer, sSlaveInputMode, sSlaveOutputMode;
  std::string sProgram, sArgs;
  std::stringstream ss(sMessage);
  if ((nRet = CheckConnectMessage(fb, ss, sServer, sSlaveInputMode, sSlaveOutputMode, sProgram, sArgs)))
    return nRet;

  fdostream slaveWriteStdin;
  fdistream slaveReadStdout;

  if ((nRet = ConnectSlave(fb, comm, sProgram, sArgs, slaveWriteStdin, slaveReadStdout)))
    return nRet;

  atexit(atexit_kill_slave);

      // Signals to be passed on to slave process
  Signal(SIGHUP, SignalPassOn);
  Signal(SIGINT, SignalPassOn);
  Signal(SIGQUIT, SignalPassOn);
  Signal(SIGUSR1, SignalPassOn);
  Signal(SIGUSR2, SignalPassOn);
  Signal(SIGALRM, SignalPassOn);
  Signal(SIGTERM, SignalPassOn);
  Signal(SIGTSTP, SignalPassOn);
  Signal(SIGCONT, SignalPassOn);
  Signal(SIGCHLD, SignalPassOn);
      // Signal(s) handled by the distribution system
  Signal(SIGPIPE, SignalAbort);


  comm(nServerRank, nTag) << "READY\n" + sServer;

  fb.Info(1) << "Slave server " << sServer 
             << " up and running on host " << HostName() << " with pid " << getpid() << ".";

//   int nSleep = 5;
//   std::cerr << "Slave taking a " << nSleep 
//             << " second break to attach a debugger. Pid is " << getpid() << " .\n";
//   sleep(nSleep);
//   std::cerr << "Break over, continuing.\n";

  bool bTerminate = false;
  while (!(nRet = GetNextJob(fb, comm, sMessage, bTerminate)) && !bTerminate)
  {
    TJobDataset jobData;

    if ((nRet = ExtractJobData(fb, sMessage, jobData)))
      return nRet;

    for (TJobDataset::iterator jit = jobData.begin(); jit != jobData.end(); jit++)
    {
      int nTimeStart = time(0);
      if ((nRet = WriteJobData(fb, slaveWriteStdin, sSlaveInputMode, jit->sData)))
        return nRet;
      
      if ((nRet = ReadJobData(fb, slaveReadStdout, sSlaveOutputMode, jit->sResults)))
        return nRet;
      jit->nTime = time(0) - nTimeStart;
    }

    if ((nRet = SendResults(fb, comm, nServerRank, nTag, sServer, jobData)))
      return nRet;

    if (bRunOnce && (nRet = ConnectSlave(fb, comm, sProgram, sArgs, slaveWriteStdin, slaveReadStdout)))
      return nRet;
  }

  if (nRet)
    return nRet;

//  Don't send TERMINATED message.  If the master is down, the slaves
//  will lock up trying to get this message sent.
//  if (bTerminate)
//    comm(nServerRank, nTag) << "TERMINATED\n" << sServer;

  return 0;

}


int 
slave_main(int argc, char *argv[])
{
//   MPICommunicator comm(MPI::COMM_WORLD, MPICommunicator::singlethreaded);;
  MPICommunicator comm;

  std::stringstream ss_id;
  ss_id << "slave " << comm.Get_rank() << " main";
  Feedback fb(ss_id.str());

      // Jumps not applied at the moment...
  int nMainRet = 0, nJmpRet = 0;
//   jmp_buf env;
//   if ((nJmpRet = sigsetjmp(env, 1)) == 0)
  nMainRet = slave_main_int(comm, fb, argc, argv);
  if (nMainRet != 0 || nJmpRet != 0)
  {
    fb.Warning("An error has occurred on host " + HostName() + ".  The system will now stop and wait for MPI to kill it.");
    KillProcess(child_pid, sChildName, fb);
    child_pid = 0;
    StopServer();
  }

  if (nJmpRet)
    return nJmpRet;
  return nMainRet;
}




// int nReceiverTid = -1;
// std::string sServer;

// bool bGetResults = false;

// void ReadResults(Feedback &fb)
// {
// }

// int ReadMessage(Feedback &fb)
// {
//   return 0;
// //   if (pvm_recv(-1, -1) < 0)
// //     return fb.Error(
// //   {
// //     pvm_stream ps;
// //     std::string sServerNow, sMessage;
// //     if (!(ps >> sServerNow >> sMessage).good())
// //       return fb.Error(E_SLAVEMAIN_RECV);
    
// //     if (sServer.empty())
// //       sServer = sServerNow;
// //     else if (sServer != sServerNow)
// //       return fb.Error(E_SLAVEMAIN_MSG) << " server changed name.";
      
// //     std::stringstream ss(sMessage);
// //     std::string sTag, sServer2;
// //     if (!std::getline(ss, sTag) || !std::getline(ss, sServer2))
// //       return fb.Error(E_SLAVEMAIN_MSG) << ", couldn't extract Tag and/or server.";
// //     if (sServer2 != sServer)
// //       return fb.Error(E_SLAVEMAIN_MSG) << ": Server in message doesn't match destination.";

// //     fb.Info(2) << "Received message with tag " << sTag << ".";
          
// //     if (sTag == "CONNECT")
// //     {
// //       int nVer;
// //       std::string sInput, sOutput;
// //       if (!(ss >> nVer >> sInput >> sOutput).good())
// //         return fb.Error(E_SLAVEMAIN_MSG);
// //       int nFdIn = open(const_cast<char*>(sInput.c_str()), O_RDONLY);
// //       int nFdOut = open(const_cast<char*>(sOutput.c_str()), O_WRONLY);
// //       if (nFdIn == -1 || nFdOut == -1)
// //         return fb.Error(E_SLAVEMAIN_OPEN);
// //       dup2(nFdIn, 0);
// //       dup2(nFdOut, 1);
// //       dup2(nFdOut, 2);
// //       fb.Info(1) << "Connected as " << sServer << " with input " << sInput << " and output " << sOutput << "."; 
      
// //       pvm_stream ps2(true);
// //       ps2 << sServer << std::string("READY\n"+sServer);
// //       if (pvm_send(nReceiverTid, 0) < 0)
// //         return fb.Error(E_SLAVEMAIN_SEND) << " while sending READY message.";
// //     } 
// //     else if (sTag == "JOB")
// //     {
// //       std::string sJobID, sJob;
// //       ss >> sJobID >> sJob;
// //       std::cout << "JOB:\n" << sJobID << "\n" << sJob << "\nResult?\n";
// //       std::string sRes;
// //       std::getline(std::cin, sRes);
// //       pvm_stream ps2(true);
// //       ps2 << sServer << std::string("RESULTS\n"+sServer+"\n"+sJobID+"\n0\n"+sRes); 
// //       if (pvm_send(nReceiverTid, 0) < 0)
// //         return fb.Error(E_SLAVEMAIN_SEND) << " while sending results.";
// //       fb.Info(2) << "Sent results for job " << sJobID << ".";
// //     }
// //     else
// //     {
// //       fb.Info(1) << "Received unprocessed message. Tag: " << sTag << ".";
// //     }
// //   }
// }

// int main(int argc, char *argv[])
// {
//   Feedback fb("slave_stdio main");
//   pvm_mytid();
//   pvm_stream ps;
//   if (pvm_recv(-1, PvmSender::tid_message_id) < 0 ||
//       !(ps >> nReceiverTid).good())
//     return fb.Error(E_SLAVEMAIN_RECV) << " while receiving client-side receiver tid.";
//   else
//     fb.Info(2) << "received client-side receiver tid " << nReceiverTid << ".";

//   return 0;    
// }
// // int main(int argc, char *argv[])
// // {
// //   int nErr = SlaveServerReceiver::Instance().Run(argc, argv);
// //   if (nErr)
// //     std::cerr << "Slave server receiver returned error code " << nErr << ".\n";
// //   else
// //     std::cerr << "Slave server receiver completed successfully.\n";
// //   return nErr;
// // }


