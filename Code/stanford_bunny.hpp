//
//  stanford_bunny.hpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/17.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef stanford_bunny_hpp
#define stanford_bunny_hpp

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef MACOS
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
///#include "GL/gl.h"
#include "GL/glew.h"
#include "OpenGL/OpenGL.h"
#include "GL/glut.h"

#include <stdio.h>
#endif


void DrawBunny();


#endif    //_STANFORD_BUNNY_H_

