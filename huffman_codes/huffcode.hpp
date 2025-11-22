// huffcode.hpp  SKELETON
// Glenn G. Chappell
// 2025-11-10
//
// For CS 411 Fall 2025
// Assignment 6, Exercise A
// Header for class HuffCode

#ifndef FILE_HUFFCODE_HPP_INCLUDED
#define FILE_HUFFCODE_HPP_INCLUDED

#include <string>
// For std::string
#include <unordered_map>
// For std::unordered_map;
#include <queue>
// For std::priority_queue

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:

    void setWeights(const std::unordered_map<char, int> & theweights);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

// ***** HuffCode: data members *****
private:
    struct huffNode
    {
        int weight;
        char character;
        huffNode *left;
        huffNode *right;
    };
    huffNode *src;

};  // End class HuffCode


#endif //#ifndef FILE_HUFFCODE_HPP_INCLUDED

