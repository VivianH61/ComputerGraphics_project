//
//  ground.cpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/12.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "ground.hpp"
#include "Helperfunctions.hpp"


// The ground object consists of the grassland, the road, and some floor tiles on the road
void Ground::Display() {
    glPushMatrix();
    glTranslatef(0, -200, -0);
    Helper *help = new Helper();
    glColor3f(78.0/255, 112.0/255, 16.0/255);
    help->DrawCuboid(200, 0.1, 200);
    glPopMatrix();
}
