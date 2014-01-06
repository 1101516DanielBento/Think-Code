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
	GLboolean q,a,up,down,left,right;
	
public:
	Teclas();
	Teclas* clone() const;
	
	void setQ(GLboolean q);
	void setA(GLboolean a);
	void setUP(GLboolean up);
	void setDOWN(GLboolean down);
	void setLEFT(GLboolean left);
	void setRIGHT(GLboolean right);
	
	GLboolean getQ() const;
	GLboolean getA() const;
	GLboolean getUP() const;
	GLboolean getDOWN() const;
	GLboolean getLEFT() const;
	GLboolean getRIGHT() const;
	
};

#endif
