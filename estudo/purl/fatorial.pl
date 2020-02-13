#!/usr/bin/env perl

use 5.18.2;
use warnings;

print "\ndiga seu numero:";
my $resp= <STDIN>;
chomp $resp;

print "\n o exponencial e:";
print fatorial($resp);
print "\n\n";

sub fatorial 
{
	my $indice= int 0;
	my $number=shift;
	$number = int $number;
	my $auxiliar=$number-1;
	while ($auxiliar!=1)
	{
		$number=$number*$auxiliar--;
	}
	return $number;
}
