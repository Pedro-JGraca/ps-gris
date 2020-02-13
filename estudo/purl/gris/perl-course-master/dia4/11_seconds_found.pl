#!/usr/bin/env perl

use 5.18.2;
use warnings;

my $match = '(?<hour>[0-2][0-4]):(?<minute>[0-5][0-9])';
my $secondsInHour = 0;
my $secondsInMinutes = 0;

open my $fh, '<', '11.txt';

while (my $linha = <$fh>) {
    while ($linha =~ m/(?<hour>[0-2][0-9]):(?<minute>[0-5][0-9])/ig) {
        $secondsInHour=  $+{hour}*60*60;
        $secondsInMinutes = $+{minute}*60;
    }    
}

my $total = $secondsInHour + $secondsInMinutes;

say "Found the total size of seconds: " . $total;

close $fh;