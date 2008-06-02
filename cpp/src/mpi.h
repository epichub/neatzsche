#include "evaluator.h"
#include <mpi.h>

using namespace std;
void Build_dervied_type(int *fid, int *tid, double *w, int *marker, bool *enbld
			MPI_DataType *mpi_p_ptr);

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
  Phenoetypes * receive(Phenoetypes * p){

  }
  void send(Population * p){
      unsigned int s = p->getMembers()->size();
      unsigned int n = (s-i)/nodes;
      bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);

      while(i < s) {
	if(uneven && (s-i)<(2*n)){
	  n = (s-i);
	}
	Phenotypes*[] = new Phenotypes * [];
	for(size_t i2 = 0; i2 < n && i < s; i2++, i++) {

	  //the endline at the end here is to make the >> operator of
	  //genome stop for each genome, the genome tag is for the nodes
	  //parsing..
	  cout << "genome" << endl << p->getMembers()->at(i)->getGenome() << endl;
	}
	
      }
}
