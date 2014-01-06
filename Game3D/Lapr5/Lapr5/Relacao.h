#ifndef RELACAO_
#define RELACAO_
#include <iostream>
using namespace std;
class Relacao
{
private:
	float peso;
	float largura;
	int noi;
	int nof;

public:
	Relacao();
	Relacao(float weight,float width);
	Relacao(int p1, int p2, float weight, float width);
	~Relacao();

	float getPeso();
	int getNoi();
	int getNof();
	float getLargura();

	void escreve(ostream &out) const;
};

#endif