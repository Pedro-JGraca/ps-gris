#!/usr/bin/env perl

use strict;
use warnings;

# Operador resto possui o sinal do dividendo
# Operador mod possui o sinal do divisor
my $mod = -1 % 3;
print "$mod\n";

my $retest = 1 % -3;
print "$retest\n";