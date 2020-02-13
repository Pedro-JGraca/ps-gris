#!/usr/bin/env perl

use strict;
use warnings;

my $saida = qx{ls -l};
print "SAIDA: $saida\n";