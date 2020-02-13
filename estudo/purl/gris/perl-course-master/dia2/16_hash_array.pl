#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @others_stones = qw(baixo Wyman bateria Watts);

my %stones = (
    'voz' => 'Jagger',
    'guitarra' => 'Richards',
   @others_stones,
);

print Dumper(\%stones);
