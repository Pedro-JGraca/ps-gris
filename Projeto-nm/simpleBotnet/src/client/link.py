
import requests

class linker:
    def __init__(self,addr="http://127.0.0.1:8080/"):
        self.jwtToken=""
        self.addr=addr

    def doRequest(self,rote,json):
        try:
            addr = self.addr + rote
            #precisa colocar o jwtToken no json?
            r=requests.post(addr,json=json)
            return [r.json(),r.status_code]

        except Exception as e:
            print("[python] exception ocurred!",e)
            return False


    def makeRegister(self):

        json = "a"

        Return = self.doRequest("register", json)

        if (Return==False):
            print("[python] register was not made")
            return False
        
        elif (Return[1]==200):
            print("[python] register was made")
            self.jwtToken="x-auth: " + Return[0].json["x-auth"]
            return True
        
        else:
            print("[python] Code response Error: " + str(Return[1]))
            return False
    
    def report(self,input):
        if (type(input) is str):

            print("[python] report: " + input)
            json={"response":input} #response é campo do json enviado
            self.doRequest("report",json) #report se refere a rota flask 

        else:
            print("[python] The input is not string.")
        
    def clientOK(self):
        print("[python] responding OK")
        json = {"status":"ok"}
        Return = self.doRequest("clientOk",json)
        if (Return==False):
            print("[python] not responded OK... server not found")
        elif (Return[1]==200):
            print("[python] responded OK")
        else:
            print("[python] not responded OK... server not understend")

    def upload(self,file):

        json = {"file":file}

        Return = self.doRequest("upload",json)
        if (Return==False):
            print("[python] not upload... server not found")
            return False
        elif (Return[1]==200):
            print("[python] upload OK")
            return True
        else:
            print("[python] not upload... server not understend")
            return False

    def download(self,file):
        try :
            ref_arquivo = open(str(file),"r")
            ref_arquivo.close()
        except:
            print ("don't find file: " + str(file))
            return False
        json = {"download":str(file)}

        Return = self.doRequest("download",json)
        if (Return==False):
            print("[python] not download... server not found")
            return False
        elif (Return[1]==200):
            print("[python] download OK")
            return True
        else:
            print("[python] not download... server not understend")
            return False

        
link=linker()

