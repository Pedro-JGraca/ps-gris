/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo do Fris
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Arquivo cabecalho da funcao que codifica hexa para base64.
 *
 */

#define EOS											'\0'

#define HEXADECIMAL 						"0123456789abcdef"
#define BASE										16

#define NUMERO_ARGUMENTOS				2
#define CARACTER_QUEBRADOR			'e'

typedef unsigned char byte;

typedef enum {
ok,
entradaNull,
saidaNull,
bytesNull,
caracterInvalido,
entradaNaoHexa,
numeroArgumentosInvalido,
} tipoErros;

tipoErros
Quebrador (byte *entrada, byte *saida, unsigned tamanho);


tipoErros
Verificador(char entrada); /*verifica se o numero de entrada contem caracteres em hexadecimal*/
