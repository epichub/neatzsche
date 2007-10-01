#include "paintwindow.h"
#include <QRectF>
#include <QColor>
//#include <Qtopia>


PaintWindow::PaintWindow (int w, int h, Wrapper *iwrapper, BBWorld * ibbw, QWidget * parent)
  : QWidget(parent)
{
  paintArea = new PaintArea(w,h);

  bbw = ibbw;
  plr = bbw->getPlayer();
  wrapper = iwrapper;
  std::cerr << "plr: " << plr << std::endl;
  if(plr)
    plr->w = wrapper;
  thread = new Senderthread(wrapper, plr);
  connect(wrapper,SIGNAL(guiSignal()),this,SLOT(updGreenGui()));
  //connect(connectBtn,SIGNAL(clicked()),this,SLOT(connectGame()));
  //paintWorld();
  //update();
  //QDesktopWidget desktopWidget;
  //setFixedSize(desktopWidget.availableGeometry().size());
}


void PaintWindow::updGreenGui()
{
  paintWorld();
}


void PaintWindow::paintWorld()
{
  bbw->update();
  paintArea->clear(Qt::white);

  QColor plrColor = QColor(plr->getR(), plr->getG(), plr->getB());
  paintArea->setColor(plrColor);
  if(!(plr->point->at(0) == -1 && plr->point->at(1) == -1))
    paintArea->drawFilledRectangle(plrColor, plr->point->at(0), plr->point->at(1), 10 + plr->size, 10 + plr->size);

  for(unsigned int i=0;i<bbw->playerCount();i++)
    {

      BBPlayer * tempPlayr = bbw->getPlayer(i);
//       std::cerr << "drawing player at: " << tempPlayr->point->at(0) << "," << tempPlayr->point->at(1) << std::endl;
      QColor tempColor = QColor(tempPlayr->getR(), tempPlayr->getG(), tempPlayr->getB());
      paintArea->setColor(tempColor);
      if(tempPlayr->point->at(0)<0 || tempPlayr->point->at(0) >= 240 || tempPlayr->point->at(1) <  0 || tempPlayr->point->at(1) >= 320)
	std::cerr << "not drawing player out of bounds : " << tempPlayr->point->at(0) << " , "<<  tempPlayr->point->at(1) << std::endl;
      else
	paintArea->drawFilledRectangle(tempColor, tempPlayr->point->at(0), tempPlayr->point->at(1), 9 + tempPlayr->size, 9 + tempPlayr->size);
    }

  for(unsigned int i=0;i<bbw->powerupSize();i++)
    {
      Powerup * tempPwrup = bbw->getPowerup(i);

      QPoint tempPoint = QPoint(tempPwrup->point->at(0), tempPwrup->point->at(1));
      QImage tempImage;
//       std::cerr << "printing image at point: " << tempPwrup->point->at(0)<< " , " << tempPwrup->point->at(1) << std::endl;
      if(tempPwrup->wot == 'i')
	{
	  tempImage = QImage("size.png");
	}
      if(tempPwrup->wot == 's')
	{

	  tempImage = QImage("speed.png");
	}
      if(tempPwrup->wot == 'p')
	{
	  tempImage = QImage("strength.png");
	}
      paintArea->drawImage(tempPoint,tempImage);
    }

  Trap * trap = bbw->getTrap();
  QImage trapImage = QImage("hole.png");
//   std::cerr << "trap h:" << trapImage.height() << "trap w:" << trapImage.width() << std::endl;
//     std::cerr << "trap at x:" << trap->point->at(0) << "trap y:" << trap->point->at(1) << std::endl;
  if(trap->point->at(0)>-1 && trap->point->at(0) < 240 && trap->point->at(1) > -1 && trap->point->at(1) < 320){
//     std::cerr << "drawing trap at x:" << trap->point->at(0) << "trap y:" << trap->point->at(1) << std::endl;
    QPoint trapPoint(trap->point->at(0), trap->point->at(1));
    paintArea->drawImage(trapPoint,trapImage);
  }
  else
    std::cerr << "not drawing trap at x:" << trap->point->at(0) << "trap y:" << trap->point->at(1) << std::endl;

  buffer = paintArea->getPixmap();
  update();
}
void PaintWindow::paintWorld2()
{

}


void PaintWindow::plrStartpos(int posX, int posY)
{
  //plr = bbw->getPlayer();
  paintArea->clear(Qt::white);
  QColor plrColor = QColor(plr->getR(), plr->getG(), plr->getB());
  paintArea->setColor(plrColor);
  paintArea->drawFilledRectangle(plrColor, posX, posY, 10, 10);
  /*
    Trap * trap = bbw->getTrap();
    QImage trapImage = QImage("hole.png");
    QPoint trapPoint = QPoint(trap->point->at(0), trap->point->at(1));
    paintArea->drawImage(trapPoint,trapImage);
  */
  buffer = paintArea->getPixmap();
  update();
}

void PaintWindow::paintEvent(QPaintEvent * e)
{
  QPainter painter(this);
  painter.drawPixmap(0,0,240,320,buffer);
}

void PaintClientWindow::keyPressEvent(QKeyEvent *event)
{
  switch (event->key()) {
  case Qt::Key_1:
    plr->NORTHWEST();
    plr->update();
    //  thread->stop();
    paintWorld();
    break;
  case Qt::Key_2:
    plr->NORTH();
    plr->update();
    // thread->stop();
    paintWorld();
    break;
  case Qt::Key_3:
    plr->NORTHEAST();
    plr->update();
    // thread->stop();
    paintWorld();
    break;
  case Qt::Key_4:
    plr->WEST();
    plr->update();
    // thread->stop();
    paintWorld();
    break;
  case Qt::Key_6:
    plr->EAST();
    plr->update();
    // thread->stop();
    paintWorld();
    break;
  case Qt::Key_7:
    plr->SOUTHWEST();
    plr->update();
    // thread->stop();
    paintWorld();
    break;
  case Qt::Key_8:
    plr->SOUTH();
    plr->update();
    //thread->stop();
    paintWorld();
    break;
  case Qt::Key_9:
    plr->SOUTHEAST();
    plr->update();
    //thread->stop();
    paintWorld();
    break;
  case Qt::Key_0:
    hide();
    lw->show();
    break;
    //default:
    //QFrame::keyPressEvent(event);
  }
}


void PaintClientWindow::keyReleaseEvent(QKeyEvent *event)
{
  switch (event->key()) {
  case Qt::Key_1:
    //         paintWorld2();
    thread->start();
    //    plr->stop();
    break;
  case Qt::Key_2:
    //     	 paintWorld2();
    thread->start();
    //    plr->stop();
    break;
  case Qt::Key_3:
    //     	 paintWorld2();
    thread->start();
    //    plr->stop();
    break;
  case Qt::Key_4:
    //     	 paintWorld2();
    thread->start();
    //    plr->stop();
    break;
  case Qt::Key_6:
    //     	paintWorld2();
    thread->start();
    //    plr->stop();
    break;
  case Qt::Key_7:
    //	 	paintWorld2();
    thread->start();
    //    plr->stop();
    break;
  case Qt::Key_8:
    //	 	paintWorld2();
    thread->start();
    //    plr->stop();
    break;
  case Qt::Key_9:
    //     paintWorld2();
    thread->start();
    //    plr->stop();
    break;
    //default:
    //QFrame::keyPressEvent(event);
  }
}
void PaintClientWindow::closeEvent(QCloseEvent *event)
{
  std::cerr << "i closeevent" << std::endl;
  wrapper->disconnect(bbw->getPlayer()->getID());
}
void PaintBotWindow::paintWorld()
{
  for(unsigned int i=0;i<vects->size();i++){
    paintArea->drawLine(vects->at(i)->second,vects->at(i)->first.start->at(0),vects->at(i)->first.start->at(1),
			vects->at(i)->first.start->at(0)+vects->at(i)->first.vec->at(0),
			vects->at(i)->first.start->at(0)+vects->at(i)->first.vec->at(0));
  }
  deleteVectors();
  PaintWindow::paintWorld();
}
