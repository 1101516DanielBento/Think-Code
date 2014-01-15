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

relacao(tiago,fred,'Conhecido').
relacao(tiago,pedro,'Amigo').
relacao(tiago,daniel,'Desconhecido').
relacao(tiago,luis,'Familia').
relacao(tiago,daniel,'Other').
relacao(tiago,daniela,'Amigo').
relacao(fred,jose,'').
relacao(fred,neves,'Familia').
relacao(luis,daniela,'Amigo').
relacao(daniela,francisco,'').
relacao(pedro,rocha,'Conhecido').
relacao(rocha,antonio,'Other').
%------------------pesquisas para amigos------------------
%amigos diretos de um utilizador
amigos_diretos(Utilizador, L):-
	findall(Y,(relacao(Utilizador,Y,_);relacao(Y,Utilizador,_)),L).


amigo_Do_Amigo(Utilizador,Y,L,UtilizadorCentral):-
	(relacao(Utilizador,Y,_);relacao(Y,Utilizador,_)), \+member(Y,L), Y \== UtilizadorCentral.

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


%-------------tamanho da rede ate ao terceiro nivel-----------

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
	user(UtilizadorOrigem),
	user(UtilizadorDestino),
	findall(Y,relacao(UtilizadorOrigem,Y,_),L),
	cria_caminho([UtilizadorOrigem],L,LC),
	determina_caminho_curto(UtilizadorDestino,LC,LR).

determina_caminho_curto(UtilizadorDestino,[[UtilizadorDestino|L]|_],R):-
	reverse([UtilizadorDestino|L],R).

determina_caminho_curto(UtilizadorDestino,[[Destino|Destinos]|LR],L):-
	findall(X,relacao(Destino,X,_),LL),
	cria_caminho([Destino|Destinos],LL,Lcaminho),
	append(LR,Lcaminho,Lappend),
	determina_caminho_curto(UtilizadorDestino,Lappend,L).

cria_caminho(_,[],[]).
cria_caminho(Utilizadores,[Destino|Destinos],LR):-
	member(Destino,Utilizadores),
	cria_caminho(Utilizadores,Destinos,LR).
cria_caminho(Utilizadores,[Destino|Destinos],[[Destino|Utilizadores]|LR]):-
	cria_caminho(Utilizadores,Destinos,LR).


%------------------caminho mais forte----------------------------

determinar_caminho_mais_forte(UtilizadorOrigem,UtilizadorDestino,LF):-findall(Y,determinar_caminho_mais_forte2(UtilizadorOrigem,UtilizadorDestino,Y),L),maior(L,LF).

determinar_caminho_mais_forte2(UtilizadorOrigem,UtilizadorDestino,LF):-findall((D,P),relacao(UtilizadorOrigem,D,P),LR),cria([UtilizadorOrigem],LR,Lcria),
	determinar_caminho_mais_forte22(UtilizadorDestino,Lcria,LF).

determinar_caminho_mais_forte22(UtilizadorDestino,[[(UtilizadorDestino,Peso)|Caminho]|_],[ResultadoDivisao,(UtilizadorDestino,Peso)|Caminho]):-soma([(UtilizadorDestino,Peso)|Caminho],PesoTotal),
	length([(UtilizadorDestino,Peso)|Caminho],Npessoas),
	divide(PesoTotal,Npessoas,ResultadoDivisao).
determinar_caminho_mais_forte22(UtilizadorDestino,[[(Pessoa,Peso)|Caminho]|R],LF):-findall((Y,P),
	relacao(Pessoa,Y,P),L),
	cria([(Pessoa,Peso)|Caminho],L,LR),
	append(R,LR,La),
	%write(V),nl
	!,
	determinar_caminho_mais_forte22(UtilizadorDestino,La,LF).

cria(_,[],[]).
cria(O,[(Y,_)|Ys],R):-member(Y,O),cria(O,Ys,R).
cria(O,[(Y,S)|Ys],[[(Y,NS)|O]|R]):-traduz(S,NS),cria(O,Ys,R).

soma(L,0):-length(L,1).
soma([(_,Peso)|Caminho],PesoTotal):-soma(Caminho,P),PesoTotal is P +Peso.

divide(A,B,C):-C is A/B.

maior(L,L):-length(L,1).
maior([[X|Xs],[Y|_]|R],P):-X>Y,
	maior([[X|Xs]|R],P).
maior([[X|_],[Y|Ys]|R],P):-Y>=X,
	maior([[Y|Ys]|R],P).


traduz(Peso,Npeso):-Peso == 'Familia', Npeso is 0+10.
traduz(Peso,Npeso):-Peso == 'Amigo', Npeso is 0+8.
traduz(Peso,Npeso):-Peso == 'Conhecido', Npeso is 0+6.
traduz(Peso,Npeso):-Peso == 'Desconhecido', Npeso is 0+4.
traduz(Peso,Npeso):-Peso == 'Other', Npeso is 0+2.
traduz(Peso,Npeso):-Peso == '', Npeso is 0+2.
traduz(_,Npeso):-Npeso is 0+2.












