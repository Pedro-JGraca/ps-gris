#!/usr/bin/env perl

use 5.18.2;
use warnings;

my @numeros = qw(2 40 10 1);

say "Array antes: @numeros";
# Insere um elemento na posição 2 do array
splice @numeros, 2, 0, 22;

say "Array depois: @numeros";

# Splice removendo os dois elementos do meio
my @elementos_removidos = splice @numeros, 2, 2;

say "Array depois da remoção: @numeros";
say "Elementos removidos: @elementos_removidos";