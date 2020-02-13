#!/usr/bin/env perl

use 5.18.2;
use warnings;

my @numeros = qw(2 40 10 1);

say "Array antes: @numeros";

my @pequenos = grep { $_ < 10 } @numeros;

say "Array com pequenos: @pequenos";