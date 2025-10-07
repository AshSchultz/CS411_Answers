/**
 * contigsum.hpp
 * by Ashley Schultz
 * 
 * Solution for homework 3
 * Source for function contigsum
 */
#ifndef CONTIGSUM
#define CONTIGSUM

#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;
using std::max;
using std::cout;


// Recursive function that returns the Greatest Contiguous Sum (GCS) of a sequence of integers.
// Takes iterators to the first and last elements of a sequence of integers
template<typename RAIter>
int contigSum(RAIter first, RAIter last) {
    long int size = last - first;
    // BASE CASE
    if (size <= 1)
    {
        // Return zero if the first element doesn't exist or is less then zero
        return size > 0 ? (*first > 0 ? *first : 0) : 0;
    }

    // RECURSIVE CASE
    RAIter midpoint = first + (size/2);
    int firstPartGCS = contigSum(first, midpoint);
    int secondPartGCS = contigSum(midpoint, last);

    //Find GCS with first value in the second part of the input
    int firstSum = 0;
    int GCSFirstSum = 0;
    for (RAIter curr = midpoint+1; curr < last; curr++)
    {
        firstSum += *curr;
        if (firstSum > GCSFirstSum)
        {
            GCSFirstSum = firstSum;
        }
        
    }

    // Find GCS with last value in the first part of the input
    int lastSum = 0;
    int GCSLastSum = 0;
    for (RAIter curr = first + (size/2); curr >= first; curr--)
    {
        lastSum += *curr;
        if (lastSum > GCSLastSum)
        {
            GCSLastSum = lastSum;
        }
        
    }
    
    // Return the max of the first and second parts GCS,
    // and the GCS of the first part with the last element and the
    // second parts GCS with the first element
    return max<int>({firstPartGCS, secondPartGCS, GCSLastSum + GCSFirstSum});
    
}

#endif // #ifndef CONTIGSUM