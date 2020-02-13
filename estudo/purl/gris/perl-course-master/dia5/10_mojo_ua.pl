
use 5.20.3;
use Mojo::UserAgent;
use Mojo::Util qw(b64_encode);
use Data::Dumper;

my $curl    = Mojo::UserAgent->new;

my $authorization = b64_encode($ENV{USER}.':'.$ENV{PASS}, '');

my $tx_info = $curl->get(
	'https://api.github.com/users/mdjunior/gpg_keys' 
	=> { Authorization => "Basic $authorization"}
);

my $res = $tx_info->result;

if ($res->is_success) {
	my $items =  $tx_info->res->json;
	say Dumper($items);
} else {
	say 'Erro!';
}
