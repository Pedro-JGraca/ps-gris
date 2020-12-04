# simpleBotnet

1. Sobre o programa
    Esse é um simples projeto de uma botnet. A ideia é usa-la para fins acadêmicos (estudo).
    Podemos ver o arquivo simpleBotnet.jpg. Basicamente é uma imagem que descreve o sistema.

2. Sobre a estrutura de arquivos geral desse diretório

    Como podemos ver existem 3 diretorios principais:
        1. src
        2. build
        3. exec

        Na src temos o código fonte.

        Na build temos apenas a estrutura de 3 diretórios com nenhum arquivo dentro. Esses diretorios são:
            client
            server
            admin
            
        Todos eles estão vazios.

        Na exec temos a mesma estrutura de arquivos, só que dessa vês nós temos arquivos dentro.

        A ideia é que a build é o local de produção, se vc der git clone e mandar compilar, é nela que irá ser construído os arquivos. (Se vc não fizer nenhuma alteração, ficará igual a exec). A exec é para caso vc queria apenas copiar os programas para uso, sem querer compilar. Fique atento as dependências necessárias.

3. Sobre como usar esse programa

    Entre no diretório "exec".
    3.1: Servidor
        No diretorio "server" temos o arquivo "app.py". É um servido em flask. Aonde vc desejar montar primeiro copie esse diretorio para a maquina desejada e execute o seguinte comando: (isso ta em modo de desenvolvimento, não foi feito para um servidor de produção)
        $python3 app.py SENHA PORTA
    
        Esse argumento que eu chamei de "SENHA" logo após ao comando é a senha do servidor. Esse servidor só aceita as requisições de ordem para o cliente se a requisição vier com essa senha.

        O segundo argumento é um numero que vc precisará colocar. Esse numero será a porta usada para a comunicação com o servidor.

    3.2: Administrador
        No diretorio "admin" temos o arquivo "main.py". É ele que vc precisará executar para se comunicar com o servidor. Além disso temos outros dois arquivos que são muito importantes. Um deles é outro python ("front.py") e para a execução vc não deve precisar mexer nele (só leve ele junto com o "main.py" para a maquina de administração). 
        O outro é chamado de "serverLink.txt". Nele vc colocará o endereço do servidor no mesmo formato do exemplo ali.
        
        Por fim, para executar basta:
        $python3 main.py
        
    3.3: Cliente
        No diretorio "client" temos 3 arquivos:
            link.py
            client
            serverLink.txt
        
        O "serverLink.txt" é literalmente o mesmo arquivo e vc irá precisar levar ele para a maquina do cliente. O "link.py" se comporta parecido com o "front.py" e deverá ser levado junto, assim como no administrador. O binário que roda o cliente própriamente dito é o "client". Nele, para vc executar o cliente vc precisa:

        $./client

        O cliente é a vítima, falta criar um "virus.sh" onde ele irá fazer esse programa client rodar junto com a inicialização do sistema.

4. Sobre como compilar
    Para compilar basta executar o comando abaixo no local onde se encontra o arquivo init.sh:
        $bash ./init.sh 
    
    Ficará tudo dentro da pasta build. Para o uso será igual a que foi descrito no ponto 3.

obs:
    O arquivo foi compilado num linux 64bits. Se precisar de mais informação, entre em contato.
