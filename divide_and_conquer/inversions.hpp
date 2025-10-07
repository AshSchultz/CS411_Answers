/**
 * inversions.hpp
 * by Ashley Schultz
 * 
 * Solution for assignment 3 (divide and conquer)
 * 
 * mergeSort and stableMerge authored by Glen G. Chappell from
 * this link https://github.com/ggchappell/cs411-2025-03/blob/main/merge_sort.cpp
 * These functions were modified in the course of this assignment, modifications are
 * marked by the author.
 * LAST MODIFIED: 2025-10-7
 */

#ifndef INVERSIONS
#define INVERSIONS

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::to_string;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <utility>
using std::move;
#include <iterator>
using std::begin;
using std::end;
using std::distance;
using std::next;
using std::iterator_traits;
#include <algorithm>
using std::move;
using std::swap;
#include <chrono>
// Everything from <chrono> is preceded by std::
#include <cassert>
// For assert
using std::abs;

// stableMerge
// Merge two halves of a sequence, each sorted, into a single sorted
// sequence in the same location. Merge is done in a stable manner.
// MODIFICATION: returns the total number of inversions done by merging
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges, each sorted
//      by <.
//     MODIFICATION:
//     middle points to a value further in the list then first
template <typename FDIter>
size_t stableMerge(FDIter first, FDIter middle, FDIter last)
{
    // Get type of what iterators point to
    using Value = typename iterator_traits<FDIter>::value_type;

    // MODIFICATION: add a static cast to size_t to silence compiler warning -Wsign-conversion
    vector<Value> buffer(static_cast<size_t>(distance(first, last)));
                               // Buffer for temporary copy of data
    auto in1 = first;          // Read location in 1st half
    auto in2 = middle;         // Read location in 2nd half
    auto out = begin(buffer);  // Write location in buffer

    // Merge two sorted lists into a single list in buff.
    // MODIFICATION: initialize variable to hold total inversions, to return later
    size_t inversions = 0;
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)  // Must do comparison this way, to be stable.
        {
            // MODIFICATION: sum the number of inversions from each merge
            inversions += static_cast<size_t>(distance(first, in2)-distance(begin(buffer), out));
            *out++ = std::move(*in2++);
        }
        else
        {
            *out++ = std::move(*in1++);
        }
    }

    // Move remainder of original sequence to buffer.
    // Only one of the following two calls will do anything, since the
    //  other is given an empty source range.
    // NOTE. This is the 3-parameter version of std::move (the "move"
    //  version of std::copy, declared in <algorithm>), not the
    //  1-parameter version (casts to an Rvalue, declared in <utility>).
    move(in1, middle, out);
    move(in2, last, out);

    // Move buffer contents back to original sequence location.
    move(begin(buffer), end(buffer), first);
    // MODIFICATION: return total number of inversions
    return inversions;
}


// mergeSort
// Sort a range using Merge Sort MODIFICATION: Returns the number 
// of inversions from merging
// Recursive.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
template <typename FDIter>
size_t mergeSort(FDIter first, FDIter last)
{
    // Compute size of range
    auto size = distance(first, last);

    // BASE CASE

    if (size <= 1)
        return 0;

    // RECURSIVE CASE

    // Create iterator to middle of range
    auto middle = next(first, size/2);

    // MODIFICATION: sum up total inversions from each recursive call
    // and the final merge, store it in totalInversions
    size_t totalInversions = 0;
    // Recursively sort the two lists
    totalInversions += mergeSort(first, middle);
    totalInversions += mergeSort(middle, last);
    // And merge them
    totalInversions += stableMerge(first, middle, last);
    // MODIFICATION: Return totalInversions
    return totalInversions;
}

// inversions
// wrapper function that calls mergesort, which returns
// the number of inversions done by sorting the sequence
// Pre:
//     [first, last) is a valid range.
template<typename RAIter>
size_t inversions(RAIter first, RAIter last){
    return mergeSort(first, last);
}
#endif // #ifndef INVERSIONS