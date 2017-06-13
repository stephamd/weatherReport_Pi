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
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

//#if defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_SAX1_ENABLED)

//extern "C" void XMLCDECL

bool debug1 = true;

XmlParser::XmlParser() {
}

XmlParser::XmlParser(const char* _filename) {
    filename = _filename;
}

XmlParser::~XmlParser() {
}

int XmlParser::openDoc() {
    assert(filename);
    if (debug1) printf("Open Document\n");
    doc = xmlParseFile(filename);
    if (debug1) printf("Document Opened\n");

    //close and return if file is not formatted correctly
    if (doc == NULL) {
        printf("Document not parsed successfully\n");
        xmlFreeDoc(doc);
        return 0;
    }

    root_node = xmlDocGetRootElement(doc);

    if (root_node == NULL) {
        printf("Document Empty");
        xmlFreeDoc(doc);
        return 0;
    }

    if (xmlStrcmp(root_node->name, (const xmlChar *) "response")) {
        printf("XML Doc is not of correct type");
        cleanUp();
        return 0;
    }

    printf("Document Parsed Successfully\n");
    return 1;

}

//returns all element contents under specified path
//
std::map<std::string, std::string> XmlParser::getPathInfo(std::string path){
    std::map<std::string, std::string> data;
    
    std::vector<std::string> searchNodes = parsePath(path);
    
    
    
    return data;
}


std::vector<std::vector<std::string> > XmlParser::getInfo(std::vector<std::string> vec) {
    std::vector<std::vector<std::string> > info;

    return info;
}

//splits up path string based off of "/"
std::vector<std::string> XmlParser::parsePath(std::string path){
    
    std::vector<std::string> path_elements;
    
    if (path.size() < 2){
        printf("No path defined\n");
        return path_elements;
    }
    
}

int XmlParser::cleanUp() {
    /* Cleanup */
    if (doc != NULL)
        xmlFreeDoc(doc);
    return (0);
}
