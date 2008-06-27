#ifndef _MPI_H_
#define _MPI_H_
#include "evaluator.h"
// extern "C" {

#include <mpi.h>
//}

MPI::Datatype Build_gene_type(GeneSmall * gs);
//MPI::Datatype Build_neuralnode_type(int* id, char* type, int* depth);
MPI::Datatype Build_neuralnode_type(NeuralNodeSmall * nns);
// void Build_neuralnode_type(NeuralNodeSmall * nns,
// 		     MPI::Datatype *mpi_t_ptr);
void Build_genome_type(Genome * g,
		     MPI::Datatype *mpi_t_ptr);
using namespace std;
class Neatzsche_MPI {
protected:
  int rank;
  int size;
  MPI::Datatype genetype;
  MPI::Datatype nodetype;
public:
  Neatzsche_MPI(int argc, char ** args)
  {
    MPI::Init ( argc, args );
    rank = MPI::COMM_WORLD.Get_rank();
    size = MPI::COMM_WORLD.Get_size();
    NeuralNodeSmall ns;
    GeneSmall gs;
//     nodetype = Build_neuralnode_type(&ns);
//     Build_gene_type(&gs,&genetype);
  }
  ~Neatzsche_MPI(){}
  int getRank(){return rank;}
  int getSize(){return size;}
  static const unsigned int MPI_Cont = 0;
  static const unsigned int MPI_Stop = 1;
  bool receive(Phenotypes * p, TransferFunctions * tfs)
  {
    Genome * g = new Genome(tfs);
    MPI::Status status;
    MPI::Datatype ndt,gdt;
    int genomes,genes,nodes,id;
    MPI::COMM_WORLD.Recv(&genomes,1,MPI::INT,0,0);//Receive the number of genome
    NeuralNodeSmall * nns;
    GeneSmall * gs; 
    nodeVector * nv = NULL; Genes * genev = NULL; vector<Genome *> * v = new vector<Genome *>();
    Genome * genome = NULL;
    int stringc=0; char *strbuf;vector<string> * ftypes = NULL;
    for(unsigned int i=0;i<genomes;i++){
      ftypes = new vector<string>();
      cout << "before " << endl;
      MPI::COMM_WORLD.Recv(&id,1,MPI_INT,0,0);
      MPI::COMM_WORLD.Recv(&nodes,1,MPI_INT,0,0);
      MPI::COMM_WORLD.Recv(&genes,1,MPI_INT,0,0);
      nns = (NeuralNodeSmall*)malloc(sizeof(NeuralNodeSmall)*nodes);
      gs = (GeneSmall*)malloc(sizeof(GeneSmall)*genes);

      nodetype = Build_neuralnode_type(&nns[0]);
      MPI::COMM_WORLD.Recv(nns,nodes,nodetype,0,0);
      for(int i=0;i<nodes;i++){//blargh, 1 int would be more usefull in this case:P
	MPI::COMM_WORLD.Probe(0, MPI_Cont, status);
	stringc = status.Get_count(MPI_CHAR);
	strbuf = (char*) malloc(sizeof(char)*stringc);
	MPI::COMM_WORLD.Recv(strbuf,stringc,MPI::CHAR,0,0);//receive the ftype of the node
	ftypes->push_back(string(strbuf).substr(0,stringc));
	free(strbuf);
      }
      genetype = Build_gene_type(&gs[0]);
      MPI::COMM_WORLD.Recv(gs,genes,genetype,0,0);

      genome = new Genome(tfs);

      genome->fromSmall(id,nodes,nns,genes,gs,ftypes);

      cout << "i: "<<i<<" printing my received genome:" << endl;
      cout << genome << endl;
      delete ftypes;
      p->push_back(new Phenotype(genome));
      delete nns; delete gs;
    }
    unsigned int cont;
    MPI::COMM_WORLD.Recv(&cont,1,MPI::INT,0,0);//continue or stop?
    return cont == MPI_Cont;
  }
  void send(Population * pop, unsigned int nodes, unsigned int i, bool lastgen)
  {
    unsigned int s = pop->getMembers()->size();
    unsigned int n = (s-i)/nodes;
    bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);

    MPI_Datatype * stt;


    GeneSmall * gsv = NULL;
    NeuralNodeSmall * nsv = NULL;
    Genome * genome = NULL; int genes, nnodes, id;
    int sendtag = Neatzsche_MPI::MPI_Cont;
    string sftype;
    int sc=0;
    while(i < s) {
      if(uneven && (s-i)<(2*n)){
	n = (s-i);
      }
      
      sc = ((sc+1) % (size-1))+1;
      cout << "sending to sc: "<<sc<<" : " << n << " genomes " << endl;
      MPI::COMM_WORLD.Send(&n,1,MPI_INT,sc,0);//send number of genomes incoming
      for(size_t i2 = 0; i2 < n && i < s; i2++, i++) {

	genome = pop->getMembers()->at(i)->getGenome();
	cout << "sending genome " << genome->getID() 
	     << " nodes: " << genome->getNodes()->size()
	     << " genes: " << genome->getGenes()->size() << endl;
	genome->toSmall(nsv,gsv,&nnodes,&genes);
	id = genome->getID();



	
	MPI::COMM_WORLD.Send(&id,1,MPI_INT,sc,0);//send genome id..
	MPI::COMM_WORLD.Send(&nnodes,1,MPI_INT,sc,0);//send number of nodes
	MPI::COMM_WORLD.Send(&genes,1,MPI_INT,sc,0);//send number of genes

	nodetype = Build_neuralnode_type(&nsv[0]);

	MPI::COMM_WORLD.Send(nsv,nnodes,nodetype,sc,0);//send node vector
	for(int i=0;i<nnodes;i++){
	  sftype = "";
	  sftype = genome->getNodes()->at(i)->getTFunc()->ftype;
	  MPI::COMM_WORLD.Send(sftype.c_str(),sftype.length(),MPI::CHAR,sc,0);//send gene vector
	}
	genetype = Build_gene_type(&gsv[0]);
	MPI::COMM_WORLD.Send(gsv,genes,genetype,sc,0);//send gene vector

	delete nsv; delete gsv;
      }
      if(lastgen)
	sendtag = MPI_Stop;
      else
	sendtag = MPI_Cont;
      MPI::COMM_WORLD.Send(&sendtag,1,MPI::INT,sc,0);//send genome id..
    }

  }
};
#endif
