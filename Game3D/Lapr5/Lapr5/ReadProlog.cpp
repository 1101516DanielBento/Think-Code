#include <SWI-cpp.h>
#include <iostream>
#include <string>
#include "ReadProlog.h"

char* argProlog[] = {"swipl.ll","-s","network.pl",NULL};
PlEngine e(3,argProlog);

using namespace std;

ReadProlog::ReadProlog(){}

ReadProlog::~ReadProlog(){}

void ReadProlog::user()//gets current user	
{
	cUser = new User_Local();

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
	PlQuery userFriends("friends",friends);

	while(userFriends.next_solution()){
		User_Local* cUserFriend = new User_Local();
		cUserFriend->setUsername("'" + (string)friends[1] + "'");
		//cout<<"Direct friend: "<<cUserFriend->getUsername()<<endl;
		tags(cUserFriend);
		cUser->setFriend(cUserFriend);//adds friend to object User
		cUser->networkSizeInc();//increments network size
		friendsOfFriends(cUserFriend);
	}
}

void ReadProlog::friendsOfFriends(User_Local* user)//gets friends of friends
{
	PlTermv friends(2);
	friends[0]=PlCompound(user->getUsername().c_str());
	PlQuery userFriends("friends",friends);

	while(userFriends.next_solution()){
		User_Local* cUserFriend = new User_Local();
		cUserFriend->setUsername("'" + (string)friends[1] + "'");
		//cout<<"Friend of "<<user->getUsername().c_str()<<endl<<thisFriendOfFriend<<endl;
		tags(cUserFriend);
		user->setFriend(cUserFriend);
		cUser->networkSizeInc();//increments network size
	}	
}

void ReadProlog::tags(User_Local* user)//gets user tags
{
	PlTermv tag(2);
	tag[0]=PlCompound(user->getUsername().c_str());
	PlQuery userTags("user_tags",tag);

	while(userTags.next_solution()){
		//cout<<"Tag: "<<(string)tag[1]<<endl;
		user->setTag((string)tag[1]);
		}
}

void ReadProlog::readToObject()
{
	//_sleep(10000);
	this->user();//loads user info
	this->friends();
	cUser->showNetwork();//shows network
}