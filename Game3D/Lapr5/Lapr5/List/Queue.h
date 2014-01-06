#ifndef Queue_
#define Queue_

#include "No.h"

template<class T>
class Queue
{
	private:
		No<T> *inicio;
		No<T> *fim;
		
		void destroiQueue();
	public:
		Queue();
		Queue(const Queue<T>& q);
		virtual ~Queue();

		bool vazia() const;
		virtual void insere(const T& elem);
		void  retira(T& x);
		T& frente() const;
		T& ultimo() const;
		int comprimento() const;
	
		Queue<T>& operator = (const Queue<T>& q);   // atribuição

		void escreve(ostream & ostr) const;
};

template <class T>
Queue<T>::Queue()
{
	inicio=NULL;
	fim=NULL;
}

template <class T>
Queue<T>::Queue(const Queue<T>& q)
{
	No<T> * apno =new No<T>;
	if(q.inicio)
		inicio=apno;
	else 
	{
		inicio=NULL;
		fim=NULL;
	}
	No<T> * apnoaux=q.inicio;
	
	while(apnoaux !=NULL)
	{
		apno->setInfo(apnoaux->info) ;
		if(apnoaux->prox ==NULL)
		{
			apno->prox=NULL;
			apnoaux=apnoaux->prox;
		}
		else
		{
			apno->prox=new No<T>;
			apno=apno->prox;
			apnoaux=apnoaux->prox;
		}
	}
	fim=apno;
}

template <class T>
Queue<T>::~Queue() 
{
	destroiQueue();
}

template <class T>
void Queue<T>::destroiQueue() 
{
	No<T> * temp;

	while(inicio)
	{
		temp=inicio->prox;
		delete inicio;
		inicio=temp;
	}
	fim=inicio;
}

template<class T>
bool Queue<T>::vazia() const
{
	return (inicio==NULL);
}

template<class T>
void Queue<T>::insere(const T& elem)
{
	No<T>* apno= new No<T>;

	apno->info=elem;
	apno->prox=NULL;
	if(vazia())
	{
		inicio=apno;
		fim=apno;
	}
	else
	{
		fim->prox=apno;
		fim=apno;
	}
}

template<class T>
T& Queue<T>::frente() const
{
	return inicio->info;
}

template<class T>
T& Queue<T>::ultimo() const
{
	return fim->info;
}

template<class T>
int Queue<T>::comprimento() const
{
	No<T>* temp;
	int comp=0;

	temp=inicio;
	while (temp)
	{
		comp++;
		temp=temp->prox;
	}
	return comp;
}

template<class T>
void Queue<T>::retira(T& x)
{
	if (!vazia())
	{
		No<T>* temp=inicio;
	
		x=inicio->info;
		inicio=inicio->prox;	
		
		delete temp;
		
		if(inicio==NULL)
			fim=inicio;
	}
}

template <class T>
Queue<T>& Queue<T>::operator = (const Queue<T>& q)
{
	T elem ; 

	if (this == &q)
		return *this ;
	else
	{
		Queue aux(q) ; 
	
		destroiQueue();
		
		while (!aux.vazia())
		{
			aux.retira(elem);
			insere (elem) ;
		}
		return *this;
	}
}


template<class T>
void Queue<T>::escreve(ostream& ostr) const
{
	No<T>* temp=inicio;
	
	if (inicio)
		do
		{
			ostr << temp->info << " ";
			temp = temp->prox;
		}while (temp);
	else
		ostr << "Vazia";
}

template<class T>
ostream & operator << (ostream& ostr, const Queue<T>& q)
{
	q.escreve(ostr);
	return ostr;
}

#endif