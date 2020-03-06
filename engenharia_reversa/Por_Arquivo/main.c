/*
 * Universidade Federal do Rio de Janeiro
 * Processo seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Main do programa que recupera arquivos encriptografados pelo LEO
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descripto.h"

#define NUMERO_ARGUMENTOS										2	
#define COMPRIMENTO_BUFFER									512


int
main (int argc, char **argv)
{
	unsigned char buffer[2], key;
	unsigned indice;
	char *destino;
	tipoErros validador;
	FILE *arquivo, *escrevendo;
	size_t lidos;

	if (argc != NUMERO_ARGUMENTOS )
	{
		printf("\nUSO: %s <arquivo-encriptado>\n\n",argv[0]);
		printfErro (numero_invalido_argumentos);
		exit(numero_invalido_argumentos);
	}

	validador = achadorKEY (&key);
	if (validador!=ok)
	{
		printfErro (validador);
		exit (validador);
	}

	printf ("\nKEY:%u\n", key);
	
	
	arquivo = fopen (argv[1], "r");
	if (arquivo==NULL)
	{
		printfErro (arquivoNULL);
		exit (arquivoNULL);
	}
	destino = malloc (sizeof(char *)*600);

	for (indice=0;((argv[1][indice]!='.')||(argv[1][indice+1]!='l'));indice++)
        destino[indice]=argv[1][indice];	
	
	printf ("\n\nCriptografado: %s\nDescriptografado: %s\n\n", argv[1], destino);
	escrevendo = fopen(destino,"w");
	if (escrevendo==NULL)
	{
		printfErro(escrevendoNULL);
		exit(escrevendoNULL);
	}

	while ((lidos = fread (buffer, 1, 1, arquivo)))
	{
		buffer[0]-=key;
		fwrite (buffer,1,lidos,escrevendo);
	}
	
	fclose (escrevendo);
	
	fclose (arquivo);
	
	return ok;
}

void
printfErro (tipoErros validador)
{
	switch (validador)
	{
		case ok :
			printf ("\n\nErro(%u): NAO DEVERIA APARECER, MAS PARECE QUE TA TUDO CERTO\n\n", ok);
		break;

		case numero_invalido_argumentos :
			printf ("\n\nERRO(%u): Numero invalido de argumentos\n\n", numero_invalido_argumentos);
		break;

		case nao_consegue_abrir_key :
			printf ("\n\nERRO(%u): nao consegue abrir o arquivo key\n\n",  nao_consegue_abrir_key);
		break;

		case key_sem_conteudo:
			printf ("\n\nERRO(%u): o arquivo key esta corrompido\n\n", key_sem_conteudo);
		break;

		case arquivoNULL :
			printf ("\n\nErro(%u): Nao conseguue abrir o arquivo passado\n\n", arquivoNULL);
		break;
		
		case escrevendoNULL :
			printf ("\n\nErro(%u): Nao consegue escrever\n\n", escrevendoNULL);
		break;

		default :
			printf ("\n\nERRO(%u): DESCONHECIDO\n\n",validador);
	}
}
