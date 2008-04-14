#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "lightsim.h"
#include "paintwindow.h"
#include <QApplication>

int main(int argc, char *args[])
{
  if(argc!=7) {
    cout <<"Usage: lightsim-viewer <filename> <width> <height> <scale> <cellsize> <paint pruned (0/1)>"<<endl;
    exit(1);
  }
  Lightsim2D ls2d=Lightsim2D(atof(args[5]));
  ls2d.readFromFile(args[1]);
  ls2d.createVectors();
  ls2d.pruneBlockedVectors();
  ls2d.print();
  QApplication app(argc,args);
  PaintWindow *pw=new PaintWindow(atoi(args[2]),atoi(args[3]),atoi(args[4]),atoi(args[6]),NULL);
  pw->updateLS(&ls2d);
  pw->paintWorld();
  pw->show();
  return app.exec();
}
