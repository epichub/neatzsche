PROJECT(gofitness)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake_modules/")
INCLUDE(FindNEATZSCHE)
INCLUDE(FindGNUGO)
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


if(GNUGO_FOUND)
  SET(GNUGO_INCL
    ${GNUGO_INCLUDE_DIR})
  SET(GNUGO_LIB
    ${GNUGO_LIBRARY})
#  TARGET_LINK_LIBRARIES(gofitness patterns engine board utils sgf ncurses ${GNUGO_LIBRARY})
else(GNUGO_FOUND)
  message("gnugo not found.. making it for you..")
  EXECUTE_PROCESS( 
    COMMAND "./configure" "--prefix=${CMAKE_INSTALL_PREFIX}" 
    COMMAND "make" 
    COMMAND "make" "install" 
    COMMAND "mkdir" "-p" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    COMMAND "cp" "engine/libboard.a" "${CMAKE_INSTALL_PREFIX}/lib/"
    COMMAND "cp" "engine/libengine.a" "${CMAKE_INSTALL_PREFIX}/lib/"
    COMMAND "cp" "patterns/libpatterns.a" "${CMAKE_INSTALL_PREFIX}/lib/"
    COMMAND "cp" "sgf/libsgf.a" "${CMAKE_INSTALL_PREFIX}/lib/"
    COMMAND "cp" "utils/libutils.a" "${CMAKE_INSTALL_PREFIX}/lib/"
    COMMAND "cp" "engine/board.h" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    COMMAND "cp" "engine/hash.h" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    COMMAND "cp" "engine/clock.h" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    COMMAND "cp" "engine/gnugo.h" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    COMMAND "cp" "sgf/sgf_properties.h" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    COMMAND "cp" "sgf/sgftree.h" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    COMMAND "cp" "config.h" "${CMAKE_INSTALL_PREFIX}/include/gnugo"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/gnugo-3.6
    RESULT_VARIABLE GNUGORES
    OUTPUT_VARIABLE GNUGOOUT
    ERROR_VARIABLE GNUGOERR)
#   if(GNUGORES)
    message("resvar: ${GNUGORES}")
#   endif(GNUGORES)
  SET(GNUGO_INCL
    ${CMAKE_INSTALL_PREFIX}/include/gnugo)
  SET(GNUGO_LIB
    ${CMAKE_INSTALL_PREFIX}/lib)
#  TARGET_LINK_LIBRARIES(gofitness patterns engine board utils sgf ncurses ${NEATZSCHE_LIBRARY} )
endif(GNUGO_FOUND)
# message("cwd: ${CMAKE_CURRENT_SOURCE_DIR}/gnugo-3.6")
# message("resvar: ${GNUGORES}")
# message("outvar: ${GNUGOOUT}")
# message("errvar: ${GNUGOERR}")

INCLUDE_DIRECTORIES(
  include
  ${Boost_INCLUDE_DIRS}${CMAKE_INSTALL_PREFIX}/lib/
  ${NEATZSCHE_INCLUDE_DIR}
  ${GNUGO_INCL}
  )

LINK_DIRECTORIES(
  ${GNUGO_LIB_PATH}
  ) 

ADD_DEFINITIONS(-DGGSTABLE)
ADD_LIBRARY(gofitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(gofitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")

TARGET_LINK_LIBRARIES(gofitness patterns engine board utils sgf ncurses ${NEATZSCHE_LIBRARY})







