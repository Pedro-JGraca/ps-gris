#!/usr/bin/env perl

use strict;
use warnings;

print "Say my name!\n";
my $name = <STDIN>;
chomp $name;

print "Errou, $name!!! :-("; # Conserte para que fique sem pular linha...