#ifndef CELL_H_
#define CELL_H_

using namespace std;
class Cell {

private:
  unsigned int x;
  unsigned int y;
  unsigned int numHits;
public:
  Cell(int x, int y){this->x=x; this->y=y; numHits=0; };
  unsigned int getX() { return x; };
  unsigned int getY() { return y; };
  double getNumHits() { return numHits; }
  void addHit() { numHits++; }

};
#endif
