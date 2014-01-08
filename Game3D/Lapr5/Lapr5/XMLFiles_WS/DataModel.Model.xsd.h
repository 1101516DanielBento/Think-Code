﻿
// File generated by Wsutil Compiler version 1.0095 
// This file defines C/C++ functions, callbacks, types that correspond to operations,
// and types specified in WSDL and XSD files processed by Wsutil compiler. The generated 
// type definitions, function and callback declarations can be used with various 
// Web Services APIs either in applications that send and receive requests to and 
// from a running web service, or in the implementation of web services, or in both. 
//
// If Wsutil has generated this file from an XSD file, the file contains definition of 
// C/C++ structures types that correspond to types defined in the XSD file. 
// For example, if the following XSD complexType is defined in the XSD file
//
//      <xsd:complexType name="AddRequest">
//          <xsd:sequence>
//              <xsd:element minOccurs="0" name="a" type="xsd:int" />
//              <xsd:element minOccurs="0" name="b" type="xsd:int" />
//          </xsd:sequence>
//      </xsd:complexType>
// 
// this file contains the following definitions of the structure 
//      // AddRequest (xsd:complexType)
//      // <AddRequest xmlns='http://tempuri.org'>
//      // WS_STRUCT_DESCRIPTION* = &calculator_xsd.globalTypes.AddRequest
//      struct AddRequest
//      {
//          int a;
//          int b;
//      };
//
// For more information on how to use the C/C++ types generated in this file to read or write elements of XML documents that conform to 
// this XSD, please see the documentation for 
// WsReadType() and WsWriteType() functions.
// 
#if _MSC_VER > 1000 
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

// The following types were generated:

//     struct ArrayOfUser;
//     struct User;
//     struct Tag;
//     struct ArrayOfGameRequest;
//     struct GameRequest;
//     struct Game;
//     struct ArrayOfTag;
//     struct ArrayOfUser;
//     struct User;
//     struct Tag;
//     struct ArrayOfGameRequest;
//     struct GameRequest;
//     struct Game;
//     struct ArrayOfTag;

// The following header files must be included in this order before this one

// #include <WebServices.h>
// #include "System.xsd.h"

////////////////////////////////////////////////
// C structure definitions for generated types
////////////////////////////////////////////////

// typeDescription: DataModel_Model_xsd.globalTypes.ArrayOfUser
typedef struct ArrayOfUser 
{
    unsigned int UserCount;
    _Field_size_(UserCount)struct User** User; // optional
} ArrayOfUser;

// typeDescription: DataModel_Model_xsd.globalTypes.User
typedef struct User 
{
    BOOL Active;
    WS_DATETIME Birthdate;
    WCHAR* Email; // optional
    unsigned int FriendshipListCount;
    _Field_size_opt_(FriendshipListCount)struct TupleOfintdateTimeTag2Xw_Sbs0H** FriendshipList; // optional
    unsigned int FriendshipRequestListCount;
    _Field_size_opt_(FriendshipRequestListCount)struct TupleOfintdateTime** FriendshipRequestList; // optional
    int IdPermission;
    int IdUser;
    WCHAR* Name; // optional
    WCHAR* Password; // optional
    int Points;
    unsigned int RelationshipRequestNegociationCount;
    _Field_size_opt_(RelationshipRequestNegociationCount)struct TupleOfintArrayOfGameRequestDj_S7S2QP** RelationshipRequestNegociation; // optional
    unsigned int UserTagsCount;
    _Field_size_opt_(UserTagsCount)struct Tag** UserTags; // optional
    WCHAR* Username; // optional
} User;

// typeDescription: DataModel_Model_xsd.globalTypes.Tag
typedef struct Tag 
{
    int IdTag;
    WCHAR* TagName; // optional
} Tag;

// typeDescription: DataModel_Model_xsd.globalTypes.ArrayOfGameRequest
typedef struct ArrayOfGameRequest 
{
    unsigned int GameRequestCount;
    _Field_size_(GameRequestCount)struct GameRequest** GameRequest; // optional
} ArrayOfGameRequest;

#if defined(WS_CPLUSPLUS)
typedef struct Game
{
    Game();
    Game(WS_STRUCT_DESCRIPTION*);
    struct GameRequest* WINAPI AsGameRequest();
    const struct _WS_STRUCT_DESCRIPTION* _type;
    WCHAR* GameName; // optional
    int IdGame;
} Game;
#endif

#if !defined(WS_CPLUSPLUS)
// typeDescription: DataModel_Model_xsd.globalTypes.Game
typedef struct Game 
{
    const struct _WS_STRUCT_DESCRIPTION* _type;
    WCHAR* GameName; // optional
    int IdGame;
} Game;
void WINAPI Game_Init(Game*);
struct GameRequest* WINAPI Game_AsGameRequest(Game*);
#endif

#if defined(WS_CPLUSPLUS)
typedef struct GameRequest:Game
{
    GameRequest();
    int Difficulty;
    BOOL Status;
} GameRequest;
#endif

#if !defined(WS_CPLUSPLUS)
// typeDescription: DataModel_Model_xsd.globalTypes.GameRequest
typedef struct GameRequest 
{
    struct Game _base;
    int Difficulty;
    BOOL Status;
} GameRequest;
void WINAPI GameRequest_Init(GameRequest*);
#endif

// typeDescription: DataModel_Model_xsd.globalTypes.ArrayOfTag
typedef struct ArrayOfTag 
{
    unsigned int TagCount;
    _Field_size_(TagCount)struct Tag** Tag; // optional
} ArrayOfTag;

////////////////////////////////////////////////
// Global web service descriptions.
////////////////////////////////////////////////

typedef struct _DataModel_Model_xsd
{
    struct // globalTypes
    {
        // xml type: ArrayOfUser ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: ArrayOfUser
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: DataModel_Model_xsd.globalTypes.ArrayOfUser
        WS_STRUCT_DESCRIPTION ArrayOfUser;
        
        // xml type: User ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: User
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: DataModel_Model_xsd.globalTypes.User
        WS_STRUCT_DESCRIPTION User;
        
        // xml type: Tag ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: Tag
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: DataModel_Model_xsd.globalTypes.Tag
        WS_STRUCT_DESCRIPTION Tag;
        
        // xml type: ArrayOfGameRequest ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: ArrayOfGameRequest
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: DataModel_Model_xsd.globalTypes.ArrayOfGameRequest
        WS_STRUCT_DESCRIPTION ArrayOfGameRequest;
        
        // xml type: GameRequest ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: GameRequest
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: DataModel_Model_xsd.globalTypes.GameRequest
        WS_STRUCT_DESCRIPTION GameRequest;
        
        // xml type: Game ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: Game
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: DataModel_Model_xsd.globalTypes.Game
        WS_STRUCT_DESCRIPTION Game;
        
        // xml type: ArrayOfTag ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: ArrayOfTag
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: DataModel_Model_xsd.globalTypes.ArrayOfTag
        WS_STRUCT_DESCRIPTION ArrayOfTag;
        
    } globalTypes;
    struct // globalElements
    {
        // xml element: ArrayOfUser ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: ArrayOfUser
        // elementDescription: DataModel_Model_xsd.globalElements.ArrayOfUser
        WS_ELEMENT_DESCRIPTION ArrayOfUser;
        
        // xml element: User ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: User
        // elementDescription: DataModel_Model_xsd.globalElements.User
        WS_ELEMENT_DESCRIPTION User;
        
        // xml element: Tag ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: Tag
        // elementDescription: DataModel_Model_xsd.globalElements.Tag
        WS_ELEMENT_DESCRIPTION Tag;
        
        // xml element: ArrayOfGameRequest ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: ArrayOfGameRequest
        // elementDescription: DataModel_Model_xsd.globalElements.ArrayOfGameRequest
        WS_ELEMENT_DESCRIPTION ArrayOfGameRequest;
        
        // xml element: GameRequest ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: GameRequest
        // elementDescription: DataModel_Model_xsd.globalElements.GameRequest
        WS_ELEMENT_DESCRIPTION GameRequest;
        
        // xml element: Game ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: Game
        // elementDescription: DataModel_Model_xsd.globalElements.Game
        WS_ELEMENT_DESCRIPTION Game;
        
        // xml element: ArrayOfTag ("http://schemas.datacontract.org/2004/07/DataModel.Model")
        // c type: ArrayOfTag
        // elementDescription: DataModel_Model_xsd.globalElements.ArrayOfTag
        WS_ELEMENT_DESCRIPTION ArrayOfTag;
        
    } globalElements;
} _DataModel_Model_xsd;

extern const _DataModel_Model_xsd DataModel_Model_xsd;

#ifdef __cplusplus
}
#endif

