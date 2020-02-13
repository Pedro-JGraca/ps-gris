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

	unsigned indice,auxiliar;
	byte segredo;

	for (indice=0;indice!=tamanho;indice++)
		saida[indice]=0;
	
	for (segredo=0;auxiliar!=indice;segredo++)
	{
		for(indice=0;(indice!=tamanho);indice++)
		{
			saida[indice]=entrada[indice]^segredo;
			if ((saida[indice]>=' ')&&(saida[indice]<='~'))
			{
				if (saida[indice]!=95)
				{
					/*é um caracter desejado*/
					auxiliar++;
				}
			}
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
