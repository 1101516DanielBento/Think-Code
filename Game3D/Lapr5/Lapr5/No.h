#ifndef No_
#define No_

template <class T> 
class Lista ;

template <class T> 
class Queue ;

template <class T> 
class Stack ;

template <class T> 
class Lista_Iterador ;

template<class T>
class No
{
	friend Lista<T>;
	friend Queue<T>;
	friend Stack<T>;
	friend Lista_Iterador<T>;

	private:
		T info;
		No<T>* prox;

	public:
		No () 
		{  
			prox = NULL ; 
		}

		No (const No<T> &n)
		{
			info = n.info ; 
			prox = n.prox ; 
		}
		~No () 
		{  
		}

		void setInfo (const T i) 
		{
			info = i ; 
		}

		T& getInfo()  const 
		{
			return info ; 
		}

		void setProx (No<T>* ap) 
		{
			prox = ap ; 
		}

		No<T>* getProx() const 
		{
			return prox ; 
		}
};

#endif