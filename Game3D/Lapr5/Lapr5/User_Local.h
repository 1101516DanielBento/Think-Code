//Author Fred 1101008
//User created with prolog data

#include <string>
#include <vector>

using namespace std;

class User_Local{

private:
	string username;
	vector<string> taglist;
	vector<User_Local*> friends;
	int numUsers;
	int currentTagNumber;
	int nFriends;

public:
	User_Local();
	~User_Local();
	User_Local& operator=(const User_Local& User_Local);
	void initialize();
	string getUsername();
	int getNetworkSize();
	void networkSizeInc();
	void setUsername(string username);
	string getTags();
	void setTag(string tag);
	void setFriend(User_Local* User_Local);
	void showFriends();
	void toString();
	void showNetwork();
};

