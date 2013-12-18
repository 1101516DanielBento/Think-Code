%helloworld(_Request):-
%	format('Content-type: text/plain~n~n'),
%	format('Hello World!~n').

%:-http_handler('/test', helloworld, []).

:-use_module(library(http/thread_httpd)).
:-use_module(library(http/http_dispatch)).
:-use_module(library(http/http_client)).
:-use_module(library(http/http_parameters)).

:-http_handler('/register_user', register_user, []).

:-dynamic register_user/3.
:-dynamic user/3.


server(Port):-
	http_server(http_dispatch, [port(Port)]).


register_user(Request) :-
    http_parameters(Request,
                    [ name(Name, []),
                      sex(Sex, [oneof([male,female])]),
                      birth_year(BY, [between(1850,2013)])]),
    register_user(Name, Sex, BY),
    format('Content-type: text/plain~n~n'),
    format('User registered!~n'),
    format('Name: ~w~nSex: ~w~nBirth Year: ~w~n',[Name,Sex,BY]).


register_user(Name,Sex,BY):-
	assertz(user(Name,Sex,BY)),
	tell('prologDB.pl'),
	listing(user/3),
	told.














