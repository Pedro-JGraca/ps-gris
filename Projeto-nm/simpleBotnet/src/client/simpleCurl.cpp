#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


#include "simpleCurl.h"
#include "httpManager.h"

using namespace std;


simpleCurl::simpleCurl()
{
    curl= curl_easy_init();
    if (!curl){
        throw runtime_error( "Unable to init curl" );
    }
}

CURL *
simpleCurl::getObject()
{
    return curl;
}

string 
simpleCurl::simplePerform(const char * subpath, long *statusCode=nullptr,const char **headers,FILE *fp)
{
    
    string result;
    
    CURLcode res;
    struct curl_slist *headerList=NULL;

    //build header list
    if (headers!=nullptr){
        for(unsigned i=0;headers[i]!=NULL;i++){
            headerList = curl_slist_append(headerList, headers[i]);
        }
    }
    
    //set common options
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_URL, (SERVER_URL + subpath).c_str() );
    if (fp!=nullptr){
        curl_easy_setopt(curl, CURLOPT_WRITEDATA,fp);
    }
    else{
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, httpManager::writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
    }

    //perform and check the request
    res = curl_easy_perform(curl);
    if (statusCode!=nullptr){
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, statusCode);
    }

    if(res != CURLE_OK){
        throw runtime_error( string("curl perform error: ")+curl_easy_strerror(res));
    }
    
    cout << "request sucessfully " << result << *statusCode << endl;
    
    
    

    //clean up
    curl_slist_free_all(headerList);
    return result;
}

simpleCurl::~simpleCurl()
{
    curl_easy_reset(curl);
    curl_easy_cleanup(curl);
}