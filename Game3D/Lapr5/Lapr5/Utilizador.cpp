#include "Utilizador.h"

Utilizador::Utilizador(int id2,string pass,string user)
{
	id= id2;
	password = pass;
	username = user;
}

Utilizador::Utilizador()
{
}

Utilizador::~Utilizador() { }

void Utilizador::setUsername(string uname)
{
	username = uname;
}

string Utilizador::getUsername()
{
	return username;
}

void Utilizador::setPonto(Ponto *p2)
{
	p=p2;
}

Ponto* Utilizador::getPonto()
{
	return p;
}

void Utilizador::setNome(string n)
{
	nome = n;
}

string Utilizador::getNome()
{
	return nome;
}

void Utilizador::setId(int i)
{
	id = i;
}

int Utilizador::getId()
{
	return id;
}

void Utilizador::setForca1(int f1)
{
	forca1 = f1;
}

int Utilizador::getForca1()
{
	return forca1;
}

void Utilizador::setForca2(int f2)
{
	forca2 = f2;
}

int Utilizador::getForca2()
{
	return forca2;
}

void Utilizador::setEstado(string e)
{
	estado = e;
}

string Utilizador::getEstado()
{
	return estado;
}

void Utilizador::setNumAmigos(int nAmigos)
{
	numAmigos = nAmigos;
}

int Utilizador::getNumAmigos()
{
	return numAmigos;
}

void Utilizador::setTagsRelacao(string tagsR)
{
	tagsRelacao = tagsR;
}

string Utilizador::getTagsRelacao()
{
	return tagsRelacao;
}

void Utilizador::setTagsPessoais(string tagsP)
{
	tagsPessoais = tagsP;
}

string Utilizador::getTagsPessoais()
{
	return tagsPessoais;
}

void Utilizador::setNumTags(int nTags)
{
	numTags = nTags;	
}

int Utilizador::getNumTags()
{
	return numTags;
}

