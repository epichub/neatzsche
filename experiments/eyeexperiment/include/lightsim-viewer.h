#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "lightsim.h"
#include "paintwindow.h"
#include <QApplication>
#include <QObject>
#include <QTimer>
#include "settings.h"
#include <sstream>
#include "eval.h"

class ReadTimer : public QObject {

Q_OBJECT

private:
  Lightsim2D ls2d;
  NEATsettings *set;
  LightsimEvaluator *ls2de;
  string filename2;
  TransferFunctions *tfs;
  Genome *genome;
  Phenotype *phenome;
  PaintWindow *pw;
  QFileSystemWatcher* watcher;
  QTimer *timer;
  unsigned int ms;
  int mode;
  char* filename;
  double cellsize;
  bool timerActive;

public:
  ReadTimer(char *args[]);

public slots:
  void reload();
  void scheduleReload();
};
