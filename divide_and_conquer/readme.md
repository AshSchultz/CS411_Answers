# To build

In `CS411_Answers/` directory:

For contigsum:
`g++ -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -fdiagnostics-color=always -Wall -ggdb cs411-2025-03/contigsum_test.cpp -I divide_and_conquer/ -idirafter doctest/doctest/ -o build/contigsum`

for inversions:
`g++ -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -fdiagnostics-color=always -Wall -ggdb cs411-2025-03/inversions_test.cpp -I divide_and_conquer/ -idirafter doctest/doctest/ -o build/inversions`