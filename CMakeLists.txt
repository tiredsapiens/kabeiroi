cmake_minimum_required(VERSION 3.10)

# Set the root project name
set(CMAKE_C_COMPILER "/usr/bin/clang")
project(Kabeiroi)
# Add engine subdirectory
add_subdirectory(engine)

# Add testbed subdirectory
add_subdirectory(testbed)
include_directories(${CMAKE_SOURCE_DIR}/engine/core)

#target_include_directories(testbed PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/engine/core  # Make core available for other targets
#        ${CMAKE_CURRENT_SOURCE_DIR}/engine/src
#)
#get_target_property(INCLUDE_DIRS testbed INCLUDE_DIRECTORIES)
#message(STATUS "Testbed include directories: ${INCLUDE_DIRS}")