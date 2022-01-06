//
//  House.cpp
//  G53GRA.Framework
//
//  Created by VV on 2020/11/28.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "House.hpp"

#include<iostream>
using std::cout;
#define _USE_MATH_DEFINES // for C++
#include <math.h>
GLfloat w = 700;
GLfloat h = 700;
double rotate_x = 0.0;
double rotate_y = 0.0;
# define  white  1.0 ,  1.0  ,  1.0   // 对颜色的宏定义
# define  green  0.0 ,  0.502,  0.0
# define  red    1.0 ,  0.0  ,  0.0
# define  gray   0.502, 0.502,0.502
# define  hgray  0.117, 0.180,0.227
# define  blue   0.0  , 0.0  ,  1.0
# define  pi  3.14159265
# define  gold   1.0,215.0/255.0,0.0
# define  hgreen 0.0,100.0/255.0,0.0
# define  brown  210.0/255.0, 105.0/255.0,  30.0/255.0
# define  men   244.0/255.0 ,164.0/255.0 , 96.0/255.0
# define  menba   139.0/255.0 ,69.0/255.0,19.0/255.0
double fang[8][3];             // define 8 points of a cubiod
                               // define constract function, givn the coordinate of the cubiod
                                //calculate the coordinates of all points of the rectangle automatically
                               // and put the coordinate of 8 points in the variable "fang"

double san[8][3];              // 定义地面为梯形的长方体

void cons(double x,double y,double z,double x1,double y1,double z1){
    san[0][0] = x;
    san[0][1] = y;
    san[0][2] = z;     //  the 1th point
 
    san[1][0] = x;
    san[1][1] = y;
    san[1][2] = z+z1;   //  the 2th point
 
    san[4][0] = x;
    san[4][1] = y+y1;
    san[4][2] = z;     //  the 4th point
 
    san[5][0] = x;
    san[5][1] = y+y1;
    san[5][2] = z+z1/2;      //  the 5th point
    for(int i=0;i<3;i++){
        if(i==0){
        san[3][i]=san[0][i]+x1;
        san[2][i]=san[1][i]+x1;
        san[6][i]=san[4][i]+x1;
        san[7][i]=san[5][i]+x1;
        }else{
            san[3][i]=san[0][i];
            san[2][i]=san[1][i];
            san[6][i]=san[4][i];
            san[7][i]=san[5][i];
        }
    }
}
void constract(double x,double y,double z,double x1,double y1,double z1){
    fang[0][0] = x;
    fang[0][1] = y;
    fang[0][2] = z;        //  the 0th point
 
    fang[1][0] = x;
    fang[1][1] = y;
    fang[1][2] = z+z1;     //  the 1th point
 
    fang[2][0] = x+x1;
    fang[2][1] = y;
    fang[2][2] = z+z1;     //  the 2th point
 
    fang[3][0] = x+x1;
    fang[3][1] = y;
    fang[3][2] = z;        //  the 0th point
    for(int i=0;i<4;i++){  // for()loop to calcolate other 4 points
        for(int j=0;j<3;j++){
            if(j==1)
                fang[i+4][j]=fang[i][j]+y1;
            else
                fang[i+4][j]=fang[i][j];
        }
    }
}
void build2(){
    glBegin(GL_POLYGON);
    //glColor3f(red);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(san[0][0],san[0][1],san[0][2]);
    glVertex3f(san[1][0],san[1][1],san[1][2]);
    glVertex3f(san[2][0],san[2][1],san[2][2]);
    glVertex3f(san[3][0],san[3][1],san[3][2]);
    glEnd();   //     below
 
    glBegin(GL_POLYGON);
    //glColor3f(green);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(san[1][0],san[1][1],san[1][2]);
    glVertex3f(san[0][0],san[0][1],san[0][2]);
    glVertex3f(san[4][0],san[4][1],san[4][2]);
    glVertex3f(san[5][0],san[5][1],san[5][2]);
    glEnd();   //     left
 
    glBegin(GL_POLYGON);
    //glColor3f(green);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(san[7][0],san[7][1],san[7][2]);
    glVertex3f(san[6][0],san[6][1],san[6][2]);
    glVertex3f(san[3][0],san[3][1],san[3][2]);
    glVertex3f(san[2][0],san[2][1],san[2][2]);
    glEnd();   //     right
 
    glBegin(GL_POLYGON);
    //glColor3f(green);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(san[5][0],san[5][1],san[5][2]);
    glVertex3f(san[6][0],san[6][1],san[6][2]);
    glVertex3f(san[2][0],san[2][1],san[2][2]);
    glVertex3f(san[1][0],san[1][1],san[1][2]);
    glEnd();   //     front
 
    glBegin(GL_POLYGON);
    //glColor3f(green);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(san[0][0],san[0][1],san[0][2]);
    glVertex3f(san[3][0],san[3][1],san[3][2]);
    glVertex3f(san[7][0],san[7][1],san[7][2]);
    glVertex3f(san[4][0],san[4][1],san[4][2]);
    glEnd();   //     back
 
    glBegin(GL_POLYGON);
    //glColor3f(red);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(san[4][0],san[4][1],san[4][2]);
    glVertex3f(san[7][0],san[7][1],san[7][2]);
    glVertex3f(san[6][0],san[6][1],san[6][2]);
    glVertex3f(san[5][0],san[5][1],san[5][2]);
    glEnd();   //     top
}
void build(){
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(fang[0][0],fang[0][1],fang[0][2]);
    glVertex3f(fang[1][0],fang[1][1],fang[1][2]);
    glVertex3f(fang[2][0],fang[2][1],fang[2][2]);
    glVertex3f(fang[3][0],fang[3][1],fang[3][2]);
    glEnd();   //     below
 
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(fang[1][0],fang[1][1],fang[1][2]);
    glVertex3f(fang[0][0],fang[0][1],fang[0][2]);
    glVertex3f(fang[4][0],fang[4][1],fang[4][2]);
    glVertex3f(fang[5][0],fang[5][1],fang[5][2]);
    glEnd();   //     left
 
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(fang[7][0],fang[7][1],fang[7][2]);
    glVertex3f(fang[6][0],fang[6][1],fang[6][2]);
    glVertex3f(fang[2][0],fang[2][1],fang[2][2]);
    glVertex3f(fang[3][0],fang[3][1],fang[3][2]);
    glEnd();   //     right
 
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(fang[5][0],fang[5][1],fang[5][2]);
    glVertex3f(fang[6][0],fang[6][1],fang[6][2]);
    glVertex3f(fang[2][0],fang[2][1],fang[2][2]);
    glVertex3f(fang[1][0],fang[1][1],fang[1][2]);
    glEnd();   //     front
 
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(fang[0][0],fang[0][1],fang[0][2]);
    glVertex3f(fang[3][0],fang[3][1],fang[3][2]);
    glVertex3f(fang[7][0],fang[7][1],fang[7][2]);
    glVertex3f(fang[4][0],fang[4][1],fang[4][2]);
    glEnd();   //     back
 
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(fang[4][0],fang[4][1],fang[4][2]);
    glVertex3f(fang[7][0],fang[7][1],fang[7][2]);
    glVertex3f(fang[6][0],fang[6][1],fang[6][2]);
    glVertex3f(fang[5][0],fang[5][1],fang[5][2]);
    glEnd();   //     top
}




void House :: DrawDorm(double x, double y, double z, double scale)
{
    
    glPushMatrix();
    glTranslatef(x, y, z),
    glScaled(scale, scale, scale);
    //**************************** Add garage floor（color  dark grey）****************
    glBegin(GL_POLYGON);
    constract(330,20,250,140,1,250);
    glColor3f(gray);
    build();
    //****************************Add fence base (color is white)****************
    glBegin(GL_POLYGON);
    constract(10,10,10,20,20,480);
    glColor3f(white);
    build();       //    Corresponding to point A
    constract(30,10,10,440,20,20);
    glColor3f(white);
    build();       //    Corresponding to point B
    constract(470,10,10,20,20,480);
    glColor3f(white);
    build();       //    Corresponding to point C
    constract(30,10,470,100,20,20);
    glColor3f(white);
    build();       //    Corresponding to point D
    constract(230,10,470,100,20,20);
    glColor3f(white);
    build();       //    Corresponding to point F
    
    //****************************Add fence post (color is white)********
    glBegin(GL_POLYGON);
    constract(10,10,10,20,50,20);
    glColor3f(white);
    build();       //    Corresponding to point A
    glBegin(GL_POLYGON);
    constract(470,10,10,20,50,20);
    glColor3f(white);
    build();       //    Corresponding to point C
    glBegin(GL_POLYGON);
    constract(230,10,470,20,50,20);
    glColor3f(white);
    build();
    glBegin(GL_POLYGON);
    constract(10,10,470,20,50,20);
    glColor3f(white);
    build();
    glBegin(GL_POLYGON);
    constract(470,10,470,20,50,20);
    glColor3f(white);
    build();
    glBegin(GL_POLYGON);
    constract(310,10,470,20,50,20);
    glColor3f(white);
    build();
    glBegin(GL_POLYGON);
    constract(110,10,470,20,50,20);
    glColor3f(white);
    build();
    
    //****************************Add fence (dark gray color)********
    glColor3f(hgray);
    for(int i=35;i<470;i+=25)
    {
        constract(15,20,i,6,30,6);
        build();         //Left vertical bar
    }
    for(int i=35;i<470;i+=25)
    {
        constract(475,20,i,6,30,6);
        build();          // Right vertical bar
    }
    for(int i=35;i<470;i+=25)
    {
        constract(i,20,15,6,30,6);
        build();          // Top bar
    }
    for(int i=35;i<110;i+=25)
    {
        constract(i,20,485,6,30,6);
        build();          // Bottom bar 1
    }
    for(int i=250;i<310;i+=25)
    {
        constract(i,20,485,6,30,6);
        build();          // Bottom bar 2
    }
    
    //****************************Add garage wall (color is white)********
    glColor3f(white);
    constract(320,10,250,10,100,220);
    build();
    constract(460,10,250,10,100,220);
    build();
    //****************************Add garage roof (dark gray color)********
    glColor3f(hgray);
    constract(320,110,250,150,10,220);
    build();
    //****************************Add bedroom and living room walls (white color)********
    glColor3f(white);
    constract(50,10,50,12,150,200);
    build();     //Left wall
    glColor3f(white);
    constract(438,10,50,12,150,200);
    build();     //right wall
    glColor3f(white);
    constract(62,10,50,376,150,12);
    build();     //Go up to the wall
    glColor3f(white);
    constract(62,10,235,376,50,12);
    build();     //Lower wall1
    glColor3f(white);
    constract(62,60,235,50,50,12);
    build();     //Lower wall2
    glColor3f(white);
    constract(162,60,235,276,50,12);
    build();     //Lower wall3
    glColor3f(white);
    constract(62,110,235,376,50,12);
    build();     //Lower wall4

    //****************************Add glass to bedroom and living room (white color)********
    glColor4f(blue,0.35);
    constract(62+50,60,235,50,50,12);
    build();
    //****************************Add garage glass (dark grey)********
    glColor4f(blue,0.35);
    constract(330,22,450,130,90,10);
    build();

    //****************************Add roof (color red)************
    glColor3f(50.0/255, 78.0/255, 78.0/255);
    cons(50,160,140,400,27,110);
    build2();
    cons(50,187,140,400,27,90);
    build2();
    cons(50,214,140,400,27,70);
    build2();
    cons(50,241,140,400,15,50);
    build2();

    cons(50,160,140,400,27,-110);
    build2();
    cons(50,187,140,400,27,-90);
    build2();
    cons(50,214,140,400,27,-70);
    build2();
    cons(50,241,140,400,15,-50);
    build2();

     //************************************* door*************
    glColor3f(men);
    constract(230,10,250,50,100,5);
    build();              //door
    glColor3f(menba);
    constract(235,60,255,5,5,5);
    build();              //Door handle
    //**************************************path*************
    for(int i=0;i<6;i++)
    {
        glColor3f(brown);
        constract(235-i*15,10,250+i*40,40,2,20);
        build();
    }
    //**************************************trunk*************
    glColor3f(brown);
    constract(60,10,390,15,70,15);
    build();
    //**************************************leaf*************
    glColor3f(hgreen);
    glTranslatef(60,70,400);
    glutSolidSphere(25.0, 20, 20);
    glTranslatef(20,0,0);
    glutSolidSphere(25.0, 20, 20);
    glTranslatef(-10,0,-10);
    glutSolidSphere(25.0, 20, 20);
    glTranslatef(0,0,20);
    glutSolidSphere(25.0, 20, 20);
    glTranslatef(0,10,-10);
    glutSolidSphere(25.0, 20, 20);
    glPopMatrix();
}




void House::Display(){
    // display 6 residential houses
    for (int i = 0; i < 3; i ++) {
        DrawDorm(-220-i *100,-200,160, 0.2);
        DrawDorm(-220-i*100,-200,0, 0.2);
    }
}
