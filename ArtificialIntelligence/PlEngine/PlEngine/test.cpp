#include <SWI-cpp.h>
#include <iostream>

using namespace std;

//Degug->Project Proprieties->C/C++->Aditional include directories: .../swipl/include
//Degug->Project Proprieties->Linker->Aditional library directories: .../swipl/lib
//Degug->Project Proprieties->Linker->Input->Aditional Dependencies: libswipl.dll.a
//Add ambient variable(PATH): .../swipl/bin
class test
{
public:
	void user();
	void friends();
};

void test::user()
{
    char* userName; 
	PlTermv user(1);
	PlQuery getCurrentUser("user",user);

	while(getCurrentUser.next_solution()){//gets current user	
		cout<<(char*)user[0]<<endl;
		userName=(char*)user[0];
		}
}

void test::friends()
{
	PlTermv friends(2);
	friends[0]=PlCompound("Matt");
	PlQuery userFriends("friends",friends);
	int i=0;

	while(userFriends.next_solution()){//gets friends	
		cout<<(char*)friends[1]<<endl;
		//relationships[i]=(char*)friends[1];
		i++;
	}
}

int main(){

	char* argv[] = {"swipl.ll","-s","C:\\Users\\W370ET\\Desktop\\ISEP\\LAPR5\\Lapr5Project\\ArtificialIntelligence\\write\\test.pl",NULL};

	PlEngine e(3,argv);

	test t;

	t.user();
	t.friends();
	
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