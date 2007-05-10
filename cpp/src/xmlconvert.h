#include "genome.h"
#include "evolution.h"
#include <sstream>
#include <iostream>
#include "tinyxml.h"
#include <fstream>
static inline string makeNodeID(NeuralNode * n){
  stringstream ss;
  ss << n->getID() << ":" << n->getFType();
  return ss.str();
}
static void writenetwork(Phenotype * pheno, string file)  
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

// 	Phenotype * pheno = new Phenotype(g);
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
	  neuron->SetAttribute("weight", genes->at(i)->getWeight());
	  neuron->SetAttribute("recurrent", rec ? "true" : "false");
	}

	
	//dump_to_stdout( &doc );
	doc.SaveFile( file.c_str() );  

}
