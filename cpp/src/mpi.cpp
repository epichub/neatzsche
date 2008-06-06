#include "mpi.h"
void Build_gene_type(GeneSmall * gs,
		     MPI_DataType *mpi_t_ptr)
{
  int * fid = &(gs->fid);
  int * tid = &(gs->tid);
  int * marker = &(gs->marker);
  double * w = &(gs->w);
  bool enabled = &(gs->enabled);
  
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
  MPI_Address(enabled, &address);
  displacements[4] = address - start_address;
  MPI_Type_sctruct(5,block_lengths,displacements,typelist,mpi_t_ptr);
  MPI_Type_commit(mpi_t_ptr);
}
void Build_neuralnode_type(NeuralNodeSmall * ns,
		     MPI_DataType *mpi_t_ptr)
{
  int * id = &(ns->id);
  char * type = &(ns->type);
  int * depth = &(ns->depth);
  string * ftype = &(ns->ftype);
  int block_lengths[5];
  MPI_Aint displacements[5];
  MPI_Datatype typelist[5];
  MPI_Aint start_address;
  MPI_Aint address;
  
  typelist[0] = MPI_INT;
  typelist[1] = MPI_CHAR;
  typelist[2] = MPI_INT;
  typelist[3] = MPI_STRING;

  block_length[0] = block_length[1] = block_length[2] = 1;
  displacements[0] = 0;
  MPI_Address(id, &start_address);
  MPI_Address(type, &address);
  displacements[1] = address - start_address;
  MPI_Address(depth, &address);
  displacements[2] = address - start_address;
  MPI_Address(ftype, &address);
  displacements[3] = address - start_address;
  MPI_Type_sctruct(4,block_lengths,displacements,typelist,mpi_t_ptr);
  MPI_Type_commit(mpi_t_ptr);
}

void Build_genome_type(Genome * g,
		     MPI_DataType *mpi_t_ptr)
{
//   int * fid = &(g->getFrom()->getID());
//   int * fid = &(g->getTo()->getID());
//   int * marker = &(g->getTo()->getMarker());
//   double * w = &(g->getTo()->getWeight());
  int id = g->getID();
  nodeVector * nv = g->getNodes();
  Genes * genev = g->getGenes();
  int nodes = nv->size();//4 datatypes
  int genes = genev->size();
  int block_lengths[nodes+genes+1];
  MPI_Aint displacements[nodes+genes+1];
  MPI_Datatype typelist[nodes+genes+1];
  MPI_Aint start_address;
  MPI_Aint address;
  typelist[0] = MPI_INT;//id
  MPI_DataType dt;
  int i=0;
  for(i=1;i<nodes+1;i++){
    Build_neuralnode_type(nv->at(i-1),&dt);
    typelist[i] = dt;
  }
  for(;i<nodes+genes+1;i++){
    Build_gene_type(genev->at(i-(1+nodes)),&dt);
    typelist[i] = dt;
  }
  for(i=0;i<nodes+genes+1;i++)
    block_length[i] = 0;
  displacements[0] = 0;
  MPI_Address(id, &start_address);
  for(i=1;i<nodes+1;i++){
    MPI_Address(nv->at(i-1), &address);
    displacements[i] = address - start_address;
  }
  for(;i<genes+nodes+1;i++){
    MPI_Address(genev->at(i-(1+nodes)), &address);
    displacements[i] = address - start_address;
  }
  MPI_Type_sctruct(5,block_lengths,displacements,typelist,mpi_t_ptr);
  MPI_Type_commit(mpi_t_ptr);
}
