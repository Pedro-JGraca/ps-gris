#!/usr/bin/env perl

use strict;
use warnings;
use utf8;
binmode STDOUT, ':utf8';

my $super_string = 'Tá na hora, tá na hora,
tá na hora de brincar
pula pula bole bole';

print scalar reverse $super_string;

my $hello = "dlrow ,olleH";

print scalar reverse $hello;