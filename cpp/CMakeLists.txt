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


#message("system cpu: \"${CMAKE_SYSTEM_PROCESSOR}\"")
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  message("in apple system, setting makefile accordingly")
  if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i386")
    message("setting myoptflags to intel c2d..")
    SET(MYOPTFLAGS "-march=nocona -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math")
  elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "powerpc")
    SET(MYOPTFLAGS "-mtune=powerpc -maltivec -mabi=altivec -mcpu=7400 -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math")
  endif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i386")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i686")
    SET(MYOPTFLAGS "-march=pentium4 -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math")
  elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "Cell Broadband Engine, altivec supported")
    SET(MYOPTFLAGS "-O3 -pipe -mtune=970 -mcpu=970 -mabi=altivec -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math")
  elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "AMD")
    SET(MYOPTFLAGS "-march=k8 -O3 -pipe -fomit-frame-pointer -funroll-loops -ftree-vectorize -ftracer -ffast-math")
  endif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i686")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#message("myoptflags \"${MYOPTFLAGS}\"")
# message(${MYOPTFLAGS})
SET_TARGET_PROPERTIES(neatzschelib PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} ${MYOPTFLAGS}")
SET_TARGET_PROPERTIES(neatzsche PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} ${MYOPTFLAGS}")
# add_library(neatzsche STATIC )
