/*
 * Universidade Federal do Rio de Janeiro
 * Processo Seletivo GRIS
 * Autor: Pedro Jullian Medina Torres Graca
 * Descricao: Arquivo cabecalho do programa que descriptografa o LEO
 *
 */


#define EOS                  		'\0'
#define TAMANHO_MAXIMO_LINHA		200

typedef enum {
	ok,
	numero_invalido_argumentos,
	nao_achou_arquivo,
	ler_quebrado,
	sem_saida_ler,
	nao_fechou_ler,
	arquivoNULL
}tipoErros;


tipoErros
VerificaPasta (char *pasta);

tipoErros
ContadorArquivos (char * pasta, unsigned *qntdArquivos);

void
printfErro(tipoErros validador);

tipoErros 
achadorKEY (unsigned char *key);

tipoErros
listadorArquivo (char * pasta);
