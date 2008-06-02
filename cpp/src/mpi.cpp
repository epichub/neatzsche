#include "mpi.h"
void Build_gene_type(Gene * g,
		     MPI_DataType *mpi_t_ptr)
{
  int * fid = &(g->getFrom()->getID());
  int * fid = &(g->getTo()->getID());
  int * marker = &(g->getTo()->getMarker());
  double * w = &(g->getTo()->getWeight());
  int block_lengths[5];
  MPI_Aint displacements[5];
  MPI_Datatype typelist[5];
  MPI_Aint start_address;
  MPI_Aint address;
  
  typelist[0] = MPI_INT;
  typelist[1] = MPI_INT;
  typelist[2] = MPI_INT;
  typelist[3] = MPI_DOUBLE;
  typelist[4] = MPI_BOOL;

  block_length[0] = block_length[1] = block_length[2] = 1;

  displacements[0] = 0;

  MPI_Address(fid, &start_address);

  MPI_Address(tid, &address);
  displacements[1] = address - start_address;

  MPI_Address(marker, &address);
  displacements[2] = address - start_address;

  MPI_Address(w, &address);
  displacements[3] = address - start_address;

  MPI_Address(enbld, &address);
  displacements[4] = address - start_address;
  MPI_Type_sctruct(5,block_lengths,displacements,typelist,mpi_t_ptr);

  MPI_Type_commit(mpi_t_ptr);
}
