#include "lightsim-viewer.h"

ReadTimer::ReadTimer(char *args[])
  { 
    timerActive=false;
    mode=-1;
    this->mode=atoi(args[1]);
    this->ms=atoi(args[3]); 
    this->filename=args[2];
    this->cellsize=atof(args[7]);
      
    //ls2d.init(cellsize);
    if(mode == 0) {
      stringstream ss;
      ss<<filename<<"/settings";
      set=new NEATsettings();
      std::ifstream f(ss.str().c_str());
      f>>set;
      f.close();
      phenome=new Phenotype();
      stringstream ss2;
      tfs = new TransferFunctions(set);
      ss2<<filename<<"/curgenome";
      filename2 = ss2.str();
      cout <<"Loading..."<<endl<<"settings: "<<ss.str()<<endl<<"genome: "<<ss2.str()<<endl;  
      cellsize=set->getValue("cellsize");
       
      ls2de=new LightsimEvaluator(set,set->getValue("xmax"),set->getValue("ymax"),set->getValue("number_of_lightsources"),cellsize,set->getValue("ls_distance"));
      //cout << "cellsize: "<<cellsize<<" xmax: "<<set->getValue("xmax")<<" ymax: "<<set->getValue("ymax")<<" lsnum: "<<set->getValue("number_of_lightsources")<<" ls_dist: "<<set->getValue("ls_distance")<<endl;
    }
    else {
      /*set=new NEATsettings();
      std::ifstream f(filename);
      f >> ls2d;
      f.close();
      set->setValue("fitness_mode",1);
      set->setValue("ls_distance",ls2d.getLsdist());
      ls2de=new LightsimEvaluator(set,ls2d.getXmax(),ls2d.getYmax(),0,cellsize,ls2d.getLsdist());*/
    }
    pw=new PaintWindow(atoi(args[4]),atoi(args[5]),atoi(args[6]),this->cellsize,atoi(args[8]),NULL); 
    reload();
    pw->show();

    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(ms);
    connect(timer, SIGNAL(timeout()), this, SLOT(reload()));

    watcher = new QFileSystemWatcher(this); 
    if(mode == 0) {
      watcher->addPath(filename2.c_str()); 
    }
    else {
      watcher->addPath(filename);
    }
    connect(watcher, SIGNAL(fileChanged(const QString &)), this, SLOT(scheduleReload()));
  }


void ReadTimer::reload() {
  if(mode == 0) {
    genome=new Genome(tfs);
    std::ifstream f(filename2.c_str());
    f >> genome;
    f.close();
    phenome=new Phenotype(genome);
    phenome->cleanNet();
    ls2d=new Lightsim2D(cellsize, phenome, set->getValue("xmax"), set->getValue("ymax"), set->getValue("number_of_lightsources"), set->getValue("ls_distance"));
    //cout << "cellsize: "<<set->getValue("cellsize")<<" xmax: "<<set->getValue("xmax")<<" ymax: "<<set->getValue("ymax")<<" lsnum: "<<set->getValue("number_of_lightsources")<<" ls_dist: "<<set->getValue("ls_distance")<<endl;
    ls2d->createVectors();
    ls2d->pruneBlockedVectors();
      /*
      f->cleanNet();
      
      ls2d=new Lightsim2D(cellsize,f,xmax,ymax,lsnum,ls_distance);
      ls2d->createVectors();
      ls2d->pruneBlockedVectors();
      
      f->setFitness(LightsimEvaluator::f(ls2d));
       */
  }
  else if(mode ==1) {
    std::ifstream f(filename);
    f >> *ls2d;
    f.close();
  }
  else { cerr << "Illegal mode: "<<mode<<endl; exit(1); }
  cout << "Fitness: "<< ls2de->f(ls2d)<<" ";
    cout << "Fitness2: " << ls2de->f(phenome)<<endl;
  ls2d->print();    
  pw->updateLS(ls2d);

  pw->paintWorld();
  timerActive = false;
  if(mode == 0) {
    delete phenome;
      if(ls2d != NULL)
          delete(ls2d); 
  }
}

void ReadTimer::scheduleReload() {
  if (timerActive) return;
  timer->start();
  timerActive = true;
}


int main(int argc, char *args[])
{
  if(argc<9) {
    cout <<"Usage: lightsim-viewer <mode [0(genome)/1(ls2d)]> <dir path/filename> <min update rate (ms)> <width> <height> <scale> <cellsize (not used in mode 0)> <paint pruned (0/1)>"<<endl;
    exit(1);
  } 
  QApplication app(argc,args);
  ReadTimer rt(args);
  return app.exec();
}


