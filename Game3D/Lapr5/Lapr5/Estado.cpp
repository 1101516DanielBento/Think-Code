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
	eixo = new GLdouble[3];
	eixo[0] = 0;
	eixo[1] = 0;
	eixo[2] = 0;
	setLight(GL_FALSE);
	setApresentaNormais(GL_FALSE);
	setLightViewer(1);
	setEixo(0,0,0);
	setLocating(0);
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
	eixo[0] = x;
	eixo[1] = y;
	eixo[2] = z;
	
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

GLdouble* Estado::getEixo() const
{
	return eixo;
}

GLint Estado::getTimer() const
{
	return timer;
}

void Estado :: setLocating(int loc)
{
	locating = loc;
}

int Estado :: getLocating()const
{
	return locating;
}