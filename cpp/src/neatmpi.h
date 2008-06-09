#ifndef _MPI_H_
#define _MPI_H_
#include "evaluator.h"
// extern "C" {

#include <mpi.h>
//}

void Build_gene_type(GeneSmall * gs,
			MPI::Datatype *mpi_p_ptr);
void Build_neuralnode_type(NeuralNodeSmall * nns,
		     MPI::Datatype *mpi_t_ptr);
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
    Build_neuralnode_type(&ns,&nodetype);
    Build_gene_type(&gs,&genetype);
  }
  ~Neatzsche_MPI(){}
  int getRank(){return rank;}
  int getSize(){return size;}
  static const unsigned int MPI_Cont = 0;
  static const unsigned int MPI_Stop = 1;
  Phenotypes * receive(Phenotypes * p, TransferFunctions * tfs)
  {
    // int MPI::Recv( void *buf, int count, MPI::Datatype datatype, int source, 
    //               int tag, MPI::Comm comm, MPI::Status *status )
    Genome * g = new Genome(tfs);
//     MPI::Datatype * dt;
//     Build_node_type(g,&dt);
//     MPI::Recv ( , message_size, MPI::CHAR, neighbor, 0, MPI::COMM_WORLD, &status );
    MPI::Status status;
    MPI::Datatype ndt,gdt;
    int genomes,genes,nodes;
    MPI::COMM_WORLD.Recv(&genomes,1,MPI::INT,0,0);//Receive the number of genome
    NeuralNodeSmall * nns;
    GeneSmall * gs; 
    nodeVector * nv = NULL; Genes * genev = NULL; vector<Genome *> * v = new vector<Genome *>();
    Genome * genome = NULL;

    for(unsigned int i=0;i<genomes;i++){

      MPI::COMM_WORLD.Recv(&nodes,1,MPI_INT,0,0);
      MPI::COMM_WORLD.Recv(&genes,1,MPI_INT,0,0);

//       for(unsigned int i2=0;i2<nodes;i2++){
      nns = (NeuralNodeSmall*)malloc(sizeof(NeuralNodeSmall)*nodes);
      gs = (GeneSmall*)malloc(sizeof(GeneSmall)*nodes);


      MPI::COMM_WORLD.Recv(nns,nodes,nodetype,0,0);
      //       }
//       for(unsigned int i2=0;i2<genes;i2++){

      MPI::COMM_WORLD.Recv(gs,genes,genetype,0,0);
//       }
      genome = new Genome(tfs);
      genome->fromSmall(nodes,nns,genes,gs);
      p->push_back(new Phenotype(genome));
    }
    //     MPI::COMM_WORLD.Recvv ( , message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD, &status );
  }
  void send(Population * pop, unsigned int nodes, unsigned int i)
  {
    unsigned int s = pop->getMembers()->size();
    unsigned int n = (s-i)/nodes;
    bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);

    MPI_Datatype * stt;


    GeneSmall * gsv = NULL;
    NeuralNodeSmall * nsv = NULL;
    Genome * genome = NULL; int genes = 0; int nnodes = 0;
    //Build_genome_type(phenotypes->getMembers()->at(i),&stt);	
    int sendtag = Neatzsche_MPI::MPI_Cont;
    int sc=0;
    while(i < s) {
      if(uneven && (s-i)<(2*n)){
	n = (s-i);
      }
      // 	Phenotypes*[] = new Phenotypes * [];
      
      sc++;
      MPI::COMM_WORLD.Send(&n,1,MPI_INT,sc,sendtag);//send number of genomes incoming
      for(size_t i2 = 0; i2 < n && i < s; i2++, i++) {
	//	Genome ** g = new Genome * [];
	genome = pop->getMembers()->at(i)->getGenome();
	genome->toSmall(nsv,gsv,&nnodes,&genes);
// 	for(unsigned int i=0;i<genome->size()
// 	Build_genome_type(phenotypes->getMembers()->at(i),&dt);	
	if(i2<(n-1))
	  sendtag = MPI_Cont;
	else
	  sendtag = MPI_Stop;
// 	nnodes = genome->getNodes()->size();
// 	genes = genome->geGenes()->size();
	MPI::COMM_WORLD.Send(&nnodes,1,MPI_INT,sc,sendtag);//send number of nodes
	MPI::COMM_WORLD.Send(&genes,1,MPI_INT,sc,sendtag);//send number of genes

	MPI::COMM_WORLD.Send(nsv,nnodes,nodetype,sc,sendtag);//send node vector
	MPI::COMM_WORLD.Send(gsv,genes,genetype,sc,sendtag);//send gene vector

      }
//       MPI_Send(pop->getMembers()->at(0),1,stt,sc,MPI_Stop,MPI_COMM_WORLD);
    }

  }
};
#endif
