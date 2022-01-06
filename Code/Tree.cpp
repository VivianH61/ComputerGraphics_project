//#include <windows.h>
//#include <GL/freeglut.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Tree.hpp"

#include <stdio.h>      /* printf, scanf, puts, NULL */



#define TREE 6
#define STEM 1
#define LEAF 2
#define LEAF_MAT 3
#define TREE_MAT 4
#define STEMANDLEAVES 5

const double PI = 3.14159265;
int Rebuild = 1;
int Level = 4;
double g_r = 8, g_theta = PI / 2.0, g_phai = PI / 2.0;
float treePos[3] = { 0, -2, 4 };

Tree::Tree()
{

}

inline float randf()
{
  return (rand() / (float)RAND_MAX);
}

/*
 1. Starting at some point and move a certain distance in a certain direction.
 2. At that point, make a branch.
 3. Turn some angle to the right and then repeat the previous step with a shorter distance.
 4. Go to step 1
 5. Finally, bound each node with a leaf
 */

void FractalTree(int level)
{
  long savedseed;

  if (level == Level)
  {
    glPushMatrix();
    glRotatef(60 + randf() * 120, 0, 1, 0);
    glCallList(STEMANDLEAVES);
    glPopMatrix();
  }
  else
  {
    glCallList(STEM);

    glPushMatrix();
    glTranslatef(0, 100, 0);
    glScalef(0.7, 0.7, 0.7);

    savedseed = rand();
    glPushMatrix();
    glRotatef(0 + randf() * 90, 0, 1, 0);
    glRotatef(30 + randf() * 30, 0, 0, 1);
    FractalTree(level + 1);
    glPopMatrix();

    srand(savedseed);
    savedseed = rand();
    glPushMatrix();
    glRotatef(180 + randf() * 90, 0, 1, 0);
    glRotatef(30 + randf() * 30, 0, 0, 1);
    FractalTree(level + 1);
    glPopMatrix();

    srand(savedseed);
    savedseed = rand();
    glPushMatrix();
    glRotatef(90 + randf() * 90, 0, 1, 0);
    glRotatef(30 + randf() * 30, 0, 0, 1);
    FractalTree(level + 1);
    glPopMatrix();

    glPopMatrix();
  }
}

void CreateTreeLists(void)
{
  GLUquadricObj* cylquad = gluNewQuadric();
  int i;

  glNewList(STEM, GL_COMPILE);
  glCallList(TREE_MAT);
  glPushMatrix();
  glRotatef(-90, 1, 0, 0);
  gluCylinder(cylquad, 10, 8, 100, 10, 2);
  glPopMatrix();
  glEndList();

  glNewList(LEAF, GL_COMPILE);
  glBegin(GL_TRIANGLES);
  glNormal3f(-0.1, 0, 0.25);
  glVertex3f(0, 0, 0);
  glVertex3f(50, 50, 20);
  glVertex3f(0, 100.0, 0);
  glNormal3f(0.2, 0, 0.5);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 100.0, 0);
  glVertex3f(-50, 50, 20);
  glEnd();
  glEndList();

  glNewList(STEMANDLEAVES, GL_COMPILE);
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glCallList(STEM);
  glCallList(LEAF_MAT);
  for (i = 0; i < 3; i++)
  {
    glTranslatef(0, 3.33, 0);
    glRotatef(90, 0, 1, 0);
    glPushMatrix();
    glRotatef(0, 0, 1, 0);
    glRotatef(50, 1, 0, 0);
    glCallList(LEAF);
    glPopMatrix();
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glRotatef(60, 1, 0, 0);
    glCallList(LEAF);
    glPopMatrix();
  }
  glPopAttrib();
  glPopMatrix();
  glEndList();

  gluDeleteQuadric(cylquad);
}

void SetupMaterials(void)
{
  GLfloat tree_ambuse[] = { 0.4, 0.25, 0.1, 1.0 };
  GLfloat tree_specular[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat tree_shininess[] = { 10 };

  GLfloat leaf_ambuse[] = { 0.9, 0.0, 0.0, 1.0 };
  GLfloat leaf_specular[] = { 0.9, 0.9, 0.0, 1.0 };
  GLfloat leaf_shininess[] = { 10 };

  glNewList(TREE_MAT, GL_COMPILE);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, tree_ambuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, tree_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, tree_shininess);
  glEndList();

  glNewList(LEAF_MAT, GL_COMPILE);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, leaf_ambuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, leaf_specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, leaf_shininess);
  glEndList();
}

void Tree::Display()
{

 
    for (int i = 0; i < 15; i ++) {
        glPushMatrix();
        glTranslatef(-40, -200.0f, 240.0f - 20 * i);
        glScaled(0.1, 0.1, 0.1);
        glRotatef(i * 90, 0.0, 1.0, 0.0);
        if (Rebuild)
        {
        glNewList(TREE, GL_COMPILE);
        FractalTree(0);
        glEndList();
        Rebuild = 0;
        }
        glCallList(TREE);
        SetupMaterials();
        CreateTreeLists();
        glPopMatrix();
    }
    
    int tmp_x = 0;
    int tmp_z = 0;
    int min_x = -400;
    int max_x = 500;
    int min_z = 300;
    int max_z = 400;
    srand( 1 );
    for (int i = 0; i < 100; i ++) {
        glPushMatrix();
        
        tmp_x = min_x + rand() % (( max_x + 1 ) - min_x);
        tmp_z = min_z + rand() % (( max_z + 1 ) - min_z);
        glTranslatef(tmp_x, -200.0f, tmp_z);
        glScaled(0.1, 0.1, 0.1);
        glRotatef(i * 90, 0.0, 1.0, 0.0);
        if (Rebuild)
        {
        glNewList(TREE, GL_COMPILE);
        FractalTree(0);
        glEndList();
        Rebuild = 0;
        }
        glCallList(TREE);
        SetupMaterials();
        CreateTreeLists();
        glPopMatrix();
    }
    //-400-500
    // z 300-400
            
    
    
    

}
