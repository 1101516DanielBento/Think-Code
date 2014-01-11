#ifndef DICTIONARY_
#define DICTIONARY_

#include <string>
#include <iostream>
#include <vector>


using namespace std;

//User has an array of users representing his friends;
//This array has users so it can be lodged intp a new user array(friends of friends); 

class Dictionary{

private:
	int idWord;
	string wordName;
	//tagIds
	vector<int> *tagList;
	


public:
	Dictionary();
	~Dictionary();

	int getIdWord();
	vector<int>* getTagList();
	string getWordName();

	void setWordName(string word);
	void setIdWord(int id);
	void setTagList(vector<int> *lst);


	Dictionary& operator=(const Dictionary& d);
	void toString();

};

#endif