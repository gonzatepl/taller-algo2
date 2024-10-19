#include "Lista.h"

Lista::Lista() {
    _longitud = 0;
    _actual = nullptr;

}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    _destruir();
}

//AUXILIAR DEL DESTRUCTOR
void Lista::_destruir() {
    if (longitud()>0){
        posicionarAdelante();
        while (_actual != nullptr) {
            Nodo* temp = _actual;
            _actual= _actual->siguiente;
            _longitud--; //A medida que se destruye la lista, también 'se destruye' su longitud
            delete temp;
        }
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    Nodo* temp = aCopiar._actual;
    int x = 0;
    this->_destruir();
    //La idea es que cada vez que estoy igualando una lista a otra, la primera tiene que estar en 0, antes de tomar los nuevos valores.
    while(x<aCopiar.longitud()){
        this->agregarAtras(temp->valor);
        temp = temp->siguiente;
        x++;
    }
    return *this;
}

void Lista::posicionarAdelante() {
    while (_actual->anterior != nullptr) {
        _actual = _actual->anterior;
    }
}

void Lista::posicionarAtras() {
    while (_actual->siguiente != nullptr) {
        _actual = _actual->siguiente;
    }
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo();
    nuevo->valor = elem;
    if(longitud()==0){
        _actual = nuevo;
        _actual->anterior=nullptr;
        _actual->siguiente=nullptr;
    }else{
        posicionarAdelante();
        nuevo->siguiente = this->_actual;
        nuevo->siguiente->anterior = nuevo;
        this->_actual = nuevo;
        _actual->anterior=nullptr;
    }
    this->_longitud++;
    //delete nuevo;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo();
    nuevo->valor = elem;
    if(longitud()==0){
        _actual = nuevo;
        _actual->anterior=nullptr;
        _actual->siguiente=nullptr;
    }else{
        posicionarAtras();
        nuevo->anterior = this->_actual;
        nuevo->anterior->siguiente = nuevo;
        this->_actual = nuevo;
        _actual->siguiente=nullptr;
    }
    this->_longitud++;
    //Lo de abajo es simplemente una 'convención', hardcodeo para el operador asignacion
    posicionarAdelante();
    //delete nuevo;
}

//ASUMO QUE EL PRIMER ELEMENTO DE LA LISTA ES EL 0 (i entre 0...longitud-1, ambos inclusivos, es la precondicion)
//OBS: EL IF GENERAL QUE PREGUNTA POR LONGITUD()>0 ES PORQUE NO SE ASUME COMO PRECONDICIÓN EN LOS TESTS, ALGO QUE DEBERÍA SERLO
void Lista::eliminar(Nat i) {
    posicionarAdelante();
    Nodo* actual = _actual;
    Nodo* prox = _actual->siguiente;
    Nodo* pre = _actual->anterior;
    int x = 0;
    while(x<i){
        pre = actual;
        actual = actual->siguiente;
        prox = actual->siguiente;
        x++;
    }
    if (pre != nullptr){
        pre->siguiente = prox;
    }else{
        _actual = prox;
    }
    if (prox != nullptr){
        prox->anterior = pre;
    }
    delete(actual);
    this->_longitud--;
}

int Lista::longitud() const {
    return _longitud;
}


const int& Lista::iesimo(Nat i) const {
    Nodo* actual = this->_actual;
    int x = 0;
    while(x<i){
        actual = actual->siguiente;
        x++;
    }
    int & res = actual->valor;
    return res;
    //assert(false);
}

int& Lista::iesimo(Nat i) {
    posicionarAdelante();
    Nodo* actual = this->_actual;
    int x = 0;
    while(x<i){
        actual = actual->siguiente;
        x++;
    }
    int & res = actual->valor;
    return res;
    //assert(false);
}

void Lista::mostrar(ostream& o) {
    posicionarAdelante();
    Nodo* actual = _actual;
    int x = 0;
    o << "[";
    while(x<longitud()){
        o << actual->valor << ", ";
        actual = actual->siguiente;
        x++;
    }
    o<< "]" << endl;
}
