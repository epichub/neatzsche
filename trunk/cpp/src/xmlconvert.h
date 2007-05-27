#include "genome.h"
#include "evolution.h"
#include <sstream>
#include <iostream>
#include "tinyxml.h"
#include <fstream>
static inline string makeNodeID(NeuralNode * n){
  stringstream ss;
  ss << n->getID() << ":" << n->getTFunc()->ftype;
  return ss.str();
}
static inline void writenetwork(Phenotype * pheno, string file)  
{  
  TiXmlDocument doc;  
  TiXmlElement* title;
  TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
  doc.LinkEndChild( decl );  
 
  TiXmlElement * root = new TiXmlElement( "network" );  
  doc.LinkEndChild( root ); 

  title = new TiXmlElement( "title" );
  stringstream ss; ss << pheno->getID();
  title->LinkEndChild( new TiXmlText( ss.str().c_str() ));  
  root->LinkEndChild( title ); 

  vector< nodeVector * > *net = pheno->getNet()->getNet();
  for(unsigned int i2=0;i2<net->size();i2++){
    for(unsigned int i=0;i<net->at(i2)->size();i++){
      TiXmlElement * neuron;
      neuron = new TiXmlElement( "neuron" );  
      root->LinkEndChild( neuron );  
      neuron->SetAttribute("id", makeNodeID(net->at(i2)->at(i)).c_str());
      string sType;
      if(net->at(i2)->at(i)->getType()==NeuralNode::INPUT)
	sType = "input";
      else if(net->at(i2)->at(i)->getType()==NeuralNode::HIDDEN)
	sType = "hidden";
      else if(net->at(i2)->at(i)->getType()==NeuralNode::OUTPUT)
	sType = "output";
      else
	sType = "bias";
      //	  cout << "net->at(i2)->at(i)->getType(): " << net->at(i2)->at(i)->getType()
      neuron->SetAttribute("type", sType.c_str());
      neuron->SetAttribute("hint-layer", (i2+1));
      neuron->SetAttribute("hint-position", (i+1));//TODO: HUH?
      neuron->SetAttribute("value", 0);
      neuron->SetAttribute("step-pending", "false");
      neuron->SetAttribute("activation", "sigmoid");
    }
  }
  Genes * genes = pheno->getGenome()->getGenes();

  for(unsigned int i=0;i<genes->size();i++){
    TiXmlElement * neuron;
    neuron = new TiXmlElement( "connection" );  
    root->LinkEndChild( neuron );  
    neuron->SetAttribute("src-id", makeNodeID(genes->at(i)->getFrom()).c_str());
    neuron->SetAttribute("tgt-id", makeNodeID(genes->at(i)->getTo()).c_str());
    bool rec = (genes->at(i)->getTo()->getDepth()<=genes->at(i)->getFrom()->getDepth()) ? true : true;
    neuron->SetAttribute("weight", (int)genes->at(i)->getWeight());
    neuron->SetAttribute("recurrent", rec ? "true" : "false");
  }

	
  //dump_to_stdout( &doc );
  doc.SaveFile( file.c_str() );  

}
class SpecGraph {
private:
  TiXmlDocument doc;
  int gc;
  string file;
  TiXmlElement * run;
public:
  SpecGraph(int pops, int gens, string ifile){
    file = ifile;
    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
    doc.LinkEndChild( decl );  

    run = new TiXmlElement( "run" );  
    doc.LinkEndChild( run ); 
 
    TiXmlElement * sp = new TiXmlElement( "search-parameters" );  
    run->LinkEndChild( sp ); 

    TiXmlElement* tmp;

    tmp = new TiXmlElement( "population-size" );
    stringstream ssPops; ssPops << pops;
    tmp->LinkEndChild( new TiXmlText( ssPops.str().c_str() ));  
    sp->LinkEndChild( tmp ); 

    tmp = new TiXmlElement( "generations" );
    stringstream ssGens; ssGens << gens;
    tmp->LinkEndChild( new TiXmlText( ssGens.str().c_str() ));  
    sp->LinkEndChild( tmp ); 
    gc = 0;
  }
  inline void update(Population * p)
  {
    double max = p->getMembers()->at(0)->getOrigFitness();
    double avg = p->calcAvgFitness();
    double min = p->getMembers()->at(p->getMembers()->size()-1)->getOrigFitness();
    double cchamp = p->getMembers()->at(0)->getGenome()->getGenes()->size();
    double cmax = p->maxComplexity();
    double cmin = p->minComplexity();
    double cavg = p->calcAvgComplexity();
    speciesVector * v  = new speciesVector();
    speciesVector * orig = p->getSpecies();
    v->insert(v->end(),p->begin(),p->end());
    sort(v->begin(),v->end(),speciesidcomp);
    addgeneration(p->getSpecies(),max,avg,min,cmax,cavg,cmin,cchamp);
  }
  inline void addgeneration(speciesVector * v, double max, double avg, double min,
			    double cmax, double cavg, double cmin, double cchamp)  
  {  

    TiXmlElement * groot = new TiXmlElement( "generation" );  
    groot->SetAttribute("id",gc++);
    run->LinkEndChild( groot ); 

    TiXmlElement* tmp;
    TiXmlElement* tmp2;

    tmp = new TiXmlElement( "fitness" );
    stringstream ssMaxf; ssMaxf << max * 100;
    tmp2 = new TiXmlElement( "max" );    
    tmp2->LinkEndChild( new TiXmlText( ssMaxf.str().c_str() ));  
    tmp->LinkEndChild(tmp2);  
    stringstream ssMinf; ssMinf << min * 100;
    tmp2 = new TiXmlElement( "min" );    
    tmp2->LinkEndChild( new TiXmlText( ssMinf.str().c_str() ));  
    tmp->LinkEndChild(tmp2);
    stringstream ssAvgf; ssAvgf << avg * 100;
    tmp2 = new TiXmlElement( "avg" );    
    tmp2->LinkEndChild( new TiXmlText( ssAvgf.str().c_str() ));  
    tmp->LinkEndChild(tmp2);
    groot->LinkEndChild( tmp ); 

    tmp = new TiXmlElement( "complexity" );
    stringstream ssMaxc; ssMaxc << cmax;
    tmp2 = new TiXmlElement( "max" );    
    tmp2->LinkEndChild( new TiXmlText( ssMaxc.str().c_str() ));  
    tmp->LinkEndChild(tmp2);  
    stringstream ssMinc; ssMinc << cmin;
    tmp2 = new TiXmlElement( "min" );    
    tmp2->LinkEndChild( new TiXmlText( ssMinc.str().c_str() ));  
    tmp->LinkEndChild(tmp2);
    stringstream ssAvgc; ssAvgc << cmin;
    tmp2 = new TiXmlElement( "avg" );    
    tmp2->LinkEndChild( new TiXmlText( ssAvgc.str().c_str() ));  
    tmp->LinkEndChild(tmp2);
    groot->LinkEndChild( tmp ); 

    for(unsigned int i2=0;i2<v->size();i2++){
      tmp = new TiXmlElement( "specie" );
      tmp->SetAttribute("id",v->at(i2)->getID());
      tmp->SetAttribute("count",(int)v->at(i2)->getMembers()->size());
      for(unsigned int i=0;i<v->at(i2)->getMembers()->size();i++){
	TiXmlElement * chromosome;
	chromosome = new TiXmlElement( "chromosome" );  
	chromosome->SetAttribute("id", v->at(i2)->getMembers()->at(i)->getID());
	chromosome->SetAttribute("fitness", (int)(v->at(i2)->getMembers()->at(i)->getOrigFitness()*100));
	tmp->LinkEndChild( chromosome ); 	
      }
      groot->LinkEndChild( tmp ); 
    }
  }
  void writetofile(){
    cerr << "writing specgraph to: " << file << endl;
    doc.SaveFile( file.c_str() );  
  }
};

