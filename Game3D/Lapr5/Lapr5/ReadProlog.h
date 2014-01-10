//Author Fred 1101008
//This class is used for reading data passe to prolog from a http Web Service.
//It reads prolog facts and passes the data to objects to be worked in OpenGL

#include <string>
#include "User_Local.h"

using namespace std;

class ReadProlog{

private:
	int nFriends;
	int nTags;
	string currentUser; 
    User_Local* cUser;

public:
	ReadProlog();
	~ReadProlog();
	void user();
	void friends();
	void friendsOfFriends(User_Local* user);
	void tags(User_Local* user);
	void showUser(User_Local* user);
	void readToObject();
};



//lucky7elemental
//elemental777
//1101008elemental
//addedeffect777






