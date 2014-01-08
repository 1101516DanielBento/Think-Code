#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>
#include <iostream>
#include <string>
#include "grafos.h"
#include "Camera.h"
#include "Estado.h"
#include "Modelo.h"
#include "Teclas.h"
#include "Objecto.h"
using namespace std;

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
/*
 #ifdef _WIN32
 #include <GL/glaux.h>
 #endif*/

typedef struct vecCol{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}vecCol;

vecCol colisao[100];

std::vector<std::vector<GLfloat>> PosTodosUsers;


using namespace std;

#define graus(X) (double)((X)*180/M_PI)
#define rad(X)   (double)((X)*M_PI/180)
#define K_ESFERA 4.0
#define VELv 0.5

#define CAMERA_LIVRE 1
#define CAMERA_RASANTE 2

#define EIXO_X		1
#define EIXO_Y		2
#define EIXO_Z		3


//#define RAND_MAX

// luzes e materiais

const GLfloat mat_ambient[][4] = {{0.33, 0.22, 0.03, 1.0},	// brass
	{0.0, 0.0, 0.0},			// red plastic
	{0.0215, 0.1745, 0.0215},	// emerald
	{0.02, 0.02, 0.02},		// slate
	{0.0, 0.0, 0.1745},		// azul
	{0.02, 0.02, 0.02},		// preto
	{0.1745, 0.1745, 0.1745}};// cinza

const GLfloat mat_diffuse[][4] = {{0.78, 0.57, 0.11, 1.0},		// brass
	{0.5, 0.0, 0.0},				// red plastic
	{0.07568, 0.61424, 0.07568},	// emerald
	{0.78, 0.78, 0.78},			// slate
	{0.0, 0.0,  0.61424},			// azul
	{0.08, 0.08, 0.08},			// preto
	{0.61424, 0.61424, 0.61424}};	// cinza

const GLfloat mat_specular[][4] = {{0.99, 0.91, 0.81, 1.0},			// brass
	{0.7, 0.6, 0.6},					// red plastic
	{0.633, 0.727811, 0.633},		// emerald
	{0.14, 0.14, 0.14},				// slate
	{0.0, 0.0, 0.727811},			// azul
	{0.03, 0.03, 0.03},				// preto
	{0.727811, 0.727811, 0.727811}};	// cinza

const GLfloat mat_shininess[] = {27.8,	// brass
	32.0,	// red plastic
	76.8,	// emerald
	18.78,	// slate
	30.0,	// azul
	75.0,	// preto
	60.0};	// cinza

enum tipo_material {brass, red_plastic, emerald, slate, azul, preto, cinza};

#ifdef __cplusplus
inline tipo_material operator++(tipo_material &rs, int ) {
	return rs = (tipo_material)(rs + 1);
}
#endif

typedef	GLdouble Vertice[3];
typedef	GLdouble Vector[4];

//Vertice center[];

/*typedef struct {
 GLboolean   q,a,up,down,left,right;
 }Teclas;*/

typedef struct pos_t{
    GLfloat    x,y,z;
}pos_t;

typedef struct objecto_t{
    pos_t    pos;
    GLfloat  dir;
    GLfloat  vel;
}objecto_t;
/*
 typedef struct Camera{
 GLfloat fov;
 GLdouble dir_lat;
 GLdouble dir_long;
 GLfloat dist;
 Vertice center;
 
 }Camera;*/

/*typedef struct Estado{
 Camera		*camera;
 GLint         timer;
 Teclas		teclas;
 int			xMouse,yMouse;
 GLboolean	light;
 GLboolean   debug;
 GLboolean	apresentaNormais;
 GLint		lightViewer;
 GLint		eixoTranslaccao;
 GLdouble	eixo[3];
 }Estado;*/

/*typedef struct Modelo {
 objecto_t objecto;
 
 GLfloat g_pos_luz1[4];
 GLfloat g_pos_luz2[4];
 
 GLfloat escala;
 GLUquadric *quad;
 }Modelo;*/

Estado *estado = new Estado();
Modelo *modelo = new Modelo();
Teclas *teclas = new Teclas();

void initEstado(){
	estado->getCamera()->setDirLat(graus(M_PI/4));
	estado->getCamera()->setDirLong(graus(-M_PI/4));
	estado->getCamera()->setFov(60);
	estado->getCamera()->setDistance(100);
	//estado.camera.velh = 1.0;
	estado->getCamera()->setVelv(5.0);
	//estado.camera.velTotal = estado.camera.velh + estado.camera.velv;
	estado->setEixo(0, 0, 0);
	/*center[0]=0;
	 center[1]=0;
	 center[2]=0;*/
	estado->getCamera()->setCenterX(0);
	estado->getCamera()->setCenterY(0);
	estado->getCamera()->setCenterZ(0);
	estado->setLight(GL_TRUE);
	estado->setApresentaNormais(GL_TRUE);
	estado->setLightViewer(1);
	estado->setTimer(100);
	
	//coordenadas do objecto
	/*modelo.objecto.pos.x=90;
	 modelo.objecto.pos.y=80;
	 modelo.objecto.pos.z=50;*/
	
	modelo->getObjecto()->setX(nos[0].x);
	modelo->getObjecto()->setY(nos[0].y);
	modelo->getObjecto()->setZ(nos[0].z);
	
	
}

void initModelo()
{
	GLfloat *l1 = new GLfloat[4];
	l1[0] = -5.0;
	l1[1] = 5.0;
	l1[2] = 5.0;
	l1[3] = 0.0;
	
	GLfloat *l2 = new GLfloat[4];
	l2[0] = 5.0;
	l2[1] = -15.0;
	l2[2] = 5.0;
	l2[3] = 0.0;
	
	//modelo->getObjecto()->setVel(2.0);
	modelo->setEscala(0.2);
	modelo->setGPosLuz1(l1);
	modelo->setGPosLuz2(l2);
	modelo->setCameraMode(1);
	//modelo->getObjecto()->setDir(estado->getCamera()->getDirLong());
}


void myInit()
{
	
	GLfloat LuzAmbiente[]={0.5,0.5,0.5, 0.0};
	estado->setOrtho(GL_FALSE);
	estado->setTimer(100);
	
	//glClearColor (0.0, 0.0, 0.0, 0.0);
	
	glEnable(GL_SMOOTH); /*enable smooth shading */
	glEnable(GL_LIGHTING); /* enable lighting */
	glEnable(GL_DEPTH_TEST); /* enable z buffer */
	glEnable(GL_NORMALIZE);
	
	glDepthFunc(GL_LESS);
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzAmbiente);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado->getLightViewer());
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	
	initModelo();
	//initEstado();
	
	modelo->setQuad(gluNewQuadric());
	gluQuadricDrawStyle(modelo->getQuad(),GLU_FILL);
	gluQuadricNormals(modelo->getQuad(), GLU_OUTSIDE);
	
	
	//le o grafo exemplo
	leGrafo();
	
	modelo->getObjecto()->setX(nos[0].x);
	modelo->getObjecto()->setY(nos[0].z);
	modelo->getObjecto()->setZ(nos[0].y);
	
	//por varaiaveis de teste
}

void imprime_ajuda(void)
{
	printf("\n\nDesenho de um labirinto a partir de um grafo\n");
	printf("h,H - Ajuda \n");
	printf("i,I - Reset dos Valores \n");
	printf("******* Diversos ******* \n");
	printf("l,L - Alterna o calculo luz entre Z e eye (GL_LIGHT_MODEL_LOCAL_VIEWER)\n");
	printf("k,K - Alerna luz de camera com luz global \n");
	printf("s,S - PolygonMode Fill \n");
	printf("w,W - PolygonMode Wireframe \n");
	printf("p,P - PolygonMode Point \n");
	printf("c,C - Liga/Desliga Cull Face \n");
	printf("n,N - Liga/Desliga apresenta?o das normais \n");
	printf("******* grafos ******* \n");
	printf("F1  - Grava grafo do ficheiro \n");
	printf("F2  - L grafo para ficheiro \n");
	printf("F6  - Cria novo grafo\n");
	printf("******* Camera ******* \n");
	printf("Bot?o esquerdo - Arrastar os eixos (centro da camera)\n");
	printf("Bot?o direito  - Rodar camera\n");
	printf("Bot?o direito com CTRL - Zoom-in/out\n");
	printf("PAGE_UP, PAGE_DOWN - Altera dist?ncia da camara \n");
	printf("ESC - Sair\n");
}


void material(enum tipo_material mat)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient[mat]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse[mat]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular[mat]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess[mat]);
}

const GLfloat red_light[] = {1.0, 0.0, 0.0, 1.0};
const GLfloat green_light[] = {0.0, 1.0, 0.0, 1.0};
const GLfloat blue_light[] = {0.0, 0.0, 1.0, 1.0};
const GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};


void putLights(GLfloat* diffuse)
{
	const GLfloat white_amb[] = {0.2, 0.2, 0.2, 1.0};
	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_amb);
	glLightfv(GL_LIGHT0, GL_POSITION, modelo->getGPosLuz1());
	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white_amb);
	glLightfv(GL_LIGHT1, GL_POSITION, modelo->getGPosLuz2());
	
	/* desenhar luz */
	//material(red_plastic);
	//glPushMatrix();
	//	glTranslatef(modelo.g_pos_luz1[0], modelo.g_pos_luz1[1], modelo.g_pos_luz1[2]);
	//	glDisable(GL_LIGHTING);
	//	glColor3f(1.0, 1.0, 1.0);
	//	glutSolidCube(0.1);
	//	glEnable(GL_LIGHTING);
	//glPopMatrix();
	//glPushMatrix();
	//	glTranslatef(modelo.g_pos_luz2[0], modelo.g_pos_luz2[1], modelo.g_pos_luz2[2]);
	//	glDisable(GL_LIGHTING);
	//	glColor3f(1.0, 1.0, 1.0);
	//	glutSolidCube(0.1);
	//	glEnable(GL_LIGHTING);
	//glPopMatrix();
	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

void desenhaSolo(){
	/*#define STEP 10
	 glBegin(GL_QUADS);
	 glNormal3f(0,0,1);
	 for(int i=-300;i<300;i+=STEP)
	 for(int j=-300;j<300;j+=STEP){
	 glVertex2f(i,j);
	 glVertex2f(i+STEP,j);
	 glVertex2f(i+STEP,j+STEP);
	 glVertex2f(i,j+STEP);
	 }
	 glEnd();*/
	glPushMatrix();
	glTranslatef(-275,-275,-5);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2f(0,0);
	glVertex2f(0,0);
	glTexCoord2f(0,1);
	glVertex2f(0,550);
	glTexCoord2f(1,1);
	glVertex2f(550,550);
	glTexCoord2f(1,0);
	glVertex2f(550,0);
	glEnd();
	glPopMatrix();
}

void CrossProduct (GLdouble v1[], GLdouble v2[], GLdouble cross[])
{
	cross[0] = v1[1]*v2[2] - v1[2]*v2[1];
	cross[1] = v1[2]*v2[0] - v1[0]*v2[2];
	cross[2] = v1[0]*v2[1] - v1[1]*v2[0];
}

GLdouble VectorNormalize (GLdouble v[])
{
	int		i;
	GLdouble	length;
	
	if ( fabs(v[1] - 0.000215956) < 0.0001)
		i=1;
	
	length = 0;
	for (i=0 ; i< 3 ; i++)
		length += v[i]*v[i];
	length = sqrt (length);
	if (length == 0)
		return 0;
	
	for (i=0 ; i< 3 ; i++)
		v[i] /= length;
	
	return length;
}

void desenhaNormal(GLdouble x, GLdouble y, GLdouble z, GLdouble normal[], tipo_material mat){
	
	switch (mat){
		case red_plastic:
			glColor3f(1,0,0);
			break;
		case azul:
			glColor3f(0,0,1);
			break;
		case emerald:
			glColor3f(0,1,0);
			break;
		default:
			glColor3f(1,1,0);
	}
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(0.4,0.4,0.4);
	glBegin(GL_LINES);
	glVertex3d(0,0,0);
	glVertex3dv(normal);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void distribuicaoNos()
{
	srand((unsigned)time(0));
	GLfloat floor=-30.0, ceiling=30.0;//mais alto e mais baixo
	GLfloat range=(ceiling-floor)+1.0;
	GLfloat floor2 = 2.0,ceiling2 = 4.0;
	GLfloat range2=(ceiling2-floor2)+5.0;
	
	for(int i =0; i < 8/*alterar para num utilizadores*/;i++)
	{
		vector<GLfloat> aux3;
		
		GLfloat random_x = floor+int(range*rand()/(RAND_MAX +1.0));
		GLfloat random_y = floor+int(range*rand()/(RAND_MAX+1.0));
		GLfloat random_z = floor2+int(range2*rand()/(RAND_MAX+1.0));
		
		colisao[i].x = random_x;
		colisao[i].y = random_y;
		colisao[i].z = random_z;
		
		aux3.push_back(random_x);
		aux3.push_back(random_y);
		aux3.push_back(random_z);
		
		PosTodosUsers.push_back(aux3);
		aux3.pop_back();
	}
}


void desenhaCilindro(GLfloat xi,GLfloat yi,GLfloat zi,GLfloat xf,GLfloat yf, GLfloat zf,GLfloat raio)
{
	GLfloat vx = xf-xi;
	GLfloat vy = yf-yi;
	GLfloat vz = zf-zi;
	GLfloat comp = sqrt(vx*vx + vy*vy + vz*vz);
	GLfloat ax,rx,ry,rz,raio_c;
	raio_c = raio/2.0;
	glPushMatrix();
	
	glTranslatef(xi,yi,zi);
	//glRotatef(graus(orientacao),0,0,1);
	//glRotatef(graus(inclinacao),0,1,0);
	if(fabs(vz) < 0.0001)
	{
		glRotatef(90,0,1,0);
		ax = 57.2957795*-atan2(vy,vx);
		if(vx < 0)
		{
			ax = ax + 180;
		}
		rx = 1;
		ry = 0;
		rz = 0;
	}else{
		ax = 57.2957795*acos(vz/comp);
		if(vz < 0.0){
			ax = -ax;
		}
		rx = -vy*vz;
		ry = vx*vz;
		rz = 0;
	}
	glRotatef(ax, rx, ry, rz);
	gluQuadricOrientation(modelo->getQuad(),GLU_OUTSIDE);
	gluCylinder(modelo->getQuad(), raio_c, raio_c, comp, 20, 1);//normal é desenhada automaticamente pela funcao
	glPopMatrix();
	
}

/*void Caminho()
 {
 //GLUquadricObj *obj = gluNewQuadric();
 
 desenhaCilindro(PosTodosUsers[0][0],PosTodosUsers[0][1],PosTodosUsers[0][2],PosTodosUsers[1][0],PosTodosUsers[1][1],PosTodosUsers[1][2],3.0);
 }*/

void desenhaLigacao(Arco arco)
{
	Nos *noi,*nof;
	//GLdouble desnivel, comprimentoProj, comprimento,raio,orientacao,inclinacao;
	
	if(nos[arco.noi].x==nos[arco.nof].x){
		// arco vertical
		if(nos[arco.noi].y<nos[arco.nof].y){
			noi=&nos[arco.noi];
			nof=&nos[arco.nof];
		}else{
			nof=&nos[arco.noi];
			noi=&nos[arco.nof];
		}
		material(red_plastic);
		desenhaCilindro(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z,noi->largura);
		
	}else{
		if(nos[arco.noi].y==nos[arco.nof].y){
			//arco horizontal
			if(nos[arco.noi].x<nos[arco.nof].x){
				noi=&nos[arco.noi];
				nof=&nos[arco.nof];
			}else{
				nof=&nos[arco.noi];
				noi=&nos[arco.nof];
			}
			desenhaCilindro(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z,noi->largura);
		}else{
			noi=&nos[arco.noi];
			nof=&nos[arco.nof];
			material(red_plastic);
			desenhaCilindro(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z,noi->largura);
			
			
		}
	}
}

void desenhaNos()
{
	for(int i = 0; i < numNos; i++)
	{
		glPushMatrix();
		material(red_plastic);
		glTranslatef(nos[i].x,nos[i].y,nos[i].z);
		glutSolidSphere((K_ESFERA/2),20,20);
		glPopMatrix();
	}
}


void desenhaLabirinto(){
	GLfloat xi,yi,zi,xf,yf,zf,raio;
	glPushMatrix();
	glTranslatef(0,0,0.05);
	//glScalef(5,5,5);
	
	/*for(int i=0; i<numNos; i++){
	 glPushMatrix();
	 material(red_plastic);
	 glTranslatef(nos[i].x,nos[i].y,nos[i].z);
	 //glutSolidCube(0.5);
	 glutSolidSphere((K_ESFERA/2.0),20,20);
	 glPopMatrix();
	 //desenhaNo(i);
	 */
	desenhaNos();
	//material(emerald);
	for(int i=0; i<numArcos; i++){
		desenhaLigacao(arcos[i]);
		//Caminho();
	}
	glPopMatrix();
}

void desenhaEixo(){
	gluCylinder(modelo->getQuad(),0.5,0.5,20,16,15);
	glPushMatrix();
	glTranslatef(0,0,20);
	glPushMatrix();
	glRotatef(180,0,1,0);
	gluDisk(modelo->getQuad(),0.5,2,16,6);
	glPopMatrix();
	gluCylinder(modelo->getQuad(),2,0,5,16,15);
	glPopMatrix();
}

void desenhaPlanoDrag(int eixo){
	glPushMatrix();
	glTranslated(estado->getEixoX(),estado->getEixoY(),estado->getEixoZ());
	switch (eixo) {
		case EIXO_Y :
			if(abs(estado->getCamera()->getDirLat())<M_PI/4)
				glRotatef(-90,0,0,1);
			else
				glRotatef(90,1,0,0);
			material(red_plastic);
			break;
		case EIXO_X :
			if(abs(estado->getCamera()->getDirLat())>M_PI/6)
				glRotatef(90,1,0,0);
			material(azul);
			break;
		case EIXO_Z :
			if(abs(cos(estado->getCamera()->getDirLong()))>0.5)
				glRotatef(90,0,0,1);
			
			material(emerald);
			break;
	}
	/*glBegin(GL_QUADS);
	 glNormal3f(0,1,0);
	 glVertex3f(-100,0,-100);
	 glVertex3f(100,0,-100);
	 glVertex3f(100,0,100);
	 glVertex3f(-100,0,100);
	 glEnd();
	 glPopMatrix();*/
}

void desenhaEixos(){
	
	glPushMatrix();
	glTranslated(estado->getEixoX(),estado->getEixoY(),estado->getEixoZ());
	material(emerald);
	glPushName(EIXO_Z);
	desenhaEixo();
	glPopName();
	glPushName(EIXO_Y);
	glPushMatrix();
	glRotatef(-90,1,0,0);
	material(red_plastic);
	desenhaEixo();
	glPopMatrix();
	glPopName();
	glPushName(EIXO_X);
	glPushMatrix();
	glRotatef(90,0,1,0);
	material(azul);
	desenhaEixo();
	glPopMatrix();
	glPopName();
	glPopMatrix();
}

void setCamera(){
	
	
	/*if(estado->getLight()){
	 //Posicionar a c?mera
	 glRotatef(graus(-M_PI/2.0), 1, 0, 0);
	 glRotatef(graus(M_PI/2.0-modelo->getObjecto()->getDir()), 0, 0, 1);
	 glTranslatef(-modelo->getObjecto()->getX(), -modelo->getObjecto()->getY(), -modelo->getObjecto()->getZ()-5);
	 //glTranslatef(-nos[0].x,-nos[0].y,-nos[0].z-5);
	 
	 putLights((GLfloat*)white_light);
	 }else{
	 //Posicionar a c?mera
	 putLights((GLfloat*)white_light);
	 glRotatef(graus(-M_PI/2.0), 1, 0, 0);
	 glRotatef(graus(M_PI/2.0-modelo->getObjecto()->getDir())-90, 0, 0, 1);
	 glTranslatef(-modelo->getObjecto()->getX(), -modelo->getObjecto()->getY(), -modelo->getObjecto()->getZ()-5);
	 estado->getCamera()->setCenterX(modelo->getObjecto()->getX() + cos(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	 estado->getCamera()->setCenterY(modelo->getObjecto()->getY() - sin(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	 estado->getCamera()->setCenterZ(modelo->getObjecto()->getZ() + 2 + sin(estado->getCamera()->getDirLat()));
	 //glTranslatef(-nos[0].x,-nos[0].y,-nos[0].z-5);
	 
	 /*gluLookAt(modelo->getObjecto()->getX(),modelo->getObjecto()->getY(),modelo->getObjecto()->getZ()+2,
	 estado->getCamera()->getCenterX(),estado->getCamera()->getCenterY(),estado->getCamera()->getCenterZ(),
	 0,0,1);*/
	/*estado->getCamera()->drawMe();
	 
	 }*/
	
	estado->getCamera()->setCenterX(modelo->getObjecto()->getX() + cos(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	estado->getCamera()->setCenterY(modelo->getObjecto()->getZ() - sin(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	estado->getCamera()->setCenterZ(modelo->getObjecto()->getY() + 2 + sin(estado->getCamera()->getDirLat()));
	
	putLights((GLfloat*)white_light);
	
	gluLookAt(modelo->getObjecto()->getX(), modelo->getObjecto()->getZ(), modelo->getObjecto()->getY() + 2 ,
			  estado->getCamera()->getCenterX() , estado->getCamera()->getCenterY() , estado->getCamera()->getCenterZ() ,
			  //modelo->getObjecto()->getX()+2,modelo->getObjecto()->getZ()+2 , modelo->getObjecto()->getY() + 2 ,
			  0,0,1);
	
	
}

void display(void)
{
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	/*modelo.objecto.pos.x = nos[0].x;
	 modelo.objecto.pos.y = nos[0].y;
	 modelo.objecto.pos.z = nos[0].z;*/
	setCamera();
	//material(slate);
	
	desenhaSolo();
	
	desenhaEixos();
	
	desenhaLabirinto();
	
	//setCamera();
	
	if(estado->getEixoTrans()) {
		// desenha plano de translacção
		cout << "Translate... " << estado->getEixoTrans() << endl;
		desenhaPlanoDrag(estado->getEixoTrans());
		
	}
	
	glFlush();
	glutSwapBuffers();
	
}
//detecta colisao esfera
bool detectaColisoes(GLfloat nx, GLfloat ny, GLfloat nz)
{
	int compUsers = numNos;
	int compLigacoes = numArcos;
	
	GLfloat raio = K_ESFERA/2.0;
	GLfloat d;
	
	for(int i = 1; i < compUsers; i++)
	{
		d = sqrt(((nx - nos[i].x)*(nx - nos[i].x)+((ny - nos[i].y)*(ny - nos[i].y))+((nz - nos[i].z)*(nz - nos[i].z))));
		
		if(d <= (raio))
		{
			return false;
		}
	}
	return true;
}

//detecta colisao ligacao

bool detectaColisoesLigacoes(GLfloat nx, GLfloat ny, GLfloat nz)
{
	bool flag = true;
	int noi, nof;
	int compLigacoes = numArcos;
	int compUsers = numNos;
	glLoadIdentity();
	for(int i = 1; i <= compLigacoes; i++)
	{
		//exemplo adaptar para Arcos e Nos
		//encontra o arco
		//encontra o no
		noi = arcos[i].noi;
		nof = arcos[i].nof;
		
		//encontra noi e nof para fazer a ponte entre os dois
		//lista de utilizadores
		//convem fazer uma classe Utilizador
		
		
		//nao tenho a certeza
		GLdouble larg = arcos[i].largura+0.4;
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(modelo->getObjecto()->getX(),modelo->getObjecto()->getY(),modelo->getObjecto()->getZ());
		GLdouble angOrientacao = graus(atan2(ny-modelo->getObjecto()->getY(),nx-modelo->getObjecto()->getX()));
		GLdouble catetoOposto = nz - modelo->getObjecto()->getZ();
		GLdouble tamanho = sqrt(pow((nx-modelo->getObjecto()->getZ()),2)+pow((ny-modelo->getObjecto()->getZ()),2));
		GLdouble angInclinacao = graus(atan2(catetoOposto,tamanho));
		glRotated(angOrientacao,0,0,1);
		GLdouble nx2 = (nx - modelo->getObjecto()->getX())*cos(rad(angOrientacao)) + (nz - modelo->getObjecto()->getZ())*sin(rad(angOrientacao));
		GLdouble ny2 = (nz - modelo->getObjecto()->getZ())*cos(rad(angOrientacao)) - (nx - modelo->getObjecto()->getX())*sin(rad(angOrientacao));
		GLdouble dist = sqrt(pow(nx -modelo->getObjecto()->getX(),2) + pow(ny - modelo->getObjecto()->getY(),2) + pow(nz - modelo->getObjecto()->getZ(),2));
		GLdouble nz2 = modelo->getObjecto()->getZ() + nx2/tamanho*catetoOposto;
		
		if((0 <= nx2 && nx2 <= tamanho) && (-larg/2.0 <= ny2 && ny2 <= larg/2.0) && (nz2 - (larg/2.0+0.1) <= ny && ny <= ny2 + (larg/2.0+0.1)))
		{
			flag = false;
		}
		glPopMatrix();
	}
	return flag;
}

void Timer(int value)
{
	
	printf("\nEntrou no Timer");
	glutTimerFunc(estado->getTimer(), Timer, 0);
	
	GLfloat x1,y1,z1,x2,y2,z2;
	
	x2 = modelo->getObjecto()->getX() + VELv*cos(modelo->getObjecto()->getDir());
	y2 = modelo->getObjecto()->getY() + VELv*sin(modelo->getObjecto()->getDir());
	x1 = modelo->getObjecto()->getX();
	y1 = modelo->getObjecto()->getY();
	GLfloat dist = pow((x2 - x1),2) + pow((y2 - y1),2);
	GLfloat raio = pow((K_ESFERA/2.0),2);
	
	if(teclas->getQ())
	{
		modelo->getObjecto()->setY(modelo->getObjecto()->getY()+VELv);
		teclas->setQ(GL_FALSE);
	}
	if(teclas->getA())
	{
		modelo->getObjecto()->setY(modelo->getObjecto()->getY()-VELv);
		teclas->setA(GL_FALSE);
	}
	if(teclas->getLEFT())
	{
		//modelo->getObjecto()->setDir(modelo->getObjecto()->getDir()-0.1);
		modelo->getObjecto()->setDir(estado->getCamera()->getDirLong() - 0.1);
		estado->getCamera()->setDirLong(estado->getCamera()->getDirLong() - 0.1);
	}
	
	if(teclas->getRIGHT())
	{
		//modelo->getObjecto()->setDir(modelo->getObjecto()->getDir()+0.1);
		modelo->getObjecto()->setDir(estado->getCamera()->getDirLong()+0.1);
		estado->getCamera()->setDirLong(estado->getCamera()->getDirLong()+0.1);
	}
	
	if(teclas->getUP())
	{
		//if(dist <= raio)
		//{
		//modelo->getObjecto()->setX(modelo->getObjecto()->getX()+VELv*cos(modelo->getObjecto()->getDir()));
		//modelo->getObjecto()->setY(modelo->getObjecto()->getY()+VELv*sin(modelo->getObjecto()->getDir()));
		//}
		if(detectaColisoes(modelo->getObjecto()->getX(),modelo->getObjecto()->getZ(),modelo->getObjecto()->getY()))
		{
			modelo->getObjecto()->setX(modelo->getObjecto()->getX() + cos(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
			modelo->getObjecto()->setZ(modelo->getObjecto()->getZ() + sin(-modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
		}
	}
	
	if(teclas->getDOWN())
	{
		//modelo->getObjecto()->setX(modelo->getObjecto()->getX()-VELv*cos(modelo->getObjecto()->getDir()));
		//modelo->getObjecto()->setY(modelo->getObjecto()->getY()-VELv*sin(modelo->getObjecto()->getDir()));
		if(detectaColisoes(modelo->getObjecto()->getX(),modelo->getObjecto()->getZ(),modelo->getObjecto()->getY()))
		{
			modelo->getObjecto()->setX(modelo->getObjecto()->getX() - cos(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
			modelo->getObjecto()->setZ(modelo->getObjecto()->getZ() - sin(-modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
		}
	}
	
	//if(teclas->getR())
	//{
	//modelo->setCameraMode(CAMERA_RASANTE);
	//modelo->getObjecto()->setX(/*u->getPoint()->getX()+0.1*/nos[0].x + 0.1);
	//modelo->getObjecto()->setY(/*u->getPoint()->getZ()+u->getDimEsfera()-2*/nos[0].y + 0.1);
	//modelo->getObjecto()->setZ(/*u->getPoint()->getY()+0.1*/nos[0].z - 2);
	//}
	
	/*if(teclas->getV())
	 {
	 modelo->setCameraMode(CAMERA_LIVRE);
	 modelo->setObjecto(new Objecto());
	 estado->getCamera()->setDirLat(0);
	 estado->getCamera()->setDirLong(0);
	 estado->getCamera()->setFov(30);
	 estado->getCamera()->setDistance(100);
	 estado->getCamera()->setEyeX(40);
	 estado->getCamera()->setEyeY(40);
	 estado->getCamera()->setEyeZ(0);
	 estado->getCamera()->setCenterX(nos[0].x);
	 estado->getCamera()->setCenterY(nos[0].y);
	 estado->getCamera()->setCenterZ(nos[0].z);
	 }*/
	
	if(estado->getDebug())
		printf("Velocidade %.2f \n",modelo->getObjecto()->getVel());
	
	glutPostRedisplay();
}



void keyboard(unsigned char key, int x, int y)
{
	
    switch (key)
    {
		case 27 :
			exit(0);
			break;
		case 'h':
		case 'H':
			imprime_ajuda();
			break;
		case 'l':
		case 'L':
			if(estado->getLightViewer())
				estado->setLightViewer(0);
			else
				estado->setLightViewer(1);
			glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado->getLightViewer());
			glutPostRedisplay();
			break;
		case 'k':
		case 'K':
			estado->setLight(!estado->getLight());
			glutPostRedisplay();
			break;
		case 'w':
		case 'W':
			glDisable(GL_LIGHTING);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glutPostRedisplay();
			break;
		case 'p':
		case 'P':
			glDisable(GL_LIGHTING);
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			glutPostRedisplay();
			break;
		case 's':
		case 'S':
			glEnable(GL_LIGHTING);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glutPostRedisplay();
			break;
		case 'c':
		case 'C':
			if(glIsEnabled(GL_CULL_FACE))
				glDisable(GL_CULL_FACE);
			else
				glEnable(GL_CULL_FACE);
			glutPostRedisplay();
			break;
		case 'n':
		case 'N':
			estado->setApresentaNormais(!estado->getApresentaNormais());
			glutPostRedisplay();
			break;
		case 'i':
		case 'I':
			//initEstado();
			initModelo();
			glutPostRedisplay();
			break;
		case 'a':
		case 'A':
			teclas->setA(GL_TRUE);
			//estado.camera.center[2]-=0.2;
			printf("carregou no a\n");
			break;
		case 'q':
		case 'Q':
			teclas->setQ(GL_TRUE);
			//estado.camera.center[2]+=0.2;
			break;
		case 'r':
		case 'R':
			teclas->setR(GL_TRUE);
			break;
		case 'v':
		case 'V':
			teclas->setV(GL_TRUE);
			break;
	}
	if(estado->getDebug())
		printf("Carregou na tecla %c\n",key);
	
}

// Callback para interaccao via teclado (largar a tecla)
void KeyUp(unsigned char key, int x, int y)
{
	switch (key) {
			// ... accoes sobre largar teclas ...
			
		case 'Q' :
		case 'q' : teclas->setQ(GL_FALSE);
			break;
		case 'A' :
		case 'a' : teclas->setA(GL_FALSE);
			break;
			
	}
	
	if(estado->getDebug())
		printf("Largou a tecla %c\n",key);
}

// Callback para interaccao via teclas especiais  (carregar na tecla)

void SpecialKey(int key, int x, int y){
	
	switch(key){
		case GLUT_KEY_F1 :
			gravaGrafo();
			break;
		case GLUT_KEY_F2 :
			leGrafo();
			glutPostRedisplay();
			break;
			
		case GLUT_KEY_F6 :
			numNos=numArcos=0;
			addNo(criaNo( 0, 10,0));  // 0
			addNo(criaNo( 0,  5,0));  // 1
			addNo(criaNo(-5,  5,0));  // 2
			addNo(criaNo( 5,  5,0));  // 3
			addNo(criaNo(-5,  0,0));  // 4
			addNo(criaNo( 5,  0,0));  // 5
			addNo(criaNo(-5, -5,0));  // 6
			addArco(criaArco(0,1,1,1));  // 0 - 1
			addArco(criaArco(1,2,1,1));  // 1 - 2
			addArco(criaArco(1,3,1,1));  // 1 - 3
			addArco(criaArco(2,4,1,1));  // 2 - 4
			addArco(criaArco(3,5,1,1));  // 3 - 5
			addArco(criaArco(4,5,1,1));  // 4 - 5
			addArco(criaArco(4,6,1,1));  // 4 - 6
			glutPostRedisplay();
			break;
			
		case GLUT_KEY_RIGHT :
			teclas->setRIGHT(GL_TRUE);
			break;
		case GLUT_KEY_LEFT :
			teclas->setLEFT(GL_TRUE);
			break;
		case GLUT_KEY_UP :
			teclas->setUP(GL_TRUE);
			break;
		case GLUT_KEY_DOWN :
			teclas->setDOWN(GL_TRUE);
			break;
	}
	
	
	if(estado->getDebug())
		printf("Carregou na tecla especial %d\n",key);
	
	
}

void SpecialKeyUp(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_RIGHT :
			teclas->setRIGHT(GL_FALSE);
			break;
		case GLUT_KEY_LEFT :
			teclas->setLEFT(GL_FALSE);
			break;
		case GLUT_KEY_UP :
			teclas->setUP(GL_FALSE);
			break;
		case GLUT_KEY_DOWN :
			teclas->setDOWN(GL_FALSE);
			break;
	}
	if(estado->getDebug())
		printf("Largou a tecla especial %d\n",key);
	
}
//biilboard(?) + botao + campos de texto
bool login()
{
	char user1[10], pass[10];
	printf("Username: ");
	cin >> user1;
	printf("Password: ");
	cin >> pass;
	
	//em vez do if ---> webservice para verificar o utilizador, no qual o result sera true ou false
	if(strcmp(user1,"user1") == 0){
		if(strcmp(pass,"qwerty")==0){
			return true;
		}
	}else{
		return false;
	}
	return false;
}

void loginWindow()
{
	bool checkLogin = login();
	if(checkLogin)
	{
		printf("Login efectuado com Sucesso!!\n");
		myInit();
		imprime_ajuda();
	}
	
}

void setProjection(int x, int y, GLboolean picking){
    glLoadIdentity();
	if (picking) { // se está no modo picking, lê viewport e define zona de picking
		GLint vport[4];
		glGetIntegerv(GL_VIEWPORT, vport);
		gluPickMatrix(x, glutGet(GLUT_WINDOW_HEIGHT)  - y, 4, 4, vport); // Inverte o y do rato para corresponder à jana
	}
	
	gluPerspective(estado->getCamera()->getFov(),(GLfloat)glutGet(GLUT_WINDOW_WIDTH) /glutGet(GLUT_WINDOW_HEIGHT) ,1,500);
	
}

void myReshape(int w, int h){
	glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
	setProjection(0,0,GL_FALSE);
	glMatrixMode(GL_MODELVIEW);
}


void motionRotate(int x, int y){
#define DRAG_SCALE	0.01
	double lim=M_PI/2-0.1;
	estado->getCamera()->setDirLong((estado->getXMouse()-x)*DRAG_SCALE);//=(estado->xMouse-x)*DRAG_SCALE;
	estado->getCamera()->setDirLat((estado->getYMouse()-y)*DRAG_SCALE*0.5);//-=(estado->yMouse-y)*DRAG_SCALE*0.5;
	if(estado->getCamera()->getDirLat()>lim)
		estado->getCamera()->setDirLat(lim);
	else
		if(estado->getCamera()->getDirLat()<-lim)
			estado->getCamera()->setDirLat(estado->getCamera()->getDirLat() - lim);//dir_lat=-lim;
	estado->setXMouse(x);
	estado->setYMouse(y);
	glutPostRedisplay();
}

void motionZoom(int x, int y){
#define ZOOM_SCALE	0.5
	//estado.camera.dist-=(estado.yMouse-y)*ZOOM_SCALE;
	estado->getCamera()->setDistance((estado->getYMouse() -y)*ZOOM_SCALE);
	if(estado->getCamera()->getDistance()<5)
		estado->getCamera()->setDistance(5);//dist=5;
	else
		if(estado->getCamera()->getDistance()>200)
			estado->getCamera()->setDistance(200);//dist=200;
	estado->setYMouse(y);
	glutPostRedisplay();
}

void motionDrag(int x, int y){
	GLuint buffer[100];
	GLint vp[4];
	GLdouble proj[16], mv[16];
	int n;
	GLdouble newx, newy, newz;
	
	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); // guarda a projecção
	glLoadIdentity();
	setProjection(x,y,GL_TRUE);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCamera();
	desenhaPlanoDrag(estado->getEixoTrans());
	
	n = glRenderMode(GL_RENDER);
	if (n > 0) {
		glGetIntegerv(GL_VIEWPORT, vp);
		glGetDoublev(GL_PROJECTION_MATRIX, proj);
		glGetDoublev(GL_MODELVIEW_MATRIX, mv);
		gluUnProject(x, glutGet(GLUT_WINDOW_HEIGHT) - y, (double) buffer[2] / UINT_MAX, mv, proj, vp, &newx, &newy, &newz);
		printf("Novo x:%lf, y:%lf, z:%lf\n\n", newx, newy, newz);
		switch (estado->getEixoTrans()) {
			case EIXO_X :
				estado->setEixoX(newx);
				//estado.eixo[1]=newy;
				break;
			case EIXO_Y :
				estado->setEixoY(newy);
				//estado.eixo[2]=newz;
				break;
			case EIXO_Z :
				//estado.eixo[0]=newx;
				estado->setEixoZ(newz);
				break;
		}
		glutPostRedisplay();
	}
	
	
	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

int picking(int x, int y){
	int i, n, objid=0;
	double zmin = 10.0;
	GLuint buffer[100], *ptr;
	
	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); // guarda a projecção
	glLoadIdentity();
	setProjection(x,y,GL_TRUE);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCamera();
	desenhaEixos();
	
	n = glRenderMode(GL_RENDER);
	if (n > 0)
	{
		ptr = buffer;
		for (i = 0; i < n; i++)
		{
			if (zmin > (double) ptr[1] / UINT_MAX) {
				zmin = (double) ptr[1] / UINT_MAX;
				objid = ptr[3];
			}
			ptr += 3 + ptr[0]; // ptr[0] contem o número de nomes (normalmente 1); 3 corresponde a numnomes, zmin e zmax
		}
	}
	
	
	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	
	return objid;
}

void mouse(int btn, int state, int x, int y){
	switch(btn) {
		case GLUT_RIGHT_BUTTON :
			if(state == GLUT_DOWN){
				estado->setXMouse(x);
				estado->setYMouse(y);
				if(glutGetModifiers() & GLUT_ACTIVE_CTRL)
					glutMotionFunc(motionZoom);
				else
					glutMotionFunc(motionRotate);
				cout << "Left down\n";
			}
			else{
				glutMotionFunc(NULL);
				cout << "Left up\n";
			}
			break;
		case GLUT_LEFT_BUTTON :
			if(state == GLUT_DOWN){
				estado->setEixoTrans(picking(x,y));
				if(estado->getEixoTrans())
					glutMotionFunc(motionDrag);
				cout << "Right down - objecto:" << estado->getEixoTrans() << endl;
			}
			else{
				if(estado->getEixoTrans()!=0) {
					estado->getCamera()->setCenterX(estado->getEixoX());//=estado.eixo[0];
					estado->getCamera()->setCenterY(estado->getEixoY());//=estado.eixo[1];
					estado->getCamera()->setCenterZ(estado->getEixoZ());//=estado.eixo[2];
					glutMotionFunc(NULL);
					estado->setEixoTrans(0);//=0;
					glutPostRedisplay();
				}
				cout << "Right up\n";
			}
			break;
	}
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
	
	/* need both double buffering and z buffer */
	
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Think&Code");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	
	
	glutTimerFunc(estado->getTimer(), Timer, 0);
	
	glutKeyboardFunc(keyboard);
	//glutKeyboardFunc(KeyUp);
	glutSpecialFunc(SpecialKey);
	glutSpecialUpFunc(SpecialKeyUp);
	
	glutMouseFunc(mouse);
	
	
	
	
	//loginWindow();
	//myinit + imprime ajuda dentro do login
	
	myInit();
	
	imprime_ajuda();
	
    glutMainLoop();
	
	return 0;
}
