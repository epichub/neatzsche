#ifndef _GENE_H_
#define _GENE_H_
#include "ann.h"

using namespace std;
class Genome;
class Gene {
private:
  bool enabled;
  int marker;//the historical marker
  double mutation;
  NeuralNode * from;
  NeuralNode * to;
  double w;
  Genome * g;
  //  bool isrecur; //needed to know how to make
                //new links in mutation code later.
public:
  Gene(){mutation=0;marker=0;}
  Gene(Gene * ge){enabled=ge->enabled;marker=ge->marker;
    mutation=ge->mutation;from=ge->from;to=ge->to;w=ge->w;
    g=ge->g;}
  
  Gene(int markerin, NeuralNode *  fromin, NeuralNode * toin, double wi, Genome *go)
  {
    enabled = true; marker = markerin; from = fromin; to = toin; w = wi; g = go; mutation=w;
  }
  Gene * duplicate(Genome * g);
  void disable(){ enabled = false; }
  void enable(){ enabled = true; }
  NeuralNode * getFrom(){ return from; }
  NeuralNode * getTo(){ return to; }
  void setFrom(NeuralNode * ifrom) { from = ifrom; }
  void setTo(NeuralNode * ito) { to = ito; }
  double getWeight(){return w;}
  void setWeight(double we){w=we;mutation=we;};
  void setGenome(Genome * go){g = go;}
  int getMarker(){
    return marker;}
  bool isEnabled(){return enabled;}
  double getMutation(){return mutation;}
  bool equal(Gene * g);
  //  bool recurrent(){return isrecur;}
  friend ostream& operator<< (ostream& os, const Gene *g);
  friend istream& operator>> (istream& is, Gene *g);
};
inline bool genemarkercomp(Gene * g1, Gene * g2){return g1->getMarker() < g2->getMarker();}
#endif //_GENE_H_
