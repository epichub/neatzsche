#ifndef BOYE_H_
#define BOYE_H_
#include "evolution.h"
#include "coevolution.h"

class Neatzsche_Comm {
public:
  Neatzsche_Comm(){};
  virtual ~Neatzsche_Comm(){};
  virtual void outputPopulation(Population * p, unsigned int nodes,  Coevolution * c, 
                                unsigned int i, bool stop) {};
  virtual bool readPopulation(Phenotypes * p, Coevolution * c, TransferFunctions * tfs, int & gencount){return true;};
  virtual void outputFitness(Phenotypes * p){};
  virtual void readFitness(Population * p, unsigned int i){};
};
class Neatzsche_Boye : public Neatzsche_Comm {
public:
  Neatzsche_Boye(){};
  virtual ~Neatzsche_Boye(){};
  virtual void outputPopulation(Population * p, int nodes,  Coevolution * c, 
				unsigned int i, bool pipeio, bool stop)
  {
    unsigned int s = p->getMembers()->size();
    unsigned int n = (s-i)/nodes;
    bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);
    if(pipeio)
      cout << "POPULATION\n";

    while(i < s) {
      cout << "NODES" << endl;
      if(stop)
	cout << "STOP" << endl;
      else
	cout << "CONTINUE" << endl;

      cout << c;
      if(uneven && (s-i)<(2*n)){
	n = (s-i);
      }
      for(size_t i2 = 0; i2 < n && i < s; i2++, i++) {
	//the endline at the end here is to make the >> operator of
	//genome stop for each genome, the genome tag is for the nodes
	//parsing..
	cout << "genome" << endl << p->getMembers()->at(i)->getGenome() << endl;
      }
      cout << "NODES" << endl;
    }

    if(pipeio)
      cout << "POPULATION\n" ;
  }
  virtual bool readPopulation(Phenotypes * p, Coevolution * c, TransferFunctions * tfs)
  {
    string s;
    cin >> s;
    stringstream tmpbuf;
    cin >> s;

    if(s.find("STOP") != string::npos)
      return false;
    //  cerr << "s: " << s << endl;
    //   cin >> s;
    //   cerr << "s: " << s << endl;
    Genome * g = NULL;

    cin >> c; // read in the coevo stuff..

    cin >> s;

    int c2 = 0;
    while(s.find("NODESTOP")==string::npos&&s.find("genome")!=string::npos){
      g = new Genome(tfs);
      cin >> g;
      c2++;
      p->push_back(new Phenotype(g));
      cin >> s;
    }
    //   cerr << "done reading genomes..: psize" << p->size()<< endl;
    return true;
  }
  virtual void outputFitness(Phenotypes * p)
  {
    for(unsigned int i=0;i<p->size();i++){
      cout << p->at(i)->getID() << "\t" << p->at(i)->getFitness() << "\t";
    }
    cout << endl << flush;
  }
  virtual void readFitness(Population * p, unsigned int i)
  {
    for(;i<p->getMembers()->size();i++){
      int nID;
      float fFitn;
      cin >> nID >> fFitn;
      Phenotype * ph = p->getByID(nID);
      if(fFitn>0.5){
      }
      ph->setFitness(fFitn);
      ph->transferFitness();

    }
    string s;
    getline(cin, s); // chomp off final newline
    int a = -1;
    if (++a)
      {
	if (cin.eof())
	  cerr << "eof";
	else
	  cerr << "noeo";
	char c;
	cin.read(&c, 1);
      }
  }
};
#endif
