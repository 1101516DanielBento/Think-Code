:-dynamic nodo/3,ramo/3.
:-dynamic trafego/5,ecoponto/3,loja/2,casa/2,personagem/3,lixo/3,requisicao/6.
nodo(0,0,-5).
nodo(1,-5,-5).
nodo(2,-5,0).
nodo(3,0,0).
nodo(4,0,5).
nodo(5,7,5).
nodo(6,7,-8).
nodo(7,-5,-8).
nodo(8,3,0).
nodo(9,3,-8).
ramo(0,1,5).
ramo(1,2,5).
ramo(1,7,3).
ramo(2,3,5).
ramo(3,0,5).
ramo(3,4,5).
ramo(3,8,3).
ramo(4,5,7).
ramo(5,6,13).
ramo(6,9,4).
ramo(8,9,8).
ramo(9,7,8).
trafego(0,1,1,0,0).
trafego(1,2,1,0,0).
trafego(1,7,1,0,0).
trafego(2,3,1,0,0).
trafego(3,0,1,0,0).
trafego(3,4,1,0,0).
trafego(3,8,1,0,0).
trafego(4,5,1,0,0).
trafego(5,6,1,0,0).
trafego(6,9,1,0,0).
trafego(8,9,1,0,0).
trafego(9,7,1,0,0).
ecoponto(1,vidro,1).
ecoponto(3,papel,3).
ecoponto(9,plastico,9).
lixo(papel,1,0).
lixo(plastico,1,1).
lixo(papel,1,6).
lixo(papel,1,8).
lixo(vidro,1,9).
personagem(peao,3,9).
