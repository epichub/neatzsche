# ABOUT
Neatzsche is a implementation of Kenneth Stanley's NEAT algorithm.
The implementation was started as a part of Bjørn Magnus Mathisens
master thesis in 2007. Part of it was written at [NTNU](www.ntnu.com)
in Trondheim and parts of it was written while visiting Ken's research
group at UCF.

The implementation is done in C++ and supports MPI for running in
paralell; The fitness evaluation is distributed, while the genetic
computations are done at the central server. The user can instruct the
code to give the "master" node only a given percentage of the
fitness-evaluation workload of the other nodes. This way one can
guarantee that the master node is finished with it's fitness
evaluations before the results come in from the other nodes in the MPI network.

The code has been used in two master thesis:
* My own: implementing the MPI-distributed NEAT in c++ and finding
it's usefullness in evaluating how a "roving eye" can play Go.
* Master thesis by Anders Storsveen: Where he uses my NEAT. Link:
  implementation to show that NEATS usage as a CPPN (compositional
  pattern producing networks) can create an EYE through evolution. Link:


The code was created for research, and as such has poor interface
design. It has many command line arguments some of which are nested
into substrings depending on previous arguments - it is all however
documentet when running the binary.

More documentation will come.

# Arguments

	usage: (all the node numbers are for the initial generation) 
	neatzsche [seed (0 for new)] [settings file] [pop options] [selector option] [phenotype eval sofile] [phenotype eval options] [stopcondition] [mpi run(0/1)] [speciationgraph (0/1)]
	where:
		[pop options] = "spawn [input nodes] [output nodes] [hidden nodes] [link probability] [population size]"
		[pop options2] = "genesis [genome-file] [population size] [initial elitism]"
		[selector options] = "fp [number of top species getting elitism]"
		[selector options2] = "rank [s] [number of top species getting elitism]"
		[selector options3] = "sigma [number of top species getting elitism]"
		[stop condition1] = "count [generations] [runs]"
		[stop condition2] = "key"

	
# Plugin Structure

The fitness evaluation is implemented as a plugin system, so you only
implement a given "api" so that the NEAT algorithm can call you
fitness evalutation.

