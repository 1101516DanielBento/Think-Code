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
	q,a,up,down,left,right=GL_FALSE;
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
