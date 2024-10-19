//
// Created by jm_ba on 6/21/2021.
//

#include "Fichin.h"

Fichin::Fichin(const Mapa &mapa) : _hayPersonaJugando(false), _mapaRanking(mapa), _partidaActual(Partida(mapa)) {

}

Mapa Fichin::mapa() const {
    return _mapaRanking;
}

bool Fichin::alguienJugando() const {
    return _hayPersonaJugando;
}

Jugador Fichin::jugadorActual() const {
    return _infoJugador.first;
}

Partida Fichin::partidaActual() const {
    return _partidaActual;
}

string_map<Puntaje> Fichin::ranking() const{
    return _ranking;
}

Partida Fichin::nuevaPartida(Jugador j) {
    this->_infoJugador = make_pair(j, 0);
    this->_hayPersonaJugando = true;
    this->_jugadores.insert(j);
    this->_partidaActual = Partida(_mapaRanking); //UTILIZACION DEL OPERADOR = DE PARTIDA
    return this->_partidaActual;
}

Partida Fichin::mover(Direccion d) {
    _partidaActual.moverJugador(d);
    this->_infoJugador.second++;
    if (_partidaActual.perdio()) {
        this->_hayPersonaJugando = false;
        this->_infoJugador = make_pair("", 0);
    }

    if (_partidaActual.gano()) {
        if ((_ranking.count(_infoJugador.first) == 0)
            || (_ranking.count(_infoJugador.first) > 0 &&
                (_infoJugador.second < _ranking.at(_infoJugador.first)))) {    //ANTES ESTABA >
            pair<Jugador,Puntaje> jugador = make_pair(_infoJugador.first,_infoJugador.second);
            _ranking.insert(jugador); //PROBLEMA CON CONST
        }
        this->_infoJugador = make_pair("", 0);
        this->_hayPersonaJugando = false;
    }
    return Partida(_mapaRanking);
}

pair<Jugador, Puntaje> Fichin::objetivo() const {
    //Empezar a iterar directo con _JugadorActual
    string var = "";
    string anterior = "";
    int j = 0;
    for (string i : _jugadores) {
        if (j == 0) {
            anterior = i;
            var = anterior;
            j++;
        } else {
            if (!var.empty()) {
                if (_ranking.at(i) < _ranking.at(_infoJugador.first)) {
                    //Esto busca el mejor puntaje que le gana
                    if (_ranking.at(var) < _ranking.at(i)) {
                        var = i;
                     }
                }
            }
        }
    }
    return pair<Jugador, Puntaje>(var, _ranking.at(var));
}

