#ifndef CONTIGSUM
#define CONTIGSUM

#include <iterator>
#include <vector>

using std::vector;

// Recursive work horse function
template<typename RAIter>
int contigSumRecurse(RAIter first, RAIter last, vector<RAIter> & chosen)
{

    // BASE CASE
    long int size = last - first;
    if (size == 0)
    {
        int sum = 0;
        for (auto & e:chosen)
        {
            sum += *e;
        }
        return sum;
    }
    chosen.push_back(first);
    return contigSumRecurse(first+1, last, chosen);
    
}

template<typename RAIter>
int contigSum(RAIter first, RAIter last) {

    vector<RAIter> chosen;
    return contigSumRecurse(first, last, chosen);
}

#endif // #ifndef CONTIGSUM