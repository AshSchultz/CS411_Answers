// huffcode.cpp  SKELETON
// Glenn G. Chappell
// 2025-11-10
//
// For CS 411 Fall 2025
// Assignment 6, Exercise A
// Source for class HuffCode

#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
using std::pair;
using std::vector;
#include <iostream>

void HuffCode::setWeights(const unordered_map<char, int> & theweights)
{
    std::priority_queue<huffNode *, vector<huffNode *>> pq;
    for (auto weight : theweights)
    {
        huffNode * node = new huffNode;
        node->weight = weight.second;
        node->character = weight.first;
        pq.push(node);
    }
    
    while (pq.size() >= 2)
    {
        huffNode *l = pq.top();
        pq.pop();
        huffNode *r = pq.top();
        pq.pop();
        huffNode *newNode = new huffNode;
        newNode->left = l;
        newNode->right = r;
        newNode->weight = l->weight + r->weight;
        pq.push(newNode);
    }
    
    src = pq.top();
    
}

string HuffCode::encode(const string & text) const
{
    if (!src)
    {
        return "";
    }
    
    // TODO: WRITE THIS!!!
    return "";  // DUMMY
}


string HuffCode::decode(const string & codestr) const
{
    // TODO: WRITE THIS!!!
    return "";  // DUMMY
}

