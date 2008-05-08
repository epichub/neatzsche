#include "lightsim-viewer.h"

ReadTimer::ReadTimer(char *args[])
  { 
    timerActive=false;
    mode=-1;
    this->mode=atoi(args[1]);
    this->ms=atoi(args[3]); 
    this->filename=args[2];
    this->cellsize=atof(args[7]);
    if(mode == 0) {
      phenome=new Phenotype();
      stringstream ss;
      stringstream ss2;
      ss<<filename<<".settings";
      set=new NEATsettings();
      std::ifstream f(ss.str().c_str());
      f>>set;
      f.close();
      tfs = new TransferFunctions(set);
      ss2<<filename<<".genome";
      filename2 = ss2.str();
      }
    pw=new PaintWindow(atoi(args[4]),atoi(args[5]),atoi(args[6]),atof(args[7]),atoi(args[8]),NULL); 
    ls2d.init(cellsize);
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
    cout <<"Usage: lightsim-viewer <mode [0(genome)/1(ls2d)]> <filename(except settings/genome)> <min update rate (ms)> <width> <height> <scale> <cellsize> <paint pruned (0/1)>"<<endl;
    exit(1);
  } 
  QApplication app(argc,args);
  ReadTimer rt(args);
  return app.exec();
}


