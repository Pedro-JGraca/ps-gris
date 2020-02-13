#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Data::Printer;

my $complicado = [
    {
        'um' => [
            1,
            2,
            [
                3,
                'bla',
                {
                    'resposta' => 42,
                },
            ],
            {
                4 => 5,
                6 => [
                    7,
                    8,
                    9,
                ],
            },
        ],
    },
];

say p($complicado);