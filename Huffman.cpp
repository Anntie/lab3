//
//  Huffman.cpp
//  lab3
//
//  Created by Andrew on 10/27/17.
//  Copyright © 2017 Andrew Golovenko. All rights reserved.
//

#include "Huffman.hpp"

MinHeapNode::MinHeapNode(char data, unsigned int frequency) : data(data), frequency(frequency) {
    left = right = nullptr;
}

bool compare::operator()(MinHeapNode *l, MinHeapNode *r) {
    return (l->frequency > r->frequency);
}

void printCodes(struct MinHeapNode* root, std::string str) {
    if (!root)
        return;
    
    if (root->data != '$')
        std::cout << root->data << ": " << str << "\n";
    
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(std::map<char, int> data)
{
    MinHeapNode *left, *right, *top;
    
    // Create a min heap & inserts all characters of data[]
    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;
    
    for (auto item : data) {
        minHeap.push(new MinHeapNode(item.first, item.second));
    }
    
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();
        
        right = minHeap.top();
        minHeap.pop();
        
        // Create a new internal node with frequency equal to the sum of the two nodes frequencies
        top = new MinHeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    
    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}
