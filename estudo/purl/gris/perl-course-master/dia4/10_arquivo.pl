#!/usr/bin/env perl

use 5.18.2;
use warnings;
use autodie;

open my $fh, '<', '10.txt';

my $contador = 0;

while (my $linha = <$fh>) {

    while ($linha =~ m/(UF\w{2})/ig) {
        $contador++;
        say "$.: $1";
    }
}

say "Foram encontradas $contador ocorrencias!";

close $fh;