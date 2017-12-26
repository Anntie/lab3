//
//  Util.hpp
//  lab3
//
//  Created by Andrew on 10/27/17.
//  Copyright © 2017 Andrew Golovenko. All rights reserved.
//

#ifndef Util_hpp
#define Util_hpp

#include <iostream>
#include <fstream>
#include <map>

class FileReader {
public:
    FileReader(std::string filename);
    std::map<char, int> getFrequency();
    
private:
    int ASCII_frequency[128];
    void readFile(std::string filename);
    
    void initArray();
};

#endif /* Util_hpp */
