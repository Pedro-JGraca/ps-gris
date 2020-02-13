#
# Universidade Federal do Rio de Janeiro
# Processo Seletivo GRIS
# Autor: Pedro Jullian Medina Torres Graca
# Descricao: 
#

CC = gcc
LD = gcc

CFLAGS = -Wall -std=c11
LFLAGS = -Wall -std=c11

REVERSAOBJS =  main.o
#primeiro coloco o codigo fonte e depois o codigo main

REVERSA = reversa

ALL = $(REVERSA)

# REGRA IMPLICITA
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

reversa: $(REVERSAOBJS)
	$(LD) $(LFLAGS) -o $@ $(REVERSAOBJS)


clean:
	rm -f *.o $(EXECS)


