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
tags_sub(fcp, futebolclubeporto).
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
%------------------pesquisas para amigos------------------
%amigos diretos de um utilizador
amigos_diretos(Utilizador, L):-
	findall(Y,(relacao(Utilizador,Y);relacao(Y,Utilizador)),L).


amigo_Do_Amigo(Utilizador,Y,L,UtilizadorCentral):-
	(relacao(Utilizador,Y);relacao(Y,Utilizador)), \+member(Y,L), Y \== UtilizadorCentral.

%------------------pesquisas para tags--------------------

%um utilizador
tags_1_utilizador( Utilizador,L):-
	findall(Tag,user_tags(Utilizador, Tag), L).

%todos os nomes dessa tag
encontra_tags_sub(H,LR):-
	findall(Tag,(tags_sub(H,Tag);tags_sub(Tag,H)),L), append([H],L,LR).

%Lista de utilizadores e as suas tags
utilizadores_tags([],[]).
utilizadores_tags([H|T],[[H|LTags]|LF]):-
	tags_1_utilizador(H,LTags),utilizadores_tags(T,LF).

% Dado as tags do amigo com os seus significados verifica se esta na
% lista das tags do Utilizador



verificaTagComum([H|_],LTagsUtilizador,Valor):-
	member(H,LTagsUtilizador),Valor is 0+1.

verificaTagComum([_|T],LTagsUtilizador,Valor):-
	verificaTagComum(T,LTagsUtilizador,Valor).
verificaTagComum([],_,_).


%----------------------------------------------------------



%tamanho da rede

tamanho_rede_Utilizador(Utilizador):-
	user(Utilizador),!,
	amigos_diretos(Utilizador,L),
	tamanho_rede(L,L,_,Utilizador).

tamanho_rede([],_,LF,UtilizadorCentral):-
	length(LF,N), write('O Tamanho da rede do utilizador '),write(UtilizadorCentral),write(' � de '), write(N), write(' elementos.'), nl.

tamanho_rede([H|T],L,_,UtilizadorCentral):-
	findall(Y,amigo_Do_Amigo(H,Y,L,UtilizadorCentral),LR),append(L,LR,LX),
	tamanho_rede(T,LX,LX,UtilizadorCentral).


%encontra amigos que tenham em comum X tags

obter_amigos_X_tags_comuns(Utilizador,X,ListaAmigos):-
	amigos_diretos(Utilizador,LAmigosDirectos),
	utilizadores_tags(LAmigosDirectos,LTagsAmigos),
	obter_tags_comuns(LTagsAmigos,X,ListaAmigos,Utilizador,0).

obter_tags_comuns([[Huser,Htag|TL]|T],X,ListaAmigos,Utilizador,N):-
	encontra_tags_sub(Htag,LSignificadosTags),
	tags_1_utilizador(Utilizador,LTagsUtilizador),
	verificaTagComum(LSignificadosTags,LTagsUtilizador,Valor),Valor == 1, N1 is N + 1,
	obter_tags_comuns([[Huser|TL]|T],X,ListaAmigos,Utilizador,N1);obter_tags_comuns([[Huser|TL]|T],X,ListaAmigos,Utilizador,N).

obter_tags_comuns([[H|[]]|T],X,[H|ListaAmigos],Utilizador,N):-
	N > 0, X = N, obter_tags_comuns(T,X,ListaAmigos,Utilizador,0).

obter_tags_comuns([[_|[]]|T],X,ListaAmigos,Utilizador,0):-
	obter_tags_comuns(T,X,ListaAmigos,Utilizador,0).

obter_tags_comuns([],_,_,_,_).












