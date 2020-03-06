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
	unsigned char buffer [COMPRIMENTO_BUFFER], key;
	unsigned qntdArquivos, auxiliar, indice;
	char *command,*linha, *origem, *destino, *movendo;
	tipoErros validador;
	FILE *arquivo, *aberto, *escrevendo;
	size_t lidos;

	if (argc != NUMERO_ARGUMENTOS )
	{
		printf("\nUSO: %s <PASTA-ARQUVISO-ENCRIPTADOS>\n\n",argv[0]);
		printfErro (numero_invalido_argumentos);
		exit(numero_invalido_argumentos);
	}

	validador = VerificaPasta(argv[1]);
	if (validador!=ok)
	{
		printfErro (validador);
		exit (validador);
	}
	
	qntdArquivos=0;
	validador = ContadorArquivos (argv[1], &qntdArquivos);
	if (validador!=ok)
	{
		printfErro (validador);
		exit (validador);
	}

	command = malloc (sizeof(char*)*(strlen(argv[1])+30));
	if (argv[1][strlen(argv[1])-1]=='/')
		argv[1][strlen(argv[1])-1]=EOS;	
	sprintf(command,"mkdir ./%s_RESOLVIDO", argv[1]);
	printf("\n%s\n",command);
	system(command);
	sprintf(command,"./%s_RESOLVIDO", argv[1]);
	/*argv[1] tem o nome da pasta onde estah os arquivos encriptografados e command tem aonde eu quero botar depois de desincriptografar*/
	validador = achadorKEY (&key);
	if (validador!=ok)
	{
		printfErro (validador);
		exit (validador);
	}

	printf ("\nKEY:%u\n", key);
	
	validador = listadorArquivo(argv[1]);
	if (validador!=ok)
	{
		printfErro (validador);
		exit (validador);
	}
	linha = malloc (sizeof(char *)*TAMANHO_MAXIMO_LINHA);
	arquivo = fopen ("arquivos.txt", "r");
	if (arquivo==NULL)
	{
		printfErro (arquivoNULL);
		exit (arquivoNULL);
	}
	origem = malloc (sizeof(char *)*600);
	destino = malloc (sizeof(char *)*600);
	movendo = malloc (sizeof(char *)*600);

	sprintf (origem,"cp %s/*.leo ./",argv[1]);
	system (origem);

	while ((fgets(linha,TAMANHO_MAXIMO_LINHA,arquivo))!=NULL)
	{
		strcpy (origem,linha);
		for (indice=0;((origem[indice]!='.')||(origem[indice+1]!='l'));indice++)
			destino[indice]=origem[indice];

		printf ("\n\nOrigem: %s\nDestino: %s\n\n", origem, destino);
		aberto = fopen (origem, "r");
		if (aberto==NULL)
		{
			printf ("\nnao abriu %s\n", origem);
			printfErro (arquivoNULL);
			exit (arquivoNULL);
		}

		escrevendo = fopen(destino,"w");
		while ((lidos = fread (buffer, COMPRIMENTO_BUFFER, 1, aberto)))
		{
			for (auxiliar=0;auxiliar!=COMPRIMENTO_BUFFER;auxiliar++)
				buffer[auxiliar]-=key;
			fwrite (buffer,COMPRIMENTO_BUFFER,lidos,escrevendo);
		}
		sprintf(H,"mv %s %s", destino,command);
		system (movendo);
		fclose (aberto);
		fclose (escrevendo);
	}
	fclose (arquivo);

	free (linha);
	
	system ("rm *.leo");
	system ("rm arquivos.txt");
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

		case nao_achou_arquivo :
			printf ("\n\nERRO(%u): Arquivo Nao Achado\n\n", nao_achou_arquivo);
		break;
		
		case ler_quebrado :
			printf ("\n\nERRO(%u): Comando echo $? nao conseguiu gerar arquivo ler.txto\n\n", ler_quebrado);
		break;

		case sem_saida_ler :
			printf ("\n\nERRO(%u): Comando echo $? nao conseguiu ver informacao no ler.txto\n\n", sem_saida_ler);
		break;

		case nao_fechou_ler :
			printf ("\n\nERRO(%u): Comando fclosen nao conseguiu fechar arquivo ler.txto\n\n", nao_fechou_ler);
		break;

		case arquivoNULL :
			printf ("\n\nErro(%u): Nao conseguue abrir o arquivos.txt\n\n", arquivoNULL);
		break;

		default :
			printf ("\n\nERRO(%u): DESCONHECIDO\n\n",validador);
	}
}
