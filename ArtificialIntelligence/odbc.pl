:-use_module(library(odbc)).

:-dynamic user/1.
:-dynamic user_tags/2.

connect:-
	odbc_connect('wvm023', _,
		     [user(wvm023),
		     password(wvm023),
		     alias(wvm023),
		     open(once)]).

users(U):-
	odbc_query(wvm023, 'SELECT username FROM dbo.[User]', U,[ types([default])]).

toBaseKnowledge(Id):-userByID(Id,_).

userByID(UId,User):-
	string_concat('SELECT username FROM dbo.[User] WHERE idUser=', (UId), Sql),
	findall(X, odbc_query(wvm023, Sql , row(X)), [User|_]),
	userKnowledge(User),
	userTagIDs(UId, TagList),
	userTagsKnowledge(User, TagList).


userTagIDs(UId, TagList):-
	string_concat('SELECT idTag FROM dbo.[UserTags] WHERE idUser=', (UId), SqlTagID),
	findall(X, odbc_query(wvm023, SqlTagID, row(X)), TagIDList),
	userTags(TagIDList, TagList).


userTags([],[]).
userTags([H|T],[Tag|TagList]):-
	string_concat('SELECT tagName FROM dbo.[TagList] WHERE idTag=', (H), SqlTags),
	findall(X, odbc_query(wvm023, SqlTags, row(X)), [Tag|_]),
	userTags(T, TagList).


friends(UId,IDs):-
	string_concat('SELECT idUserB FROM dbo.[FriendShip] WHERE idUserA=', (UId), Sql1),
	findall(X, odbc_query(wvm023, Sql1, row(X)), IDs1),
	string_concat('SELECT idUserA FROM dbo.[FriendShip] WHERE idUserB=', (UId), Sql2),
	findall(X, odbc_query(wvm023, Sql2, row(X)), IDs2),
	append(IDs1,IDs2,IDs).


userKnowledge(U):-
	assertz(user(U)).


userTagsKnowledge(_,[]).
userTagsKnowledge(U, [Tag|T]):-
	assertz(user_tags(U,Tag)),
	userTagsKnowledge(U,T).
