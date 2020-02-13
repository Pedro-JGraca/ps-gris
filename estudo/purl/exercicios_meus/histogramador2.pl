#!/usr/bin/env perl

#professor

use 5.18.2;
use warnings;
use autodie;
use Data::Dumper;

my %dicionario;

open my $fh, '<', 'numeros';

while (my $numero = <$fh>) {
    chomp $numero;

    $dicionario{$numero} += 1;
}

close $fh;

while (1) 
{
    print "Qual numero você quer?\n";
    my $resposta = <STDIN>;
    chomp $resposta;

    if ( exists $dicionario{ $resposta } ) {
        say $dicionario{ $resposta };
    } else {
        say "0";
    }    
}
