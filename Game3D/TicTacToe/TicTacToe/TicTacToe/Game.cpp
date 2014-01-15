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
tuple<int,int,int> temp;
bool circle=false;
vector<tuple<int,int,int>> myPlays, aiPlays;
vector<int> xSpots, oSpots;
char state[]={'t','t','t','t','t','t','t','t','t'};
TicTacToe* t = new TicTacToe();
int numPlays=0,countPlays=0;

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

void drawCircle(int boxX,int boxY){
    
	glPushMatrix();

	glTranslatef(boxX+100,boxY+100,0);

	glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0);
        for(int n = 0; n <= 40; ++n) {
            float const t = 2*M_PI*(float)n/(float)40;
            glVertex2f(0 + sin(t)*60, 0 + cos(t)*60);
        }
    glEnd();

	glPopMatrix();
}

void drawCross(int boxX, int boxY){
	
	glPushMatrix();

	glTranslatef(boxX+20,boxY+20,0);

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(160,160);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0,160);
	glVertex2f(160,0);
	glEnd();

	glPopMatrix();
}

tuple<int,int,int> BoxClick(int mouseX,int mouseY){
	
	for(unsigned int i=0; i<9 ;i++){
		if(mouseX < get<0>(references.at(i))+200 && mouseX > get<0>(references.at(i)) && mouseY < get<1>(references.at(i))+200 && mouseY > get<1>(references.at(i))){
			tuple<int,int,int> temp;
			get<0>(temp)=get<0>(references.at(i));
			get<1>(temp)=get<1>(references.at(i));
			get<2>(temp)=get<2>(references.at(i));
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

int RequestAIMove(){
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


void updateState(char turn,int index){//array com posicoes que ja foram jogadas
	state[index-1]=turn;
	numPlays++;
}

void playerWin(){
	cout<<"Player wins!"<<endl;
	_sleep(2000);
	return;
}

void AiWin(){
	cout<<"Computer wins!"<<endl;
	_sleep(2000);
	return;
}

void itsADraw(){
	cout<<"Draw!"<<endl;
	_sleep(2000);
	return;
}

void checkState(){

		//check for player victory
		//horizontal win
		if(state[0]=='o' && state[1]=='o' && state[2]=='o'){
			playerWin();
			return;
		}

		if(state[3]=='o' && state[4]=='o' && state[5]=='o'){
			playerWin();
			return;
		}
			
		if(state[6]=='o' && state[7]=='o' && state[8]=='o'){
			playerWin();
			return;
		}
		//vertical win
		if(state[0]=='o' && state[3]=='o' && state[6]=='o'){
			playerWin();
			return;
		}

		if(state[1]=='o' && state[4]=='o' && state[7]=='o'){
			playerWin();
			return;
		}
			
		if(state[2]=='o' && state[5]=='o' && state[8]=='o'){
			playerWin();
			return;
		}
		//diagonal win
		if(state[0]=='o' && state[4]=='o' && state[8]=='o'){
			playerWin();
			return;
		}

		if(state[2]=='o' && state[4]=='o' && state[6]=='o'){
			playerWin();
			return;
		}

		//check for AI victory
		//horizontal win
		if(state[0]=='x' && state[1]=='x' && state[2]=='x'){
			AiWin();
			return;
		}

		if(state[3]=='x' && state[4]=='x' && state[5]=='x'){
			AiWin();
			return;
		}
			
		if(state[6]=='x' && state[7]=='x' && state[8]=='x'){
			AiWin();
			return;
		}
		//vertical win
		if(state[0]=='x' && state[3]=='x' && state[6]=='x'){
			AiWin();
			return;
		}

		if(state[1]=='x' && state[4]=='x' && state[6]=='x'){
			AiWin();
			return;
		}
			
		if(state[2]=='x' && state[5]=='x' && state[8]=='x'){
			AiWin();
			return;
		}
		//diagonal win
		if(state[0]=='x' && state[4]=='x' && state[8]=='x'){
			AiWin();
			return;
		}

		if(state[2]=='x' && state[4]=='x' && state[6]=='x'){
			AiWin();
			return;
		}
		//check draw

		if(countPlays==8){
			itsADraw();
			return;
		}
}



tuple<int,int,int> findCoordsByBoxNum(int n){

	for(unsigned int i=0;i<references.size();i++){
		if(n==get<2>(references.at(i)))
			return references.at(i);
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
	glPopMatrix();
	
	glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);

	if(mouseClicked==true){
		//Player
		temp = BoxClick(get<0>(mouseCoords),get<1>(mouseCoords));
		myPlays.push_back(temp);
		t->RequestPlayerMove(get<2>(temp));
		updateState('o',get<2>(temp));
		cout<<get<2>(temp)<<endl;
		countPlays++;
		
		//AI
		temp=findCoordsByBoxNum(RequestAIMove());
		aiPlays.push_back(temp);
		updateState('x',get<2>(temp));
		cout<<get<2>(temp)<<endl;
		countPlays++;

		for(unsigned int i=0;i<9;i++){
			 cout<<state[i]<<endl;
		}

		mouseClicked=false;
	}

	for(unsigned int i=0;i<myPlays.size();i++){
		drawCircle(get<0>(myPlays.at(i)),get<1>(myPlays.at(i)));
	}
	
	for(unsigned int i=0;i<aiPlays.size();i++){
		drawCross(get<0>(aiPlays.at(i)),get<1>(aiPlays.at(i)));
	}

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
	glutSwapBuffers();
    glutPostRedisplay();
	checkState();//check if game ended
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

	return 0;
}
