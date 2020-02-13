#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $string = 'UFRJ UFMG UFPR UFSC UERJ UFRRJ';
my $match = 'RJ';

my $contador = 0;

# depende do contexto: nesse como escalar, retorna true se existe match (false se não dá match)
while ($string =~ m/$match/ig) {
    $contador++;
}

say "$match aparece $contador vezes!";
