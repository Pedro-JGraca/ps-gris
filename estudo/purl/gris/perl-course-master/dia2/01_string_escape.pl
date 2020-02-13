#!/usr/bin/env perl

use strict;
use warnings;

my $string = 'usando \'aspas\'';
print "$string\n";

my $string_quoted = q{usando 'aspas'};
print "$string_quoted\n";