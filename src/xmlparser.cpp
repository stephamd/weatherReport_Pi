/* xmlparser.cpp
 *
 * Copyright � TechSolve Inc. 2013-2016,
 * All rights reserved.
 * 
 * Use without explicit consent in writing is forbidden.
 *
 */


#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include "xmlparser.hpp"


using namespace std;

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

//#if defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_SAX1_ENABLED)

//extern "C" void XMLCDECL

bool debug1 = true;

XmlParser::XmlParser()
{
}

XmlParser::XmlParser(const char* _filename)
{
    filename = _filename;
}

XmlParser::~XmlParser()
{
}

int XmlParser::openDoc()
{
    assert(filename);
    if (debug1) cout << "Open Document" << endl;
    doc = xmlParseFile(filename);
    if (debug1) cout << "Document Opened" << endl;

    //close and return if file is not formatted correctly
    if (doc == NULL){
	printf("Document not parsed successfully\n");
        xmlFreeDoc(doc);
	return 0;
    }

    cur = xmlDocGetRootElement(doc);    

    if (cur == NULL){
	printf("Document Empty");
	xmlFreeDoc(doc);
	return 0;
    }

    if (xmlStrcmp(cur->name, (const xmlChar *) "response")){
	printf("XML Doc is not of correct type");
	xmlFreeDoc(doc);
	return 0;
    }
    
    printf("Document Parsed Successfully\n");
    return 1; 

}


vector<vector<string> > XmlParser::getInfo(vector<string> vec)
{
    vector<vector<string> > info;
        
    return info;
}

int XmlParser::cleanUp()
{
    /* Cleanup */ 
    xmlFreeDoc(doc); 
    return(0);
}
