/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: 
 */
#include <stdio.h>
#include <stdlib.h>

#include "reversa.h"

int
main (int argc, char **argv)
{
	
	if (argc!=NUMERO_ARGUMENTOS)
	{
		printf("\nErro(%i): numero de argumentos invalido \n Uso: %s <numero> \n\n", numeroArgumentosInvalido, argv[0]);
		exit(numeroArgumentosInvalido);
	}
	printf ("\nfloat:%lu\ndouble:%lu\n\n", sizeof(float), sizeof(double));

	return ok;
}
