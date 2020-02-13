#!/usr/bin/env perl

use 5.26.1;
use strict;
use warnings;
use autodie;

open my $fh, '<', 'number.txt';
my $indice = int 0;
my $auxiliar= int 0;
my $tamanho= int 0;
my @array= <$fh>;
my %ash;

foreach (@array) 
{
	$tamanho++;
}
print "\n\no tamanho do arquivo e $tamanho\n";
while ($indice!=$tamanho) 
{
	$auxiliar=0;
	while ($indice+$auxiliar!=$tamanho)
	{
		if ($array[$indice]==$array[$indice+$auxiliar])
		{
			$ash{$array[$indice]}++;
		}
		$auxiliar++;
	}
	$indice++;
}

print "\n";
	print "Qual numero vc quer?";

while(my $var = <STDIN>)
{
	chomp $var;
	print "\nA ocorrencia de $var e :$ash{$var}\n\n";
}

close $fh;
