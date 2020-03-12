#!/bin/bash
function VerificaUsuario() {
	a=0
	TEM=0
	while [ $a != $i ]; do
		if [ $DIR == ${USUARIO[$a]} ];then
			TEM=1
			a=$[a+1]
		else
			a=$[a+1]
		fi
	done
	if [ $TEM -eq 1 ]; then
		SAIDA=0 #o o usuario exite
	else
		SAIDA=1 #1 usuario nao existe
	fi
}

function EscolhaDoUsuario() {
	declare -i i
	declare -A USUARIO
	i=0
	SAIDA=1
	P="P"
	while [ $SAIDA -eq 1 ]; do
		clear
		echo "escolha um dos usuarios abaixo para fazer o backup" 
		echo ""
		sudo passwd -Sa | grep " P " >> a.txt
		for line in $(cat a.txt);do 
			if [[ ${line} =~ ^([0-9,/,-]+)$ ]];then
				sleep 0s
			else
				if [ "$line" == "$P" ]; then
					sleep 0s
				else
					if [ "$line" == "root" ]; then
						sleep 0s
					else
						USUARIO[$i]=$line
						echo ${USUARIO[$i]}
						i=$[i+1]
					fi
				fi
			fi;done
		sudo rm a.txt
		echo ""
		echo "Qual voce escolhe"
		read DIR
		VerificaUsuario
		if [ $SAIDA -eq 1 ]; then
			echo "esse usuario nao existe. Por favor escolha outro."
			echo ""
			sleep 2s
		else
			echo "usuario $DIR escolhido" 
		fi
	done
}

function RemoveDiretorioAntigo() {
	ls /home/$DIR/BACKUP 1>>a.txt
	for line in $(cat a.txt);do 
	numero=${line//$DIR/""}
	numero=${numero//.*/""}
	APAGAR=$[DATA-3]
	#tag
	if [ $numero -lt $APAGAR ]; then 
		sudo rm /home/$DIR/BACKUP/$line
	else
		sleep 0s
	fi;done
	sudo rm a.txt
}

function VerificaSeExiste () {
	ls 1>>a.txt
	EXISTE=0
	for line in $(cat a.txt);do 
	echo $line $2
	if [ "$line" == "$2" ]; then
		EXISTE=1
	fi;done
	rm a.txt
}

#main
sudo -n echo senhada 2>>a.txt 1>>a.txt
SUDO=$?
if [ $SUDO -eq 0 ]; then
	sudo rm a.txt
	date -I >>a.txt
	for line in $(cat a.txt);do DATA=$line;done
	DATA=${DATA//-/""} #tira os -
	EscolhaDoUsuario
	
	ls /home/$DIR/BACKUP 1>>a.txt 2>>a.txt
	if [ $? -eq 0 ];then
		sleep 0s #zuera para nao fazer nada
	else
		mkdir /home/$DIR/BACKUP
	fi
	sudo rm a.txt
	
	NOME=$DIR$DATA
	RemoveDiretorioAntigo
	
	if [ $# -ne 0 ]; then
		case $1 in
		"-g")
				echo criando $NOME.tar.gz
				sudo tar -czf $NOME.tar.gz /home/$DIR 2>>a.txt
				sudo mv $NOME.tar.gz /home/$DIR/BACKUP/
				sudo rm a.txt
				echo criado $NOME.tar.gz/;;
		"-e")if [ $# -ne 2 ]; then
					echo voce precisa informar o diretorio
				else
					echo por favor nao use sudo para isso.
				fi;;
		*)echo por favor coloque alguma flag aceitavel;;
		esac
	else #default
		echo criando $NOME.tar.bz2
		sudo tar -cjf $NOME.tar.bz2 /home/$DIR 2>>a.txt
		sudo mv $NOME.tar.bz2 /home/$DIR/BACKUP/
		rm a.txt
		echo criado $NOME.tar.bz2
	fi
else #se nao tem senha
	rm a.txt
	if [ $# -ne 0 ]; then
		case $1 in
		"-g")
				echo "esse script precisa ser executado com sudo."
				echo "por favor coloque sudo antes de exexcuta-lo";;
		"-e")if [ $# -ne 2 ]; then
					echo voce precisa informar o diretorio/arquivo
				else
					mkdir ./BACKUP-ESPECIAL
					VerificaSeExiste
					if [ $EXISTE -eq 1 ]; then
						echo criando $2.tar.bz2
						tar -cjj $2.tar.bz2 $2 2>>a.txt
						mv $2 ./BACKUP-ESPECIAL/
						echo criando $2.tar.bz2
						rm a.txt
					else
						echo nao existe $2 no arquivo
					fi
				fi;;
		"-eg")if [ $# -ne 2 ]; then
					echo voce precisa informar o diretorio/arquivo
				else
					mkdir ./BACKUP-ESPECIAL
					VerificaSeExiste
					if [ $EXISTE -eq 1 ]; then
						echo criando $2.tar.gz
						tar -cfz $2.tar.gz $2 2>>a.txt
						mv $2 ./BACKUP-ESPECIAL/
						echo criado $2.tar.gz
						rm a.txt
					else
						echo nao existe $2 no arquivo	
					fi
				fi;;
		"-ge")if [ $# -ne 2 ]; then
					echo voce precisa informar o diretorio/arquivo
				else
					mkdir ./BACKUP-ESPECIAL
					VerificaSeExiste
					if [ $EXISTE -eq 1 ]; then
						echo criando $2.tar.bz2
						tar -cfz $2.tar.gz $2 2>>a.txt
						mv $2 ./BACKUP-ESPECIAL/
						echo criado $2.tar.gz
						rm a.txt
					else
						echo nao existe $2 no arquivo
					fi
				fi;;
		*)echo por favor coloque alguma flag aceitavel;;
		esac
	else	
		echo "esse script precisa ser executado com sudo."
		echo "por favor coloque sudo antes de exexcuta-lo"
	fi
fi
#exit
#main
