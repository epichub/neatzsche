PROJECT(datasetfitness)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake_modules/")
INCLUDE(FindNEATZSCHE)
INCLUDE(FindBoost)

SET(FITNESS_SOURCES
src/dataset.cpp
src/eval.cpp

include/dataset.h
include/eval.h
)

INCLUDE_DIRECTORIES(
include
${Boost_INCLUDE_DIRS}
${NEATZSCHE_INCLUDE_DIR}
)

LINK_DIRECTORIES(
$ENV{HOME}/local/lib
)


ADD_LIBRARY(helloworldfitness SHARED ${FITNESS_SOURCES})
INSTALL(TARGETS helloworldfitness
  LIBRARY DESTINATION lib)
SET_TARGET_PROPERTIES(helloworldfitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")
# ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)

TARGET_LINK_LIBRARIES(helloworldfitness ${NEATZSCHE_LIBRARY})


