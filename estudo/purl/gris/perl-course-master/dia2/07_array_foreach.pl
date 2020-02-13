#!/usr/bin/env perl

use 5.18.2;
use warnings;

my @numeros = qw(um dois tres);

$numeros[9] = 42;

foreach my $i (1..@numeros) {
    say $numeros[$i - 1];
}