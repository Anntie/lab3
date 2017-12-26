//
//  Util.cpp
//  lab3
//
//  Created by Andrew on 10/27/17.
//  Copyright © 2017 Andrew Golovenko. All rights reserved.
//

#include "Util.hpp"

FileReader::FileReader(std::string filename) {
    initArray();
    readFile(filename);
}

void FileReader::initArray() {
    for (int i = 0; i < 128; i++) {
        ASCII_frequency[i] = 0;
    }
}

void FileReader::readFile(std::string filename) {
    std::ifstream file;
    file.open(filename, std::ios::in);
    char c;
    while (!file.eof()) {
        file.get(c);
        ASCII_frequency[c]++;
    }
    file.close();
}

std::map<char, int> FileReader::getFrequency() {
    std::map<char, int> frequency;
    for (int i = 0; i < 128; i++) {
        if (ASCII_frequency[i] > 0) {
            frequency.insert(std::make_pair(static_cast<char>(i), ASCII_frequency[i]));
        }
    }
    return frequency;
}
