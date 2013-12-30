#include <SWI-cpp.h>
#include <iostream>
#include "ReadProlog.h"

using namespace std;

//Degug->Project Proprieties->C/C++->Aditional include directories: .../swipl/include
//Degug->Project Proprieties->Linker->Aditional library directories: .../swipl/lib
//Degug->Project Proprieties->Linker->Input->Aditional Dependencies: libswipl.dll.a
//Add ambient variable(PATH): .../swipl/bin

int main(){

	char* argv[] = {"swipl.ll","-s","C:\\Users\\W370ET\\Desktop\\ISEP\\LAPR5\\Lapr5Project\\ArtificialIntelligence\\write\\test.pl",NULL};

	PlEngine e(3,argv);

	ReadProlog* reader = new ReadProlog();

	reader->user();
	reader->friends();

	cin.get();
	return 1;	
}
