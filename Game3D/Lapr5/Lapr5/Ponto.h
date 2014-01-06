#ifndef PONTO_
#define PONTO_

class Ponto
{
protected:
	float x,y,z;

public:
	Ponto();
	Ponto(float x, float y);
	//servirá para colocar as coordenadas de cada utilizador apos a distribuicao radial
	Ponto(float x, float y, float z);
	Ponto* clone() const;

	void setX(float x);
	void setY(float y);
	void setZ(float z);

	float getX() const;
	float getY() const;
	float getZ() const;
	
	bool isValid();
	void invalidate();

	Ponto& operator=(const Ponto &p);
};

#endif