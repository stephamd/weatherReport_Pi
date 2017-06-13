/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "curlWrapper.hpp"
#include <curl/curl.h>



curlWrapper::curlWrapper() {

}

curlWrapper::~curlWrapper() {
    cleanUp();
}

//not part of class
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

//Initialize curl
//return:
//  success - true
//  failure - false;

bool curlWrapper::init_curl() {
    curl = curl_easy_init();
    if (curl) {
        return true;
    } else {
        return false;
    }
}

bool curlWrapper::downloadFile(char outfilename[], char* url) {
    bool result;
    FILE *fp;
    if (curl) {
        fp = fopen(outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        CURLcode res = curl_easy_perform(curl);

        if (res != 0) {
            printf("downloadFile: error, check error buffer\n");
            result = false;
            
        } else {
            result = true;
        }
        
    } else {
        printf("downloadFile: curl not initialized\n");
        result = false;
    }
    fclose(fp);
    return result;
}

void curlWrapper::cleanUp() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
}

