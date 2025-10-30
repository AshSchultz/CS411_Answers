cmake_minimum_required(VERSION 3.10.0)
project(CS411_Answers VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Project source directory
# Glob all source from src to feed into add_executable
file(GLOB cs411_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/bridges_test.cpp")
# Glob all cs411-2025-03
file(GLOB cs411_ans_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/exhaustive_search/*.cpp")

file(GLOB cs411_ans_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming/*.cpp")

# Create your executable target as usual
add_executable(CS411_Answers WIN32 ${cs411_ans_SRC} ${cs411_SRC})

target_include_directories(CS411_Answers PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/divide_and_conquer"
"${CMAKE_CURRENT_SOURCE_DIR}/doctest/doctest" "${CMAKE_CURRENT_SOURCE_DIR}/exhaustive_search"
"${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming")
