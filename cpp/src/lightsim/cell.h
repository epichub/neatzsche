#ifndef CELL_H_
#define CELL_H_

using namespace std;

class Cell {

private:
  unsigned int x;
  unsigned int y;
  unsigned int numHits;
  std::vector <Cell*>* cells;
public:
  Cell(int x, int y);
  ~Cell() {
    /*
    for(int i=0;i<cells->size();i++) {
      delete cells->at(i);
    }
    */
    //delete cells;
  };
  unsigned int getX() { return x; };
  unsigned int getY() { return y; };
  double getNumHits() { return numHits; };
  void addHit() { numHits++; }
  void addCell(Cell* c);

};
#endif
