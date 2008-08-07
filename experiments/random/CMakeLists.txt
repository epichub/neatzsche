PROJECT(randomfitness)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake_modules/")
INCLUDE(FindNEATZSCHE)
INCLUDE(FindBoost)

SET(FITNESS_SOURCES
src/eval.cpp
include/eval.h
)

INCLUDE_DIRECTORIES(
include
${Boost_INCLUDE_DIRS}
${NEATZSCHE_INCLUDE_DIR}
)

ADD_LIBRARY(randomfitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(randomfitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")

TARGET_LINK_LIBRARIES(randomfitness ${NEATZSCHE_LIBRARY})


