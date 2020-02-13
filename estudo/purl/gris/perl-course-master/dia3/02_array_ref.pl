#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @outros_numeros =  ('quatro', 'cinco');

my @numeros = ('um', 'dois', \@outros_numeros, 'tres');

say "Em números: @numeros";
say Dumper(\@numeros);

# Alterando os elementos em @outros_numeros
push @outros_numeros, 'seis';

say "Em números: @numeros";
say Dumper(\@numeros);