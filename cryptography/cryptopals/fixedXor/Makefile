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

FIXEDXOROBJS = xozador.o main.o

XOR = xor

EXECS = $(XOR)
				
ALL = $(EXECS)

# REGRA IMPLICITA
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

xor: $(FIXEDXOROBJS)
	$(LD) $(LFLAGS) -o $@ $(FIXEDXOROBJS)


clean:
	rm -f *.o $(EXECS)


