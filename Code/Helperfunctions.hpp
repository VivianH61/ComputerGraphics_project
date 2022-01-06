//
//  Helperfunctions.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/11/29.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Helperfunctions_hpp
#define Helperfunctions_hpp

#include "DisplayableObject.h"
#include <cmath>
#define PI 3.1415927

// This class inccluded encapsulations of some functions, which are used to draw objects
class Helper :
public DisplayableObject{
public:
    //画长方体
    Helper(){};
    ~Helper(){};
    void Display(){};
    void DrawCuboid(double x, double y, double z);
    void DrawTextTetrahedron(double x, double y, double z, const std::string& filename="");
    void DrawTextCuboid(double x, double y, double z, const std::string& filename="");
    void DrawTextLengtai(double x1, double x2, double h, const std::string& filename="");
    void DrawCylinder(GLfloat radius, GLfloat height);
    void DrawRoof(double x, double y, double z, const std::string& filename="");
    
};



#endif /* Helperfunctions_hpp */
