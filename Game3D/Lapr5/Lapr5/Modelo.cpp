//
//  Modelo.cpp
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#include "Modelo.h"

Modelo::Modelo(/*int numUsers*/)
{
	g_pos_luz1 = new GLfloat[4];
	g_pos_luz2 = new GLfloat[4];
	quad = gluNewQuadric();
	
	/*mdls = new StudioModel*[numUsers];
	for(int i=0;i<numUsers;i++)
		mdls[i] = new StudioModel();*/

	mod = new Objecto();
	
	texID = new GLuint[NUM_TEXTURAS];
}

Modelo::~Modelo()
{
}

GLfloat* Modelo::getGPosLuz1() const
{
	return g_pos_luz1;
}

GLfloat* Modelo::getGPosLuz2() const
{
	return g_pos_luz2;
}

GLfloat Modelo::getEscala() const
{
	return escala;
}

GLUquadric* Modelo::getQuad() const
{
	return quad;
}

/*StudioModel** Modelo::getMdls() const
{
	return mdls;
}*/

Objecto* Modelo::getObjecto()
{
	return mod;
}

int Modelo::getCameraMode()
{
	return cameraMode;
}

void Modelo::setObjecto(Objecto* obj)
{
	mod = obj;
}

GLuint* Modelo::getTexID() const
{
	return texID;
}

void Modelo::setGPosLuz1(GLfloat* g_pos_luz1)
{
	this->g_pos_luz1 = g_pos_luz1;
}

void Modelo::setGPosLuz2(GLfloat* g_pos_luz2)
{
	this->g_pos_luz2 = g_pos_luz2;
}

void Modelo::setEscala(GLfloat escala)
{
	this->escala = escala;
}

void Modelo::setQuad(GLUquadric* quad)
{
	this->quad = quad;
}

/*void Modelo::setMdls(StudioModel** mdls)
{
	this->mdls = mdls;
}*/


void Modelo::setCameraMode(int mode)
{
	this->cameraMode = mode;
}
