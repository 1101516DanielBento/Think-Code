#ifndef Stack_
#define Stack_

#include "No.h"

template<class T>
class Stack
{
	private:
		No<T> *topo;

		void destroiStack();
		const Stack<T>& inverte();

	public:
		Stack();
		Stack(const Stack<T>& s);
		virtual ~Stack();

		void push(const T &elem);
		void pop(T &x);
		const T& top() const;
		bool vazia() const;
		int comprimento() const;

		const Stack<T>& operator = (const Stack<T> &s);	
		void escreve(ostream & ostr) const;
};

template <class T>
Stack<T>::Stack()
{
	topo = NULL;
}


template <class T>
Stack<T>::Stack(const Stack<T> &s)
{
	No<T> * apno = new No<T>;

	if(s.topo)
		topo=apno;
	else 
		topo=NULL;

	No<T> *ap = s.topo;

	while (ap != NULL)
	{
		apno->info=ap->info;

		if(ap->prox == NULL)
			apno->prox=NULL;
		else
		{
			apno->prox=new No<T>;
			apno=apno->prox;
		}
		ap=ap->prox;
	}
}

template <class T>
void Stack<T>::destroiStack() 
{
	No<T> * temp;

	while (topo)
	{
		temp=topo->prox;
		delete topo;
		topo=temp;
	}
}

template <class T>
Stack<T>::~Stack() 
{
 	destroiStack();
}
  
template<class T>
bool Stack<T>::vazia() const
{
	return (topo==NULL);
}

template<class T>
int Stack<T>::comprimento() const
{
	No<T> *temp;
	int comp=0;

	temp=topo;
	while (temp)
	{
		comp++;
		temp=temp->prox;
	}
	return comp;
}


template<class T>
const T& Stack<T>::top() const
{
	return topo->info;
}


template<class T>
void Stack<T>::pop(T & x)
{
	if (!vazia())
	{
		x=topo->info;

		No<T>* temp;

		temp=topo ;
		topo=topo->prox ; 
		delete temp ;
		
	}
}

template<class T>
void Stack<T>::push(const T &elem)
{
	No<T>* apno= new No<T>;

	apno->info=elem;	
	apno->prox=topo;
	topo=apno;
}

template<class T>
const Stack<T>& Stack<T>::inverte()
{
	Stack<T> aux(*this) ; 
	T x ; 

	destroiStack();
	
	while (!aux.vazia())
	{
		aux.pop(x) ; 
		push(x) ; 
	}

	return *this ; 
}


template <class T>
const Stack<T>& Stack<T>::operator = (const Stack<T> & s)
{
	Stack<T> aux(s) ; 
	T item ; 

	destroiStack();
    
	aux.inverte() ;   //para que os elem fiquem pela mesma ordem 
	
	while (!aux.vazia())   
	{
		 aux.pop(item) ;
		 push(item) ;
	} 

	return *this;
}
 

template<class T>
void Stack<T>::escreve(ostream & ostr) const
{
	No<T>* temp=topo;

	while (temp)
	{
		ostr << temp->info << " " ;
		temp=temp->prox;
	}

}

template<class T>
ostream & operator << (ostream & ostr, const Stack<T> & s)
{
	s.escreve(ostr);
	return ostr;
}



#endif