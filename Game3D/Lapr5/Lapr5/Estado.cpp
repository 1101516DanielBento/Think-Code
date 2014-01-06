//
//  Estado.cpp
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#include "Estado.h"

Estado::Estado()
{
	camera = new Camera();
	//eixo = new GLdouble[3];
	eixoX = 0;
	eixoY = 0;
	eixoZ = 0;
	setLight(GL_FALSE);
	setApresentaNormais(GL_FALSE);
	setLightViewer(1);
	setEixo(0,0,0);
	setLocating(0);
	//debug = GL_TRUE;
}

void Estado::setCamera(Camera *camera)
{
	this->camera = camera;
}

void Estado::setXMouse(int xm)
{
	xMouse = xm;
}

void Estado::setYMouse(int ym)
{
	yMouse = ym;
}

void Estado::setLight(GLboolean light)
{
	this->light=light;
}

void Estado::setApresentaNormais(GLboolean aN)
{
	apresentaNormais=aN;
}

void Estado::setOrtho(GLboolean o)
{
	ortho = o;
}

void Estado::setLightViewer(GLint lv)
{
	lightViewer = lv;
}

void Estado::setEixoTrans(GLint eixoTranslaccao)
{
	this->eixoTranslaccao = eixoTranslaccao;
}

void Estado::setEixo(GLdouble x,GLdouble y,GLdouble z)
{
	eixoX = x;
	eixoY = y;
	eixoZ = z;
	
}

void Estado::setEixoX(GLfloat x)
{
	eixoX = x;
}

void Estado::setEixoY(GLfloat y)
{
	eixoY = y;
}

void Estado::setEixoZ(GLfloat z)
{
	eixoZ = z;
}

void Estado::setTimer(GLint timer)
{
	this->timer = timer;
}

Camera* Estado::getCamera() const
{
	return camera;
}

int Estado::getXMouse() const
{
	return xMouse;
}

int Estado::getYMouse() const
{
	return yMouse;
}

GLboolean Estado::getLight() const
{
	return light;
}

GLboolean Estado::getApresentaNormais() const
{
	return apresentaNormais;
}

GLboolean Estado::getOrtho() const
{
	return ortho;
}

GLint Estado::getLightViewer() const
{
	return lightViewer;
}

GLint Estado::getEixoTrans() const
{
	return eixoTranslaccao;
}

GLdouble Estado::getEixoX() const
{
	return eixoX;
}

GLdouble Estado::getEixoY() const
{
	return eixoY;
}

GLdouble Estado::getEixoZ() const
{
	return eixoZ;
}

GLint Estado::getTimer() const
{
	return timer;
}

GLboolean Estado::getDebug()
{
	return debug;
}

void Estado :: setLocating(int loc)
{
	locating = loc;
}

int Estado :: getLocating()const
{
	return locating;
}