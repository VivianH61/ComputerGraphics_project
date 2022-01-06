//
//  Helperfunctions.cpp
//  G53GRA.Framework
//
//  Created by VV on 2020/11/29.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Helperfunctions.hpp"

void Helper::DrawCuboid(double x, double y, double z) {
    glPushMatrix();
    glScaled(x,y,z);
    glutSolidCube(1);
    glScaled(1,1,1);
    glPopMatrix();
}

void Helper::DrawTextTetrahedron(double x, double y, double z, const std::string& filename) {
    int texID = Scene::GetTexture(filename);
    glBindTexture(GL_TEXTURE_2D, texID);
    // 左
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
    glTexCoord2f(1, 0.0); glVertex3f(0,0,z);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, z/2);
    glEnd();
    
    //后
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
    glTexCoord2f(1, 0.0); glVertex3f(x,0,0);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, z/2);
    glEnd();
    
    //前
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0); glVertex3f(0,0,z);
    glTexCoord2f(1, 0.0); glVertex3f(x,0,z);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, z/2);
    glEnd();
    
    //右
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0); glVertex3f(x,0,z);
    glTexCoord2f(1, 0.0); glVertex3f(x,0,0);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, z/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(x, 0, z);
    glTexCoord2f(1, 1); glVertex3f(0, 0, z);
    glTexCoord2f(0, 1); glVertex3f(x, 0, 0);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, NULL);
}

void Helper::DrawTextLengtai(double x1, double x2, double h, const std::string& filename) {
    int texID = Scene::GetTexture(filename);
    glBindTexture(GL_TEXTURE_2D, texID);
    
    glPushMatrix();
    //下底
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(0, 0, x2);
    glTexCoord2f(1, 1); glVertex3f(x2, 0, x2);
    glTexCoord2f(0, 1); glVertex3f(x2, 0, 0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    //上底****
    glBegin(GL_QUADS);
    int tmp = (x2-x1)*1.0/2;
    glTexCoord2f(0.0, 0.0); glVertex3f(x2-tmp, h, tmp);
    glTexCoord2f(1, 0.0); glVertex3f(tmp, h, tmp);
    glTexCoord2f(1, 1); glVertex3f(tmp, h, tmp+x1);
    glTexCoord2f(0, 1); glVertex3f(tmp+x1, h, tmp+x1);
    glEnd();
    glPopMatrix();
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, x2);
    glTexCoord2f(1, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(tmp, h, tmp);
    glTexCoord2f(0, 1); glVertex3f(tmp, h, tmp+x1);
    glEnd();
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, x2);
    glTexCoord2f(1, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(tmp, h, tmp);
    glTexCoord2f(0, 1); glVertex3f(tmp, h, tmp+x1);
    glEnd();
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(x2, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(tmp, h, tmp+x1);
    glTexCoord2f(0, 1); glVertex3f(tmp+x1, h, tmp+x1);
    glEnd();
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(x2, 0, x2);
    glTexCoord2f(1, 0.0); glVertex3f(x2, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(x2-tmp, h, tmp);
    glTexCoord2f(0, 1); glVertex3f(tmp+x1, h, tmp+x1);
    glEnd();
//    
    
    glBindTexture(GL_TEXTURE_2D, NULL);
}

void Helper::DrawTextCuboid(double x, double y, double z, const std::string& filename) {
    int texID = Scene::GetTexture(filename);
    glBindTexture(GL_TEXTURE_2D, texID);
    glPushMatrix();
    //底
    glBegin(GL_QUADS);
    //glColor3f(1, 1, 1);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(0, 0, z);
    glTexCoord2f(1, 1); glVertex3f(x, 0, z);
    glTexCoord2f(0, 1); glVertex3f(x, 0, 0);
    //glColor3f(1,1,1);
    glEnd();

    //顶
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, y, 0);
    glTexCoord2f(1, 0.0); glVertex3f(0, y, z);
    glTexCoord2f(1, 1); glVertex3f(x, y, z);
    glTexCoord2f(0, 1); glVertex3f(x, y, 0);
    //glColor3f(1,1,1);
    glEnd();

    //left
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1); glVertex3f(0, y, 0);
    glTexCoord2f(0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0); glVertex3f(0, 0, z);
    glTexCoord2f(1, 1); glVertex3f(0, y, z);
    glEnd();


    //right
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1); glVertex3f(x, y, 0);
    glTexCoord2f(0.0, 0.0); glVertex3f(x, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(x, 0, z);
    glTexCoord2f(1, 1); glVertex3f(x, y, z);
    //glColor3f(1,1,1);
    glEnd();

    //前
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1); glVertex3f(0, y, z);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, z);
    glTexCoord2f(1, 0.0); glVertex3f(x, 0, z);
    glTexCoord2f(1, 1); glVertex3f(x, y, z);
    //glColor3f(1,1,1);
    glEnd();

    //后
    //glColor4f(1.0, 1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1); glVertex3f(0, y, 0);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(x, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(x, y, 0);
    glEnd();
    
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, NULL);
}

void Helper::DrawCylinder(GLfloat radius, GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();


    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
    
}


void Helper::DrawRoof(double x, double y, double z, const std::string& filename) {
    int texID = Scene::GetTexture(filename);
    glBindTexture(GL_TEXTURE_2D, texID);
    glPushMatrix();
    //base
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(0, 0, z);
    glTexCoord2f(1, 1); glVertex3f(x, 0, z);
    glTexCoord2f(0, 1); glVertex3f(x, 0, 0);
    glEnd();
    
    // Front
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(x, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, 0);
    glEnd();

    //Behind
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, z);
    glTexCoord2f(1, 0.0); glVertex3f(x, 0, z);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, z);
    glEnd();
    
    //left
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(0, 0, z);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, z);
    glTexCoord2f(0, 1); glVertex3f(x/2, y, 0);
    glEnd();
    
    //right
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(x, 0, 0);
    glTexCoord2f(1, 0.0); glVertex3f(x, 0, z);
    glTexCoord2f(1, 1); glVertex3f(x/2, y, z);
    glTexCoord2f(0, 1); glVertex3f(x/2, y, 0);
    glEnd();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, NULL);
}
 
