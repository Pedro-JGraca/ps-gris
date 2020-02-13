#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @outros_numeros =  ('quatro', 'cinco');

my @numeros = ('um', 'dois', \@outros_numeros, 'tres');

say "Em números: @numeros";
say Dumper(\@numeros);

# Alterando os elementos em @outros_numeros através do @numeros usando a referência
push @{ $numeros[2] }, 'seis';

say "Em números: @numeros";
say Dumper(\@numeros);

say "Em @outros_numeros: @outros_numeros";
say Dumper(\@outros_numeros);