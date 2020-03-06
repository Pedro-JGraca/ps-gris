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


DESCRIPTOOBJS = arquivo.o main.o

DESCRIPTO = descripto

EXECS = $(DESCRIPTO)
 
ALL = $(EXECS)

# REGRA IMPLICITA
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

descripto: $(DESCRIPTOOBJS)
	$(LD) $(LFLAGS) -o $@ $(DESCRIPTOOBJS)

clean:
	rm -f *.o $(EXECS)

