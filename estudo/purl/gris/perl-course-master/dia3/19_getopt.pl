#!/usr/bin/env perl

use 5.18.2;
use warnings;
use Getopt::Long;

my $data = "default_file.txt";
my $length = 42;
my $verbose;
GetOptions ("length=i" => \$length,    # numeric
            "file=s"   => \$data,      # string
            "verbose"  => \$verbose)   # flag
or die("Error in command line arguments\n");

say "O tamanho passado foi: $length";
say "O arquivo passado foi: $data";

if ($verbose) {
    say "O modo verbose está ligado!";
}

# Execute o arquivo passando os parâmetros: -f arquivo.txt e/ou -l 10 e/ou -v