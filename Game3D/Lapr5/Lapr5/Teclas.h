//
//  Teclas.h
//  Grafo3DProject
//
//  Created by Pedro on 06/01/14.
//  Copyright (c) 2014 pedrosimoes. All rights reserved.
//

#ifndef TECLAS_
#define TECLAS_

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Teclas{
private:
	GLboolean q,a,r,v,g,e,l,up,down,left,right;
	
public:
	Teclas();
	Teclas* clone() const;
	
	void setQ(GLboolean q);
	void setA(GLboolean a);
	void setR(GLboolean r);
	void setV(GLboolean v);
	void setE(GLboolean e);
	void setG(GLboolean g);
	void setL(GLboolean l);
	void setUP(GLboolean up);
	void setDOWN(GLboolean down);
	void setLEFT(GLboolean left);
	void setRIGHT(GLboolean right);
	
	GLboolean getQ() const;
	GLboolean getA() const;
	GLboolean getR() const;
	GLboolean getV() const;
	GLboolean getE() const;
	GLboolean getG() const;
	GLboolean getL() const;
	GLboolean getUP() const;
	GLboolean getDOWN() const;
	GLboolean getLEFT() const;
	GLboolean getRIGHT() const;
	
};

#endif
