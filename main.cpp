//
//  main.cpp
//  lab3
//
//  Created by Andrew on 10/27/17.
//  Copyright © 2017 Andrew Golovenko. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include "Util.hpp"
#include "Huffman.hpp"

void huffman(const std::string& filename) {
    FileReader r(filename);
    HuffmanCodes(r.getFrequency());
}

int main() {
    std::string filenames[] = {"file1.txt", "file2.txt", "file3.txt"};
    
    // Single-thread
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 3; i++) {
        std::cout << "------ File #" << (i + 1) << " ------" << std::endl;
        huffman(filenames[i]);
    }
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
    long long time = duration.count();
    std::cout << "Single-thread: " << time << "ms" << std::endl;
    
    // Multithread
    start = std::chrono::steady_clock::now();
    
    for (int i = 0; i < 3; i++) {
        std::cout << "------ File #" << (i + 1) << " ------" << std::endl;
        std::thread thread(huffman, filenames[i]);
        thread.join();
    }
    
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
    time = duration.count();
    std::cout << "Multithread: " << time << "ms" << std::endl;
    
    
}
