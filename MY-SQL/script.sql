create database pSgris
default character set utf8
default collate utf8_general_ci;

use pSgris;

create table AVALIADORES (
	id_palestrante					Tinyint(2) NOT NULL AUTO_INCREMENT,
	palestrante							Varchar(50) NOT NULL,
	aula										Varchar(20) NOT NULL,
	PRIMARY KEY (id_palestrante)
)DEFAULT CHARSET = utf8;

create table TAG (
	id_tag									Tinyint(2) NOT NULL AUTO_INCREMENT,
	aula										Varchar(20) NOT NULL,
	data_entrega						Date  NOT NULL,
	PRIMARY KEY (id_tag)
)DEFAULT CHARSET = utf8;

create table AVALIADOS (
	id_avaliado							Tinyint(3) NOT NULL AUTO_INCREMENT,
	nome										Varchar(50) NOT NULL,
	dre											Char(9) NOT NULL,
	curso										Varchar(50) NOT NULL,
	data_nascimento			  	Date NOT NULL,
	periodo									TinyInt(2) NOT NULL,
	PRIMARY KEY (id_avaliado)
)DEFAULT CHARSET = utf8;

create table OUVINTES (
	id_ouvinte							Tinyint(2) NOT NULL AUTO_INCREMENT,
	nome										Varchar(50) NOT NULL,
	intituicao_de_origem		Varchar(50),
	ano_nascimento					Date NOT NULL,
	PRIMARY KEY (id_ouvinte)
)DEFAULT CHARSET = utf8;
