#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

sub retorna_o_que_recebe {
    my @parametros = @_;
    return @parametros;
}

my @valor = retorna_o_que_recebe('teste', 1, {'hash' => 'especial'});
say Dumper(\@valor);