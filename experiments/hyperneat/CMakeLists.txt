PROJECT(hyperfitness)
cmake_minimum_required(VERSION 2.6)

INCLUDE(FindBoost)

SET(FITNESS_SOURCES
src/eval.cpp
src/dataset.cpp
src/dataseteval.cpp

include/eval.h
include/dataset.h
include/dataseteval.h
)

INCLUDE_DIRECTORIES(
include
${Boost_INCLUDE_DIRS}
$ENV{HOME}/local/include
)

LINK_DIRECTORIES(
$ENV{HOME}/local/lib
)


ADD_LIBRARY(hyperfitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(hyperfitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")
# ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)

TARGET_LINK_LIBRARIES(hyperfitness neatzschelib)


