#include <fstream>
#include <tuple>
#include "NetworkWriter.h"

void NetworkWriter::getUsers(vector<User_C>* network){
	this->network=network;
}

void NetworkWriter::writeToProlog(){

	userNetworkData.open("network.pl");

	userNetworkData<<"user('"<<network->at(0).getUsername()<<"')."<<"\n";//writes current user
	getTags(network->at(0));

	for(int i=0; i<network->size(); i++){
		ids.push_back(network->at(i).getIdUser());
		cout<<"id : "<< network->at(i).getIdUser() << "\n";
	}

	for(int i=0;i<network->at(0).getFriends()->size();i++){//get current user friends

		tuple<int,string> temp = network->at(0).getFriends()->at(i);
	
		for(int j=0; j<ids.size(); j++){

			if(ids.at(j)==get<0>(temp)){
				userNetworkData<<"friends('"<<network->at(0).getUsername()<<"','"<<network->at(j).getUsername()<<"')."<<"\n";
				getTags(network->at(j));
				getFriendships(network->at(j), network->at(0).getIdUser());
			}
		}
	}
	userNetworkData.close();
}

void NetworkWriter::getTags(User_C user){

	for(int i=0; i<user.getTagList()->size();i++){//current user tags
		tuple<int,string> temp = user.getTagList()->at(i);
		userNetworkData<<"user_tags('"<<user.getUsername()<<"','"<<get<1>(temp)<<"')."<<"\n";
	}
}

void NetworkWriter::getFriendships(User_C current, int id){//get friends of friends
	
	for(int i=0;i<current.getFriends()->size();i++){
		
		tuple<int,string> temp = current.getFriends()->at(i);
		
		for(int j=0; j<ids.size(); j++){
			if(ids.at(j)==get<0>(temp) && ids.at(j)!=id){
				userNetworkData<<"friends('"<<current.getUsername()<<"','"<<network->at(j).getUsername()<<"')."<<"\n";
				getTags(network->at(j));
			}
		}
	}	
}