PROJECT(gofitness)
cmake_minimum_required(VERSION 2.6)

INCLUDE(FindBoost)

SET(FITNESS_SOURCES
src/statechanges.cpp
src/gowrapper.cpp
src/eval.cpp

include/statechanges.h
include/gowrapper.h
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
ADD_DEFINITIONS(-DGGSTABLE)
ADD_LIBRARY(gofitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(gofitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")
# ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)

TARGET_LINK_LIBRARIES(gofitness patterns engine board utils sgf ncurses neatzschelib)


