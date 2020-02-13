#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $frase = 'cachorros e gatorros';

while ($frase =~ m/(?<bicho>gato|cacho)rros/g) {
    say $+{bicho};
}
# if ( $frase =~ m/(?<bicho>gato|cachorro)s/g ) {
#     say $+{bicho};
# }