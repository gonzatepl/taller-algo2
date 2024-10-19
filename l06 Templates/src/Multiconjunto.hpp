#ifndef MULTC_HPP
#define MULTC_HPP

#include "Diccionario.hpp"
#include <vector>

using namespace std;

template<class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario<T, int> _elementos;
};

template<class T>
Multiconjunto<T>::Multiconjunto() {
    _elementos = Diccionario<T, int>();
}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if(_elementos.def(x)){
        _elementos.definir(x, _elementos.obtener(x)+1);
    }else{
        _elementos.definir(x, 1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const{
    int res = 0;
    if (_elementos.def(x)){
        res = _elementos.obtener(x);
    }
    return res;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const {
    bool res = true;
    for(T x: _elementos.claves()){
        res = res && this->ocurrencias(x) <= otro.ocurrencias(x);
    }
    return res;
}

#endif