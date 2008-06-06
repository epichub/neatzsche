#include "evaluator.h"
#include <mpi.h>

using namespace std;
void Build_gene_type(GeneSmall * gs,
			MPI_DataType *mpi_p_ptr);
void Build_neuralnode_type(NeuralNodeSmall * nns,
		     MPI_DataType *mpi_t_ptr);
void Build_genome_type(Genome * g,
		     MPI_DataType *mpi_t_ptr);
class Neatzsche_MPI {
protected:
  int rank;
  int size;
public:
  Neatzsche_MPI(int argc, char * args[])
  {
    MPI_Init ( &argc, &argv );
    MPI_Comm_rank ( MPI_COMM_WORLD, &rank );
    MPI_Comm_size ( MPI_COMM_WORLD, &size );
  }
  ~Neatzsche_MPI(){}
  static unsigned int MPI_Cont = 0;
  static unsigned int MPI_Stop = 0;
  Phenoetypes * receive(Phenoetypes * p, TransferFunctions * tfs)
  {
    // int MPI_Recv( void *buf, int count, MPI_Datatype datatype, int source, 
    //               int tag, MPI_Comm comm, MPI_Status *status )
    Genome * g = new Genome(tfs);
//     MPI_DataType * dt;
//     Build_node_type(g,&dt);
//     MPI_Recv ( , message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD, &status );
    MPI_Status status;
    MPI_DataType dt;
    int genomes,genes,nodes;
    MPI_Rec(&genomes,1,MPI_INT,0,0,MPI_COMM_WORLD);//Receive the number of genome
    NeuralNodeSmall * nns;
    GeneSmall * gs; 
    nodeVector * nv = NULL; Genes * genev = NULL; vector<Genome *> v = new vector<Genome *>();
    Genome * genome = NULL;
    for(unsigned int i=0;i<genomes;i++){

      MPI_Rec(&nodes,1,MPI_INT,0,0,MPI_COMM_WORLD);
      MPI_Rec(&genes,1,MPI_INT,0,0,MPI_COMM_WORLD);

//       for(unsigned int i2=0;i2<nodes;i2++){
      nns = malloc(sizeof(NeuralNodeSmall)*nodes);
      gs = malloc(sizeof(NeuralNodeSmall)*nodes);

      Build_node_type(&nns,&dt);
      MPI_Rec(nns,nodes,dt,0,0,MPI_COMM_WORLD);
      //       }
//       for(unsigned int i2=0;i2<genes;i2++){
      Build_gene_type(&gs,&dt);
      MPI_Rec(gs,genes,dt,0,0,MPI_COMM_WORLD);
//       }
      genome = new Genome(tfs);
      genome->fromSmall(nodes,nns,genes,gs);
    }
    //     MPI_Recv ( , message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD, &status );
  }
  void send(Population * p, unsigned int nodes unsigned int i)
  {
    unsigned int s = p->getMembers()->size();
    unsigned int n = (s-i)/nodes;
    bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);
    MPI_DataType * genetype;
    MPI_DataType * nodetype;
    MPI_DataType * stt;
    GeneSmall gs;
    GeneSmall ns;
    Build_node_type(&ns,nodetype);
    Build_node_type(&gs,genetype);

    //Build_genome_type(phenotypes->getMembers()->at(i),&stt);	
    int sc=0;
    while(i < s) {
      if(uneven && (s-i)<(2*n)){
	n = (s-i);
      }
      // 	Phenotypes*[] = new Phenotypes * [];
      
      sc++;
      for(size_t i2 = 0; i2 < n && i < s; i2++, i++) {
	//	Genome ** g = new Genome * [];
	Build_genome_type(phenotypes->getMembers()->at(i),&dt);	
	MPI_Send(phenotypes->getMembers()->at(i)->getSmall(),1,dt,sc,MPI_Cont,MPI_COMM_WORLD);
//       MPI_Send ( dummy, message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD );
//       MPI_Recv ( dummy, message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD, &status );
      }
      MPI_Send(phenotypes->getMembers()->at(0),1,stt,sc,MPI_Stop,MPI_COMM_WORLD);
    }
}
