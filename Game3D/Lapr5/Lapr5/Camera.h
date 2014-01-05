//
//  Camera.h
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//
#ifndef CAMERA_H
#define CAMERA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include "Point.h"
#include <math.h>

#include <iostream>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

class Camera{
	
private:
	
	GLfloat fov;
	GLdouble dir_lat;
	GLdouble dir_long;
	GLfloat dist;
	GLfloat eyeX, eyeY, eyeZ;
	GLfloat centerX, centerY, centerZ;
	GLfloat rotation;
	GLfloat velv;
	
public:
	
	Camera(GLfloat x, GLfloat y, GLfloat z);
	Camera();
	
	void setFov(GLfloat fov);
	void setDirLat(GLdouble dirlat);
	void setDirLong(GLdouble dirlong);
	void setDistance(GLfloat dist);
	void setEyeX(GLfloat x);
	void setEyeY(GLfloat y);
	void setEyeZ(GLfloat z);
	void setCenterX(GLfloat cx);
	void setCenterY(GLfloat cy);
	void setCenterZ(GLfloat cz);
	void setVelv(GLfloat vel);
	
	GLfloat getFov() const;
	GLdouble getDirLat() const;
	GLdouble getDirLong()const;
	GLfloat getDistance() const;
	GLfloat getEyeX() const;
	GLfloat getEyeY() const;
	GLfloat getEyeZ() const;
	GLfloat getCenterX() const;
	GLfloat getCenterY() const;
	GLfloat getCenterZ() const;
	GLfloat getVelv() const;
	
	void drawMe();
	GLfloat rotateLeft();
	void rotateRight();
};

#endif
