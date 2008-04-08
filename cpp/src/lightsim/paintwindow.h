#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H
#include "paintarea.h"
#include "lightsim.h"

class PaintWindow : public QWidget
{
  Q_OBJECT

  public:
  PaintWindow (int w, int h, unsigned int scale, Lightsim2D *ls, QWidget * parent = 0 );
  QSize sizeHint() const {return paintArea->sizeHint();};
  void paintEvent(QPaintEvent * e);
  PaintArea * getPaintArea(){return paintArea;}
  void virtual paintWorld();
  void virtual paintWorldWithPruned();

protected:
  PaintArea * paintArea;
  QPixmap buffer;
  Lightsim2D *ls;
  unsigned int scale;
  unsigned int w;
  unsigned int h;
  void paintIt(bool paintPruned);
};

#endif
