#include "lightsim.h"

Lightsim2D::Lightsim2D() {}

Lightsim2D::Lightsim2D(double cellsize) {
  init(cellsize);
}

Lightsim2D::Lightsim2D(double cellsize, unsigned int ** twodmap,unsigned int xmax,unsigned int ymax) {

  init(cellsize,xmax,ymax);

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
	  cerr << "Error: Got output: "<<twodmap[i][j]<<"\n";
	}
      }
    }

}

Lightsim2D::Lightsim2D(double cellsize, Phenotype *f, unsigned int xmax, unsigned int ymax, unsigned int lsnum, unsigned int ls_dist) {

  init(cellsize, f, xmax, ymax, lsnum, ls_dist);

}

void Lightsim2D::init(double cellsize, Phenotype *f, unsigned int xmax, unsigned int ymax, unsigned lsnum, unsigned int ls_dist) {

  init(cellsize,xmax,ymax);

  ls_distance=ls_dist;
  vector<double> tmpin;
  vector<double> tmpout;
  double tmpdist;
  int tmpwinner;
  int centerX=xmax/2;
  int centerY=ymax/2;

  for(unsigned int i=ls_distance;i<(xmax+ls_distance);i++) {
    for(unsigned int j=0;j<ymax;j++) {
      /*
      if(i == 0 &&((j % (unsigned int)(floor((ymax/(double)lsnum)+0.5))) == skewNum)) {
	lightsources->push_back(new Lightsource(i,j));
      }
      
      else {
      */
	tmpin.push_back(i-ls_distance);
	tmpin.push_back(j);
	tmpin.push_back(sqrt(pow((i-ls_distance)-(double)centerX,2)+pow(j-(double)centerY,2)));
	tmpout=f->react(tmpin);
	tmpdist=-1;
	tmpwinner=0;

	//cerr << "output is: ";
	for(unsigned int k=0;k<tmpout.size();k++){
	  //cerr <<tmpout.at(k)<<" ";
	  if(fabs(tmpout.at(k))<0.15 &&
	     (fabs(tmpout.at(k))<tmpdist||tmpdist==-1)) {
	    tmpwinner=k+1;
	    tmpdist=fabs(tmpout.at(k));
	  }
	}
	//cout<<endl;
	tmpin.clear();
	
	if(tmpwinner == ((unsigned int)0)) {
	  // Do nothing, empty
	}
	else if(tmpwinner == ((unsigned int)1)) {
	  //	  cout << "found OC at "<<i<<","<<j<<"\n";
	  opaquecells->push_back(new Opaquecell(i,j));
	}
	else if(tmpwinner == ((unsigned int)2)) {
	  //cout << "found LSC at "<<i<<","<<j<<"\n";
	  LSCs->push_back(new LSC(i,j));
	}
	else {
	  cerr << "Error: Got output: "<<tmpwinner<<"\n";
	}
	//     }
    }
  }
  double lsSpacing=ymax/(double)lsnum;
  unsigned int skewNum=(ymax-(lsSpacing*(lsnum-1)))/2;

  for(unsigned int i=0;i<lsnum;i++) {
    lightsources->push_back(new Lightsource(0,skewNum+floor(i*lsSpacing)));
  }
}

Lightsim2D::~Lightsim2D() {
  clear();
}

void Lightsim2D::reset() {
  clear();
  init(cellsize);
}

void Lightsim2D::clear() {
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

void Lightsim2D::init(double cellsize, unsigned int xmax, unsigned int ymax) {

  this->xmax=xmax;
  this->ymax=ymax;
  init(cellsize);

}

void Lightsim2D::init(double cellsize) {
  this->cellsize=cellsize;
  lightsources=new vector<Lightsource*>();
  opaquecells=new vector<Opaquecell*>();
  LSCs=new vector<LSC*>();
  lightvectors=new vector<Lightvector*>();
  deletedLightvectors=new vector<Lightvector*>();
}


std::ostream& operator<< (ostream& os, Lightsim2D *ls)
{
  os << ls->getXmax() << " " << ls->getYmax() << ls->getLsdist() <<"\n";
  
  os << ls->getLSCs()->size()<< " ";
  for(unsigned int i=0;i<ls->getLSCs()->size(); i++) {
    os <<ls->getLSCs()->at(i)->getX()<<" "<<ls->getLSCs()->at(i)->getY();
    if(i!=ls->getLSCs()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  os << ls->getOpaquecells()->size()<< " ";
  for(unsigned int i=0;i<ls->getOpaquecells()->size(); i++) {
    os <<ls->getOpaquecells()->at(i)->getX()<<" "<<ls->getOpaquecells()->at(i)->getY();
    if(i!=ls->getOpaquecells()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  os << ls->getLightvectors()->size()<< " ";
  for(unsigned int i=0;i<ls->getLightvectors()->size(); i++) {
    os <<ls->getLightvectors()->at(i)->getLightsource()->getX()<<" "<<ls->getLightvectors()->at(i)->getLightsource()->getY()<<" "<<ls->getLightvectors()->at(i)->getLSC()->getX()<<" "<<ls->getLightvectors()->at(i)->getLSC()->getY();
    if(i!=ls->getLightvectors()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  os << ls->getDeletedLightvectors()->size()<< " ";
  for(unsigned int i=0;i<ls->getDeletedLightvectors()->size(); i++) {
    os <<ls->getDeletedLightvectors()->at(i)->getLightsource()->getX()<<" "<<ls->getDeletedLightvectors()->at(i)->getLightsource()->getY()<<" "<<ls->getDeletedLightvectors()->at(i)->getLSC()->getX()<<" "<<ls->getDeletedLightvectors()->at(i)->getLSC()->getY();
    if(i!=ls->getDeletedLightvectors()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  os << ls->getLightsources()->size()<< " ";
  for(unsigned int i=0;i<ls->getLightsources()->size(); i++) {
    os <<ls->getLightsources()->at(i)->getX()<<" "<<ls->getLightsources()->at(i)->getY();
    if(i!=ls->getLightsources()->size()-1) { 
      os << " "; 
    }
  }
  os << "\n";

  return os;
}

std::istream& operator>>(std::istream& ins, Lightsim2D& ls)
{
  ls.reset();
  int num=0;
  string s;
  unsigned int x,y,x2,y2;
  ins>>s;
  ls.setXmax(atoi(s.c_str()));
  ins>>s;
  ls.setYmax(atoi(s.c_str()));
  ins>>s;
  ls.setLsdist(atoi(s.c_str()));
  ins>>s;
  num=atoi(s.c_str());
  cout << "num er: "<<num;
  for(unsigned int i=0;i<num;i++) {
    ins>>s;
    x=atoi(s.c_str());
    ins>>s;
    y=atoi(s.c_str());
    ls.getLSCs()->push_back(new LSC(x,y));
  }
  
  ins>>s;
  num=atoi(s.c_str());
  for(unsigned int i=0;i<num;i++) {
    ins>>s;
    x=atoi(s.c_str());
    ins>>s;
    y=atoi(s.c_str());
    ls.getOpaquecells()->push_back(new Opaquecell(x,y));
  }
  
  ins>>s;
  num=atoi(s.c_str());
  for(unsigned int i=0;i<num;i++) {
    ins>>s;
    x=atoi(s.c_str());
    ins>>s;
    y=atoi(s.c_str());
    ins>>s;
    x2=atoi(s.c_str());
    ins>>s;
    y2=atoi(s.c_str());
    ls.getLightvectors()->push_back(new Lightvector(x,y,x2,y2));
  }
  
  ins>>s;
  num=atoi(s.c_str());
  for(unsigned int i=0;i<num;i++) {
    ins>>s;
    x=atoi(s.c_str());
    ins>>s;
    y=atoi(s.c_str());
    ins>>s;
    x2=atoi(s.c_str());
    ins>>s;
    y2=atoi(s.c_str());
    ls.getDeletedLightvectors()->push_back(new Lightvector(x,y,x2,y2));
  }
  
  ins>>s;
  num=atoi(s.c_str());
  for(unsigned int i=0;i<num;i++) {
      ins>>s;
      x=atoi(s.c_str());
      ins>>s;
      y=atoi(s.c_str());
      ls.getLightsources()->push_back(new Lightsource(x,y));
  }
  
  
  return ins;
}

void Lightsim2D::readFromFile(string filename) {
  ifstream i(filename.c_str());
  string id;
  unsigned int x,y;
  while(i.good()) {
    i>>id;
    if(id.find("lsrc")!=string::npos) {
      //cout << "Found lsrc";
      i>>x>>y;
      lightsources->push_back(new Lightsource(x,y));
    }
    else if(id.find("opc")!=string::npos) {
      //cout << "Found opc";
      i>>x>>y;
      opaquecells->push_back(new Opaquecell(x,y));
    }
    else if(id.find("lsc")!=string::npos) {
      //cout << "Found LSC";
      i>>x>>y;
      LSCs->push_back(new LSC(x,y));
    }
    else if(id.find("done")==string::npos){
      cerr << "Error in datafile\n";
      exit(1);
    }
    if(id.find("done")==string::npos) {
      //      cout << " with "<<x<<","<<y<<"\n";
    }
    id="done";
  }

  i.close();
}

void Lightsim2D::print() {
  cout << "length av LSRC, OPC, LSC, LVec og Pruned er : " << lightsources->size() << "," <<opaquecells->size() << "," << LSCs->size() <<","<<lightvectors->size()<<","<<deletedLightvectors->size()<<"\n";
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
  double tmpLen=0;
  while(it!=lightvectors->end()){
    erased=false;
    //(*it)->getLSC()->printCell();
    for(unsigned int j=0;j<opaquecells->size();j++) {
      tmpLen=(*it)->getnVector()->orthogonalLength(opaquecells->at(j)->getX(),opaquecells->at(j)->getY());
      if(tmpLen>=0&&tmpLen<cellsize) {
	//cout << "erasing  because of OPC"<<endl;
	deletedLightvectors->push_back(*it);
	lightvectors->erase(it);
       	j = opaquecells->size();
	erased=true;
      }
    }
    if(!erased) {
      //cout <<"antall LSC: "<<LSCs->size()<<endl;
      for(unsigned int j=0;j<LSCs->size();j++) {
	//LSCs->at(j)->printCell();
	//cout <<LSCs->at(j)<<" og "<<(*it)->getLSC()<<endl;
	if(LSCs->at(j)!=(*it)->getLSC()) {
	  tmpLen=(*it)->getnVector()->orthogonalLength(LSCs->at(j)->getX(),LSCs->at(j)->getY());
	  if(tmpLen>=0&&tmpLen<cellsize) {
	    //cout << "erasing because of LSC"<<endl;
	    deletedLightvectors->push_back(*it);
	    lightvectors->erase(it);
	    j = LSCs->size();
	    erased=true;
	  }
	}
	//else { cout << "LSC kan ikke blokke seg selv!"<<endl; }
      }
    }
    if(!erased) {
      //cout <<"adding hit on lightsource: "<<(*it)->getLightsource()->getX()<<","<<(*it)->getLightsource()->getY()<<endl;
      (*it)->getLSC()->addHit(); 
      //(*it)->getLightsource()->addHit(); 
      (*it)->getLightsource()->addCell((*it)->getLSC());
      ++it; 
    }
  }
  //cout << "done!\n";
}
