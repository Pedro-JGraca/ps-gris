#ifndef HTTP_MANAGER_H
#define HTTP_MANAGER_H

#include <stdio.h>
#include <string>
#include <vector>
#include <curl/curl.h>

using namespace std;

struct commandReport{
    string response;
    int exitCode;
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
        vector <string> getComand();

        //reports the result of a comand back to server
        void report(const char * report);

        //uploads specific file to /upload
        void upload(const char * fname);

        //downloads file from server and save it locally
        void download(const char *fname);

        void clientOK();
        
};


#endif