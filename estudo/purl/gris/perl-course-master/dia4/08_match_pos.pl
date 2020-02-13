#!/usr/bin/env perl

use 5.18.2;
use warnings;

my @lines = <DATA>;
my $match = 'ai';

my $contador = 0;

# depende do contexto: nesse como escalar, retorna true se existe match (false se não dá match)
foreach my $line (@lines) {
    while ($line =~ m/ai|pego|nossa/g) {
        say "Deu match na posição ". pos($line);
        $contador++;
    }
}

say "$match aparece $contador vezes!";

__DATA__
Nossa, nossa
Assim você me mata
Ai, se eu te pego
Ai, ai se eu te pego
Delícia, delícia
Assim você me mata
Ai, se eu te pego
Ai, ai, se eu te pego
Sábado na balada
A galera começou a dançar
E passou a menina mais linda
Tomei coragem e comecei a falar
Nossa, nossa
Assim você me mata
Ai, se eu te pego
Ai, ai se eu te pego
Delícia, delicia
Assim você me mata
Ai, se eu te pego
Ai, ai, se eu te pego
Sábado na balada
A galera começou a dançar
E passou a menina mais linda
Tomei coragem e comecei a falar
Nossa, nossa
Assim você me mata
Ai, se eu te pego
Ai, ai se eu te pego
Delícia, delicia
Assim você me mata
Ai, se eu te pego
Ai, ai, se eu te pego
Nossa, nossa
Assim você me mata
Ai, se eu te pego
Ai, ai se eu te pego
Delícia, delicia
Assim você me mata
Ai, se eu te pego
Ai, ai, se eu te pego hein