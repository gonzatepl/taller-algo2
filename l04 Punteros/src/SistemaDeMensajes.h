#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>

#include <vector>

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    //DESTRUCTOR EJ2)
    ~SistemaDeMensajes();

    //EJ3)
    void desregistrarJugador(int ip);

    Proxy* obtenerProxy(int id);

  private:
    ConexionJugador* _conns[4];
    //EJ5)
    vector<Proxy*> _punterosCreados;
};

#endif
