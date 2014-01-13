//
//  Teclas.cpp
//  Grafo3DProject
//
//  Created by Pedro on 06/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#include "Teclas.h"

Teclas::Teclas()
{
	right = GL_FALSE;
	down = GL_FALSE;
	left = GL_FALSE;
	up = GL_FALSE;
	q = GL_FALSE;
	a = GL_FALSE;
	r = GL_FALSE;
	v = GL_FALSE;
}

Teclas* Teclas::clone() const
{
	return new Teclas (*this);
}

void Teclas::setQ(GLboolean q)
{
	this->q=q;
}

void Teclas::setA(GLboolean a)
{
	this->a=a;
}

void Teclas::setR(GLboolean r)
{
	this->r=r;
}

void Teclas::setV(GLboolean v)
{
	this->v=v;
}

void Teclas::setUP(GLboolean up)
{
	this->up=up;
}

void Teclas::setDOWN(GLboolean down)
{
	this->down=down;
}

void Teclas::setLEFT(GLboolean left)
{
	this->left=left;
}

void Teclas::setRIGHT(GLboolean right)
{
	this->right=right;
}

GLboolean Teclas::getQ() const
{
	return q;
}

GLboolean Teclas::getA() const
{
	return a;
}

GLboolean Teclas::getR() const
{
	return r;
}

GLboolean Teclas::getV() const
{
	return v;
}

GLboolean Teclas::getUP() const
{
	return up;
}

GLboolean Teclas::getDOWN() const
{
	return down;
}

GLboolean Teclas::getLEFT() const
{
	return left;
}

GLboolean Teclas::getRIGHT() const
{
	return right;
}
