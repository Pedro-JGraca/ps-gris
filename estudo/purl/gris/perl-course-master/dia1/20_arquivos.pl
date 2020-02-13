#!/usr/bin/env perl

use strict;
use warnings;
use autodie;

open my $fh, '<', 'xuxa.txt';

while (my $linha = <$fh>) {
    chomp $linha;
    print "$.: $linha\n";
}

close $fh;