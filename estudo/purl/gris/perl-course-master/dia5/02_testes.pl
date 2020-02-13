#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Test::More;

use Sum;

# Verificações simples

is( sum(1, 1, 3),    5,     '1+1'   );
is( sum(2, 2),    4,     '2+2'   );

is_deeply(
    sum_struct(1,1,1,2),
    {
        'impar' => [1, 1, 1],
	'par' => [2],
    },
    'teste impar'
);

done_testing;
