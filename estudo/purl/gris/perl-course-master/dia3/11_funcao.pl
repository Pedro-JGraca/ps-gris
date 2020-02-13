#!/usr/bin/env perl

use 5.18.2;
use warnings;

sub minha_funcao {
    return 42;
}

my $valor = minha_funcao();

say $valor;