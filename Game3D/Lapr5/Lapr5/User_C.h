#ifndef USER_C_
#define USER_C_

#include <string>
#include <iostream>
#include <vector>


using namespace std;

//User has an array of users representing his friends;
//This array has users so it can be lodged intp a new user array(friends of friends); 

class User_C{

private:
	int idUser;
	string username;
	//tagName
	vector<tuple<int,string>> *tagList;
	//idFriend,TagName
	vector<tuple<int,string>> *friends;
	//idUser
	vector<int> *request;
	//tuple<idUser, list<tuple<idGame, dif, status>>>
	vector<tuple<int,vector<tuple<int,int,bool>>>> *reqNeg;
	int points;
	int moodState;



public:
	User_C();
	~User_C();

	int getIdUser();
	vector<tuple<int,string>>* getTagList();
	vector<tuple<int,string>>* getFriends();
	vector<int>* getRequest();
	vector<tuple<int,vector<tuple<int,int,bool>>>>* getReqNeg();
	int getPoints();
	int getMoodState();
	string getUsername();

	void setUsername(string username);
	void setIdUser(int idUser);
	void setTagList(vector<tuple<int,string>> *lst);
	void setFriends(vector<tuple<int,string>> *lst);
	void setRequest(vector<int> *lst);
	void setReqNeg(vector<tuple<int,vector<tuple<int,int,bool>>>> *lst);
	void setPoints(int points);
	void setMoodState(int mood);



	User_C& operator=(const User_C& user);
	void toString();

};

#endif