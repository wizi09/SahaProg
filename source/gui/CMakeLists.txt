
# 
# External dependencies
# 

# find_package(THIRDPARTY REQUIRED)


# 
# Executable name and options
# 

# Target name
set(target gui)

#------------------ Qt 4.8 lib ----------------------------------------------------------
FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui QtSql REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)


# Exit here if required dependencies are not met
message(STATUS "Example ${target}")


# 
# Sources
# 

set(sources
    main.cpp
)


# 
# Create executable
# 



# Build executable
add_executable(${target}
    MACOSX_BUNDLE
    ${sources}
)

# Create namespaced alias
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})


# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
    FOLDER "${IDE_FOLDER}"
)


# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
    ${DEFAULT_INCLUDE_DIRECTORIES}
  
)


# 
# Libraries
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LIBRARIES}
    ${QT_LIBRARIES}
)


# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE
    ${DEFAULT_COMPILE_DEFINITIONS}
)


# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS}
)


