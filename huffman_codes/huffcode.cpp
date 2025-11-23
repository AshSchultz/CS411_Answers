// huffcode.cpp  SKELETON
// Glenn G. Chappell
// 2025-11-10
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

void HuffCode::setWeights(const unordered_map<char, int> &theweights) {
  std::priority_queue<huffNode *, vector<huffNode *>, Compare> pq;
  for (auto weight : theweights) {
    huffNode *node = new huffNode;
    node->weight = weight.second;
    node->character = weight.first;
    pq.push(node);
  }

  while (pq.size() >= 2) {
    huffNode *l = pq.top();
    pq.pop();
    huffNode *r = pq.top();
    pq.pop();
    huffNode *newNode = new huffNode;
    newNode->character = '$';
    newNode->left = l;
    newNode->right = r;
    newNode->weight = l->weight + r->weight;
    pq.push(newNode);
  }

  src = pq.top();
}

// void printTree(const huffNode *curr){
//     if (curr == nullptr)
//     {
//         return;
//     }
//     std::cout << curr->weight;
//     if(curr->character) {
//         std::cout << " " << curr->character;
//     }
//     std::cout << std::endl;

//     printTree(curr->left);
//     printTree(curr->right);
// }

string HuffCode::encodeChar(const char a, huffNode *tree, string str, bool &found) const {
  if (tree == nullptr) {
    found = false;
    return "";
  }

  if (tree->character != '$') {
    if (tree->character == a) {
      found = true;
      return str;
    }
  }
  string huffstring = encodeChar(a, tree->left, str + '0', found);
  if (found) {
    return huffstring;
  } else {
    huffstring = encodeChar(a, tree->right, str + '1', found);
    if (found) {
      return huffstring;
    }
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
    encodedText.append(encodeChar(text[i], src, encodedText, found));
  }
  std::cout << encodedText << "\n";
  return encodedText; // DUMMY
}

string HuffCode::decode(const string &codestr) const {
  // TODO: WRITE THIS!!!
  return ""; // DUMMY
}

void HuffCode::deallocateTree(huffNode *node) {
  // do nothing if passed a non-existent node
  if (node == nullptr) {
    return;
  }
  // now onto each branch of the binary tree
  deallocateTree(node->left);
  deallocateTree(node->right);
  delete[] node;
}

HuffCode::~HuffCode() { deallocateTree(src); }
