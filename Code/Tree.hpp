//
//  Tree.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/16.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "DisplayableObject.h"

// Fractal trees
//I used stochastic fractals to generate structures looking just like tree branches.
class Tree :
public DisplayableObject {
public:
    float treePos[3];
    //Tree(float x, float y, float z);
    Tree();
    ~Tree(){};
    void Display();
};

#endif /* Tree_hpp */
