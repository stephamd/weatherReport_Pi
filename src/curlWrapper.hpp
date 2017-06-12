/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   curlWrapper.hpp
 * Author: matt
 *
 * Created on June 12, 2017, 10:29 AM
 */

#ifndef CURLWRAPPER_HPP
#define CURLWRAPPER_HPP

class curlWrapper {
    
public:
    curlWrapper();
    ~curlWrapper();
    
    bool init();
    bool downloadFile(const char* outfilename, const char* url);
    void cleanUp();
    
private:
    CURL *curl;
    write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
    
    
    
    
};



#endif /* CURLWRAPPER_HPP */

