#
# Universidade Federal do Rio de Janeiro
# Processo Seletivo GRIS
# Autor: Pedro Jullian Medina Torres Graça
# Descricao: Arquivo de dependencias
#


CC = gcc
LD = gcc

CFLAGS = -Wall -std=c99
LFLAGS = -Wall -std=c99


DESCRIPTOOBJS = descobreKey.o main.o

DESCRIPTO = descriptoArq

EXECS = $(DESCRIPTO)
 
ALL = $(EXECS)

# REGRA IMPLICITA
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

descriptoArq: $(DESCRIPTOOBJS)
	$(LD) $(LFLAGS) -o $@ $(DESCRIPTOOBJS)

clean:
	rm -f *.o $(EXECS)

