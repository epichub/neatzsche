#include "lightsim-viewer.h"

ReadTimer::ReadTimer(char *args[])
  { 
    timerActive=false;
    mode=-1;
    this->mode=atoi(args[1]);
    this->ms=atoi(args[3]); 
    this->filename=args[2];
    this->cellsize=atof(args[7]);
    ls2d.init(cellsize);
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
      this->cellsize=set->getValue("cellsize");
      ls2de=new LightsimEvaluator(set,set->getValue("xmax"),set->getValue("ymax"),set->getValue("number_of_lightsources"));
    }
    else {
      set=new NEATsettings();
      std::ifstream f(filename);
      f >> ls2d;
      f.close();
      set->setValue("fitness_mode",1);
      set->setValue("ls_distance",ls2d.getLsdist());
      ls2de=new LightsimEvaluator(set,ls2d.getXmax(),ls2d.getYmax(),0);
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

/*
void ReadTimer::reload() {
  std::ifstream f(filename);
  f >> ls2d;
  f.close();
  ls2d.print();
  pw->updateLS(&ls2d);
  pw->paintWorld();
  timerActive = false;
}
*/

void ReadTimer::reload() {
  if(mode == 0) {
    genome=new Genome(tfs);
    std::ifstream f(filename2.c_str());
    f >> genome;
    f.close();
    phenome=new Phenotype(genome);
    ls2d.reset();
    ls2d.init(cellsize, phenome,  set->getValue("xmax"), set->getValue("ymax"), set->getValue("number_of_lightsources"), set->getValue("ls_distance"));
    ls2d.createVectors();
    ls2d.pruneBlockedVectors();
  }
  else if(mode ==1) {
    std::ifstream f(filename);
    f >> ls2d;
    f.close();
  }
  else { cerr << "Illegal mode: "<<mode<<endl; exit(1); }
  cout << "Fitness: "<< ls2de->f(&ls2d)<<" ";
  ls2d.print();    
  pw->updateLS(&ls2d);
  pw->paintWorld();
  timerActive = false;
  if(mode == 0) {
    delete phenome;
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


