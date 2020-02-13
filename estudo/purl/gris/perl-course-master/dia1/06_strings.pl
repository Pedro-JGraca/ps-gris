#!/usr/bin/env perl

use strict;
use warnings;

my $sequence = 1;
my $action = 'permit';
my $proto = 'ip';
my $source = '10.10.10.0/24';
my $destination = 'any';

print "$sequence $action $proto $source $destination\n";
$sequence++;

print $sequence . " " . $action . " " . $proto . " " . $source . " " . $destination . "\n";