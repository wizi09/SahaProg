#  CMakeLists.txt
#
#  Created on: 2016-02-23
#      Author: Abdallah	
#       Email: abdou9989@gmail.com	


cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# 
# Project meta informations
# 
# Meta information about the project
set(META_PROJECT_NAME        "SehaProg")
set(META_PROJECT_DESCRIPTION "Ecosystem de e-hospital")
set(META_AUTHOR_ORGANIZATION "Seha-Tech Pro")
set(META_AUTHOR_DOMAIN       "https://github.com/wizi09/sehatech/")
set(META_AUTHOR_MAINTAINER   "abdou9989@gmail.com")
set(META_VERSION_MAJOR       "0")
set(META_VERSION_MINOR       "0")
set(META_VERSION_PATCH       "1")
set(META_VERSION             "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")
set(META_NAME_VERSION        "${META_PROJECT_NAME} v${META_VERSION} (${META_VERSION_REVISION})")

# Project options
option(BUILD_SHARED_LIBS     "Build shared instead of static libraries."              OFF)
option(OPTION_SELF_CONTAINED "Create a self-contained install with all dependencies." OFF)
option(OPTION_BUILD_TESTS    "Build tests."                                           OFF)
option(OPTION_BUILD_DOCS     "Build documentation."                                   OFF)
option(OPTION_BUILD_EXAMPLES "Build examples."                                        ON)
option(OPTION_BUILD_DATABASE "Build database."                                        OFF)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  SehaProgConfig.h.in SehaProgConfig.h  )
  
 # file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/SehaProgConfig.h
  #      DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/SehaProgConfig.h)
# 
# Declare project
# 


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Declare project
project(${META_PROJECT_NAME} C CXX)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

include_directories("${PROJECT_BINARY_DIR}")
# Create version file
file(WRITE "${PROJECT_BINARY_DIR}/VERSION" "${META_NAME_VERSION}")


# 
# Compiler settings and options
# 

include(cmake/CompileOptions.cmake)


# 
# Project modules
# 

add_subdirectory(source)
#add_subdirectory(docs)
#add_subdirectory(deploy)