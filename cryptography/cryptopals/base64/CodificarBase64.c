/*
 * Universidade Federal do Rio de Janeiro
 * processo seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Codigo fonte das funcoes que codifica hexa para a base64
 *
 */
#include <string.h>
#include "base64.h"

tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida)
{
	if (!entrada)
		return entradaNull;
	if(!saida)
		return saidaNull;

	unsigned indice, auxiliar;
	indice=0;
	auxiliar=0;
	
	for(;numeroBytes>2;numeroBytes-=3) /*faz ate o chegar o ultimo conjunto de seguimentos e o ultimo caso este seja 3*/
	{
		saida[indice]= CONJUNTO_BASE_64[(entrada[auxiliar]>>2)&0x3F];
		saida[indice+1]= CONJUNTO_BASE_64[((entrada[auxiliar]<<4)&0x30)|((entrada[auxiliar+1]>>4)&0x0F)]; 
		saida[indice+2]= CONJUNTO_BASE_64[((entrada[auxiliar+1]<<2)&0x3c)|((entrada[auxiliar+2]>>6)&0x03)];
		saida[indice+3]= CONJUNTO_BASE_64[((entrada[auxiliar+2])&0x3F)];
		indice+=4; 
		auxiliar+=3;
	}

	if (numeroBytes%3==2) /*caso sobre 2 bytes no final*/
	{
		saida[indice] = CONJUNTO_BASE_64[(entrada[auxiliar]>>2)&0x3F];
		saida[indice+1] = CONJUNTO_BASE_64[((entrada[auxiliar]<<4)&0x30)|((entrada[auxiliar+1]>>4)&0x0F)];
		saida[indice+2] = CONJUNTO_BASE_64[(entrada[auxiliar+1]<<2)&0x3C];
		saida[indice+3] = PADDING; 
		indice+=4;
	}

	if (numeroBytes%3==1) /*caso sobre 1 byte no final*/
	{
		saida[indice] = CONJUNTO_BASE_64[(entrada[auxiliar]>>2)&0x3F];
		saida[indice+1] = CONJUNTO_BASE_64[(entrada[auxiliar]<<4)&0x30];
		saida[indice+2] = PADDING;
		saida[indice+3] = PADDING; 
		indice+=4;
	}
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
