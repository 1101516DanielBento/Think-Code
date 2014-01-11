
%------------------------------------------------------------------------------------
% Determinar condiçoes de circulação
% No caso de não existir nenhuma ocorrencia relativa ao trafego assume-se 
% circulação perfeita (valor 1)
%------------------------------------------------------------------------------------
transito(HoraActual,MinutoActual,IdNodo1,IdNodo2,Transito):-
	trafego(IdNodo1,IdNodo2,Transito,HoraEvento,MinutoEvento),
	relogio2instante(HoraEvento,MinutoEvento,InstanteEvento),
	relogio2instante(HoraActual,MinutoActual,InstanteActual),
	InstanteActual>=InstanteEvento,!.

transito(_,_,_,_,1).





%------------------------------------------------------------------------------------
% Conversao de Hora, Minuto em Instante
%------------------------------------------------------------------------------------
relogio2instante(Hora,Minuto,Instante):-
			Instante is Hora*60 + Minuto.





%------------------------------------------------------------------------
% Inicio da aplicacao
%------------------------------------------------------------------------

start:-
	consult(playedGame),
	removeBecos,
	start2(LEntregas,Percurso,DistanciaTotal),
	%write('Entregas='),write(LEntregas),nl,
	%write('Percurso='),
	%write(Percurso),nl,
	%write('Distancia Total='),write(DistanciaTotal),nl.
	write(Percurso),nl.


start2(LEntregas,Percurso,DistanciaTotal):-

	personagem(Tipo,CapCarga,IdNodo),	

	% juntar todas as requisições numa lista
	% as etiquetas temporais estão a ser ignoradas nesta fase
	findall((TipoEmissor,IdEmissor,TipoLixo,Peso),requisicao(TipoEmissor,IdEmissor,TipoLixo,Peso,Hora,Minuto),LReq),
	findall((TipoL,PesoL,IdNodoL),lixo(TipoL,PesoL,IdNodoL),LLixo),
	
	%esta lista pode ser ordenada p/ optimizar algoritmo
	% na solucao a desenvolver é necessário considerar que as requisicoes vao chegando em tempo real
	% logo a lista de requisiçõe tem que ser constantemente actualizada
	%...
	
	%processarLixo2(CapCarga,IdNodo,LLixo,LEntregas,Percurso,DistanciaTotal).
	%processarRequisicoes(Tipo,CapCarga,IdNodo,LReq,LEntregas,Percurso,DistanciaTotal).
	processarRequisicoes(Tipo,CapCarga,IdNodo,LReq,LER,PercursoR,DistanciaTotalR),

	%falta processar bonus, quando não existirem requisições para processar é necessario 
	% apanhar bonus de forma similar às requisiçoes
	%...
	reverse(PercursoR,Perc),
	devolve_no_inicial(Perc,IdNodoI),
	processarLixo2(CapCarga,IdNodoI,LLixo,LEL,PercursoL,DistanciaTotalL),

	append(LER,LEL,LEntregas),
	append(PercursoR,PercursoL,Percurso),

	DistanciaTotal is DistanciaTotalR + DistanciaTotalL.
	

devolve_no_inicial(PercursoR,IdNodoI):-
	length(PercursoR,Length),
	Length\==0, !,
	no_inicial(PercursoR,IdNodoI).

devolve_no_inicial(PercursoR,IdNodoI):-
	personagem(Tipo,CapCarga,IdNodoI).

no_inicial([IdNodoI|T],IdNodoI).
	

%------------------------------------------------------------------------------------
%processarRequisicoes(Tipo,CapCarga,IdNodo,LReq,LEntregas,Percurso,DistanciaTotal)
%
% Tipo: tipo personagem (peao, bicicleta)
% CapCarga
% IdNodo: posicao inicial
% LReq: Lista de requisições
% LEntregas: lista de entregas realizadas
% Percurso: Persurso total
% DistanciaTotal: distancia do percurso calculado
%------------------------------------------------------------------------------------
 
%nesta demo o tipo do personagem não é utilizado

% condicao final
processarRequisicoes(_,_,_,[],[],[],0).

% a requisição tem peso igual ou inferior à capacidade de carga
% nesse caso a requisição é processada em apenas uma viagem
%
% na solucao actual o personagem segue directo para o ecoponto sem tentar preencher a capacidade de carga, esta limitacao 
% devera ser resolvida na solucao a desenvolver, a capacidade de carga pode ser completada com requisiçoes existentes
% ou com bonus que estejam no caminho
processarRequisicoes(_,CapCarga,IdNodoInicial,[(TipoEmissor,IdEmissor,TipoLixo,Peso)|Resto],[(TipoLixo,Peso)|LEntregas],Percurso,DistanciaTotal):-
	CapCarga==Peso, !,
	
	TipoEmissor(IdEmissor,IdNodoEmissor),
	
	%calcular percurso da posicao inicial até posicao da loja ou casa
	calculacaminho(IdNodoInicial,IdNodoEmissor,Percurso1,Distancia1),


	%escolher um eco-ponto compativel com o tipo de lixo
	%na solucao final deverá ser escolhido o mais proximo
	procura_ecoponto(IdNodoEmissor,TipoLixo,IdNodoEcoponto),
	%ecoponto(IdEcoponto,TipoLixo,IdNodoEcoponto),
	
	%calcular percurso da loja ou casa até ecoponto
	calculacaminho(IdNodoEmissor,IdNodoEcoponto,Percurso2,Distancia2),
	
	%processar resto das requisições
	processarRequisicoes(_,CapCarga,IdNodoEcoponto,Resto,LEntregas,PercursoR,DistanciaTotalR),

	%Calcular resultados finais
	append(Percurso1,Percurso2,PercursoAux),
	append(PercursoAux,PercursoR,Percurso),

	DistanciaTotal is DistanciaTotalR + Distancia1 + Distancia2.

processarRequisicoes(_,CapCarga,IdNodoInicial,[(TipoEmissor,IdEmissor,TipoLixo,Peso)|Resto],[[(TipoLixo,Peso)|LE]|LEntregas],Percurso,DistanciaTotal):-
	CapCarga>Peso, !,
	
	TipoEmissor(IdEmissor,IdNodoEmissor),
	
	%calcular percurso da posicao inicial até posicao da loja ou casa
	calculacaminho(IdNodoInicial,IdNodoEmissor,Percurso1,Distancia1),

	NovaCapCarga is CapCarga - Peso,
	processarRequisicoes2(NovaCapCarga,IdNodoEmissor,Resto,PercursoR0,DistanciaTotalR0,LR,LE,IdNodoActual),

	procura_ecoponto(IdNodoActual,TipoLixo,IdNodoEcoponto),
	calculacaminho(IdNodoActual,IdNodoEcoponto,Percurso2,Distancia2),
	
	elimina((TipoLixo,Peso),LE,LE1),
	outras_entregas(IdNodoEcoponto,TipoLixo,LE1,PercursoR1,DistanciaTotalR1,IdNodoActualR1),

	processarRequisicoes(_,CapCarga,IdNodoActualR1,LR,LEntregas,PercursoR2,DistanciaTotalR2),

	append(Percurso1,PercursoR0,PercursoAux),
	append(PercursoAux,Percurso2,PercursoAux2),
	append(PercursoAux2,PercursoR1,PercursoAux3),
	append(PercursoAux3,PercursoR2,Percurso),

	DistanciaTotal is DistanciaTotalR2 + DistanciaTotalR1+ DistanciaTotalR0 + Distancia1 + Distancia2.

% a requisição tem peso maior que a capacidade de carga
% nesse caso a requisição requer mais do que uma viagem
processarRequisicoes(_,CapCarga,IdNodoInicial,[(TipoEmissor,IdEmissor,TipoLixo,Peso)|Resto],[(TipoLixo,CapCarga)|LEntregas],Percurso,DistanciaTotal):-

	TipoEmissor(IdEmissor,IdNodoEmissor),
	
	%calcular percurso da posicao inicial até posicao da loja ou casa
	calculacaminho(IdNodoInicial,IdNodoEmissor,Percurso1,Distancia1),


	%escolher um eco-ponto compativel com o tipo de lixo
	%na solucao final deverá ser escolhido o mais proximo
	% é necessario validar se existe ecoponto para tipo de lixo da requisicao
	% caso contrario nao pode processar esse lixo
	procura_ecoponto(IdNodoEmissor,TipoLixo,IdNodoEcoponto),
	%ecoponto(IdEcoponto,TipoLixo,IdNodoEcoponto),
	
	%calcular percurso da loja ou casa até ecoponto
	calculacaminho(IdNodoEmissor,IdNodoEcoponto,Percurso2,Distancia2),
	

	%processar resto das requisições
	NovoPeso is Peso - CapCarga,
	processarRequisicoes(_,CapCarga,IdNodoEcoponto,[(TipoEmissor,IdEmissor,TipoLixo,NovoPeso)|Resto],LEntregas,PercursoR,DistanciaTotalR),

	%Calcular resultados finais
	append(Percurso1,Percurso2,PercursoAux),
	append(PercursoAux,PercursoR,Percurso),

	DistanciaTotal is DistanciaTotalR + Distancia1 + Distancia2.

%------------------------------------------------------------------------------------
	
processarRequisicoes2(_,IdNodoInicial,[],[],0,[],[],IdNodoInicial).

processarRequisicoes2(CapCarga,IdNodoInicial,[(TipoEmissor,IdEmissor,TipoLixo,Peso)|Resto],Percurso,DistanciaTotal,LR,[(TipoLixo,Peso)|LEntregas],IdNodoActual):-
	CapCarga>Peso, !,
	
	TipoEmissor(IdEmissor,IdNodoEmissor),
	
	calculacaminho(IdNodoInicial,IdNodoEmissor,Percurso1,Distancia1),

	NovaCapCarga is CapCarga - Peso,
	processarRequisicoes2(NovaCapCarga,IdNodoEmissor,Resto,PercursoR,DistanciaTotalR,LR,LEntregas,IdNodoActual),

	append(Percurso1,PercursoR,Percurso),

	DistanciaTotal is DistanciaTotalR + Distancia1.

processarRequisicoes2(CapCarga,IdNodoInicial,[(TipoEmissor,IdEmissor,TipoLixo,Peso)|Resto],Percurso,DistanciaTotal,Resto,[(TipoLixo,Peso)],IdNodoEmissor):-
	CapCarga==Peso, !,
	
	TipoEmissor(IdEmissor,IdNodoEmissor),
	
	calculacaminho(IdNodoInicial,IdNodoEmissor,Percurso,DistanciaTotal).

processarRequisicoes2(CapCarga,IdNodoInicial,[(TipoEmissor,IdEmissor,TipoLixo,Peso)|Resto],Percurso,DistanciaTotal,[(TipoEmissor,IdEmissor,TipoLixo,NovoPeso)|Resto],[(TipoLixo,NovoPeso)],IdNodoEmissor):-
	CapCarga<Peso, !,
	
	TipoEmissor(IdEmissor,IdNodoEmissor),
	
	NovoPeso is Peso - CapCarga,
	calculacaminho(IdNodoInicial,IdNodoEmissor,Percurso,DistanciaTotal).

%------------------------------------------------------------------------------------

elimina(_,[],[]).

elimina(X,[X|T],L):-!,elimina(X,T,L).

elimina(X,[Y|T],[Y|L]):-elimina(X,T,L).

outras_entregas(X,_,[],[],0,X).

outras_entregas(IdNodoInicial,TipoLixoActual,[(TipoLixo,Peso)|LE],Percurso,DistanciaTotal,IdNodoActualR1):-
	
	TipoLixoActual \== TipoLixo,!,
	procura_ecoponto(IdNodoInicial,TipoLixo,IdNodoEcoponto),
	calculacaminho(IdNodoInicial,IdNodoEcoponto,Percurso1,Distancia1),

	elimina((TipoLixo,Peso),LE,LE1),	
	outras_entregas(IdNodoEcoponto,TipoLixo,LE1,PercursoR,DistanciaTotalR,IdNodoActualR1),
	
	append(Percurso1,PercursoR,Percurso),

	DistanciaTotal is DistanciaTotalR + Distancia1.

outras_entregas(IdNodoInicial,TipoLixo,[(TipoLixo,Peso)|LE],[],0,IdNodoInicial).

%------------------------------------------------------------------------------------

%processarLixo2(CapCarga,IdNodo,LLixo,LEntregas,Percurso,DistanciaTotal)
%
% CapCarga
% IdNodo: posicao inicial
% LLixo: Lista de lixo
% LEntregas: lista de entregas realizadas
% Percurso: Persurso total
% DistanciaTotal: distancia do percurso calculado

processarLixo2(_,_,[],[],[],0).

processarLixo2(CapCarga,IdNodoInicial,[(Tipo,Peso,IdNodo)|Resto],[(Tipo,Peso)|LEntregas],Percurso,DistanciaTotal):-
	CapCarga==Peso, !,
	
	%calcular percurso da posicao inicial até posicao da loja ou casa
	calculacaminho(IdNodoInicial,IdNodo,Percurso1,Distancia1),


	%escolher um eco-ponto compativel com o tipo de lixo
	%na solucao final deverá ser escolhido o mais proximo
	procura_ecoponto(IdNodo,Tipo,IdNodoEcoponto),
	%ecoponto(IdEcoponto,TipoLixo,IdNodoEcoponto),
	
	%calcular percurso da loja ou casa até ecoponto
	calculacaminho(IdNodo,IdNodoEcoponto,Percurso2,Distancia2),
	
	%processar resto das requisições
	processarLixo2(CapCarga,IdNodoEcoponto,Resto,LEntregas,PercursoR,DistanciaTotalR),

	%Calcular resultados finais
	append(Percurso1,Percurso2,PercursoAux),
	append(PercursoAux,PercursoR,Percurso),

	DistanciaTotal is DistanciaTotalR + Distancia1 + Distancia2.

processarLixo2(CapCarga,IdNodoInicial,[(Tipo,Peso,IdNodo)|Resto],[[(Tipo,Peso)|LE]|LEntregas],Percurso,DistanciaTotal):-
	CapCarga>Peso, !,
	
	%calcular percurso da posicao inicial até posicao da loja ou casa
	calculacaminho(IdNodoInicial,IdNodo,Percurso1,Distancia1),

	NovaCapCarga is CapCarga - Peso,
	processarLixo3(NovaCapCarga,IdNodo,Resto,PercursoR0,DistanciaTotalR0,LL,LE,IdNodoActual),

	procura_ecoponto(IdNodoActual,Tipo,IdNodoEcoponto),
	calculacaminho(IdNodoActual,IdNodoEcoponto,Percurso2,Distancia2),

	elimina((Tipo,Peso),LE,LE1),
	outras_entregas(IdNodoEcoponto,Tipo,LE1,PercursoR1,DistanciaTotalR1,IdNodoActualR1),

	processarLixo2(CapCarga,IdNodoActualR1,LL,LEntregas,PercursoR2,DistanciaTotalR2),

	append(Percurso1,PercursoR0,PercursoAux),
	append(PercursoAux,Percurso2,PercursoAux2),
	append(PercursoAux2,PercursoR1,PercursoAux3),
	append(PercursoAux3,PercursoR2,Percurso),

	DistanciaTotal is DistanciaTotalR2 + DistanciaTotalR1+ DistanciaTotalR0 + Distancia1 + Distancia2.

processarLixo2(CapCarga,IdNodoInicial,[(Tipo,Peso,IdNodo)|Resto],[(Tipo,Peso)|LEntregas],Percurso,DistanciaTotal):-
	
	%calcular percurso da posicao inicial até posicao da loja ou casa
	calculacaminho(IdNodoInicial,IdNodo,Percurso1,Distancia1),


	%escolher um eco-ponto compativel com o tipo de lixo
	%na solucao final deverá ser escolhido o mais proximo
	% é necessario validar se existe ecoponto para tipo de lixo da requisicao
	% caso contrario nao pode processar esse lixo
	procura_ecoponto(IdNodo,Tipo,IdNodoEcoponto),
	%ecoponto(IdEcoponto,TipoLixo,IdNodoEcoponto),
	
	%calcular percurso da loja ou casa até ecoponto
	calculacaminho(IdNodo,IdNodoEcoponto,Percurso2,Distancia2),
	

	%processar resto das requisições
	NovoPeso is Peso - CapCarga,
	processarLixo2(CapCarga,IdNodoEcoponto,[(Tipo,NovoPeso,IdNodo)|Resto],LEntregas,PercursoR,DistanciaTotalR),

	%Calcular resultados finais
	append(Percurso1,Percurso2,PercursoAux),
	append(PercursoAux,PercursoR,Percurso),

	DistanciaTotal is DistanciaTotalR + Distancia1 + Distancia2.

%------------------------------------------------------------------------------------

processarLixo3(_,IdNodoInicial,[],[],0,[],[],IdNodoInicial).

processarLixo3(CapCarga,IdNodoInicial,[(Tipo,Peso,IdNodo)|Resto],Percurso,DistanciaTotal,LL,[(Tipo,Peso)|LEntregas],IdNodoActual):-
	CapCarga>Peso, !,
	
	calculacaminho(IdNodoInicial,IdNodo,Percurso1,Distancia1),

	NovaCapCarga is CapCarga - Peso,
	processarLixo3(NovaCapCarga,IdNodo,Resto,PercursoR,DistanciaTotalR,LL,LEntregas,IdNodoActual),

	append(Percurso1,PercursoR,Percurso),

	DistanciaTotal is DistanciaTotalR + Distancia1.


processarLixo3(CapCarga,IdNodoInicial,[(Tipo,Peso,IdNodo)|Resto],Percurso,DistanciaTotal,Resto,[(Tipo,Peso)],IdNodo):-
	CapCarga==Peso, !,
	
	calculacaminho(IdNodoInicial,IdNodo,Percurso,DistanciaTotal).

processarLixo3(CapCarga,IdNodoInicial,[(Tipo,Peso,IdNodo)|Resto],Percurso,DistanciaTotal,[(Tipo,NovoPeso,IdNodo)|Resto],[(Tipo,NovoPeso)],IdNodo):-
	CapCarga<Peso, !,
	
	NovoPeso is Peso - CapCarga,
	calculacaminho(IdNodoInicial,IdNodo,Percurso,DistanciaTotal).

%------------------------------------------------------------------------------------

calculacaminho(Orig,Dest,Perc,Total):-
	estimativa(Orig,Dest,H),
	calculacaminho1([c(H/0,[Orig])],Dest,P,Total),
	reverse(P,Perc).

calculacaminho1(Percursos,Dest,Percurso,Total):-
	menor_percursoh(Percursos,Menor,Restantes),
	percursos_seguintesh(Menor,Dest,Restantes,Percurso,Total).

percursos_seguintesh(c(_/Dist,Percurso),Dest,_,Percurso,Dist):-
	Percurso=[Dest|_].

percursos_seguintesh(c(_,[Dest|_]),Dest,Restantes,Percurso,Total):-!,
	calculacaminho1(Restantes,Dest,Percurso,Total).

percursos_seguintesh(c(_/Dist,[Ult|T]),Dest,Percursos,Percurso,Total):-
	findall(c(H1/D1,[Z,Ult|T]),proximo_noh(Ult,T,Z,Dist,Dest,H1/D1),Lista),
	append(Lista,Percursos,NovosPercursos),
	calculacaminho1(NovosPercursos,Dest,Percurso,Total).

menor_percursoh([Percurso|Percursos],Menor,[Percurso|Resto]):-
	menor_percursoh(Percursos,Menor,Resto),
	menorh(Menor,Percurso),!.

menor_percursoh([Percurso|Resto],Percurso,Resto).

%acrescentar velocidade no personagem
%Utilizar velocidade e transito((H+D)*(Vel*transito))
%menorh(c(H1/D1,_),c(H2/D2,_)):-
menorh(c(H1/D1,L1),c(H2/D2,L2)):-
	C1 is H1+D1,
	rt(L1,Traf1),C3 is C1*(1-Traf1+1),
	C2 is H2+D2,
	rt(L2,Traf2),C4 is C2*(1-Traf2+1),
	C3<C4.
%------------------------------------------------------------------------------------
rt([D,O|T],Traf):-
	obter_transito(O,D,Traf).

copia([],[]).

copia([H|T],[H|L1]):-copia(T,L1).
%------------------------------------------------------------------------------------

proximo_noh(X,T,Y,Dist,Dest,H/Dist1):-
	(ramo(X,Y,Z),obter_transito(X,Y,Traf);ramo(Y,X,Z),obter_transito(Y,X,Traf)),
	Traf\==0,
	not member(Y,T),
	Dist1 is Dist + Z,
	estimativa(Y,Dest,H).

estimativa(C1,C2,Est):-
	nodo(C1,X1,Y1),
	nodo(C2,X2,Y2),
	DX is X1-X2,
	DY is Y1-Y2,
	Est is sqrt(DX*DX+DY*DY).

%------------------------------------------------------------------------------------

%------------------------------------------------------------------------------------

procura_ecoponto(IdNodoActual,TipoLixo,IdNodoEcoponto):-
	findall(IdNodo,ecoponto(_,TipoLixo,IdNodo),L),
	L\==[],
	ecoponto_mais_proximo(IdNodoActual,L,1000000,[IdNodoEcoponto|T]).

ecoponto_mais_proximo(_,[],_,_).

ecoponto_mais_proximo(IdNodoActual,[IdNodo|T],H,[IdNodo|T1]):-
	estimativa(IdNodoActual,IdNodo,H1),
	H1<H,!,
	ecoponto_mais_proximo(IdNodoActual,T,H1,[IdNodo|T1]).
	
ecoponto_mais_proximo(IdNodoActual,[IdNodo|T],H,IdNodoEcoponto):-
	ecoponto_mais_proximo(IdNodoActual,T,H,IdNodoEcoponto).

obter_transito(O,D,Transito):-
	trafego(O,D,Transito,_,_),!.

obter_transito(_,_,1).

%------------------------------------------------------------------------------------
% retira becos
%------------------------------------------------------------------------------------
removeBecos:- 
	%write('A remover becos...'),
	findall(X,(nodo(X,Y,_)),L1),
	%nl,write('Nós existentes:'),write(L1),
	obter_nodos_ocupados(NODOS_COM_COISAS),
	interseccao_negada(L1,NODOS_COM_COISAS,R),
	removeBecos2(R).

%removeBecos2([]):-nl,write('---FIM---'),nl.
removeBecos2([]).
removeBecos2([X|AUX]):- grau(X,RESUL),remover(X,RESUL),removeBecos2(AUX).



remover(X,1):- 
	%nl,write('Beco encontrado:'),write(X),
	(ramo(P,X,_),retract(ramo(P,X,_)),
	%nl,write('Ramo entre '),write(P),write(' e '),write(X),write(' eliminado.'),
	nodo(X,_,_),retract(nodo(X,_,_)),
	%nl,write('Nodo '),write(X),write(' eliminado.'),
	testar(P));
	(ramo(X,W,_),retract(ramo(X,P,_)),
	%nl,write('Ramo entre '),write(X),write(' e '),write(P),write(' eliminado.'),
	nodo(X,_,_),retract(nodo(X,_,_)),
	%nl,write('Nodo '),write(X),write(' eliminado.'),
	testar(P)).
  
remover(_,_).

testar(P):- grau(P,RESUL),obter_nodos_ocupados(NODOS_COM_COISAS),not member(P,NODOS_COM_COISAS),!,remover(P,RESUL).


interseccao_negada([],L,[]).
interseccao_negada([X|R],Y,Z):-member(X,Y),!,interseccao_negada(R,Y,Z).
interseccao_negada([X|R],Y,[X|Z]):-interseccao_negada(R,Y,Z).

obter_nodos_ocupados(NODOS_COM_COISAS):-
	findall(X,(ecoponto(_,_,X)),NODOS_COM_ECOPONTOS),
	findall(X,(loja(_,X)),NODOS_COM_LOJAS),append(NODOS_COM_ECOPONTOS,NODOS_COM_LOJAS,NODOS_C_LeE),
	findall(X,(casa(_,X)),NODOS_COM_CASAS),append(NODOS_C_LeE,NODOS_COM_CASAS,NODOS_C_LeEeC),
	findall(X,(personagem(_,_,X)),NODO_COM_PERSONAGEM),append(NODOS_C_LeEeC,NODO_COM_PERSONAGEM,NODOS_C_LeEeCeP),
	findall(X,(lixo(_,_,X)),NODOS_COM_BONUS),append(NODOS_COM_BONUS,NODOS_C_LeEeCeP,NODOS_COM_COISAS).

grau(X, RES):-findall(Y,(ramo(X, Y, _) ; ramo(Y, X, _)),Res),length(Res, RES).

