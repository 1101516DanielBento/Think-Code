#include "TicTacToe.h"
#include <iostream>

using namespace std;

char* tictactoe[] = {"swipl.ll","-s","newtictactoe.pl",NULL};
PlEngine p(3,tictactoe);

void TicTacToe::getState(){
	
	PlTermv requestAIMove(0);
	PlQuery q("makemove",requestAIMove);

	while(q.next_solution()){
		cout<<"AI made a move"<<endl;
	}
}


void TicTacToe::getCoords(){

	string x="x/1";

	PlTermv listing(1);
	listing[0]=PlCompound(x.c_str());
	PlQuery q("listing",listing);
	while(q.next_solution()){
		cout<<(char*)listing[1]<<endl;
	}
}