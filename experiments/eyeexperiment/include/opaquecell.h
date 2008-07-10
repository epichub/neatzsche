#ifndef OPAQUECELL_H_
#define OPAQUECELL_H_

#include "cell.h"

class Opaquecell : public Cell {
public:
  Opaquecell(int x, int y) : Cell(x,y){};
};

#endif
