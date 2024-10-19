#ifndef TIPOS_H
#define TIPOS_H

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

using Nat = unsigned int;

using Coordenada = pair<Nat, Nat>;

using Jugador = string;

using Puntaje = Nat;

enum Direccion {
    ARRIBA, ABAJO, IZQUIERDA, DERECHA
};

enum ResultadoMovimiento {
    SIGUE, GANO, PERDIO
};

struct infoPosicion{
    infoPosicion(): fantasma(false), pared(false), chocolate(false), nroChocolate(-1){}
    bool fantasma;
    bool pared;
    bool chocolate;
    int nroChocolate;
}; // AGREGAMOS infoPosicion para poder acceder desde mapa


#endif // TIPOS_H
