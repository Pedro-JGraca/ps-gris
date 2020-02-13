#!/usr/bin/env perl

use strict;
use warnings;
use autodie;

open my $fh, '<', 'a_somar.txt';
my $indice = int 1;
my $soma = int 0;

print "\n\tparcelas:\n";
while (my $linha = <$fh>) 
{
	chomp $linha;
	if (!($linha+$linha))
	{
		print "\tseu arquivo contem argumentos invalidos. Por favor apenas numeros\n";
		exit 0;
	}
	print "\t$indice: $linha\n";
	$indice++;
	$soma=$soma+$linha;
}
printf "\n\tsoma e:$soma\n";

close $fh;
