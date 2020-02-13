#
# Universidade Federal do Rio de Janeiro
# Processo Seletivo GRIS
# Autor: Pedro Jullian Medina Torres Graca
# Descricao: arquivo makefile de intalacao do programa
#

CC = gcc
LD = gcc

CFLAGS = -Wall -std=c99
LFLAGS = -Wall -std=c99

BASE64OBJS = CodificarBase64.o main.o

BASE64 = base64

EXECS = $(BASE64)
				
ALL = $(EXECS)

# REGRA IMPLICITA
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

base64: $(BASE64OBJS)
	$(LD) $(LFLAGS) -o $@ $(BASE64OBJS)


clean:
	rm -f *.o $(EXECS)


