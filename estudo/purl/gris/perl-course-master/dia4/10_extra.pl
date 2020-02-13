#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $match = '(?<achei>UF\w\w)';

open my $fh, '<', '10.txt';

while (my $linha = <$fh>) {
    $linha =~ s/$match/UFRJ/ig;
    print $linha
}

close $fh;