/*module for easy interface with the server*/

#ifndef SIMPLE_CURL_H
#define SIMPLE_CURL_H
#include <stdio.h>
#include <string>
#include <vector>
#include <curl/curl.h>


#define SERVER_URL string("http://127.0.0.1:8080")
using namespace std;

class simpleCurl{
    private:
        CURL *curl;
    public:
        simpleCurl();
        string simplePerform(const char * subpath,long *statusCode,
                            const char **headers,FILE *fp);
        CURL *getObject();
        ~simpleCurl();
};


#endif