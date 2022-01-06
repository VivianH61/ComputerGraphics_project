//
//  TextBelltower.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/4.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef TextBelltower_hpp
#define TextBelltower_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Helperfunctions.hpp"

class TextBelltower :
public DisplayableObject {
public:
    TextBelltower(){this->help = new Helper();};
    ~TextBelltower(){};
    void SetTexture(const std::string& filename);
    void DrawRoof(double x, double y, double z);
    void Display();
protected:
    // ID to bound texture
    int _texID;
    Helper *help;
    
};

#endif /* TextBelltower_hpp */
