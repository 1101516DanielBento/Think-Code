#include "Relacao.h"


Relacao::Relacao(float weight,float width)
{
	noi=0;
	nof=0;
	peso=weight;
	largura=width;
}

Relacao::Relacao(int p1, int p2, float weight,float width)
{
	noi=p1;
	nof=p2;
	peso=weight;
	largura = width;
}

Relacao::Relacao()
{
}

Relacao::~Relacao()
{
}

float Relacao::getPeso()
{
	return peso;
}

int Relacao::getNoi()
{
	return noi;
}

int Relacao::getNof()
{
	return nof;
}

float Relacao::getLargura()
{
	return largura;
}
void Relacao::escreve(ostream &out)const
{
	out<<"Ramo Peso: "<<peso<<endl;
	out<<"Ramo Largura: "<<largura<<endl;
}

ostream & operator <<(ostream &out, const Relacao &r)
{
	l.escreve(out);
	return(out);
}
