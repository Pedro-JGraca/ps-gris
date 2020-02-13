#!/usr/bin/env perl

use strict;
use warnings;

my $saida = system('ls','-l');
print "SAIDA: $saida\n";