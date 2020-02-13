#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $baixo = 'Wyman';

my %stones = (
    'voz' => 'Jagger',
    'guitarra' => 'Richards',
    'baixo' => $baixo,
);

foreach my $key (keys %stones) {
    say "$key: $stones{$key}"
}
