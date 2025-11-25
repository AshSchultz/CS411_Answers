// huffcode.hpp
//
// Ashley Schultz
// Glenn G. Chappell wrote the skeleton
// 2025-11-25
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
#include <memory>
// For std::shared_ptr

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {
  // ***** HuffCode: ctors, dctor, op= *****
public:
  // Compiler-generated default ctor, copy ctor, copy =, dctor used

  // ***** HuffCode: general public functions *****
public:
  void setWeights(const std::unordered_map<char, int> &theweights);

  std::string encode(const std::string &text) const;

  std::string decode(const std::string &codestr) const;

  // ***** HuffCode: data members *****
private:

  // Node definition for the huffman tree
  struct huffNode {
    int weight;
    char character;
    std::shared_ptr<huffNode> left = nullptr;
    std::shared_ptr<huffNode> right = nullptr;
  };

  // Class for comparing two nodes in priority queue, used internally in set weights function
  class Compare {
  public:
    bool operator()(std::shared_ptr<huffNode> a, std::shared_ptr<huffNode> b) {
      return a->weight > b->weight;
    };
  };

  // Source for the huffman tree created in set weights function
  std::shared_ptr<huffNode> src;

  // Map of characters to codes for encoding strings to use dynamic coding principles
  mutable std::unordered_map<char, std::string> huffMap;

  // Internal workhorse function that recursively encodes a character using the huffman tree created in setWeights()
  std::string encodeChar(const char &a, std::shared_ptr<huffNode> tree,
                         std::string str, bool &found) const;

}; // End class HuffCode

#endif // #ifndef FILE_HUFFCODE_HPP_INCLUDED
