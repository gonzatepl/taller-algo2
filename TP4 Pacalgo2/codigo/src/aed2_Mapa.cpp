#include "aed2_Mapa.h"

Mapa::Mapa(uint largo, uint alto, Coordenada inicio, Coordenada llegada,
           set<Coordenada> cf, set<Coordenada> cp, set<Coordenada> cc): _inicio(inicio), _llegada(llegada) {

    //Inicializamos el tablero de largo * alto cuyos elementos son del tipo infoPosicion, los cuales (asumo que)
    //se inicializan por el constructor que tiene la estructura infoPosicion
    _tablero = vector<vector<infoPosicion>>(largo, vector<infoPosicion>(alto));

    _cantChocolates = 0;

    _agregarElementosAlTablero(cf, 'F', _cantChocolates);
    _agregarElementosAlTablero(cp, 'P', _cantChocolates);
    _agregarElementosAlTablero(cc, 'C', _cantChocolates);

}

uint Mapa::largo() const{
    return _tablero.size();
}

uint Mapa::alto() const{
    return _tablero[0].size();
}

Coordenada Mapa::inicio() const{
    return _inicio;
}

Coordenada Mapa::llegada() const{
    return _llegada;
}

set<Coordenada> Mapa::fantasmas() const{
    set<Coordenada> fantasmas;
    for(int i=0;i<_tablero.size();i++){
        for(int j=0;j<_tablero[i].size();j++){
            if(_tablero[i][j].fantasma){
                fantasmas.insert(make_pair(i+1,j+1));
            }
        }
    }
    return fantasmas;
}

set<Coordenada> Mapa::paredes() const{
    set<Coordenada> paredes;
    for(int i=0;i<_tablero.size();i++){
        for(int j=0;j<_tablero[i].size();j++){
            if(_tablero[i][j].pared){
                paredes.insert(make_pair(i+1,j+1));
            }
        }
    }
    return paredes;
}

set<Coordenada> Mapa::chocolates() const{
    set<Coordenada> chocolates;
    for(int i=0;i<_tablero.size();i++){
        for(int j=0;j<_tablero[i].size();j++){
            if(_tablero[i][j].chocolate){
                chocolates.insert(make_pair(i+1,j+1));
            }
        }
    }
    return chocolates;
}

uint Mapa::cantidadChocolates() const {
    return _cantChocolates;
}

uint Mapa::nroChocolate(uint i, uint j) const {
    return _tablero[i][j].nroChocolate;
}

bool Mapa::hayChocolate(uint i, uint j) const {
    return _tablero[i][j].chocolate;
}

bool Mapa::hayFantasma(uint i, uint j) const {
    return _tablero[i][j].fantasma;
}

bool Mapa::hayPared(uint i, uint j) const {
    return _tablero[i][j].pared;
}

void Mapa::_agregarElementosAlTablero(set<Coordenada> c, char tipo, uint& cantChocolates){
    for(Coordenada i : c){
        if(tipo == 'F'){
            _tablero[i.first-1][i.second-1].fantasma = true;
        }
        if(tipo == 'P'){
            _tablero[i.first-1][i.second-1].pared = true;
        }
        if(tipo == 'C'){
            _tablero[i.first-1][i.second-1].chocolate = true;
            _tablero[i.first-1][i.second-1].nroChocolate = cantChocolates;
            cantChocolates++;
        }
    }
}
