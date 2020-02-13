#!/usr/bin/env perl

use strict;
use warnings;

my $contador = 1;

print "Teste com WHILE:\n";
while ($contador <= 13) {
    print "Reason $contador: " . rand() . "\n";
    $contador++;
}

print "Teste com FOREACH:\n";
foreach my $contador_novo (1..13) {
    print "Reason $contador_novo: " . rand(). "\n";
}

print "Teste com FOR:\n";
for my $contador_novo_2 (1..13) {
    print "Reason $contador_novo_2: " . rand(). "\n";
}