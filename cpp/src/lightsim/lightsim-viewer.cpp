#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "lightsim.h"
#include "paintwindow.h"
#include <QApplication>

int main(int argc, char *args[])
{
  Lightsim2D *ls2d=new Lightsim2D(0.5);
  std::ifstream f(args[0]);
  f >> ls2d;
  f.close();
  ls2d->print();
  QApplication app(argc,args);
  PaintWindow *pw=new PaintWindow(1100,900,100,ls2d,NULL);
  pw->paintWorld();
  pw->show();
  return app.exec();
}
