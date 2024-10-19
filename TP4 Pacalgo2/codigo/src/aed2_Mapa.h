#ifndef AED2_MAPA_H
#define AED2_MAPA_H

#include<vector>
#include <set>
#include "Tipos.h"

using namespace std;
using uint = unsigned int;

class Mapa{
public:
    Mapa(uint largo, uint alto, Coordenada inicio, Coordenada llegada,
         set<Coordenada> cf, set<Coordenada> cp, set<Coordenada> cc);
    uint largo() const;
    uint alto() const;
    Coordenada inicio() const;
    Coordenada llegada() const;
    set<Coordenada> fantasmas() const;
    set<Coordenada> paredes() const;
    set<Coordenada> chocolates() const;
    uint cantidadChocolates() const;
    bool hayFantasma(uint i, uint j) const;
    bool hayPared(uint i, uint j) const;
    bool hayChocolate(uint i, uint j) const;
    uint nroChocolate(uint i, uint j) const;

private:
    void _agregarElementosAlTablero(set<Coordenada> c, char tipo,  uint& cantChocolates); // ,
    vector<vector<infoPosicion>> _tablero;
    Coordenada _inicio;
    Coordenada _llegada;
    uint _cantChocolates; // VER DE REEMPLAZAR CON CARDINAL DE CONJUNTO DE CHOCOLATES, Y MOVERLO A PUBLIC, NECESITAMOS TENERLO VISIBLE

};

#endif // AED2_MAPA_H