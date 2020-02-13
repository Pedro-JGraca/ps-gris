/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: arquivo da funcao teste que codifica hexa para a base64.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#include "base64.h"

int
main (int argc, char **argv)
{
 	byte *buffer;
	char armazem[3];
	unsigned indice, validador,auxiliar;
	char *codificado;
	char *validacao;
	byte hexa;

	if (argc!=NUMERO_ARGUMENTOS)
	{
		printf("\nO numero de argumentos fornecido (%i) é invalido",argc);
		printf("\nUso: %s <string-a-ser-convertida>\n\n", argv[0]);
		exit(numeroArgumentosInvalido);
	}
	
	for(indice=0;indice<strlen(argv[1]);indice++)
		if (Verificador(argv[1][indice])!=0)
		{
			printf("\nCaracter %c na posicao %u Invalido\n\n", argv[1][indice], indice);
			exit(caracterInvalido);
		}

	if(indice%2==1)
	{
		argv[1][indice++]='0';
		argv[1][indice]=EOS;
	}

	buffer=malloc(sizeof(byte)*indice);
	codificado=malloc((sizeof(byte)*indice*2));
	
	for(auxiliar=0;auxiliar<indice;auxiliar++)
	{
		armazem[0]=argv[1][auxiliar];
		armazem[1]=EOS;
		hexa =(unsigned) strtoul (armazem,&validacao,BASE);
		if (*validacao!=EOS)
		{		
			printf ("\no caracter %c nao eh valido\n\n",*validacao);
			exit(caracterInvalido);
		}
		buffer[auxiliar/2]=(hexa<<4)&0xF0;
		armazem[0]=argv[1][++auxiliar];
		armazem[1]=EOS;
		hexa =(unsigned) strtoul (armazem,&validacao,BASE);
		if (*validacao!=EOS)
		{
			printf ("\no caracter %c nao eh valido\n\n",*validacao);
			exit(caracterInvalido);
		}
		buffer[auxiliar/2]=((hexa&0x0F)|buffer[auxiliar/2]);
	}

	validador=CodificarBase64 (buffer, (unsigned) auxiliar/2, codificado);
	if (validador!=ok)
	{
		printf("\nErro(%i): ",validador);
	
		switch (validador)
		{
			case entradaNull :
				printf ("A entrada \"%s\" eh nula.\n\n",argv[1]);
			break;
			
			case saidaNull:
				printf ("A saida eh nula.\n\n");
			break;
			default :
				printf ("desconhecido\n\n");
		}
	}
	buffer[indice]=EOS;
	
	printf ("\nCodificado com Sucesso");
	printf ("\n\nPara a Entrada: %s\na resposta e: %s\n\n",buffer, codificado);
 	free (buffer);
	free (codificado);
	return ok;
}
