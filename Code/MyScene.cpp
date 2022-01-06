#include "MyScene.h"

#include "Triangle.h"
#include "Floor.h"
#include "House.hpp"
#include "TexturedSphere.hpp"
#include "TextBelltower.hpp"
#include "ground.hpp"
#include "Tree.hpp"
#include "Bunny.hpp"

#include <iostream>
#include <filesystem>
namespace fs = std::__fs::filesystem;

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight){}

void MyScene::Initialise()
{
    ;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // set the background colour of the scene to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DITHER);
    glShadeModel(GL_SMOOTH);
    
    TextBelltower *bt  =new TextBelltower();
    TexturedSphere *ts = new TexturedSphere("./others/glass3.bmp");
    ts->size(30);
    ts->SetResolution(10);


    AddObjectToScene(bt);
    AddObjectToScene(ts);
    AddObjectToScene(new Tree());
    AddObjectToScene(new House());
    
    

    
}

/// set the perspective of camera
void MyScene::Projection()
{
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    gluPerspective(60.0, (GLdouble)windowWidth/(GLdouble)windowHeight, 1.0, 1000.0);
    //glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//    GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
//    gluPerspective(100.0, aspect, 1.0, 1000.0);
    gluLookAt(-10, 10, 50, 0, 0, 0, 0, 1, 0);
}
