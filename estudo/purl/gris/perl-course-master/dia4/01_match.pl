#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $teste = 'curso de Perl';

if ($teste =~ m/Curso/) {
    say 'Tem a palavra Curso!';
} else {
    say 'Não tem a palavra Curso!';
}