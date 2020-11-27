#include <iostream>
#include "requests.h"

using namespace std;

int main(){
    httpManager manager;
    
    manager.makeRegister();
    cout << "regiter done!" << endl;
    //commandInput cmd= manager.getComand();
    //cmd.result.response="ok";
    //manager.report(cmd.result);
    //manager.upload("test.txt");
    manager.download("paimon.png");
}