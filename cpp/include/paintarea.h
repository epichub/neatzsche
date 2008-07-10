#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QtGui>

class PaintArea
{
private:
  QPixmap buffer;
  QBrush brush;
  int h;
  int w;

public:
  PaintArea(int iw, int ih);
  void drawRectangle(int x, int y, int width, int height);
  void drawFilledRectangle(QColor color, int x, int y, int width, int height);
  void drawLine(QColor color, int x1, int y1, int x2, int y2);
  void drawImage (const QPoint & point, const QImage & image );
  void clear(const QColor & fillColor = Qt::white){buffer.fill(fillColor);}
  void setSize( QResizeEvent * event );
  void setColor(QColor b){brush = b;}
  QPixmap getPixmap(){return buffer;}
  QSize sizeHint() const;
};

#endif
