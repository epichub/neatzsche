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

Lightsim2D::Lightsim2D(double cellsize, Phenotype *f, unsigned int xmax, unsigned int ymax, unsigned int lsnum) {

  init(cellsize);

  vector<double> tmpin;
  vector<double> tmpout;
  double tmpstr;
  int tmpwinner;
  int centerX=xmax/2;
  int centerY=ymax/2;
  for(unsigned int i=0;i<xmax;i++) {
    for(unsigned int j=0;j<ymax;j++) {
      if(i == 0 &&((j % (ymax/lsnum)) == 0 || j == 0)) {
	lightsources->push_back(new Lightsource(i,j));
      }
      else {
	tmpin.push_back(i);
	tmpin.push_back(j);
	tmpin.push_back(sqrt(pow(i-centerX,2)+pow(j-centerY,2)));
	tmpout=f->react(tmpin);
	tmpstr=0;
	tmpwinner=0;
	for(unsigned int k=0;k<tmpout.size();k++){
	  if(tmpout.at(k)>tmpstr&&tmpout.at(k)>0.3) {
	    tmpwinner=k+1;
	    tmpstr=tmpout.at(k);
	  }
	}
	tmpin.clear();
	
	if(tmpwinner == ((unsigned int)0)) {
	  // Do nothing, empty
	}
	else if(tmpwinner == ((unsigned int)1)) {
	  //cout << "found OC at "<<i<<","<<j<<"\n";
	  opaquecells->push_back(new Opaquecell(i,j));
	}
	else if(tmpwinner == ((unsigned int)2)) {
	  //cout << "found LSC at "<<i<<","<<j<<"\n";
	  LSCs->push_back(new LSC(i,j));
	}
	else {
	  cout << "Error: Got output: "<<tmpwinner<<"\n";
	}
      }
    }
  }
}

Lightsim2D::~Lightsim2D() {
  for(unsigned int i=0;i<lightvectors->size();i++) {
    delete(lightvectors->at(i));
  }
  delete(lightvectors);

  for(unsigned int i=0;i<deletedLightvectors->size();i++) {
    delete(deletedLightvectors->at(i));
  }
  delete(deletedLightvectors);

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
}

void Lightsim2D::init(double cellsize) {
  this->cellsize=cellsize;
  lightsources=new vector<Lightsource*>();
  opaquecells=new vector<Opaquecell*>();
  LSCs=new vector<LSC*>();
  lightvectors=new vector<Lightvector*>();
  deletedLightvectors=new vector<Lightvector*>();
}


std::ostream& operator<< (ostream& os, const Lightsim2D *ls)
{

  for(unsigned int i=0;i<ls->getLSCs()->size(); i++) {
    os <<ls->getLSCs()->at(i)->getX()<<" "<<ls->getLSCs()->at(i)->getY();
    if(i!=ls->getLSCs()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  for(unsigned int i=0;i<ls->getOpaquecells()->size(); i++) {
    os <<ls->getOpaquecells()->at(i)->getX()<<" "<<ls->getOpaquecells()->at(i)->getY();
    if(i!=ls->getOpaquecells()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  for(unsigned int i=0;i<ls->getLightvectors()->size(); i++) {
    os <<ls->getLightvectors()->at(i)->getLightsource()->getX()<<" "<<ls->getLightvectors()->at(i)->getLightsource()->getY()<<" "<<ls->getLightvectors()->at(i)->getLSC()->getX()<<" "<<ls->getLightvectors()->at(i)->getLSC()->getY();
    if(i!=ls->getLightvectors()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  for(unsigned int i=0;i<ls->getDeletedLightvectors()->size(); i++) {
    os <<ls->getDeletedLightvectors()->at(i)->getLightsource()->getX()<<" "<<ls->getDeletedLightvectors()->at(i)->getLightsource()->getY()<<" "<<ls->getDeletedLightvectors()->at(i)->getLSC()->getX()<<" "<<ls->getDeletedLightvectors()->at(i)->getLSC()->getY();
    if(i!=ls->getDeletedLightvectors()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  for(unsigned int i=0;i<ls->getLightsources()->size(); i++) {
    os <<ls->getLightsources()->at(i)->getX()<<" "<<ls->getLightsources()->at(i)->getY();
    if(i!=ls->getLightsources()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  return os;
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
  vector<Lightvector*>::iterator it = lightvectors->begin();
  bool erased=false;
  while(it!=lightvectors->end()){
    for(unsigned int j=0;j<opaquecells->size();j++) {
      if((*it)->getnVector()->orthogonalLength(opaquecells->at(j)->getX(),opaquecells->at(j)->getY()) <cellsize) {
	deletedLightvectors->push_back(*it);
	lightvectors->erase(it);
       	j = opaquecells->size();
	erased=true;
      }
      else { 
	erased=false; 
      }
    }
    if(!erased) {
      ++it;
    }
    else {
      (*it)->getLSC()->addHit(); 
      (*it)->getLightsource()->addHit(); 
    }
  }
  //cout << "done!\n";
}
