#!/usr/bin/env perl

use strict;
use warnings;

my $xuxa = 1;
my $sasha = 0;

if ($xuxa && $xuxa) {
    print "AND!\n";
}

if ($xuxa || $sasha) {
    print "OR!\n";
}

if ( not $sasha) {
    print "NOT SASHA!\n";
}

if ( ! $sasha) {
    print "OUTRO NOT SASHA!\n";
}