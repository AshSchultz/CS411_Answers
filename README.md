# CS411_Answers
Code repository for CS411(Analysis of Algorithms) Class at the University of Alaska Fairbanks

## To Build

after cloning the project, run:

`git submodule update --init --recursive`

This will pull all git submodules for this project, which are required for building

### Using cmake

Requires cmake to be installed and using a unix like shell.

First specify the test program to compile with in CS411_Answers/CMakeLists.txt on this line:

`file(GLOB cs411_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/inversions_test.cpp")`

for example if you wanted to compile against the bridges test program:

`file(GLOB cs411_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/cs411-2025-03/bridges_test.cpp")`

once you have specified the test program, now in the terminal cd into the repository folder

`cd CS411_Answers`


