#!/usr/bin/env perl

use 5.26.1;
use strict;
use warnings;
use autodie;

open my $fh, '<', 'number.txt';
my $indice = int 0;
my $auxiliar= int 0;
my $tamanho= int 0;
my $temporario = int 0;
my @array;
my @ordenado;

print "\n";
while (my $linha = <$fh>) 
{
	chomp $linha;
	$array[$indice]=$linha;
	$indice++;
}

foreach (@array)
{
	$tamanho++;
}

$indice=0;

say foreach (@array);
print "\n-------------\n";
my @salvar = @array;

while($auxiliar!=$tamanho)
{
	$indice=$temporario;
	$ordenado[$auxiliar]=$array[$indice];
	while ($indice<$tamanho)
	{
		if ($ordenado[$auxiliar]>$array[$indice])
		{
			$ordenado[$auxiliar]=$array[$indice];

			$temporario++;
		}
		$indice++;
	}
	$auxiliar++;
}#my @ordenado = sort {$a<=>$b} @array;

say foreach (@ordenado);

close $fh;
