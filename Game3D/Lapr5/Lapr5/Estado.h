//
//  Estado.h
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#ifndef ESTADO_
#define ESTADO_

#include <iostream>

#include "Camera.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Estado{
	
private:
	Camera		*camera;
	int			xMouse,yMouse;
	GLboolean	light;
	GLboolean	apresentaNormais;
	GLboolean   ortho;
	GLint		lightViewer;
	GLint		eixoTranslaccao;
	GLdouble	eixoX;
	GLdouble	eixoY;
	GLdouble	eixoZ;
	GLint       timer;
	int locating;
	GLboolean	debug;
	
public:
	
	Estado();
	void setCamera(Camera *camera);
	void setXMouse(int xm);
	void setYMouse(int ym);
	void setLight(GLboolean light);
	void setApresentaNormais(GLboolean aN);
	void setOrtho(GLboolean o);
	void setLightViewer(GLint lv);
	void setEixoTrans(GLint eixoTranslaccao);
	void setEixo(GLdouble x,GLdouble y,GLdouble z);
	void setTimer(GLint timer);
	void setLocating(int loc);
	void setDebug(GLboolean d);
	
	
	Camera* getCamera() const;
	int getXMouse() const;
	int getYMouse() const;
	GLboolean getLight() const;
	GLboolean getApresentaNormais() const;
	GLboolean getOrtho() const;
	GLint getLightViewer() const;
	GLint getEixoTrans() const;
	GLdouble getEixoX() const;
	GLdouble getEixoY() const;
	GLdouble getEixoZ() const;
	GLint getTimer()	const;
	int getLocating()	const;
	GLboolean getDebug() const;
	
};

#endif /* defined(__Grafo3DProject__Estado__) */
