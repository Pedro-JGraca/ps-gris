
class barramento:
    def __init__(self, entrada, saida):
        self.entrada = self.validarEntrada(entrada)
        self.saida = self.validarSaida(saida)

    def atualiza(self,entrada):
        self.limparSaida()
        self.entrada = self.validarEntrada(entrada)
        self.validarSaida(self.saida)
        self.colocarSaida()
        

    def validarEntrada(self,entrada):
        if (type(entrada)==list):
            if (len(entrada)!=0):
                ent = True
                for i in entrada:
                    if (type(i)!=int) and (i!=None):
                        print("bad entrada: " + str(i))
                        ent = False
                    elif ((i!=0) and (i!=1)) and (i!= None):
                        print("bad entrada: " + str(i))
                        ent = False
                if (ent):
                    cnt = 0
                    for i in entrada:
                        if (type(i)==int):
                            cnt+=1
                    if (cnt <= 1):
                        return entrada
                    else:
                        print("Curto!")
                        return False
                else:
                    return False
            else:
                print("tentando entrar com lista vazia")
        else:
            print ("tentando entrar algo diferente de lista de entradas!")
    
    def validarSaida(self, saida):
        if (type(saida)==list):
            if (len(saida)!=0):
                for i in saida:
                    if i!=None:
                        print ("bad saida: " + str(i))
                        return False
            else:
                print("tentando sair lista vazia")
                return False
        else:
            print ("tentando sair com algo diferente de lista de saidas!")
            return False

        return saida
    
    def achaEntrada(self):
        for i in self.entrada:
            if (type(i)==int):
                return self.entrada.index(i)

    def colocarSaida(self):
        if(self.achaEntrada()!= None):
            a = self.entrada[self.achaEntrada()]
        else:
            a = None
        for i in range(0,len(self.saida)):
            self.saida[i]= a
    
    def limparSaida(self):
        for i in range(0,len(self.saida)):
            self.saida[i]= None

class tresS:
    def __init__(self, tamanho):
        self.entrada = []
        self.saida = []
        self.OE=False
        if type(tamanho) != int:
            tamanho = 8
        for i in (0,tamanho):
            self.saida.append(None)
    
    def atualiza(self,inpuT):
        if type(inpuT)==list:
            self.entrada = inpuT
            self.saida = []
            if (self.OE):
                for i in range(0,len(self.entrada)):
                    self.saida.append(self.entrada[i])
            else:
                for i in range(0,len(self.entrada)):
                    self.saida.append(None)
        else:
            print("Atualizacao precisa de lista")
    def setOE(self,i):
        if type(i) == bool:
            self.OE = i
        else:
            print("OE é booleano!")

class registrador:
    def __init__(self, tamanho):
        self.entrada = []
        self.saida = []
        self.OE=False
        self.clk = []

        if type(tamanho) != int:
            tamanho = 8
        for i in (0,tamanho):
            self.saida.append(None)
    
    def atualiza(self,inpuT):
        if type(inpuT)==list:
            self.entrada = inpuT
            self.saida = []
            if (self.OE) and (self.clk):
                for i in range(0,len(self.entrada)):
                    self.saida.append(self.entrada[i])
            else:
                for i in range(0,len(self.entrada)):
                    self.saida.append(None)
        else:
            print("Atualizacao precisa de lista")

    def setOE(self,i):
        if type(i) == bool:
            self.OE = i
        else:
            print("OE é booleano!")
    
    def setCLK(self,i):
        if type(i) == bool:
            self.clk = i
        else:
            print("CLK é booleano!")

class flipFlopD:
    def __init__(self, D):

        self.Q = None
        self.QB= None
        self.clk = False

        if type(D) == bool:
            self.D = D
        else:
            print("D é booleano!")

    def atualiza(self, A):
        if (self.clk):
            self.Q = self.D
            self.D = A
            self.QB = not self.Q
    
    def getQ(self):
        return self.Q

    
class ALU:
    def __init__(self, cin, tamanho):
        self.A = []#8 bits
        self.B = []#8bits
        self.SOUT = []#8bits
        self.clk = False
        self.Cout = 0#
        self.Borrow = 0
        self.zeros = 0
        self.paridade = 0
        self.overflow = 0
        self.preOverflow = 0
        self.cin = cin
        self.FIN = []

        if type(tamanho) != int:
            print("Bad Entrada: " , end = "")
            print(tamanho)
        
        if type(tamanho) == int:
            for i in (0,tamanho):
                self.A.append(None)
                self.B.append(None)
                self.SOUT.append(None)
                if (tamanho<4):
                    self.FIN.append(None)
            self.tamanho = tamanho

        if type(cin) != int:
            print("Bad Entrada: " , end = "")
            print(cin)
        elif cin > 1:
            cin = 1

    def setClk(self, a):
        if type(a) != bool:
            print("Bad Entrada: " , end = "")
            print(a)
        else:
            self.clk = a
    
    def setA(self,A):
        if type(A) != list:
            print("Bad Entrada: " , end = "")
            print(A)
        elif len(A)!=self.tamanho:
            print("Bad Entrada: " , end = "")
            print(A)
        else:
            saida = True
            for i in A:
                if type(i)!=int:
                    saida = False
                elif i != 0 and i != 1:
                    saida = False
            if saida:
                self.A = A

    def setB(self,A):
        if type(A) != list:
            print("Bad Entrada: " , end = "")
            print(A)
        elif len(A)!=self.tamanho:
            print("Bad Entrada: " , end = "")
            print(A)
        else:
            saida = True
            for i in A:
                if type(i)!=int:
                    saida = False
                elif i != 0 and i != 1:
                    saida = False
            if saida:
                self.B = A

    def decide(self,FINO):
        self.SOUT = []
        if (FINO == [0,0,0,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append(self.A[i]) #inverte
            self.inverte()

            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow          
        
        elif (FINO == [0,0,0,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) and (self.B[i])) #A and B

            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades() 
            self.overflow = self.Cout ^ self.preOverflow                
        
        elif (FINO == [0,0,1,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) or (self.B[i])) #A or B

            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow      

        elif (FINO == [0,0,1,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i])) #A
            
            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow

        elif (FINO == [0,1,0,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) + self.B[i]) #A + B
            self.arrumador()
            
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow

        elif (FINO == [0,1,0,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append(self.B[i]) # B
            
            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow


        elif (FINO == [0,1,1,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append(self.A[i]) # a+1
            self.SOUT[len(self.SOUT)-1] += 1
            self.arrumador()

            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow

        
        elif (FINO == [0,1,1,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) and (self.B[i])) #A and B
            self.inverte() #N(A and B)

            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow

        elif (FINO == [1,0,0,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) or (self.B[i])) #A or B
            self.inverte() #N(A or B)

            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow
        
        elif (FINO == [1,0,0,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.B[i])) #B
            self.inverte() #N(B)
            self.SOUT[len(self.SOUT)-1] += 1
            self.arrumador() #N(B) + 1
            for i in range(0, len(self.A)):
                self.SOUT[i] = (self.A[i] + self.SOUT[i]) #A + N(B) + 1
            self.arrumador()
            
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow
        
        elif (FINO == [1,0,1,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) ^ (self.B[i])) #A xor B

            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow
        
        elif (FINO == [1,0,1,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) ^ (self.B[i])) #A xor B
            self.inverte() #N(A xor B)

            self.Cout = 0
            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow

        elif (FINO == [1,1,0,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i]) + self.B[i]) #A + B
            self.arrumador()
            self.SOUT[len(self.SOUT)-1] += self.cin
            self.arrumador() #A + B+cin

            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow
        
        elif (FINO == [1,1,0,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append(self.B[i]) #B
            self.inverte() #N(B)
            for i in range(0, len(self.A)):
                self.SOUT[i] = (self.A[i] + self.SOUT[i]) #A + N(B)

            self.arrumador()

            self.SOUT[len(self.SOUT)-1] += self.cin
            self.arrumador() #A + N(B)+cin

            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow
        
        elif (FINO == [1,1,1,0]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.A[i])) #A
            self.SOUT[len(self.SOUT)-1] += self.cin
            self.arrumador() #A + cin

            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow
    
        elif (FINO == [1,1,1,1]) and self.clk:
            for i in range(0, len(self.A)):
                self.SOUT.append((self.B[i])) #B
            self.SOUT[len(self.SOUT)-1] += self.cin
            self.arrumador() #B + cin

            self.setBorrow()
            self.setZeros()
            self.setParidades()
            self.overflow = self.Cout ^ self.preOverflow
        
        else:
            print ("FIN invalido!")
    
    def arrumador(self):
        for i in range(0,len(self.SOUT)):
            index = len(self.SOUT)-(i+1)
            if (self.SOUT[index]==2):
                self.SOUT[index]= 0
                if (index == 1):
                    self.preOverflow = 1
                if (index == 0 ):
                    self.Cout = 1
                else:
                    self.SOUT[index-1]+=1
            if (self.SOUT[index]==3):
                self.SOUT[index]= 1

                if (index == 1):
                    self.preOverflow = 1

                if (index == 0 ):
                    self.Cout = 1
                else:
                    self.SOUT[index-1]+=1

    def inverte(self):
        for i in range (0,len(self.SOUT)):
            self.SOUT[i] = (-1)*(self.SOUT[i]-1)

    def setBorrow(self):
        self.Borrow = (-1)*(self.Cout-1)
    
    def setZeros(self):
        zeros = True
        for i in self.SOUT:
            if i != 0:
                zeros = False
        if (zeros):
            self.zeros =1
        else:
            self.zeros = 0
    
    def setParidades(self):
        cnt1 = 0
        for i in self.SOUT:
            if i == 1:
                cnt1+=1
        if (cnt1%2 == 0):
            self.paridade = 1
        else:
            self.paridade = 0
        
a = ALU(0,8)

#print(a.A)

a.setClk(True)
a.setA([0,1,0,1,0,0,1,1])
a.setB([1,1,1,1,0,0,0,1])
print(a.A)
print(a.B)
print(25*'-')
a.decide([1,0,0,1])

print(a.SOUT)
print(a.Cout)
print(a.Borrow)