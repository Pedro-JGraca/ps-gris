#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Dumper;

my @others_stones = qw(baixo Wyman bateria Watts);

my %stones = (
    'voz' => 'Jagger',
    'guitarra' => 'Richards',
   @others_stones,
);

say "Qual o ano que você quer saber?";
chomp(my $ano = <STDIN>);

if ($ano < 1969) {
    $stones{'guitarra principal'} = 'Jones';
}

if ($ano > 1993) {
    delete $stones{'baixo'};
}

say Dumper(\%stones);