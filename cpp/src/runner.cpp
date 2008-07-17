/*
  Copyright 2007 Bjørn Magnus Mathisen
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
}

void NEATRunner::runLoop()
{
  //setting up signal handlers
  (void)signal(SIGINT,signalhandler);
  (void)signal(SIGTERM,signalhandler);
  (void)signal(SIGKILL,signalhandler);
  //
  time_t startt,tmpt;long totaltime=0;
  int countruns=0;

  vector<double> beststate;
  generations++;
  Evaluator * bak = NULL;
  if(nodes==0&&localFE==false){
    localFE=true;
  }else if(!localFE)
    cerr << "running cluster code.." << endl;
  writeRunfile(false,basefile,infoline,pid);
  pop->fe = icb->fe;
  stringstream sgfc; sgfc << sgf.str() << "-" << countruns << ".xml";
  if(speciationGraph)
    sg = new SpecGraph((int)pop->getMembers()->size(),generations,sgfc.str());
  stringstream sCurrentGenomeFilesuffixless; sCurrentGenomeFilesuffixless << sCurrentGenomeFile.str();
  stringstream sCurrentGenomeFilec; sCurrentGenomeFilec << sCurrentGenomeFile.str() << "-" << countruns;
  stringstream sCurrentXMLGenomeFilec; sCurrentXMLGenomeFilec << sCurrentXMLGenomeFile.str() << "-" << countruns << ".xml";
  stringstream sCurrentGraphFilec; sCurrentGraphFilec << sCurrentGraphFile.str() << "-" << countruns;
  if(currentgraphf==NULL){
    currentgraphf = new ofstream(sCurrentGraphFile.str().c_str());
  }
  ofstream ofs(sCurrentGenomeFilec.str().c_str());
  ofstream ofs2(sCurrentGenomeFilesuffixless.str().c_str());
  bool slaveStop = false;

  while(!stop){
    if(coevo != NULL && pop->getGeneration() == (coevo->getStartGeneration()+1)){
      cout << "doing coevo!?" << endl;
      bak = ev;
      ev = coevo;
    }
    startt = time(0);
    if(localFE){
      ev->evaluate(pop->getMembers(),pop->getMembers()->size());
    }else{
      if(generations>0&&(pop->getGeneration()+2)==generations&&runs==(countruns+1)){
	cout << "setter slavestop.." << endl;
	slaveStop = true;
      }
      comm->outputPopulation(pop,nodes,coevo,mc,slaveStop); //stream the population out to nodes for evaluation	
      ev->evaluate(pop->getMembers(),mc);//sweet..
      comm->readFitness(pop,mc); //read the corresponding returned fitness values
    }

    //checking and updating for the overall best phenotype.
    //do population/species sorting and stat updating
    pop->updateSpeciesStats();
    pop->sortmembers();
    pop->sortspecies();

    avgf = pop->calcAvgFitness();

    //keeping a copy of generation champ:
    gbest = pop->getCopyOfCurrentBest();
    setChamp(best,gbest); 
    best->getGenome()->setSeed(rands);
    ofs.open(sCurrentGenomeFilec.str().c_str());
    ofs << best->getGenome();
    ofs.close();
    ofs2.open(sCurrentGenomeFilesuffixless.str().c_str());
    ofs2 << best->getGenome();
    ofs2.close();

    //     if(pop->getGeneration()%2==0){
    //       cerr << icb->fe->show(best);
    //     }

    icb->best = best;
    writenetwork(best,sCurrentXMLGenomeFilec.str());
    if(speciationGraph)
      sg->update(pop);
    //writing stats to file

    *currentgraphf << getStatString(pop,avgf);
    currentgraphf->flush();
    //updating smoothed graph data..
    updateSmoothData(smoothdata,pop,avgf,countruns+1);
    if(coevo!=NULL)
      coevo->update(pop); // update the coevolution data..

    tmpt = (time(0)-startt);
    totaltime += tmpt;

    cerr << (pop->getGeneration()+1) << ":"
	 << " curmaxid: "<<pop->getMembers()->at(0)->getID()<<" curmax: " << pop->getMembers()->at(0)->getFitness()
	 << " bestid: "<<best->getID()<<" bestfitness: "<< best->getFitness()
	 << " maxfitness: " << pop->getHighestFitness() 
	 << " curmin: " << pop->getMembers()->at(pop->getMembers()->size()-1)->getFitness()
	 << " species: " << pop->getSpecies()->size() 
	 << " size: " << pop->getMembers()->size() 
	 << " time: " << tmpt 
	 << " time/size: " << (double)tmpt/(double)pop->getMembers()->size() << endl;

    //run the code that adjusts fitness according to species age and size..
    //select the lucky ones for reprocicration..

    sel->select(pop,0);
    //do the mating    
    rep->reproduce(pop);
    if(generations>0&&(pop->getGeneration()+1)==generations&&runs==(countruns+1)){ // stopconditions
      setChamp(sbest,best);
      stop = true;
      if(speciationGraph){
	sg->writetofile();
	delete sg;
      }
    }else{
      if(generations>0&&(pop->getGeneration()+1)==generations){
	//generation run is over lets go on to the next run..
	countruns++;
	//keep superchamp across runs..
	Phenotype * tmp = best;
	best = NULL;
	setChamp(sbest,tmp);
	//reset population...
	if(pop->spawn)
	  pop->resetSpawn();
	else
	  pop->resetGenesis();
	if(bak!=NULL){
	  ev = bak;
	  bak = NULL;
	}
	sg->writetofile();
	if(speciationGraph){
	  delete sg;
	  sgfc.str(""); sgfc << sgf.str() << "-" << countruns << ".xml";
	  sg = new SpecGraph((int)pop->getMembers()->size(),generations,sgfc.str());
	}
	sCurrentGenomeFilec.str(""); sCurrentGenomeFilec << sCurrentGenomeFile.str() << "-" << countruns;
	sCurrentXMLGenomeFilec.str(""); sCurrentXMLGenomeFilec << sCurrentXMLGenomeFile.str() << "-" << countruns << ".xml";
	sCurrentGraphFilec.str(""); sCurrentGraphFilec << sCurrentGraphFile.str() << "-" << countruns;
	delete currentgraphf; currentgraphf = new ofstream(sCurrentGraphFilec.str().c_str());

      }
    }
  }
  ofstream ofsuper(sFinalGenomeFile.c_str());
  ofsuper << sbest->getGenome();
  ofsuper.close();
  cout << "final best fitness" << sbest->getFitness() << endl;
  delete sbest;
  ofstream finalgraphf(finalgraphfile.c_str());
  for(int i=0;i<generations-1;i++)
    finalgraphf << smoothdata[i][0]/(double)runs << " " 
		<< smoothdata[i][1]/(double)runs << " " 
		<< smoothdata[i][2]/(double)runs << endl;
  for(int i=0;i<generations-1;i++)
    delete[] smoothdata[i];
  delete[] smoothdata;

  //close graph files..
  finalgraphf.close();
  currentgraphf->close();
  delete currentgraphf;
  writeRunfile(true,basefile,infoline,pid);  
  
}
