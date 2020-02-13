use Mojolicious::Lite;

get '/' => {text => 'I ♥ Mojolicious!'};

app->start;