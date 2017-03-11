#  CMakeLists.txt
#
#  Created on: 2016-02-23
#      Author: Abdallah	
#       Email: abdou9989@gmail.com	


cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(SahaProg)

#------------------------------------------------------------------------------------------------
#--------------------------------------- Options de compilation -------------------------------------------
#------------------------------------------------------------------------------------------------

set(SAHAPROG_BUILD_LAB_VERSION 0 CACHE STRING "Compile ou non les sources liees a l'edition Lab." FORCE)

set(SAHAPROG_BUILD_STABLE_VERSION 0 CACHE STRING "Compile ou non les sources liees a version stable." FORCE)

set(SAHAPROG_BUILD_SERVER_VERSION 0 CACHE STRING "Compile ou non les sources liees a la version serveur du SAHAPROG." FORCE)

set(SAHAPROG_BUILD_CLIENT_VERSION 0 CACHE STRING "Compile ou non les sources liees au client SAHAPROG." FORCE)

set(SAHAPROG_BUILD_TEST_VERSION 1 CACHE STRING "Compile ou non les sources liees aux tests." FORCE)

set(SAHAPROG_BUILD_ALL 0 CACHE STRING "Compile ou non les sources liees a SAHAPROG Lab, SAHAPROG, SAHAPROG Server." FORCE)


#------------------ BOOST 1.5.4 --------------------------------------
find_package(Boost REQUIRED COMPONENTS thread system regex)
include_directories(${Boost_INCLUDE_DIR})

#------------------ Qt 4.8 lib ----------------------------------------------------------
FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui QtSql REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)


include("SrcCmakeList.cmake")
