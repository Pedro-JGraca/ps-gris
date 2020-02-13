#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

sub minha_funcao {
    return (42, 43, 44);
}

my @valor = minha_funcao();
say Dumper(\@valor);


# Exemplo com função retornando referência
sub minha_funcao_ref {
    my $hash_ref = {
        'um' => 1,
        'dois' => 2,
    };

    return (42, $hash_ref);
}

my @valores_com_ref = minha_funcao_ref();
say Dumper(\@valores_com_ref);