//
//  Objecto.h
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#ifndef OBJECTO_
#define OBJECTO_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Objecto{
protected:
	float x,y,z;
	GLfloat dir;
	GLfloat vel;
	GLfloat inc;
public:
	Objecto();
	Objecto(float x, float y);
	Objecto(float x, float y, float z);
	Objecto* clone() const;
	
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setDir(GLfloat dir);
	void setVel(GLfloat vel);
	void setInc(GLfloat inc);
	
	float getX() const;
	float getY() const;
	float getZ() const;
	GLfloat getDir() const;
	GLfloat getVel() const;
	GLfloat getInc() const;
	
	bool isValid();
	void invalidate();
	
	Objecto& operator=(const Objecto &p);
};

#endif