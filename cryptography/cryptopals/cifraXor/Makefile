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

CIFRAXOROBJS = quebradorCifra.o main.o

QUEBRAR = quebrar

EXECS = $(QUEBRAR)
				
ALL = $(EXECS)

# REGRA IMPLICITA
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

quebrar: $(CIFRAXOROBJS)
	$(LD) $(LFLAGS) -o $@ $(CIFRAXOROBJS)


clean:
	rm -f *.o $(EXECS)


