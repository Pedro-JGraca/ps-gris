#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $time_start = time;

my $fibonacci_old = 1;
my $fibonacci = 1;

foreach (1..100_000_000) {
    $fibonacci_old = $fibonacci;
    $fibonacci = $fibonacci + $fibonacci_old;
}

say "Fibonacci: $fibonacci";

my $time_end = time;
my $interval = $time_end - $time_start;

say "tempo total de execução: $interval";