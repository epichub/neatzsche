#include "neatmpi.h"
MPI::Datatype Build_gene_type(GeneSmall * gs)
{
//   int * fid = &(gs->fid);
//   int * tid = &(gs->tid);
//   int * marker = &(gs->marker);
//   double * w = &(gs->w);
//   bool * enabled = &(gs->enabled);
  
  int block_lengths[6] = {1,1,1,1,1,1};
  MPI::Aint displacements[6];
  MPI::Datatype typelist[6] = {MPI::INT,MPI::INT,MPI::INT,MPI::DOUBLE,MPI::BOOL,MPI::UB};
//   MPI::Aint start_address;
//   MPI::Aint address;
  
//   typelist[0] = MPI::INT;
//   typelist[1] = MPI::INT;
//   typelist[2] = MPI::INT;
//   typelist[3] = MPI::DOUBLE;
//   typelist[4] = MPI::BOOL;

//   block_lengths[0] = block_lengths[1] = block_lengths[2] = 1;
//   displacements[0] = 0;
//   start_address =  MPI::Get_address(fid);
//   address = MPI::Get_address(tid);
//   displacements[1] = address - start_address;
//   address = MPI::Get_address(marker);
//   displacements[2] = address - start_address;
//   address = MPI::Get_address(w);
//   displacements[3] = address - start_address;
//   address = MPI::Get_address(enabled);
//   displacements[4] = address - start_address;

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
  //  MPI::Datatype::Commit(mpi_t_ptr);
  return mpi_t_ptr;
}
MPI::Datatype Build_neuralnode_type(NeuralNodeSmall * ns)//int* id, char* type, int* depth)
{
//   cout << "in build neuralnodetype" << endl;
//   int * id = &();
//   char * type = &(ns->type);
//   int * depth = &(ns->depth);
  //string * ftype = &(ns->ftype);
  int block_lengths[4] = {1,1,1,1};
  MPI::Aint displacements[4];
  MPI::Datatype typelist[4] = {MPI::INT,MPI::CHAR,MPI::INT,MPI::UB};
  MPI::Aint start_address;
  MPI::Aint address;
  
//   displacements[0] = 0;
//   start_address = MPI::Get_address(id);
// //   cout << "before getaddress type" << endl;
//   address = MPI::Get_address(type);

//   displacements[1] = address - start_address;
// //   cout << "before getaddress depth" << endl;
//   address = MPI::Get_address(depth);
//   displacements[2] = address - start_address;
// //   address = MPI::Get_address(ftype);
// //   displacements[3] = address - start_address;
  displacements[0] = MPI::Get_address(ns);
  displacements[1] = MPI::Get_address(&(ns->type));
  displacements[2] = MPI::Get_address(&(ns->depth));
  displacements[3] = MPI::Get_address(ns+1);
  int base = displacements[0];
  for(int i=0;i<4;i++) displacements[i] -= base;

  MPI::Datatype mpi_t_ptr =  MPI::Datatype::Create_struct(4,block_lengths,displacements,typelist);

//   cout << "before type commit" << endl;
  mpi_t_ptr.Commit();
//   cout << "before return" << endl;
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
