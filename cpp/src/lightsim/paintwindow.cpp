#include "paintwindow.h"
#include <QRectF>
#include <QColor>

PaintWindow::PaintWindow (int w, int h, unsigned int scale, double objectsizeFactor, bool paintPruned, QWidget * parent)
  : QWidget(parent)
{
  paintArea = new PaintArea(w,h);
  this->w=w;
  this->h=h;
  this->scale=scale;
  this->objectsizeFactor=objectsizeFactor;
  this->paintPruned=paintPruned;
  resize(w,h);
}

void PaintWindow::updateLS(Lightsim2D *ls) {
  this->ls=ls; 
}

void PaintWindow::paintWorld() {
  paintArea->clear(Qt::white);

  for(unsigned int i=0;i<ls->getLSCs()->size(); i++) {
    paintArea->drawFilledRectangle(Qt::green,
				   (ls->getLSCs()->at(i)->getX()*scale)-((objectsizeFactor*scale)/2),
				   (ls->getLSCs()->at(i)->getY()*scale)-((objectsizeFactor*scale)/2),
				   objectsizeFactor*scale,objectsizeFactor*scale);
  }

  for(unsigned int i=0;i<ls->getLightvectors()->size(); i++) {
    nPoint* tmp=ls->getLightvectors()->at(i)->getnVector()->endPoint();
    paintArea->drawLine(Qt::yellow,
			ls->getLightvectors()->at(i)->getnVector()->start->at(0)*scale,
			ls->getLightvectors()->at(i)->getnVector()->start->at(1)*scale,
			tmp->coords->at(0)*scale,
			tmp->coords->at(1)*scale);
  }
  if(paintPruned) {
    nPoint *tmp=0;
    for(unsigned int i=0;i<ls->getDeletedLightvectors()->size(); i++) {
      tmp=ls->getDeletedLightvectors()->at(i)->getnVector()->endPoint();
      paintArea->drawLine(Qt::red,
			  ls->getDeletedLightvectors()->at(i)->getnVector()->start->at(0)*scale,
			  ls->getDeletedLightvectors()->at(i)->getnVector()->start->at(1)*scale,
			  tmp->coords->at(0)*scale,
			  tmp->coords->at(1)*scale);   
    }
  }
  for(unsigned int i=0;i<ls->getLightsources()->size(); i++) {
    paintArea->drawFilledRectangle(Qt::blue,
				   (ls->getLightsources()->at(i)->getX()*scale)-((objectsizeFactor*scale)/2),
				   (ls->getLightsources()->at(i)->getY()*scale)-((objectsizeFactor*scale)/2),
				   objectsizeFactor*scale,objectsizeFactor*scale);
  }

  for(unsigned int i=0;i<ls->getOpaquecells()->size(); i++) {
    paintArea->drawFilledRectangle(Qt::black,
				   (ls->getOpaquecells()->at(i)->getX()*scale)-((objectsizeFactor*scale)/2),
				   (ls->getOpaquecells()->at(i)->getY()*scale)-((objectsizeFactor*scale)/2),
				   objectsizeFactor*scale,objectsizeFactor*scale);
  }

  buffer=paintArea->getPixmap();
  this->update();
}


void PaintWindow::paintEvent(QPaintEvent * e)
{
  QPainter painter(this);
  painter.drawPixmap(0,0,w,h,buffer);
}

