
#include <iostream>
#include <vector>
#include "clientManager.h"

using namespace std;

options 
cmd2Enum( string& cmd )
{
    options result;
    vector<string> cmds={"openShell","run", "isOK","nop"};

    for(unsigned i=0;  i < cmds.size();i++ )
    {   
        if (cmd==cmds[i]){
            result=static_cast<options>(i);
            return result;
        }
    }
    return op_nop;
}

int 
main()
{
    clientManager manager;
    if (!manager.getRegisterMade()){
        return 1;
    }
    
    vector <string> cmd;

    while (1){
        string exec = manager.getComand();
        options option=cmd2Enum(exec);
        cmd = manager.getArgs();

        switch (option)
        {
            
        case op_openShell:
            cout << "opening shell" << endl;
            manager.openShell(cmd);
            break;

        case op_run:
            cout << "op_run" << endl;
            manager.run(cmd);
            break;
        
        case op_isOK:
            cout << "op_isOK" << endl;
            manager.isOK();
            break;

        case op_nop:
            cout << "NOP" << endl;
            break;
        
        default:
            cout << "unkownOption" << endl;
            break;
        }

    }
}

/*
    1 : adm -> serv
    2 : serv -> clt
    3 : serv <- clt
    4 : adm <- serv

    5 : adm -> clt
            adm -> serv
            serv -> clt

    6 : adm <- clt
            serv <- clt
            adm <- serv 
*/