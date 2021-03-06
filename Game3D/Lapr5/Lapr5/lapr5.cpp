#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>
#include <thread>
#include <string>
#include <GL/GLAux.h>
//#include <AL/alut.h>
#include "grafos.h"
#include "Camera.h"
#include "Estado.h"
#include "Modelo.h"
#include "Teclas.h"
#include "Objecto.h"
#include "TextureLoader.h"
//#include "objLoader.h"
#include "WebService_Request.h"
#include "User_C.h"
#include <tuple>
//#include "Dialog.h"

#pragma comment (lib, "glaux.lib")    /* link with Win32 GLAUX lib */
#pragma comment (lib, "openAL32.lib")
#pragma comment (lib, "alut.lib")
#pragma comment (user, "Compiled on " __DATE__ " at " __TIME__)



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

#define graus(X) (double)((X)*180/M_PI)
#define rad(X)   (double)((X)*M_PI/180)

#define K_ESFERA 2.1
#define RAIO_NO 5.0
#define VELv 0.5
#define DIMENSAO_CAMARA 5
#define BUFSIZE 512
#define DISTANCIA_SOLO 1.0
#define WINDOW_SIZE_HEIGHT 600
#define WINDOW_SIZE_WIDTH 800
#define INFINITESIMO 0,0000000000000001
#define NF 20
#define NP 20
#define EYE_ROTATION 0.01


#define CAMERA_LIVRE 1
#define CAMERA_RASANTE 2

#define NOME_FUNDO_SOLO "texturas/bottom.jpg"

#define NOME_FUNDO_FRONT "texturas/front.jpg"
#define NOME_FUNDO_BACK "texturas/back.jpg"
#define NOME_FUNDO_LEFT "texturas/left.jpg"
#define NOME_FUNDO_RIGHT "texturas/right.jpg"
#define NOME_FUNDO_UP "texturas/top.jpg"
#define NOME_FUNDO_DOWN "texturas/bottom.jpg"

//texturas humor
/*
0 - Sem estado de espírito
1 - Furioso
2 - Desanimado
3 - Contente
4 - Entusiasmado
5 - Eufórico
*/

#define NOME_NEUTRO "texturas/estados/semEstado.jpg"
#define NOME_FURIOSO "texturas/estados/Angry.jpg"
#define	NOME_DESANIMADO "texturas/estados/Depressed.jpg"
#define NOME_CONTENTE "texturas/estados/Happy.jpg"
#define NOME_ENTUSIASMADO "texturas/estados/Enthusiastic.jpg"
#define NOME_EUFORICO "texturas/estados/Optimistic.jpg"


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

Estado *estado = new Estado();
Estado *estadominimapa = new Estado();
Modelo *modelo = new Modelo();
Teclas *teclas = new Teclas();
int obj = 0,mainWindow,sw1,gameMode = 0;

vector<tuple<int,vector<tuple<int,string>>,User_C>> *graf = new vector<tuple<int,vector<tuple<int,string>>,User_C>>();


//######################TEXTURAS############

TextureLoader *apTexLoad = new TextureLoader();
glTexture txtNeutro;
glTexture txtFurioso;
glTexture txtDesanimado;
glTexture txtEntusiasmado;
glTexture txtContente;
glTexture txtEuforico;
glTexture txtChateado;
glTexture txtBOTTOM;
glTexture txtTOP;
glTexture txtLEFT;
glTexture txtRIGHT;
glTexture txtFRONT;
glTexture txtBACK;


void CriarTexturas(GLuint texID[])
{

	AUX_RGBImageRec *TextureImage[1];     // Create Storage Space For The Texture
	glGenTextures(NUM_TEXTURAS,texID);
	memset(TextureImage,0,sizeof(void *)*1);            // Set The Pointer To NULL
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	apTexLoad->SetHighQualityTextures(TRUE);
	apTexLoad->SetTextureFilter(txTrilinear);

	apTexLoad->LoadTextureFromDisk(NOME_NEUTRO, &txtNeutro);
	apTexLoad->LoadTextureFromDisk(NOME_FURIOSO, &txtChateado);
	apTexLoad->LoadTextureFromDisk(NOME_DESANIMADO, &txtDesanimado);
	apTexLoad->LoadTextureFromDisk(NOME_CONTENTE, &txtContente);
	apTexLoad->LoadTextureFromDisk(NOME_ENTUSIASMADO, &txtEntusiasmado);
	apTexLoad->LoadTextureFromDisk(NOME_EUFORICO, &txtEuforico);

	apTexLoad->LoadTextureFromDisk(NOME_FUNDO_BACK, &txtBACK);
	apTexLoad->LoadTextureFromDisk(NOME_FUNDO_FRONT, &txtFRONT);
	apTexLoad->LoadTextureFromDisk(NOME_FUNDO_LEFT, &txtLEFT);
	apTexLoad->LoadTextureFromDisk(NOME_FUNDO_RIGHT, &txtRIGHT);
	apTexLoad->LoadTextureFromDisk(NOME_FUNDO_UP, &txtTOP);
	apTexLoad->LoadTextureFromDisk(NOME_FUNDO_DOWN, &txtBOTTOM);
	//apTexLoad->LoadTextureFromDisk(NOME_LOGIN, &txtLogin);

	glBindTexture(GL_TEXTURE_2D, NULL);
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


	modelo->setEscala(0.2);
	modelo->setGPosLuz1(l1);
	modelo->setGPosLuz2(l2);
	modelo->setCameraMode(1);
	CriarTexturas(modelo->getTexID());

}

bool comparaNos(Nos n1, Nos n2){

	if((n1.x == n2.x) && (n1.y == n2.y) && (n1.z == n2.z))
		return true;
	return false;

}


int getRandNumber()
{

	int num = 0;
	int superior = 20, inferior = 0;
	while( num < 40 && num > 60)
	{
		num = rand() % (superior - inferior +1 ) + inferior;
	}

	//float val = rand() % (1 - (-1) + 1) +1;
	//cout<<"Val = "<<val<<endl;
	//system("PAUSE");
	return num;
}

void distribuiNos2(vector<tuple<int,vector<tuple<int,string>>,User_C>> *graf)//funcional
{
	GLdouble raio;

	GLdouble lng = 0.0;



	Nos nu;
	int numVert = graf->size();
	int inc = 10;
	GLdouble inc_lng = 2.0*M_PI/(GLdouble)numVert;
	GLdouble inc_lat = M_PI/(GLdouble) numVert;

	for(int j = 0; j < numVert; j++){
		GLdouble lat = -M_PI/2.0 + M_PI/(GLdouble)NP/2.0;
		float lar = rand() % 4;
		raio = (K_ESFERA*lar)/4.0;
		if(j==0){
			nu.x = 0;
			nu.y = 0;
			nu.z = 0;
		}else{
			//numero = rand() % (superior - inferior + 1) + inferior;
			nu.x = (j*2.74 + 10) * cos(lng)*sin(lat);
			nu.y = (j*4.1289 + 20) * sin(lng)*sin(lat);
			//nu.z = (j*3.5445 + 19) * sin(-lat);
			int z = rand() % 20;
			nu.z = z;
			//nu.z = 0;
			//nu.x = getRandNumber();//* cos(lng) * sin(lat);
			//nu.y = getRandNumber();//* cos(lat);
			//nu.z = getRandNumber();//* sin(lng)*sin(lat);
		}

		nu.largura=raio;

		get<2>(graf->at(j)).setNo(nu);

		//desenhaNos(nos[j].x,nos[j].y,nos[j].z,raio);
		//desenhaNos(get<2>(graf->at(j)).getNo().x,get<2>(graf->at(j)).getNo().y,get<2>(graf->at(j)).getNo().z,raio);
		//desenhaNos2(graf);
		//desenhaNos
		lat+=inc_lat;

		lng+=inc_lng;
		//inc+=10;
	}
}
void myInit()
{

	GLfloat LuzAmbiente[]={0.5,0.5,0.5, 0.0};
	estado->setOrtho(GL_FALSE);

	estado->setTimer(20);

	//glClearColor (0.0, 0.0, 0.0, 0.0);

	glEnable(GL_SMOOTH); /*enable smooth shading */
	glEnable(GL_LIGHTING); /* enable lighting */
	glEnable(GL_DEPTH_TEST); /* enable z buffer */
	glEnable(GL_NORMALIZE);

	glDepthFunc(GL_LESS);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzAmbiente);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado->getLightViewer());
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	//glShadeModel(GL_FLAT);
	initModelo();
	//initEstado();

	modelo->setQuad(gluNewQuadric());
	gluQuadricDrawStyle(modelo->getQuad(),GLU_FILL);
	gluQuadricNormals(modelo->getQuad(), GLU_OUTSIDE);


	if(gameMode >= 1)//modo avançado
	{
		distribuiNos2(graf);
		modelo->getObjecto()->setX(get<2>(graf->at(0)).getNo().x);
		modelo->getObjecto()->setY(get<2>(graf->at(0)).getNo().z + K_ESFERA*RAIO_NO/2.0+1.0);
		modelo->getObjecto()->setZ(get<2>(graf->at(0)).getNo().y);

	}else{
		//le o grafo exemplo
		leGrafo();
		modelo->getObjecto()->setX(nos[0].x);
		modelo->getObjecto()->setY(nos[0].z + K_ESFERA*RAIO_NO/2.0+1.0);
		modelo->getObjecto()->setZ(nos[0].y);
	}

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
	printf("e,E - Jogar Hangman \n");
	printf("g,G - Jogar TicTacToe \n");
	printf("l,L - Jogar Labirinto \n");
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
	material(brass);
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
		glLoadName(obj++);
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
			glLoadName(obj++);
			desenhaCilindro(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z,noi->largura);
		}else{
			noi=&nos[arco.noi];
			nof=&nos[arco.nof];
			material(red_plastic);
			glLoadName(obj++);
			desenhaCilindro(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z,noi->largura);
		}
	}
}


void desenhaLigacao2(Nos noi, Nos nof)
{
	//Nos *noi,*nof;
	//GLdouble desnivel, comprimentoProj, comprimento,raio,orientacao,inclinacao;
	Nos tmp;
	if(noi.x==nof.x){
		// arco vertical
		if(noi.y < nof.y){
			noi=noi;
			nof=nof;
		}else{
			tmp = nof;
			nof = noi;
			noi = tmp;
		}
		glLoadName(obj++);
		material(red_plastic);
		desenhaCilindro(noi.x,noi.y,noi.z,nof.x,nof.y,nof.z,noi.largura);

	}else{
		if(noi.y==nof.y){
			//arco horizontal
			if(noi.x<nof.x){
				noi=noi;
				nof=nof;
			}else{
				tmp = nof;
				nof = noi;
				noi = tmp;
			}
			glLoadName(obj++);
			material(red_plastic);
			desenhaCilindro(noi.x,noi.y,noi.z,nof.x,nof.y,nof.z,noi.largura);
		}else{
			noi=noi;
			nof=nof;
			material(red_plastic);
			glLoadName(obj++);
			desenhaCilindro(noi.x,noi.y,noi.z,nof.x,nof.y,nof.z,noi.largura);
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
		//glPushName(100+i);
		glutSolidSphere((K_ESFERA*nos[i].largura/2.0),NF,NP);
		//glutSpher

		glPopMatrix();
	}
}


void desenhaNos(GLdouble x, GLdouble y, GLdouble z,GLdouble raio)
{
	///GLdouble raio;
	//for(int i = 0; i < numNos; i++)
	//{
	//	raio = K_ESFERA*nos[i].largura/2.0;
	glPushMatrix();
	material(red_plastic);
	glTranslatef(x,y,z);
	material(azul);
	glutSolidSphere(raio,NF,NP);
	//glTranslatef(nos[i].x,nos[i].y,nos[i].z);
	//glPushName(100+i);
	//glutSolidSphere((K_ESFERA*nos[i].largura/2.0),NF,NP);
	//glutSpher
	//contadorTeste++;
	glPopMatrix();

	//}
}

void desenhaNos2(vector<tuple<int,vector<tuple<int,string>>,User_C>> *graf)
{
	///GLdouble raio;
	//for(int i = 0; i < numNos; i++)
	//{
	//	raio = K_ESFERA*nos[i].largura/2.0;
	int numVert = graf->size();
	int raio = (K_ESFERA*RAIO_NO)/4.0;
	for(int j = 0; j < numVert; j++){
		glPushMatrix();
		material(azul);
		glTranslatef(get<2>(graf->at(j)).getNo().x,get<2>(graf->at(j)).getNo().y,get<2>(graf->at(j)).getNo().z);
		glLoadName(j);
		glutSolidSphere(raio,NF,NP);
		//glTranslatef(nos[i].x,nos[i].y,nos[i].z);
		//glPushName(100+i);
		//glutSolidSphere((K_ESFERA*nos[i].largura/2.0),NF,NP);
		//glutSpher
		//contadorTeste++;
		glPopMatrix();
	}

}



//incompleto
void distribuiNos()
{
	GLdouble raio;
	GLdouble inc_lng = 2.0*M_PI/(GLdouble) NF;
	GLdouble lng = 0.0;

	GLdouble inc_lat = M_PI/(GLdouble) NP;

	for(int i = 0; i < numNos; i++)//percorre o num de fatias
	{
		GLdouble lat = -M_PI/2.0 + M_PI/(GLdouble)NP/2.0;

		//for(int j = 0; j < NP; j++)//percorre o num de partiçoes
		//{
			if(i < numNos)//desenha esfera
			{
				raio = (K_ESFERA*nos[i].largura)/2.0;
				nos[i].x = 30 * cos(lng)*sin(lat);
				nos[i].z = 30 * sin(lng)*sin(lat);
				nos[i].y = 30 * cos(lat);
				desenhaNos(nos[i].x,nos[i].z,nos[i].y,raio);
				lat+=inc_lat;
			}
		//}
		lng+=inc_lng;
	}

}




bool checkConnectionOnList(Nos noi,Nos nof, vector<tuple<Nos,Nos>> * lig){

	for(int i=0; i<lig->size(); i++){
		Nos nTmp1 = get<0>(lig->at(i));
		Nos nTmp2 = get<1>(lig->at(i));

		if((comparaNos(nTmp1, noi) && comparaNos(nTmp2, nof)) ||  (comparaNos(nTmp1, nof) && comparaNos(nTmp2, noi)))
			return false;
	}

	return true;
}

Nos getNoFromVector(int idV, vector<tuple<int,vector<tuple <int,string>>,User_C>> *grafo){
	for(int i=0; i<grafo->size(); i++){
		int vComp = get<0>(grafo->at(i));
		if(idV == vComp)
			return get<2>(grafo->at(i)).getNo();
	}


	Nos ret;
	return ret;

}
vector<tuple<Nos,Nos>> *getLigacoes(vector<tuple<int,vector<tuple <int,string>>,User_C>> *grafo){
	vector<tuple<Nos,Nos>> * lig = new vector<tuple<Nos,Nos>>();

	//CICLO PARA CORRER O GRAFO
	for(int i=0; i<grafo->size(); i++){

		Nos noi = get<2>(grafo->at(i)).getNo();

		//VECTOR COM VERTICES DE LIGAÇÃO
		vector<tuple<int,string>> tmpU = get<1>(grafo->at(i));
		for(int j=0; j<tmpU.size(); j++){
			Nos nof = getNoFromVector(get<0>(tmpU.at(j)), grafo);

			if(checkConnectionOnList(noi,nof, lig)){
				tuple<Nos,Nos> *t = new tuple<Nos,Nos>(noi,nof);
				lig->push_back(*t);
			}
			//Arco arcTmp;

			//Nos nof = get<2>(grafo->at(get<0>(tmpU.at(j)))).getNo();

		}
	}



	return lig;
}

void desenhaArcos(vector<tuple<int,vector<tuple<int,string>>,User_C>> *graf)
{
	Nos noi,nof;

	int h = graf->size();

	for(int k  = 0; k < graf->size(); k++)
	{
		vector<tuple<int,string>> tmpU = get<1>(graf->at(k));
		for(int i = 0; i < tmpU.size(); i++)
		{
			//Arco arcTmp;
			noi = get<2>(graf->at(k)).getNo();
			nof = get<2>(graf->at(get<0>(tmpU.at(i)))).getNo();
			glLoadName(h + i);
			desenhaLigacao2(noi,nof);
		}
	}
}

void desenhaLabirinto(){

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
	//distribuiNos();
	
	//distribuiNos2(graf);
	//desenhaNos2(graf);
	//desenhaArcos(graf);
	//desenhaNos();

	//material(emerald);
	desenhaNos();
	for(int i=0; i<numArcos; i++){
		desenhaLigacao(arcos[i]);
	}
	//Caminho();
	//}
	glPopMatrix();
}

void desenhaLabirinto(vector<tuple<int,vector<tuple<int,string>>,User_C>> *graf){

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

	//distribuiNos2(graf);
	desenhaNos2(graf);
	desenhaArcos(graf);
	//desenhaNos();

	//material(emerald);
	//for(int i=0; i<numArcos; i++){
	//desenhaLigacao(arcos[i]);
	//Caminho();
	//}
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
		if(abs(estado->getCamera()->getDirLong())<M_PI/4)
			glRotatef(-90,0,0,1);
		else
			glRotatef(90,1,0,0);
		material(red_plastic);
		break;
	case EIXO_X :
		if(abs(estado->getCamera()->getDirLong())>M_PI/6)
			glRotatef(90,1,0,0);
		material(azul);
		break;
	case EIXO_Z :
		if(abs(cos(estado->getCamera()->getDirLong()))>0.5)
			glRotatef(90,0,0,1);

		material(emerald);
		break;
	}
	glPopMatrix();
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

void desenhaBillboardEstadohumor(User_C *u)
{
	/*
	0 - Sem estado de espírito (Minha sugestão: começar em estado "Normal")
	1 - Furioso
	2 - Desanimado
	3 - Contente
	4 - Entusiasmado
	5 - Eufórico
	*/
	//Ponto *p = u->getPonto();
	glTexture glt;
	if(u->getMoodState()== 0)//sem estado de espirito
		glt = txtNeutro;
	else
		if(u->getMoodState()== 1)//Furioso
			glt = txtFurioso;
		else
			if(u->getMoodState()== 2)//Desanimado
				glt = txtDesanimado;
			else
				if(u->getMoodState()== 3)//Contente
					glt = txtContente;
				else
					if(u->getMoodState()== 4)//Entusiasmado
						glt = txtEntusiasmado;
					else
						glt = txtEuforico;
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, glt.TextureID);
	glEnable(GL_TEXTURE_2D);
	if(modelo->getObjecto()->getX()<0)
		glTranslatef(u->getNo().x,u->getNo().y + 2,u->getNo().z +11);
	else
		glTranslatef(u->getNo().x,u->getNo().y - 2,u->getNo().z + 11);
	GLdouble deltaz=4;
	GLdouble angOrientacao = graus(atan2(modelo->getObjecto()->getZ()-u->getNo().z,modelo->getObjecto()->getX()-u->getNo().x));
	glRotated(angOrientacao,0,0,1);

	glBegin(GL_QUADS);
	glNormal3f(0,1,0);

	glTexCoord2f(0,0);
	glVertex3f(0,0,0);

	glTexCoord2f(0,1);
	glVertex3f(0,0,4);

	glTexCoord2f(1,1);
	glVertex3f(0,4,4);

	glTexCoord2f(1,0);
	glVertex3f(0,4,0);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, NULL);
}

void setCamera(){

	/*if(estado->getLight()){
	//Posicionar a camera
	glLoadIdentity();
	glRotatef(graus(-M_PI/2.0), 1, 0, 0);
	glRotatef(graus(M_PI/2.0-modelo->getObjecto()->getDir()), 0, 0, 0);
	glTranslatef(-modelo->getObjecto()->getX(), -modelo->getObjecto()->getZ(), -modelo->getObjecto()->getY());
	putLights((GLfloat*)white_light);
	}else{
	//Posicionar a camera
	putLights((GLfloat*)white_light);
	glLoadIdentity();
	glRotatef(graus(-M_PI/2.0), 1, 0, 0);
	glRotatef(graus(M_PI/2.0-modelo->getObjecto()->getDir()), 0, 0, 1);
	//glRotatef(graus(M_PI/2.0-modelo->getObjecto()->getDir()), 0, 0, 1);
	glTranslatef(-modelo->getObjecto()->getX(), -modelo->getObjecto()->getZ(), -modelo->getObjecto()->getY());

	}*/
	estado->getCamera()->setCenterX(modelo->getObjecto()->getX() + cos(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	estado->getCamera()->setCenterY(modelo->getObjecto()->getZ() - sin(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	estado->getCamera()->setCenterZ(modelo->getObjecto()->getY() + 2 + sin(estado->getCamera()->getDirLat()));
	//}

	putLights((GLfloat*)white_light);

	gluLookAt(modelo->getObjecto()->getX()  , modelo->getObjecto()->getZ() , modelo->getObjecto()->getY() + 2 ,
		estado->getCamera()->getCenterX() , estado->getCamera()->getCenterY() , estado->getCamera()->getCenterZ() ,
		0,0,1);

}

void setCamera2()
{
	estado->getCamera()->setCenterX(modelo->getObjecto()->getX() + cos(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	estado->getCamera()->setCenterY(modelo->getObjecto()->getZ() - sin(estado->getCamera()->getDirLong() * cos(estado->getCamera()->getDirLat())));
	estado->getCamera()->setCenterZ(modelo->getObjecto()->getY() + 2 + sin(estado->getCamera()->getDirLat()));
	//}

	putLights((GLfloat*)white_light);

	gluLookAt(modelo->getObjecto()->getX()  , modelo->getObjecto()->getZ() , modelo->getObjecto()->getY() + 2 ,
		estado->getCamera()->getCenterX() , estado->getCamera()->getCenterY() , estado->getCamera()->getCenterZ() ,
		0,0,1);
}

//not done
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
		//teclas->setV(GL_FALSE);
		//estado.camera.center[2]+=0.2;
		break;
	case 'r':
	case 'R':
		teclas->setR(GL_TRUE);
		teclas->setV(GL_FALSE);
		break;
	case 'v':
	case 'V':
		teclas->setV(GL_TRUE);
		teclas->setR(GL_FALSE);
		break;
	case 'g':
	case'G':
		teclas->setG(GL_TRUE);
		//sw1 = glutCreateSubWindow(mainWindow,10,10,WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
		break;
	case 'e':
	case 'E':
		teclas->setE(GL_TRUE);
		//glutDestroyWindow(sw1);
		break;
	case 'm':
	case 'M':
		teclas->setM(GL_TRUE);
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
	case 'R':
	case 'r':
		teclas->setR(GL_FALSE);
		break;
	case 'V':
	case 'v':
		teclas->setV(GL_FALSE);
		break;

	case 'g':
	case 'G':
		teclas->setG(GL_FALSE);
		break;
	case 'e':
	case 'E':
		teclas->setE(GL_FALSE);
		break;
	case 'm':
	case 'M':
		teclas->setM(GL_FALSE);
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
	//setCamera();
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


void processHits(GLint hits, GLuint buffer[])
{
	unsigned int  j;
	GLuint names,*ptr;

	printf("hits = %d\n",hits);
	ptr = (GLuint *) buffer;
	for(int i = 0; i < hits; i++)
	{/*para cada hit*/
		names = *ptr;
		printf("numero de nomes por hit = %d \n", names);
		ptr++;
		printf(" z1 is %g;", (float) *ptr/0x7fffffff);
		ptr++;
		printf("z2 is %g\n;", (float) *ptr/0x7fffffff);
		ptr++;
		printf(" nome : ");
		for(j = 0; j < names; j++)
		{/*para cada nome*/
			printf("%d", *ptr);
			ptr++;
		}
		printf("\n");
	}
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	setProjection(0,0,GL_FALSE);
	glMatrixMode(GL_MODELVIEW);
}

//################MINI-MAPA###############

void minimapaView()
{
	estadominimapa->getCamera()->setDirLat(-(M_PI/2));
	estadominimapa->getCamera()->setDirLong(0);
	estadominimapa->getCamera()->setCenterZ(0);
	estadominimapa->getCamera()->setCenterX(0);
	estadominimapa->getCamera()->setCenterY(0);


	estadominimapa->getCamera()->setEyeZ(0);
	estadominimapa->getCamera()->setEyeX(0);
	estadominimapa->getCamera()->setEyeY(50);

	//estadominimapa->getCamera()->setCenterX(modelo->getObjecto()->getX() + cos(estadominimapa->getCamera()->getDirLong() * cos(estadominimapa->getCamera()->getDirLat())));
	//estadominimapa->getCamera()->setCenterY(modelo->getObjecto()->getZ() - sin(estadominimapa->getCamera()->getDirLong() * cos(estadominimapa->getCamera()->getDirLat())));
	estadominimapa->getCamera()->setCenterY(modelo->getObjecto()->getY() + 2 + sin(estadominimapa->getCamera()->getDirLat()));

	estadominimapa->getCamera()->setCenterX(0);
	estadominimapa->getCamera()->setCenterZ(0);

	estadominimapa->getCamera()->setCenterY(0);


	putLights((GLfloat*)white_light);

	gluLookAt(estadominimapa->getCamera()->getEyeY(),estadominimapa->getCamera()->getEyeX(),estadominimapa->getCamera()->getEyeZ(),estadominimapa->getCamera()->getCenterX(),estadominimapa->getCamera()->getCenterY(),estadominimapa->getCamera()->getCenterZ(),0,0,1);
}

void desenhaMinimapa(int width, int height)
{
	glViewport(0,0, (GLint) width/6, (GLint) height/6);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_DEPTH_BUFFER_BIT);
	minimapaView();

	//desenhaEixos();
	//material(slate);
	//desenhaSolo();
	desenhaLabirinto(graf);


	//desenhaLabirinto();


	glFlush();
	Reshape(width,height);
}

void desenhaSkyBox()
{
	float x = 0;
	float y = 0;
	float z = 0;
	float width  = 512;
	float height = 512;
	float length = 512;



	glEnable(GL_TEXTURE_2D);


	glEnable(GL_COLOR_MATERIAL);
	// centra o cubo
	x = x - width  / 2;
	y = y - height / 2;
	z = z - length / 2;


	//BOTTOM
	glBindTexture(GL_TEXTURE_2D, txtBOTTOM.TextureID);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(x, y + height, z);
	glTexCoord2f(1.0f,0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);

	//TOP

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, txtTOP.TextureID);
	glBegin(GL_QUADS);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,  z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y,  z + length);
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);

	//RIGHT +
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, txtRIGHT.TextureID);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y,  z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y,  z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y,  z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,  z);
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);

	//LEFT
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, txtLEFT.TextureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f);  glVertex3f(x, y + height, z + length);
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);

	//BACK
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, txtBACK.TextureID);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y,  z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y,  z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y + height, z);
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);

	//FRONT
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, txtFRONT.TextureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,  z);
	glTexCoord2f(1.0f, 1.0f);  glVertex3f(x + width, y,  z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);

}




void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	setCamera();

	//material(slate);

	//desenhaSolo();
	desenhaSkyBox();
	//desenhaEixos();
	if(gameMode < 1)
		desenhaLabirinto();
	else
		desenhaLabirinto(graf);


	//aselectObjects();

	if(estado->getEixoTrans()) {
		//desenha plano de translacção
		//std::cout << "Translate... " << estado->getEixoTrans() << endl;
		desenhaPlanoDrag(estado->getEixoTrans());

	}
	desenhaMinimapa(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_INIT_WINDOW_HEIGHT));
	glFlush();
	glutSwapBuffers();

}


void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	setCamera();

	//material(slate);

	//desenhaSolo();
	//desenhaSkyBox();
	//desenhaEixos();

	desenhaNos2(graf);
	desenhaArcos(graf);

	//	desenhaLabirinto(graf);

	//aselectObjects();

	//if(estado->getEixoTrans()) {
	//desenha plano de translacção
	//std::cout << "Translate... " << estado->getEixoTrans() << endl;
	//desenhaPlanoDrag(estado->getEixoTrans());

	//}

	desenhaMinimapa(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_INIT_WINDOW_HEIGHT));

	//glDepthMask(GL_TRUE);
	//glDisable(GL_BLEND);

	glFlush();
	glutSwapBuffers();

}



int picking(/*int x, int y*/){
	int i, n, objid=0;
	double zmin = 10.0;
	GLuint buffer[100], *ptr;

	//	GLint viewport[4];
	//	GLdouble modelview[16];
	//	GLdouble projection[16];
	//	GLdouble posX, posY, posZ;

	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); // guarda a projecção
	glLoadIdentity();
	//setProjection(estado->getCamera()->getEyeX(),estado->getCamera()->getEyeZ(),GL_TRUE);

	//colisao

	glOrtho(-DIMENSAO_CAMARA/2, DIMENSAO_CAMARA/2, -DIMENSAO_CAMARA/2, DIMENSAO_CAMARA/2, 0.0, DIMENSAO_CAMARA/2 + modelo->getObjecto()->getVel());


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//colisao
	glRotatef(graus(-M_PI/2)-atan2(1.0, 1.0), 1, 0, 0);
	glRotatef(graus((M_PI/2)-modelo->getObjecto()->getDir()), 0, 0, 1);
	glTranslatef(-modelo->getObjecto()->getX(), -modelo->getObjecto()->getY(), -modelo->getObjecto()->getZ());

	//distribuiNos2();
	//desenhaArcos();
	//setCamera();
	//desenhaNos2(graf);
	//desenhaArcos(graf);
	//display();
	//Nos noAux;
	display();

	//glutPostRedisplay();

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
		/*glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
		glGetDoublev(GL_PROJECTION_MATRIX,projection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		gluUnProject(estado->getCamera()->getCenterX(),estado->getCamera()->getCenterY(),estado->getCamera()->getCenterZ(),modelview,projection,viewport,&posX,&posY,&posZ);
		noAux.x = posX;
		noAux.y = posY;
		noAux.z = posZ;*/
	}

	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	return objid;
}

bool picking2(float nx,float ny,float nz){

	int i, n, objid=0;
	double zmin = -30.0;
	double zmax = 30.0;

	GLuint buffer[100], *ptr;

	GLint vport[4];
	GLdouble model[16];
	GLdouble proj[16];
	glGetIntegerv(GL_VIEWPORT, vport);

	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();

	glMatrixMode(GL_PROJECTION);
	glGetDoublev(GL_PROJECTION, proj);
	glPushMatrix(); // guarda a projecção
	glLoadIdentity();
	glOrtho(nx-modelo->getObjecto()->getVel(), nx+modelo->getObjecto()->getVel(), nz-modelo->getObjecto()->getVel(), nz+modelo->getObjecto()->getVel(), zmax, zmin);
	glMatrixMode(GL_MODELVIEW);
	glGetDoublev(GL_MODELVIEW, model);
	//glLoadIdentity();
	//glRotatef(graus(-M_PI/2)-atan2(1.0, 1.0), 1, 0, 0);
	//glRotatef(graus((M_PI/2)-modelo->getObjecto()->getDir()), 0, 0, 1);
	//glTranslatef(-modelo->getObjecto()->getX(), -modelo->getObjecto()->getY(), -modelo->getObjecto()->getZ());

	//setCamera();

	//desenhaSolo();

	//desenhaEixos();

	//desenhaLabirinto();
	//distribuiNos2(graf);
	//desenhaNos2(graf);
	//desenhaArcos(graf);
	//glutPostRedisplay();
	display();
	//glPushMatrix();

	n = glRenderMode(GL_RENDER);
	if (n > 0)
	{
		ptr = buffer;
		for (i = 0; i < n; i++)
		{
			if (zmin > (double) ptr[1] / UINT_MAX) {
				zmin = (double) ptr[1] / UINT_MAX;
				objid = ptr[3];

				return true;
			}
			ptr += 3 + ptr[0]; // ptr[0] contem o número de nomes (normalmente 1); 3 corresponde a numnomes, zmin e zmax

		}

	}

	//glPopMatrix();

	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	return false;

}

int selectObjects(/*int x, int y*/)
{
	int i, objid = 0;
	GLint hits;
	double zmin = 1.0, zmax = 1.0;
	GLuint buffer[BUFSIZE], *ptr;

	glSelectBuffer(BUFSIZE, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();
	//glPushName(0);//colocar o inicial na stack - 0


	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-DIMENSAO_CAMARA/2.0,DIMENSAO_CAMARA/2.0,
		-DIMENSAO_CAMARA/2.0,DIMENSAO_CAMARA/2.0,
		0.0,DIMENSAO_CAMARA/2.0 + modelo->getObjecto()->getVel());
	setProjection(modelo->getObjecto()->getX(),modelo->getObjecto()->getZ(),GL_TRUE);

	glMatrixMode(GL_MODELVIEW);



	glLoadIdentity();
	setCamera();
	//glRotatef(graus(-M_PI/2.0 - atan2(estado->getCamera()->getVelv(),modelo->getObjecto()->getVel())),1,0,0);
	//glRotatef(graus(M_PI/2.0 - modelo->getObjecto()->getDir()),0,0,1);
	//glTranslatef(-modelo->getObjecto()->getX(),-modelo->getObjecto()->getZ(),-modelo->getObjecto()->getY());
	glPushMatrix();
	desenhaLabirinto(graf);
	glPopMatrix();


	hits = glRenderMode(GL_RENDER);
	if(hits > 0)
	{
		ptr = buffer;
		for(i = 0; i < hits; i++)
		{
			if(zmin > (double) ptr[1]/UINT_MAX)
			{
				zmin = (double) ptr[1] / UINT_MAX;
				objid = ptr[3];
			}
			ptr += 3 + ptr[0];
		}
	}
	processHits(hits,buffer);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	return objid;

}

bool detectaColisoesLigacoes2(GLfloat nx, GLfloat nz, GLfloat ny)
{
	nz-=1;
	bool flag = false;
	//int noi, nof;
	glLoadIdentity();
	for(int i = 1; i <=numArcos; i++)
	{
		//nos[arcos[i].noi] useri
		//nos[arcos[i].nof userf
		GLdouble larg = nos[arcos[i].noi].largura + 0.4;
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(nos[arcos[i].noi].x,nos[arcos[i].noi].y,nos[arcos[i].noi].z);
		GLdouble angOr = graus(atan2((nos[arcos[i].nof].y - nos[arcos[i].noi].y),(nos[arcos[i].nof].x - nos[arcos[i].nof].x)));
		GLdouble catetoOposto = nos[arcos[i].nof].z - nos[arcos[i].nof].z;
		GLdouble tamanho = sqrt(pow((nos[arcos[i].nof].x - nos[arcos[i].noi].x),2) + pow((nos[arcos[i].nof].y - nos[arcos[i].noi].y),2) + pow((nos[arcos[i].nof].z - nos[arcos[i].noi].z),2));
		GLdouble angIncl = graus(atan2(catetoOposto,tamanho));
		glRotated(angOr,0,0,1);
		GLdouble nx2 = (nx - nos[arcos[i].noi].x*cos(rad(angOr))) + (nz - nos[arcos[i].noi].y)*sin(rad(angOr));
		GLdouble ny2 = (nz - nos[arcos[i].noi].y*cos(rad(angOr))) - (nx - nos[arcos[i].noi].x)*sin(rad(angOr));
		GLdouble d = sqrt(pow((nos[arcos[i].nof].x - nos[arcos[i].noi].x),2) + pow((nos[arcos[i].nof].y - nos[arcos[i].noi].y),2) + pow((nos[arcos[i].nof].y - nos[arcos[i].noi].y),2));
		GLdouble nz2 = nos[arcos[i].noi].z + nx2/tamanho*catetoOposto;

		if((0 <= nx2 && nx2 <= tamanho) && ((-larg/2.0)+2.2 <= ny2 && ny2 <= (larg/2.0)-3) && ((nz2-((larg/2.0+0.1)+4) <= ny && ny <= (nz2 + (larg/2.0-0.2)))))
		{
			flag = true;
		}
		glPopMatrix();
	}
	return flag;
}

GLfloat pointDistance(Nos noi, Nos nof)
{
	Nos vec;
	vec.x = nof.x -noi.x;
	vec.y = nof.y - noi.y;
	vec.z = nof.z - noi.z;
	return(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}

GLfloat pointDistanceArco(Nos noi, Arco arco, Nos* Lnos)
{
	Nos vec;
	vec.x = Lnos[arco.nof].x -noi.x;
	vec.y = Lnos[arco.nof].y - noi.y;
	vec.z = Lnos[arco.nof].z - noi.z;

	return(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}

//deteta colisoes esfera-esfera
//deteta Colisao esfera especifica

bool colisaoEsferaEsfera2(Nos& noCam , float r1, Nos* lnos, Arco* larcos)
{
	Nos vec;
	float dist, r2;
	for(int i = 0; i < numNos; i++)
	{
		dist = pointDistance(noCam,lnos[i]);
		//cout<<"#######";
		//cout<<"\ndist:" <<dist;
		//cout<<"\nraios::"<<(r1+r2);
		//cout<<"#######";
		r2 =  ( K_ESFERA*lnos[i].largura/2.0)+1 ;
		if(dist <= (r1+r2))
		{
			float a = sqrt(dist) - (r1+r2);
			//coordinate vec(c2.x - c1.x,c2.y-c1.y,c2.z-c1.z);//c2-c1
			vec.x = lnos[i].x - noCam.x;
			vec.y = lnos[i].y - noCam.y;
			vec.z = lnos[i].z - noCam.z;
			float len = sqrt((vec.x*vec.x + vec.y*vec.y + vec.z*vec.z));
			vec.x/=len;
			vec.y/=len;
			vec.z/=len;

			noCam.x = noCam.x+vec.x*a;
			noCam.y = noCam.y + vec.y*a;
			noCam.z = noCam.z + vec.z*a;
			return 1;//true
		}
	}
	return 0;
}



bool detetaColisaoEsferaSubir(Nos &noCam,Nos* lnos)
{
	for(int i = 0; i < numNos; i++)
	{
		float r2 =  ( K_ESFERA*lnos[i].largura/2.0) + 1 ;
		if(noCam.y < lnos[i].y + r2)
		{
			return true;
		}

	}
	return false;
}
bool detetaColisaoEsferaDescer(Nos &noCam,Nos* lnos)
{
	for(int i = 0; i < numNos; i++)
	{
		float r2 =  ( K_ESFERA*lnos[i].largura/2.0) - 1 ;
		if(noCam.y < lnos[i].y + r2)
		{
			return true;
		}

	}
	return false;
}

bool colisaoArco(float x, float y,float cproj,float desnivel)
{
	//float nx = (x-arcos->noi)*cos(x)+(x-y)*sin(x);
	//float ny = (x-y)*cos(x)-(y-x)*sin(x);


	for (int i=0; i<numArcos; i++) {
		if(x<cproj && -desnivel/2<=y && y<=desnivel/2)
		{
			return true;
		}
	}
	return false;

}


void moveTo(Nos c)
{
	estado->getCamera()->setCenterX(c.x);
	estado->getCamera()->setCenterY(c.z);
	estado->getCamera()->setCenterZ(c.y);
}

Nos camPos()
{
	Nos camNewPos;
	camNewPos.x = estado->getCamera()->getCenterX();
	camNewPos.y = estado->getCamera()->getCenterY();
	camNewPos.z = estado->getCamera()->getCenterZ();
	return camNewPos;
}
//falta fazer ligação com webservice para saber os pedidos que estão pendentes.
int PedidosPendentes()
{
	int op;
	cout<<"#####################################"<<endl;
	cout<<"Tem pedidos de amizade pendentes!"<<endl;
	cout<<"Para aceitar o pedido escolha uma opção:"<<endl;
	cout<<"#####################################"<<endl;
	cout<<"#1------------JOGO DO GALO----------#"<<endl;
	cout<<"#2--------------ENFORCADO-----------#"<<endl;
	cout<<"#3--------------LABIRINTO-----------#"<<endl;
	cout<<"#0------------REJEITAR PEDIDO-------#"<<endl;
	cout<<"#####################################"<<endl;

	cin>>op;

	return op;
}
//falta fazer ligação com webservice para confirmar se é amigo ou não
int FazerPedidoAmizade()
{
	int op;
	cout<<"#####################################"<<endl;
	cout<<"Pretende adicionar como amigo?"<<endl;
	cout<<"#####################################"<<endl;
	cout<<"#1-----------------SIM--------------#"<<endl;
	cout<<"#2-----------------NAO--------------#"<<endl;
	cout<<"#####################################"<<endl;

	cin>>op;

	return op;
}


void motionNavigateSubWindow(int x, int y)
{
	int dif;
	dif  = y - estado->getYMouse();
	if(dif > 0)
	{
		estado->getCamera()->setDirLat(estado->getCamera()->getDirLat() - 0.001/*dif*rad(EYE_ROTATION)*/);
		if(estado->getCamera()->getDirLat() < -rad(90))
			estado->getCamera()->setDirLat(rad(90));
	}
	if(dif < 0)
		estado->getCamera()->setDirLat(estado->getCamera()->getDirLat() + 0.001/*abs(dif)*rad(EYE_ROTATION)*/);
	if(estado->getCamera()->getDirLat() > rad(90))
		estado->getCamera()->setDirLat(rad(90));

	dif =  x - estado->getXMouse();

	if(dif > 0)
	{
		//modelo->getObjecto()->setDir(modelo->getObjecto()->getDir()  - 0.001/*dif*rad(EYE_ROTATION)*/);
		estado->getCamera()->setDirLong(estado->getCamera()->getDirLong() - 0.001/*dif*rad(EYE_ROTATION)*/);
	}

	if(dif < 0)
	{
		//modelo->getObjecto()->setDir(modelo->getObjecto()->getDir() +  0.1/*abs(dif)*rad(EYE_ROTATION)*/);
		estado->getCamera()->setDirLong(estado->getCamera()->getDirLong() + 0.1/*abs(dif)*rad(EYE_ROTATION)*/);
	}
}
//definir mouse para mudar de direcao de forma a ter 2 opçoes setas e rato (right mouse button)
void mouse(int btn, int state, int x, int y){
	switch(btn) {
	case GLUT_RIGHT_BUTTON :
		if(state == GLUT_DOWN){
			estado->setXMouse(x);
			estado->setYMouse(y);
			//if(glutGetModifiers() & GLUT_ACTIVE_CTRL){
			//	glutMotionFunc(motionZoom);
			//	//printf("hello!!!");
			//}else{
			//	glutMotionFunc(motionRotate);
			//	//printf("hello2!!!");
			//}
			//std::cout << "Right down\n";
			glutMotionFunc(motionNavigateSubWindow);
		}
		else{
			glutMotionFunc(NULL);
			std::cout << "Right up\n";
		}
		break;
	case GLUT_LEFT_BUTTON :
		if(state == GLUT_DOWN){
			//estado->setEixoTrans(picking(x,y));
			//estado->setEixoTrans(selectObjects(x,y));
			if(estado->getEixoTrans())
				//glutMotionFunc(motionDrag);
					std::cout << "Left down - objecto:" << estado->getEixoTrans() << endl;
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
			std::cout << "Left up\n";
		}
		break;
	}
}

void Timer(int value)
{

	glutTimerFunc(estado->getTimer(), Timer, 0);

	float nx, ny,nx2,ny2,nz,desnivel,cproj;


	if(teclas->getV())
	{
		cout<<"\nVOO LIVRE!";
		teclas->setR(GL_FALSE);
		modelo->setCameraMode(CAMERA_LIVRE);
	}

	if(teclas->getR())
	{
		cout<<"\nVOO RASANTE!";
		teclas->setV(GL_FALSE);
		modelo->setCameraMode(CAMERA_RASANTE);
		modelo->getObjecto()->setX(get<2>(graf->at(0)).getNo().x);
		modelo->getObjecto()->setY(get<2>(graf->at(0)).getNo().z + K_ESFERA*RAIO_NO/2.0+1.0);
		modelo->getObjecto()->setZ(get<2>(graf->at(0)).getNo().y);

	}

	if(teclas->getG())
	{
		cout<<"\nTicTacToe\n";
		system("TicTacToe.exe");

	}

	if(teclas->getE())
	{
		cout<<"\nHangman!\n";
		system("HangMan.exe");
	}

	if(teclas->getM())
	{
		cout<<"\nLabirinto 3D!\n!";
		system("Labirinto.exe");
	}
	switch(modelo->getCameraMode())
	{
	case CAMERA_LIVRE:

		if(teclas->getQ())
		{
			Nos cameraPos = camPos();
			if(!picking())
			{
				modelo->getObjecto()->setY(modelo->getObjecto()->getY() + modelo->getObjecto()->getVel());
				teclas->setQ(GL_FALSE);
			}
		}

		if(teclas->getA())
		{
			if(!picking())
			{
				modelo->getObjecto()->setY(modelo->getObjecto()->getY() - modelo->getObjecto()->getVel());
				teclas->setA(GL_FALSE);
			}
		}

		if(teclas->getLEFT())
		{
			modelo->getObjecto()->setDir(modelo->getObjecto()->getDir()-0.1);
			estado->getCamera()->setDirLong(estado->getCamera()->getDirLong() - 0.1);
		}

		if(teclas->getRIGHT())
		{
			modelo->getObjecto()->setDir(modelo->getObjecto()->getDir()+0.1);
			estado->getCamera()->setDirLong(estado->getCamera()->getDirLong()+0.1);
		}

		/*if(teclas->getUP())
		{
		nx=modelo->getObjecto()->getX()+cos(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel();
		ny=modelo->getObjecto()->getZ()-sin(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel();
		nz = modelo->getObjecto()->getY() + 1;
		if(detectaColisoesLigacoes(modelo->getObjecto()->getX(),modelo->getObjecto()->getZ(),modelo->getObjecto()->getY()) )

		{

		modelo->getObjecto()->setDir(modelo->getObjecto()->getDir() - 0.1);
		estado->getCamera()->setDirLong(estado->getCamera()->getDirLong() - 0.1);


		}

		}*/

		if(teclas->getUP())
		{
			Nos cameraPos = camPos();

			//condições para os nós
			if(picking()){
				cout <<"\n\tCOLISAO!";
				if(!colisaoEsferaEsfera2(cameraPos,DIMENSAO_CAMARA,nos,arcos))
				{
					cout<<"Não ha colisao na esfera\n";
				}
				modelo->getObjecto()->setY(modelo->getObjecto()->getY() + 0.1);
			}else{
				modelo->getObjecto()->setX(modelo->getObjecto()->getX() + cos(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
				modelo->getObjecto()->setZ(modelo->getObjecto()->getZ() + sin(-modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
			}
		}
		if(teclas->getDOWN())
		{
			Nos cameraPos = camPos();
			if(picking())
			{
				if(!colisaoEsferaEsfera2(cameraPos,DIMENSAO_CAMARA,nos,arcos))
				{
					cout<<"Não ha colisao na esfera\n";
				}
				modelo->getObjecto()->setY(modelo->getObjecto()->getY() + 0.1);
			}else{
				modelo->getObjecto()->setX(modelo->getObjecto()->getX() - cos(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
				modelo->getObjecto()->setZ(modelo->getObjecto()->getZ() - sin(-modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel());
			}
		}

		break;
	case CAMERA_RASANTE:

		if(teclas->getLEFT())
		{
			modelo->getObjecto()->setDir(modelo->getObjecto()->getDir()-0.1);
			estado->getCamera()->setDirLong(estado->getCamera()->getDirLong() - 0.1);
		}

		if(teclas->getRIGHT())
		{
			modelo->getObjecto()->setDir(modelo->getObjecto()->getDir()+0.1);
			estado->getCamera()->setDirLong(estado->getCamera()->getDirLong()+0.1);
		}

		if(teclas->getUP())
		{

			/*if(detectaColisoesLigacoes(modelo->getObjecto()->getX(),modelo->getObjecto()->getZ(),modelo->getObjecto()->getY()) )
			{
			int tentativas = 200;
			nx=modelo->getObjecto()->getX()+cos(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel();
			ny=modelo->getObjecto()->getZ()-sin(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel();
			nz = modelo->getObjecto()->getY() + 1;
			while(!detectaColisoesLigacoes2(nx,nz,ny) && tentativas>0){
			ny -= 0.01;tentativas--;}
			modelo->getObjecto()->setX(nx);
			modelo->getObjecto()->setZ(nz);
			if(tentativas>0)
			modelo->getObjecto()->setY(ny);
			}*/
			if(picking())
			{
				cout<<"\ncolidiu";

				nx=modelo->getObjecto()->getX()+cos(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel();
				ny=modelo->getObjecto()->getZ()-sin(modelo->getObjecto()->getDir())*modelo->getObjecto()->getVel();
				nz = modelo->getObjecto()->getY() + 1;

				nx2=(nx-modelo->getObjecto()->getX())*cos(modelo->getObjecto()->getDir())+(ny-modelo->getObjecto()->getZ())*sin(modelo->getObjecto()->getDir());
				ny2=(ny-modelo->getObjecto()->getZ())*cos(modelo->getObjecto()->getDir())+(nx-modelo->getObjecto()->getX())*sin(modelo->getObjecto()->getDir());

				cproj=pow((nx-modelo->getObjecto()->getX()),2);
				desnivel=(ny-modelo->getObjecto()->getZ());

				if(nx2>0.0 && colisaoArco(nx2, ny2,desnivel,cproj))
				{
					modelo->getObjecto()->setX(nx2);
					modelo->getObjecto()->setZ(ny2);
				}
				Nos cameraPos = camPos();



				if(detetaColisaoEsferaSubir(cameraPos, nos) )
				{
					modelo->getObjecto()->setY(modelo->getObjecto()->getY() + 0.1);
					cout<<"colisao subir\n";
				}else{
					if( detetaColisaoEsferaDescer(cameraPos,nos) )
					{
						modelo->getObjecto()->setY(modelo->getObjecto()->getY() - 0.1);
						cout<<"colisao descer\n";
					}
				}
			}
		}

		if(teclas->getDOWN())
		{

			if(detectaColisoesLigacoes2(modelo->getObjecto()->getX(),modelo->getObjecto()->getZ(),modelo->getObjecto()->getY()) )
			{
				int tentativas = 200;
				nx = modelo->getObjecto()->getX() - cos(modelo->getObjecto()->getDir()) * modelo->getObjecto()->getVel();
				nz = modelo->getObjecto()->getZ() - sin(-modelo->getObjecto()->getDir()) * modelo->getObjecto()->getVel();
				ny = modelo->getObjecto()->getY() + 1;
				while(!detectaColisoesLigacoes2(nx,nz,ny) && tentativas>0){
					ny -= 0.01;tentativas--;}
				modelo->getObjecto()->setX(nx);
				modelo->getObjecto()->setZ(nz);
				if(tentativas>0)
					modelo->getObjecto()->setY(ny);
			}


		}
		break;

	default:
		break;

	}



	if(!estado->getDebug())
		printf("Velocidade %.2f \n",modelo->getObjecto()->getVel());

	glutPostRedisplay();
}



int getPositionOfVectorByIdUser(vector<User_C> *userList, int idUserToSearch){

	for(int i=0; i<userList->size(); i++){
		if(userList->at(i).getIdUser() == idUserToSearch){
			return i;
		}
	}

	return -1;
}




vector<tuple<int,vector<tuple <int,string>>,User_C>> *geraGrafo(vector<User_C> *userList){
	//Tuple ( idVertice, listaLigacoes, Utilizador correspondente
	vector<tuple<int,vector<tuple <int,string>>,User_C>> *grafo = new vector<tuple<int,vector<tuple <int,string>>,User_C>>();

	for(int i=0; i<userList->size(); i++){
		int idV=i;
		vector<tuple <int,string>> *vect = new vector<tuple <int,string>>();
		for(int j=0; j<userList->at(i).getFriends()->size(); j++){
			int idVTemp=getPositionOfVectorByIdUser(userList , get<0>(userList->at(i).getFriends()->at(j)));
			if(idVTemp != -1){
				string tgNTemp=get<1>(userList->at(i).getFriends()->at(j));
				tuple <int,string> t(idVTemp,tgNTemp);
				vect->push_back(t);
			}
		}

		tuple<int,vector<tuple <int,string>>,User_C> *tup = new tuple<int,vector<tuple <int,string>>,User_C> (idV,*vect,userList->at(i));

		grafo->push_back(*tup);
	}

	return grafo;

}




int main(int argc, char **argv)
{

	char **argvT = argv;
	char * x= argvT[1];
	//int id = atoi(x);
	string username, password;
	int id = 0;
	WebService_Request *ws= new WebService_Request();

	cout<<"1 - Modo Avancado"<<endl<<"0 - Modo Normal"<<endl;
	cin>>gameMode;
	switch(gameMode)
	{
	case 1:
		while(id < 1){
			cout<<"Username : ";
			cin>>username;
			cout<<"\nPassword : ";
			cin>>password;
			id=ws->login(username,password);
			if(id > 0){
				//vector<User_C> *userList = ws->getNetworkById(id);
				vector<User_C> *userList = ws->getNetworkById(id);
				//vector<tuple<int,vector<tuple <int,string>>,User_C>> *grafo = geraGrafo(userList);
				graf = geraGrafo(userList);
			}else{
				cout<<"Login Falhou! Password ou Username Errado!"<<endl;
			}
		}
		break;
	default:
		break;
	}

	//	int id=ws->login("Quim","qwerty");
	//	vector<User_C> *userList = ws->getNetworkById(id);

	// tuplo -> conjunto de dados separados
	// get<> la dentro 0 corresponde a posiçao do int , string ou boolean
	// 



	glutInit(&argc, argv);

	/* need both double buffering and z buffer */

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	//	glutCreateWindow("Think&Code");
	mainWindow = glutCreateWindow("Think&Code");
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
