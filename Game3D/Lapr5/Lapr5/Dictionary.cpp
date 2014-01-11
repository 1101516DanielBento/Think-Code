#include "Dictionary.h"

Dictionary::Dictionary()
{
	idWord=-1;
	wordName="";
	tagList = new vector<int>();
}

Dictionary::~Dictionary(){}

Dictionary& Dictionary::operator=(const Dictionary& d)
{
	idWord=d.idWord;
	wordName=d.wordName;
	tagList = d.tagList;

	return *this;
}


void Dictionary::toString(){
	cout<<"Dictionary: " + idWord << " Word:" + wordName;
}

int  Dictionary::getIdWord(){
	return idWord;
}


vector<int> *Dictionary::getTagList(){
	return tagList;
}


string Dictionary::getWordName(){
	return wordName;
}

void Dictionary::setWordName(string word){
	this->wordName=word;
}
void Dictionary::setIdWord(int id){
	this->idWord=id;
}
void Dictionary::setTagList(vector<int> *lst){
	this->tagList=lst;
}