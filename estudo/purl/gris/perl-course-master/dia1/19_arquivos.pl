#!/usr/bin/env perl

use strict;
use warnings;

open my $fd, '>', 'arquivo.txt';

print $fd 'Alo Mundo';

close $fd;