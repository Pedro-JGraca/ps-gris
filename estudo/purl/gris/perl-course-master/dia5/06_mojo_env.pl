#!/usr/bin/env perl
use Mojolicious::Lite;

get '/:param' => sub {
    my $c = shift;
    my $param = $c->param('param');

    my $shell = $ENV{SHELL};
    $c->render(text => "Hello from $param at $shell.");
};

app->start;