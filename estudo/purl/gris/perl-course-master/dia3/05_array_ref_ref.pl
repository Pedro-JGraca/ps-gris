#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @outros_numeros =  ('quatro', 'cinco');

my $numeros_ref = ['um', 'dois', \@outros_numeros, 'tres'];

say ${ ${ $numeros_ref }[2] }[0];

# Como as chaves são opcionais, poderia ficar:
say ${ $$numeros_ref[2] }[0];

# Mas não poderia ficar sem nenhuma pois não daria para saber de onde é a referência.
#   Você pode indicar que é referência usando apenas 2 $'s com a seta '->':
say $$numeros_ref[2]->[0];