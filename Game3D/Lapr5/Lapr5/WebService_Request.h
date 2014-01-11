
#ifndef WEBSERVICE_REQUEST_
#define WEBSERVICE_REQUEST_

//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif

#include "WebServices.h"

#include "XMLFiles_WS\schemas.microsoft.com.2003.10.Serialization.xsd.h" 
#include "XMLFiles_WS\tempuri.org.xsd.h" 
#include "XMLFiles_WS\tempuri.org.wsdl.h" 
//#include "XMLFiles_WS\DataModel.Model.xsd.h"
#include "XMLFiles_WS\GameWS.xsd.h"

#include <string> 
#include "wchar.h"
#include <cstring>
#include <iostream> 
#include <vector>
#include "User_C.h"
#include <tuple> 

#include <stdlib.h> 
//#include "stdafx.h"

using namespace std;

class WebService_Request{
protected:
	//WebService 
	HRESULT hr; 
	WS_ERROR* error; 
	WS_HEAP* heap; 
	WS_SERVICE_PROXY* proxy; 
	WS_ENDPOINT_ADDRESS address; 
	WS_STRING url;
	WS_HTTP_BINDING_TEMPLATE templ;

	bool to_bool(std::string const& s);
	vector<string> splitString(string s, string delimiter);
	string convertWcharToString(wchar_t *wc);
	User_C convertObjWStoUser(UserType *usr);
	vector<User_C> *convertWebServiceListToVector(UserType **user, unsigned int size);

public:
	WebService_Request();
	~WebService_Request();

	int login(string UserName, string Password);
	vector<User_C> *getNetworkById(int idUser);


	
};

#endif