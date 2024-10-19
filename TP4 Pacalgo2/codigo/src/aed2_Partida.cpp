#include "aed2_Partida.h"

 Partida::Partida(const Mapa& mapa): _mapaPartida(mapa), _cantMovimientos(0){
    uint cantChocolates = mapa.cantidadChocolates();
    _chocolatesPartida = vector<bool>(cantChocolates, true); //Inicializamos la función característica del conjunto de chocolates
    Coordenada inicio = mapa.inicio();

    _posActualJugador = inicio;

    if(mapa.hayChocolate(inicio.first-1, inicio.second-1)){
        _movimientosInmunes = 10;
        uint nroChocolateInicio = _mapaPartida.nroChocolate(inicio.first-1, inicio.second-1);
        _chocolatesPartida[nroChocolateInicio] = false;
    } else {
        _movimientosInmunes = 0;
    }
}

Partida& Partida::operator=(const Partida & d) {
    //EL MAPA NUNCA CAMBIA, POR ESTE MOTIVO, NO NECESITAMOS REASIGNARLO
    this->_chocolatesPartida = d._chocolatesPartida;
    this->_cantMovimientos = d._cantMovimientos;
    this->_movimientosInmunes = d._movimientosInmunes;
    this->_posActualJugador = d._posActualJugador;
}

void Partida::moverJugador(Direccion d) {
    Coordenada sig = _siguienteMovimiento(d);
    if(sig != _posActualJugador){
        uint nroChoc = _mapaPartida.nroChocolate(sig.first-1, sig.second-1);
        _cantMovimientos++;
        if(_mapaPartida.hayChocolate(sig.first-1, sig.second-1) && _chocolatesPartida[nroChoc]){
            _movimientosInmunes = 10;
            _chocolatesPartida[nroChoc] = false;
        } else {
            if(_movimientosInmunes>0){
                _movimientosInmunes--;
            }
        }
    }
    _posActualJugador = sig;
}

const Mapa& Partida::mapa() const{
    return _mapaPartida; //AL DEVOLVER REFERENCIA AL MAPA, EL COSTO DEL COPIADO DEL MAPA DE PARTIDA A PARTIDA, ES O(1) (SE COPIA LA REF)
}

Coordenada Partida::posicionActualJugador() const{
    return _posActualJugador;
}

uint Partida::cantMovimientos() const{
    return _cantMovimientos;
}

uint Partida::cantMovimientosInmunes() const{
    return _movimientosInmunes;
}

set<Coordenada> Partida::chocolates() const {
    set<Coordenada> chocolates;
    for(int i=0;i<_mapaPartida.largo();i++){
        for(int j=0;j<_mapaPartida.alto();j++){
            uint nroChoc = _mapaPartida.nroChocolate(i, j);
            if(_mapaPartida.hayChocolate(i, j) && _chocolatesPartida[nroChoc]){
                chocolates.insert(make_pair(i+1,j+1));
            }
        }
    }
    return chocolates;
}

bool Partida::gano() const {
    return _posActualJugador == _mapaPartida.llegada();
}

bool Partida::perdio() const {
    return !(this->gano()) && _movimientosInmunes == 0 && _tieneFantasmaCerca();
}

Coordenada Partida::_siguienteMovimiento(Direccion d) {
    Coordenada res;
    //Coordenada inicio = _mapaPartida.inicio();
    uint alto = _mapaPartida.alto();
    uint largo = _mapaPartida.largo();
    Coordenada proxMovimiento = _posMovimiento(_posActualJugador, d);
        // !(_mapaPartida.tablero()[inicio.first][inicio.second].pared))
    if(1 <= proxMovimiento.first && proxMovimiento.first <= largo &&
       1 <= proxMovimiento.second && proxMovimiento.second <= alto &&
       !(_mapaPartida.hayPared(proxMovimiento.first-1, proxMovimiento.second-1))){
        res = proxMovimiento;
    } else {
        res = _posActualJugador;
    }
    return res;
}

Coordenada Partida::_posMovimiento(Coordenada c, Direccion d) {
    Coordenada res;
    if(d==ARRIBA){
        res = make_pair(c.first, c.second + 1);
    } else if (d==ABAJO){
        res = make_pair(c.first, c.second - 1);
    } else if (d==IZQUIERDA){
        res = make_pair(c.first - 1, c.second);
    } else {
        //(d==DERECHA)
        res = make_pair(c.first + 1, c.second);
    }
    return res;
}

bool Partida::_tieneFantasmaCerca() const {
    bool res = false;
    uint alto = _mapaPartida.alto() -1; //SE LE RESTA 1 POR LA INDEXACION DEL TABLERO
    uint largo = _mapaPartida.largo() -1; //SE LE RESTA 1 POR LA INDEXACION DEL TABLERO
    Coordenada p = _posActualJugador;

    int posI = p.first   - 1; //SE LE RESTA 1 POR LA INDEXACION DEL TABLERO
    int posJ = p.second  - 1; //SE LE RESTA 1 POR LA INDEXACION DEL TABLERO
    pair<int,int> distManh[24] = { make_pair(posI-3, posJ), make_pair(posI-2, posJ), make_pair(posI-1, posJ),
                                   make_pair(posI+1, posJ), make_pair(posI+2, posJ), make_pair(posI+3, posJ),
                                   make_pair(posI, posJ-3), make_pair(posI, posJ-2), make_pair(posI, posJ-1),
                                   make_pair(posI, posJ+1), make_pair(posI, posJ+2), make_pair(posI, posJ+3),
                                   make_pair(posI-1, posJ+2), make_pair(posI+1, posJ+2),
                                   make_pair(posI-1, posJ-2), make_pair(posI+1, posJ-2),
                                   make_pair(posI-2, posJ+1), make_pair(posI-1, posJ+1),
                                   make_pair(posI+1, posJ+1), make_pair(posI+2, posJ+1),
                                   make_pair(posI-2, posJ-1), make_pair(posI-1, posJ-1),
                                   make_pair(posI+1, posJ-1), make_pair(posI+2, posJ-1)};
    for(int i=0;i<24; i++){
        int pi = distManh[i].first;
        int pj = distManh[i].second;
        if(0 <= pi && pi <= largo &&
           0 <= pj && pj <= alto &&
           _mapaPartida.hayFantasma(pi, pj)){
            res = res || true;
        }
    }

    return res;
}

int Partida::_max(int i, int j){
    int res = i;
    if(j>i){
        res = j;
    }
    return res;
}

int Partida::_min(int i, int j){
    int res = i;
    if(j<i){
        res = j;
    }
    return res;
}


