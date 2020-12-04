#!/usr/bin/python3

from flask import Flask
from flask import request
from flask.helpers import send_from_directory
import os,sys

from myManager import manager,decodeJwt,encodeJwt
#from killableThread import thread_with_trace
#from myclient import client

import time
import logging

FOLDER="local"

###############################     ROUTES  ########################################
app = Flask(__name__)
master=manager(sys.argv[1])
door=int(sys.argv[2])

#UID MUST BE PASSED TO PROVE REGISTRATION
def requireRegister():
    uid = request.headers.get('x-auth')
    uid,aproved = decodeJwt(uid)
    return uid["uid"],aproved


#response -> {x-auth:jwt,aproved: true}
@app.route('/register', methods=["GET"])
def register():
    uid,aproved=master.register(request.remote_addr)
    return {"x-auth":uid,"aproved":aproved},200

#example of return  list of unfinished tasks {taskuid1:cmd1,taskuid2:cmd2 ...} 
@app.route('/getcmd', methods=["POST"])
def getCmd():
    uid,aproved=requireRegister()
    if not aproved:
        return {"cmd":"NOP"},403
    command = master.getCmd(uid)
    if command!=None:
        return {"cmd":command},200
    else:
        return {"cmd":"NOP"},404

#report example {taskuid uid:aaaaa,report:"data"} }
#response {result:"OK"}
@app.route('/report', methods=["POST"])
def report():
    uid,aproved=requireRegister()
    if not aproved:
        return "Forbidden",403
    result=request.json["response"]
    master.report(result)
    return {'status':'ok'},200

@app.route('/clientOk', methods=["POST"])
def isOK():
    uid,aproved=requireRegister()
    master.clientList[uid].setOK=False
    return {'status':'ok'},200

@app.route('/admin', methods=["POST"])
def adminCmd():
    try:
        if (master.passwordCorrect(request.headers.get('x-passwd'))):
            return parseJsonPOST_RPC(request.json,master)
        else:
            return {"status":"incorrect password"}
    except Exception as e:
        print('---------------------------------')
        print("error in: " + str(e))

########################    HELPERS    #########################

@app.route("/sendFile2Server", methods=["POST"])   #insegura
def sendFile2Server():
    passwdServer = request.headers.get('x-passwd')
    passwdClient = request.headers.get('x-auth')
    isValid=False
    if (passwdServer!=None):
        if (master.passwordCorrect(request.headers.get('x-passwd'))):
            isValid = True
        else:
            return {"status":"incorrect password"}
    elif (passwdClient!=None):
        uid,isValid=requireRegister()
    else:
        isValid=False
    if (isValid):
        print("RPC SendFile2Server ", request.files['lFile'].filename)
        request.files['lFile'].save(request.files['lFile'].filename)
        os.system("mv " + request.files['lFile'].filename + " " + FOLDER )
        return {'status':'recebido'},200
    else:
        return {'status':'notValid'},200

@app.route("/receiveFromServer", methods=["GET","POST"])
def receiveFromServer(): 
    passwdServer = request.headers.get('x-passwd')
    passwdClient = request.headers.get('x-auth')
    isValid=False
    if (passwdServer!=None):
        if (master.passwordCorrect(request.headers.get('x-passwd'))):
            isValid = True
        else:
            return {"status":"incorrect password"}
    elif (passwdClient!=None):
        uid,isValid=requireRegister()
    else:
        isValid=False
    if (isValid):
        cmd = request.json['sFile']
        return send_from_directory(directory=FOLDER, filename=cmd, as_attachment=True)
    else:
        return {'status':'notValid'},200

def parseJsonPOST_RPC(json,master):

    status_return=200
    if (json["CMD"]=="displayClients"):
        print("RPC DISPLAY",json)
        result=master.displayClients()

    elif (json["CMD"]=="abrirShell"):
        print("RPC abrirShell",json)
        result=master.abrirShell(json["uid"],json["addr"],json["port"])
        if (json["uid"] < len(master.clientList) and json["uid"] >= 0):
            status_return = 200
        else:
            status_return = 400
        
    elif(json["CMD"]=="runCommand"):
        print("RPC runCommand",json)
        result=master.runCommand(json["cmdString"],json["uid"])

    elif (json["CMD"]=="testServer"):
        print("RPC test server")
        result="server ok"

    elif (json["CMD"]=="testClient"):
        print("RPC test server", json)
        result=master.testClient(json["uid"])

    elif (json["CMD"]=="lisFileServer"):
        os.system("ls " + FOLDER +  " 1>>a.txt")
        a = open("a.txt")
        returnList = []
        for line in a:
            returnList.append(line)
        a.close()
        os.system("rm a.txt")
        result= returnList
    
    elif (json["CMD"]=="fileServer2Client"):
        print("RPC file Server 2 Client ", json)
        result=master.fileServer2Client(json["uid"],json["csFile"])
    
    elif (json["CMD"]=="fileClient2Server"):
        print("RPC file Client 2 Server", json)
        result=master.fileClient2Server(json["uid"],json["scFile"])
    
    elif (json["CMD"]=="runComandLocal"):
        print("RPC runComandLocal", json)
        if (os.system(json["cmdL"] + " 1>>.print.txt")==0):
            r = open(".print.txt") 
            result = ""               
            for line in r:
                result+=line
            r.close()
            os.system("rm .print.txt")

        else:
            result = "comand not executed"
            os.system("rm .print.txt")

    else:
        return {"status":"unkown"},401
    
    return {"status":result},status_return

app.run("0.0.0.0",port=door, use_reloader=False)


