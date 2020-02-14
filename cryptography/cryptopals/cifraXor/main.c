/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: arquivo da funcao teste da funcao que decodifica xor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#include "cifraXor.h"

int
main (int argc, char **argv)
{
 	byte *buffer;
 	byte *encoding;
	char armazem[2];
	unsigned indice, auxiliar;
	unsigned tamanho=strlen(argv[1]);
	char *validacao;
	byte hexa;
	tipoErros validador;

/*inicio de prevencao de erros*/
	if (argc!=NUMERO_ARGUMENTOS)
	{
		printf("\nO numero de argumentos fornecido (%i) é invalido",argc);
		printf("\nUso: %s <numero-hexa>\n\n", argv[0]);
		exit(numeroArgumentosInvalido);
	}
	for (indice=0;indice!=tamanho;indice++)
		if (Verificador(argv[1][indice])!=ok)
		{
			printf ("\nErro(%u): caracter \"%c\" na posicao %u eh invalido\n\n",caracterInvalido,argv[1][indice],indice);
			exit(caracterInvalido);
		}
/*fim da verificacao*/
	

/*inicio mallocacao de memoria*/
	buffer=malloc(sizeof(byte)*tamanho);
	encoding=malloc(sizeof(byte)*tamanho);
/*fim da mallocacao de memoria*/

/*correcao do buffer*/
	if (tamanho%2==1) /*impar*/
	{
		printf ("\nTamanho: %u eh impar\n",tamanho);
		argv[1][tamanho]='0';
		argv[1][++tamanho]=EOS;
	}
/*fim da correcao do buffer*/


/*inicio da construcao do buffer*/
	for(auxiliar=0;auxiliar<tamanho;auxiliar++)
	{
		armazem[0]=argv[1][auxiliar];
		armazem[1]=EOS;
		hexa =(byte) strtoul (armazem,&validacao,BASE);
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
/*fim da construcao do buffer*/

	printf ("\nPara Entrada:");
	for (indice =0;indice!=(auxiliar/2);indice++)
		printf("%c", buffer[indice]);
	printf ("\n");

/*usando a funcao*/	
	validador=Quebrador (buffer, encoding, auxiliar/2);
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
	
	printf ("\nQuebrou com sucesso\n");
	
	free(buffer);
	free(encoding);

	return ok;
}
