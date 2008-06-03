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
  Phenoetypes * receive(Phenoetypes * p)
  {
    // int MPI_Recv( void *buf, int count, MPI_Datatype datatype, int source, 
    //               int tag, MPI_Comm comm, MPI_Status *status )

    //     MPI_Recv ( , message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD, &status );
  }
  void send(Population * p, unsigned int nodes unsigned int i)
  {
    unsigned int s = p->getMembers()->size();
    unsigned int n = (s-i)/nodes;
    bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);
    MPI_DataType * dt;
    MPI_DataType * stt;
    Build_genome_type(phenotypes->getMembers()->at(i),&stt);	
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
	MPI_Send(phenotypes->getMembers()->at(i),1,dt,sc,MPI_Cont,MPI_COMM_WORLD);
//       MPI_Send ( dummy, message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD );
//       MPI_Recv ( dummy, message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD, &status );
      }
      MPI_Send(phenotypes->getMembers()->at(0),1,stt,sc,MPI_Stop,MPI_COMM_WORLD);
    }
}
