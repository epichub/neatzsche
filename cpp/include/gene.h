/*
  Copyright 2007 Bjørn Magnus Mathisen
  This file is part of NEATzsche.

  NEATzsche is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  NEATzsche is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NEATzsche; if not, write to the Free Software Foundation,
  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 */
#ifndef _GENE_H_
#define _GENE_H_
#include "ann.h"

using namespace std;

typedef struct {
  int fid;
  int tid;
  int marker;
  double w;
  bool enabled;
}  GeneSmall;

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

  void fromData(int fid, int tid, double w, int marker, bool enbld);
  Gene * duplicate(Genome * g);
  GeneSmall * getSmall()
  {GeneSmall * gs = new GeneSmall(); gs->fid = from->getID(); 
    gs->tid = to->getID(); gs->marker = marker; gs->w = w; gs->enabled = enabled; return gs;}
  void fromSmall(GeneSmall * gs, Genome * genome);
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
