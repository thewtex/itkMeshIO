CMAKE_MINIMUM_REQUIRED(VERSION 2.4)
IF(COMMAND CMAKE_POLICY)
  CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND CMAKE_POLICY)

PROJECT(MeshIO)

FIND_PACKAGE(ITK REQUIRED)
INCLUDE(${ITK_USE_FILE})

IF( ITK_VERSION_MAJOR MATCHES "3" )
  IF( NOT ITK_USE_REVIEW )
    MESSAGE(FATAL_ERROR "ITK must be build with ITK_USE_REVIEW turned ON")
  ENDIF( NOT ITK_USE_REVIEW )
ENDIF()

SET(EXECUTABLE_OUTPUT_PATH ${MeshIO_BINARY_DIR}/bin CACHE INTERNAL "Where to put the executables")
SET(LIBRARY_OUTPUT_PATH ${MeshIO_BINARY_DIR}/bin CACHE INTERNAL "Where to put the libraries")


INCLUDE(CTest)

#INCLUDE_DIRECTORIES(
#  ${PROJECT_SOURCE_DIR}/Source
#  )

# Disable MSVC 8 warnings
IF(WIN32)
  OPTION(DISABLE_MSVC8_DEPRECATED_WARNINGS
         "Disable Visual Studio 8 deprecated warnings" ON)
  MARK_AS_ADVANCED(FORCE DISABLE_MSVC8_DEPRECATED_WARNINGS)
  IF(DISABLE_MSVC8_DEPRECATED_WARNINGS)
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
  ENDIF(DISABLE_MSVC8_DEPRECATED_WARNINGS)
ENDIF(WIN32)

SET(GIFTI_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Utilities/gifticlib)
INCLUDE_DIRECTORIES(BEFORE ${ITK_INCLUDE_DIR}
  ${PROJECT_SOURCE_DIR}/MeshIO
  ${GIFTI_INCLUDE_DIR}
)

ADD_SUBDIRECTORY( Utilities )
ADD_SUBDIRECTORY( MeshIO )
ADD_SUBDIRECTORY( Testing )
ADD_SUBDIRECTORY( Examples )

