#!/usr/bin/env perl

use 5.18.2;
use warnings;

sub minha_funcao {
    my $numero = shift;
    say $numero;
    return $numero * 2;
}

my $print = \&minha_funcao;

my $result = $print->(10_100);

say $result;