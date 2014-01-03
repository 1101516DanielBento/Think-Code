#include <SWI-cpp.h>
#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class ReadProlog{

private:
	int nFriends;
	int nTags;
	string currentUser; 
    User* cUser;

public:
	ReadProlog();
	~ReadProlog();
	void user();
	void friends();
	void friendsOfFriends(User* user);
	void tags(User* user);
	void showUser(User* user);
	void showNetwork();
};

ReadProlog::ReadProlog(){}

ReadProlog::~ReadProlog(){}


void ReadProlog::user()//gets current user	
{
	cUser = new User();

	PlTermv user(1);
	PlQuery getCurrentUser("user",user);

	while(getCurrentUser.next_solution()){
		currentUser = (string)user[0];
		cUser->setUsername("'" + currentUser + "'");
		//cout<<"Current User: "<<currentUser<<endl;
		tags(cUser);
		}
}

void ReadProlog::friends()//gets friends
{
	PlTermv friends(2);
	friends[0]=PlCompound(cUser->getUsername().c_str());
	PlQuery userFriends("friend",friends);

	while(userFriends.next_solution()){
		User* cUserFriend = new User();
		cUserFriend->setUsername("'" + (string)friends[1] + "'");
		//cout<<"Direct friend: "<<cUserFriend->getUsername()<<endl;
		tags(cUserFriend);
		cUser->setFriend(cUserFriend);
		friendsOfFriends(cUserFriend);
	}
}

void ReadProlog::friendsOfFriends(User* user)//gets friends of friends
{
	PlTermv friends(2);
	friends[0]=PlCompound(user->getUsername().c_str());
	PlQuery userFriends("friend",friends);

	while(userFriends.next_solution()){
		User* cUserFriend = new User();
		cUserFriend->setUsername("'" + (string)friends[1] + "'");
		//cout<<"Friend of "<<user->getUsername().c_str()<<endl<<thisFriendOfFriend<<endl;
		tags(cUserFriend);
		user->setFriend(cUserFriend);
	}	
}

void ReadProlog::tags(User* user)//gets user tags
{
	PlTermv tag(2);
	tag[0]=PlCompound(user->getUsername().c_str());
	PlQuery userTags("user_tags",tag);

	while(userTags.next_solution()){
		//cout<<"Tag: "<<(string)tag[1]<<endl;
		user->setTag((string)tag[1]);
		}
}

void ReadProlog::showNetwork()
{
	this->user();//loads user info
	this->friends();
	cUser->showNetwork();//shows network
}

//lucky7elemental
//elemental777
//1101008elemental
//addedeffect777






