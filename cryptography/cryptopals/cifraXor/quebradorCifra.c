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
		saida[indice]=0;
		
	auxiliar=0;
	/*H,N*/
	for (segredo='O';segredo!=177;segredo++)
	{
		auxiliar=0;
		for(indice=0;indice!=tamanho;indice++)
		{
			saida[indice]=entrada[indice]^segredo;
			if ((saida[indice]>=' ')&&(saida[indice]<='~'))
				if (saida[indice]!=95)
					/*é um caracter desejado*/
					auxiliar++;
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
