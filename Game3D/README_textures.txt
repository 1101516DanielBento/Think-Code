RGBpixmap pixmap;
	pixmap.readBMPFile("imagem.bmp");
	pixmap.setTexture(1);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0,0.0); glVertex2d(0.0,0.0);
	glTexCoord2d(1.0,0.0); glVertex2d(10.0,0.0);
	glTexCoord2d(1.0,1.0); glVertex2d(10.0,10.0);
	glTexCoord2d(0.0,1.0); glVertex2d(0.0,10.0);
	glEnd();