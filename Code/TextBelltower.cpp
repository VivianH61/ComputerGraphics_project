//
//  TextBelltower.cpp
//  G53GRA.Framework
//
//  Created by VV on 2020/12/4.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "TextBelltower.hpp"
#include "Helperfunctions.hpp"
#include <string>
using namespace std;




void TextBelltower::SetTexture(const std::string& filename)
{
    // Load texture using the provided Texture loader (.bmp only)
    _texID = Scene::GetTexture(filename);
}

void belltower();
void ground();
void posters();
void studentcenter();


void TextBelltower::Display()
{
    Helper *help = new Helper();
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glDisable(GL_DEPTH_TEST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    

    glPushMatrix();//00000
    glTranslatef(0, -200, 0);
    
    ground();
    
    belltower();
    studentcenter();
    glPushMatrix();
    glTranslatef(300, 0, 0);
    studentcenter();
    glPopMatrix();


    glEnable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    
    
    glPopMatrix(); //00000

}

void belltower(){
    Helper *help = new Helper();
    //***************BellTower****Begin***********************
        glPushMatrix();
        glTranslatef(-300, 0, -250);
        //画楼
        string filename = "./building/jinshu.bmp";
        //下
        glPushMatrix();
        glTranslatef(-2.5,0,-2.5);
        help->DrawTextCuboid(50,60,50,filename);
        glPopMatrix();
        //中
        glPushMatrix();
        glTranslatef(0, 60, 5);
        help->DrawTextCuboid(45,50,45,filename);
        glPopMatrix();
        //上
        glPushMatrix();
        glTranslatef(2.5, 110, 7.5);
        help->DrawTextCuboid(40,40,40,filename);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(2.5, 150, 7.5);
        help->DrawTextTetrahedron(40, 10, 40,filename);
        glPopMatrix();
        
        
        //画钟表 （没有texture）
        glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(23, 135, 48);
        glColor3f(1, 1, 1);
        help->DrawCylinder(16, 0.5);
        for (int i=0; i<12; i++) {
            glColor3f(0, 0, 0);
            glPushMatrix();
            glRotatef(30*i, 0, 0, 1);
            glTranslatef(0, 13, 0);
            help->DrawCuboid(2, 4, 0.5);
            glPopMatrix();
        }
        double hour_angle = 60;
        double minute_angle = 0;
        double second_angle = 40;
        //时针
        glPushMatrix();
        glRotatef(hour_angle, 0, 0, 1);
        glTranslatef(0, 3, 7);
        help->DrawCuboid(3, 6, 0.5);
        glPopMatrix();
        //分针
        glPushMatrix();
        glRotatef(minute_angle, 0, 0, 1);
        glTranslatef(0, 4, 7);
        help->DrawCuboid(2, 8, 0.5);
        glPopMatrix();
        //秒针
        glPushMatrix();
        glRotatef(second_angle, 0, 0, 1);
        glTranslatef(0, 5, 7);
        help->DrawCuboid(1, 10, 0.5);
        glPopMatrix();
        
        glPopMatrix();
        
        //画钟楼左右边的楼
        filename = "./building/SC_wall.bmp";
        //左
        glPushMatrix();
        glTranslatef(-170, 0, 0);
        help->DrawTextCuboid(165, 65, 45, filename);
        glPopMatrix();
        //右
        glPushMatrix();
        glTranslatef(55, 0, 0);
        help->DrawTextCuboid(165, 65, 45, filename);
        glPopMatrix();

        filename = "./building/window2.bmp";
        //画窗户(left)
        for (int i = 0; i < 8; i ++) {
            int x = -160;
            glPushMatrix();
            glTranslatef(x + i * 20, 45, 45);
            
            help->DrawTextCuboid(10, 16, 0.5, filename);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(x + i * 20, 21, 45);
            help->DrawTextCuboid(10, 16, 0.5, filename);
            glPopMatrix();
        }
        //画窗户(right)
        for (int i = 0; i < 8; i ++) {
            int x = 65;
            glPushMatrix();
            glTranslatef(x + i * 20, 45, 55);
            help->DrawTextCuboid(10, 16, 0.5, filename);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(x + i * 20, 21, 55);
            help->DrawTextCuboid(10, 16, 0.5, filename);
            glPopMatrix();
        }
        
        
        string t = "./building/building3.bmp";
       
        //画屋顶
        glPushMatrix();
        glTranslatef(-5, 50, 45);
        help->DrawRoof(56, 20, 20, t);
        glPopMatrix();
        //画台阶
        
        glPushMatrix();
        double stair_size = 4;
        int stair_num = 5;
        glTranslatef(0, stair_size*stair_num, 50);
        for (int i=1; i<=stair_num; i++) {
            glTranslatef(0, -stair_size, 0);
            help->DrawTextCuboid(45,stair_size,20+stair_size*i,t);
        }
        glPopMatrix();
    
    
        //画柱子
        
    
        glPushMatrix();
        glTranslatef(5, stair_size*stair_num, 61);
        help->DrawTextCuboid(3,30,3,t);
        glPopMatrix();
    
        glPushMatrix();
        glTranslatef(39, stair_size*stair_num, 61);
        help->DrawTextCuboid(3,30,3,t);
        glPopMatrix();
        
        glPopMatrix();
        //********BellTower*****END*********
}

void ground() {
    Helper *help = new Helper();
    //spinning sphere 底座
    glPushMatrix();
    glTranslatef(230, 0,70);
    //glRotated(90, 1, 0, 0);
    glColor3f(30.0/255, 47.0/255, 47.0/255);
    help->DrawTextCuboid(40, 20, 40, "./building/text2.bmp");
    glPopMatrix();
    
    
    string t = "";
    
    // draw grassland
    glPushMatrix();
    glColor3f(78.0/255, 112.0/255, 16.0/255);
    glTranslatef(300, 0, 0);
    help->DrawCuboid(2000, 0.1, 1000);
    glPopMatrix();
    
    //ground under student ceter
    glPushMatrix();
    t = "./ground/grid3.bmp";
    
    for (int i = 0; i < 20; i ++) {
        for (int j = 0; j < 10; j ++) {
            glPushMatrix();
            glTranslatef(-30 + i*30, 0, 200-j*30);
            help->DrawTextCuboid(30, 0.1, 30, t);
            glPopMatrix();
        }
    }
    glPopMatrix();
    
//    // draw river
//    glPushMatrix();
//    t = "./ground/water.bmp";
//    glTranslatef(-70, 0.01, 70);
//    int len_unit = 150;
//    help->DrawTextCuboid(30, 0.1, len_unit, t);
//    glTranslatef(0, 0, -len_unit);
//    help->DrawTextCuboid(30, 0.1, len_unit, t);
//    glPopMatrix();
    
    //draw 居民楼other building
    t = "./building/building5.bmp";
    glPushMatrix();
    glTranslatef(0, 0, -250);
    help->DrawTextCuboid(100, 150, 80, t);
    glTranslatef(0, 0, -100);
    help->DrawTextCuboid(100, 150, 80, t);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0, 0, -250);
    help->DrawTextCuboid(100, 150, 80, t);
    glPopMatrix();
    
    t = "./building/building2.bmp";
    glPushMatrix();
    glTranslatef(150, 0, -250);
    help->DrawTextCuboid(180, 120, 80, t);
    glPopMatrix();
    
    t = "./building/building3.bmp";
    glPushMatrix();
    glTranslatef(400, 0, -250);
    help->DrawTextCuboid(100, 150, 80, t);
    glPopMatrix();
    
    
    
    // draw road
    //横向
    t = "./ground/road7.bmp";
    glPushMatrix();
    int w = 50;
    int l_unit = 170;
    glTranslatef(-500, 0, 250);
    for (int i = 0; i < 30; i ++) {
        help->DrawTextCuboid(l_unit, 0.1, w, t);
        glTranslatef(l_unit, 0, 0);
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-500, 0, -150);
    for (int i = 0; i < 30; i ++) {
        help->DrawTextCuboid(l_unit, 0.1, w, t);
        glTranslatef(l_unit, 0, 0);
    }
    glPopMatrix();
    //纵向
    t = "./ground/road8.bmp";
    glPushMatrix();
    l_unit= 180;
    glTranslatef(-100, 10, 85);
    for (int i = 0; i < 4; i ++) {
        help->DrawTextCuboid(w, 0.1, l_unit, t);
        glTranslatef(0, 0, -w);
    }
    glPopMatrix();
    
    
    // traffic light
    t = "./others/light1.bmp";
    glPushMatrix();
    glTranslatef(-100, 50, 250);
    glPushMatrix();
    glRotated(90, 1, 0, 0);
    help->DrawCylinder(1, 50);
    glPopMatrix();
    glRotated(45, 0, 0, 1);
    help->DrawTextCuboid(20, 20, 0.1, t);
    glPopMatrix();
    
}

void studentcenter() {
    Helper *help = new Helper();
    // ************Student Center****Begin*************
    
    //main body
    help->DrawTextCuboid(200, 30, 200, "./building/building7.bmp");
    string t = "";
    int x = 32; //小方块的边长
    int d = 5; //方块之间的间隙
    int x0 = 10+x/2;
    int z0 = 10+x/2;
    
    x0 = 10;
    z0 = 10;
    
    int xn;
    int zn;
    // 周围四个角 浅灰色
    //t = "./ground/grid5.bmp";
    t = "./building/text1.bmp";
    glColor3f(220.0/255, 220.0/255, 220.0/255);
    glPushMatrix();
    xn = 0;
    zn = 0;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 0;
    zn = 1;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 1;
    zn = 0;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 3;
    zn = 0;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 4;
    zn = 0;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 4;
    zn = 1;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 4;
    zn = 3;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 4;
    zn = 4;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 3;
    zn = 4;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 0;
    zn = 3;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 1;
    zn = 4;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 0;
    zn = 4;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    //深灰色
    //t = "./ground/grid1.bmp";
    t = "./building/text4.bmp";
    glColor3f(102.0/255, 102.0/255, 102.0/255);
    glPushMatrix();
    xn = 0;
    zn = 2;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 1;
    zn = 1;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 1;
    zn = 3;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 3;
    zn = 1;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 3;
    zn = 3;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 2;
    zn = 0;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 2;
    zn = 4;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 2;
    zn = 2;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 4;
    zn = 2;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    
    // 绿色
    glColor3f(0, 77.0/255, 0);
    t = "./building/text1.bmp";
    glPushMatrix();
    xn = 2;
    zn = 1;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 1;
    zn = 2;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 2;
    zn = 3;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    
    glPushMatrix();
    xn = 3;
    zn = 2;
    glTranslatef(x0 + (x+d)*xn, 30, z0 + (x+d)*zn);
    help->DrawTextCuboid(32, 0.1, 32, t);
    glPopMatrix();
    

//
    
//    //draw posters
//    glPushMatrix();
//    glTranslatef(20, 7, 200);
//    help->DrawTextCuboid(40, 15, 0.1, "posters/poster1.bmp");
//    glPopMatrix();
    // ***********Student Center***END*****************
}



