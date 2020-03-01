create database pSgris
default character set utf8
default collate utf8_general_ci;

use pSgris;

create table PALESTRANTES 
(
	id_palestrante					Tinyint(2) NOT NULL AUTO_INCREMENT,
	nome										Varchar(50) NOT NULL,
	aula										Varchar(20) NOT NULL,
	avaliador								enum('S','N') NOT NULL default 'N', 
	PRIMARY KEY (id_palestrante)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;


create table TAG 
(
	id_tag									Tinyint(2) NOT NULL AUTO_INCREMENT,
	aula										Varchar(20) NOT NULL,
	data_entrega						Date  NOT NULL,
	CONSTRAINT fk_id_palestrante FOREIGN KEY (id_palestrante) REFERENCES PALESTRANTES (id_palestrante)
	PRIMARY KEY (id_tag)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;

create table AVALIADOS 
(
	dre											Char(9) NOT NULL,
	nome										Varchar(50) NOT NULL,
	curso										Varchar(50) NOT NULL,
	data_nascimento			  	Date NOT NULL,
	periodo									TinyInt(2) NOT NULL,
	PRIMARY KEY (dre)
)
ENGINE=innoDB
DEFAULT CHARSET = utf8;

create table NOTAS 
(
	id_notas								Tinyint(3) NOT NULL AUTO_INCREMENT,
	CONSTRAINT fk_dre_avaliados FOREIGN KEY (dre) REFERENCES AVALIADOS (dre)
	CONSTRAINT fk_id_tag FOREIGN KEY (id_tag) REFERENCES TAG (id_tag)
	notas										Decimal(3,2) NOT NULL,
	PRIMARY KEY (id_notas)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;

create table OUVINTES 
(
	id_ouvinte							Tinyint(2) NOT NULL AUTO_INCREMENT,
	nome										Varchar(50) NOT NULL,
	intituicao_de_origem		Varchar(50),
	ano_nascimento					Date NOT NULL,
	PRIMARY KEY (id_ouvinte)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;
