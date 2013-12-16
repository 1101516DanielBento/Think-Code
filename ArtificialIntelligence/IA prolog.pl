%BASE DE CONHECIMENTO

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

%tamanho da rede

tamanho_rede_Utilizador(Utilizador,LF):-user(Utilizador),!,
	findall(Y,(relacao(Utilizador,Y);relacao(Y,Utilizador)),L),tamanho_rede(L,L,LF,Utilizador).

tamanho_rede([],_,LF,UtilizadorCentral):-
	length(LF,N), write('O Tamanho da rede do utilizador '),write(UtilizadorCentral),write(' é de '), write(N), write(' elementos.'), nl.

tamanho_rede([H|T],L,_,UtilizadorCentral):-
	findall(Y,amigo_Do_Amigo(H,Y,L,UtilizadorCentral),LR),append(L,LR,LX), tamanho_rede(T,LX,LX,UtilizadorCentral).

amigo_Do_Amigo(Utilizador,Y,L,UtilizadorCentral):-
	(relacao(Utilizador,Y);relacao(Y,Utilizador)), \+member(Y,L), Y \== UtilizadorCentral.




