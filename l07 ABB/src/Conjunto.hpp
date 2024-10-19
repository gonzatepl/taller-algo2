
template <class T>
Conjunto<T>::Conjunto() {
    _cardinal = 0;
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() {
    Nodo * actual = _raiz;
    if(actual != nullptr && cardinal()>0){
        _destruir(actual);
    }
    _raiz = nullptr; //POR LAS DUDAS, QUIZAS NO VAYA

}

template <class T>
void Conjunto<T>::_destruir(Nodo * n){
    if(n->izq != nullptr){
        _destruir(n->izq);
    }
    if(n->der != nullptr){
        _destruir(n->der);
    }
    delete n;
    _cardinal--;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    bool res = false;
    Nodo* r = _raiz;
    if(cardinal()>0){
        while(r != nullptr && r->valor != clave){
            if (r->valor > clave){
                r = r->izq;
            } else {
                r = r->der;
            }
        }
        res = res || r != nullptr;
    }
    return res;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    Nodo* iterar = _raiz;
    Nodo* elemPadre = nullptr;
    if(!pertenece(clave)){
        Nodo *nuevo = new Nodo(clave);
        if (cardinal() == 0) {
            _raiz = nuevo;
        } else {
            while (iterar != nullptr) {
                elemPadre = iterar;
                nuevo->padre = elemPadre;
                if (iterar->valor > clave) {
                    iterar = iterar->izq;
                } else {
                    iterar = iterar->der;
                }
            }
            if(elemPadre->valor > clave) {
                nuevo->padre->izq = nuevo;
                iterar = nuevo;
            } else {
                nuevo->padre->der = nuevo;
                iterar = nuevo;
            }
        }
        _cardinal++;
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* iterar = _raiz;
    while(iterar != nullptr && iterar->valor != clave){
        if (iterar->valor > clave){
            iterar = iterar->izq;
        } else {
            iterar = iterar->der;
        }
    }
    //SI EL ELEMENTO QUE QUIERO ELIMINAR SE ENCUENTRA EN EL CONJUNTO
    if(iterar != nullptr){
        //3 Casos
        if(iterar->izq == nullptr && iterar->der == nullptr){
            //ES HOJA
            _borroHoja(iterar);
        } else if (iterar->izq == nullptr || iterar->der == nullptr){
            //TIENE UN SOLO HIJO
            _borroPadreUnicoHijo(iterar);
        } else {
            //TIENE DOS HIJOS
            //BUSCAMOS EL PREDECESOR INMEDIATO: EL ELEMENTO MÁS A LA DERECHA, DE LOS DE LA IZQUIERA DE _ACTUAL
            Nodo* predI = iterar->izq; // SI LLEGAMOS HASTA ACA, SABEMOS QUE ESTO NO SE INDEFINE
            while(predI->der != nullptr){
                predI = predI->der;
            }
            //COPIAMOS EL PREDECESOR INMEDIATO EN EL LUGAR DEL NODO QUE QUEREMOS BORRAR (LO BORRAMOS REEMPLAZANDOLO CON predI)
            iterar->valor = predI->valor;
            iterar = predI;
            //BORRAMOS predI: REPETIMOS EL PROCESO DE ARRIBA PERO AHORA CON predI
            if(iterar->izq == nullptr && iterar->der == nullptr){
                //PRED ES HOJA
                _borroHoja(iterar);
            } else {
                //PRED TIENE UN SOLO HIJO
                _borroPadreUnicoHijo(iterar);
            }
        }
        _cardinal--;
    }
}

template <class T>
void Conjunto<T>::_borroHoja(Nodo* actual){
    if(actual->padre != nullptr){
        //NO ESTOY ELIMINANDO A LA RAIZ
        if (actual->padre->izq == actual){
            //ERA HIJO POR IZQ
            actual->padre->izq = nullptr;
            delete actual;
        } else {
            //ERA HIJO POR DER
            actual->padre->der = nullptr;
            delete actual;
        }
    } else {
        delete actual;
        //delete r;
    }
}

template <class T>
void Conjunto<T>::_borroPadreUnicoHijo(Nodo * actual) {
    if (actual->padre != nullptr) {
        //NO ESTOY ELIMINANDO A LA RAIZ
        if (actual->izq == nullptr) {
            //TIENE UN HIJO A LA DERECHA
            if(actual->padre->izq == actual){
                //ES HIJO A LA IZQUIERDA
                actual->padre->izq = actual->der;
            } else {
                //ES HIJO A LA DERECHA
                actual->padre->der = actual->der;
            }
            actual->der->padre = actual->padre;
        } else {
            //TIENE UN HIJO A LA IZQUIERDA
            if(actual->padre->izq == actual){
                //ES HIJO A LA IZQUIERDA
                actual->padre->izq = actual->izq;
            } else {
                //ES HIJO A LA DERECHA
                actual->padre->der = actual->izq;
            }
            actual->izq->padre = actual->padre;
        }
    } else {
        if (actual->izq == nullptr) {
            //LA RAIZ TIENE UN HIJO A LA DERECHA
            actual->der->padre = nullptr;
            _raiz = actual->der;
        } else {
            //LA RAIZ TIENE UN HIJO A LA IZQUIERDA
            actual->izq->padre = nullptr;
            _raiz = actual->izq;
        }

    }
    delete actual;
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    while(actual != nullptr && actual->valor != clave){
        if (actual->valor > clave){
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }
    T& sig = actual->valor;
    //ASUMIMOS QUE EL ELEMENTO CLAVE SE ENCUENTRA EN EL ARBOL: actual = clave
    if(actual->der != nullptr){
        //EL NODO TIENE SUBARBOL DERECHO: DEVOLVEMOS EL MINIMO DE ESTE
        actual = actual->der;
        while (actual->izq != nullptr){
            actual = actual->izq;
        }
        sig = actual->valor;
    } else {
        //EL NODO NO TIENE SUBARBOL DERECHO, SEGUIMOS SUBIENDO HASTA DAR CON EL SIGUIENTE (Algoritmo de Cormen)
        Nodo* arriba = actual->padre;
        while (arriba != nullptr && actual==arriba->der){
            actual = arriba;
            arriba = arriba->padre;
        }
        sig = arriba->valor;
    }
    //_setearActualEnRaiz();
    return sig;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* r = _raiz;
    while (r->izq != nullptr){
        r = r->izq;
    }
    return r->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* r = _raiz;
    while (r->der != nullptr){
        r = r->der;
    }
    return r->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

//MOSTRARLO DE FORMA RECURSIVA
template <class T>
void Conjunto<T>::mostrar(std::ostream& o) const {
   Nodo* n = _raiz;
    //LA IDEA ES MOSTRARLOS EN ORDEN CRECIENTE, DESDE EL MINIMO, HASTA EL MÁXIMO (IZQ-DER DEL ARBOL)
    o << "[ ";
    _mostrar(o, n);
    o << " ]" << endl;
}

template <class T>
void Conjunto<T>::_mostrar(std::ostream& o, Nodo* n){
    if(n->izq == nullptr && n->der == nullptr){
        //EL NODO ES HOJA, MUESTRO SU ELEMENTO
        o<<n->valor<< " " <<endl;
    } else if (n->izq == nullptr || n->der == nullptr){
        //EL NODO TIENE UN UNICO HIJO
        if(n->der == nullptr){
            //EL HIJO DEL NODO ES EL DE LA IZQUIERDA
            _mostrar(o, n->izq);
        } else {
            //EL HIJO DEL NODO ES EL DE LA DERECHA
            _mostrar(o, n->der);
        }
    } else {
        //EL NODO TIENE AMBOS HIJOS
        _mostrar(o, n->izq);
        _mostrar(o, n->der);
    }
}


//MOSTRAR MAS SIMPLE
//void inorder(node* t)
//    {
//        if(t == NULL)
//            return;
//        inorder(t->left);
//        cout << t->data << " ";
//        inorder(t->right);
//    }