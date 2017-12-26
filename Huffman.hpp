//
//  Huffman.hpp
//  lab3
//
//  Created by Andrew on 10/27/17.
//  Copyright © 2017 Andrew Golovenko. All rights reserved.
//

#ifndef Huffman_hpp
#define Huffman_hpp

#include <iostream>
#include <vector>
#include <map>
#include <queue>

// A Huffman tree node
struct MinHeapNode
{
    char data;
    unsigned int frequency;
    MinHeapNode *left, *right;
    
    MinHeapNode(char data, unsigned int frequency);
};

struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r);
};

void printCodes(struct MinHeapNode* root, std::string str);

void HuffmanCodes(std::map<char, int> data);

#endif /* Huffman_hpp */
