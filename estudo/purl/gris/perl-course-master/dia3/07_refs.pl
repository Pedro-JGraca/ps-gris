#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my $num_ref = [0, 2, 4, 6, 8];

my $stones_ref = {
    'voz' => 'Jagger',
    'guitarra' => ['Richards', 'Wood'], # Repare na referência para o array
    'bateria' => 'Watts',
};

say 'Tipo de referência para $stones_ref: '. ref($stones_ref);
say 'Tipo de referência para $num_ref: '. ref($num_ref);