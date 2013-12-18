%BASE DE CONHECIMENTO
%Utilizadores

user(tiago).
user(fred).
user(pedro).
user(daniel).
user(luis).
user(daniela).
user(francisco).
user(rocha).
user(jose).
user(antonio).
user(neves).

%Tags

tags(fcporto).
tags(slbenfica).
tags(sportingcp).
tags(desporto).
tags(televisao).
tags(filmes).
tags(series).
tags(tecnologias).
tags(csharp).
tags(isep).
tags(livros).

tags_sub(fcp, fcporto).
tags_sub(fcp, futebolClubePorto).
tags_sub(slb, slbenfica).
tags_sub(slb, sportLisboaBenfica).
tags_sub(scp, sportingcp).
tags_sub(scp, sportingClubPortugal).
tags_sub(isep,institutoSuperiorEngenhariaPorto).

user_tags(tiago, fcp).
user_tags(tiago,series).
user_tags(fred,desporto).
user_tags(fred, fcporto).
user_tags(pedro,csharp).
user_tags(daniel,tecnologias).
user_tags(daniel,desporto).
user_tags(luis, filmes).
user_tags(luis,csharp).
user_tags(daniela,televisao).
user_tags(daniela,livros).
user_tags(francisco, sportLisboaBenfica).
user_tags(rocha,scp).
user_tags(rocha,desporto).
user_tags(jose,slb).
user_tags(antonio,isep).
user_tags(neves, institutoSuperiorEngenhariaPorto).
user_tags(neves, livros).

%Relações (GRAFO)

relacao(tiago,fred).
relacao(tiago,pedro).
relacao(tiago,daniel).
relacao(tiago,luis).
relacao(fred,jose).
relacao(fred,neves).
relacao(luis,daniela).
relacao(daniela,francisco).
relacao(pedro,rocha).
relacao(rocha,antonio).

%amigos diretos de um utilizador
amigos_diretos(Utilizador, L):-
	findall(Y,(relacao(Utilizador,Y);relacao(Y,Utilizador)),L).


%tamanho da rede

tamanho_rede_Utilizador(Utilizador):-
	user(Utilizador),!,
	amigos_diretos(Utilizador,L),tamanho_rede(L,L,_,Utilizador).

tamanho_rede([],_,LF,UtilizadorCentral):-
	length(LF,N), write('O Tamanho da rede do utilizador '),write(UtilizadorCentral),write(' � de '), write(N), write(' elementos.'), nl.

tamanho_rede([H|T],L,_,UtilizadorCentral):-
	findall(Y,amigo_Do_Amigo(H,Y,L,UtilizadorCentral),LR),append(L,LR,LX), tamanho_rede(T,LX,LX,UtilizadorCentral).

amigo_Do_Amigo(Utilizador,Y,L,UtilizadorCentral):-
	(relacao(Utilizador,Y);relacao(Y,Utilizador)), \+member(Y,L), Y \== UtilizadorCentral.


%encontra amigos que tenham em comum X tags

amigos_tags_comuns(Utilizador,L,LF):-
	amigos_diretos(Utilizador,L),utilizador_tags(L,LF).

utilizador_tags([],[]).

utilizador_tags([H|T],[[H|LTags]|LF]):-
	findall(Tag,user_tags(H,Tag),LTags),utilizador_tags(T,LF).










