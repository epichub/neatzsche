/*
  Copyright 2007 Bj�rn Magnus Mathisen
  This file is part of NEATzsche.

  NEATzsche is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  NEATzsche is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NEATzsche; if not, write to the Free Software Foundation,
  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 */
#include "runner.h"

void Interruptcallback::operator()(int sig){
  string sINP;
  int iINP=0;
  cerr << "\nstopsignal triggered  press 1 for interactive evaluation, 2 for evaluator show "
       << "\nor 3 for debug eval: ";
  cin >> sINP; iINP = atoi(sINP.c_str());
  if(best!=NULL){
    if(iINP==1){
      fe->interact(best);
    }else if(iINP==2){
      cerr << "show:\n" << fe->show(best);
      cerr << "fitness: " << fe->f(best) << endl;
    }else if(iINP==3)
      fe->debugeval(best);
    ofstream ofs("signal-best");
    ofs << best->getGenome();
    ofs.close();
  }else
    cerr << "stopsignal triggered before first eval, no phenotype available to look at." << endl;;

  cerr << "press 1 to exit: ";
  iINP = 0;
  cin >> sINP; iINP = atoi(sINP.c_str());
  if(iINP==1)
    exit(0);
//   else
//     run->runLoop();
}

void NEATRunner::runLoop()
{
  //setting up signal handlers
//   (void)signal(SIGINT,signalhandler);
//   (void)signal(SIGTERM,signalhandler);
//   (void)signal(SIGKILL,signalhandler);
//
  time_t startt,tmpt;long totaltime=0;
  //  cerr << "humhum" << endl;
  if(currentgraphf==NULL)
    currentgraphf = new ofstream(sCurrentGraphFile.c_str());
  
  //  cerr << "humhum2" << endl;
  int countruns=0;
//   int oelitism=0;
//   Genome * oseed=NULL;
//   int osize=pop->getMembers()->size();
  bool localFE=false;
  vector<double> beststate;
  generations++;
  Evaluator * bak = NULL;
  if(nodes==0){
//     cerr << "nodes is 0, setting up for local runs.." << endl;
    localFE=true;
  }// else
//     cerr << "running cluster code.." << endl;
  writeRunfile(false,basefile,infoline,pid);
  pop->fe = icb->fe;
  while(!stop){
    if(pop->getGeneration() == coevo->getStartGeneration()){
      bak = ev;
      ev = coevo;
    }
    startt = time(0);
    if(localFE){
      ev->evaluate(pop->getMembers(),pop->getMembers()->size());
    }else{
      cerr << "outputting pop" << endl;
      outputPopulation(pop,nodes,coevo,mc,pipeio); //stream the population out to nodes for evaluation	
      cerr << "evaling pop" << endl;
      ev->evaluate(pop->getMembers(),mc);//sweet..
      cerr << "reading pop" << endl;
      readFitness(pop,mc); //read the corresponding returned fitness values
    }

    //checking and updating for the overall best phenotype.
    //do population/species sorting and stat updating
//     cerr << "sorting and updating...";
    pop->updateSpeciesStats();
    pop->sortmembers();
    pop->sortspecies();

    avgf = pop->calcAvgFitness();

    //keeping a copy of generation champ:
    gbest = pop->getCopyOfCurrentBest();
    setChamp(best,gbest);

    ofstream ofs(sCurrentGenomeFile.c_str());
    ofs << best->getGenome();

    ofs.close();

//     if(pop->getGeneration()%2==0){
//       cerr << icb->fe->show(best);
//     }
    icb->best = best;
    writenetwork(best,sCurrentXMLGenomeFile);


    //writing stats to file
    *currentgraphf << getStatString(pop,avgf);
    currentgraphf->flush();

    //updating smoothed graph data..
    updateSmoothData(smoothdata,pop,avgf,countruns+1);

    coevo->update(pop); // update the coevolution data..

    tmpt = (time(0)-startt);
    totaltime += tmpt;

    cerr << (pop->getGeneration()+1) << ":"
	 << " curmax: " << pop->getMembers()->at(0)->getFitness()
	 << " bestid: "<<best->getID()<<" bestfitness: "<< best->getFitness()
	 << " maxfitness: " << pop->getHighestFitness() 
	 << " curmin: " << pop->getMembers()->at(pop->getMembers()->size()-1)->getFitness()
	 << " species: " << pop->getSpecies()->size() 
	 << " size: " << pop->getMembers()->size() 
	 << " time: " << tmpt 
	 << " time/size: " << (double)tmpt/(double)pop->getMembers()->size() << endl;
//     cerr.flush();
    //run the code that adjusts fitness according to species age and size..
    //select the lucky ones for reprocicration..
//     cerr << "selecting...";
//     cerr.flush();
    sel->select(pop,0);
    //do the mating
//     cerr << "reproducing...";
    rep->reproduce(pop);
    if(generations>0&&(pop->getGeneration()+1)==generations&&runs==(countruns+1)){ // stopconditions
      setChamp(sbest,best);
      stop = true;
    }else{
      if(generations>0&&(pop->getGeneration()+1)==generations){
//  	cerr << "going run reset" << endl;
	//generation run is over lets go on to the next run..
	countruns++;
	//keep superchamp across runs..
	Phenotype * tmp = best;
	best = NULL;
	setChamp(sbest,tmp);
	//reset population...
// 	oseed = pop->getOriginalSeed();
// 	oelitism = pop->getOriginalInitialElitism();
// 	delete pop;
// 	pop = new Population(set,tfs);
// 	pop->genesis(oseed,osize,oelitism);
	if(pop->spawn)
	  pop->resetSpawn();
	else
	  pop->resetGenesis();
	if(bak!=NULL){
	  ev = bak;
	  bak = NULL;
	}
      }
    }
  }

  ofstream ofs(sFinalGenomeFile.c_str());
  ofs << sbest->getGenome();
  ofs.close();
  cerr << "final best fitness" << sbest->getFitness() << endl;
//   cerr << "done writing finalgenome file " << endl;
//   cerr << "writing smoothed final graph file generations: " << generations
//        << "smoothdata size:" << sizeof(smoothdata)/sizeof(smoothdata[0]) << endl;
  ofstream finalgraphf(finalgraphfile.c_str());
  for(int i=0;i<generations-1;i++)
    finalgraphf << smoothdata[i][0] << " " 
		<< smoothdata[i][1] << " " 
		<< smoothdata[i][2] << endl;
  cerr << "done writing smoothed final graph file to " << finalgraphfile << endl;
//   cerr << "!!! total time divided by number of evals: " << (double)totaltime/((double)(generations*countruns*osize))<<endl ;
  //close graph files..
  finalgraphf.close();
  currentgraphf->close();
//   cerr << "before writerunfile" << endl;
  writeRunfile(true,basefile,infoline,pid);  
//   cerr << "after writerunfile" << endl;
}
