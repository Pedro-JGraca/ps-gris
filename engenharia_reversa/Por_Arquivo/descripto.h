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
	nao_consegue_abrir_key,
	key_sem_conteudo,
	arquivoNULL,
	escrevendoNULL
}tipoErros;

void
printfErro(tipoErros validador);

tipoErros 
achadorKEY (unsigned char *key);

