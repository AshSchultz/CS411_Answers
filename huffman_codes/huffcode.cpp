// huffcode.cpp
//
// Ashley Schultz
// Glenn G. Chappell wrote the skeleton
// 2025-11-25
//
// For CS 411 Fall 2025
// Assignment 6, Exercise A
// Source for class HuffCode

#include "huffcode.hpp" // for class HuffCode declaration
#include <string>
using std::string;
#include <unordered_map>
using std::pair;
using std::unordered_map;
using std::vector;
#include <iostream>
#include <memory>
using std::make_shared;
using std::shared_ptr;

void HuffCode::setWeights(const unordered_map<char, int> &theweights) {
  std::priority_queue<shared_ptr<huffNode>, vector<shared_ptr<huffNode>>,
                      Compare>
      pq;

  // Create leaf nodes
  for (auto weight : theweights) {
    auto node = make_shared<huffNode>();
    node->weight = weight.second;
    node->character = weight.first;
    pq.push(node);
  }

  // Create full tree
  while (pq.size() > 1) {
    auto l = pq.top();
    pq.pop();
    auto r = pq.top();
    pq.pop();
    auto newNode = make_shared<huffNode>();
    // Set each non leaf node to null character
    newNode->character = '\0';
    newNode->left = l;
    newNode->right = r;
    newNode->weight = l->weight + r->weight;
    pq.push(newNode);
  }

  src = pq.top();
}

// Internal workhorse function that recursively encodes a character using the huffman tree created in setWeights()
string HuffCode::encodeChar(const char &a, shared_ptr<huffNode> tree,
                            string str, bool &found) const {
  string huffstring;

  if (huffMap[a] != "") {
    return huffMap[a];
  }

  if (tree == nullptr) {
    return "";
  }

  if (tree->character == a) {
    found = true;
    return str;
  }

  // Encode left subtree
  huffstring.append(encodeChar(a, tree->left, str + '0', found));

  if (found) {
    huffMap[a] = huffstring;
    return huffstring;
  }

  // Encode right subtree
  huffstring.append(encodeChar(a, tree->right, str + '1', found));

  if (found) {
    huffMap[a] = huffstring;
    return huffstring;
  }

  return "";
}

string HuffCode::encode(const string &text) const {
  if (!src) {
    return "";
  }

  string encodedText;
  for (size_t i = 0; i < text.length(); i++) {
    bool found = false;
    string str("");
    encodedText.append(encodeChar(text[i], src, str, found));
  }

  return encodedText;
}

string HuffCode::decode(const string &codestr) const {

  string decodedText;

  auto temp = src;
  // Go through each binary '1' or '0' character, 
  // traverse the tree depending on the character until a character is found
  for (size_t i = 0; i < codestr.length(); i++) {
    if (codestr[i] == '0') {
      temp = temp->left;
    } else {
      temp = temp->right;
    }

    if (temp->character != '\0') {
      decodedText += temp->character;
      temp = src;
    }
  }

  return decodedText;
}
