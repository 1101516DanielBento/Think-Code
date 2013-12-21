#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//lighting
GLfloat LuzAmbiente[]= { 0.5f,0.5f,0.5f,1.0f};
GLfloat LuzDifusa[]= {0.5f,0.5f,0.5f,1.0f};
GLfloat PosicaoLuz[] = {5.0f,25.0f,5.0f,1.0f};
GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};

//variaveis do mouse: W = tamanho janela(windows), mouse = posicao mouse
GLint mouse_x,mouse_y, W_x,W_y,obj_select;

//variaveis de estado, state variables para Ortho/Perpective view, lighting on/off
static int view_state = 0, light_state = 0;
/*GLboolean view_state = GL_TRUE;
GLboolean light_state= GL_TRUE;*/

// usar para por X's e O's a rodar
//GLboolean spin = GL_FALSE, spinboxes = GL_FALSE;
GLint spin, spinboxes;
//---------logica-------------
//win = 1 player ganha, -1 computador ganha, 2 empate
//player ou computador; 1 = X, -1 = O
//start_game indica quem esta em jogo

GLint player, computer, win, start_game;
//GLboolean start_game = GL_FALSE;

// alinhamento das caixas em quais alguem pode ganhar
// Existem 8 possibilidades, 3 de baixo para cima, 3 horizontais and 2 diagonais
//
// 0 | 1 | 2
// 3 | 4 | 5
// 6 | 7 | 8
//
// informacao linha, coluna, diagonal

//caixas == quadrados pequenos
static int caixas[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

//informacao retida na game board
// 1 = X's, -1 = O's  e 0 = espaco livre

int mapa_caixa[9];//mesa de jogo == mapa_caixa
//centro x,y da localizacao de cada caixa

int object_map[9][2] = {{-6,6},{0,6},{6,6},{-6,0},{0,0},{6,0},{-6,-6},{0,-6},{6,-6}};

//apontador quadric para construir o X
GLUquadricObj *Cilindro;

//comecar a rotina de jogo

void init_game(void)
{
	int i;
	//limpar o mapa de jogo para quando se iniciar um jogo novo
	for(i = 0; i < 9; i++)
	{
		mapa_caixa[i]=0;
	}

	//definir win para 0, assim ainda nao ha vencedor
	win = 0;
	start_game = 1;//o player inicia o jogo
}

//verifica para 3 em linha/coluna/diagonal
//return 1 se houver vencedor

int verifica_movimento()
{
	int i , t= 0;

	//verifica 3 em linha
	for(i = 0; i < 8 ; i++)
	{
		t = mapa_caixa[caixas[i][0]] + mapa_caixa[caixas[i][1]] +mapa_caixa[caixas[i][2]];
		if( (t==3) || (t==-3))
		{
			spinboxes = i;
			return(1);
		}
	}
	t=0;
	//verificacao para empate
	for(i=0; i < 8; i++)
	{
		t = t + abs(mapa_caixa[caixas[i][0]])+abs(mapa_caixa[caixas[i][1]])+abs(mapa_caixa[caixas[i][2]]);
	}

	if(t==24) return(2);

	return 0;
}

//bloquear outros joagdores ????

int bloquear_vitoria()
{
	int i, t;
	for(i = 0; i < 8; i++)
	{
		t = mapa_caixa[caixas[i][0]] + mapa_caixa[caixas[i][1]] +mapa_caixa[caixas[i][2]];
		if((t==2) || (t==-2))
		{
			//procurar espaço vazio
			if(mapa_caixa[caixas[i][0]]==0) mapa_caixa[caixas[i][0]] = computer;
			if(mapa_caixa[caixas[i][1]]==0) mapa_caixa[caixas[i][1]] = computer;
			if(mapa_caixa[caixas[i][2]]==0) mapa_caixa[caixas[i][2]] = computer;
			return 1;
		}
	}
	return 0;
}

//verifica espaço livre num canto da mesa de jogo
int verifica_canto()
{
	int i;
	if(mapa_caixa[0] == 0)
	{
		mapa_caixa[0] = computer;
		i = 1;
		return 1;
	}

	if(mapa_caixa[2] == 0)
	{
		mapa_caixa[2] = computer;
		i = 1;
		return 1;
	}

	if(mapa_caixa[6] == 0)
	{
		mapa_caixa[6] = computer;
		i = 1;
		return 1;
	}

	if(mapa_caixa[8] == 0)
	{
		mapa_caixa[8] = computer;
		i = 1;
		return 1;
	}

	return 0;
}

//verifica se existe algum espaço livre numa linha
// como os cantos ja estao verificados so é necessario verificar
// as caixas 1,3,4,5,7

int verifica_linha()
{
	int i;
	if(mapa_caixa[1] == 0)
	{
		mapa_caixa[1] = computer;
		i = 1;
		return 1;
	}

	if(mapa_caixa[3] == 0)
	{
		mapa_caixa[3] = computer;
		i = 1;
		return 1;
	}

	if(mapa_caixa[4] == 0)
	{
		mapa_caixa[4] = computer;
		i = 1;
		return 1;
	}

	if(mapa_caixa[5] == 0)
	{
		mapa_caixa[5] = computer;
		i = 1;
		return 1;
	}

	if(mapa_caixa[7] == 0)
	{
		mapa_caixa[7] = computer;
		i = 1;
		return 1;
	}

	return 0;
}

//logica para o turno do computador

int turno_computer()
{
	if(bloquear_vitoria()==1) return 1;
	if(verifica_canto()==1) return 1;
	if(verifica_linha()==1)return 1;
	
	return 0;
}


void escreverEcra( int x, int y, char *st)
{
	int l,i;

	l=strlen( st ); // ver a quantidade de char que existe na string
	glRasterPos2i( x, y); // local onde se inicia a escrita
	for( i=0; i < l; i++)  
		{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); // escrever char no ecra
	}

}





void TimerGalo(int timer)
{
	spin++; //aumenta a rotaçao do cubo em 1
	if(spin > 360) spin = 0; // faz reset ao spin se este ultrapassar os 360;
	glutPostRedisplay();
	glutTimerFunc(10,TimerGalo,1); // Reset ao timer
}

//setup do mundo OpenGL, é chamado ao iniciar o jogo
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);//cor preto
	glShadeModel(GL_SMOOTH); //como o objecto vai ser renderizado
	glEnable(GL_DEPTH_TEST);//verifica a profundiade ao ser renderizado

	//Adicionar Lightig a cena
	glLightfv(GL_LIGHT1,GL_AMBIENT,LuzAmbiente);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,LuzDifusa);
	glLightfv(GL_LIGHT1,GL_POSITION,PosicaoLuz);
	glEnable(GL_LIGHTING);//liga o lighting
	glEnable(GL_LIGHT1);//liga a luz1

	start_game = 0;
	win = 0;

	//criar um novo quadric object

	Cilindro = gluNewQuadric();
	gluQuadricDrawStyle(Cilindro,GLU_FILL);
	gluQuadricNormals(Cilindro,GLU_SMOOTH);
	gluQuadricOrientation(Cilindro,GLU_OUTSIDE);


}

void Desenha_O(int x, int y, int z, int angle)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glRotatef(angle,1,0,0);
	glutSolidTorus(0.5,2.0,8,16);
	glPopMatrix();
}

void Desenha_X(int x, int y, int z, int angle)
{
	glPushMatrix();
		glTranslatef(x,y,z);
		glPushMatrix();
			glRotatef(angle,1,0,0);
			glRotatef(90,0,1,0);
			glRotatef(45,1,0,0);
			glTranslatef(0,0,-3);
			gluCylinder(Cilindro,0.5,0.5,6,16,16);
		glPopMatrix();
		glPushMatrix();
			glRotatef(angle,1,0,0);
			glRotatef(90,0,1,0);
			glRotatef(315,1,0,0);
			glTranslatef(0,0,-3);
			gluCylinder(Cilindro,0.5,0.5,6,16,16);
		glPopMatrix();
	glPopMatrix();
}

//desenhar o jogo

void displayGalo()
{
	//char txt[30];
	int ix, iy,i,j;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpar ecra
	glMatrixMode(GL_PROJECTION); //dizer ao openGL que estamos a fazer trabalho com a matrix
	glLoadIdentity();
	glOrtho(-9.0,9.0,-9.0,9.0,0.0,30.0);//definir a Ortho view
	glMatrixMode(GL_MODELVIEW);// dizer ao opengl que estamos a usar model view
	glLoadIdentity();//limpar a model matrix

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glColor3f(0.0,0.0,1.0);

	if(start_game == 0)
	{
		escreverEcra(-2,0,"Jogo do Galo");
		escreverEcra(-3,-1,"Para iniciar click --> ");
		escreverEcra(-3,-2,"Botao direito para X's");
		escreverEcra(-3,-3,"Botao esquerdo para O's");
	}

	if(win == 1) escreverEcra(-2,1,"Ganhaste");
	if(win == -1) escreverEcra(-2,1,"Perdeste! Computador Ganhou");
	if(win == 2) escreverEcra(-2,1,"Empate!!!");


	//definir a view e imprimir a view state no ecra
	if(view_state == 1)
	{
		glColor3f( 0.0, 0.0, 1.0);
		escreverEcra(-3, 8, "Perspective View");
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, 1, 1, 30);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}else{
		glColor3f(0.0,0.0,1.0);
		escreverEcra(-2,8,"Ortho View");
	}

	//Lighting On/Off
	if(light_state == 1)
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
	}else{
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
	}


	gluLookAt(0,0,20,0,0,0,0,1,0);

	//desenhar grelha de jogo
	for(ix = 0; ix< 4 ; ix++)
	{
		glPushMatrix();
		glColor3f(1,1,1);
		glBegin(GL_LINES);
		glVertex2i(-9,-9+ix*6);
		glVertex2i(9,-9+ix*6);
		glEnd();
		glPopMatrix();
	}

	for(iy = 0; iy < 4 ; iy++)
	{
		glPushMatrix();
		glColor3f(1,1,1);
		glBegin(GL_LINES);
		glVertex2i(-9+iy*6,9);
		glVertex2i(-9+iy*6,-9);
		glEnd();
		glPopMatrix();
	}

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
	glColor4f(0.5,0.5,0.5,1.0);
	glColorMaterial(GL_FRONT,GL_EMISSION);
	glColor4f(0.0,0.0,0.0,1.0);
	glColorMaterial(GL_FRONT, GL_SPECULAR);
	glColor4f(0.35, 0.35, 0.35, 1.0);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glColor4f(0.69, 0.69, 0.69, 1.0);
	glColor3f( 1.0, 0.0, 1.0);  // cor do cubo

	for(i = 0; i < 9; i++)
	{
		j = 0;
		if(abs(win) == 1)
		{
			if((i==caixas[spinboxes][0]) || (i == caixas[spinboxes][1]) || (i==caixas[spinboxes][2]))
			{
				j = spin;
			}else{
				j=0;
			}
		}
		if(mapa_caixa[i]==1)
			Desenha_X(object_map[i][0],object_map[i][1],-1,j);

		if(mapa_caixa[i] == -1)
			Desenha_O(object_map[i][0],object_map[i][1],-1,j);
	}
	glutSwapBuffers();
}

//reshape e chamado quando a janela e redimensionada

void reshape(GLint lar, GLint alt)
{
	W_x = lar;
	W_y = alt;
	glViewport(0,0,lar,alt);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


//Teclado

void keyboard_Galo(unsigned char key,int x, int y)
{
	switch(key)
	{
	case 'v':
	case 'V':
		view_state = abs(view_state -1);
		break;
	case 'l':
	case 'L':
		light_state = abs(light_state -1);
		break;
	case 27:
		exit(0);//sair do jogo ao pressionar 'ESC'
		break;
	default:
		break;
	}
}

//rato

void mouse_Galo(GLint button, GLint state, GLint x,GLint y)
{
	//converter coordenadas de um windows mouse para coordenadas openGL
	mouse_x = (18*(GLfloat) ((GLfloat)x/(GLfloat)W_x))/6;
	mouse_y = (18*(GLfloat)((GLfloat)y/(GLfloat)W_y))/6;

	obj_select = mouse_x+mouse_y*3;

	if(start_game == 0)
	{
		if((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
		{
			player =1;
			computer = -1;
			init_game();
			return;
		}

		if((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{

			player = -1;
			computer = 1;
			init_game();
			turno_computer();
			return;
		}
	}

	if(start_game == 1)
	{
		if((button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN))
		{
			if(win == 0)
			{
				if(mapa_caixa[obj_select] == 0)
				{
					mapa_caixa[obj_select] = player;
					win = verifica_movimento();
					if(win == 1)
					{
						start_game = 0;
						return;
					}
					turno_computer();
					win = verifica_movimento();
					if(win == 1)
					{
						win = -1;
						start_game = 0;
					}
				}
			}
		}

	}
	if(win == 2)
		start_game = 0;
}

//main
/*
int main (int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(10,10);
	glutCreateWindow(argv[0]);
	glutSetWindowTitle("JOGO DO GALO 3D");
	init();
	glutDisplayFunc(displayGalo);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard_Galo);
	glutMouseFunc(mouse_Galo);
	glutTimerFunc(10, TimerGalo,1);
	glutMainLoop();
	return 0;

}*/