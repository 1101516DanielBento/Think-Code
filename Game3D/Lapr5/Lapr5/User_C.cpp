#include "User_C.h"

User_C::User_C()
{
	idUser=-1;
	username="";
	points=0;
	tagList = new vector<tuple<int,string>>();
	friends = new vector<tuple<int,string>>();
	request = new vector<int>();
	reqNeg = new vector<tuple<int,vector<tuple<int,int,bool>>>>();
}

User_C::~User_C(){}

User_C& User_C::operator=(const User_C& user)
{
	username=user.username;
	idUser=user.idUser;
	points=user.points;
	tagList=user.tagList;
	friends=user.friends;
	reqNeg=user.reqNeg;
	request=user.request;

	return *this;
}


void User_C::toString(){
	cout<<"User: " + this->getUsername();
}

int  User_C::getIdUser(){
	return idUser;
}


vector<tuple<int,string>> *User_C::getTagList(){
	return tagList;
}
vector<tuple<int,string>> *User_C::getFriends(){
	return friends;
}
vector<int> *User_C::getRequest(){
	return request;
}
vector<tuple<int,vector<tuple<int,int,bool>>>> *User_C::getReqNeg(){
	return reqNeg;
}
int User_C::getPoints(){
	return points;
}
string User_C::getUsername(){
	return username;
}

void User_C::setUsername(string username){
	this->username=username;
}
void User_C::setIdUser(int idUser){
	this->idUser=idUser;}
void User_C::setTagList(vector<tuple<int,string>> *lst){
	this->tagList=lst;
}
void User_C::setFriends(vector<tuple<int,string>> *lst){
	this->friends=lst;
}
void User_C::setRequest(vector<int> *lst){
	this->request=lst;
}
void User_C::setReqNeg(vector<tuple<int,vector<tuple<int,int,bool>>>> *lst){
	this->reqNeg=lst;
}
void User_C::setPoints(int points){
	this->points=points;
}


