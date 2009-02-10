#include "paintwindow.h"
#include <QRectF>
#include <QColor>

PaintWindow::PaintWindow (int w, int h, Lightsim2D *ls, QWidget * parent)
  : QWidget(parent)
{
  paintArea = new PaintArea(w,h);
  this->ls=ls;
  scale=100;
}

void PaintWindow::paintWorld()
{
  paintArea->clear(Qt::white);
  for(unsigned int i=0;i<ls->getLightsources()->size(); i++) {
    paintArea->drawFilledRectangle(Qt::blue,
				   ls->getLightsources()->at(i)->getX()*scale,
				   ls->getLightsources()->at(i)->getY()*scale,
				   10,10);
  }
  for(unsigned int i=0;i<ls->getLSCs()->size(); i++) {
    paintArea->drawFilledRectangle(Qt::green,
				   ls->getLSCs()->at(i)->getX()*scale,
				   ls->getLSCs()->at(i)->getY()*scale,
				   10,10);
  }
  for(unsigned int i=0;i<ls->getOpaquecells()->size(); i++) {
    paintArea->drawFilledRectangle(Qt::black,
				   ls->getOpaquecells()->at(i)->getX()*scale,
				   ls->getOpaquecells()->at(i)->getY()*scale,
				   10,10);
  }

  for(unsigned int i=0;i<ls->getLightvectors()->size(); i++) {
    nPoint* tmp=ls->getLightvectors()->at(i)->endPoint();
    paintArea->drawLine(Qt::yellow,
			ls->getLightvectors()->at(i)->start->at(0)*scale,
			ls->getLightvectors()->at(i)->start->at(1)*scale,
			tmp->coords->at(0)*scale,
			tmp->coords->at(1)*scale);
  }
  for(unsigned int i=0;i<ls->getDeletedLightvectors()->size(); i++) {
    nPoint* tmp=ls->getDeletedLightvectors()->at(i)->endPoint();
    paintArea->drawLine(Qt::red,
			ls->getDeletedLightvectors()->at(i)->start->at(0)*scale,
			ls->getDeletedLightvectors()->at(i)->start->at(1)*scale,
			tmp->coords->at(0)*scale,
			tmp->coords->at(1)*scale);

  }
  
  buffer=paintArea->getPixmap();
}


void PaintWindow::paintEvent(QPaintEvent * e)
{
  QPainter painter(this);
  painter.drawPixmap(0,0,11*scale,9*scale,buffer);
}

