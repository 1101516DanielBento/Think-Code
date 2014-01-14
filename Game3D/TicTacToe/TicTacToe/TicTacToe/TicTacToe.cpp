#include "TicTacToe.h"
#include <iostream>

using namespace std;

char* tictactoe[] = {"swipl.ll","-s","newtictactoe.pl",NULL};
PlEngine p(3,tictactoe);

int computerPos, myPos;

void TicTacToe::RequestAIMove(){
	
	PlTermv requestAIMove(0);
	PlQuery q("makemove",requestAIMove);

	while(q.next_solution()){
		cout<<"AI made a move"<<endl;
	}
}

void TicTacToe::getAICoord(){
	
	PlTermv x(1);
	PlQuery q("x",x);
	while(q.next_solution()){
		computerPos=x[0];
	}
	cout<<"Position played by AI: "<<computerPos<<endl;
}

void TicTacToe::RequestPlayerMove(int pos){

	string temp = to_string(pos);

	PlTermv playerMove(1);
	playerMove[0]=PlCompound(temp.c_str());
	PlCall("makePlayerMove",playerMove);

}

void TicTacToe::getMyCoord(){

	PlTermv o(1);
	PlQuery q("o",o);
	while(q.next_solution()){
		myPos=o[0];
	}
	cout<<"Position played by human: "<<myPos;
}

