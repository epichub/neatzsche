#include "paintarea.h"

PaintArea::PaintArea(int iw, int ih)
{
  h = ih; w = iw;
  buffer = QPixmap(w,h);
  buffer.fill(Qt::white);
}

void PaintArea::drawRectangle(int x, int y, int width, int height)
{
  QPainter p(&buffer);
  p.setBrush(brush);
  p.drawRect(x, y, width, height);
  p.end();
}

void PaintArea::drawFilledRectangle(QColor color, int x, int y, int width, int height)
{
  QPainter p(&buffer);
  p.setBrush(brush);
  p.setPen(color);
  p.drawRect(x, y, width, height);
  p.fillRect(x, y, width, height, brush);
  p.end();
}
void PaintArea::drawLine(QColor color, int x1, int y1, int x2, int y2)
{
  QPainter p(&buffer);
  p.setBrush(brush);
  p.setPen(color);
  p.drawLine(x1, y1, x2, y2);
//   p.fillRect(x, y, width, height, brush);
  p.end();
}
void PaintArea::drawImage (const QPoint & point, const QImage & image )
{
  QPainter p(&buffer);
  p.drawImage(point,image);
  p.end();
}

void PaintArea::setSize( QResizeEvent * event )
{
  w = event->size().width(); h = event->size().height();
  QPixmap tmp(w,h);
  tmp.fill(Qt::white);
  QPainter qp(&tmp);
  qp.drawPixmap(0,0,buffer);
  buffer = tmp;
}
QSize PaintArea::sizeHint() const
{
  return QSize(w,h);
}
