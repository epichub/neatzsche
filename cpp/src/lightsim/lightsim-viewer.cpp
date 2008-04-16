#include "lightsim-viewer.h"

ReadTimer::ReadTimer(char *args[])
  { 
    timerActive=false;
    this->ms=atoi(args[2]); 
    this->filename=args[1];
    this->cellsize=atof(args[6]);
    pw=new PaintWindow(atoi(args[3]),atoi(args[4]),atoi(args[5]),atof(args[6]),atoi(args[7]),NULL); 
    ls2d.init(cellsize);
    reload();
    pw->show();

    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(ms);
    connect(timer, SIGNAL(timeout()), this, SLOT(reload()));

    watcher = new QFileSystemWatcher(this); 
    watcher->addPath(filename); 
    connect(watcher, SIGNAL(fileChanged(const QString &)), this, SLOT(scheduleReload()));
  }


void ReadTimer::reload() {
  std::ifstream f(filename);
  f >> ls2d;
  f.close();
  ls2d.print();
  pw->updateLS(&ls2d);
  pw->paintWorld();
  timerActive = false;
}

void ReadTimer::scheduleReload() {
  if (timerActive) return;
  timer->start();
  timerActive = true;
}


int main(int argc, char *args[])
{
  if(argc!=8) {
    cout <<"Usage: lightsim-viewer <filename> <min update rate (ms)> <width> <height> <scale> <cellsize> <paint pruned (0/1)>"<<endl;
    exit(1);
  }
  QApplication app(argc,args);
  ReadTimer rt(args);
  return app.exec();
}


