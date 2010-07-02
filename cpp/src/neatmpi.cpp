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
  
  displacements[0] = MPI::Get_address(ns);
  displacements[1] = MPI::Get_address(&(ns->type));
  displacements[2] = MPI::Get_address(&(ns->depth));
  displacements[3] = MPI::Get_address(ns+1);
  long base = displacements[0];
  for(int i=0;i<4;i++) displacements[i] -= base;

  MPI::Datatype mpi_t_ptr =  MPI::Datatype::Create_struct(4,block_lengths,displacements,typelist);
  mpi_t_ptr.Commit();
  return mpi_t_ptr;
}
bool Neatzsche_MPI::readPopulation(Phenotypes * p, Coevolution * c, TransferFunctions * tfs)
{
  MPI::Status status;
  MPI::Datatype ndt,gdt;
  int genomes,genes,nodes,id;
  MPI::COMM_WORLD.Recv(&genomes,1,MPI::INT,0,0);//Receive the number of genome
  NeuralNodeSmall * nns;
  GeneSmall * gs;
  Genome * genome = NULL;
  int stringc=0; 
  char *strbuf;
  vector<string> * ftypes = NULL;
  for(int i=0;i<genomes;i++){
    ftypes = new vector<string>();
    MPI::COMM_WORLD.Recv(&id,1,MPI_INT,0,0);
    MPI::COMM_WORLD.Recv(&nodes,1,MPI_INT,0,0);
    MPI::COMM_WORLD.Recv(&genes,1,MPI_INT,0,0);
//     nns = (NeuralNodeSmall*)malloc(sizeof(NeuralNodeSmall)*nodes);
//     gs = (GeneSmall*)malloc(sizeof(GeneSmall)*genes);
    nns = new NeuralNodeSmall [nodes];
    gs = new GeneSmall[genes];

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
    delete ftypes;
    p->push_back(new Phenotype(genome));
    if(nodes>0)
      delete[] nns; 
    if(genes>0)
      delete[] gs;
  }
  unsigned int cont;
  MPI::COMM_WORLD.Recv(&cont,1,MPI::INT,0,0);//continue or stop?
  return cont == MPI_Cont;

}
void Neatzsche_MPI::outputPopulation(Population * pop, unsigned int nodes,  Coevolution * c, 
					     unsigned int i, bool lastgen)
{
  unsigned int s = pop->getMembers()->size();
  unsigned int n = (s-i)/nodes;
  bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);

  GeneSmall * gsv = NULL;
  NeuralNodeSmall * nsv = NULL;
  Genome * genome = NULL; int genes, nnodes;
  int sendtag = Neatzsche_MPI::MPI_Cont;
  string sftype;
  int sc=0;
  if(lastgen)
    sendtag = MPI_Stop;
  else
    sendtag = MPI_Cont;
  while(i < s) {
    if(uneven && (s-i)<(2*n)){
      n = (s-i);
    }
      
    sc = (sc % (size-1))+1;

    MPI::COMM_WORLD.Send(&n,1,MPI_INT,sc,0);//send number of genomes incoming
    for(size_t i2 = 0; i2 < n && i < s; i2++, i++) {

      genome = pop->getMembers()->at(i)->getGenome();
      genome->toSmall(nsv,gsv,&nnodes,&genes);
	
      MPI::COMM_WORLD.Send(&i,1,MPI_INT,sc,0);//send genome id..
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
      if(nnodes>0)
	delete[] nsv; 
      if(genes>0)
	delete[] gsv;
    }
    MPI::COMM_WORLD.Send(&sendtag,1,MPI::INT,sc,0);//send stop or not
  }

}
