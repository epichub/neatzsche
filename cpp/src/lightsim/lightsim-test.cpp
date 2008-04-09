#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "lightsim.h"
#include "paintwindow.h"
#include <QApplication>

int main(int argc, char *args[])
{
  Lightsim2D ls2d=Lightsim2D(atof(args[2]));
  ls2d.readFromFile(args[1]);
  ls2d.createVectors();
  ls2d.pruneBlockedVectors();
  ls2d.print();
  QApplication app(argc,args);
  PaintWindow *pw=new PaintWindow(1100,900,100,true,NULL);
  pw->updateLS(&ls2d);
  pw->paintWorld();
  pw->show();
  return app.exec();
}
