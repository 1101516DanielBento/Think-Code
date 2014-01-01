#include <string>

using namespace std;

//User has an array of users representing his friends;
//This array has users so it can be lodged intp a new user array(friends of friends); 

class User{

private:
	string username;
	string taglist[100];
	User* friends[100];
	int currentTagNumber;
	int nFriends;

public:
	User();
	~User();
	User& operator=(const User& user);
	void initialize();
	string getUsername();
	void setUsername(string username);
	string getTags();
	void setTag(string tag);
	void setFriend(User* user);
	void showFriends();
	void toString();
	void showNetwork();
};

User::User()
{
	initialize();
}

User::~User(){}

User& User::operator=(const User& user)
{
	username = user.username;
	taglist[100] = user.taglist[100];
	friends[100] = user.friends[100];
	currentTagNumber = user.currentTagNumber;
	nFriends = user.nFriends;
	return *this;
}


void User::initialize()
{
	this->nFriends=0;
	this->currentTagNumber=0;
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

void User::setFriend(User* user)
{
	this->friends[nFriends]=user;
	nFriends++;
}

void User::showFriends()
{
	for(int i=0;i<nFriends;i++)
	{
		this->friends[i]->toString();
	}
}

string User::getTags()
{
	string storer;

	storer = "Tags of: " + this->username + "\n";

	for(int i=0;i<currentTagNumber;i++)
	{
		storer += this->taglist[i] + "\n";
	}

	return storer;
}

void User::toString(){
	cout<<"User: " + this->getUsername() + "\n" + this->getTags();
}

void User::showNetwork()
{
	this->toString();

	for(int i=0;i<nFriends;i++)
	{
		cout<<"Direct Friend: "<<this->friends[i]->username<<endl;
		cout<<friends[i]->getTags();

		for(int j=0;j<friends[i]->nFriends;j++)
		{
			cout<<"Friends of "<<this->friends[i]->username<<": "<<endl<<friends[i]->friends[j]->username<<endl;
			cout<<friends[i]->friends[j]->getTags();
		}
	}
}
