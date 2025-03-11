cmake_minimum_required(VERSION 3.10)
project(engine)

#Set flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -shared  -fPIC")

#Include directories
include_directories(src ${VULKAN_SDK} / include)
## Define the engine target
#add_library(engine STATIC
#        core/logger.h
#        src/main.c
#)
# Include directories for the engine itself
#target_include_directories(testbed PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/core  # Make core available for other targets
#        ${CMAKE_CURRENT_SOURCE_DIR}/src
#)
#Source files
file(GLOB_RECURSE SOURCES "*.c")

#Create shared library
add_library(engine SHARED ${SOURCES})

#Link libraries
target_link_libraries(engine vulkan xcb X11
        #X11 - xcb
        xkbcommon)
link_directories(/usr/lib/x86_64-linux-gnu/libX11-xcb)

#Set library search paths
link_directories(${VULKAN_SDK} / lib / usr / X11R6 / lib)

#Set define flags
target_compile_definitions(engine PRIVATE _DEBUG DKEXPORT)
