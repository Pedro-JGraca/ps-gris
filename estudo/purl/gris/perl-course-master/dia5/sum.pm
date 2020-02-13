#!/usr/bin/env perl

use 5.18.2;
use warnings;

sub sum {
    my @parametros = @_;
    my $soma = 0;
    map { $soma += $_ } @parametros;
    return $soma;
}

sub sum_struct {
    my @parametros = @_;
    my $result = {};

    foreach my $elemento (@parametros) {
        if ($elemento % 2 == 0) {
            push @{ $result->{'par'} }, $elemento;
        } else {
            push @{ $result->{'impar'} }, $elemento;
        }
    }
    return $result;
}

sub sum_count {
    my @parametros = @_;
    my $result = {};

    foreach my $elemento (@parametros) {
        if ($elemento % 2 == 0) {
            $result->{'par'}++;
        } else {
            $result->{'impar'}++;
        }
    }
    return $result;
}

1;