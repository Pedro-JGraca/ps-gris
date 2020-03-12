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

sudo -n echo senhada 2>>a.txt 1>>a.txt
SUDO=$?
if [ $SUDO -eq 0 ]; then
	#main
	sudo rm a.txt
	date -I >>a.txt
	for line in $(cat a.txt);do DATA=$line;done
	DATA=${DATA//-/""}
	EscolhaDoUsuario
	ls /home/$DIR/BACKUP 1>>a.txt 2>>a.txt
	if [ $? -eq 0 ];then
		sleep 0s
	else
		mkdir /home/$DIR/BACKUP
	fi
	nome=$DIR$DATA
	echo $NOME
	#main
else
	rm a.txt
	echo "esse script precisa ser executado com sudo."
	echo "por favor coloque sudo antes de exexcuta-lo"
fi


