#!/usr/bin/env perl

use 5.18.2;
use warnings;

say for (1..19);

# Condicional, apenas para números pares
for (1..19) {
    say if ($_ % 2 == 0)
}