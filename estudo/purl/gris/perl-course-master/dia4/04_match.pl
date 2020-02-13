#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $string = 'SuperCursoPerl';
my $match = 'curso';

if ($string =~ m/$match/i) {
    say "Tem a palavra $match!";
} else {
    say "Não tem a palavra $match!";
}