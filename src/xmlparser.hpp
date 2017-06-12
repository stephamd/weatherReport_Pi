
/* 
 * File:   xmlparser.hpp
 * Author: matt
 *
 * Created on June 12, 2017, 9:35 AM
 */

#ifndef XMLPARSER_HPP
#define XMLPARSER_HPP

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


class XmlParser {
public:
    XmlParser();
    XmlParser(const char*);
    ~XmlParser();
    int openDoc();
    std::vector<std::vector<std::string> > getInfo(std::vector<std::string>);
    int cleanUp();
    
private:
    const char* filename;
    xmlDocPtr doc = NULL;
    xmlNodePtr cur = NULL;
};
#endif /* XMLPARSER_HPP */



