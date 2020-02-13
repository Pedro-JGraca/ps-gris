#!/usr/bin/env perl

use 5.18.2;
use warnings;

my @numeros = qw(2 40 10 1);

print "O maior índice lista antes do shift é $#numeros\n";

my $primeiro = shift @numeros;

print "O primeiro elemento da lista é $primeiro e o maior indice da lista é $#numeros\n";