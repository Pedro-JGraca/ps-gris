package modulo::print;

use 5.18.2;
use warnings;
use parent 'Exporter';
our @EXPORT = qw(minha_funcao);

sub minha_funcao {
    say $_[0];
}

1;