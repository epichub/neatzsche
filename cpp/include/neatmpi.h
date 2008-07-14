#ifndef _MPI_H_
#define _MPI_H_
#include "evaluator.h"
#include "coevolution.h"
// extern "C" {

#include <mpi.h>
#include "boye.h"

//}

MPI::Datatype Build_gene_type(GeneSmall * gs);
//MPI::Datatype Build_neuralnode_type(int* id, char* type, int* depth);
MPI::Datatype Build_neuralnode_type(NeuralNodeSmall * nns);
// void Build_neuralnode_type(NeuralNodeSmall * nns,
// 		     MPI::Datatype *mpi_t_ptr);
void Build_genome_type(Genome * g,
		       MPI::Datatype *mpi_t_ptr);
using namespace std;

class Neatzsche_MPI : public Neatzsche_Comm {
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
//     NeuralNodeSmall ns;
//     GeneSmall gs;
//     nodetype = Build_neuralnode_type(&ns);
//     genetype = Build_gene_type(&gs);
  }
  virtual ~Neatzsche_MPI(){}
  int getRank(){return rank;}
  int getSize(){return size;}
  static const unsigned int MPI_Cont = 0;
  static const unsigned int MPI_Stop = 1;
  virtual bool readPopulation(Phenotypes * p, Coevolution * c, TransferFunctions * tfs);
  virtual void outputPopulation(Population * pop, unsigned int nodes,  Coevolution * c, 
				unsigned int i, bool lastgen);
  virtual void sendSeed(int seed)
  {
    for(int i=1;i<size;i++)
      MPI::COMM_WORLD.Send(&seed,1,MPI::INT,i,0);
  }
  virtual int receiveSeed()
  {
    int ret;
    MPI::COMM_WORLD.Recv(&ret,1,MPI::INT,0,0);
    return ret;
  }
  virtual void outputFitness(Phenotypes * p)
  {
    int size, id; double f;
    size = p->size();
    MPI::COMM_WORLD.Send(&size,1,MPI::INT,0,0);
    for(unsigned int i=0;i<p->size();i++){
      id =  p->at(i)->getID();
      f = p->at(i)->getFitness();
      MPI::COMM_WORLD.Send(&id,1,MPI::INT,0,0);
      MPI::COMM_WORLD.Send(&f,1,MPI::DOUBLE,0,0);
    }
  }
  virtual void readFitness(Population * p, unsigned int i)
  {
    int id,n; double f; Phenotypes *members = p->getMembers();
    for(int i=1;i<size;i++){
      MPI::COMM_WORLD.Recv(&n,1,MPI::INT,i,0);    
      for(int i2=0;i2<n;i2++){
	MPI::COMM_WORLD.Recv(&id,1,MPI::INT,i,0);
	MPI::COMM_WORLD.Recv(&f,1,MPI::DOUBLE,i,0);
// 	for(int i3=0;i3<members->size();i3++)
// 	  if(members->at(i3)->getID() == id)
	//cout << "setting genome " << members->at(id)->getID() << " (fakeid: "<<id<<" ) to fitness " << f << endl;
	members->at(id)->setFitness(f); 
	members->at(id)->transferFitness();
      }
    }
  }
};

#endif
