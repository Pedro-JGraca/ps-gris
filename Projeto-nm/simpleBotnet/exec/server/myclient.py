import threading
import time
class client:
    def __init__(self,uid,ip):
        self.uid=uid
        self.ip=ip
        self.cmd=None
        self.lastcmd=[]
        self.file=None
        self.cvcmd = threading.Condition()
        self.cvfile = threading.Condition()
        self.setOK = True;

    def report(self,result):
        print("Chegou o result: " + result)
        return self.ouvir(result)

    def getCmd(self):
        self.cvcmd.acquire()

        while self.cmd==None:
            self.cvcmd.wait()
        #consume cmd
        result=self.cmd
        self.lastcmd=result
        self.cmd=None
        self.cvcmd.release()

        return result

    def setCmd(self,cmdList):

        self.cvcmd.acquire() #interrupcao 
        #produce item
        self.cmd=cmdList
        self.cvcmd.notify() #acorda wait, fazendo o get pegar o comando
        self.cvcmd.release()

    def openShell(self,addr,port):
        self.setCmd(["openShell",addr,port])
    
    def runCommand(self,args):
        self.setCmd(["run"]+args)

    def clientOK(self):
        self.setCmd(["isOK"])
        time.sleep(1)# mudar para 5 quando terminar
        if (self.setOK):
            return "Client don't conected"
        else:
            self.setOK=True;
            return "Client ok!"
    
    def fileServer2Client(self,csFile):
        self.setCmd(["downServ"] + [csFile])

    def fileClient2Server(self,scFile):
        self.setCmd(["upServ"] + [scFile])


    def __eq__(self,other):
        return self.uid==other.uid

    def __str__(self):
        return f"uid: {self.uid} ip:{self.ip} activeCmd: {self.cmd} lastcmd: {self.lastcmd}"
        
    def __repr__(self):
        return self.__str__()        