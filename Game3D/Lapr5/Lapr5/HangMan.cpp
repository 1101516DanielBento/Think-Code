#include <iostream>
#include <SWI-cpp.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "HangMan.h"

char* arg[] = {"swipl.ll","-s","hangman.pl",NULL};
PlEngine e(3,arg);

HangMan::HangMan(){
	this->initialize();
}

HangMan::~HangMan(){}

void HangMan::initialize(){
	this->sucesses=0;
	this->wrongTries=0;
	this->playing=true;
}

string HangMan::Word(){
	return word;
}

void HangMan::Start(){
	this->getWord();

	for(unsigned int i=0;i<word.size();i++){
		wordChars.push_back(word.at(i));
	}

	this->getHint();
	this->play();
}

void HangMan::getWord(){//gets a random ocurrence of word/1
	PlTermv allwords(1);
	PlQuery checkWords("word",allwords);

	while(checkWords.next_solution()){
		words.push_back((string)allwords[0]);
	}

	word = words[randomize(words.size()-1,0)];
}

void HangMan::getHint(){//gets the word hint
	PlTermv wordHint(2);
	wordHint[0] = PlCompound(word.c_str());
	PlQuery checkHints("hint",wordHint);

	while(checkHints.next_solution()){
		hint = (string)wordHint[1];
	}
}

void HangMan::InitBoard(){//initializes the board
	for(unsigned int i=0;i<word.size();i++){
		board.push_back(" - ");
	}
	out();
}

void HangMan::UpdateBoard(vector<int> pos, string letter){//updates board on sucessefull play
	for(unsigned int i=0;i<pos.size();i++){
		board[pos[i]] = " " + letter + " ";
	}
	out();
}


void HangMan::play(){
	char awnser;

	cout<<"Hint: "<<hint<<endl<<endl;
	InitBoard();

	while(playing){

		bool guessed = false;
		checkGameState();
		cout<<"Take a guess: "<<endl;
		cin>>awnser;

		for(unsigned int i=0;i<word.size();i++){

			if(word.at(i)==awnser){
				cout<<"Correct!"<<endl;
				sucesses+=getCharOcorrences(awnser).size();
				UpdateBoard(getCharOcorrences(awnser),charToString(awnser));
				guessed = true;
				break;
			}
		}

		if(!guessed){
			wrongTries++;
			cout<<"Wrong!"<<endl<<endl;
			out();
		}
	}
}


void HangMan::checkGameState(){
	
	if(word.size()==sucesses){
		this->playing=false;
		cout<<"You Win!!!"<<endl<<endl;
		Sleep(2000);
		exit(0);
	}

	if(wrongTries==max_tries_hard){
		this->playing=false;
		cout<<"You Lost!!!"<<endl<<endl;
		Sleep(2000);
		exit(0);
	}
}

void HangMan::out(){
	for(unsigned int i=0;i<board.size();i++){
		cout<<board[i];
	}
	cout<<endl<<endl;
}

vector<int> HangMan::getCharOcorrences(char c){
	vector<int> ocorrences;
	
	for(unsigned int i=0; i<wordChars.size(); i++){
		if(c==wordChars[i]){
			ocorrences.push_back(i);
		}
	}
	
	return ocorrences;
}

int HangMan::randomize(int max, int min){
	srand(static_cast<unsigned int> (time(0)));
	return min + (rand() % (int)(max - min + 1));
}

string HangMan::charToString(char c){
	char* chA[1];
	chA[0]=&c;
	string result = chA[0];
	return result;
}

