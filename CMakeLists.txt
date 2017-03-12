#  CMakeLists.txt
#
#  Created on: 2016-02-23
#      Author: Abdallah	
#       Email: abdou9989@gmail.com	


cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(SehaProg)

#------------------------------------------------------------------------------------------------
#--------------------------------------- Options de compilation -------------------------------------------
#------------------------------------------------------------------------------------------------

set(SEHAPROG_BUILD_LAB_VERSION 0 CACHE STRING "Compile ou non les sources liees a l'edition Lab." FORCE)

set(SEHAPROG_BUILD_STABLE_VERSION 0 CACHE STRING "Compile ou non les sources liees a version stable." FORCE)

set(SEHAPROG_BUILD_SERVER_VERSION 0 CACHE STRING "Compile ou non les sources liees a la version serveur du SAHAPROG." FORCE)

set(SEHAPROG_BUILD_CLIENT_VERSION 0 CACHE STRING "Compile ou non les sources liees au client SAHAPROG." FORCE)

set(SEHAPROG_BUILD_TEST_VERSION 1 CACHE STRING "Compile ou non les sources liees aux tests." FORCE)

set(SEHAPROG_BUILD_ALL 0 CACHE STRING "Compile ou non les sources liees a SAHAPROG Lab, SAHAPROG, SAHAPROG Server." FORCE)



#------------------ BOOST 1.5.4 --------------------------------------
find_package(Boost REQUIRED COMPONENTS thread system regex)
include_directories(${Boost_INCLUDE_DIR})

#------------------ Qt 4.8 lib ----------------------------------------------------------
FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui QtSql REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

#------------------ Gnu Scientific Library----------------------------------------------------------
FIND_PACKAGE(GSL REQUIRED)    
if (GSL_FOUND)
  include_directories(${GSL_INCLUDE_DIRS})
  MESSAGE("GSL_INCLUDE_DIR Include Dir ---------->    : ${GSL_INCLUDE_DIRS}")
	MESSAGE("GSL_LIBRARIES Found       ---------->    : ${GSL_LIBRARIES}.")
  #INCLUDE(${FLTK_USE_FILE})
endif (GSL_FOUND)

#------------------dLIB
set(Dlib_DIR "C:/Program Files/Project/lib/cmake/dlib")
set(dlib_INCLUDE_DIRS "C:/Program Files/Project/include")
set(dlib_LIBRARIES "C:/Program Files/Project/lib/libdlib.a")
include_directories(${dlib_INCLUDE_DIRS})


include("SrcCmakeList.cmake")
