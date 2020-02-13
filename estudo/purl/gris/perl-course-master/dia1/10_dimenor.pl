#!/usr/bin/env perl

use strict;
use warnings;

print "Qual sua idade?\n";
my $idade = <STDIN>;

if ($idade < 18) {
    print "Dimenor!"
    
} elsif ($idade > 60) {
    print "Coroa!"
} else {
    print "Café com leite!"
}

# Encontre o erro