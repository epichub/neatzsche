#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "lightsim.h"
#include "paintwindow.h"
#include <QApplication>
#include <QObject>
#include <QTimer>

class ReadTimer : public QObject {

Q_OBJECT

private:
  Lightsim2D ls2d;
  PaintWindow *pw;
  unsigned int ms;
  char* filename;
  double cellsize;

public:
  ReadTimer(char *args[]);

public slots:
  void update();
};
