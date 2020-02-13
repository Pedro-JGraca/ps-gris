#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;

my @numero = qw(um dois tres);

$numero[9] = 42;

print Dumper(@numero);

print scalar @numero;
print "\n";