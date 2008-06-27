#include "neatmpi.h"
MPI::Datatype Build_gene_type(GeneSmall * gs)
{
  int block_lengths[6] = {1,1,1,1,1,1};
  MPI::Aint displacements[6];
  MPI::Datatype typelist[6] = {MPI::INT,MPI::INT,MPI::INT,MPI::DOUBLE,MPI::BOOL,MPI::UB};

  displacements[0] = MPI::Get_address(gs);
  displacements[1] = MPI::Get_address(&(gs->tid));
  displacements[2] = MPI::Get_address(&(gs->marker));
  displacements[3] = MPI::Get_address(&(gs->w));
  displacements[4] = MPI::Get_address(&(gs->enabled));
  displacements[5] = MPI::Get_address(gs+1);
  int base = displacements[0];
  for(int i=0;i<6;i++) displacements[i] -= base;

  MPI::Datatype mpi_t_ptr = MPI::Datatype::Create_struct(6,block_lengths,displacements,typelist);
  mpi_t_ptr.Commit();
  return mpi_t_ptr;
}
MPI::Datatype Build_neuralnode_type(NeuralNodeSmall * ns)//int* id, char* type, int* depth)
{
  int block_lengths[4] = {1,1,1,1};
  MPI::Aint displacements[4];
  MPI::Datatype typelist[4] = {MPI::INT,MPI::CHAR,MPI::INT,MPI::UB};
  MPI::Aint start_address;
  MPI::Aint address;
  
  displacements[0] = MPI::Get_address(ns);
  displacements[1] = MPI::Get_address(&(ns->type));
  displacements[2] = MPI::Get_address(&(ns->depth));
  displacements[3] = MPI::Get_address(ns+1);
  int base = displacements[0];
  for(int i=0;i<4;i++) displacements[i] -= base;

  MPI::Datatype mpi_t_ptr =  MPI::Datatype::Create_struct(4,block_lengths,displacements,typelist);
  mpi_t_ptr.Commit();
  return mpi_t_ptr;
}
