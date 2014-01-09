//
//  Objecto.cpp
//  Grafo3DProject
//
//  Created by Pedro on 05/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//
#include "Objecto.h"

Objecto::Objecto()
{
	this->x=0;
	this->y=0;
	this->z=10;
	this->dir=0;
	this->vel=0.2;
}
Objecto::Objecto(float x, float y)
{
	this->x=x;
	this->y=y;
	
}
Objecto::Objecto(float x, float y, float z)
{
	this->x=x;
	this->y=y;
	this->z=z;
	
}
Objecto* Objecto::clone() const{
	return new Objecto (*this);
}


void Objecto::setX(float x)
{
	
	this->x=x;
}

void Objecto::setY(float y)
{
	
	this->y=y;
}

void Objecto::setZ(float z)
{
	
	this->z=z;
}

void Objecto::setInc(float inc)
{
	
	this->inc=inc;
}

float Objecto::getX() const
{
	
	return x;
}

float Objecto::getY() const
{
	
	return y;
}

float Objecto::getZ() const
{
	
	return z;
}

GLfloat Objecto::getDir() const
{
	
	return dir;
}

GLfloat Objecto::getVel() const
{
	return vel;
}

GLfloat Objecto::getInc() const
{
	return inc;
}

void Objecto::setDir(GLfloat dir)
{
	this->dir = dir;
}

void Objecto::setVel(GLfloat vel)
{
	this->vel = vel;
}

bool Objecto::isValid()
{
	if (x>=0 && y>=0)
		return true;
	return false;
}

void Objecto::invalidate()
{
	x=-1;y=-1;
}

Objecto& Objecto::operator=(const Objecto &p)
{
	if(this!=&p){
		x=p.getX();
		y=p.getY();
		z=p.getZ();
	}
	return (*this);
}