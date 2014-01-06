#include "Ponto.h"

Ponto::Ponto()
{
	this->x=0;
	this->y=0;
}

Ponto::Ponto(float x, float y)
{
	this->x = x;
	this->y = y;
}

Ponto::Ponto(float x, float y,float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Ponto* Ponto::clone() const
{
	return new Ponto(*this);
}

void Ponto::setX(float x)
{
	this->x = x;
}

void Ponto::setY(float y)
{
	this->y = y;
}

void Ponto::setZ(float z)
{
	this->z = z;
}

float Ponto::getX() const
{
	return x;
}

float Ponto::getY() const
{
	return y;
}

float Ponto::getZ() const
{
	return z;
}

bool Ponto:: isValid()
{
	if(x >= 0 && y >= 0)
		return true;
	return false;
}

void Ponto::invalidate()
{
	x=-1;
	y=-1;
}

Ponto& Ponto::operator=(const Ponto &p)
{
	if(this!=&p)
	{
		x=p.getX();
		y=p.getY();
		z=p.getZ();
	}
	return (*this);
}