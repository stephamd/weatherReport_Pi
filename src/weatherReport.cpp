/*

Weather reporting using curl and weather underground API


author: Matt Stephan

 */



//includes

#include <stdio.h>
#include <stddef.h>
#include <string>
#include <curl/curl.h>
#include "curlWrapper.hpp"
#include "xmlparser.hpp"


int main(int argc, char* argv[]) {

    curlWrapper curl();
    curl.init_curl();
    char *url = "http://api.wunderground.com/api/f20b91a98c48d70f/conditions/q/OH/Cincinnati.xml";
    char outfilename[FILENAME_MAX] = "./res/weather_report.xml";

    //initialize objects
    XmlParser parser = XmlParser("./res/weather_report.xml");

   

    parser.openDoc();

    parser.cleanUp();

    return 0;
}




