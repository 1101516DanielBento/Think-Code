//Author Fred 1101008
//This class writes data from a Web Service to prolog

#include <fstream>
#include <iostream>
#include <vector>
#include "User_C.h"

using namespace std;

class NetworkWriter{

private:
	vector<User_C>* network;
	vector<int> ids;
	ofstream userNetworkData;

public:
	void getUsers(vector<User_C>* network);
	void writeToProlog();
	void getFriendships(User_C user,int id);
	void getTags(User_C user);
};
