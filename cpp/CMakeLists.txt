PROJECT(NEATZSCHE)
cmake_minimum_required(VERSION 2.6)
SET(MPI_COMPILER mpicxx)
INCLUDE(FindMPI)
INCLUDE(FindBoost)

SET(CMAKE_INSTALL_PREFIX "$ENV{HOME}/local/")
SET(NEATZSCHE_INCLUDE
include/neuralmath.h 
include/ann.h
include/gene.h 
include/genome.h
include/genetics.h 
include/evoops.h
include/settings.h 
include/evolution.h
include/coevolution.h
include/evaluator.h 
include/iface.h
include/runner.h 
include/tinystr.h
include/tinyxml.h
include/xmlconvert.h)

SET(NEATZSCHE_CPP
src/neuralmath.cpp 
src/ann.cpp
src/gene.cpp
src/genome.cpp
src/genetics.cpp 
src/evoops.cpp
src/settings.cpp 
src/evolution.cpp
src/coevolution.cpp
src/evaluator.cpp 
src/runner.cpp
src/boye.cpp 
src/neatmpi.cpp
src/tinyxml.cpp
src/tinystr.cpp
src/tinyxmlerror.cpp
src/tinyxmlparser.cpp
)
INSTALL(FILES ${NEATZSCHE_INCLUDE}
  DESTINATION include/neatzsche)
# INSTALL(PROGRAMS neatzsche ${CMAKE_CURRENT_BINARY_DIR}/neatzsche
#   DESTINATION bin)



SET(NEATZSCHE_SOURCES
  ${NEATZSCHE_CPP}
  ${NEATZSCHE_INCLUDE})

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

ADD_LIBRARY(libneatzsche STATIC ${NEATZSCHE_SOURCES})

install(TARGETS ${_target_NAME} LIBRARY DESTINATION lib RUNTIME DESTINATION bin ARCHIVE DESTINATION lib)
# install(FILES ../cmake_modules/FindNEATZSCHE.cmake DESTINATION ${CMAKE_ROOT}/Modules)

# INSTALL(TARGETS 
#   libneatzsche
#   RUNTIM DESTINATION bin)
SET_TARGET_PROPERTIES(libneatzsche PROPERTIES COMPILE_FLAGS "-fPIC")


SET_TARGET_PROPERTIES(libneatzsche PROPERTIES LINK_FLAGS "-rdynamic")
SET_TARGET_PROPERTIES(libneatzsche PROPERTIES OUTPUT_NAME "neatzsche")
TARGET_LINK_LIBRARIES(libneatzsche ${MPI_LIBRARIES} dl)
ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)
INSTALL(TARGETS libneatzsche neatzsche
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin)
TARGET_LINK_LIBRARIES(neatzsche libneatzsche ${MPI_LIBRARIES} dl)

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


SET(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")
SET(CMAKE_C_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG}})

SET(CMAKE_CXX_FLAGS ${MYOPTFLAGS})
SET(CMAKE_C_FLAGS ${MYOPTFLAGS})

SET(CMAKE_CXX_FLAGS_RELEASE ${MYOPTFLAGS})
SET(CMAKE_C_FLAGS_RELEASE ${MYOPTFLAGS})
