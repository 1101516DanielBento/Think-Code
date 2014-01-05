#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>     
#include <cmath>
#include <iostream>
#include "grafos.h"
#include <vector>
#include <ctime>
#include <iostream>
#include <string>


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

typedef struct TextBox{
	string user;
	string pw;
	int idSeleccionada;
}TextBox;

TextBox txtBox;

std::vector<std::vector<GLfloat>> PosTodosUsers;

std::vector<std::wstring> nomesUtilizadores;//vector que contem todos os utilizadores
std::vector<std::vector<std::wstring>> relacoesUtilizadores;//vector que contem as ligacoes entre utilizadores


using namespace std;

#define graus(X) (double)((X)*180/M_PI)
#define rad(X)   (double)((X)*M_PI/180)
#define K_ESFERA 4.0
#define VELv 0.5
#define DIMENSAO_CAMARA 4
#define DISTANCIA_SOLO 2

//TEXTURAS

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

typedef struct {
	GLboolean   q,a,up,down,left,right;
}Teclas;

typedef struct pos_t{
    GLfloat    x,y,z;
}pos_t;

typedef struct objecto_t{
    pos_t    pos;
    GLfloat  dir;
    GLfloat  vel;
}objecto_t;

typedef struct Camera{
	GLfloat fov;
	GLdouble dir_lat;
	GLdouble dir_long;
	GLfloat dist;
	Vertice center;
	GLfloat velh;
	GLfloat velv;
	GLfloat velTotal;
}Camera;

typedef struct Estado{
	Camera		camera;
	GLint         timer;
	Teclas		teclas;
	int			xMouse,yMouse;
	GLboolean	light;
	GLboolean   debug;
	GLboolean	apresentaNormais;
	GLint		lightViewer;
	GLint		eixoTranslaccao;
	GLdouble	eixo[3];
    GLboolean   VLivre;     //bool para verificar voo livre/rasante
}Estado;

typedef struct Modelo {
	objecto_t objecto;
	#ifdef __cplusplus
		tipo_material cor_cubo;
	#else
		enum tipo_material cor_cubo;
	#endif

	GLfloat g_pos_luz1[4];
	GLfloat g_pos_luz2[4];

	GLfloat escala;
	GLUquadric *quad;
}Modelo;

Estado estado;
Modelo modelo;

void initEstado(){
	estado.camera.dir_lat=M_PI/4;
	estado.camera.dir_long=-M_PI/4;
	estado.camera.fov=60;
	estado.camera.dist=100;
	estado.camera.velh = 1.0;
	estado.camera.velv = 1.0;
	estado.camera.velTotal = estado.camera.velh + estado.camera.velv;
	estado.eixo[0]=0;
	estado.eixo[1]=0;
	estado.eixo[2]=0;
	estado.camera.center[0]=0;
	estado.camera.center[1]=0;
	estado.camera.center[2]=0;
	estado.light=GL_FALSE;
	estado.apresentaNormais=GL_FALSE;
	estado.lightViewer=1;
	estado.timer=20;
	//coordenadas do objecto
	modelo.objecto.pos.x=90;
	modelo.objecto.pos.y=80;
	modelo.objecto.pos.z=50;
	
	
}

void initModelo(){
	modelo.escala=0.2;

	modelo.cor_cubo = brass;
	modelo.g_pos_luz1[0]=-5.0;
	modelo.g_pos_luz1[1]= 5.0;
	modelo.g_pos_luz1[2]= 5.0;
	modelo.g_pos_luz1[3]= 0.0;
	modelo.g_pos_luz2[0]= 5.0;
	modelo.g_pos_luz2[1]= -15.0;
	modelo.g_pos_luz2[2]= 5.0;
	modelo.g_pos_luz2[3]= 0.0;
}


void myInit()
{

	GLfloat LuzAmbiente[]={0.5,0.5,0.5, 0.0};

	glClearColor (0.0, 0.0, 0.0, 0.0);

	glEnable(GL_SMOOTH); /*enable smooth shading */
	glEnable(GL_LIGHTING); /* enable lighting */
	glEnable(GL_DEPTH_TEST); /* enable z buffer */
	glEnable(GL_NORMALIZE);

	glDepthFunc(GL_LESS);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzAmbiente); 
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado.lightViewer); 
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); 

	initModelo();
	initEstado();
	modelo.quad=gluNewQuadric();
	gluQuadricDrawStyle(modelo.quad, GLU_FILL);
	gluQuadricNormals(modelo.quad, GLU_OUTSIDE);
	
	
	//le o grafodo fich
	leGrafo();


	//atribuir a posicao do objecto/user que faz login no jogo
	modelo.objecto.pos.x = nos[0].x;
	modelo.objecto.pos.y = nos[0].y;
	modelo.objecto.pos.z = nos[0].z;


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
	printf("n,N - Liga/Desliga apresentação das normais \n");
	printf("******* grafos ******* \n");
	printf("F1  - Grava grafo do ficheiro \n");
	printf("F2  - Lê grafo para ficheiro \n");
	printf("F6  - Cria novo grafo\n");
	printf("******* Camera ******* \n");
	printf("Botão esquerdo - Arrastar os eixos (centro da camera)\n");
	printf("Botão direito  - Rodar camera\n");
	printf("Botão direito com CTRL - Zoom-in/out\n");
	printf("PAGE_UP, PAGE_DOWN - Altera distância da camara \n");
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
	glLightfv(GL_LIGHT0, GL_POSITION, modelo.g_pos_luz1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white_amb);
	glLightfv(GL_LIGHT1, GL_POSITION, modelo.g_pos_luz2);

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
#define STEP 10
	glBegin(GL_QUADS);
		glNormal3f(0,0,1);
		for(int i=-300;i<300;i+=STEP)
			for(int j=-300;j<300;j+=STEP){
				glVertex2f(i,j);
				glVertex2f(i+STEP,j);
				glVertex2f(i+STEP,j+STEP);
				glVertex2f(i,j+STEP);
			}
	glEnd();
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

GLboolean detectaColisao(GLfloat nx,GLfloat ny,GLfloat nz)
{/*
    GLuint i=(nx+MAZE_HEIGHT*0.5+0.5),j=(int)(nz+MAZE_WIDTH*0.5+0.5);
    if(mazedata[i][j]=='*')
    {
        return GL_TRUE;
    }*/
    return(GL_FALSE);
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
		d = sqrt(((nx - modelo.objecto.pos.x)*(nx - modelo.objecto.pos.x))+((ny - modelo.objecto.pos.y)*(ny - modelo.objecto.pos.y))+((nz - modelo.objecto.pos.z)*(nz - modelo.objecto.pos.z)));
		
		if(d <= (raio+3))
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
		glTranslatef(modelo.objecto.pos.x,modelo.objecto.pos.y,modelo.objecto.pos.z);
		GLdouble angOrientacao = graus(atan2(ny-modelo.objecto.pos.y,nx-modelo.objecto.pos.x));
		GLdouble catetoOposto = nz - modelo.objecto.pos.z;
		GLdouble tamanho = sqrt(pow((nx-modelo.objecto.pos.x),2)+pow((ny-modelo.objecto.pos.y),2));
		GLdouble angInclinacao = graus(atan2(catetoOposto,tamanho));
		glRotated(angOrientacao,0,0,1);
		GLdouble nx2 = (nx - modelo.objecto.pos.x)*cos(rad(angOrientacao)) + (nz - modelo.objecto.pos.z)*sin(rad(angOrientacao));
		GLdouble ny2 = (nz - modelo.objecto.pos.z)*cos(rad(angOrientacao)) - (nx - modelo.objecto.pos.x)*sin(rad(angOrientacao));
		GLdouble dist = sqrt(pow(nx -modelo.objecto.pos.x,2) + pow(ny - modelo.objecto.pos.y,2) + pow(nz - modelo.objecto.pos.z,2));
		GLdouble nz2 = modelo.objecto.pos.z + nx2/tamanho*catetoOposto;

		if((0 <= nx2 && nx2 <= tamanho) && (-larg/2.0 <= ny2 && ny2 <= larg/2.0) && (nz2 - (larg/2.0+0.1) <= ny && ny <= ny2 + (larg/2.0+0.1)))
		{
			flag = false;
		}
		glPopMatrix();
	}
	return flag;
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
			gluQuadricOrientation(modelo.quad,GLU_OUTSIDE);
			gluCylinder(modelo.quad, raio_c, raio_c, comp, 20, 1);//normal È desenhada automaticamente pela funcao
			glPopMatrix();	

}

void Caminho()
{
	//GLUquadricObj *obj = gluNewQuadric();

	desenhaCilindro(PosTodosUsers[0][0],PosTodosUsers[0][1],PosTodosUsers[0][2],PosTodosUsers[1][0],PosTodosUsers[1][1],PosTodosUsers[1][2],3.0);
}

void desenhaLigacao(Arco arco)
{
	No *noi,*nof;
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
			material(slate);
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


void desenhaLabirinto(){
	GLfloat xi,yi,zi,xf,yf,zf,raio;
	glPushMatrix();
		glTranslatef(0,0,0.05);
		//glScalef(5,5,5);
	
		for(int i=0; i<numNos; i++){
			glPushMatrix();
			material(azul);
				glTranslatef(nos[i].x,nos[i].y,nos[i].z);
				//glutSolidCube(0.5);
				glutSolidSphere((K_ESFERA/2.0),20,20);
			glPopMatrix();
			//desenhaNo(i);
		}
		material(emerald);
		for(int i=0; i<numArcos; i++){
			desenhaLigacao(arcos[i]);
			//Caminho();

		}
	glPopMatrix();
}

void desenhaEixo(){
	gluCylinder(modelo.quad,0.5,0.5,20,16,15);
	glPushMatrix();
		glTranslatef(0,0,20);
		glPushMatrix();
			glRotatef(180,0,1,0);
			gluDisk(modelo.quad,0.5,2,16,6);
		glPopMatrix();
		gluCylinder(modelo.quad,2,0,5,16,15);
	glPopMatrix();
}

#define EIXO_X		1
#define EIXO_Y		2
#define EIXO_Z		3

void desenhaPlanoDrag(int eixo){
	glPushMatrix();
		glTranslated(estado.eixo[0],estado.eixo[1],estado.eixo[2]);
		switch (eixo) {
			case EIXO_Y :
					if(abs(estado.camera.dir_lat)<M_PI/4)
						glRotatef(-90,0,0,1);
					else
						glRotatef(90,1,0,0);
					material(red_plastic);
				break;
			case EIXO_X :
					if(abs(estado.camera.dir_lat)>M_PI/6)
						glRotatef(90,1,0,0);
					material(azul);
				break;
			case EIXO_Z :
					if(abs(cos(estado.camera.dir_long))>0.5)
						glRotatef(90,0,0,1);

					material(emerald);
				break;
		}
		glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-100,0,-100);
			glVertex3f(100,0,-100);
			glVertex3f(100,0,100);
			glVertex3f(-100,0,100);
		glEnd();
	glPopMatrix();
}

void desenhaEixos(){

	glPushMatrix();
		glTranslated(estado.eixo[0],estado.eixo[1],estado.eixo[2]);
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


	if(estado.light){
		//Posicionar a câmera
		glRotatef(graus(-M_PI/2.0), 1, 0, 0);
		glRotatef(graus(M_PI/2.0-modelo.objecto.dir), 0, 0, 1);
		glTranslatef(-modelo.objecto.pos.x, -modelo.objecto.pos.y, -modelo.objecto.pos.z-K_ESFERA-DISTANCIA_SOLO);
		putLights((GLfloat*)white_light);
	}else{
		//Posicionar a câmera
		putLights((GLfloat*)white_light);
		glRotatef(graus(-M_PI/2.0), 1, 0, 0);
		glRotatef(graus(M_PI/2.0-modelo.objecto.dir), 0, 0, 1);
		glTranslatef(-modelo.objecto.pos.x, -modelo.objecto.pos.y, -modelo.objecto.pos.z-K_ESFERA-DISTANCIA_SOLO);
	}
}

void display(void)
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	setCamera();

	//material(slate);
	//desenhaSolo();
	
	desenhaEixos();
	
	desenhaLabirinto();
 
	if(estado.eixoTranslaccao) {
		// desenha plano de translacÁ„o
		cout << "Translate... " << estado.eixoTranslaccao << endl; 
		desenhaPlanoDrag(estado.eixoTranslaccao);

	}

	glFlush();
	glutSwapBuffers();

}



void Timer(int value)
{
	glutTimerFunc(estado.timer, Timer, 0);
	
	

	GLfloat	x1 = modelo.objecto.pos.x;
	GLfloat y1 = modelo.objecto.pos.y;
	GLfloat z1 = modelo.objecto.pos.z;

	GLfloat	x2 = modelo.objecto.pos.x+estado.camera.velh*cos(modelo.objecto.dir);
	GLfloat y2 = modelo.objecto.pos.y+estado.camera.velv*sin(modelo.objecto.dir);
	GLfloat z2 = modelo.objecto.pos.z+estado.camera.velv; 

	GLfloat d = sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2)); //distancia ao ponto de colisao

	GLfloat k = (d - DIMENSAO_CAMARA/2.0)/estado.camera.velTotal;
	GLfloat raio = K_ESFERA/2.0;
	if(estado.teclas.q)
	{
		modelo.objecto.pos.z=modelo.objecto.pos.z+VELv;
		estado.teclas.q=GL_FALSE;
	}
	if(estado.teclas.a)
	{
		modelo.objecto.pos.z=modelo.objecto.pos.z-VELv;
		estado.teclas.a=GL_FALSE;
	}
	if(estado.teclas.left)
	{
		modelo.objecto.dir+=0.1;
	}
	
	if(estado.teclas.right)
	{
		modelo.objecto.dir-=0.1;
	}

	if(estado.teclas.up)
	{
		modelo.objecto.pos.x=modelo.objecto.pos.x+estado.camera.velh*cos(modelo.objecto.dir);
		modelo.objecto.pos.y+=estado.camera.velv*sin(modelo.objecto.dir);
		//modelo.objecto.pos.z = modelo.objecto.pos.z + estado.camera.velv;
	}
	
	if(estado.teclas.down)
	{
		modelo.objecto.pos.x=modelo.objecto.pos.x-VELv*cos(modelo.objecto.dir);
		modelo.objecto.pos.y-=VELv*sin(modelo.objecto.dir);
	}

	

	
	if(estado.debug)
		printf("Velocidade %.2f \n",modelo.objecto.vel);
	
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
				if(estado.lightViewer)
					estado.lightViewer=0;
				else
					estado.lightViewer=1;
				glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado.lightViewer);
				glutPostRedisplay();
			break;
		case 'k':
		case 'K':
				estado.light=!estado.light;
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
				estado.apresentaNormais=!estado.apresentaNormais;
				glutPostRedisplay();
			break;    		
		case 'i':
		case 'I':
				initEstado();
				initModelo();
				glutPostRedisplay();
			break;
		case 'a':
		case 'A':
				estado.teclas.a=GL_TRUE;
				//estado.camera.center[2]-=0.2;
			break;
		case 'q':
		case 'Q':
				estado.teclas.q=GL_TRUE;
				//estado.camera.center[2]+=0.2;
			break;
	}
	if(estado.debug)
		printf("Carregou na tecla %c\n",key);
	
}

// Callback para interaccao via teclado (largar a tecla)
void KeyUp(unsigned char key, int x, int y)
{
	switch (key) {
			// ... accoes sobre largar teclas ...
			
		case 'Q' :
		case 'q' : estado.teclas.q=GL_FALSE;
			break;
		case 'A' :
		case 'a' : estado.teclas.a=GL_FALSE;
			break;
			
	}
	
	if(estado.debug)
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
			estado.teclas.right=GL_TRUE;
			break;
		case GLUT_KEY_LEFT :
			estado.teclas.left=GL_TRUE;
			break;
		case GLUT_KEY_UP :
			estado.teclas.up=GL_TRUE;
			break;
		case GLUT_KEY_DOWN :
			estado.teclas.down=GL_TRUE;
			break;
	}

	
	if(estado.debug)
		printf("Carregou na tecla especial %d\n",key);

}

void SpecialKeyUp(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_RIGHT :
			estado.teclas.right=GL_FALSE;
			break;
		case GLUT_KEY_LEFT :
			estado.teclas.left=GL_FALSE;
			break;
		case GLUT_KEY_UP :
			estado.teclas.up=GL_FALSE;
			break;
		case GLUT_KEY_DOWN :
			estado.teclas.down=GL_FALSE;
			break;
	}
	if(estado.debug)
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
/*void desenhaMenuLogin()
{
    
	float width  = glutGet(GLUT_WINDOW_WIDTH);
	float height = glutGet(GLUT_INIT_WINDOW_HEIGHT);
	
	
    
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(0,100,0,100);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
	glColor3f(1.0, 1.0, 1.0);
    
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
    
    
	glBindTexture(GL_TEXTURE_2D, txtLogin.TextureID);
	
	
	glPushMatrix();
	glTranslatef(0,-10,0);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0,0,-0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(100,0,-0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(100,100,-0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0,100,-0.5);
    
    glEnd();
    
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_TEXTURE_2D);
    
	bitmapCenterStringLogin(txtBox.user.c_str(),35,60,0);
	
	bitmapCenterStringLogin(c.c_str(),35,54,0);
    
}

void setProjectionLogin(int x, int y, GLboolean picking)
{
    glLoadIdentity();
	if (picking) { // se está no modo picking, lê viewport e define zona de picking
		GLint vport[4];
		glGetIntegerv(GL_VIEWPORT, vport);
		gluPickMatrix(x, glutGet(GLUT_WINDOW_HEIGHT)  - y, 4, 4, vport); // Inverte o y do rato para corresponder à jana
	}
	
    gluOrtho2D(0,100,0,100);
}*/

void loginWindow()
{
	bool checkLogin = login();
	if(checkLogin)
	{
		printf("Login efectuado com Sucesso!!\n");
		myInit();
		imprime_ajuda();
	}else{
		printf("Username ou Password Errados!!");
	}

}

void setProjection(int x, int y, GLboolean picking){
    glLoadIdentity();
	if (picking) { // se est· no modo picking, lÍ viewport e define zona de picking
		GLint vport[4];
		glGetIntegerv(GL_VIEWPORT, vport);
		gluPickMatrix(x, glutGet(GLUT_WINDOW_HEIGHT)  - y, 4, 4, vport); // Inverte o y do rato para corresponder ‡ jana
	}
	    
	gluPerspective(estado.camera.fov,(GLfloat)glutGet(GLUT_WINDOW_WIDTH) /glutGet(GLUT_WINDOW_HEIGHT) ,1,500);

}

/*void setProjection(int x, int y, GLboolean picking){
	glLoadIdentity();
	if(picking)
	{
		glOrtho(-DIMENSAO_CAMARA/2.0,DIMENSAO_CAMARA/2.0,
			-DIMENSAO_CAMARA/2.0,DIMENSAO_CAMARA/2.0,
			0.0,DIMENSAO_CAMARA/2.0+VELv);//VELv È temporario
	}
}*/


void myReshape(int w, int h){	
	glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
	setProjection(0,0,GL_FALSE);
	glMatrixMode(GL_MODELVIEW);
}


void motionRotate(int x, int y){
#define DRAG_SCALE	0.01
	double lim=M_PI/2-0.1;
	estado.camera.dir_long+=(estado.xMouse-x)*DRAG_SCALE;
	estado.camera.dir_lat-=(estado.yMouse-y)*DRAG_SCALE*0.5;
	if(estado.camera.dir_lat>lim)
		estado.camera.dir_lat=lim;
	else 
		if(estado.camera.dir_lat<-lim)
			estado.camera.dir_lat=-lim;
	estado.xMouse=x;
	estado.yMouse=y;
	glutPostRedisplay();
}

void motionZoom(int x, int y){
#define ZOOM_SCALE	0.5
	estado.camera.dist-=(estado.yMouse-y)*ZOOM_SCALE;
	if(estado.camera.dist<5)
		estado.camera.dist=5;
	else 
		if(estado.camera.dist>200)
			estado.camera.dist=200;
	estado.yMouse=y;
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
	glPushMatrix(); // guarda a projecÁ„o
		glLoadIdentity();
		setProjection(x,y,GL_TRUE);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCamera();
	desenhaPlanoDrag(estado.eixoTranslaccao);
	
	n = glRenderMode(GL_RENDER);
	if (n > 0) {
		glGetIntegerv(GL_VIEWPORT, vp);
		glGetDoublev(GL_PROJECTION_MATRIX, proj);
		glGetDoublev(GL_MODELVIEW_MATRIX, mv);
		gluUnProject(x, glutGet(GLUT_WINDOW_HEIGHT) - y, (double) buffer[2] / UINT_MAX, mv, proj, vp, &newx, &newy, &newz);
		printf("Novo x:%lf, y:%lf, z:%lf\n\n", newx, newy, newz);
		switch (estado.eixoTranslaccao) {
			case EIXO_X :
					estado.eixo[0]=newx;
					//estado.eixo[1]=newy;
				break;
			case EIXO_Y :
					estado.eixo[1]=newy;
					//estado.eixo[2]=newz;
				break;
			case EIXO_Z :
					//estado.eixo[0]=newx;
					estado.eixo[2]=newz;
				break;		
		}
		glutPostRedisplay();
	}


	glMatrixMode(GL_PROJECTION); //repıe matriz projecÁ„o
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
	glPushMatrix(); // guarda a projecÁ„o
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
			ptr += 3 + ptr[0]; // ptr[0] contem o n˙mero de nomes (normalmente 1); 3 corresponde a numnomes, zmin e zmax
		}
	}


	glMatrixMode(GL_PROJECTION); //repıe matriz projecÁ„o
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	return objid;
}

void mouse(int btn, int state, int x, int y){
	switch(btn) {
		case GLUT_RIGHT_BUTTON :
					if(state == GLUT_DOWN){
						estado.xMouse=x;
						estado.yMouse=y;
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
						estado.eixoTranslaccao=picking(x,y);
						if(estado.eixoTranslaccao)
							glutMotionFunc(motionDrag);
					cout << "Right down - objecto:" << estado.eixoTranslaccao << endl;
					}
					else{
						if(estado.eixoTranslaccao!=0) {
							estado.camera.center[0]=estado.eixo[0];
							estado.camera.center[1]=estado.eixo[1];
							estado.camera.center[2]=estado.eixo[2];
							glutMotionFunc(NULL);
							estado.eixoTranslaccao=0;
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  

    glutInitWindowSize(640, 480);
    glutCreateWindow("Think&Code");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	
	
	
	glutTimerFunc(estado.timer, Timer, 0);

	glutKeyboardFunc(keyboard);
	
	glutSpecialFunc(SpecialKey);
	//glutKeyboardFunc(KeyUp);
	glutSpecialUpFunc(SpecialKeyUp);
	
	glutMouseFunc(mouse);
	
	
	

	loginWindow();
	//myinit + imprime ajuda dentro do login

	myInit();

	imprime_ajuda();


    glutMainLoop();
	
	return 0;
}
