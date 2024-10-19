#include "SistemaDeMensajes.h"
#include "Proxy.h"

//Revisar la definición de la clase SistemaDeMensajes.
//Notar que por cuestiones de eficiencia, los jugadores se guardan como un arreglo de ConexionJugador*

//El sistema de mensajes empieza sin tener ningún jugador registrado.
SistemaDeMensajes::SistemaDeMensajes() : _conns() {
    //Es una buena práctica representar a los punteros que no tienen ninguna posición de memoria con nullptr
    for(int i=0;i<4;i++){
        _conns[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip)  {
    if(registrado(id)){
		desregistrarJugador(id);
	}	
	_conns[id] = new ConexionJugador(ip);
}

bool SistemaDeMensajes::registrado(int id)  const{
    return _conns[id] != nullptr;
}

//requiere que esté registrado el jugador del identificador parámetro.
void SistemaDeMensajes::enviarMensaje(int id, string mensaje)  {
    _conns[id]->enviarMensaje(mensaje); // Similar a (*_conns[id]).enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip(); // Similar a (*_conns[id]).ip();
}

//DESTRUCTOR EJ2)
SistemaDeMensajes::~SistemaDeMensajes() {
    for(int i=0;i<4;i++){
        delete _conns[i];
    }
    //EJ 5)
    for(Proxy* x : _punterosCreados){
        delete x;
    }


}

//EJ3)

void SistemaDeMensajes::desregistrarJugador(int id){
    delete _conns[id];
    _conns[id] = nullptr;
}

//EJ4)
//CREO que se está perdiendo memoria, ver si no hay que hacer un delete de p en algún momento, o si en realidad lo
//que sucede es que la memoria que se reserva en heap al hacer el new sobre p, pasa a estar alojada en el vector
Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    //Proxy* p = new Proxy(_conns[id]);
    Proxy* p = new Proxy(&_conns[id]); //Para ejercicio 6
    //Ej5)
    _punterosCreados.push_back(p);
    return p;
}





