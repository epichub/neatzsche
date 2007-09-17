CC  = gcc
CXX = g++

.SUFFIXES:

OPTS = -O -Wall
ifeq ($(STYLE), DEBUG)
  OPTS = -g -Wall -DDEBUG
endif
ifeq ($(STYLE), PROFILE)
  OPTS = -pg -Wall
endif
ifeq ($(STYLE), RELEASE)
  OPTS = -O3 -Wall
endif

os-type := $(shell uname)

GL_LIB=-lGL -lGLU -lglut
INCLUDE=-I$(HOME)/local/include
LIBS=-L$(HOME)/local/lib -Wl,--rpath,$(HOME)/local/lib

ifeq ($(os-type), SunOS)
#  GL_LIB=-lXmu -lX11 -lXext -lXi -lMesaGL -lm -lglut -lMesaGLU
  LIBS=-L$(HOME)/local/lib -Wl,-R,$(HOME)/local/lib
  INCLUDE+= -I/store/include
endif

ifeq ($(os-type), ubuntu)
  GL_LIB=-lGL -lGLU -lglut
  LIBS=$(LIBS) -L/usr/lib/nvidia
endif

ifeq ($(os-type), Darwin)
  LIBS=-L$(HOME)/local/lib
endif

ostype:
	@echo "os-type is \"$(os-type)\""

clean:
	rm -f *~ *.o a.out

gl_sleeper:
#	@echo "The OS type is: $(OSTYPE)"
	g++ $(OPTS) $(INCLUDE) $(LIBS) -o glsleeper gl_sleeper.cpp $(GL_LIB) 
# 	@if [ -z "`grep glsleeper .cvsignore`" ]; then echo glsleeper >>.cvsignore; fi

logio: logio.cpp
	$(CXX) $(OPTS) $(INCLUDE) $(LIBS) -o logio $< -lpthread -lutilities
pipeio: pipeio.cpp
	$(CXX) $(OPTS) $(INCLUDE) $(LIBS) -o pipeio $< -lpthread -lutilities

%: %.cpp force
	$(CXX) $(OPTS) -o $@ $<
force: ;
