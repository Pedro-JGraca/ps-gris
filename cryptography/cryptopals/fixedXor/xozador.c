/*
 * Universidade Federal do Rio de Janeiro
 * processo seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Codigo fonte das funcao que executa xor bit a bit de duas entradas que recebe
 *
 */
#include <string.h>
#include "fixedXor.h"

tipoErros
Xozador (byte *entrada1,byte *entrada2, byte *saida, unsigned tamanho)
{
	if (!entrada1)
		return entrada1Null;
	if (!entrada2)
		return entrada2Null;
	if(!saida)
		return saidaNull;

	unsigned indice;
	
	for(indice=0;indice<tamanho;indice++) 
		saida[indice]=entrada1[indice]^entrada2[indice];

	saida[indice]=EOS;
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
