create database pSgris
default character set utf8
default collate utf8_general_ci;

use pSgris;

create table PALESTRANTES
(
	id_palestrante					Tinyint(2) NOT NULL AUTO_INCREMENT,
	nome										Varchar(50) NOT NULL,
	avaliador								enum('S','N') NOT NULL default 'N', 
	PRIMARY KEY (id_palestrante)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;

create table AULAS
(
	id_aula								int(7) NOT NULL AUTO_INCREMENT,
	nome									Varchar(20) NOT NULL,
	id_palestrante				Tinyint(2) NOT NULL,
	data									Datetime NOT NULL,
	CONSTRAINT fk_id_palestrante FOREIGN KEY (id_palestrante) REFERENCES PALESTRANTES (id_palestrante),
	PRIMARY KEY (id_aula)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;

create table TAG
(
	id_tag											Tinyint(2) NOT NULL AUTO_INCREMENT,
	id_aula_tag									int(7) NOT NULL,
	data_entrega								Date  NOT NULL,
	CONSTRAINT fk_id_aula FOREIGN KEY (id_aula_tag) REFERENCES AULAS (id_aula),
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
	dre_avaliado						Char(9) NOT NULL,
	id_tag									Tinyint(2) NOT NULL,
	entregou								enum('S','N') NOT NULL default 'S',
	nota										Decimal(3,2) NOT NULL,
	CONSTRAINT fk_dre_avaliados FOREIGN KEY (dre_avaliado) REFERENCES AVALIADOS (dre),
	CONSTRAINT fk_id_tag FOREIGN KEY (id_tag) REFERENCES TAG (id_tag),
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

create table FREQUENCIA
(
	id_frequencia						Bigint NOT NULL AUTO_INCREMENT,
	id_aula_frk							int(7) NOT NULL,
	dre_avaliado_frk				Char(9),
	id_ouvinte							Tinyint(2),	
	CONSTRAINT fk_id_ouvinte FOREIGN KEY (id_ouvinte) REFERENCES OUVINTES (id_ouvinte),
	CONSTRAINT fk_id_aula_frk FOREIGN KEY (id_aula_frk) REFERENCES AULAS (id_aula),
	CONSTRAINT fk_dre_avaliado_frk FOREIGN KEY (dre_avaliado_frk) REFERENCES AVALIADOS (dre),
	PRIMARY KEY (id_frequencia)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;
