#!/usr/bin/env perl

use 5.18.2;
use warnings;

my @nomes = qw(igoo tundro zok);

my @filtrados = map {ucfirst} @nomes;

say "Array filtrado: @filtrados";