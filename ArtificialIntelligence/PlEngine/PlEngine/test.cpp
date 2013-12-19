#include <SWI-cpp.h>
#include <iostream>

using namespace std;

int main(){

	char* argv[] = {"swipl.ll","-s","C:\\Users\\Fred\\Desktop\\ISEP\\LAPR5\\Functions.pl",NULL};

	PlEngine e(3,argv);

	PlTermv av(1);

	PlQuery q("homem",av);

	while(q.next_solution()){
	
		cout<<(char*)av[0]<<endl;
	}

	cin.get();
	return 1;
	}