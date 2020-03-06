create database pSgrisWeb2
default character set utf8
default collate utf8_general_ci;

use pSgrisWeb2;

create table Usuarios
(
	id_usuarios							Tinyint(2) NOT NULL AUTO_INCREMENT,
	nome										Varchar(50) NOT NULL,
	nascimento							Date,
	sexo										enum('F','M','O') DEFAULT 'O',
	hash_senha							Varchar(128) NOT NULL,
	PRIMARY KEY (id_usuarios)
)
ENGINE=innoDB
AUTO_INCREMENT=1
DEFAULT CHARSET = utf8;


insert into Usuarios
(nome,hash_senha)
values
('root','00000');

insert into Usuarios
(nome,nascimento,sexo,hash_senha)
values
('pedro','1996-08-26', 'M','00000');

