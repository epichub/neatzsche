#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H
#include "paintarea.h"
#include "../bbworld.h"
#include "wrapper.h"
#include "senderthread.h"

class BBWorld;
class BBPlayer;
class GuiWrapper;
class Lobbywindow;
class Senderthread;

class PaintWindow : public QWidget
{
  Q_OBJECT

  public:
  PaintWindow (int w, int h, Wrapper *iwrapper, BBWorld * ibbw, QWidget * parent = 0 );

  QSize sizeHint() const {return paintArea->sizeHint();};
  void paintEvent(QPaintEvent * e);
  PaintArea * getPaintArea(){return paintArea;}
  virtual void paintWorld();
  void paintWorld2();
  void plrStartpos(int posX, int posY);
  void setPlayer(BBPlayer * iplr){plr=iplr;}				      
public slots:
  void updGreenGui();

protected:
  BBPlayer * plr;
  BBWorld * bbw;
  PaintArea * paintArea;
  QPixmap buffer;
//   Lobbywindow * lw;
  Wrapper *wrapper;
  Senderthread *thread;
//   void keyPressEvent(QKeyEvent *event);
//   void keyReleaseEvent(QKeyEvent *event);
// protected:
//   void closeEvent(QCloseEvent *event);
  


};

class PaintClientWindow : public PaintWindow
{
  Q_OBJECT

  public:
  PaintClientWindow (int w, int h, GuiWrapper *iwrapper, Lobbywindow *ilw, BBWorld * ibbw, QWidget * parent = 0 )
    : PaintWindow(w,h,((Wrapper*)iwrapper),ibbw,parent) {gw = iwrapper; lw = ilw;};
  virtual void paintWorld(){PaintWindow::paintWorld();}
  Lobbywindow * lw;
  GuiWrapper * gw;
protected:
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
protected:
  void closeEvent(QCloseEvent *event);
//   void paintWorld();  


};

class PaintBotWindow : public PaintWindow
{
  Q_OBJECT
private:
  std::vector<std::pair<nVector,QColor> *> * vects;
  void deleteVectors()
  {
    for(unsigned int i=0;i<vects->size();i++)
      delete vects->at(i);
    delete vects;
    vects = new std::vector<std::pair<nVector,QColor>*>();
  }
public:
  PaintBotWindow (int w, int h, Wrapper *iwrapper, BBWorld * ibbw, QWidget * parent = 0 )
    : PaintWindow(w,h,iwrapper,ibbw,parent) {vects = new std::vector<std::pair<nVector,QColor>*>();};
  void addVector(nVector v, QColor c){vects->push_back(new std::pair<nVector,QColor>(v,c));}
  virtual void paintWorld();
};
#endif
