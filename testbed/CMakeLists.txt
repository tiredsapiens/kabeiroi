cmake_minimum_required(VERSION 3.10)
project(testbed)

# Set flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fPIC")

# Include directories

message(${CMAKE_SOURCE_DIR}/engine/core)

#include_directories(
#        src
#        ../engine/src
#        ../engine/core
#        engine/core
#        engine/src
#        ${CMAKE_SOURCE_DIR}/engine/core
#        ${CMAKE_SOURCE_DIR}/engine/src
#        ../bin
#)
file(GLOB_RECURSE SOURCES "*.c")
#add_executable(testbed ${SOURCES})

add_executable(testbed ${SOURCES})
include_directories(#testbed PUBLIC
        ../engine/src/core
        ${CMAKE_CURRENT_SOURCE_DIR}/../engine/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../engine/platform
        ${CMAKE_CURRENT_SOURCE_DIR}/../engine/core
)
#target_sources(testbed PRIVATE ../engine/src/core/logger.h ../engine/src/core/logger.c)

#message(${CMAKE_CURRENT_SOURCE_DIR}/../engine/core)
get_target_property(INCLUDE_DIRS testbed INCLUDE_DIRECTORIES)
message(STATUS "Testbed include directories: ${INCLUDE_DIRS}")
# Source files

# Create executable
# Link libraries
target_link_libraries(testbed
        engine
)

# Set define flags
target_compile_definitions(testbed PRIVATE
        _DEBUG
        DKIMPORT
)

# Set rpath for runtime linking
set_target_properties(testbed PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH_USE_LINK_PATH TRUE
        INSTALL_RPATH "$ORIGIN/../engine"
)
