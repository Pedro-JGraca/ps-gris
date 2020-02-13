#!/usr/bin/env perl

use strict;
use warnings;

my $linha_numero = 1;

while (my $linha = <STDIN>) {
    chomp $linha;
    print "$linha_numero: $linha\n";
    $linha_numero++;
}