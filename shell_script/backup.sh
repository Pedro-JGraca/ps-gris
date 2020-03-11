#!/bin/bash
function VerificaUsuario() {
#	USUARIOS=users
#	echo ${USUARIOS[1]}
	SAIDA=1
}

function EscolhaDoUsuario() {
	declare - i i
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
				echo $line
				#USUARIO[$i]= $line
				i=$[i+1]
			fi
		fi;done
	sudo rm a.txt
	echo $USUARIOS
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
	sudo rm a.txt
	date -I >>a.txt
	for line in $(cat a.txt);do DATA=$line;done
	DATA=${DATA//-/""}
	EscolhaDoUsuario
	echo $DIR
else
	rm a.txt
	echo "esse script precisa ser executado com sudo."
	echo "por favor coloque sudo antes de exexcuta-lo"
fi


