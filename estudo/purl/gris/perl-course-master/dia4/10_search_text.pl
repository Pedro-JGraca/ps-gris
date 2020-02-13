#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $match = '(?<achei>UF\w\w)';
my $contador = 0;
my $contadorLinha = 0;

open my $fh, '<', '10.txt';

while (my $linha = <$fh>) {
    $contadorLinha++;
    while ($linha =~ m/$match/ig) {
        say "Achei ". $+{achei} . " deu match na posição ". pos($linha). " na linha ".$contadorLinha;
        $contador++;
    }    
}

say "Achei esse tanto de vezes: " . $contador;

close $fh;