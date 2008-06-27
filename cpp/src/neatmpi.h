#ifndef _MPI_H_
#define _MPI_H_
#include "evaluator.h"
// extern "C" {

#include <mpi.h>
//}

MPI::Datatype Build_gene_type(GeneSmall * gs);
//MPI::Datatype Build_neuralnode_type(int* id, char* type, int* depth);
MPI::Datatype Build_neuralnode_type(NeuralNodeSmall * nns);
// void Build_neuralnode_type(NeuralNodeSmall * nns,
// 		     MPI::Datatype *mpi_t_ptr);
void Build_genome_type(Genome * g,
		     MPI::Datatype *mpi_t_ptr);
using namespace std;
class Neatzsche_MPI {
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
    NeuralNodeSmall ns;
    GeneSmall gs;
//     nodetype = Build_neuralnode_type(&ns);
//     Build_gene_type(&gs,&genetype);
  }
  ~Neatzsche_MPI(){}
  int getRank(){return rank;}
  int getSize(){return size;}
  static const unsigned int MPI_Cont = 0;
  static const unsigned int MPI_Stop = 1;
  Phenotypes * receive(Phenotypes * p, TransferFunctions * tfs)
  {
    // int MPI::Recv( void *buf, int count, MPI::Datatype datatype, int source, 
    //               int tag, MPI::Comm comm, MPI::Status *status )
    Genome * g = new Genome(tfs);
//     MPI::Datatype * dt;
//     Build_node_type(g,&dt);
//     MPI::Recv ( , message_size, MPI::CHAR, neighbor, 0, MPI::COMM_WORLD, &status );
    MPI::Status status;
    MPI::Datatype ndt,gdt;
    int genomes,genes,nodes;
    MPI::COMM_WORLD.Recv(&genomes,1,MPI::INT,0,0);//Receive the number of genome
    NeuralNodeSmall * nns;
    GeneSmall * gs; 
    nodeVector * nv = NULL; Genes * genev = NULL; vector<Genome *> * v = new vector<Genome *>();
    Genome * genome = NULL;
    int stringc=0; char *strbuf;vector<string> * ftypes = NULL;
    for(unsigned int i=0;i<genomes;i++){
      ftypes = new vector<string>();

      MPI::COMM_WORLD.Recv(&nodes,1,MPI_INT,0,0);
      MPI::COMM_WORLD.Recv(&genes,1,MPI_INT,0,0);
      nns = (NeuralNodeSmall*)malloc(sizeof(NeuralNodeSmall)*nodes);
      gs = (GeneSmall*)malloc(sizeof(GeneSmall)*genes);

//       cout << "sizeof(NeuralNodeSmall): " << sizeof(NeuralNodeSmall)
// 	   << " sizeof(int)+sizeof(char)+sizeof(int): " << sizeof(int)+sizeof(char)+sizeof(int) << endl;
      cout << "allocation done(n: "<<nodes<<" g: "<<genes<<"), starting reception.." << endl;
//       for(int i=0;i<nodes;i++){
      nodetype = Build_neuralnode_type(&nns[0]);
      MPI::COMM_WORLD.Recv(&(nns[i].id),nodes,nodetype,0,0);
      cout << "last node in: " << nns[nodes-1].id << endl;
// 	cout << "received i: " << i << " id: " << nns[i].id << " type: " 
// 	     << nns[i].type << " depth: " << nns[i].depth << endl;
//       }
      //      nodetype = Build_neuralnode_type(&(nns[0].id),&(nns[0].type),&(nns[0].depth));
//       cout << "ns0: " <<MPI::Get_address(&nns[0]) << " ns0id: " << MPI::Get_address(&(nns[0].id))
// 	   << " ns0type: " << MPI::Get_address(&(nns[0].type))
// 	   << " ns0depth: " << MPI::Get_address(&(nns[0].depth))<< endl;
//       cout << "ns1: " <<MPI::Get_address(&nns[1]) << " ns0id: " << MPI::Get_address(&(nns[1].id))
// 	   << " ns1type: " << MPI::Get_address(&(nns[1].type))
// 	   << " ns1depth: " << MPI::Get_address(&(nns[1].depth))<< endl;
//       MPI::Datatype nodetypev = nodetype.Create_hvector(nodes,1,1+sizeof(NeuralNodeSmall)-(sizeof(int)+sizeof(char)+sizeof(int)));
//       MPI::COMM_WORLD.Recv(&(nns[0].id),1,nodetypev,0,0);
//       for(int i=0;i<nodes;i++){

//       }
//       cout << "id of nodes-1: " << nns[nodes-1].id << " receiving nodes: " << nodes << endl;
//       cout << "id of node 1: " << nns[1].id << endl;
//       cout << "id of node 0: " << nns[0].id << endl;
      for(int i=0;i<nodes;i++){//blargh, 1 int would be more usefull in this case:P
	MPI::COMM_WORLD.Probe(0, MPI_Cont, status);
	stringc = status.Get_count(MPI_CHAR);
	strbuf = (char*) malloc(sizeof(char)*stringc);
	MPI::COMM_WORLD.Recv(strbuf,stringc,MPI::CHAR,0,MPI_Cont);//receive the ftype of the node
// 	strbuf[stringc] = '\0';
// 	cout << "stringc: " << stringc << " sizeof(strbuf): "<<sizeof(strbuf) 
// 	     <<"  recv ftype: \"" << strbuf << "\" substred: \""
// 	     << string(strbuf).substr(0,stringc) << "\"" << endl;
	ftypes->push_back(string(strbuf).substr(0,stringc));
	free(strbuf);
      }
//       cout << "receiving a gs " << endl;
      genetype = Build_gene_type(&gs[0]);
      MPI::COMM_WORLD.Recv(gs,genes,genetype,0,0);
      for(int i=0;i<genes;i++){
	cout << "fid: " << gs[i].fid << " tid: " << gs[i].tid << " marker: " 
	     << gs[i].marker << " w: " << gs[i].w << " enabled: " << gs[i].enabled << endl;
      }
//       cout << "done receiving a gs " << endl;

//       cout << "going to make genome and insert! :P " << endl;
      genome = new Genome(tfs);
//       cout << "after new genome" << endl;
      genome->fromSmall(nodes,nns,genes,gs,ftypes);
//       cout << "after from small" << endl;
      cout << "i: "<<i<<" printing my received genome:" << endl;
      cout << genome << endl;
      delete ftypes;
//       cout << "after delet ftype" << endl;
      p->push_back(new Phenotype(genome));
      delete nns; delete gs;
//       cout << "done trying to make genome and insert! " << endl;
    }
    //     MPI::COMM_WORLD.Recvv ( , message_size, MPI_CHAR, neighbor, 0, MPI_COMM_WORLD, &status );
  }
  void send(Population * pop, unsigned int nodes, unsigned int i)
  {
    unsigned int s = pop->getMembers()->size();
    unsigned int n = (s-i)/nodes;
    bool uneven = (floor((s-i)/(double)n)!=(s-i)/(double)n);

    MPI_Datatype * stt;


    GeneSmall * gsv = NULL;
    NeuralNodeSmall * nsv = NULL;
    Genome * genome = NULL; int genes = 0; int nnodes = 0;
    //Build_genome_type(phenotypes->getMembers()->at(i),&stt);	
    int sendtag = Neatzsche_MPI::MPI_Cont;
    string sftype;
    int sc=0;
    while(i < s) {
      if(uneven && (s-i)<(2*n)){
	n = (s-i);
      }
      // 	Phenotypes*[] = new Phenotypes * [];
      
      sc = ((sc+1) % (size-1))+1;
//       cout << "sending to sc: "<<sc<<" : " << n << " genomes " << endl;
      MPI::COMM_WORLD.Send(&n,1,MPI_INT,sc,sendtag);//send number of genomes incoming
      for(size_t i2 = 0; i2 < n && i < s; i2++, i++) {
	//	Genome ** g = new Genome * [];

	genome = pop->getMembers()->at(i)->getGenome();
	cout << "sending genome " << genome->getID() 
	     << " nodes: " << genome->getNodes()->size()
	     << " genes: " << genome->getGenes()->size() << endl;
	genome->toSmall(nsv,gsv,&nnodes,&genes);
// 	cout << "etter tosmall, nsvat0 sin id: " << nsv[0].id << endl;
// 	for(unsigned int i=0;i<genome->size()
// 	Build_genome_type(phenotypes->getMembers()->at(i),&dt);	
	if(i2<(n-1))
	  sendtag = MPI_Cont;
	else
	  sendtag = MPI_Stop;
// 	nnodes = genome->getNodes()->size();
// 	genes = genome->geGenes()->size();
// 	cout << "sending " << nnodes << " nodes " << endl;
	MPI::COMM_WORLD.Send(&nnodes,1,MPI_INT,sc,sendtag);//send number of nodes
// 	cout << "sending " << genes << " genes " << endl;
	MPI::COMM_WORLD.Send(&genes,1,MPI_INT,sc,sendtag);//send number of genes
// 	cout << "sending nsv " << endl;

	//	for(int i=0;i<nodes;i++){
	nodetype = Build_neuralnode_type(&nsv[0]);
	// 	  cout << "etter buildneuralnodetype" << endl;
	MPI::COMM_WORLD.Send(nsv,nnodes,nodetype,sc,sendtag);//send node vector
	for(int i=0;i<nnodes;i++){
	  cout << "##SENDING node id: " << nsv[i].fid << " tid: " << gsv[i].tid << " marker: " 
	       << gsv[i].marker << " w: " << gsv[i].w << " enabled: " << gsv[i].enabled << endl;
	}
	  //	}
// 	nodetype = Build_neuralnode_type(&(nsv[0].id),&(nsv[0].type),&(nsv[0].depth));
// 	MPI::Datatype nodetypev = nodetype.Create_hvector(nnodes,1,1+sizeof(NeuralNodeSmall)-(sizeof(int)+sizeof(char)+sizeof(int)));
// 	MPI::COMM_WORLD.Send(&(nsv[0].id),1,nodetypev,sc,sendtag);//send node vector
// 	cout << "after sending nsv " << endl;
	for(int i=0;i<nnodes;i++){
	  sftype = "";
	  sftype = genome->getNodes()->at(i)->getTFunc()->ftype;
// 	  cout << "length: "<<sftype.length()<<" sending ftype: \"" << sftype.c_str() << "\"" << endl;
	  MPI::COMM_WORLD.Send(sftype.c_str(),sftype.length(),MPI::CHAR,sc,sendtag);//send gene vector
	}
	genetype = Build_gene_type(&gsv[0]);
	MPI::COMM_WORLD.Send(gsv,genes,genetype,sc,sendtag);//send gene vector
	for(int i=0;i<genes;i++){
	  cout << "##SENDING gene fid: " << gsv[i].fid << " tid: " << gsv[i].tid << " marker: " 
	       << gsv[i].marker << " w: " << gsv[i].w << " enabled: " << gsv[i].enabled << endl;
	}
	delete nsv; delete gsv;
	if(i==1)
	  exit(0);
      }
//       MPI_Send(pop->getMembers()->at(0),1,stt,sc,MPI_Stop,MPI_COMM_WORLD);
    }

  }
};
#endif
