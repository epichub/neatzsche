#include "lightsim.h"

Lightsim2D::Lightsim2D(double cellsize) {
  init(cellsize);
}

Lightsim2D::Lightsim2D(double cellsize, unsigned int ** twodmap) {
  init(cellsize);
  for(unsigned int i=0; i<sizeof(twodmap)/sizeof(twodmap[0]);i++)
    {
      for(unsigned int j=0;j<sizeof(twodmap[0])/sizeof(twodmap[0][0]);j++)
      {
	if(twodmap[i][j] == ((unsigned int)1)) {
	  cout << "found LS at "<<i<<","<<j<<"\n";
	  lightsources->push_back(new Lightsource(i,j));
	}
	else if(twodmap[i][j] == ((unsigned int)2)) {
	  cout << "found OC at "<<i<<","<<j<<"\n";
	  opaquecells->push_back(new Opaquecell(i,j));
	}
	else if(twodmap[i][j] == ((unsigned int)3)) {
	  cout << "found LSC at "<<i<<","<<j<<"\n";
	  LSCs->push_back(new LSC(i,j));
	}
	else {
	  cout << "Error: Got output: "<<twodmap[i][j]<<"\n!";
	}
      }
    }
  createVectors();
  pruneBlockedVectors();
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
  cout << "length av LSRC OPC og LSC er : " << lightsources->size() << "," <<opaquecells->size() << "," << LSCs->size() <<"\n";
  cout << "number of lightvectors is: " << lightvectors->size() <<"\n";
}

void Lightsim2D::createVectors() {
  for(unsigned int i=0;i<LSCs->size();i++) {
    for(unsigned int j=0;j<lightsources->size();j++) {
      lightvectors->push_back(new nVector(LSCs->at(i)->getX(),LSCs->at(i)->getY(),lightsources->at(j)->getX(),lightsources->at(j)->getY()));
    }
  }
}

void Lightsim2D::pruneBlockedVectors() {
  vector<nVector*>::iterator it = lightvectors->begin();
  bool erased=false;
  while(it!=lightvectors->end()){
    erased=false;
    cout << "checking lightvector: ("<<(*it)->start->at(0)<<","<<(*it)->start->at(1)<<") + t("<<(*it)->vec->at(0)<<","<<(*it)->vec->at(1)<<")" << endl;
    for(unsigned int j=0;j<opaquecells->size();j++) {
      //      if((*it)->twodHasPoint(opaquecells->at(j)->getX(),opaquecells->at(j)->getY(),0.5)) {
      nVector * tmpvec=(*it)->orthogonal(*new nPoint(opaquecells->at(j)->getX(),opaquecells->at(j)->getY()));
      //      cout << "ocx: "<<opaquecells->at(j)->getX()<<" ocy: "<<opaquecells->at(j)->getY()<<" ovx: "<<tmpvec->vec->at(0)<<" ovy: "<<tmpvec->vec->at(1)<<" tmpvec->scalarValue(): " << tmpvec->scalarValue() << endl;
      if(tmpvec->scalarValue()<cellsize) {
	deletedLightvectors->push_back(*it);
	lightvectors->erase(it);
	//       cout << "Checking if: "<<opaquecells->at(j)->getX()<<","<<opaquecells->at(j)->getY()<<" blocks "<<(*it)->start->at(0)<<","<<(*it)->start->at(1)<<" with V=["<<(*it)->vec->at(0)<<","<<(*it)->vec->at(1)<<"]\n";
		cout<< "!!!! It did! pruning that one.\n";
	j = opaquecells->size();
	erased=true;
      }else{
	//	cout<< "@@@@ NO GO" << endl;
      }
    }
    if(!erased) {
      ++it;
    }
  }
}
