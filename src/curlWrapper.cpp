/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "curlWrapper.hpp"

curlWrapper::curlWrapper() {

}

curlWrapper::~curlWrapper() {
    cleanUp();
}

//Initialize curl
//return:
//  success - true
//  failure - false;

bool curlWrapper::init() {
    curl = curl_easy_init();
    if (curl) {
        return true;
    } else {
        return false;
    }
}

bool curlWrapper::downloadFile(const char* outfilename, const char* url) {
    if (curl) {
        FILE fp = fopen(outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        CURLcode res = curl_easy_perform(curl);
        
        if (res != 0) {
            printf("downloadFile: error, check error buffer\n");
            return false;
        } else {
            return true;
        }
        
    } else {
        printf("downloadFile: curl not initialized\n");
        return false;
    }
    return false;
}

void curlWrapper::cleanUp() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
}

size_t curlWrapper::write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {


}