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

say "Qual instrumento que você quer saber?";
chomp(my $instrumento = <STDIN>);

if (exists $stones{$instrumento}) {
    say $stones{$instrumento};
} else {
    say "Esse instrumento não existe na banda.";
}