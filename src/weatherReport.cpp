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

    //TODO: configure based off config.xml
    char *url = "http://api.wunderground.com/api/f20b91a98c48d70f/conditions/q/OH/Cincinnati.xml";
    char outfilename[FILENAME_MAX] = "/home/matt/weatherReport_Pi/res/weather_report.xml";

    
    //-----------testing------------
    curlWrapper curl;
    curl.init_curl();
    curl.downloadFile(outfilename, url);

    XmlParser parser = XmlParser("/home/matt/weatherReport_Pi/res/weather_report.xml");

    parser.openDoc();

    printf("made it past open doc\n");
    parser.cleanUp();
    printf("made it past parser cleanup\n");
    
    curl.cleanUp();
    printf("made if past curl cleanup\n");
    //--------------------------------
    
    //TODO: Create main loop
    
    
    return 0;
}




