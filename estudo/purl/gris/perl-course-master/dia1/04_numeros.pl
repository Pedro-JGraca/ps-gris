#!/usr/bin/env perl

use strict;
use warnings;
use Devel::Peek;

my $numero = 42;
Dump($numero);
$numero = "quarenta e dois";
Dump($numero);

my $string = "quarenta e dois";
Dump($string);
$string = 42;
Dump($string);

print "O que diferencia uma string de um inteiro?\n"