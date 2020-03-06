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
achadorKEY (unsigned char *key)
{
	FILE *ler;
	char letra [2];
	system ("cp /tmp/key ./key ");
	ler = fopen ("key", "r");
	if (ler==NULL)
		return nao_consegue_abrir_key;
	
	if (fgets(letra,2,ler)==NULL)
		return key_sem_conteudo;
	*key = (unsigned char) atoi (letra);	
	system ("rm ./key");
	return ok;

}

