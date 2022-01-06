//
//  House.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/11/28.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef House_hpp
#define House_hpp




#include <stdio.h>
#include "DisplayableObject.h"
#include "Helperfunctions.hpp"

class House :
    public DisplayableObject
{
public:
    House(){};
    ~House(){};
    void DrawDorm(double x, double y, double z, double scale);
    void Display();
};

#endif /* House_hpp */
