#!/usr/bin/env perl

use strict;
use warnings;
use autodie;
use English qw( -no_match_vars );

open my $fh, '<', 'xuxa.txt';

while (<$fh>) {
    chomp $ARG;
    print "$NR: $ARG\n";
}

close $fh;