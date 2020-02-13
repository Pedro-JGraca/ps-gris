#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Try::Tiny;

my $dividendo = 10;
my $divisor = 0;

try {
    say $dividendo / $divisor;
} catch {
    say "erro: $_";
} finally {
    $divisor = 1;
};
