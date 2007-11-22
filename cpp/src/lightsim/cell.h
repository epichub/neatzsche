#ifndef CELL_H_
#define CELL_H_

using namespace std;
class Cell {

private:
  unsigned int x;
  unsigned int y;
public:
  Cell(int x, int y){this->x=x; this->y=y;};
  unsigned int getX() { return x; };
  unsigned int getY() { return y; };
};
#endif
