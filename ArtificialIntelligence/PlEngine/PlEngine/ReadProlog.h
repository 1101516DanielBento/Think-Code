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
	//cUser->toString();
}

void ReadProlog::friends()//gets friends
{
	PlTermv friends(2);
	friends[0]=PlCompound(cUser->getUsername().c_str());
	PlQuery userFriends("friends",friends);

	while(userFriends.next_solution()){
		User* cUserFriend = new User();
		cUserFriend->setUsername("'" + (string)friends[1] + "'");
		//cout<<"Direct friend: "<<cUserFriend->getUsername()<<endl;
		tags(cUserFriend);
		cUser->setFriend(cUserFriend);
		friendsOfFriends(cUserFriend);
	}
	//cUser->showFriends();
}

void ReadProlog::friendsOfFriends(User* user)//gets friends of friends
{
	PlTermv friends(2);
	friends[0]=PlCompound(user->getUsername().c_str());
	PlQuery userFriends("friends",friends);

	while(userFriends.next_solution()){//gets friends of friends
		User* cUserFriend = new User();
		cUserFriend->setUsername("'" + (string)friends[1] + "'");
		//cout<<"Friend of "<<user->getUsername().c_str()<<endl<<thisFriendOfFriend<<endl;
		tags(cUserFriend);
		user->setFriend(cUserFriend);
	}
	//user->showFriends();
	
}

void ReadProlog::tags(User* user)//gets user tags
{
	PlTermv tag(2);
	tag[0]=PlCompound(user->getUsername().c_str());
	PlQuery userTags("user_tags",tag);

	while(userTags.next_solution()){//gets tags
		//cout<<"Tag: "<<(string)tag[1]<<endl;
		user->setTag((string)tag[1]);
		}
}

void ReadProlog::showNetwork()
{
	this->user();
	this->friends();
	cUser->showNetwork();
}

//lucky7elemental
//elemental777
//1101008elemental
//addedeffect777






