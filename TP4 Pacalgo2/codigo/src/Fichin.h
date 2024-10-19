

#ifndef TP4_PACALGO2_SRC_FICHIN_H_
#define TP4_PACALGO2_SRC_FICHIN_H_

#include "Tipos.h"
#include "aed2_Mapa.h"
#include "aed2_Partida.h"
#include "string_map.h"


class Fichin {

 public:
  Fichin(const Mapa& mapa);

  Mapa mapa() const;

  bool alguienJugando() const;

  Jugador jugadorActual() const;

  Partida partidaActual() const;

  string_map<Puntaje> ranking() const;

  Partida nuevaPartida(Jugador j);

  Partida mover(Direccion d);

  pair<Jugador, Puntaje> objetivo() const;

 private:
  // Completar
  bool _hayPersonaJugando;
  string_map<Puntaje> _ranking;
  Partida _partidaActual;
  const Mapa _mapaRanking;
  set<Jugador> _jugadores;
  pair<Jugador,Puntaje> _infoJugador;
};

#endif //TP4_PACALGO2_SRC_FICHIN_H_


