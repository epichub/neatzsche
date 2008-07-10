#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_
#include "cell.h"
class Lightsource : public Cell {
public: 
  Lightsource(int x, int y) : Cell(x,y) {};
};

#endif
