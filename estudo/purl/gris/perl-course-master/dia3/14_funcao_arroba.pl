#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

sub retorna_o_que_recebe {
    my $valor1 = shift @_;
    my $valor2 = shift @_;

    return ($valor1, $valor2);
}

my @valor = retorna_o_que_recebe('teste', 1);
say Dumper(\@valor);