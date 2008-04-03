#include "lightsim.h"

Lightsim2D::Lightsim2D(double cellsize) {
  init(cellsize);
}

Lightsim2D::Lightsim2D(double cellsize, unsigned int ** twodmap,unsigned int xmax,unsigned int ymax) {

  init(cellsize);

  for(unsigned int i=0; i<xmax;i++)
    {
      for(unsigned int j=0;j<ymax;j++)
      {
	if(twodmap[i][j] == ((unsigned int)0)) {
	  // Do nothing, empty
	}
	else if(twodmap[i][j] == ((unsigned int)1)) {
	  //cout << "found LS at "<<i<<","<<j<<"\n";
	  lightsources->push_back(new Lightsource(i,j));
	}
	else if(twodmap[i][j] == ((unsigned int)2)) {
	  //cout << "found OC at "<<i<<","<<j<<"\n";
	  opaquecells->push_back(new Opaquecell(i,j));
	}
	else if(twodmap[i][j] == ((unsigned int)3)) {
	  //cout << "found LSC at "<<i<<","<<j<<"\n";
	  LSCs->push_back(new LSC(i,j));
	}
	else {
	  cout << "Error: Got output: "<<twodmap[i][j]<<"\n";
	}
      }
    }

}

Lightsim2D::~Lightsim2D() {
  for(unsigned int i=0;i<lightsources->size();i++) {
    delete(lightsources->at(i));
  }
  delete(lightsources);

  for(unsigned int i=0;i<opaquecells->size();i++) {
    delete(opaquecells->at(i));
  }
  delete(opaquecells);

  for(unsigned int i=0;i<LSCs->size();i++) {
    delete(LSCs->at(i));
  }
  delete(LSCs);

  for(unsigned int i=0;i<lightvectors->size();i++) {
    delete(lightvectors->at(i));
  }
  delete(lightvectors);

  for(unsigned int i=0;i<deletedLightvectors->size();i++) {
    delete(deletedLightvectors->at(i));
  }
  delete(deletedLightvectors);
}

void Lightsim2D::init(double cellsize) {
  this->cellsize=cellsize;
  lightsources=new vector<Lightsource*>();
  opaquecells=new vector<Opaquecell*>();
  LSCs=new vector<LSC*>();
  lightvectors=new vector<nVector*>();
  deletedLightvectors=new vector<nVector*>();
}

std::istream& operator>>(std::istream& i, Lightsim2D * ls)
{
  string id;
  unsigned int x,y;
  while(i.good()) {
    i>>id;
    if(id.find("lsrc")!=string::npos) {
      //cout << "Found lsrc";
      i>>x>>y;
      ls->lightsources->push_back(new Lightsource(x,y));
    }
    else if(id.find("opc")!=string::npos) {
      //cout << "Found opc";
      i>>x>>y;
      ls->opaquecells->push_back(new Opaquecell(x,y));
    }
    else if(id.find("lsc")!=string::npos) {
      //cout << "Found LSC";
      i>>x>>y;
      ls->LSCs->push_back(new LSC(x,y));
    }
    else if(id.find("done")==string::npos){
      cout << "Error in datafile\n";
      exit(1);
    }
    if(id.find("done")==string::npos) {
      //      cout << " with "<<x<<","<<y<<"\n";
    }
    id="done";
  }
  return i;
}

void Lightsim2D::print() {
  cout << "length av LSRC OPC, LSC, LVec og Pruned er : " << lightsources->size() << "," <<opaquecells->size() << "," << LSCs->size() <<","<<lightvectors->size()<<","<<deletedLightvectors->size()<<"\n";
}

void Lightsim2D::createVectors() {
  //  cout << "Creating vectors...";
  for(unsigned int i=0;i<LSCs->size();i++) {
    for(unsigned int j=0;j<lightsources->size();j++) {
      lightvectors->push_back(new Lightvector(LSCs->at(i),lightsources->at(j)));
    }
  }
  //  cout<< "done!\n";
}

void Lightsim2D::pruneBlockedVectors() {
  //cout << "Pruning blocked vectors...";
  vector<lightvector*>::iterator it = lightvectors->begin();
  bool erased=false;
  //  nVector * shortest;
  while(it!=lightvectors->end()){
    erased=false;
    for(unsigned int j=0;j<opaquecells->size();j++) {
      /*
      shortest=(*it)->orthogonal(opaquecells->at(j)->getX(),opaquecells->at(j)->getY());
      if(shortest->scalarValue()<cellsize) {
	lightvectors->erase(it);
       	j = opaquecells->size();
	erased=true;
      }
      */
      //      delete shortest;
      if((*it)->getnVector()->orthogonalLength(opaquecells->at(j)->getX(),opaquecells->at(j)->getY()) <cellsize) {
	deletedLightvectors->push_back(*it);
	lightvectors->erase(it);
       	j = opaquecells->size();
	erased=true;
      }
      else { (*it)->getLSC()->addHit(); }
    }
    if(!erased) {
      ++it;
    }
  }
  //cout << "done!\n";
}
