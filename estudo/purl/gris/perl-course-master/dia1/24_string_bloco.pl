#!/usr/bin/env perl

use strict;
use warnings;

my $name = 'OCaml';

print <<"EOHEADER";
Perl has a form of garbage collection,
but it uses a simple scheme called re-
ference counting. Simply put, each Perl
object keeps a count of the number of
other objects pointing (referencing)
itself. When the count falls to zero,
nothing is pointing at this object, and
so the object can be freed.
Author $name.
EOHEADER