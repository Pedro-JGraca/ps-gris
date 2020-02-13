/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: arquivo da funcao teste da funcao que faz xor de duas entradas hexas de tamanho iguais.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#include "fixedXor.h"

int
main (int argc, char **argv)
{
 	byte *buffer1;
	byte *buffer2;
	char armazem[3];
	unsigned indice, validador,auxiliar;
	byte *xor;
	char *validacao;
	byte hexa;
/*inicio de prevencao de erros*/
	if (argc!=NUMERO_ARGUMENTOS)
	{
		printf("\nO numero de argumentos fornecido (%i) é invalido",argc);
		printf("\nUso: %s <string> <string>\n\n", argv[0]);
		exit(numeroArgumentosInvalido);
	}
	
	for(indice=0;indice<strlen(argv[1]);indice++)
		if (Verificador(argv[1][indice])!=0)
		{
			printf("\nCaracter %c na posicao %u Invalido\n\n", argv[1][indice], indice);
			exit(caracterInvalido);
		}
	for(auxiliar=0;auxiliar<strlen(argv[2]);auxiliar++)
		if (Verificador(argv[1][auxiliar])!=0)
		{
			printf("\nCaracter %c na posicao %u Invalido\n\n", argv[2][auxiliar], auxiliar);
			exit(caracterInvalido);
		}
	if (auxiliar!=indice)
	{
		printf ("\nAs strings precisam ser iguais!\n");
		exit(stringDiferente);
	}
/*fim de prevencao de erros*/


/*inicio mallocacao de memoria*/
	buffer1=malloc(sizeof(indice)*indice);
	buffer2=malloc(sizeof(indice)*indice);
	xor=malloc(sizeof(indice)*indice);
/*fim da mallocacao de memoria*/


/*inicio da construcao dos buffers*/
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
		buffer1[auxiliar/2]=(hexa<<4)&0xF0;
		armazem[0]=argv[1][++auxiliar];
		armazem[1]=EOS;
		hexa =(unsigned) strtoul (armazem,&validacao,BASE);
		if (*validacao!=EOS)
		{
			printf ("\no caracter %c nao eh valido\n\n",*validacao);
			exit(caracterInvalido);
		}
		buffer1[auxiliar/2]=((hexa&0x0F)|buffer1[auxiliar/2]);
	}/*terminou o primeiro buffer*/
	for(auxiliar=0;auxiliar<indice;auxiliar++)
	{
		armazem[0]=argv[2][auxiliar];
		armazem[1]=EOS;
		hexa =(unsigned) strtoul (armazem,&validacao,BASE);
		if (*validacao!=EOS)
		{		
			printf ("\no caracter %c nao eh valido\n\n",*validacao);
			exit(caracterInvalido);
		}
		buffer2[auxiliar/2]=(hexa<<4)&0xF0;
		armazem[0]=argv[2][++auxiliar];
		armazem[1]=EOS;
		hexa =(unsigned) strtoul (armazem,&validacao,BASE);
		if (*validacao!=EOS)
		{
			printf ("\no caracter %c nao eh valido\n\n",*validacao);
			exit(caracterInvalido);
		}
		buffer2[auxiliar/2]=((hexa&0x0F)|buffer2[auxiliar/2]);
	}/*terminou o segundo buffer*/
/*fim da construcao dos buffers*/


/*usando a funcao*/	
	validador=Xozador (buffer1, buffer2 , xor, auxiliar/2);
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
	
	printf ("\nFixou Xor com sucesso");
	printf ("\n\nPara a Entrada: %s\ne a Entrada: %s\na resposta e: %s\n\n",buffer1, buffer2, xor);
	printf ("\n\nPara a Entrada: ");
	for (indice=0;buffer1[indice]!=EOS;indice++)
		printf("%x",buffer1[indice]);
	printf ("\t e a Entrada: ");
	for (indice=0;buffer2[indice]!=EOS;indice++)
		printf("%x",buffer2[indice]);
	printf ("\n a saida sera: ");
	for (indice=0;xor[indice]!=EOS;indice++)
		printf("%x",xor[indice]);
	printf ("\n\n");	
	
	free(buffer1);
	free(buffer2);
	free(xor);

	return ok;
}
