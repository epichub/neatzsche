PROJECT(NEATZSCHE)
cmake_minimum_required(VERSION 2.6)
SET(MPI_COMPILER mpicxx)
INCLUDE(FindMPI)
INCLUDE(FindBoost)



SET(NEATZSCHE_SOURCES
src/statechanges.cpp 
src/coevolution.cpp
src/neuralmath.cpp 
src/ann.cpp
src/gene.cpp
src/genome.cpp
src/genetics.cpp 
src/evoops.cpp
src/settings.cpp 
src/evolution.cpp
src/evaluator.cpp 
src/dataset.cpp
src/runner.cpp
src/boye.cpp 
src/neatmpi.cpp
src/tinyxml.cpp
src/tinystr.cpp
src/tinyxmlerror.cpp
src/tinyxmlparser.cpp

include/neuralmath.h 
include/ann.h
include/gene.h 
include/genome.h
include/genetics.h 
include/evoops.h
include/settings.h 
include/evolution.h
include/evaluator.h 
include/iface.h
include/runner.h 
include/tinystr.h
include/tinyxml.h
include/xmlconvert.h
)

if(Boost_FOUND)
  message("boost found")
  message(${Boost_INCLUDE_DIRS})
else(Boost_FOUND)
  message("boost NOT found")
endif(Boost_FOUND)

INCLUDE_DIRECTORIES(
include
${Boost_INCLUDE_DIRS}
${MPI_INCLUDE_PATH}
)

ADD_LIBRARY(neatzschelib STATIC ${NEATZSCHE_SOURCES})
SET_TARGET_PROPERTIES(neatzschelib PROPERTIES COMPILE_FLAGS "-fPIC")
SET_TARGET_PROPERTIES(neatzschelib PROPERTIES LINK_FLAGS "-rdynamic")
TARGET_LINK_LIBRARIES(neatzschelib ${MPI_LIBRARIES} dl)
ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)

ADD_EXECUTABLE(neatzsched src/neatzsche.cpp)
SET_TARGET_PROPERTIES(neatzsched PROPERTIES COMPILE_FLAGS "-Wall -g")

TARGET_LINK_LIBRARIES(neatzsche neatzschelib ${MPI_LIBRARIES} dl)
TARGET_LINK_LIBRARIES(neatzsched neatzschelib ${MPI_LIBRARIES} dl)
# FindMPI(MPI_VARIABLE)
# FindBoost(BOOST_LIB)


# add_library(neatzsche STATIC )