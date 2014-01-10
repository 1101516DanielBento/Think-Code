#include <string>
#include <iostream>
#include "User_Local.h"

using namespace std;

User_Local::User_Local()
{
	initialize();
}

User_Local::~User_Local(){}

User_Local& User_Local::operator=(const User_Local& user)
{
	this->username = user.username;
	this->taglist = user.taglist;
	this->friends = user.friends;
	this->currentTagNumber = user.currentTagNumber;
	this->nFriends = user.nFriends;

	return *this;
}

void User_Local::initialize()
{
	this->numUsers=1;
	this->nFriends=0;
	this->currentTagNumber=0;
}

string User_Local::getUsername()
{
	return username;
}

void User_Local::networkSizeInc(){
	this->numUsers++;
}

void User_Local::setUsername(string User_Localname)
{
	this->username=User_Localname;
}

void User_Local::setTag(string tag)
{
	this->taglist.push_back(tag);
	currentTagNumber++;
}

void User_Local::setFriend(User_Local* User_Local)
{
	this->friends.push_back(User_Local);
	nFriends++;
}

string User_Local::getTags()
{
	string storer;

	storer = "Tags of: " + this->username + "\n";

	for(int i=0;i<currentTagNumber;i++)
	{
		storer += this->taglist.at(i) + "\n";
	}

	return storer;
}

int User_Local::getNetworkSize(){
	return this->numUsers;
}

void User_Local::toString(){
	cout<<"User: " + this->getUsername() + "\n" + this->getTags();
}

void User_Local::showNetwork()
{
	this->toString();

	for(int i=0;i<nFriends;i++)
	{
		cout<<"Direct Friend: "<<this->friends.at(i)->username<<endl;
		cout<<friends.at(i)->getTags();

		for(int j=0;j<friends.at(i)->nFriends;j++)
		{
			cout<<"Friends of "<<this->friends.at(i)->username<<": "<<endl<<friends.at(i)->friends.at(j)->username<<endl;
			cout<<friends.at(i)->friends.at(j)->getTags();
		}
	}

	cout<<"Total users in this network: "<<numUsers<<endl;
}

