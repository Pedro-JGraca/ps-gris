#!/usr/bin/env perl

use strict;
use warnings;

my $linha_numero = 1;

while ( <> ) {
    chomp;
    print "$linha_numero: $_\n";
    $linha_numero++;
}