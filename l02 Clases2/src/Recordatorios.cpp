#include <iostream>
#include <list>
#include <vector>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}


// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    Fecha(int mes, int dia);
    int mes();
    int dia();

    void incrementar_dia();

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia): mes_(mes), dia_(dia) {}

int Fecha::mes() {
    return this->mes_; //Asumo por lado del cuadrado al ancho del rectangulo r_.Podría ser el alto también.
}

int Fecha::dia() {
    return this->dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia and igual_mes;
}
#endif

void Fecha::incrementar_dia(){
    if(dia_ == dias_en_mes(mes_)){
        mes_ = (mes_ + 1) % 12;
        dia_ = 1;
    }else{
        dia_++;
    }
}

// Ejercicio 11, 12

// Clase Horario

class Horario{
    public:
        #if EJ >= 11
        bool operator==(Horario o);
        #endif
        bool operator<(Horario h);
        Horario(uint hora, uint min);
        uint hora();
        uint min();

    private:
        uint hora_;
        uint min_;

};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {}

uint Horario::hora() {
    return this->hora_; //Asumo por lado del cuadrado al ancho del rectangulo r_.Podría ser el alto también.
}

uint Horario::min() {
    return this->min_;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

#if EJ >= 11
bool Horario::operator==(Horario o) {
    return  (this->hora_ == o.hora() &&
            this->min_ == o.min());
}
#endif

bool Horario::operator<(Horario h) {
     bool res = false;
     if(hora_ < h.hora()){
         res = true;
     }else if (hora_ == h.hora()){
         res = min_ < h.min();
     }
     return res;
 }

// Ejercicio 13

// Clase Recordatorio

using Mensaje = string;

class Recordatorio{

    public:
        Recordatorio(Fecha, Horario, Mensaje);
        Fecha f();
        Horario h();
        Mensaje m();

    private:
        Fecha f_;
        Horario h_;
        Mensaje m_;

};

Recordatorio::Recordatorio(Fecha f, Horario h, Mensaje m): f_(f), h_(h), m_(m) {}

Fecha Recordatorio::f() {
    return this->f_;
}

Horario Recordatorio::h() {
    return this->h_;
}

Mensaje Recordatorio::m() {
    return this->m_;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.m() << " @ " << r.f() << " " << r.h();
    return os;
}


// Ejercicio 14

// Clase Agenda

class Agenda {
    public:
        Agenda(Fecha fecha_inicial);
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();

        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();

    private:
        list<Recordatorio> recordatorios_;
        Fecha hoy_;

};

Agenda::Agenda(Fecha fecha_inicial): hoy_(fecha_inicial) {}

list<Recordatorio> Agenda::recordatorios_de_hoy(){
    list<Recordatorio> l;
    for(Recordatorio r: recordatorios_){
        if(r.f() == hoy_){
            l.push_back(r);
        }
    }

    //pasar lista a vector, ordenar vector, volver a pasar a lista, esto tiene su motivo en la imposbilidad de
    //poder ordenar tan fácilmente una lista como sucede con un vector.

    vector<Recordatorio> aux;
    for(Recordatorio x: l){
        aux.push_back(x);
    }

    for(int i=0; i < aux.size(); i++) {
        while (i > 0 && aux[i].h() < aux[i-1].h()) {
            Recordatorio k= aux[i];
            aux[i]= aux[i-1];
            aux[i-1] = k;
            i--;
        }
    }

    list<Recordatorio> lfinal;
    for(Recordatorio x: aux){
        lfinal.push_back(x);
    }

    return lfinal;
}

Fecha Agenda::hoy() {
    return this->hoy_;
}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    recordatorios_.push_back(rec);
}

void Agenda::incrementar_dia() {
    hoy_.incrementar_dia();
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;
    for(Recordatorio r: a.recordatorios_de_hoy()){
        os << r <<endl;
    }
    return os;
}
