     
#include <windows.h>
#include <GL/gl.h>       
#include <GL/glut.h>     
#include <math.h>

#define TAM_BLOCO 100
#define PASSO	20


GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat shininess[] = { 50.0 };
GLfloat parede[] = {0.3, 0, 0, 0};
GLfloat piso[] = { 0.0, 0.5, 0.0, 0.0 };
GLfloat posicao_luz[] = { 0.7, 0.7, 0.7, 0.7 };
GLfloat luz_branca[] = {1,1,1,1};
GLfloat lmodel_ambient[] = {1,0.7,0.7,0.7};


GLfloat jogadorX= TAM_BLOCO , jogadorZ=TAM_BLOCO ;
GLfloat mov_x=PASSO, mov_z=0;
GLint angulo=90;
GLint soLimite = 0;




GLint mapa[21][41] =
	{
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
		1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,
		1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,
		1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
		1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,
		1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,
		1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,
		1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,
		1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,
		1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,
		1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,
		1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,
		1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,
		1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,
		1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,
		1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

int pode_mover(float pos_x, float pos_z, float vet_x, float vet_z)
{
	float mundo_x = pos_x + vet_x ;
	float mundo_z = pos_z + vet_z ;

	int ind_x = (int) ((mundo_x + TAM_BLOCO/2) / TAM_BLOCO);
	int ind_z = (int) ((mundo_z + TAM_BLOCO/2) / TAM_BLOCO);

	if(mapa[ind_x][ind_z]) return 0;
	else return 1;
}

//---------------------------------------------

void Draw(void)
{
  int x, z;
  int x_mun, z_mun;


  //limpa todos os pixels
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);										
 
 glLoadIdentity();
 
 gluLookAt(jogadorX,25	,jogadorZ, jogadorX+mov_x,25,jogadorZ+mov_z, 0,1,0);


 glPushMatrix();

  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piso);

  glBegin ( GL_QUADS);

	 glVertex3f(-10000, -TAM_BLOCO/2, -10000);
 	 glVertex3f(-10000, -TAM_BLOCO/2, 10000);
	 glVertex3f(10000, -TAM_BLOCO/2, 10000);
	 glVertex3f(10000, -TAM_BLOCO/2, -10000);

  glEnd();

 glPopMatrix();

 //Paredes
  for(x=0; x < 21; x++)
  {
	for(z=0; z < 41; z++)
	{
	  if(mapa[x][z] == 1) 
	  {
  	     x_mun = x * TAM_BLOCO;
		 z_mun = z * TAM_BLOCO;

		glPushMatrix();

		 glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, parede);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		 glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		
		 glTranslatef(x_mun, 0 ,z_mun);

		 if(soLimite) glutWireCube(TAM_BLOCO);
		 else glutSolidCube(TAM_BLOCO);
			
		glPopMatrix();
		
	  }
	}
  }

 glutSwapBuffers();            
}

//-----------------------------------------------------------------

void Teclas_Especiais(unsigned char key, int x, int y)
{
 switch (key) 
 {
  case 'q':
  case 'Q': soLimite =!soLimite;
			glutPostRedisplay();
			break;
  case  27: exit(0);break; //ESC para sair

 }

}

//-----------------------------------------------------------------

void Teclas_Mover(int key, int x, int y)
{
 float rad;
 
 switch (key) 
 {
  case GLUT_KEY_DOWN: 

	if(pode_mover(jogadorX, jogadorZ, - mov_x, -mov_z))
	{
	  jogadorX = jogadorX-mov_x;
	  jogadorZ = jogadorZ-mov_z;
	}
	break;
	  
	
  case GLUT_KEY_UP: 

	  if(pode_mover(jogadorX, jogadorZ,  mov_x, mov_z))
	  {
	   jogadorX += mov_x;
	   jogadorZ += mov_z;
	  }
	  break;
  
  case GLUT_KEY_LEFT: 
	
	angulo = angulo-10;

	 if(angulo < 0) angulo +=360;


	rad =  (float) (3.14159 * angulo / 180.0f);

	mov_x =  cos(rad) * PASSO;
	mov_z =  sin(rad) * PASSO;
	break;

  
  case GLUT_KEY_RIGHT: 

	  angulo += 10;

	if(angulo >= 360) angulo -=360;
	 
	 rad =  (float) (3.14159 * angulo / 180.0f);

	mov_x = cos(rad) * PASSO;
	mov_z = sin(rad) * PASSO;

	break;
	 
 }
 glutPostRedisplay();
}


void Inicializa(void)
{

 glShadeModel(GL_SMOOTH);

 glClearColor(0.3, 0.6, 0.8, 1.0);
 
 glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_branca);
 glLightfv(GL_LIGHT0, GL_SPECULAR, luz_branca);
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);

 
 glMatrixMode(GL_PROJECTION);
 
 glLoadIdentity();

 //projecao perspectiva
 gluPerspective(90,1,1,3000);

 //sistema de coordenadas do modelo
 glMatrixMode(GL_MODELVIEW);

 //sistema de coordenadas de projecão
 glLoadIdentity();

 glEnable(GL_DEPTH_TEST);			 

 //numeros aleatorios
 srand(GetTickCount());


}

//--------------------------------------------------------------

void main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutCreateWindow("Labirinto LAPRV");
 
 Inicializa();

 glutDisplayFunc(Draw);
 glutKeyboardFunc(Teclas_Especiais);    
 glutSpecialFunc(Teclas_Mover);     
 glutFullScreen();
 glutMainLoop();
 
}



