
%tamanho da rede

tamanho_rede_Utilizador(Utilizador):-consult('prologbaseconhecimento.pl'),
	user(Utilizador),!,
	findall(Y,(relacao(Utilizador,Y);relacao(Y,Utilizador)),L),tamanho_rede(L,L,_,Utilizador).

tamanho_rede([],_,LF,UtilizadorCentral):-
	length(LF,N), write('O Tamanho da rede do utilizador '),write(UtilizadorCentral),write(' é de '), write(N), write(' elementos.'), nl.

tamanho_rede([H|T],L,_,UtilizadorCentral):-
	findall(Y,amigo_Do_Amigo(H,Y,L,UtilizadorCentral),LR),append(L,LR,LX), tamanho_rede(T,LX,LX,UtilizadorCentral).

amigo_Do_Amigo(Utilizador,Y,L,UtilizadorCentral):-
	(relacao(Utilizador,Y);relacao(Y,Utilizador)), \+member(Y,L), Y \== UtilizadorCentral.


