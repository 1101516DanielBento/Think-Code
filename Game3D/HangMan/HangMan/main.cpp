#include <string>
#include "HangMan.h"
#include <SWI-cpp.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif
#include "GL/glu.h"
#include "RGBpixmap.h"
#include <iostream>
#include <glaux.h>
#include <tchar.h>
#include <tuple>
//#include <Windows.h>
#include <Mmsystem.h>

//incluir nas library directories glui32.lib
//pasta do projecto glui.h
//project propreties->linker->input->adicional dependencies->Winmm.lib

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
#ifndef POS_WORD
#define POS_WORD_X 80
#endif
#ifndef POS_WORD
#define POS_WORD_Y 420
#endif
#ifndef NUM_TRIES
#define NUM_TRIES 6
#endif
#ifndef LETTER_WIDTH
#define LETTER_WIDTH 30
#endif
#ifndef LETTER_HEIGHT
#define LETTER_HEIGHT 30
#endif
using namespace std;

string word, hint;
int wrong=0,sucess=0;
char* letters[]={"images\\a.bmp","images\\b.bmp","images\\c.bmp","images\\d.bmp",
				"images\\e.bmp","images\\f.bmp","images\\g.bmp","images\\h.bmp",
				"images\\i.bmp","images\\j.bmp","images\\k.bmp","images\\l.bmp",
				"images\\m.bmp","images\\n.bmp","images\\o.bmp","images\\p.bmp",
				"images\\q.bmp","images\\r.bmp","images\\s.bmp","images\\t.bmp",
				"images\\u.bmp","images\\v.bmp","images\\w.bmp","images\\x.bmp",
				"images\\y.bmp",
				"images\\z.bmp"};

char chars[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int textID[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
vector<tuple<int, int, char>> references;
tuple<int,int> mouseCoords;
char currentLetter;
bool mouseClicked=false,arrayFilled=false,wordLoaded=false,hintLoaded=false,coordinatesLoaded=false,boardLoaded=false,guessed=false,clickedOnKeyBoard=false,letterAlreadyGuessed=false;
//vector<tuple<int,int,int,int>> letterCoordinates;
HangMan* h = new HangMan();
vector<int> textureIDs,indexes;
vector<char> wordChars, guessedLetters;
int window_width=800, window_height=600;

void drawBackground(){

	RGBpixmap pixmap;
	pixmap.readBMPFile("images\\background.bmp");
	pixmap.setTexture(29);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 29);
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0.0,0.0); glVertex2d(0,0);
	glTexCoord2d(1.0,0.0); glVertex2d(window_width,0);
	glTexCoord2d(1.0,1.0); glVertex2d(window_width,window_height);
	glTexCoord2d(0.0,1.0); glVertex2d(0,window_height);
	glEnd();
	glPopMatrix();
}

void drawHanger(){
	
	glPushMatrix();

	glTranslatef(500,300,0);
	
	glBegin(GL_QUADS);
	glVertex2f(0,230);
	glVertex2f(230,230);
	glVertex2f(230,235);
	glVertex2f(0,235);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(220,0);
	glVertex2f(225,0);
	glVertex2f(225,230);
	glVertex2f(220,230);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0,0);
	glVertex2f(240,0);
	glVertex2f(240,5);
	glVertex2f(0,5);
	glEnd();

	glLineWidth(0.25);
	glBegin(GL_LINES);
	glVertex2f(50, 230);
	glVertex2f(50, 190);
	glEnd();
	
	glPopMatrix();
}

void drawHead(){
	
	glPushMatrix();

	glTranslatef(500,300,0);

	glBegin( GL_TRIANGLE_FAN );
        glVertex2f(50, 190);
        for( int n = 0; n <= 20; ++n ) {
            float const t = 2*M_PI*(float)n/(float)20;
            glVertex2f(50 + sin(t)*15, 190 + cos(t)*15);
	    /*glVertex2f(x, y);
        for( int n = 0; n <= segments; ++n ) {
            float const t = 2*M_PI*(float)n/(float)segments
            glVertex2f(x + sin(t)*r, y + cos(t)*r);
        }*/
        }
    glEnd();

	glPopMatrix();
}

void drawBody(){

	glPushMatrix();

	glTranslatef(500,300,0);

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 180);
	glVertex2f(50, 100);
	glEnd();

	glPopMatrix();
}

void drawLeftArm(){

	glPushMatrix();

	glTranslatef(500,300,0);

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 170);
	glVertex2f(30, 130);
	glEnd();

	glPopMatrix();
}

void drawRigthArm(){

	glPushMatrix();

	glTranslatef(500,300,0);

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 170);
	glVertex2f(70, 130);
	glEnd();

	glPopMatrix();
}

void drawLeftLeg(){

	glPushMatrix();

	glTranslatef(500,300,0);

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 100);
	glVertex2f(30, 60);
	glEnd();

	glPopMatrix();
}

void drawRigthLeg(){

	glPushMatrix();

	glTranslatef(500,300,0);

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 100);
	glVertex2f(70, 60);
	glEnd();

	glPopMatrix();

}

void win(){
	cout<<"You win!"<<endl;
	Sleep(2000);
	exit(0);
}

void lost(){
	cout<<"You Lost"<<endl;
	Sleep(2000);
	exit(0);
	//send stuff to database
}

void checkGameState(){
	if(wrong==6){
		lost();
	}

	if(sucess==word.size()){
		win();
	}
}

void loadHint(){

	glRasterPos2i(20, 550);
	
	void * font = GLUT_BITMAP_HELVETICA_18;

    for (string::iterator i = hint.begin(); i != hint.end(); ++i)
    {
        char c = *i;
        glutBitmapCharacter(font, c);
    }
}

int UpdateBoard(){

	int k=0;
	string image;
	int currentTextId;
	image="images\\";
	image.push_back(currentLetter);
	image+=".bmp";
	
	int index;

	if(indexes.size()!=0){

		for(unsigned int i=0;i<26;i++){
			if(strcmp(letters[i],image.c_str())==0){
				index=i;
			}

			if(chars[i]==currentLetter){
				currentTextId=i+1;
			}
		}

		for(unsigned int i=0; i<indexes.size();i++){
			textureIDs.at(indexes.at(i))=currentTextId;
		}

		for(unsigned int i=0;i<textureIDs.size();i++){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textureIDs.at(i));
			glPushMatrix();
			glTranslatef(20,400,0);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0,0.0); glVertex2d(k,30);
			glTexCoord2d(1.0,0.0); glVertex2d(k+30,30);
			glTexCoord2d(1.0,1.0); glVertex2d(k+30,60);
			glTexCoord2d(0.0,1.0); glVertex2d(k,60);
			glEnd();
			glPopMatrix();
			k+=30;
		}
	}

	if(indexes.size()==0){
		for(unsigned int i=0;i<textureIDs.size();i++){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textureIDs.at(i));
			glPushMatrix();
			glTranslatef(20,400,0);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0,0.0); glVertex2d(k,30);
			glTexCoord2d(1.0,0.0); glVertex2d(k+30,30);
			glTexCoord2d(1.0,1.0); glVertex2d(k+30,60);
			glTexCoord2d(0.0,1.0); glVertex2d(k,60);
			glEnd();
			glPopMatrix();
			k+=30;
		}
	}
	return indexes.size();
}

void InitBoard(){
	
	if(!wordLoaded){
		h->getWord();
		h->getHint();
		word=h->Word();
		hint="Pista: " + h->Hint();
		cout<<"Word: "<<word<<endl;
		h->WordChars();
		wordLoaded=true;
	}

	
	RGBpixmap pixmap;
	pixmap.readBMPFile("images\\underscore.bmp");
	pixmap.setTexture(27);
	pixmap.readBMPFile("images\\space.bmp");
	pixmap.setTexture(28);
	  
	for(unsigned int i=0;i<word.size();i++){
		if(word.at(i)==' ')
			textureIDs.push_back(28);
		textureIDs.push_back(27);
	}

	boardLoaded=true;
}

void loadKeyBoard(){
	int k=0,j=0,m=0;

	for(unsigned int i=0; i<26; i++){
		RGBpixmap pixmap;
		pixmap.readBMPFile(letters[i]);//
		pixmap.setTexture(i+1);
	
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, i+1);

	    tuple<int,int,char> temp;
		
		if(i<8){
			glPushMatrix();
			glTranslatef(220,150,0);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0,0.0); glVertex2d(k,30);
			glTexCoord2d(1.0,0.0); glVertex2d(k+30,30);
			glTexCoord2d(1.0,1.0); glVertex2d(k+30,60);
			glTexCoord2d(0.0,1.0); glVertex2d(k,60);
			glEnd();
			glPopMatrix();

			if(!arrayFilled){
				get<0>(temp)=k+220;
				get<1>(temp)=30+150;
				get<2>(temp)=chars[i];
			}
			k+=40;
		}

		if(i>=8 && i<16){
			glPushMatrix();
			glTranslatef(220,90,0);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0,0.0); glVertex2d(j,30);
			glTexCoord2d(1.0,0.0); glVertex2d(j+30,30);
			glTexCoord2d(1.0,1.0); glVertex2d(j+30,60);
			glTexCoord2d(0.0,1.0); glVertex2d(j,60);
			glEnd();
			glPopMatrix();

			if(!arrayFilled){
				get<0>(temp)=j+220;
				get<1>(temp)=30+90;
				get<2>(temp)=chars[i];
			}
			j+=40;
		}

		if(i>=16 && i<26){
			glPushMatrix();
			glTranslatef(185,30,0);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0,0.0); glVertex2d(m,30);
			glTexCoord2d(1.0,0.0); glVertex2d(m+30,30);
			glTexCoord2d(1.0,1.0); glVertex2d(m+30,60);
			glTexCoord2d(0.0,1.0); glVertex2d(m,60);
			glEnd();
			glPopMatrix();
			
			if(!arrayFilled){
				get<0>(temp)=m+185;
				get<1>(temp)=30+30;
				get<2>(temp)=chars[i];
			}
			m+=40;
		}
		if(!arrayFilled){
			references.push_back(temp);
		}
	}
	arrayFilled=true;
}

void mouseCoordinates(int x, int y){
	get<0>(mouseCoords)=x;
	get<1>(mouseCoords)=y;
}

void checkLetterGuessed(){

	if(guessedLetters.size()>0){
		
		for(unsigned int i=0;i<guessedLetters.size();i++){//checks for already guessed letters
			
			if(guessedLetters.at(i)==currentLetter){
				letterAlreadyGuessed=true;
				return;
				}
		}
	}
	return;
}

bool letterClick(int mouseX,int mouseY){
	
	for(unsigned int i=0; i<26 ;i++){
		if(mouseX<get<0>(references.at(i))+LETTER_WIDTH && mouseX>get<0>(references.at(i)) && mouseY<get<1>(references.at(i))+LETTER_HEIGHT && mouseY>get<1>(references.at(i))){
			
			currentLetter=get<2>(references.at(i));//gets char associated with image

			cout<<"You clicked on a letter!"<<endl;
			cout<<"Letter clicked: "<<currentLetter<<endl;
			return true;
		}
	}
	return false;
}

void MouseButton(int button, int state, int x, int y)
{
	 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouseClicked=true;
		for(unsigned int i=0; i<references.size(); i++){
			cout<<"Letter: "<<get<2>(references.at(i))<<"   X: "<<get<0>(references.at(i))<<"   Y: "<<get<1>(references.at(i))<<endl;
		}
		cout<<references.size()<<endl;
		mouseCoordinates(x,window_height-y);
		cout<<"Mouse X: "<<x<<"      Mouse Y: "<<600-y<<endl;
	}
}

void Reshape(GLint width, GLint height){
	window_width=width;
	window_height=height;
}

void draw(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, window_width, 0.0, window_height);
    glMatrixMode(GL_MODELVIEW);
 
	glPushMatrix();

	drawBackground();

	if(!boardLoaded)
		InitBoard();
	
	UpdateBoard();
	loadKeyBoard();
	drawHanger();

	glPopMatrix();
    
	glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);
	loadHint();

	checkGameState();
	
	if(mouseClicked==true){

		clickedOnKeyBoard = letterClick(get<0>(mouseCoords),get<1>(mouseCoords));

		if(clickedOnKeyBoard){// && !letterAlreadyGuessed){

			//checkLetterGuessed();//

			for(unsigned int i=0; i<word.size();i++){
				if(word.at(i)==currentLetter){
					guessed=true;
					indexes=h->getCharOcorrences(currentLetter);
					sucess+=h->getCharOcorrences(currentLetter).size();
					guessedLetters.push_back(currentLetter);//
					UpdateBoard();
					PlaySound(TEXT("Sounds\\sucess1.wav"), NULL, SND_FILENAME);
					
					for(int i=0;i<guessedLetters.size();i++){
						cout<<guessedLetters.at(i); 
					}
					
					cout<<endl;
					
					break;
				}
			}

			if(!guessed){
				indexes=h->getCharOcorrences(currentLetter);
				wrong++;
				PlaySound(TEXT("Sounds\\wrong1.wav"), NULL, SND_FILENAME);
			}
			
			cout<<"Ocorrences of "<<currentLetter<<": "<<indexes.size()<<endl;
			cout<<"Guessed: "<<sucess<<endl;
			cout<<"Wrong: "<<wrong<<endl;
			mouseClicked=false;
			guessed=false;
		}
	}

	switch(wrong){

		case 1:
			drawHead();
			glutPostRedisplay();
			break;

		case 2:
			drawHead();
			drawBody();
			glutPostRedisplay();
			break;

		case 3:
			drawHead();
			drawBody();
			drawLeftArm();
			glutPostRedisplay();
			break;

		case 4:
			drawHead();
			drawBody();
			drawLeftArm();
			drawRigthArm();
			glutPostRedisplay();
			break;

		case 5:
			drawHead();
			drawBody();
			drawLeftArm();
			drawRigthArm();
			drawLeftLeg();
			glutPostRedisplay();
			break;

		case 6:
			drawHead();
			drawBody();
			drawLeftArm();
			drawRigthArm();
			drawLeftLeg();
			drawRigthLeg();
			glutPostRedisplay();
			break;

		default:
			break;
	}

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
	glutSwapBuffers();
    glutPostRedisplay();
}

void playMusic(int value){
	PlaySound(TEXT("Sounds\\background.wav"), NULL, SND_FILENAME);
}

int main(int argc, char **argv) {
	
    // init GLUT and create Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
	glutInitWindowSize(window_width, window_height);
    glutCreateWindow("HangMan");
    // register callbacks
    glutDisplayFunc(draw);
	glutReshapeFunc(Reshape);
	glutMouseFunc(MouseButton);

    // enter GLUT event processing cycle
    glutMainLoop();
    return 1;
}