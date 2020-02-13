/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo do Fris
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Arquivo cabecalho da funcao que codifica hexa para base64.
 *
 */

#define EOS											'\0'

#define HEXADECIMAL 						"0123456789abcdef"
#define CONJUNTO_BASE_64 				"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define BASE										16

#define PADDING									'='

#define NUMERO_ARGUMENTOS				2


typedef unsigned char byte;

typedef enum {
ok,
entradaNull,
saidaNull,
bytesNull,
caracterInvalido,
entradaNaoHexa,
numeroArgumentosInvalido
} tipoErros;

tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida);


tipoErros
Verificador(char entrada); /*verifica se o numero de entrada contem caracteres em hexadecimal*/
