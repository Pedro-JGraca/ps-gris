create database pSgris;
use pSgris;
create table AVALIADORES (
	id											Tinyint(2),
	palestrante							Varchar(50),
	aula										Varchar(20),
	possui_tag 							Bit
);

create table TAG (				
	aula										Varchar(20),
	data_entrega						Decimal 
);

create table AVALIADOS (
	nome										Varchar(50),
	dre											Char(9),
	curso										Varchar(50),
	data_nascimento			  	Decimal,
	periodo									TinyInt(2)
);

create table OUVINTES (
	nome										Varchar(50),
	intituicao_de_origem		Varchar(50),
	ano_nascimento					Decimal
)

