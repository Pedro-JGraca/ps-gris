#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $teste = 'Curso de Perl';

if ($teste =~ /Curso/) {
    say 'Tem a palavra Curso!';
} else {
    say 'Não tem a palavra Curso!';
}