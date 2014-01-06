#include <SWI-cpp.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define MAX_TRIES 4;

using namespace std;

class HangMan{

private:
	vector<string> words;
	string hint;
	int wrongTries;

public:
	HangMan();
	~HangMan();
	string getWord();
	string getHint(string word);
	void initialize();
	int randomize(int max, int min);
	void UI(string word,string hint);
	void setUI(int pos,char letter,string word);
	void fail();
};

HangMan::HangMan(){
	this->initialize();
}

HangMan::~HangMan(){}

void HangMan::initialize(){
	this->wrongTries=0;
}

string HangMan::getWord(){//gets a random ocurrence of word/1

	PlTermv word(1);
	PlQuery checkWords("word",word);

	while(checkWords.next_solution()){
		words.push_back((string)word[0]);
	}

	return words[randomize(words.size()-1,0)];
}

string HangMan::getHint(string word){//gets the word hint

	PlTermv wordHint(2);
	wordHint[0]=PlCompound(word.c_str());
	PlQuery checkHints("hint",wordHint);

	while(checkHints.next_solution()){
		hint = (string)wordHint[1];
	}

	return hint;
}

int HangMan::randomize(int max, int min){
	srand(static_cast<unsigned int> (time(0)));
	return min + (rand() % (int)(max - min + 1));
}

void HangMan::UI(string word, string hint){

	cout<<"Pista: "<<hint<<endl<<endl;

	for(unsigned int i=0;i<word.size();i++){
		cout<<" _ ";
	}

	cout<<endl<<endl;

	char letter;

	cout<<"Letra: ";
	cin>>letter;

	for(unsigned int i=0;i<word.size();i++){
		if(word.at(i)==letter){
			setUI(i,letter,word);
		}else{
			wrongTries++;
		}
	}
}

void HangMan::setUI(int pos,char letter,string word){
	
	for(unsigned int i=0;i<word.size();i++){
		if(i==pos){
			cout<<" "<<letter<<" ";
		}else{
			cout<<" _ ";
		}
	}
	cout<<endl;
	cin.get();
}

void HangMan::fail(){
	cout<<"Wrong!"<<endl;
}


