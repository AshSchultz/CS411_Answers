#ifndef INVERSIONS
#define INVERSIONS

#include <iterator>
#include <cstdint>

template<typename RAIter>
size_t inversions(RAIter first, RAIter last){
    return 0;
}


// stableMerge
// Merge two halves of a sequence, each sorted, into a single sorted
// sequence in the same location. Merge is done in a stable manner.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges, each sorted
//      by <.
template <typename FDIter>
void stableMerge(FDIter first, FDIter middle, FDIter last)
{
    // Get type of what iterators point to
    using Value = typename iterator_traits<FDIter>::value_type;

    vector<Value> buffer(distance(first, last));
                               // Buffer for temporary copy of data
    auto in1 = first;          // Read location in 1st half
    auto in2 = middle;         // Read location in 2nd half
    auto out = begin(buffer);  // Write location in buffer

    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)  // Must do comparison this way, to be stable.
            *out++ = std::move(*in2++);
        else
            *out++ = std::move(*in1++);
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
}


// mergeSort
// Sort a range using Merge Sort.
// Recursive.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
template <typename FDIter>
void mergeSort(FDIter first, FDIter last)
{
    // Compute size of range
    auto size = distance(first, last);

    // BASE CASE

    if (size <= 1)
        return;

    // RECURSIVE CASE

    // Create iterator to middle of range
    auto middle = next(first, size/2);

    // Recursively sort the two lists
    mergeSort(first, middle);
    mergeSort(middle, last);

    // And merge them
    stableMerge(first, middle, last);
}

#endif // #ifndef INVERSIONS