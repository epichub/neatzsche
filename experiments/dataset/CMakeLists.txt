PROJECT(gofitness)
cmake_minimum_required(VERSION 2.6)

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
$ENV{HOME}/local/include
)

LINK_DIRECTORIES(
$ENV{HOME}/local/lib
)


ADD_LIBRARY(datasetfitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(datasetfitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")
# ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)

TARGET_LINK_LIBRARIES(datasetfitness neatzschelib)


