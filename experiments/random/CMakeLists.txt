PROJECT(randomfitness)
cmake_minimum_required(VERSION 2.6)

INCLUDE(FindBoost)

SET(FITNESS_SOURCES
src/eval.cpp

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


ADD_LIBRARY(randomfitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(randomfitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")
# ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)

TARGET_LINK_LIBRARIES(randomfitness neatzschelib)


