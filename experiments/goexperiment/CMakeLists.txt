PROJECT(gofitness)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake_modules/")
INCLUDE(FindNEATZSCHE)
INCLUDE(FindBoost)
SET(CMAKE_INSTALL_PREFIX "$ENV{HOME}/local/")
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
${NEATZSCHE_INCLUDE_DIR}
${CMAKE_INSTALL_PREFIX}/include
)

LINK_DIRECTORIES(
${CMAKE_INSTALL_PREFIX}/lib
)
ADD_DEFINITIONS(-DGGSTABLE)
ADD_LIBRARY(gofitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(gofitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")
# ADD_EXECUTABLE(neatzsche src/neatzsche.cpp)

TARGET_LINK_LIBRARIES(gofitness patterns engine board utils sgf ncurses ${NEATZSCHE_LIBRARY})

EXECUTE_PROCESS(
COMMAND "./configure" "--prefix=${CMAKE_INSTALL_PREFIX}" 
COMMAND "make" 
COMMAND "make" "install" 
COMMAND "cp" "**/*a ${CMAKE_INSTALL_PREFIX}/lib"
COMMAND "cp engine/board.h ${CMAKE_INSTALL_PREFIX}/include ; cp engine/hash.h ${CMAKE_INSTALL_PREFIX}/include ; cp engine/clock.h ${CMAKE_INSTALL_PREFIX}/include ; cp engine/gnugo.h ${CMAKE_INSTALL_PREFIX}/include ; cp sgf/sg_properties.h ${CMAKE_INSTALL_PREFIX}/include ; cp sgf/sgftree.h ${CMAKE_INSTALL_PREFIX}/include ; cp utils/winsocket.h ${CMAKE_INSTALL_PREFIX}/include ; cp config.h ${CMAKE_INSTALL_PREFIX}/include"
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCES_DIR}/gnugo-3.6)



