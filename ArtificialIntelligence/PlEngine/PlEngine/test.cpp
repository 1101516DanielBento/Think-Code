#include <SWI-cpp.h>
#include <iostream>

using namespace std;

//Degug->Project Proprieties->C/C++->Aditional include directories: .../swipl/include
//Degug->Project Proprieties->Linker->Aditional library directories: .../swipl/lib
//Degug->Project Proprieties->Linker->Input->Aditional Dependencies: libswipl.dll.a
//Add ambient variable(PATH): .../swipl/bin

//example for adding numbers
void sum(int x, int y)
{
	char* argv[] = {"swipl.ll","-s","C:\\Users\\W370ET\\Desktop\\ISEP\\LAPR5\\Lapr5Project\\ArtificialIntelligence\\Functions.pl",NULL};

	PlEngine e(3,argv); 
 
	PlTermv av(3);

	av[0] = PlCompound((char*)x); 
	av[1] = PlCompound((char*)y); 

	PlQuery q("sum", av); 
  
	while(q.next_solution()){
	
		cout<<(char*)av[2]<<endl;
	}
}

//example for getting fact solutions(1 argument)
void fact(char* factname){

	char* argv[] = {"swipl.ll","-s","C:\\Users\\W370ET\\Desktop\\ISEP\\LAPR5\\Lapr5Project\\ArtificialIntelligence\\Functions.pl",NULL};
	
	PlEngine e(3,argv);

	PlTermv av(1);

	PlQuery q(factname,av);

	while(q.next_solution()){
	
		cout<<(char*)av[0]<<endl;
	}

}


int main(){

	//sum(1,2);
	
	//fact("man");

	cin.get();
	return 1;	
}


	/*PlEngine e(3,argv); 
 
	PlTermv av(3);

	av[0] = PlCompound("1"); 
	av[1] = PlCompound("2"); 

	PlQuery q("sum", av); 
  
	cout << (char*)av[2] << endl; 
	*/


	
	/*PlEngine e(3,argv);

	PlTermv av(2);

	av[0] = PlCompound("peter"); 

	PlQuery q("relationship",av);
	
	while(q.next_solution()){
		cout<<(char*)av[1]<<endl;
	}*/