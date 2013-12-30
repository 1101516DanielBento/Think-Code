#include <string>

using namespace std;

class User{

private:
	string username;
	string taglist[100];
	int currentTagNumber;

public:
	User();
	~User();
	void initialize();
	string getUsername();
	void setUsername(string username);
	string getTags();
	void setTag(string tag);
	string toString();

};

User::User()
{
	initialize();
}

string User::getUsername()
{
	return username;
}

void User::setUsername(string username)
{
	this->username=username;
}

void User::setTag(string tag){
	this->taglist[currentTagNumber]=tag;
	currentTagNumber++;
}

string User::getTags()
{
	string storer;

	for(int i=0;i<currentTagNumber;i++)
	{
		storer += this->taglist[i] + "\n";
	}

	return storer;
}

void User::initialize()
{
	this->currentTagNumber=0;
}

string User::toString(){

	return "User: " + this->getUsername() + "\n" + "Tags: \n" + this->getTags();
	
}