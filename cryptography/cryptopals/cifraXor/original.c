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
	byte maior=1;
	byte segredo;

	for (indice=0;indice!=tamanho;indice++)
		saida[indice]=0;

	for (indice=0;indice!=tamanho;indice++)
		for (auxiliar=0;auxiliar!=tamanho;auxiliar++)
			if (auxiliar!=indice)
				if (entrada[indice]==entrada[auxiliar])
					saida[indice]+=1; /*constroi no vetor saida um vetor de bytes indicando o numero de occrencias por byte*/
	
	for (indice=0;indice!=tamanho;indice++)
		if (saida[indice]>maior)
		{
			maior=saida[indice]; /*descobre o maior*/
			auxiliar=indice; /*coloca no auxiliar o indice do maior*/
		}
	/*maior é o e*/
	/*maior xor e = segredo*/
	segredo = entrada[auxiliar]^CARACTER_QUEBRADOR;
	for (indice=0;indice!=tamanho;indice++)
		saida[indice]=segredo^entrada[indice];

	printf ("\nCaracter que mais aparece: %c\tSegredo:%c\tCaracter usador: %c\n",entrada[auxiliar],segredo,CARACTER_QUEBRADOR);

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
