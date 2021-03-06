#include "WebService_Request.h"
#include <vector>
using namespace std;

bool WebService_Request::to_bool(std::string const& s) {


	if(s == "1")
		return true;
	if(s =="True")
		return true;

	return false;
}

vector<string> WebService_Request::splitString(string s, string delimiter)
{
	vector<string> lst;
	int inic=0;
	int pos = 0;


	while ((pos = s.find(delimiter)) != string::npos) {
		string val(s.substr(inic, pos-inic));
		lst.push_back(val);
		s.erase(0, pos + delimiter.length());
	}

	return lst;

}

string WebService_Request::convertWcharToString(wchar_t *wc){

	wstring ws( wc );
	string str( ws.begin(), ws.end() );

	return str;
}

User_C WebService_Request::convertObjWStoUser(UserType *usr){
	User_C *u = new User_C ();
	u->setIdUser(usr->IdUser);
	u->setUsername(convertWcharToString(usr->Username));
	u->setPoints(usr->Points);
	u->setMoodState(usr->MoodState);

	vector<string>::iterator it;

	//TAG LIST
	vector<string> tagTmp = splitString(convertWcharToString(usr->UserTags),";");
	int i=0;
	vector<tuple<int,string>> *tagListUsr = new vector<tuple<int,string>>();
	for(it=tagTmp.begin() ; it < tagTmp.end(); it++,i++ ) {

		vector<string> tagTmp2 = splitString(*it,",");
		int idT= atoi(tagTmp2[0].c_str());
		string tgN=tagTmp2[1];
		tuple<int,string> tup(idT,tgN);
		tagListUsr->push_back(tup);

	}
	u->setTagList(tagListUsr);

	//FRIENDS
	vector<tuple<int,string>> *friends = new vector<tuple<int,string>>();
	vector<string> frTMP = splitString(convertWcharToString(usr->FriendshipList),";");
	i=0;
	for(it=frTMP.begin() ; it < frTMP.end(); it++,i++ ) {

		vector<string> tagTmp2 = splitString(*it,",");
		int idT= atoi(tagTmp2[0].c_str());
		string tgN=tagTmp2[1];
		tuple<int,string> tup(idT,tgN);
		friends->push_back(tup);

	}
	u->setFriends(friends);

	//REQUESTS
	vector<int> *req = new vector<int>();
	vector<string> rTMP = splitString(convertWcharToString(usr->FriendshipRequestList),";");
	i=0;
	for(it=rTMP.begin() ; it < rTMP.end(); it++,i++ ) {

		int nr= atoi(rTMP[i].c_str());
		req->push_back(nr);

	}
	u->setRequest(req);

	vector<tuple<int,vector<tuple<int,int,bool>>>> *negs = new vector<tuple<int,vector<tuple<int,int,bool>>>>();
	vector<string> negL = splitString(convertWcharToString(usr->RelationshipRequestNegociation),";");
	i=0;
	for(it=negL.begin() ; it < negL.end(); it++,i++ ) {

		vector<string> tagTmp2 = splitString(*it,":");
		int idT= atoi(tagTmp2[0].c_str());

		vector<string> tmp3 = splitString(*it,"->");
		vector<string>::iterator it2;
		int i2=0;
		bool flag=false;
		vector<tuple<int,int,bool>> vecT;
		for(it2=tmp3.begin() ; it2 < tmp3.end(); it2++,i2++ ) {
			if(flag){
				vector<string> tagTmp2x = splitString(*it2,",");
				int idG= atoi(tagTmp2x[0].c_str());
				int dif=atoi(tagTmp2x[1].c_str());
				bool st = to_bool(tagTmp2x[2].c_str());
				tuple<int,int,bool> tup(idG,dif,st);
				vecT.push_back(tup);
			}
			flag=true;
		}
		tuple<int,vector<tuple<int,int,bool>>> tpFN(idT,vecT);
		negs->push_back(tpFN);

	}
	u->setReqNeg(negs);




	return *u;
}


vector<User_C> *WebService_Request::convertWebServiceListToVector(UserType **user, unsigned int size){
	vector<User_C>* vec = new vector<User_C>();

	for(int i=0; i<size;i++){
		vec->push_back(convertObjWStoUser(user[i]));
	}




	return vec;
}

WebService_Request::WebService_Request(){
	hr = ERROR_SUCCESS; 
	error = NULL; 
	heap = NULL; 
	proxy = NULL; 
	WS_ENDPOINT_ADDRESS addressT = {};
	address = addressT; 
	//endere�o do servi�o 
	WS_STRING urlT= WS_STRING_VALUE(L"http://wvm023.dei.isep.ipp.pt/GameWS/GameWebService.svc"); 
	url=urlT;
	address.url = url; 
	hr = WsCreateHeap(2048, 512, NULL, 0, &heap, error); 
	WS_HTTP_BINDING_TEMPLATE templT = {}; 
	templ = templT; 
	//cria��o do proxy para o servi�o 
	hr = BasicHttpBinding_IGameWebService_CreateServiceProxy(&templ, NULL, 0, &proxy, error); 
	hr = WsOpenServiceProxy(proxy, &address, NULL, error); 
}

WebService_Request::~WebService_Request(){}

vector<User_C> * WebService_Request::getNetworkById(int idUser){
	UserType **user;
	unsigned int listSize=0;
	user=(UserType**)malloc((sizeof (UserType))*listSize);
	WCHAR key[] = L"ThinkCode";


	hr=BasicHttpBinding_IGameWebService_loadUserNetwork(proxy,idUser,key,&listSize,&user,heap,NULL,0,NULL,error);

	return convertWebServiceListToVector(user,listSize);

}

int WebService_Request::login(string UserName, string Password){
	wchar_t *username=new wchar_t[UserName.size()+1]();
	for(string::size_type i=0; i<UserName.size(); ++i){
		char act = (char) UserName[i];
		username[i]=act;
	}

	wchar_t *password=new wchar_t[Password.size()+1]();
	for(string::size_type i=0; i<Password.size(); ++i){
		char act = (char) Password[i];
		password[i]=act;
	}

	WCHAR key[] = L"ThinkCode";
	int result = -2;


	hr= BasicHttpBinding_IGameWebService_login(proxy,username,password,key, &result, heap, NULL, 0, NULL, error);

	return result;
}


bool WebService_Request::changeUserPoints(int id, int pointsToAdd){
	WCHAR key[] = L"ThinkCode";
	BOOL result=false;
	hr= BasicHttpBinding_IGameWebService_changeUserPoints(proxy,id,pointsToAdd,key, &result, heap, NULL, 0, NULL, error);

	return result;
}
bool WebService_Request::changeMoodState(int idUser, int mood){
	WCHAR key[] = L"ThinkCode";
	BOOL result=false;
	hr= BasicHttpBinding_IGameWebService_changeMoodState(proxy,idUser,mood,key, &result, heap, NULL, 0, NULL, error);

	return result;

}

User_C WebService_Request::doNegociationGameComplete(int userId_ONPLAY, int UserIdB, int idGame, int difficulty){

	WCHAR key[] = L"ThinkCode";
	UserType **u;
	unsigned int listSize=0;
	u=(UserType**)malloc((sizeof (UserType))*listSize);
	hr= BasicHttpBinding_IGameWebService_doNegociationGameComplete(proxy,userId_ONPLAY,UserIdB,idGame, difficulty,key,&listSize,&u, heap, NULL, 0, NULL, error);

	return convertObjWStoUser(u[0]);

}

vector<Dictionary> *WebService_Request::getDictionarys(){
	WCHAR key[] = L"ThinkCode";
	Dict **d;
	unsigned int listSize=0;
	d=(Dict**)malloc((sizeof (Dict))*listSize+1);
	hr= BasicHttpBinding_IGameWebService_getDictionarys(proxy,key,&listSize,&d, heap, NULL, 0, NULL, error);

	vector<Dictionary> *ret = new vector<Dictionary>();
	for(int i=0; i<listSize; i++){
		Dictionary *tmp = new Dictionary();
		tmp->setIdWord(d[i]->IdDict);
		tmp->setWordName(convertWcharToString(d[i]->Word));

		vector<string> tgTmp= splitString(convertWcharToString(d[i]->TagsUsed),";");
		vector<int> *t=new vector<int>();
		for(int j=0;j<tgTmp.size();j++){
			t->push_back(atoi(tgTmp[i].c_str()));
		}
		tmp->setTagList(t);

		ret->push_back(*tmp);
	}


	return ret;
}