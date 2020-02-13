#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @outros_numeros =  ('quatro', 'cinco');

my @numeros = ('um', 'dois', @outros_numeros, 'tres');

say "Em números: @numeros";
say Dumper(\@numeros);

my @numeros_referenciado = ('um', 'dois', \@outros_numeros, 'tres');
say "Em números referenciados: @numeros_referenciado";
say Dumper(\@numeros_referenciado);
