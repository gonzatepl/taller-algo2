#include <utility>

using namespace std;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

class Juego {
    public:
    Juego(uint casilleros, Pos pos_inicial);
    Pos posicion_jugador();
    uint turno_actual();
    uint casilleros();
    uint movimientos_efecto_pocion();
    uint turnos_efecto_pocion();
    //uint turno();

    void mover_jugador(char dir);
    void ingerir_pocion(uint movimientos, uint turnos);

    private:
        Pos posicion_jugador_;
        uint casilleros_;
        uint turno_actual_;
        uint movimientos_; //AGREGADO
        uint turnos_; //AGREGADO



};

Juego::Juego(uint casilleros, Pos pos_inicial): casilleros_(casilleros), posicion_jugador_(pos_inicial){
    turno_actual_=0;    //AGREGADO
    movimientos_=0;    //AGREGADO
    turnos_=0;         //AGREGADO
}

uint Juego::casilleros(){
    return this->casilleros_;
}

Pos Juego::posicion_jugador(){
    return this->posicion_jugador_;
}

uint Juego::movimientos_efecto_pocion(){   //AGREGADO
    return this->movimientos_;             //AGREGADO
}                                          //AGREGADO

uint  Juego::turnos_efecto_pocion(){     //AGREGADO
    return this->turnos_;                //AGREGADO
}                                        //AGREGADO

uint Juego::turno_actual(){
    return this->turno_actual_;
}

//Por ahora asumo que no tengo que preocuparme por las medidas del tablero
void Juego::mover_jugador(char dir){
    //uint cant_mov;
    //if (turnos_efecto_pocion()>0){
    //    cant_mov=movimientos_efecto_pocion();
    //    turnos_--;
    //}else{
    //    cant_mov=1;
    //}

    switch (dir){
        case '^': if (posicion_jugador_.first -1 >=0){
            posicion_jugador_ =
                    make_pair(posicion_jugador_.first-1, posicion_jugador_.second );
        }
        break; //NO ES BUENA PRACTICA MANTENER LOS BREAKS, O AL MENOS NO SUELE SERLO EN GENERAL
        case 'v': if (posicion_jugador_.first +1 <= casilleros_-1){
            posicion_jugador_ =
                    make_pair(posicion_jugador_.first +1, posicion_jugador_.second );
        }
        break; //NO ES BUENA PRACTICA MANTENER LOS BREAKS, O AL MENOS NO SUELE SERLO EN GENERAL
        case '<': if (posicion_jugador_.second +1 <= casilleros_-1){
            posicion_jugador_ =
                    make_pair(posicion_jugador_.first, posicion_jugador_.second+1);
        }
        break; //NO ES BUENA PRACTICA MANTENER LOS BREAKS, O AL MENOS NO SUELE SERLO EN GENERAL
        case '>':  if (posicion_jugador_.second -1 >= 0){
            posicion_jugador_ =
                    make_pair(posicion_jugador_.first, posicion_jugador_.second-1);
        }
        break; //NO ES BUENA PRACTICA MANTENER LOS BREAKS, O AL MENOS NO SUELE SERLO EN GENERAL
    }

    turno_actual_++;

    if(turnos_efecto_pocion()>0){

    }
}

void Juego::ingerir_pocion(uint movimientos, uint turnos){
    movimientos_ += movimientos;
    turnos_ += turnos;
    turno_actual_++;

}
