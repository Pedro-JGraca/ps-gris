#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;

my $saida;

# O exec não retorna nada e o programa termina depois dele.
$saida = exec('ls','-l');

print "Valor da variável \$saida:\n";
print Dumper($saida);