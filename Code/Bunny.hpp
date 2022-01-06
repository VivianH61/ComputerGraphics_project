//
//  Bunny.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/16.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Bunny_hpp
#define Bunny_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"
#include <math.h>

class Bunny :
public DisplayableObject {
public:
    Bunny(){};
    ~Bunny(){};
    void Display();
};

#endif /* Bunny_hpp */
