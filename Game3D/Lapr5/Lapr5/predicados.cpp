#include <SWI-cpp.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;



vector<string> amigosdiretos(string Utilizador)
{ 
	char * av[] = {"", "-s", "IA prolog.pl", NULL};
	PlEngine e(3,av);
	vector<string> Lista;
	char *temp;
	PlTermv av1(2);

	PlTerm t;
	av1[0]=PlCompound(Utilizador.c_str());
	cout<<(char*)av1[0]<<endl;
	PlQuery q("amigos_diretos", av1);
	while (q.next_solution())
	{

		PlTail tail(av1[1]);
		while(tail.next(t))
		{
			cout<< (char *) t<< endl;
			temp = (char *) t;
			Lista.push_back((string)temp);
		}
	}

	return Lista;
}

vector<string> tamanho_rede_utilizador(string Utilizador)
{
	char * av[] = {"", "-s", "IA prolog.pl", NULL};
	PlEngine e(3,av);
	vector<string> Lista;
	char *temp;
	PlTermv av1(2);

	PlTerm t;
	av1[0]=PlCompound(Utilizador.c_str());
	cout<<(char*)av1[0]<<endl;
	PlQuery q("tamanho_rede_utilizador", av1);
	while (q.next_solution())
	{

		PlTail tail(av1[1]);
		while(tail.next(t))
		{
			cout<< (char *) t<< endl;
			temp = (char *) t;
			Lista.push_back((string)temp);
		}
	}


	return Lista;
}


vector<string> obter_amigos_X_tags_comuns(string Utilizador)
{
	char * av[] = {"", "-s", "IA prolog.pl", NULL};
	PlEngine e(3,av);
	vector<string> Lista;
	char *temp;
	PlTermv av1(3);

	PlTerm t;
	av1[0]=PlCompound(Utilizador.c_str());
	cout<<(char*)av1[0]<<endl;
	
	PlQuery q("obter_amigos_X_tags_comuns", av1);
	while (q.next_solution())
	{

		PlTail tail(av1[2]);
		while(tail.next(t))
		{
			cout<< (char *) t<< endl;
			temp = (char *) t;
			Lista.push_back((string)temp);
		}
	}

	return Lista;
}


vector<string> sugerir_amigos(string Utilizador)
{
	char * av[] = {"", "-s", "IA prolog.pl", NULL};
	PlEngine e(3,av);
	vector<string> Lista;
	char *temp;
	PlTermv av1(2);

	PlTerm t;
	av1[0]=PlCompound(Utilizador.c_str());
	cout<<(char*)av1[0]<<endl;
	
	PlQuery q("sugerir_amigos", av1);
	while (q.next_solution())
	{

		PlTail tail(av1[1]);
		while(tail.next(t))
		{
			cout<< (char *) t<< endl;
			temp = (char *) t;
			Lista.push_back((string)temp);
		}
	}

	return Lista;
}


vector<string> caminho_mais_curto(string UtilizadorO, string UtilizadorD)
{
	char * av[] = {"", "-s", "IA prolog.pl", NULL};
	PlEngine e(3,av);
	vector<string> Lista;
	char *temp;
	PlTermv av1(3);

	PlTerm t;
	av1[0]=PlCompound(UtilizadorO.c_str());
	cout<<(char*)av1[0]<<endl;

	av1[1]=PlCompound(UtilizadorD.c_str());
	cout<<(char*)av1[1]<<endl;
	
	PlQuery q("caminho_mais_curto", av1);
	
	bool flag=false;
	while (q.next_solution())
	{

		PlTail tail(av1[2]);
		while(tail.next(t) && flag==false)
		{
			cout<< (char *) t<< endl;
			temp = (char *) t;
			if(temp == UtilizadorD)
				flag=true;
			Lista.push_back((string)temp);
		}
	}

	return Lista;
}


vector<string> determinar_caminho_mais_forte(string UtilizadorO, string UtilizadorD)
{
	char * av[] = {"", "-s", "IA prolog.pl", NULL};
	PlEngine e(3,av);
	vector<string> Lista;
	char *temp;
	PlTermv av1(3);

	PlTerm t;
	av1[0]=PlCompound(UtilizadorO.c_str());
	cout<<(char*)av1[0]<<endl;
	
	av1[1]=PlCompound(UtilizadorD.c_str());
	cout<<(char*)av1[0]<<endl;
	
	PlQuery q("determinar_caminho_mais_forte", av1);
	while (q.next_solution())
	{

		PlTail tail(av1[2]);
		while(tail.next(t))
		{
			cout<< (char *) t<< endl;
			temp = (char *) t;
			Lista.push_back((string)temp);
		}
	}

	return Lista;
}


int main()
{
	vector <string> Ldiretos;
	vector <string> LTamRede;
	vector <string> Ltags;
	vector <string> Lsugestao;
	vector <string> Lmaiscurto;
	vector <string> Lmaisforte;
	Ldiretos = amigosdiretos("luis");
	LTamRede = tamanho_rede_utilizador("tiago");
	Ltags = obter_amigos_X_tags_comuns("tiago");
	Lsugestao = sugerir_amigos("luis");
	Lmaiscurto = caminho_mais_curto("tiago","daniela");
	Lmaisforte = determinar_caminho_mais_forte("tiago","daniela");

	for (int i = 0; i < Lmaisforte.size(); i++)
	{
		cout << "MAIN : ->"<<Lmaisforte.at(i)<<endl;
	}

	cin.get();
	return 0;
}
