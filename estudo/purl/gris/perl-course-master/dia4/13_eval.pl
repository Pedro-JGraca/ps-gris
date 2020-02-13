#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $dividendo = 10;
my $divisor = 0;

eval {
    say $dividendo / $divisor;
};

if ($@) {
    say "erro! $@";
};