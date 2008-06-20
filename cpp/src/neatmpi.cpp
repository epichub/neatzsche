#include "neatmpi.h"
void Build_gene_type(GeneSmall * gs,
		     MPI::Datatype *mpi_t_ptr)
{
  int * fid = &(gs->fid);
  int * tid = &(gs->tid);
  int * marker = &(gs->marker);
  double * w = &(gs->w);
  bool * enabled = &(gs->enabled);
  
  int block_lengths[5];
  MPI::Aint displacements[5];
  MPI::Datatype typelist[5];
  MPI::Aint start_address;
  MPI::Aint address;
  
  typelist[0] = MPI::INT;
  typelist[1] = MPI::INT;
  typelist[2] = MPI::INT;
  typelist[3] = MPI::DOUBLE;
  typelist[4] = MPI::BOOL;

  block_lengths[0] = block_lengths[1] = block_lengths[2] = 1;
  displacements[0] = 0;
  start_address =  MPI::Get_address(fid);
  address = MPI::Get_address(tid);
  displacements[1] = address - start_address;
  address = MPI::Get_address(marker);
  displacements[2] = address - start_address;
  address = MPI::Get_address(w);
  displacements[3] = address - start_address;
  address = MPI::Get_address(enabled);
  displacements[4] = address - start_address;
  *mpi_t_ptr = MPI::Datatype::Create_struct(5,block_lengths,displacements,typelist);
  mpi_t_ptr->Commit();
  //  MPI::Datatype::Commit(mpi_t_ptr);
}
MPI::Datatype Build_neuralnode_type(int* id, char* type, int* depth)
{
//   int * id = &();
//   char * type = &(ns->type);
//   int * depth = &(ns->depth);
  //string * ftype = &(ns->ftype);
  int block_lengths[3];
  MPI::Aint displacements[3];
  MPI::Datatype typelist[3];
  MPI::Aint start_address;
  MPI::Aint address;
  
  typelist[0] = MPI::INT;
  typelist[1] = MPI::CHAR;
  typelist[2] = MPI::INT;
  //  typelist[3] = MPI::STRING;

  block_lengths[0] = block_lengths[1] = block_lengths[2] = 1;
  displacements[0] = 0;
  start_address = MPI::Get_address(id);
  address = MPI::Get_address(type);
  displacements[1] = address - start_address;
  address = MPI::Get_address(depth);
  displacements[2] = address - start_address;
//   address = MPI::Get_address(ftype);
//   displacements[3] = address - start_address;
  MPI::Datatype mpi_t_ptr =  MPI::Datatype::Create_struct(3,block_lengths,displacements,typelist);
  mpi_t_ptr.Commit();
  return mpi_t_ptr;
}

// void Build_genome_type(Genome * g,
// 		     MPI::Datatype *mpi_t_ptr)
// {
// //   int * fid = &(g->getFrom()->getID());
// //   int * fid = &(g->getTo()->getID());
// //   int * marker = &(g->getTo()->getMarker());
// //   double * w = &(g->getTo()->getWeight());
//   int id = g->getID();
//   nodeVector * nv = g->getNodes();
//   Genes * genev = g->getGenes();
//   int nodes = nv->size();//4 datatypes
//   int genes = genev->size();
//   int block_lengths[nodes+genes+1];
//   MPI::Aint displacements[nodes+genes+1];
//   MPI::Datatype typelist[nodes+genes+1];
//   MPI::Aint start_address;
//   MPI::Aint address;
//   typelist[0] = MPI::INT;//id
//   MPI::Datatype dt;
//   int i=0;
//   for(i=1;i<nodes+1;i++){
//     Build_neuralnode_type(nv->at(i-1),&dt);
//     typelist[i] = dt;
//   }
//   for(;i<nodes+genes+1;i++){
//     Build_gene_type(genev->at(i-(1+nodes)),&dt);
//     typelist[i] = dt;
//   }
//   for(i=0;i<nodes+genes+1;i++)
//     block_length[i] = 0;
//   displacements[0] = 0;
//   MPI::Get_address(id, &start_address);
//   for(i=1;i<nodes+1;i++){
//     MPI::Get_address(nv->at(i-1), &address);
//     displacements[i] = address - start_address;
//   }
//   for(;i<genes+nodes+1;i++){
//     MPI::Get_address(genev->at(i-(1+nodes)), &address);
//     displacements[i] = address - start_address;
//   }
//   MPI::Type_sctruct(5,block_lengths,displacements,typelist,mpi_t_ptr);
//   MPI::Type_commit(mpi_t_ptr);
// }
