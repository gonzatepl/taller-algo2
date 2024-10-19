#ifndef DICC_HPP
#define DICC_HPP

#include <vector>
using namespace std;

template<class T1, class T2>
class Diccionario {
public:
    Diccionario();
    //~Diccionario();
    void definir(T1 k, T2 v);
    bool def(T1 k) const;
    T2 obtener(T1 k) const;
    vector<T1> claves() const;

private:
    struct Asociacion {
        Asociacion(T1 k, T2 v): clave(k), valor(v) {};
        T1 clave;
        T2 valor;
    };
    vector<Asociacion> _asociaciones;
    vector<T1> _claves;

};

template<class T1, class T2>
Diccionario<T1,T2>::Diccionario() {
    _asociaciones = vector<Asociacion>();
}

//template<class T1, class T2>
//Diccionario<T1,T2>:: ~Diccionario() {
//    for(int i=0; i<_asociaciones.size(); i++){
//        //delete _asociaciones[i];
//    }
//}

template<class T1, class T2>
void Diccionario<T1,T2>::definir(T1 k, T2 v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return; //NO ES LA MEJOR PRÁCTICA PEEEERO YA VINO ASI ARMADA EN Diccionario.cpp (*)
        }
    }
    _asociaciones.push_back(Asociacion(k,v));
    //(*)la forma de solucionar esto, es dividir en casos, si ya está definido, se actualiza sign en for, si no, pushback
}

template<class T1, class T2>
bool Diccionario<T1,T2>::def(T1 k) const {
    bool res = false;
    for(int i=0; i<_asociaciones.size();i++){
        if (_asociaciones[i].clave == k){
            res = true;
        }
    }
    return res;
}

template<class T1, class T2>
T2 Diccionario<T1,T2>::obtener(T1 k) const {
    T2 res;
    for(int i = 0; i<_asociaciones.size();i++){
        if (_asociaciones[i].clave==k){
            res = _asociaciones[i].valor;
        }
    }
    return res;
}

template<class T1, class T2>
vector<T1> Diccionario<T1,T2>::claves() const{
    vector<T1> clavesSinOrdenar = vector<T1>();
    for(int i=0; i<_asociaciones.size();i++){
        clavesSinOrdenar.push_back(_asociaciones[i].clave);
    }

    vector<T1> clavesOrdenadas = vector<T1>();
    while(clavesSinOrdenar.size()>0){
        T1 minimo = clavesSinOrdenar[0];
        int posMinimo = 0;
        for(int i = 0; i<clavesSinOrdenar.size();i++){
            if(minimo>clavesSinOrdenar[i]){
                minimo = clavesSinOrdenar[i];
                posMinimo = i;
            }
        }
        clavesOrdenadas.push_back(minimo);
        clavesSinOrdenar.erase(clavesSinOrdenar.begin()+posMinimo);
    }

    return clavesOrdenadas;
}



#endif