#ifndef UTILIZADOR_
#define UTILIZADOR_

#include "Ponto.h"
#include <iostream>
#include <string>
using namespace std;

class Utilizador
{
private:
	int id;
	string password;
	string username;
	//string avatar;
	string nome;
	string estado;
	Ponto *p;
	int forca1;
	int forca2;
	int numAmigos;
	int numTags;
	string tagsRelacao;
	string tagsPessoais;

public:
	Utilizador(int id2,string pass, string user);
	Utilizador();
	~Utilizador();

	void setUsername(string uname);
	void setPonto(Ponto *p2);
	void setNome(string nome);
	void setId(int i);
	void setForca1(int f1);
	void setForca2(int f2);
	void setEstado(string e);
	void setNumAmigos(int nAmigos);
	void setTagsRelacao(string tagsR);
	void setTagsPessoais(string tagsP);
	void setNumTags(int nTags);

	string getUsername();
	Ponto*  getPonto();
	string getNome();
	int getId();
	int getForca1();
	int getForca2();
	string getEstado();
	int getNumAmigos();
	string getTagsRelacao();
	string getTagsPessoais();
	int getNumTags();

	void escreve(ostream &out) const;
	bool operator>(const Utilizador &ut) const;
	bool operator==(const Utilizador &ut) const;
};

#endif