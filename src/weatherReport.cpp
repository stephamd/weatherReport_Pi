/*

Weather reporting using curl and weather underground api


author: Matt Stephan

 */



//includes

#include <stdio.h>
#include <stddef.h>
#include <string>
#include <curl/curl.h>
#include "xmlparser.hpp"


size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char* argv[]) {

    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = "http://api.wunderground.com/api/f20b91a98c48d70f/conditions/q/OH/Cincinnati.xml";
    char outfilename[FILENAME_MAX] = "./res/weather_report.xml";

    //initialize objects
    XmlParser parser = XmlParser("./res/weather_report.xml");
    curl = curl_easy_init();

    if (curl) {

        printf("curl intialized properly\n");


        fp = fopen(outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }

    parser.openDoc();

    parser.cleanUp();

    return 0;
}




