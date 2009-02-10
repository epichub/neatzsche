PROJECT(eyefitness)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake_modules/")
INCLUDE(FindNEATZSCHE)
INCLUDE(FindBoost)
INCLUDE(FindQt4)

SET(FITNESS_SOURCES
src/cell.cpp
src/eval.cpp
src/lightsim.cpp
src/lightsource.cpp
src/lightvector.cpp
src/lsc.cpp
src/nworld.cpp
src/opaquecell.cpp

#src/test-eye.cpp

include/cell.h
include/eval.h
include/lightsim-viewer.h
include/lightsim.h
include/lightsource.h
include/lightvector.h
include/lsc.h
include/nworld.h
include/opaquecell.h

)
SET(EYE_QT
src/paintarea.cpp
src/paintwindow.cpp

include/paintarea.h
include/paintwindow.h
)
INCLUDE_DIRECTORIES(
include
${Boost_INCLUDE_DIRS}
${Qt_INCLUDE_DIR}
${NEATZSCHE_INCLUDE_DIR} 
#$ENV{HOME}/local/include
)

# LINK_DIRECTORIES(
# $ENV{HOME}/local/lib
# )

ADD_LIBRARY(eyefitness SHARED ${FITNESS_SOURCES})
INSTALL(TARGETS eyefitness
  LIBRARY DESTINATION lib)
SET_TARGET_PROPERTIES(eyefitness PROPERTIES LINK_FLAGS "-shared -Wl -dylib")
FIND_PACKAGE(Qt4)
if(QT4_FOUND)
  SET(QT_MOC_SRCS include/paintwindow.h include/lightsim-viewer.h)
  INCLUDE(${QT_USE_FILE})
  QT4_WRAP_CPP(QT_MOC_SRCS ${QT_MOC_SRCS})
  ADD_EXECUTABLE(lightsim-viewer src/lightsim-viewer.cpp ${EYE_QT} ${QT_MOC_SRCS} ${FITNESS_SOURCES})

#   ADD_EXECUTABLE(lightsim-test src/lightsim-test.cpp ${EYE_QT})
  
  TARGET_LINK_LIBRARIES(lightsim-viewer ${NEATZSCHE_LIBRARY} ${QT_LIBRARIES})
  INSTALL(TARGETS lightsim-viewer
    RUNTIME DESTINATION bin)
elseif(QT4_FOUND)
  message("woot ikke noe Qt4 så blikke no printing pårei")
endif(QT4_FOUND)

TARGET_LINK_LIBRARIES(eyefitness ${NEATZSCHE_LIBRARY})