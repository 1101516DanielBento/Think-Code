//
//  Camera.cpp
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#include "Camera.h"

Camera::Camera(GLfloat x, GLfloat y, GLfloat z)
{
	this->eyeX=x;
	this->eyeY=y;
	this->eyeZ=z;
}

Camera::Camera()
{

	setDirLat(0.0);
	setDirLong(0.0);
	setFov(30);
	setDistance(100);
	setEyeX(40);
	setEyeY(40);
	setEyeZ(0);
	setCenterX(0);
	setCenterY(0);
	setCenterZ(0);
	setVelv(10.0);
}

void Camera::setFov(GLfloat fov)
{
	this->fov = fov;
}

void Camera::setDirLat(GLdouble dirlat)
{
	this->dir_lat = dirlat;
}

void Camera::setDirLong(GLdouble dirlong)
{
	this->dir_long = dirlong;
}

void Camera::setDistance(GLfloat dist)
{
	dist = dist;
}

void Camera::setEyeX(GLfloat x)
{
	eyeX = x;
}

void Camera::setEyeY(GLfloat y)
{
	eyeY = y;
}

void Camera::setEyeZ(GLfloat z)
{
	eyeZ = z;
}

void Camera::setCenterX(GLfloat cx)
{
	centerX = cx;
}

void Camera::setCenterY(GLfloat cy)
{
	centerY = cy;
}

void Camera::setCenterZ(GLfloat cz)
{
	centerZ = cz;
}

void Camera::setVelv(GLfloat vel)
{
	velv = vel;
}

GLfloat Camera::getFov() const
{
	return fov;
}

GLdouble Camera::getDirLat() const
{
	return dir_lat;
}

GLdouble Camera::getDirLong()const
{
	return dir_long;
}

GLfloat Camera::getDistance() const
{
	return dist;
}

GLfloat Camera::getEyeX() const
{
	return eyeX;
}

GLfloat Camera::getEyeY() const
{
	return eyeY;
}

GLfloat Camera::getEyeZ() const
{
	return eyeZ;
}

GLfloat Camera::getCenterX() const
{
	return centerX;
}

GLfloat Camera::getCenterY() const
{
	return centerY;
}

GLfloat Camera::getCenterZ() const
{
	return centerZ;
}

GLfloat Camera::getVelv() const
{
	return velv;
}

void Camera::drawMe()
{
	gluLookAt(eyeX*cos(dir_long),eyeY*sin(dir_long),eyeZ,centerX,centerY,centerZ,0.0,0.0,0.5);
}

GLfloat Camera::rotateLeft()
{
	dir_long -= M_PI/36;
	return dir_long;
}

void Camera::rotateRight()
{
	dir_long+= M_PI/36;
}