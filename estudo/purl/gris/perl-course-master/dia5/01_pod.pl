#!/usr/bin/env perl

use 5.18.2;
use warnings;

=pod
 
=head1 DESCRIPTION
 
This script can have 2 parameters. The name or address of a machine
and a command. It will execute the command on the given machine and
print the output to the screen.
 
=cut

if (scalar @ARGV < 2) {
    say 'Você deve passar ao menos 2 parâmetros. Veja perldoc 01_pod.pl!'
}

say 'Você acertou o número de parâmetros do script!';