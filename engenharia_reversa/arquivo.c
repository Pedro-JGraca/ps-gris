/*
 * Universidade Federal do Rio de Janeiro
 * Processo seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Conjunto de funcoes que trabalham com manipulacao de arquivos para o programa de descriptografa TAG do LEO
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descripto.h"

tipoErros
VerificaPasta (char *pasta)
{
	int retorno;
	char letra[2];
	char *command;
	FILE *ler;
	retorno=strlen(pasta);
	retorno +=100*sizeof(char *);
	command =  malloc (retorno);
	sprintf(command, "ls %s 1>>lixo.txt 2>>lixo.txt\necho $? 1>>ler.txt 2>>ler.txt", pasta);
	system(command);
	system("rm lixo.txt");
	/*ler arquivo ler.txt*/

	free (command);
	ler= fopen ("ler.txt", "r");
	if (ler==NULL)
		return ler_quebrado;
	
	if (fgets(letra,2,ler)==NULL)
		return sem_saida_ler;
	retorno=atoi(letra);

	if (fclose(ler)!=ok)
		retorno= nao_fechou_ler;
	system("rm ler.txt");
	return retorno;
}

tipoErros
ContadorArquivos (char * pasta, unsigned *qntdArquivos)
{

	FILE *ler;
	char letra [2];
	char *command;
	command =malloc ((strlen(pasta)+200)*sizeof (char *));
	sprintf (command,"ls %s -la|grep -e \"^-\"|wc -l>>ler2.txt",pasta);
	system(command);
	free (command);
	ler= fopen ("ler2.txt", "r");
	if (ler==NULL)
		return ler_quebrado;
	
	if (fgets(letra,2,ler)==NULL)
		return sem_saida_ler;
	*qntdArquivos=atoi(letra);

	if (fclose(ler)!=ok)
		return nao_fechou_ler;

	system("rm ler2.txt");

	return ok;
}

tipoErros
achadorKEY (unsigned char *key)
{
	FILE *ler;
	char letra [2];
	system ("cp /tmp/key ./key ");
	ler = fopen ("key", "r");
	if (ler==NULL)
		return sem_saida_ler;
	
	if (fgets(letra,2,ler)==NULL)
		return sem_saida_ler;
	*key = atoi (letra);
	
	return ok;

}

tipoErros
listadorArquivo (char * pasta)
{
	char *command;
	command = malloc (sizeof(char *)*(strlen(pasta)+40));
	sprintf (command,"ls %s | grep .leo 1>>arquivos.txt", pasta);
	system (command);
	free(command);
	return ok;
}

