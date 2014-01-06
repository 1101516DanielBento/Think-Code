#ifndef Lista_
#define Lista_

#include "No.h"

template <class T> 
class Lista_Iterador ;

template<class T>
class Lista
{
	friend Lista_Iterador<T>;
    
	private:

		No<T> *cabeca ;

		void destroilista();

	public:
		Lista() ;
		Lista(const Lista<T>& l);
		virtual ~Lista();
		bool vazia() const;
		virtual void  insere(int k, const T & elem);
		void remove(int k, T  &x);
		void encontra (int k, T &x) const ;
		int comprimento() const;
		int indexOf(const T &o) const;
		
		const Lista<T>& operator = (const Lista<T> & l) ;

		void escreve (ostream& out) const ;
};

template <class T>
Lista<T>::Lista()
{ 
	cabeca = NULL; 
}

template <class T>
Lista<T>::Lista(const Lista<T>& l)
{
	No<T> * apno =new No<T>;

	if(l.cabeca)
		cabeca=apno;
	else 
	    cabeca=NULL;   
	
	No<T> * apaux=l.cabeca;

	while (apaux)
	{
		apno->info=apaux->info;
		if(apaux->prox == NULL)
		{
			apno->prox=NULL;
			apaux=apaux->prox;
		}
		else
		{
			apno->prox = new No<T>;
			apno=apno->prox;
			apaux=apaux->prox;
		}
	}
}

template <class T>
Lista<T>::~Lista() 
{
	destroilista();
}

template <class T>
void Lista<T>::destroilista() 
{
	No<T> * temp;

	while(cabeca)
	{
		temp=cabeca->prox;
		delete cabeca;
		cabeca=temp;
	}
	cabeca = NULL ; 
}

template<class T>
bool Lista<T>::vazia() const
{
	return (cabeca==NULL);
}

template<class T>
void Lista<T>::insere(int k, const T & elem)
{
	if (k <= 0)
		cout << "Posicao invalida ! \n" ;
	else
	{
		No<T>* apno= new No<T> ;
		apno->info=elem ;

		No<T> *temp=cabeca;

		if (k == 1)
		{
			apno->prox = temp ;
			cabeca=apno;
		}
		else
		{
 		  int i=1; 
		  while (i < k-1 && temp)
		  {
			temp=temp->prox;
			i++;
		  }
          if (temp)
		  {
			apno->prox=temp->prox;
			temp->prox=apno;
		  }
		}
	}
}

template<class T>
int Lista<T>::comprimento() const
{
	No<T> *temp;

	int comp=0;

	temp = cabeca;
	while (temp)
	{
		comp++;
		temp=temp->prox;
	}
	return comp;
}


template<class T>
void Lista<T>::encontra (int k, T &x) const
{
  int comp = comprimento () ;

  if (k > 0 &&  k <= comp) 
  {
	  No<T> * apt=cabeca;

	  for (int i = 1; i < k ; i++)
		 apt = apt->prox ;   

 	  if (apt)
		  x = apt->info ;
  }
}

template <class T>
int Lista<T>::indexOf(const T &o) const{
    //No* tempNode = first;
	No<T> * apt=cabeca;
    int count = 0;
    while(apt != NULL)
    {
        if (o==(apt->info)){
            break;
        }
    ++count;
    apt = apt->prox;
    }
    return count;
}


template<class T>
void  Lista<T>::remove (int k, T  &x)
{
  if (k <= 0 || k > comprimento()) 
	  cout << "Posicao invalida ! \n" ;
  else
  {
	  No<T> * act=cabeca ;
	  No<T> * ant=NULL ;

	  for (int i = 1; i < k && act; i++)
	  {
		  ant = act ;
		  act = act->prox ;
	  }
	  
	  if (ant) 
	    ant->prox = act->prox ;
      else
		cabeca = cabeca->prox ;

	  x = act->info ;
	  delete act ;
  }
}

template <class T>
const Lista<T>& Lista<T>::operator = (const Lista<T> &l)
{

	if (this == &l)
		return *this;

	destroilista();

	No<T> * apaux = l.cabeca;
    int i = 1 ; 

	while (apaux != NULL)
	{
		insere(i,apaux->info) ;
		i++ ;
		apaux=apaux->prox;
	}
 	return *this;
}


template <class T>
void Lista<T>::escreve(ostream& out) const 
{
   	No<T> *temp=cabeca;

	if (cabeca)
		do
		{
			out << temp->info << "";
			temp=temp->prox;

		} while (temp);
	else
		out << "Lista Vazia";

	out << endl;
}


// overload <<
template <class T>
ostream& operator << (ostream& out, const Lista<T>& l) 
{
	l.escreve(out) ;
	return out ;
}


#endif