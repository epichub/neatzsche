#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H
#include "paintarea.h"
#include "lightsim.h"

class PaintWindow : public QWidget
{
  Q_OBJECT

  public:
  PaintWindow (int w, int h, Lightsim2D *ls, QWidget * parent = 0 );
  QSize sizeHint() const {return paintArea->sizeHint();};
  void paintEvent(QPaintEvent * e);
  PaintArea * getPaintArea(){return paintArea;}
  virtual void paintWorld();


protected:
  PaintArea * paintArea;
  QPixmap buffer;
  Lightsim2D *ls;
  unsigned int scale;
};

#endif
