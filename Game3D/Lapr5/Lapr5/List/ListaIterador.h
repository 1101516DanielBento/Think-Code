#ifndef Lista_Iterador_
#define Lista_Iterador_

#include "Lista.h"

template <class T> 
class Lista_Iterador 
{
	private:
		No<T> * inic;	
		No<T> * act;

	public:
  	    Lista_Iterador(const Lista<T> &l) ;
	    Lista_Iterador(const Lista_Iterador &lit) ;
		
		T operator ++(int) ;
	    const T& operator *() const ;
 	    void updat (const T& elem) ;
	    bool fim() const ;
	    
	    Lista_Iterador& operator = (const Lista_Iterador &lit) ;
	    bool operator == (const Lista_Iterador &lit) const ;
}; 

template <class T> 
Lista_Iterador<T>::Lista_Iterador(const Lista<T> &l) 
{
	inic = l.cabeca ;
 	act = inic ;
}

template <class T> 
Lista_Iterador<T>::Lista_Iterador(const Lista_Iterador<T> &lit) 
{
	inic = lit.inic ;
    act = lit.act ;
}


template <class T> 
T Lista_Iterador<T>::operator ++(int)
{
	T tmp = act->info ;
	
	act = act->prox ; 
		
	return tmp ;
}


template <class T> 
const T& Lista_Iterador<T>::operator *() const 
{
	return act->info ;
}


template <class T> 
void Lista_Iterador<T>::updat(const T& elem) 
{
	act->info = elem ; 
}  

template <class T> 
bool Lista_Iterador<T>::fim() const 
{
	return act == NULL ;
}


template <class T> 
Lista_Iterador<T>& Lista_Iterador<T>::operator = (const Lista_Iterador<T> &lit) 
{
	inic = lit.inic ; 
	act = lit.act ;

	return *this ;
}

template <class T> 
bool Lista_Iterador<T>::operator == (const Lista_Iterador<T> &lit) const
{
	return (inic == lit.inic && act == lit.act) ;
}


#endif