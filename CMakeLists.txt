cmake_minimum_required(VERSION 3.10.0)
project(CS411_Answers VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Project source directory
# Glob all source from src to feed into add_executable
file(GLOB exh_tst CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/bridges_test.cpp")
file(GLOB exh_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/exhaustive_search/*.cpp")
file(GLOB exh_header_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/exhaustive_search/*.hpp")

file(GLOB dyn_tst CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/bridges_test2.cpp")
file(GLOB dyn_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming/*.cpp")
file(GLOB dyn_header_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming/*.hpp")

file(GLOB huffcode_src "${CMAKE_CURRENT_SOURCE_DIR}/huffman_codes/*.cpp")
file(GLOB huffcode_header_src "${CMAKE_CURRENT_SOURCE_DIR}/huffman_codes/*.hpp")
file(GLOB huffcode_tst "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/huffcode_test.cpp")

file(GLOB div_header_src "${CMAKE_CURRENT_SOURCE_DIR}/divide_and_conquer/*.hpp")
file(GLOB contigsum_tst CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/contigsum_test.cpp")
file(GLOB inv_tst CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/inversions_test.cpp")

# Create executables for each of the assignments
add_executable(contigsum WIN32 ${div_header_src} ${contigsum_tst})
add_executable(inversions WIN32 ${div_header_src} ${inv_tst})
add_executable(dynamic_programming WIN32 ${dyn_tst} ${dyn_header_src} ${dyn_src})
add_executable(exhaustive_search WIN32 ${exh_SRC} ${exh_tst} ${exh_header_tst})
add_executable(Huffcode WIN32 ${huffcode_src} ${huffcode_header_src} ${huffcode_tst})

# Manage include directories for each of the executables
target_include_directories(contigsum PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/doctest/doctest"
"${CMAKE_CURRENT_SOURCE_DIR}/divide_and_conquer")
target_include_directories(inversions PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/doctest/doctest"
"${CMAKE_CURRENT_SOURCE_DIR}/divide_and_conquer")
target_include_directories(Huffcode PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/huffman_codes")
target_include_directories(Huffcode PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/doctest/doctest")
target_include_directories(exhaustive_search PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/doctest/doctest"
"${CMAKE_CURRENT_SOURCE_DIR}/exhaustive_search")
target_include_directories(dynamic_programming PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/doctest/doctest")
target_include_directories(dynamic_programming PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming")
