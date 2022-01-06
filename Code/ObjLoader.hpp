//
//  ObjLoader.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/16.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

// This class helps to load the ".obj" file to the scene

#ifndef ObjLoader_hpp
#define ObjLoader_hpp

#include <stdio.h>
#include <string>
#include <iostream>     // std::cout
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class ObjLoader{
public:
    ObjLoader(string filename);// constructor
    void Draw();//draw the object to the screen
private:
    vector<vector<float>> vSets;//store the coordinate of points (x,y,z)
    vector<vector<int>> fSets;//store the flags of the points
};

#endif /* ObjLoader_hpp */
