# make neat
#
TAGS= etags -a
LDFLAGS= -lpthread

GOSOURCE=gowrapper.cpp gowrapper.h
GOOBJ=gowrapper.o
ifeq ($(GG), CVS)
  DEFINES=-DGGCVS
endif
ifeq ($(GG), )
  DEFINES=-DGGSTABLE
endif

SRCS=go-consistency.cpp playtwoplayergame.cpp playgame.cpp test-xor.cpp unit-statechange.cpp puregotest.cpp statechanges.cpp coevolution.cpp neuralmath.cpp ann.cpp gene.cpp genome.cpp genetics.cpp evoops.cpp settings.cpp evolution.cpp evaluator.cpp dataset.cpp neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h iface.h dataset.h runner.h runner.cpp $(GOSOURCE) testwrite.cpp
TSRCS=tinyxml.cpp tinyxmlparser.cpp tinyxmlerror.cpp tinystr.cpp
TOBJS := $(addsuffix .o,$(basename ${TSRCS}))
OBJS=coevolution.o neuralmath.o ann.o gene.o statechanges.o genome.o genetics.o evoops.o settings.o evolution.o evaluator.o $(GOOBJ) dataset.o
OBJS2=coevolution.o neuralmath.o ann.o gene.o statechanges.o genome.o genetics.o evoops.o settings.o evolution.o evaluator.o $(GOOBJ) dataset.o
OBJS3=$(OBJS) test-xor.o
OBJS4=$(OBJS) test-go.o
OBJS5=$(OBJS) puregotest.o
OBJS6=$(OBJS) unit-statechange.o
OBJS7=$(OBJS) playgame.o
OBJS8=$(OBJS) go-consistency.o
OBJS9=$(OBJS) playtwoplayergame.o
OBJS9=$(OBJS) xorgenomeoutput.o

IINCLUDE=-I$(HOME)/local/include -I$(HOME)/local/include/c++/4.3.0
BLIBS=-L$(HOME)/local/lib
OPTS = -g -Wall

os-type := $(shell uname)
p-type := $(shell uname -p)

ifeq ($(STYLE), DEBUG)
  OPTS = -g -Wall -DDEBUG
endif
ifeq ($(STYLE), PROFILE)
  OPTS = -pg -Wall
endif
ifeq ($(STYLE), RELEASE)
  OPTS = -O3 -Wall
endif
ifeq ($(STYLE), OPTIMISED)
  ifeq ($(os-type), Linux)
    ifeq ($(p-type), AMD Athlon(tm) 64 X2 Dual Core Processor 4200+)
      OPTS = -march=k8 -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math
    endif
    ifeq ($(p-type), AMD Athlon(tm) 64 X2 Dual Core Processor 4600+)
      OPTS = -march=k8 -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math
    endif
    ifeq ($(p-type), i686)
      OPTS = -march=pentium4 -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math
    endif
    ifeq ($(p-type), Cell Broadband Engine, altivec supported)
      OPTS = -O3 -pipe -mtune=970 -mcpu=970 -mabi=altivec -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math
    endif
    ifeq ($(p-type), unknown)	
      OPTS = -march=nocona -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math
    endif
  endif
  ifeq ($(os-type), Darwin)
    ifeq ($(p-type), i386)	
      OPTS = -march=nocona -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math
    endif
    ifeq ($(p-type), powerpc)	
      OPTS = -mtune=powerpc -maltivec -mabi=altivec -mcpu=7400 -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math
    endif
  endif
endif

ifeq ($(CC),)
 CC=g++
endif
CXX=g++ $(OPTS) $(DEFINES) $(BINCLUDE)

ifeq ($(os-type), Linux)
  LIBS=-L$(HOME)/local/lib -Wl,--rpath,$(HOME)/local/lib
  BLIBS=
endif

ifeq ($(os-type), Linux)
  BINCLUDE = $(IINCLUDE)
endif
ifeq ($(os-type), Darwin)
  BINCLUDE = $(IINCLUDE) -I/opt/local/include
endif

all:	neatmaster neatslave tags test-xor test-go playgame

dist:
	@ +make STYLE=RELEASE

opt:
	@ +make STYLE=OPTIMISED

profile:
	@ +make STYLE=PROFILE

gcc-ver:
	@echo `$(CC) --version`

gcc:
	@echo $(CC)

# To get things out of the revision control system
$(SRCS):
	$(CXX) $(BINCLUDE) $(BLIBS) -c $*.cpp -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses 

neatmaster.cpp: $(OBJS) runner.h
	$(CXX) $(BLIBS) -c neatmaster.cpp

neatslave.cpp: $(OBJS2) iface.h
	$(CXX) $(BLIBS) -c neatslave.cpp


neatmaster: $(OBJS) $(TOBJS) neatmaster.o runner.o statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) dataset.h tinyxml.h tinystr.h  iface.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS) $(TOBJS) runner.o neatmaster.o  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv neatmaster ../

neatslave: $(OBJS2) neatslave.o statechanges.h coevolution.h neatslave.cpp neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS2) neatslave.o  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv neatslave ../
#test.o:
#	$(CXX) $(BINCLUDE) $(BLIBS) -c test-xor.cpp

test-xor: $(OBJS3) statechanges.h coevolution.h test-xor.cpp neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS3)  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv test-xor ../

test-go: $(OBJS4) test-go.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h tinyxml.h tinystr.h 
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS4) $(TOBJS) runner.o  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv test-go ../

puregotest: $(OBJS5) puregotest.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS5)  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv puregotest ../

unit-statechange: $(OBJS6) unit-statechange.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS6)  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses

playgame: $(OBJS) playgame.o playgame.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS) playgame.o  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv playgame ../show

testwrite: $(OBJS) testwrite.o testwrite.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS) testwrite.o  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv testwrite ../testwrite

playtwoplayergame: $(OBJS) playtwoplayergame.o playtwoplayergame.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ playtwoplayergame.o $(OBJS)  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv playtwoplayergame ../

# xorgenomeoutput: $(OBJS) xorgenomeoutput.o xorgenomeoutput.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
# 	$(CXX) $(BLIBS) $(LIBS) -o $@ xorgenomeoutput.o $(OBJS)  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
# 	@ mv xorgenomeoutput ../

go-consistency: $(OBJS8) go-consistency.cpp statechanges.h coevolution.h neuralmath.h ann.h gene.h genome.h genetics.h evoops.h settings.h evolution.h evaluator.h $(GOSOURCE) iface.h dataset.h
	$(CXX) $(BLIBS) $(LIBS) -o $@ $(OBJS8)  -lpthread -lboard -lengine -lutils -lsgf -lpatterns -lncurses
	@ mv go-consistency ../

# where are functions/procedures?
tags: 
	$(TAGS) $(SRCS)

# what have I done wrong?
lint: $(SRCS)
	lint  $(SRCS)

# clean out the dross
clean:
	-rm *.o TAGS

ostype:
	@echo "os-type is \"$(os-type)\""
ptype:
	@echo "p-type is \"$(p-type)\""

libecho:
	@echo "libs is \"$(LIBS)\""

includeecho:
	@echo "includes is \"$(BINCLUDE)\""