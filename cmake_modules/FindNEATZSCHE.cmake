FIND_PATH(NEATZSCHE_INCLUDE_DIR evaluator.h 
  /usr/include/neatzsche /usr/local/include/neatzsche 
  /opt/local/include/neatzsche $ENV{HOME}/local/include/neatzsche
  $ENV{HOME}/include/neatzsche) 

IF (CMAKE_GENERATOR STREQUAL Xcode)
   FIND_LIBRARY(NEATZSCHE_LIBRARY neatzsche PATH    
  $ENV{HOME}/Documents/build/neatzsche-xcode/Debug) 
ELSE (CMAKE_GENERATOR STREQUAL Xcode)
     FIND_LIBRARY(NEATZSCHE_LIBRARY neatzsche PATH 
     /usr/lib /usr/local/lib
     /opt/local/lib $ENV{HOME}/local/lib
     $ENV{HOME}/lib) 
ENDIF (CMAKE_GENERATOR STREQUAL Xcode)

  


IF (NEATZSCHE_INCLUDE_DIR AND NEATZSCHE_LIBRARY)
   SET(NEATZSCHE_FOUND TRUE)
ENDIF (NEATZSCHE_INCLUDE_DIR AND NEATZSCHE_LIBRARY)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NEATZSCHE DEFAULT_MSG NEATZSCHE_LIBRARY NEATZSCHE_INCLUDE_DIR)

IF (NEATZSCHE_FOUND)
   IF (NOT Neatzsche_FIND_QUIETLY)
      MESSAGE(STATUS "Found Neatzsche: ${NEATZSCHE_LIBRARY}")
   ENDIF (NOT Neatzsche_FIND_QUIETLY)
ELSE (NEATZSCHE_FOUND)
   IF (Neatzsche_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find Neatzsche")
   ENDIF (Neatzsche_FIND_REQUIRED)
ENDIF (NEATZSCHE_FOUND)
