#ifndef DIRTYMODULES_H
#define DIRTYMODULES_H

#include "httpManager.h"

void openShell(vector <string> cmd,httpManager &manager);

void sendfile(vector <string> cmd,httpManager &manager);

void writefile(vector <string> cmd,httpManager &manager);

void execute(vector <string> cmd,httpManager &manager);

void run(vector <string> cmd,httpManager &manager);

void isOK(httpManager &manager);
#endif