:-use_module(library(odbc)).

:-dynamic user/1.

connect:-
	odbc_connect('wvm023', _,
		     [user(wvm023),
		     password(wvm023),
		     alias(wvm023),
		     open(once)]).


users(U):-
	odbc_query(wvm023, 'SELECT Name FROM dbo.Test', U,[ types([default])]).


userByID(Id,U):-
	string_concat('SELECT Name FROM dbo.Test WHERE id=', (Id), Sql),
	findall(X, odbc_query(wvm023, Sql , row(X)), U),
	knowledge(U).

knowledge([H|_]):-
	assertz(user(H)).




