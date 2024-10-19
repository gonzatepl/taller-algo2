#include "aed2_Fichin.h"

// Completar
aed2_Fichin::aed2_Fichin(Nat largo,Nat alto,Coordenada inicio,Coordenada llegada,set<Coordenada> paredes,
                         set<Coordenada> fantasmas,set<Coordenada> chocolates):
                         _fichin(Mapa(largo,alto,inicio,llegada,fantasmas,paredes,chocolates)) {

}

void aed2_Fichin::nuevaPartida(Jugador j) {
    _fichin.nuevaPartida(j);
}

ResultadoMovimiento aed2_Fichin::mover(Direccion d) {
  ResultadoMovimiento i;
  _fichin.mover(d);
  if(_fichin.partidaActual().perdio()){
    i = PERDIO;
  } else if(_fichin.partidaActual().gano()){
    i = GANO;
  }else{
    i = SIGUE;
  }
  return i;
}

bool aed2_Fichin::alguienJugando() const{
  return _fichin.alguienJugando();
}

Jugador aed2_Fichin::jugadorActual() const {
  return _fichin.jugadorActual();
}
map<Jugador, Puntaje> aed2_Fichin::ranking() const {  //Revisar no es diccTrie
    map<Jugador, Puntaje> mapa;
    //set<Jugador> jugadores = _fichin.ranking().claves();
    for(auto i : _fichin.ranking().claves()){
        mapa.insert(make_pair(i,_fichin.ranking().at(i)));
    }

    return mapa;
}
pair<Jugador, Puntaje> aed2_Fichin::objetivo() const {
  return _fichin.objetivo();
}
Coordenada aed2_Fichin::jugador() const {
  return _fichin.partidaActual().posicionActualJugador();
}
Nat aed2_Fichin::cantidadMovimientos() const {
  return _fichin.partidaActual().cantMovimientos();
}
Nat aed2_Fichin::inmunidad() const {
  return _fichin.partidaActual().cantMovimientosInmunes();
}
Nat aed2_Fichin::largo() const {
  return _fichin.mapa().largo();
}
Nat aed2_Fichin::alto() const {
  return _fichin.mapa().alto();
}
Coordenada aed2_Fichin::inicio() const {
  return _fichin.mapa().inicio();
}
Coordenada aed2_Fichin::llegada() const {
  return _fichin.mapa().llegada();
}
set<Coordenada> aed2_Fichin::paredes() const {
  return _fichin.mapa().paredes();
}
set<Coordenada> aed2_Fichin::fantasmas() const {
  return _fichin.mapa().fantasmas();
}
set<Coordenada> aed2_Fichin::chocolatesIniciales() const {
  return _fichin.mapa().chocolates();
}
set<Coordenada> aed2_Fichin::chocolatesActuales() const {
  return _fichin.partidaActual().chocolates();
}



