#include "cell.h"

Cell::Cell(int x, int y) {
  this->x=x;
  this->y=y;
  numHits=0;
  cells=new vector<Cell*>(); 
}

void Cell::addCell(Cell* c) { 
  cells->push_back(c); 
}
