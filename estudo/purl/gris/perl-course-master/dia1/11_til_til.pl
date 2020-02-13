#!/usr/bin/env perl

use strict;
use warnings;

my $float = 100.0;
my $int = 100;
my $virgula = 100,00;
my $string = "100";

if (100 ~~ $float) {
    print "igual ao float\n";
}
if (100 ~~ $int) {
    print "igual ao int\n";
}
if (100 ~~ $virgula) {
    print "igual ao virgula\n";
}
if (100 ~~ $string) {
    print "igual ao string\n";
}