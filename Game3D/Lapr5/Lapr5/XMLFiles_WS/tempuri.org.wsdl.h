﻿
// File generated by Wsutil Compiler version 1.0095 
// This file defines C/C++ functions, callbacks, types that correspond to operations,
// and types specified in WSDL and XSD files processed by Wsutil compiler. The generated 
// type definitions, function and callback declarations can be used with various 
// Web Services APIs either in applications that send and receive requests to and 
// from a running web service, or in the implementation of web services, or in both. 
//
// If Wsutil has generated this file from a WSDL file, the file may contain up to three 
// sets of C/C++ definitions. The first set consists of function declarations that can be 
// used in calling operations on a running web service from client applications. 
// The second set consists of callback declarations that can be used in the 
// implementation of web services.  
// The third set contains definitions C/C++ structures that are used for serialization of 
// C/C++ types to Schema types defined in the WSDL file.
//
// The set of function declarations for web services clients may contain the 
// following declaration: 
//
//    HRESULT WINAPI DefaultBinding_ICalculator_Add(
//       _In_ WS_SERVICE_PROXY* _serviceProxy,
//       _In_ int a, 
//       _In_ int b, 
//       _Out_ int* result, 
//       _In_ WS_HEAP* _heap,
//       _In_opt_ WS_CALL_PROPERTY* _callProperties,
//       _In_ const ULONG _callPropertyCount,
//       _In_opt_ const WS_ASYNC_CONTEXT*_asyncContext,
//       _In_opt_ WS_ERROR* _error);
//
// This function can be called from an application code to request ICalculator web 
// service to perform operation Add using two integers a and b as input data.
// Once the web service processes this request and sends the result back,
// the result is returned to the caller of this function in the "result" parameter.
// A WS_SERVICE_PROXY must be created using WsCreateServiceProxy() function
// before this proxy function can be invoked.
//
// The set of callbacks for implementation of web services may contain the following 
// definition of a callback: 
//
//    typedef HRESULT (CALLBACK* DefaultBinding_ICalculator_AddCallback) (
//       _In_ const WS_OPERATION_CONTEXT* _context,
//       _In_ int a, 
//       _In_ int b, 
//       _Out_ int* result, 
//       _In_ const WS_ASYNC_CONTEXT* _asyncContext,
//       _In_ WS_ERROR* _error); 
//
//    typedef struct DefaultBinding_ICalculatorFunctionTable 
//    {
//         DefaultBinding_ICalculator_AddCallback DefaultBinding_ICalculator_Add;
//    } DefaultBinding_ICalculatorFunctionTable;
//
// This definition can be used to implement a function that defines the Add operation 
// as a part of an ICalculator web service. Once this callback is implemented and 
// the web service is deployed and running, if a client applications attempts to 
// execute the operation Add, the implementation of this callback is called and 
// it receives two integers a and b as input data and it returns a third integer 
// that is the result of the operation. A WS_SERVICE_ENDPOINT must be filled out, 
// and its contract field set to instance of such a function table.  
// WsCreateServiceHost may then be used to register the endpoint as a service.
// 
// The set with definitions of C/C++ structures may contain a definition of the following 
// structure:
//    typedef struct ContactInfo 
//    {
//			WCHAR*  name;
//			WCHAR*  email;
//			__int64 contactID;
//	  } ContactInfo;
//
// This structure corresponds to the following complex type defined in the WSDL file:
//    <s:complexType name="ContactInfo">
//      <s:sequence>
//        <s:element minOccurs="1" maxOccurs="1" name="name" type="s:string" />
//        <s:element minOccurs="1" maxOccurs="1" name="email" type="s:string" />
//        <s:element minOccurs="1" maxOccurs="1" name="contactID" type="s:long" />
//      </s:sequence>
//    </s:complexType>
//
// For more information about content of this file, please see the documentation for
// Wsutil compiler.
// If Wsutil generates this file from a WSDL file and policy processing is enabled using
// policy switch, the file may contain declaration of functions that can be used 
// for creating a proxy to a web service or an endpoint of a web service. 
// For example, the file may contain declaration of the following function:
//
//    HRESULT DefaultBinding_ICalculator_CreateServiceProxy(
//    _In_ WS_HTTP_SSL_BINDING_TEMPLATE* templateValue,
//    _In_reads_opt_(proxyPropertyCount) const WS_PROXY_PROPERTY* proxyProperties,
//    _In_ const ULONG proxyPropertyCount,
//    _Outptr_ WS_SERVICE_PROXY** proxy,
//    _In_opt_ WS_ERROR* error);
//
// This function can be called from application code to create a service
// proxy object. A service proxy must be created before any request can be sent 
// to the web service.
//
// Also, the file may contain declaration of the following function:
//
//    HRESULT DefaultBinding_ICalculator_CreateServiceEndpoint(
//    _In_ WS_HTTP_SSL_BINDING_TEMPLATE* templateValue,
//    _In_opt_ WS_STRING address,
//    _In_opt_ struct DefaultBinding_ICalculatorFunctionTable* functionTable,
//    _In_opt_ WS_SERVICE_SECURITY_CALLBACK authorizationCallback,
//    _In_reads_opt_(endpointPropertyCount) WS_SERVICE_ENDPOINT_PROPERTY* endpointProperties,
//    _In_ const ULONG endpointPropertyCount,
//    _In_ WS_HEAP* heap,
//    _Outptr_ WS_SERVICE_ENDPOINT** serviceEndpoint,
//    _In_opt_ WS_ERROR* error);
//
// This function can be used to create a Service Host object, which has to be 
// created before a web services starts receiving requests from its clients.
//
// For more information about content of this file, please see the documentation for
// Wsutil compiler.
#if _MSC_VER > 1000 
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

// The following client functions were generated:

//     BasicHttpBinding_IGameWebService_login
//     BasicHttpBinding_IGameWebService_loadUserNetwork
//     BasicHttpBinding_IGameWebService_loadUserNetwork_NR
//     BasicHttpBinding_IGameWebService_loadUserById
//     BasicHttpBinding_IGameWebService_changeUserPoints
//     BasicHttpBinding_IGameWebService_changeMoodState
//     BasicHttpBinding_IGameWebService_doNegociationGameComplete
//     BasicHttpBinding_IGameWebService_getDictionarys

// The following server function tables were generated:

//     struct BasicHttpBinding_IGameWebServiceFunctionTable

// the following policy helpers were generated:

//  BasicHttpBinding_IGameWebService_CreateServiceProxy;
//  BasicHttpBinding_IGameWebService_CreateServiceEndpoint;

// The following header files must be included in this order before this one

// #include <WebServices.h>
// #include "GameWS.xsd.h"
// #include "tempuri.org.xsd.h"

////////////////////////////////////////////////
// Policy helper routines
////////////////////////////////////////////////

//  WS_CHANNEL_PROPERTY_ENCODING = WS_ENCODING_XML_UTF8,
//  WS_CHANNEL_PROPERTY_ADDRESSING_VERSION = WS_ADDRESSING_VERSION_TRANSPORT,
//  WS_ENVELOPE_VERSION = WS_ENVELOPE_VERSION_SOAP_1_1,
// client channel type: WS_CHANNEL_TYPE_REQUEST, service endpoint channel type: WS_CHANNEL_TYPE_REPLY

HRESULT BasicHttpBinding_IGameWebService_CreateServiceProxy(
    _In_opt_ WS_HTTP_BINDING_TEMPLATE* templateValue,
    _In_reads_opt_(proxyPropertyCount) const WS_PROXY_PROPERTY* proxyProperties,
    _In_ const ULONG proxyPropertyCount,
    _Outptr_ WS_SERVICE_PROXY** _serviceProxy,
    _In_opt_ WS_ERROR* error);

struct BasicHttpBinding_IGameWebServiceFunctionTable;
HRESULT BasicHttpBinding_IGameWebService_CreateServiceEndpoint(
    _In_opt_ WS_HTTP_BINDING_TEMPLATE* templateValue,
    _In_opt_ CONST WS_STRING* address,
    _In_opt_ struct BasicHttpBinding_IGameWebServiceFunctionTable* functionTable,
    _In_opt_ WS_SERVICE_SECURITY_CALLBACK authorizationCallback,
    _In_reads_opt_(endpointPropertyCount) WS_SERVICE_ENDPOINT_PROPERTY* endpointProperties,
    _In_ const ULONG endpointPropertyCount,
    _In_ WS_HEAP* heap,
    _Outptr_ WS_SERVICE_ENDPOINT** serviceEndpoint,
    _In_opt_ WS_ERROR* error);

////////////////////////////////////////////////
// Client functions definitions
////////////////////////////////////////////////

// operation: BasicHttpBinding_IGameWebService_login
HRESULT WINAPI BasicHttpBinding_IGameWebService_login(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_opt_z_ WCHAR* username, 
    _In_opt_z_ WCHAR* password, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ int* loginResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

// operation: BasicHttpBinding_IGameWebService_loadUserNetwork
HRESULT WINAPI BasicHttpBinding_IGameWebService_loadUserNetwork(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_ int idUser, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ unsigned int* loadUserNetworkResultCount, 
    _Outptr_opt_result_buffer_(*loadUserNetworkResultCount) UserType*** loadUserNetworkResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

// operation: BasicHttpBinding_IGameWebService_loadUserNetwork_NR
HRESULT WINAPI BasicHttpBinding_IGameWebService_loadUserNetwork_NR(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_ int idUser, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ int* loadUserNetwork_NRResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

// operation: BasicHttpBinding_IGameWebService_loadUserById
HRESULT WINAPI BasicHttpBinding_IGameWebService_loadUserById(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_ int id, 
    _In_opt_z_ WCHAR* securityPass, 
    _Outptr_opt_ UserType** loadUserByIdResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

// operation: BasicHttpBinding_IGameWebService_changeUserPoints
HRESULT WINAPI BasicHttpBinding_IGameWebService_changeUserPoints(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_ int id, 
    _In_ int pointsToAdd, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ BOOL* changeUserPointsResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

// operation: BasicHttpBinding_IGameWebService_changeMoodState
HRESULT WINAPI BasicHttpBinding_IGameWebService_changeMoodState(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_ int idUser, 
    _In_ int mood, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ BOOL* changeMoodStateResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

// operation: BasicHttpBinding_IGameWebService_doNegociationGameComplete
HRESULT WINAPI BasicHttpBinding_IGameWebService_doNegociationGameComplete(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_ int userId_ONPLAY, 
    _In_ int UserIdB, 
    _In_ int idGame, 
    _In_ int difficulty, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ unsigned int* doNegociationGameCompleteResultCount, 
    _Outptr_opt_result_buffer_(*doNegociationGameCompleteResultCount) UserType*** doNegociationGameCompleteResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

// operation: BasicHttpBinding_IGameWebService_getDictionarys
HRESULT WINAPI BasicHttpBinding_IGameWebService_getDictionarys(
    _In_ WS_SERVICE_PROXY* _serviceProxy,
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ unsigned int* getDictionarysResultCount, 
    _Outptr_opt_result_buffer_(*getDictionarysResultCount) Dict*** getDictionarysResult, 
    _In_ WS_HEAP* _heap,
    _In_reads_opt_(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    _In_ const ULONG _callPropertyCount,
    _In_opt_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_opt_ WS_ERROR* _error);

////////////////////////////////////////////////
// Service functions definitions
////////////////////////////////////////////////

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_loginCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_opt_z_ WCHAR* username, 
    _In_opt_z_ WCHAR* password, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ int* loginResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_loadUserNetworkCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_ int idUser, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ unsigned int* loadUserNetworkResultCount, 
    _Outptr_opt_result_buffer_(*loadUserNetworkResultCount) UserType*** loadUserNetworkResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_loadUserNetwork_NRCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_ int idUser, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ int* loadUserNetwork_NRResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_loadUserByIdCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_ int id, 
    _In_opt_z_ WCHAR* securityPass, 
    _Outptr_opt_ UserType** loadUserByIdResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_changeUserPointsCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_ int id, 
    _In_ int pointsToAdd, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ BOOL* changeUserPointsResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_changeMoodStateCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_ int idUser, 
    _In_ int mood, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ BOOL* changeMoodStateResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_doNegociationGameCompleteCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_ int userId_ONPLAY, 
    _In_ int UserIdB, 
    _In_ int idGame, 
    _In_ int difficulty, 
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ unsigned int* doNegociationGameCompleteResultCount, 
    _Outptr_opt_result_buffer_(*doNegociationGameCompleteResultCount) UserType*** doNegociationGameCompleteResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IGameWebService_getDictionarysCallback) (
    _In_ const WS_OPERATION_CONTEXT* _context,
    _In_opt_z_ WCHAR* securityPass, 
    _Out_ unsigned int* getDictionarysResultCount, 
    _Outptr_opt_result_buffer_(*getDictionarysResultCount) Dict*** getDictionarysResult, 
    _In_ const WS_ASYNC_CONTEXT* _asyncContext,
    _In_ WS_ERROR* _error);

// binding: BasicHttpBinding_IGameWebService
typedef struct BasicHttpBinding_IGameWebServiceFunctionTable 
{
    BasicHttpBinding_IGameWebService_loginCallback BasicHttpBinding_IGameWebService_login;
    BasicHttpBinding_IGameWebService_loadUserNetworkCallback BasicHttpBinding_IGameWebService_loadUserNetwork;
    BasicHttpBinding_IGameWebService_loadUserNetwork_NRCallback BasicHttpBinding_IGameWebService_loadUserNetwork_NR;
    BasicHttpBinding_IGameWebService_loadUserByIdCallback BasicHttpBinding_IGameWebService_loadUserById;
    BasicHttpBinding_IGameWebService_changeUserPointsCallback BasicHttpBinding_IGameWebService_changeUserPoints;
    BasicHttpBinding_IGameWebService_changeMoodStateCallback BasicHttpBinding_IGameWebService_changeMoodState;
    BasicHttpBinding_IGameWebService_doNegociationGameCompleteCallback BasicHttpBinding_IGameWebService_doNegociationGameComplete;
    BasicHttpBinding_IGameWebService_getDictionarysCallback BasicHttpBinding_IGameWebService_getDictionarys;
} BasicHttpBinding_IGameWebServiceFunctionTable;

////////////////////////////////////////////////
// Global web service descriptions.
////////////////////////////////////////////////

typedef struct _tempuri_org_wsdl
{
    struct // messages
    {
        // message: IGameWebService_login_InputMessage
        // c type: _login
        // action: "http://tempuri.org/IGameWebService/login"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_login_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_login_InputMessage;
        
        // message: IGameWebService_login_OutputMessage
        // c type: _loginResponse
        // action: "http://tempuri.org/IGameWebService/loginResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_login_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_login_OutputMessage;
        
        // message: IGameWebService_loadUserNetwork_InputMessage
        // c type: _loadUserNetwork
        // action: "http://tempuri.org/IGameWebService/loadUserNetwork"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_loadUserNetwork_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_loadUserNetwork_InputMessage;
        
        // message: IGameWebService_loadUserNetwork_OutputMessage
        // c type: _loadUserNetworkResponse
        // action: "http://tempuri.org/IGameWebService/loadUserNetworkResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_loadUserNetwork_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_loadUserNetwork_OutputMessage;
        
        // message: IGameWebService_loadUserNetwork_NR_InputMessage
        // c type: _loadUserNetwork_NR
        // action: "http://tempuri.org/IGameWebService/loadUserNetwork_NR"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_loadUserNetwork_NR_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_loadUserNetwork_NR_InputMessage;
        
        // message: IGameWebService_loadUserNetwork_NR_OutputMessage
        // c type: _loadUserNetwork_NRResponse
        // action: "http://tempuri.org/IGameWebService/loadUserNetwork_NRResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_loadUserNetwork_NR_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_loadUserNetwork_NR_OutputMessage;
        
        // message: IGameWebService_loadUserById_InputMessage
        // c type: _loadUserById
        // action: "http://tempuri.org/IGameWebService/loadUserById"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_loadUserById_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_loadUserById_InputMessage;
        
        // message: IGameWebService_loadUserById_OutputMessage
        // c type: _loadUserByIdResponse
        // action: "http://tempuri.org/IGameWebService/loadUserByIdResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_loadUserById_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_loadUserById_OutputMessage;
        
        // message: IGameWebService_changeUserPoints_InputMessage
        // c type: _changeUserPoints
        // action: "http://tempuri.org/IGameWebService/changeUserPoints"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_changeUserPoints_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_changeUserPoints_InputMessage;
        
        // message: IGameWebService_changeUserPoints_OutputMessage
        // c type: _changeUserPointsResponse
        // action: "http://tempuri.org/IGameWebService/changeUserPointsResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_changeUserPoints_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_changeUserPoints_OutputMessage;
        
        // message: IGameWebService_changeMoodState_InputMessage
        // c type: _changeMoodState
        // action: "http://tempuri.org/IGameWebService/changeMoodState"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_changeMoodState_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_changeMoodState_InputMessage;
        
        // message: IGameWebService_changeMoodState_OutputMessage
        // c type: _changeMoodStateResponse
        // action: "http://tempuri.org/IGameWebService/changeMoodStateResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_changeMoodState_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_changeMoodState_OutputMessage;
        
        // message: IGameWebService_doNegociationGameComplete_InputMessage
        // c type: _doNegociationGameComplete
        // action: "http://tempuri.org/IGameWebService/doNegociationGameComplete"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_doNegociationGameComplete_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_doNegociationGameComplete_InputMessage;
        
        // message: IGameWebService_doNegociationGameComplete_OutputMessage
        // c type: _doNegociationGameCompleteResponse
        // action: "http://tempuri.org/IGameWebService/doNegociationGameCompleteResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_doNegociationGameComplete_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_doNegociationGameComplete_OutputMessage;
        
        // message: IGameWebService_getDictionarys_InputMessage
        // c type: _getDictionarys
        // action: "http://tempuri.org/IGameWebService/getDictionarys"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_getDictionarys_InputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_getDictionarys_InputMessage;
        
        // message: IGameWebService_getDictionarys_OutputMessage
        // c type: _getDictionarysResponse
        // action: "http://tempuri.org/IGameWebService/getDictionarysResponse"
        // messageDescription: tempuri_org_wsdl.messages.IGameWebService_getDictionarys_OutputMessage
        WS_MESSAGE_DESCRIPTION IGameWebService_getDictionarys_OutputMessage;
        
    } messages;
    struct // contracts
    {
        // binding: BasicHttpBinding_IGameWebService
        // portType: IGameWebService
        // operation: BasicHttpBinding_IGameWebService_login
        //     input message: IGameWebService_login_InputMessage
        //     output message: IGameWebService_login_OutputMessage
        // operation: BasicHttpBinding_IGameWebService_loadUserNetwork
        //     input message: IGameWebService_loadUserNetwork_InputMessage
        //     output message: IGameWebService_loadUserNetwork_OutputMessage
        // operation: BasicHttpBinding_IGameWebService_loadUserNetwork_NR
        //     input message: IGameWebService_loadUserNetwork_NR_InputMessage
        //     output message: IGameWebService_loadUserNetwork_NR_OutputMessage
        // operation: BasicHttpBinding_IGameWebService_loadUserById
        //     input message: IGameWebService_loadUserById_InputMessage
        //     output message: IGameWebService_loadUserById_OutputMessage
        // operation: BasicHttpBinding_IGameWebService_changeUserPoints
        //     input message: IGameWebService_changeUserPoints_InputMessage
        //     output message: IGameWebService_changeUserPoints_OutputMessage
        // operation: BasicHttpBinding_IGameWebService_changeMoodState
        //     input message: IGameWebService_changeMoodState_InputMessage
        //     output message: IGameWebService_changeMoodState_OutputMessage
        // operation: BasicHttpBinding_IGameWebService_doNegociationGameComplete
        //     input message: IGameWebService_doNegociationGameComplete_InputMessage
        //     output message: IGameWebService_doNegociationGameComplete_OutputMessage
        // operation: BasicHttpBinding_IGameWebService_getDictionarys
        //     input message: IGameWebService_getDictionarys_InputMessage
        //     output message: IGameWebService_getDictionarys_OutputMessage
        // contractDescription: tempuri_org_wsdl.contracts.BasicHttpBinding_IGameWebService
        WS_CONTRACT_DESCRIPTION BasicHttpBinding_IGameWebService;
        
    } contracts;
    struct // policies
    {
        // policy for binding: BasicHttpBinding_IGameWebService
        // port name: BasicHttpBinding_IGameWebService, binding: BasicHttpBinding_IGameWebService, namespace: http://tempuri.org/
        WS_HTTP_POLICY_DESCRIPTION BasicHttpBinding_IGameWebService;
    } policies;
} _tempuri_org_wsdl;

extern const _tempuri_org_wsdl tempuri_org_wsdl;

#ifdef __cplusplus
}
#endif

