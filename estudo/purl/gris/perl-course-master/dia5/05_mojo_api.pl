use Mojolicious::Lite;

get '/:param' => sub {
    my $c = shift;
    my $param = $c->param('param');
    $c->render(text => "Hello from $param.");
};

app->config(hypnotoad => {
        listen => [ 
                    'http://*:8888',
                    ],
});

app->start;
