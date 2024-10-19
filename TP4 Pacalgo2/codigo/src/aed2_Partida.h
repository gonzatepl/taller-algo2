#ifndef AED2_PARTIDA_H
#define AED2_PARTIDA_H

#include<vector>
#include "Tipos.h"
#include "aed2_Mapa.h"

using namespace std;
using uint = unsigned int;

class Partida{
public:
    Partida(const Mapa& mapa);
    Partida& operator=(const Partida& p); //Operador de asignacion de Partida
    void moverJugador(Direccion d);
    const Mapa& mapa() const; //Para devolverlo en O(1)
    Coordenada posicionActualJugador() const;
    set<Coordenada> chocolates() const;
    uint cantMovimientos() const;
    uint cantMovimientosInmunes() const;
    bool gano() const;
    bool perdio() const;

private:
    Coordenada _siguienteMovimiento(Direccion d);
    Coordenada _posMovimiento(Coordenada c, Direccion d);
    bool _tieneFantasmaCerca() const;
    int _max(int i, int j);
    int _min(int i, int j);

    const Mapa _mapaPartida; //LA VARIABLE PRIVADA _mapaPartida DEBE SER UNA REFERENCIA CONSTANTE, DE FORMA TAL QUE SE PUEDA ASIGNAR EN O(1)
    vector<bool> _chocolatesPartida;
    uint _cantMovimientos;
    Coordenada _posActualJugador;
    uint _movimientosInmunes;
};

#endif // AED2_PARTIDA_H