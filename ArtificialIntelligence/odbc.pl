:-use_module(library(odbc)).

:-dynamic user/1.
:-dynamic user_tags/2.

connect:-
	odbc_connect('wvm023', _,
		     [user(wvm023),
		     password(wvm023),
		     alias(wvm023),
		     open(once)]).

allUsers(L):-
	findall(X, odbc_query(wvm023, 'SELECT username FROM dbo.[User]', row(X)),L).


toBaseKnowledge(UId):-
	usernameByID(UId,_).


usernameByID(UId,Username):-
	string_concat('SELECT username FROM dbo.[User] WHERE idUser=', (UId), Sql),
	findall(X, odbc_query(wvm023, Sql , row(X)), [Username|_]),
        knowUser(UId, Username),
	knowFriends(UId).


userTagIDs(UId, TagList):-
	string_concat('SELECT idTag FROM dbo.[UserTags] WHERE idUser=', (UId), Sql),
	findall(X, odbc_query(wvm023, Sql, row(X)), TagIDList),
	userTags(TagIDList, TagList).


userTags([],[]):-!.
userTags([H|T],[Tag|TagList]):-
	string_concat('SELECT tagName FROM dbo.[TagList] WHERE idTag=', (H), Sql),
	findall(X, odbc_query(wvm023, Sql, row(X)), [Tag|_]),
	userTags(T, TagList).


knowFriends(UId):-
	string_concat('SELECT idUserB FROM dbo.[FriendShip] WHERE idUserA=', (UId), Sql1),
	findall(X, odbc_query(wvm023, Sql1, row(X)), IDs1),
	string_concat('SELECT idUserA FROM dbo.[FriendShip] WHERE idUserB=', (UId), Sql2),
	findall(X, odbc_query(wvm023, Sql2, row(X)), IDs2),
	append(IDs1,IDs2,IDs),
	userByIdList(IDs).


userByIdList([]):-!.
userByIdList([H|T]):-
	string_concat('SELECT username FROM dbo.[User] WHERE idUser=', (H), Sql),
	findall(X, odbc_query(wvm023, Sql, row(X)), [User|_]),
	knowUser(H,User),
	userByIdList(T).


knowUser(UId,Username):-
	assertz(user(Username)),
	userTagIDs(UId,TagList),
	knowUserTags(Username,TagList).


knowUserTags(_,[]):-!.
knowUserTags(U, [Tag|T]):-
	assertz(user_tags(U,Tag)),
	knowUserTags(U,T).
















