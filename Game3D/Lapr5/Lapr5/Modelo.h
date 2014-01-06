//
//  Modelo.h
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#ifndef MODELO_
#define MODELO_

#include <string>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include "mdlviewer.h"
#include "Objecto.h"

#define NUM_TEXTURAS 11

using namespace std;

class Modelo
{
private:
	GLfloat *g_pos_luz1;
	GLfloat *g_pos_luz2;
	GLfloat escala;
	GLUquadric *quad;
	//StudioModel **mdls;
	Objecto *mod;
	int cameraMode;
	GLuint *texID;

	
public:
	Modelo(int numUsers);
	~Modelo();
	
	GLfloat* getGPosLuz1() const;
	GLfloat* getGPosLuz2() const;
	GLfloat getEscala() const;
	GLUquadric* getQuad() const;
	//StudioModel** getMdls() const;
	Objecto* getObjecto();
	int getCameraMode();
	GLuint* getTexID() const;

	
	void setGPosLuz1(GLfloat* g_pos_luz1);
	void setGPosLuz2(GLfloat* g_pos_luz2);
	void setEscala(GLfloat escala);
	void setQuad(GLUquadric* quad);
	//void setMdls(StudioModel** mdls);
	void setObjecto(Objecto* mod);
	void setCameraMode(int mode);

};

#endif