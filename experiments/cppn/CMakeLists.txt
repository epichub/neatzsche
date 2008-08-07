PROJECT(cppnfitness)
cmake_minimum_required(VERSION 2.6)

INCLUDE(FindBoost)
INCLUDE(FindTIFF)

SET(FITNESS_SOURCES
src/image.c
src/eval.cpp

include/image.h
include/eval.h
)

INCLUDE_DIRECTORIES(
include
${Boost_INCLUDE_DIRS}
${TIFF_INCLUDE_DIR}
$ENV{HOME}/local/include
)

LINK_DIRECTORIES(
$ENV{HOME}/local/lib
${TIFF_LIBRARY}/../
)

SET_SOURCE_FILES_PROPERTIES(src/image.c include/image.h PROPERTIES LANGUAGE "CXX")
ADD_LIBRARY(cppnfitness SHARED ${FITNESS_SOURCES})
SET_TARGET_PROPERTIES(cppnfitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")

TARGET_LINK_LIBRARIES(cppnfitness neatzschelib tiff)


