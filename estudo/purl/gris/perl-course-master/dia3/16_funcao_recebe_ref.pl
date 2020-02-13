#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @pares = (2, 4, 6, 8);
my @impares = (1, 3, 5, 7);

sub minha_funcao {
    my @numeros = @_;
    return @numeros;
}

my @retorno = minha_funcao(\@pares, \@impares);
say Dumper(\@retorno);