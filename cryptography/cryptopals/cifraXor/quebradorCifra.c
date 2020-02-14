/*
 * Universidade Federal do Rio de Janeiro
 * processo seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Codigo fonte das funcao que quebra a cifra XOR
 *
 */
#include <stdio.h>

#include <string.h>
#include "cifraXor.h"

tipoErros
Quebrador (byte *entrada, byte *saida, unsigned tamanho)
{
	if (!entrada)
		return entradaNull;
	if(!saida)
		return saidaNull;

	unsigned indice,auxiliar,temporario;
	byte segredo;

	for (indice=0;indice!=tamanho;indice++)
		saida[indice]=0; /*preenche em zero a saida*/
		
	auxiliar=0;
	
	for (segredo=0;segredo!=255;segredo++)
	{
		auxiliar=0;
		for(indice=0;indice!=tamanho;indice++)
		{
			saida[indice]=entrada[indice]^segredo;
			if (((saida[indice]>='A')&&(saida[indice]<='z'))||(((saida[indice]==' ')||(saida[indice]=='\'')))) 
			{
				if (saida[indice]!=95)
					/*nao é um caracter desejado*/
					auxiliar++;
			}
			else
				indice=tamanho-1;
		
		}
		if (auxiliar==indice)
		{
			printf ("\nPara o Segredo:%c\t",segredo);
			printf ("Saida:");
			for (temporario=0;temporario!=indice;temporario++)
				printf("%c",saida[temporario]);
			printf ("\n");
		}
	}

	return ok;
}

tipoErros
Verificador(char entrada)
{
	if(!entrada)
		return entradaNull;
	
	unsigned indice=0;
	unsigned tamanho= (unsigned) strlen(HEXADECIMAL);
	
	for (;entrada!=HEXADECIMAL[indice];indice++)
		if(indice==tamanho)
			return entradaNaoHexa;
	
	return ok;
}
