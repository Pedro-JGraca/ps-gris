#!/usr/bin/env perl
use Mojolicious::Lite;
use Mojo::mysql;

# docker run --name mojo-mysql -e MYSQL_ROOT_PASSWORD=secret -d mysql:5.7
helper mysql => sub { state $mysql = Mojo::mysql->strict_mode('mysql://root:s3cret@localhost/db') };
 
get '/' => sub {
  my $c  = shift;
  my $db = $c->mysql->db;
  $c->render(json => $db->query('select now() as time')->hash);
};

app->start;