#include "lightsim-viewer.h"

ReadTimer::ReadTimer(char *args[])
  { 
    this->ms=atoi(args[2]); 
    this->filename=args[1];
    this->cellsize=atof(args[6]);
    pw=new PaintWindow(atoi(args[3]),atoi(args[4]),atoi(args[5]),atoi(args[7]),NULL); 
    ls2d.init(cellsize);
    update();
    pw->show();
    QTimer *pollTimer = new QTimer(this);
    connect(pollTimer, SIGNAL(timeout()), this, SLOT(update()));
    pollTimer->start(ms);
  }


void ReadTimer::update() {
  std::ifstream f(filename);
  f >> ls2d;
  f.close();
  ls2d.print();
  pw->updateLS(&ls2d);
  pw->paintWorld();
}

int main(int argc, char *args[])
{
  if(argc!=8) {
    cout <<"Usage: lightsim-viewer <filename> <updaterate ms> <width> <height> <scale> <cellsize> <paint pruned (0/1)>"<<endl;
    exit(1);
  }
  QApplication app(argc,args);
  ReadTimer rt(args);
  return app.exec();
}


