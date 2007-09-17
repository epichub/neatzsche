/********************************************************************
 *   		master_stdio.cpp
 *   Created on Fri Mar 17 2006 by Boye A. Hoeverstad.
 *   
 *   Stub to run master node using standard input/output
 *******************************************************************/


// slave_mpi.h must be included before stdio. See comment in slave_mpi.h
#include "slave_mpi.h"

#include "master_stdio.h"

#include "master.h"
#include "utils.h"
#include <options.h>

#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <setjmp.h>

// FeedbackError E_MASTERMAIN_LOOPSETUP("Evaluation loop setup failed");
DEFINE_FEEDBACK_ERROR(E_MASTERMAIN_LOOPSETUP, "Evaluation loop setup failed")
// FeedbackError E_MASTERMAIN_LOOP("Evaluation loop failed");
DEFINE_FEEDBACK_ERROR(E_MASTERMAIN_LOOP, "Evaluation loop failed")
// FeedbackError E_MASTERMAIN_SETUP("The master failed during system setup");
DEFINE_FEEDBACK_ERROR(E_MASTERMAIN_SETUP, "The master failed during system setup")


using namespace std;

std::string sMaster;
pid_t master_pid = 0;
jmp_buf sigPipeEnv;



/********************************************************************
 *   Kill the master process if an interrupt is received.
 *******************************************************************/
// static void signal_handler(int nSignal)
// {
//   Feedback fb("master killer");
//   if (master_pid != 0)
//     KillProcess(master_pid, sMaster, fb);
//   exit(nSignal);
// }


/********************************************************************
 *   Pass on selected signals to the master process.
 *******************************************************************/
static void
SignalPassOn(int nSignal)
{
  Feedback fb("master signal handler");
  if (master_pid != 0)
  {
    fb.Info(2) << "Received signal " << nSignal
               << ".  Passing it on to master with pid " << master_pid << "."; 
    kill(master_pid, nSignal);
  }
  else
    fb.Info(2) << "Received signal " << nSignal
               << ", but master pid is 0, so it cannot be passed on.";
}



/********************************************************************
 *   Thread to simply pass on signals to master process, if this
 *   one is available.
 *******************************************************************/
void*
SignalPassThread(void *)
{
  std::list<int> sigsPassed;
  sigsPassed.push_back(SIGHUP);
  sigsPassed.push_back(SIGINT);
  sigsPassed.push_back(SIGQUIT);
  sigsPassed.push_back(SIGUSR1);
  sigsPassed.push_back(SIGUSR2);
  sigsPassed.push_back(SIGALRM);
  sigsPassed.push_back(SIGTERM);
  sigsPassed.push_back(SIGTSTP);
  sigsPassed.push_back(SIGCONT);
  sigsPassed.push_back(SIGCHLD);

  for (;;)
  {
    sigset_t sigSet;
    sigemptyset(&sigSet);
    for (std::list<int>::const_iterator itsig = sigsPassed.begin(); 
         itsig != sigsPassed.end(); itsig++)
      sigaddset(&sigSet, *itsig);

    int nSignal;
    sigwait(&sigSet, &nSignal);
    SignalPassOn(nSignal);
  }
  return 0;
}
  

/********************************************************************
 *   Signal handling function for main thread, responding only to
 *   SIGPIPE, and taking down distro system if this happens.
 *******************************************************************/
void
SignalPipe(int)
{
  siglongjmp(sigPipeEnv, 1);
}


int RunEvalLoop(int nNumSlaves, fdostream &masterWriteStdin, fdistream &masterReadStdout)
{
  
//  extern bool bMaster;
//  bMaster = true;
  
  Feedback fb("Master evaluation loop");

  Master *pMaster;
  if (DistributorLauncher::Instance().CreateDistributor(&pMaster, nNumSlaves))
    return fb.Error(E_MASTERMAIN_LOOPSETUP) << "The \"CreateDistributor\" call failed.\n";

      // Master created, unblock SIGPIPE to allow for destroying
      // all slaves if the master goes down.
      // Block all signals in all threads
  if (sigsetjmp(sigPipeEnv, 1))
  {
    fb.Warning("SIGPIPE received on master side, assuming master process has died.  "
               "Shutting down distribution system.");
    master_pid = 0;
    DistributorLauncher::Instance().DestroyDistributor(pMaster);
    return fb.Error(E_MASTERMAIN_LOOP);
  }

  sigset_t sigSet;
  sigemptyset(&sigSet);
  sigaddset(&sigSet, SIGPIPE);
  pthread_sigmask(SIG_UNBLOCK, &sigSet, 0);
  Signal(SIGPIPE, SignalPipe);
  
  std::string sMasterInputMode, sMasterOutputMode, sBatchMode;
  int nBatchSize, nMasterOutputLines;
  if (Options::Instance().Option("batch-mode", sBatchMode)
      || Options::Instance().Option("batch-size", nBatchSize)
      || Options::Instance().Option("master-input-mode", sMasterInputMode)
      || Options::Instance().Option("master-output-mode", sMasterOutputMode)
      || Options::Instance().Option("master-output-lines", nMasterOutputLines))
    return fb.Error(E_MASTERMAIN_LOOPSETUP) << ": Failed to get the necessary options.";

  if (sMasterOutputMode == "SIMPLE")
  {
    std::stringstream ssMode;
    ssMode << nMasterOutputLines;
    sMasterOutputMode += " " + ssMode.str();
  }

//   fb.Warning("DEBUG: Main taking a break...");
//   sleep(10);
//   fb.Warning("DEBUG: Break over!");

  std::vector<std::string> data, results;
  while (masterReadStdout.good())
  {

    fb.Info(2, "Reading job data from master...");

    if (sBatchMode == "EOF")
    {
      std::string sBatch;

      std::string sEOF, sLine;
      if (!std::getline(masterReadStdout, sEOF))
      {
        fb.Info(0, "Failed to read a new batch from master, assuming simulation is completed.");
        break;
      }

      while (std::getline(masterReadStdout, sLine) && sLine != sEOF)
        sBatch += sLine + "\n";

      if (sLine != sEOF) // Then getline failed
      {
        fb.Warning("Failed to read a job data from master: End-of-file or read error before user specified batch delimiter (" + sEOF + ") was found.");
        break;
      }

      std::stringstream ssBatch(sBatch);

      data.clear();
      int nJob = 0;
      while (ssBatch.peek() != std::ios::traits_type::eof())
      {
        nJob++;
        std::string sJobData;
        if (ReadJobData(fb, ssBatch, sMasterOutputMode, sJobData))
          return fb.Error(E_MASTERMAIN_LOOP) << ": Failed to read job number " << nJob << " from master.";
        if (sJobData.empty())
          return fb.Error(E_MASTERMAIN_LOOP) << ": Job number " << nJob << " contained no data when read from master.";
        data.push_back(sJobData);
      }

    }
    else if (sBatchMode == "SIMPLE")
    {
      data.resize(nBatchSize);

      bool bSimComplete = false;
      for (size_t nJob = 0; nJob < data.size(); nJob++)
        if (ReadJobData(fb, masterReadStdout, sMasterOutputMode, data[nJob]))
        {
          std::stringstream ssErr;
          ssErr << ": Error when reading job number " << nJob << " from master.";
          if (nJob == 0)
            ssErr << "  Assuming the simulation is complete.";
          bSimComplete = true;
          fb.Warning(ssErr.str());
          break;
        }

      if (bSimComplete)
        break;
    }
    else
      return fb.Error(E_MASTERMAIN_LOOP) << ". Unknown batch-mode: " << sBatchMode << ". Accepted values are EOF and SIMPLE.";

    fb.Info(2) << "Read " << data.size() << " jobs from master via stdin, now sending data for evaluation...\n";
    results.resize(data.size());

    if (pMaster->Evaluate(data, results))
      return fb.Error(E_MASTERMAIN_LOOP) << "Distributed evaluation failed.";

    fb.Info(2, "Results received! Writing results to master...\n");

    for (size_t nJob = 0; nJob < results.size(); nJob++)
    {
//      cerr << "Writing result " << nLine << ": " << results[nLine] << ".\n";
      if (WriteJobData(fb, masterWriteStdin, sMasterInputMode, results[nJob]))
        return fb.Error(E_MASTERMAIN_LOOP) << ": Failed to write results to master.";
    }

    fb.Info(2) << "Wrote " << results.size() << " results to master.\n";

  }
  
  fb.Info(1, "Simulation complete. Shutting down slaves...");
  DistributorLauncher::Instance().DestroyDistributor(pMaster);
  fb.Info(1, "Evaluation Finished.");
  return 0;
}



int 
master_main(int argc, char *argv[])
{
//   std::cerr << "WARNING: Main taking a break at the very beginning. Pid is " << getpid() << "\n";
//   sleep(10);
//   std::cerr << "Break over!\n";

      // Block all signals in all threads
  sigset_t sigSet;
  sigfillset(&sigSet);
  pthread_sigmask(SIG_BLOCK, &sigSet, 0);

  Feedback fb("Master main");
  int nInfoLevel;
  std::string sInfoShow, sInfoHide;
  if (Options::Instance().Option("verbosity", nInfoLevel)
      || Options::Instance().Option("verbosity-showonly", sInfoShow)
      || Options::Instance().Option("verbosity-dontshow", sInfoHide))
    return fb.Error(E_MASTERMAIN_SETUP) << ": Unable to get system verbosity options.";
  fb.SetInfoLevel(nInfoLevel);
  fb.SetShowHide(sInfoShow, sInfoHide);

      // Create signal forwarding thread
  pthread_t sigThread;
  if (pthread_create(&sigThread, 0, SignalPassThread, 0))
    return fb.Error(E_MASTERMAIN_SETUP) << ": Unable to launch signal handling thread.";

  std::string sMasterArgs;
  if (Options::Instance().Option("master-program", sMaster)
      || Options::Instance().Option("master-arguments", sMasterArgs))
    return fb.Error(E_MASTERMAIN_SETUP) << ": Unable to get master program name and/or arguments from options.";

  fb.Info(1) << "Distributor master node loaded with pid " << getpid() << " and thread id " << pthread_self << ".";

      // Create two pipes, input pipe and output pipe, and connect to
      // streams.  For Pvm, this is necessary since we fork later
      // on. For MPI, we just do it to get blocking on read.
  MemoryPipe pipeInput, pipeOutput;
  mpistream pipeInputRead(&pipeInput), pipeOutputRead(&pipeOutput);
  mpostream pipeInputWrite(&pipeInput), pipeOutputWrite(&pipeOutput);

      // Send write end of output pipe and read end of input pipe to message central
  MessageRouter::Instance().SetIOChannels(&pipeInputRead, &pipeOutputWrite);
  if (MessageRouter::Instance().StartReceiver())
    return 1;
    
  fb.Info(3, "Message router loaded.");

//   fb.Warning("Main taking a break...");
//   sleep(5);
//   fb.Warning("Break over!");

      // Send read end of output pipe to MPISender.
  MPISender sender(&argc, &argv, &pipeOutputRead);
  int nNumSlaves = sender.GetNumSlaves();
  if (sender.Start())
    return fb.Error(E_MASTERMAIN_SETUP) << ": Failed to launch MPI sender thread.\n";

//   fb.Info(1, "MPI sender loaded.");
//   fb.Warning("DEBUG: Main taking a break...");
//   sleep(5);
//   fb.Warning(1, "Break over!");

      // Send write end of input pipe to MPIReceiver.
  MPIReceiver receiver(&pipeInputWrite, sender);
  if (receiver.Start())
    return fb.Error(E_MASTERMAIN_SETUP) << ": Failed to launch MPI receiver thread.\n";

  fb.Info(2, "MPI connection channels loaded.  Starting evaluation loop...");

//   fb.Warning("DEBUG: Main taking a break...");
//   sleep(5);
//   fb.Warning("DEBUG: Break over!");

      // Connect to master as the last thing to do before evaluating,
      // to avoid killing it if any of the above processing fails.
  fb.Info(2) << "Connecting to master " << sMaster << "...";

//   signal(SIGINT, signal_handler);
//   signal(SIGTERM, signal_handler);

//   fb.Warning("DEBUG: Main taking a break...");
//   sleep(10);
//   fb.Warning("DEBUG: Break over!");

  fdostream masterWriteStdin;
  fdistream masterReadStdout;
  if (ConnectProcess(sMaster, sMasterArgs, &masterWriteStdin, &masterReadStdout, 0, &master_pid, 0))
    return fb.Error(E_MASTERMAIN_SETUP) << ": Failed to launch master! Master program was \"" << sMaster << "\".";

  fb.Info(2) << "Successfully connected to master.";

      // Only kill the master process if something goes wrong,
      // otherwise let it die a natural death.
  if (int nRet = RunEvalLoop(nNumSlaves, masterWriteStdin, masterReadStdout))
  {
    KillProcess(master_pid, sMaster, fb);
    return nRet;
  }

//       // Sleep to see if the slaves will go down because we leave the mpi subsystem time enough to pass on TERMINATE messages...
//   fb.Warning("DEBUG: Main taking a break...");
//   sleep(10);
//   fb.Warning("DEBUG: Break over!");

  fb.Info(2, "Evaluation loop complete.  Waiting for message passing subsystem to shut down..");
  pthread_join(receiver.GetThreadId(), 0);
  fb.Info(2, "MPI message receiver stopped and joined.");
  pthread_join(sender.GetThreadId(), 0);
  fb.Info(2, "MPI message sender stopped and joined.");
  pthread_join(MessageRouter::Instance().GetReceiverThreadId(), 0);
  fb.Info(2, "Message router stopped and joined.  Waiting for master program to finish.");
  pid_t waitRet = wait(0);
  if (waitRet != master_pid)
  {
    int nSleep = 30;
    fb.Warning() << "Failed to wait for master ('wait' system call returned " 
                 << waitRet << " instead of " << master_pid << " as expected)."
                 << " Will pause for " << nSleep << " seconds before going down...";
    sleep(nSleep);
  }
  else
    fb.Info(1, "Distributed evaluation complete.");

  return 0;
}
