#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @numeros = qw(2 40 10 1);

say "Array antes: @numeros";

delete $numeros[1];

say Dumper(@numeros);

say "Array depois: @numeros";