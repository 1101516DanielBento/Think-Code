#include <stdlib.h>
#include <glut.h>
#include "glui.h"

class RGB_{

public:
	unsigned char r,g,b;
	RGB_()
		{ r=g=b=0;}
	};
class RGBpixmap{
 public:
  int nRows, nCols;
  RGB_ *pixel;

 RGBpixmap()
 {	
	nRows = nCols = 0;
	pixel = NULL;
 }
 ~RGBpixmap()
 {
	 if (pixel != NULL)
		delete []pixel;
 }
 int readBMPFile(char * fname);
 void makeCheckBoard();
 void setTexture(GLuint textureName);
};

