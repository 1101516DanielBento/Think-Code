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

%RelaÃ§Ãµes (GRAFO)

relacao(tiago,fred).
relacao(tiago,pedro).
relacao(tiago,daniel).
relacao(tiago,luis).
relacao(tiago,daniela).
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
%por lista
encontra_Ltags_sub([],L,L).
encontra_Ltags_sub([H|T],L,Lto):-
	encontra_tags_sub(H,LR), append(L,LR,La),
	encontra_Ltags_sub(T,La,Lto).


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

tamanho_rede_utilizador(Utilizador,LF):-
	user(Utilizador),
	amigos_diretos(Utilizador,L),
	tamanho_rede(L,L,Utilizador,LF).

tamanho_rede([H|T],L,UtilizadorCentral,LTot):-
	findall(Y,amigo_Do_Amigo(H,Y,L,UtilizadorCentral),LR),
	append(L,LR,LF),
	tamanho_rede(T,LF,UtilizadorCentral,LTot).


tamanho_rede([],LF,UtilizadorCentral,LF):-!,
	length(LF,N), write('O Tamanho da rede do utilizador '),write(UtilizadorCentral),write(' é de '), write(N), write(' elementos.'), nl.



%encontra amigos que tenham em comum X tags

obter_amigos_X_tags_comuns(Utilizador,X,ListaAmigos):-
	user(Utilizador),
	amigos_diretos(Utilizador,LAmigosDirectos),
	utilizadores_tags(LAmigosDirectos,LTagsAmigos),
	obter_tags_comuns(LTagsAmigos,X,ListaAmigos,Utilizador,0).

obter_tags_comuns([[Huser,Htag|TL]|T],X,ListaAmigos,Utilizador,N):-
	encontra_tags_sub(Htag,LSignificadosTags),
	tags_1_utilizador(Utilizador,LTagsUtilizador),
	verificaTagComum(LSignificadosTags,LTagsUtilizador,Valor),Valor == 1, N1 is N + 1,!,
	obter_tags_comuns([[Huser|TL]|T],X,ListaAmigos,Utilizador,N1);obter_tags_comuns([[Huser|TL]|T],X,ListaAmigos,Utilizador,N).

obter_tags_comuns([[H|[]]|T],X,[H|ListaAmigos],Utilizador,N):-
	N > 0, X = N, obter_tags_comuns(T,X,ListaAmigos,Utilizador,0).

obter_tags_comuns([[_|[]]|T],X,ListaAmigos,Utilizador,0):-
	obter_tags_comuns(T,X,ListaAmigos,Utilizador,0).

obter_tags_comuns([],_,[],_,_).


% --------surgerir ligações ate ao terceiro nivel com tags comuns ------

sugerir_amigos(Utilizador,LF):-
	user(Utilizador),!,
	amigos_diretos(Utilizador,LAmigos),
	tamanho_rede(LAmigos,LAmigos,Utilizador,LRede),
	elimina_diretos(LAmigos,LRede,Llimpa),
	sugestao(Llimpa,Utilizador,LF).


elimina_diretos(_,[],[]).
elimina_diretos(LA,[H|T],LP):-
	member(H,LA),!,
	elimina_diretos(LA,T,LP).
elimina_diretos(LA,[H|T],[H|LP]):-
	elimina_diretos(LA,T,LP).

sugestao([],_,[]).
sugestao([H|T],Utilizador,[H|LF]):-
	tags_1_utilizador(Utilizador,LtagsUtilizador),
	compara_tags(H,LtagsUtilizador,Valor),
	Valor == 1,!,
	sugestao(T,Utilizador,LF).
sugestao([_|T],Utilizador,LF):-
	sugestao(T,Utilizador,LF).


compara_tags(H,LTagsU,Valor):-
	tags_1_utilizador(H,LTagsA),
	encontra_Ltags_sub(LTagsA,LTagsA,LtodasTags),
	verificaTagComum(LtodasTags,LTagsU,Valor).

%---------------------Caminho mais curto-----------------------

caminho_mais_curto(UtilizadorOrigem,UtilizadorDestino,LR):-
	user(UtilizadorOrigem),!,
	user(UtilizadorDestino),!,
	findall(Y,relacao(UtilizadorOrigem,Y),L),
	cria_caminho([UtilizadorOrigem],L,LC),
	determina_caminho_curto(UtilizadorDestino,LC,LR).

determina_caminho_curto(UtilizadorDestino,[[UtilizadorDestino|L]|_],R):-
	reverse([UtilizadorDestino|L],R).

determina_caminho_curto(UtilizadorDestino,[[Destino|Destinos]|LR],L):-
	findall(X,relacao(Destino,X),LL),
	cria_caminho([Destino|Destinos],LL,Lcaminho),
	append(LR,Lcaminho,Lappend),
	determina_caminho_curto(UtilizadorDestino,Lappend,L).

cria_caminho(_,[],[]).
cria_caminho(Utilizadores,[Destino|Destinos],LR):-
	member(Destino,Utilizadores),
	cria_caminho(Utilizadores,Destinos,LR).
cria_caminho(Utilizadores,[Destino|Destinos],[[Destino|Utilizadores]|LR]):-
	cria_caminho(Utilizadores,Destinos,LR).
