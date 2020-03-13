Esse é um programa de backup. Em seu modo default ele compacta a home do usuario que voce selecionar e coloca numa pasta que ele cria chamada de BACKUP dentro de /home/.
A compactação default é tar.bz2.
A compactação cria um pacote na seguinte configuração: USUARIO DATA COMPACTACAO.
ficando assim USUARIOyyyymmdd.tar.bz2
Se dentro da pasta existir alguma compactação com um nome que remete mais de 3 dias, ela apaga.

o programa possui 2 possiveis flags
	-g			comprime em tar.gz no lugar de tar.bz2 (uma compactação menor, mas mais rápida de compactar e descompactar)
	-e			modo especial

para rodar o programa no modo Default ele deve usuar sudo.
para rodar o programa no modo especial ele não deve usar sudo.

O modo especial é basicamente um onde o usuario guarda um arquivo ou uma diretorio numa compactação (que se ele só colocar -e fica .tar.bz2 e se colocar -ge ou -eg fica .tar.gz) e coloca no diretorio "BACKUP-ESPECIAL" dentro donde esse progrma é executado


