﻿
// File generated by Wsutil Compiler version 1.0095 
#include <WebServices.h>
#include "DataModel.Model.xsd.h"
#include "System.xsd.h"

typedef struct _System_xsdLocalDefinitions 
{
    struct  // global types
    {
        char unused;
        struct  // ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
        {
            struct  // TupleOfintdateTimeTag2Xw_Sbs0H
            {
                WS_FIELD_DESCRIPTION m_Item1;
                WS_FIELD_DESCRIPTION m_Item2;
                WS_FIELD_DESCRIPTION m_Item3;
                WS_FIELD_DESCRIPTION* TupleOfintdateTimeTag2Xw_Sbs0HFields [3]; 
            } TupleOfintdateTimeTag2Xw_Sbs0Hdescs; // end of TupleOfintdateTimeTag2Xw_Sbs0H
            WS_FIELD_DESCRIPTION TupleOfintdateTimeTag2Xw_Sbs0H;
            WS_FIELD_DESCRIPTION* ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HFields [1]; 
        } ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs; // end of ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
        struct  // ArrayOfTupleOfintdateTime
        {
            struct  // TupleOfintdateTime
            {
                WS_FIELD_DESCRIPTION m_Item1;
                WS_FIELD_DESCRIPTION m_Item2;
                WS_FIELD_DESCRIPTION* TupleOfintdateTimeFields [2]; 
            } TupleOfintdateTimedescs; // end of TupleOfintdateTime
            WS_FIELD_DESCRIPTION TupleOfintdateTime;
            WS_FIELD_DESCRIPTION* ArrayOfTupleOfintdateTimeFields [1]; 
        } ArrayOfTupleOfintdateTimedescs; // end of ArrayOfTupleOfintdateTime
        struct  // ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
        {
            struct  // TupleOfintArrayOfGameRequestDj_S7S2QP
            {
                WS_FIELD_DESCRIPTION m_Item1;
                WS_FIELD_DESCRIPTION m_Item2;
                WS_FIELD_DESCRIPTION* TupleOfintArrayOfGameRequestDj_S7S2QPFields [2]; 
            } TupleOfintArrayOfGameRequestDj_S7S2QPdescs; // end of TupleOfintArrayOfGameRequestDj_S7S2QP
            WS_FIELD_DESCRIPTION TupleOfintArrayOfGameRequestDj_S7S2QP;
            WS_FIELD_DESCRIPTION* ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPFields [1]; 
        } ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs; // end of ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
    } globalTypes;  // end of global types
    struct  // XML dictionary
    {
        struct  // XML string list
        {
            WS_XML_STRING ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeName;  // ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
            WS_XML_STRING ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace;  // http://schemas.datacontract.org/2004/07/System
            WS_XML_STRING TupleOfintdateTimeTag2Xw_Sbs0HTypeName;  // TupleOfintdateTimeTag2Xw_Sbs0H
            WS_XML_STRING TupleOfintdateTimeTag2Xw_Sbs0Hm_Item1LocalName;  // m_Item1
            WS_XML_STRING TupleOfintdateTimeTag2Xw_Sbs0Hm_Item2LocalName;  // m_Item2
            WS_XML_STRING TupleOfintdateTimeTag2Xw_Sbs0Hm_Item3LocalName;  // m_Item3
            WS_XML_STRING ArrayOfTupleOfintdateTimeTypeName;  // ArrayOfTupleOfintdateTime
            WS_XML_STRING TupleOfintdateTimeTypeName;  // TupleOfintdateTime
            WS_XML_STRING ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPTypeName;  // ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
            WS_XML_STRING TupleOfintArrayOfGameRequestDj_S7S2QPTypeName;  // TupleOfintArrayOfGameRequestDj_S7S2QP
            WS_XML_STRING TupleOfintArrayOfGameRequestDj_S7S2QPm_Item2LocalName;  // GameRequest
            WS_XML_STRING TupleOfintArrayOfGameRequestDj_S7S2QPm_Item2Namespace;  // http://schemas.datacontract.org/2004/07/DataModel.Model
        } xmlStrings;  // end of XML string list
        WS_XML_DICTIONARY dict;
    } dictionary;  // end of XML dictionary
} _System_xsdLocalDefinitions;

const static _System_xsdLocalDefinitions System_xsdLocalDefinitions =
{
    { // global types
        0,
        {  // ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
            {  // TupleOfintdateTimeTag2Xw_Sbs0H
                {  // field description for m_Item1
                WS_ELEMENT_FIELD_MAPPING,
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0Hm_Item1LocalName, // m_Item1
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
                WS_INT32_TYPE,
                0,
                WsOffsetOf(TupleOfintdateTimeTag2Xw_Sbs0H, m_Item1),
                0,
                0,
                0xffffffff
                },    // end of field description for m_Item1
                {  // field description for m_Item2
                WS_ELEMENT_FIELD_MAPPING,
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0Hm_Item2LocalName, // m_Item2
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
                WS_DATETIME_TYPE,
                0,
                WsOffsetOf(TupleOfintdateTimeTag2Xw_Sbs0H, m_Item2),
                0,
                0,
                0xffffffff
                },    // end of field description for m_Item2
                {  // field description for m_Item3
                WS_ELEMENT_FIELD_MAPPING,
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0Hm_Item3LocalName, // m_Item3
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
                WS_STRUCT_TYPE,
                (void*)&DataModel_Model_xsd.globalTypes.Tag,
                WsOffsetOf(TupleOfintdateTimeTag2Xw_Sbs0H, m_Item3),
                WS_FIELD_POINTER| WS_FIELD_NILLABLE,
                0,
                0xffffffff
                },    // end of field description for m_Item3
                {  // fields description for TupleOfintdateTimeTag2Xw_Sbs0H
                (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0Hdescs.m_Item1,
                (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0Hdescs.m_Item2,
                (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0Hdescs.m_Item3,
                },
            },    // TupleOfintdateTimeTag2Xw_Sbs0H
            {  // field description for TupleOfintdateTimeTag2Xw_Sbs0H
            WS_REPEATING_ELEMENT_FIELD_MAPPING,
            0,
            0,
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.TupleOfintdateTimeTag2Xw_Sbs0H,
            WsOffsetOf(ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H, TupleOfintdateTimeTag2Xw_Sbs0H),
            WS_FIELD_POINTER| WS_FIELD_NILLABLE_ITEM,
            0,
            WsOffsetOf(ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H, TupleOfintdateTimeTag2Xw_Sbs0HCount),
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0HTypeName, // TupleOfintdateTimeTag2Xw_Sbs0H
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            0,
            },    // end of field description for TupleOfintdateTimeTag2Xw_Sbs0H
            {  // fields description for ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
            (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0H,
            },
        },    // ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
        {  // ArrayOfTupleOfintdateTime
            {  // TupleOfintdateTime
                {  // field description for m_Item1
                WS_ELEMENT_FIELD_MAPPING,
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0Hm_Item1LocalName, // m_Item1
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
                WS_INT32_TYPE,
                0,
                WsOffsetOf(TupleOfintdateTime, m_Item1),
                0,
                0,
                0xffffffff
                },    // end of field description for m_Item1
                {  // field description for m_Item2
                WS_ELEMENT_FIELD_MAPPING,
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0Hm_Item2LocalName, // m_Item2
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
                WS_DATETIME_TYPE,
                0,
                WsOffsetOf(TupleOfintdateTime, m_Item2),
                0,
                0,
                0xffffffff
                },    // end of field description for m_Item2
                {  // fields description for TupleOfintdateTime
                (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimedescs.TupleOfintdateTimedescs.m_Item1,
                (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimedescs.TupleOfintdateTimedescs.m_Item2,
                },
            },    // TupleOfintdateTime
            {  // field description for TupleOfintdateTime
            WS_REPEATING_ELEMENT_FIELD_MAPPING,
            0,
            0,
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.TupleOfintdateTime,
            WsOffsetOf(ArrayOfTupleOfintdateTime, TupleOfintdateTime),
            WS_FIELD_POINTER| WS_FIELD_NILLABLE_ITEM,
            0,
            WsOffsetOf(ArrayOfTupleOfintdateTime, TupleOfintdateTimeCount),
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTypeName, // TupleOfintdateTime
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            0,
            },    // end of field description for TupleOfintdateTime
            {  // fields description for ArrayOfTupleOfintdateTime
            (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimedescs.TupleOfintdateTime,
            },
        },    // ArrayOfTupleOfintdateTime
        {  // ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
            {  // TupleOfintArrayOfGameRequestDj_S7S2QP
                {  // field description for m_Item1
                WS_ELEMENT_FIELD_MAPPING,
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0Hm_Item1LocalName, // m_Item1
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
                WS_INT32_TYPE,
                0,
                WsOffsetOf(TupleOfintArrayOfGameRequestDj_S7S2QP, m_Item1),
                0,
                0,
                0xffffffff
                },    // end of field description for m_Item1
                {  // field description for m_Item2
                WS_REPEATING_ELEMENT_FIELD_MAPPING,
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0Hm_Item2LocalName, // m_Item2
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
                WS_STRUCT_TYPE,
                (void*)&DataModel_Model_xsd.globalTypes.GameRequest,
                WsOffsetOf(TupleOfintArrayOfGameRequestDj_S7S2QP, m_Item2),
                WS_FIELD_POINTER| WS_FIELD_NILLABLE| WS_FIELD_NILLABLE_ITEM,
                0,
                WsOffsetOf(TupleOfintArrayOfGameRequestDj_S7S2QP, m_Item2Count),
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintArrayOfGameRequestDj_S7S2QPm_Item2LocalName, // GameRequest
                (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintArrayOfGameRequestDj_S7S2QPm_Item2Namespace, // http://schemas.datacontract.org/2004/07/DataModel.Model
                0,
                },    // end of field description for m_Item2
                {  // fields description for TupleOfintArrayOfGameRequestDj_S7S2QP
                (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs.TupleOfintArrayOfGameRequestDj_S7S2QPdescs.m_Item1,
                (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs.TupleOfintArrayOfGameRequestDj_S7S2QPdescs.m_Item2,
                },
            },    // TupleOfintArrayOfGameRequestDj_S7S2QP
            {  // field description for TupleOfintArrayOfGameRequestDj_S7S2QP
            WS_REPEATING_ELEMENT_FIELD_MAPPING,
            0,
            0,
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.TupleOfintArrayOfGameRequestDj_S7S2QP,
            WsOffsetOf(ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP, TupleOfintArrayOfGameRequestDj_S7S2QP),
            WS_FIELD_POINTER| WS_FIELD_NILLABLE_ITEM,
            0,
            WsOffsetOf(ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP, TupleOfintArrayOfGameRequestDj_S7S2QPCount),
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintArrayOfGameRequestDj_S7S2QPTypeName, // TupleOfintArrayOfGameRequestDj_S7S2QP
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            0,
            },    // end of field description for TupleOfintArrayOfGameRequestDj_S7S2QP
            {  // fields description for ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
            (WS_FIELD_DESCRIPTION*)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs.TupleOfintArrayOfGameRequestDj_S7S2QP,
            },
        },    // ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
    }, // end of global types
    {  // dictionary 
        {  // xmlStrings
            WS_XML_STRING_DICTIONARY_VALUE("ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H",&System_xsdLocalDefinitions.dictionary.dict, 0),
            WS_XML_STRING_DICTIONARY_VALUE("http://schemas.datacontract.org/2004/07/System",&System_xsdLocalDefinitions.dictionary.dict, 1),
            WS_XML_STRING_DICTIONARY_VALUE("TupleOfintdateTimeTag2Xw_Sbs0H",&System_xsdLocalDefinitions.dictionary.dict, 2),
            WS_XML_STRING_DICTIONARY_VALUE("m_Item1",&System_xsdLocalDefinitions.dictionary.dict, 3),
            WS_XML_STRING_DICTIONARY_VALUE("m_Item2",&System_xsdLocalDefinitions.dictionary.dict, 4),
            WS_XML_STRING_DICTIONARY_VALUE("m_Item3",&System_xsdLocalDefinitions.dictionary.dict, 5),
            WS_XML_STRING_DICTIONARY_VALUE("ArrayOfTupleOfintdateTime",&System_xsdLocalDefinitions.dictionary.dict, 6),
            WS_XML_STRING_DICTIONARY_VALUE("TupleOfintdateTime",&System_xsdLocalDefinitions.dictionary.dict, 7),
            WS_XML_STRING_DICTIONARY_VALUE("ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP",&System_xsdLocalDefinitions.dictionary.dict, 8),
            WS_XML_STRING_DICTIONARY_VALUE("TupleOfintArrayOfGameRequestDj_S7S2QP",&System_xsdLocalDefinitions.dictionary.dict, 9),
            WS_XML_STRING_DICTIONARY_VALUE("GameRequest",&System_xsdLocalDefinitions.dictionary.dict, 10),
            WS_XML_STRING_DICTIONARY_VALUE("http://schemas.datacontract.org/2004/07/DataModel.Model",&System_xsdLocalDefinitions.dictionary.dict, 11),
        },  // end of xmlStrings
        
        {  // System_xsddictionary
          // 59218c8c-79dc-4be8-8458-ada201b874f7 
        { 0x59218c8c, 0x79dc, 0x4be8, { 0x84, 0x58, 0xad,0xa2, 0x01, 0xb8, 0x74, 0xf7 } },
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings,
        12,
        TRUE,
        },
    },  //  end of dictionary
}; //  end of System_xsdLocalDefinitions

const _System_xsd System_xsd =
{
    {  // globalTypes
        {
        sizeof(ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H),
        __alignof(ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H),
        (WS_FIELD_DESCRIPTION**)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HFields,
        WsCountOf(System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HFields),
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeName, // ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
        0,
        0,
        0,
        },   // end of struct description for ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
        {
        sizeof(TupleOfintdateTimeTag2Xw_Sbs0H),
        __alignof(TupleOfintdateTimeTag2Xw_Sbs0H),
        (WS_FIELD_DESCRIPTION**)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0HFields,
        WsCountOf(System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0Hdescs.TupleOfintdateTimeTag2Xw_Sbs0HFields),
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0HTypeName, // TupleOfintdateTimeTag2Xw_Sbs0H
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
        0,
        0,
        0,
        },   // end of struct description for TupleOfintdateTimeTag2Xw_Sbs0H
        {
        sizeof(ArrayOfTupleOfintdateTime),
        __alignof(ArrayOfTupleOfintdateTime),
        (WS_FIELD_DESCRIPTION**)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimedescs.ArrayOfTupleOfintdateTimeFields,
        WsCountOf(System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimedescs.ArrayOfTupleOfintdateTimeFields),
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTypeName, // ArrayOfTupleOfintdateTime
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
        0,
        0,
        0,
        },   // end of struct description for ArrayOfTupleOfintdateTime
        {
        sizeof(TupleOfintdateTime),
        __alignof(TupleOfintdateTime),
        (WS_FIELD_DESCRIPTION**)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimedescs.TupleOfintdateTimedescs.TupleOfintdateTimeFields,
        WsCountOf(System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintdateTimedescs.TupleOfintdateTimedescs.TupleOfintdateTimeFields),
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTypeName, // TupleOfintdateTime
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
        0,
        0,
        0,
        },   // end of struct description for TupleOfintdateTime
        {
        sizeof(ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP),
        __alignof(ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP),
        (WS_FIELD_DESCRIPTION**)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPFields,
        WsCountOf(System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPFields),
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPTypeName, // ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
        0,
        0,
        0,
        },   // end of struct description for ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
        {
        sizeof(TupleOfintArrayOfGameRequestDj_S7S2QP),
        __alignof(TupleOfintArrayOfGameRequestDj_S7S2QP),
        (WS_FIELD_DESCRIPTION**)&System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs.TupleOfintArrayOfGameRequestDj_S7S2QPdescs.TupleOfintArrayOfGameRequestDj_S7S2QPFields,
        WsCountOf(System_xsdLocalDefinitions.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPdescs.TupleOfintArrayOfGameRequestDj_S7S2QPdescs.TupleOfintArrayOfGameRequestDj_S7S2QPFields),
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintArrayOfGameRequestDj_S7S2QPTypeName, // TupleOfintArrayOfGameRequestDj_S7S2QP
        (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
        0,
        0,
        0,
        },   // end of struct description for TupleOfintArrayOfGameRequestDj_S7S2QP
    },  // globalTypes
    {  // globalElements
        {
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeName, // ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0H,
        },
        {
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTag2Xw_Sbs0HTypeName, // TupleOfintdateTimeTag2Xw_Sbs0H
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.TupleOfintdateTimeTag2Xw_Sbs0H,
        },
        {
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTypeName, // ArrayOfTupleOfintdateTime
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.ArrayOfTupleOfintdateTime,
        },
        {
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintdateTimeTypeName, // TupleOfintdateTime
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.TupleOfintdateTime,
        },
        {
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QPTypeName, // ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.ArrayOfTupleOfintArrayOfGameRequestDj_S7S2QP,
        },
        {
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.TupleOfintArrayOfGameRequestDj_S7S2QPTypeName, // TupleOfintArrayOfGameRequestDj_S7S2QP
            (WS_XML_STRING*)&System_xsdLocalDefinitions.dictionary.xmlStrings.ArrayOfTupleOfintdateTimeTag2Xw_Sbs0HTypeNamespace, // http://schemas.datacontract.org/2004/07/System
            WS_STRUCT_TYPE,
            (void*)&System_xsd.globalTypes.TupleOfintArrayOfGameRequestDj_S7S2QP,
        },
    },  // globalElements
}; // end of _System_xsd