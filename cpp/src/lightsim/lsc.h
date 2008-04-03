#ifndef LSC_H_
#define LSC_H_

class LSC : public Cell {
private:
  unsigned int numHits;
public:
  LSC(int x, int y) : Cell(x,y) { numHits=0; };
  double getNumHits() { return numHits; }
  void addHit() { numHits++; }
};

#endif

