/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo do Fris
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Arquivo cabecalho da funcao que pegua duas entradas e tira o XOR bita a bit delas.
 *
 */

#define EOS											'\0'

#define HEXADECIMAL 						"0123456789abcdef"
#define BASE										16

#define NUMERO_ARGUMENTOS				3


typedef unsigned char byte;

typedef enum {
ok,
entradaNull,
entrada1Null,
entrada2Null,
saidaNull,
bytesNull,
caracterInvalido,
entradaNaoHexa,
numeroArgumentosInvalido,
stringDiferente
} tipoErros;

tipoErros
Xozador (byte *entrada1, byte *entrada2, byte *saida, unsigned tamanho);


tipoErros
Verificador(char entrada); /*verifica se o numero de entrada contem caracteres em hexadecimal*/
