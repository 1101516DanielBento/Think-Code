#include "TicTacToe.h"
#include <glut.h>
#include <iostream>
#include <vector>
#include <tuple>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

bool mouseClicked = false;

using namespace std;

vector<tuple<int,int,int>> references;//tuple<boxX,boxY,boxNum
tuple<int,int> mouseCoords;
TicTacToe* t = new TicTacToe();

void drawBoard(){
	
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(0,200);
	glVertex2f(600,200);
	glEnd();

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(0,400);
	glVertex2f(600,400);
	glEnd();

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(200,0);
	glVertex2f(200,600);
	glEnd();

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(400,0);
	glVertex2f(400,600);
	glEnd();
}

void loadReferences(){
	
	tuple<int,int,int> temp1;
	get<0>(temp1)=0;
	get<1>(temp1)=400;
	get<2>(temp1)=1;
	references.push_back(temp1);
	
	tuple<int,int,int> temp2;
	get<0>(temp2)=200;
	get<1>(temp2)=400;
	get<2>(temp2)=2;
	references.push_back(temp2);

	tuple<int,int,int> temp3;
	get<0>(temp3)=400;
	get<1>(temp3)=400;
	get<2>(temp3)=3;
	references.push_back(temp3);
	
	tuple<int,int,int> temp4;
	get<0>(temp4)=0;
	get<1>(temp4)=200;
	get<2>(temp4)=4;
	references.push_back(temp4);
	
	tuple<int,int,int> temp5;
	get<0>(temp5)=200;
	get<1>(temp5)=200;
	get<2>(temp5)=5;
	references.push_back(temp5);
	
	tuple<int,int,int> temp6;
	get<0>(temp6)=400;
	get<1>(temp6)=200;
	get<2>(temp6)=6;
	references.push_back(temp6);
	
	tuple<int,int,int> temp7;
	get<0>(temp7)=0;
	get<1>(temp7)=0;
	get<2>(temp7)=7;
	references.push_back(temp7);
	
	tuple<int,int,int> temp8;
	get<0>(temp8)=200;
	get<1>(temp8)=0;
	get<2>(temp8)=8;
	references.push_back(temp8);
	
	tuple<int,int,int> temp9;
	get<0>(temp9)=400;
	get<1>(temp9)=0;
	get<2>(temp9)=9;
	references.push_back(temp9);
}


void drawCircle(int boardX,int boardY){
    
	glPushMatrix();

	glTranslatef(boardX,boardY,0);

	glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0);
        for(int n = 0; n <= 40; ++n) {
            float const t = 2*M_PI*(float)n/(float)40;
            glVertex2f(50 + sin(t)*100, 190 + cos(t)*100);
	    /*glVertex2f(x, y);
        for( int n = 0; n <= segments; ++n ) {
            float const t = 2*M_PI*(float)n/(float)segments
            glVertex2f(x + sin(t)*r, y + cos(t)*r);
        }*/
        }
    glEnd();

	glPopMatrix();
}
tuple<int,int> BoxClick(int mouseX,int mouseY){
	
	for(unsigned int i=0; i<9 ;i++){
		if(mouseX < get<0>(references.at(i))+200 && mouseX > get<0>(references.at(i)) && mouseY < get<1>(references.at(i))+200 && mouseY > get<1>(references.at(i))){
			tuple<int,int> temp;
			get<0>(temp)=get<0>(references.at(i));
			get<1>(temp)=get<0>(references.at(i));
			cout<<"You clicked on a box!"<<endl;
			cout<<"Box number "<<get<2>(references.at(i))<<endl;
			return temp;
		}
	}
}

void mouseCoordinates(int x, int y){
	get<0>(mouseCoords)=x;
	get<1>(mouseCoords)=y;
}

int AIMove(){
	t->RequestAIMove();
	return t->getAICoord();
}

void MouseButton(int button, int state, int x, int y)
{
	 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		 mouseClicked=true;
		 mouseCoordinates(x,600-y);
		 cout<<"Mouse X: "<<get<0>(mouseCoords)<<endl;
		 cout<<"Mouse Y: "<<get<1>(mouseCoords)<<endl;
	 }
}

void draw(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 600, 0.0, 600);
    glMatrixMode(GL_MODELVIEW);
 
	glPushMatrix();
	drawBoard();
	//drawCircle(0,100);
	glPopMatrix();
	
	glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);

	if(mouseClicked==true){
		tuple<int,int> temp=BoxClick(get<0>(mouseCoords),get<1>(mouseCoords));
		glPushMatrix();
		drawCircle(get<0>(temp),get<1>(temp));
		glPopMatrix();
		mouseClicked=false;
	}

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
	glutSwapBuffers();
    glutPostRedisplay();

}

void Reshape(GLint x, GLint y){
	glutReshapeWindow(600,600);
}

void Init(){
	loadReferences();
}


int main (int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(10,10);
	glutCreateWindow("TicTacToe");
	Init();
	glutDisplayFunc(draw);
	glutReshapeFunc(Reshape);
	glutMouseFunc(MouseButton);
	glutMainLoop();



	//t->RequestAIMove();
	//t->getAICoord();

	//cout<<"You play"<<endl;
	//cin>>pos;

	//t->RequestPlayerMove(pos);
	//t->getMyCoord();

	//cin.get();
	
	return 0;
}
