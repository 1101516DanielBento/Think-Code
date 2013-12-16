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

tags_sub(fcporto,fcp,futbolClubePorto).
tags_sub(slbenfica,slb,sportLisboaBenfica).
tags_sub(sportingcp,scp,sportingClubePortugal).
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

