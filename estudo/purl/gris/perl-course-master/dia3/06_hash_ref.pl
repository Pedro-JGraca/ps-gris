#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $extenso = {
    'um' => 1,
    'dois' => 2,
    'tres' => 3,
};

# Execute algumas vezes e verifique que a ordem das chaves não é garantida.
foreach my $chave (keys %{$extenso}) {
    say "$chave: $extenso->{$chave}";
}