//
//  ground.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/12.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef ground_hpp
#define ground_hpp

#include <stdio.h>
#include "DisplayableObject.h"


class Ground :
public DisplayableObject {
public:
    Ground(){};
    ~Ground(){};
    void Display();
protected:
    // ID to bound texture
    int _texID;
};


#endif /* ground_hpp */
