//
//  Labirinto.cpp
//  Grafo3DProject
//
//  Created by pedrosimoes on 22/12/13.
//  Copyright (c) 2013 pedrosimoes. All rights reserved.
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <iostream>


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;



void drawMaze(vector<vector<Cell>>  maze)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maze[i][j].south == 1) {
                glColor4f(0, .2, 0, 0);
                glPushMatrix();
                glTranslatef(j * 2 - 2, 0, i * 2);
                glScalef(1, 1, 0.25);   // Added here
                glutSolidCube(2);
                glPopMatrix();
            }
            if (maze[i][j].north == 1) {
                glColor4f(0, .2, 0, 0);
                glPushMatrix();
                glTranslatef(j * 2 + 2, 0, i * 2);
                glScalef(1, 1, 0.25);   // Added here
                glutSolidCube(2);
                glPopMatrix();
            }
            if (maze[i][j].east == 1) {
                glColor4f(0, .2, 0, 0);
                glPushMatrix();
                glTranslatef(j * 2, 0, i * 2 + 2);
                glScalef(0.25, 1, 1);   // Added here
                glutSolidCube(2);
                glPopMatrix();
            }
            if (maze[i][j].west == 1) {
                glColor4f(0, .2, 0, 0);
                glPushMatrix();
                glTranslatef(j * 2, 0, i * 2 - 2);
                glScalef(0.25, 1, 1);  // Added here
                glutSolidCube(2);
                glPopMatrix();
            }
        }
    }
}

void PrintMaze(vector<vector<Cell>>  maze){
    for(int i = 0; i < 2*10; ++i){
        cout << "_";
    }
    cout << endl;
    for (int i = 0; i < 10; ++i){
        cout << "|";
        for (int j = 0; j < 10; ++j){
            Cell c = maze[i][j];
            cout << (c.south == 0 ? " " : "_");
            if (c.east == 0)
                cout << " ";
            else cout << "|";
        }
        cout << endl;
    }
}
*/
/*int main()
{
	return 0;
}*/