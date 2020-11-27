# simpleBotnet

para compilar basta ir na basta ./src/ e rodar:

$bash ./build.sh 

para rodar:
entre no diretório: "build"
Dentro dele teremos 3 diretórios. Para cada diretorio entre com um terminal diferente.
Primeiro ligue o servidor:
no diretorio server escreva:

$python3 app.py

Depois conecte um cliente:
no diretorio client escreva:

$./client

Por fim entre no diretorio adm (é importante que os outros 2 terminais fiquem lá)

$./botnet

Aqui administraremos os clients (no caso o terminal onde abriu o outro)