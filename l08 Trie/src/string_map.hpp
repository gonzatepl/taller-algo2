template <typename T>
string_map<T>::string_map(){
    _raiz = nullptr;
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    //COPIA EXACTA DEL CODIGO DEL DESTRUCTOR, LA IDEA ES DEJAR COMPLETAMENTE VACIO EL TRIE DEL CONTEXTO AL QUE QUEREMOS
    //ASIGNARLE EL VALOR DEL TRIE PASADO COMO PARAMETRO.
    //DEFINITIVAMENTE NO ES LA MEJOR FORMA, VER DE OPTIMIZARLO EN UN FUTURO
    if(this->size()>0){
        for(int i=0; i<_raiz->hijosNoNulos.size(); i++){
            _destruirRecursivo(_raiz->siguientes[_raiz->hijosNoNulos[i]]);
        }
    }
    this->_size = 0;
    if (_raiz != nullptr){
        if(_raiz->definicion != nullptr){
            delete _raiz->definicion;
        }
        delete _raiz;
        _raiz = nullptr;
    }

    //ACA ARRANCA EL COPIADO
    this->_size = d.size();
    if(d._raiz != nullptr && _raiz == nullptr){
        _raiz = new Nodo();
        _copiarRecursivo(this->_raiz, d._raiz);
    }

}

template <typename T>
void string_map<T>::_copiarRecursivo(Nodo* actual, Nodo* aCopiar){
    if(aCopiar != nullptr && aCopiar->definicion != nullptr){
        actual->definicion = new T(*(aCopiar->definicion));
    }
    for(int i=0; i<aCopiar->hijosNoNulos.size(); i++){
        Nodo *nuevo = new Nodo(); //Creo nuevo nodo
        nuevo->padre = actual; //El nuevo nodo tiene como padre al nodo actual
        actual->hijosNoNulos.push_back(aCopiar->hijosNoNulos[i]); //HAY QUE SETEAR LOS HIJOS NO NULOS PARA MANTENER CONSISTENCIA
        actual->siguientes[aCopiar->hijosNoNulos[i]] = nuevo; //El nodo actual en la pos clave[i] tiene como hijo a nuevo
        _copiarRecursivo(nuevo, aCopiar->siguientes[aCopiar->hijosNoNulos[i]]);
    }
}

template <typename T>
string_map<T>::~string_map(){
    if(this->size()>0){
        for(int i=0; i<_raiz->hijosNoNulos.size(); i++){
                _destruirRecursivo(_raiz->siguientes[_raiz->hijosNoNulos[i]]);
        }
    }
    this->_size = 0;
    if (_raiz != nullptr){
        if(_raiz->definicion != nullptr){
            delete _raiz->definicion;
        }
        delete _raiz;
        _raiz = nullptr;
    }
}

template <typename T>
void string_map<T>::_destruirRecursivo(Nodo* actual){
    for(int i=0; i<actual->hijosNoNulos.size(); i++){
            _destruirRecursivo(actual->siguientes[actual->hijosNoNulos[i]]);
    }
    if(actual->definicion != nullptr){
        delete actual->definicion;
    }
    delete actual;
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    int res = 0;
    if(clave == ""){
        res = _raiz != nullptr && _raiz->definicion != nullptr;
    } else {
        if(this->size()>0){
            Nodo* actual = _raiz;
            vector<int> keys = _stringToVectorInt(clave);
            int i = 0;
            while(i<clave.size() && actual->siguientes[keys[i]] != nullptr){
                actual = actual->siguientes[keys[i]];
                i++;
            }
            res = i == keys.size() && actual->definicion != nullptr;
        }
    }
    return res;
}

template <typename T>
vector<int> string_map<T>::_stringToVectorInt(const string &key) const{
    vector<int> result = vector<int>(key.size());
    for(int i = 0; i<key.size(); i++){
        result[i] = int(key[i]);
    }
    return result;
}

//ASUMO como Pre-condición que estoy insertando solamente elementos de claves NUNCA ANTES DEFINIDAS
template <typename T>
void string_map<T>::insert(const pair<string, T>& p) {
    if (p.first.size() == 0) {
        if(_raiz == nullptr){
            Nodo* n = new Nodo();
            _raiz = n;
        }
        _raiz->definicion = new T(p.second);
    } else {
        if(_raiz == nullptr){
            Nodo* r = new Nodo();
            _raiz = r; //Entra solamente con la primera letra de la primer palabra que se ingrese al Trie
        }
        Nodo* actual = _raiz;
        vector<int> clave = _stringToVectorInt(p.first);
        int i = 0;
        while (i < clave.size()) {
            if (actual->siguientes[clave[i]] == nullptr){
                //Necesitamos agregar un nuevo nodo para poder definir la clave significado en el trie
                actual->hijosNoNulos.push_back(clave[i]); //El nodo que queremos agregar es hijo del nodo actual
                Nodo *nuevo = new Nodo(); //Creo nuevo nodo
                nuevo->padre = actual; //El nuevo nodo tiene como padre al nodo actual
                actual->siguientes[clave[i]] = nuevo; //El nodo actual en la pos clave[i] tiene como hijo a nuevo
                actual = nuevo; //Seteo actual con el nodo nuevo para seguir avanzando en la definicion

            } else {
                actual = actual->siguientes[clave[i]];
            }
            i++;
        }
        if(actual->definicion == nullptr){
            actual->definicion = new T(p.second);
        }
        else{
            delete actual->definicion;
            actual->definicion = new T(p.second);
        }
    }
    _size++;
}

//Pre: count(clave) == 1
template <typename T>
const T& string_map<T>::at(const string& clave) const {
    if(clave != "" && this->size()>0){
        Nodo* actual = _raiz;
        vector<int> keys = _stringToVectorInt(clave);
        int i = 0;
        while(i<clave.size() && actual->siguientes[keys[i]] != nullptr){
            actual = actual->siguientes[keys[i]];
            i++;
        }
        return *(actual->definicion);
    } else {
        return *(_raiz->definicion);
    }
}

//Pre: count(clave) == 1
template <typename T>
T& string_map<T>::at(const string& clave) {
    if(clave != "" && this->size()>0){
        Nodo* actual = _raiz;
        vector<int> keys = _stringToVectorInt(clave);
        int i = 0;
        while(i<clave.size() && actual->siguientes[keys[i]] != nullptr){
            actual = actual->siguientes[keys[i]];
            i++;
        }
        return *(actual->definicion);
    } else {
        return *(_raiz->definicion);
    }
}

//Pre: count(clave) == 1
template <typename T>
void string_map<T>::erase(const string& clave) {
    if(clave == ""){
        _raiz->definicion = nullptr;
    } else {
        if(this->size()>0){
            Nodo* actual = _raiz;
            Nodo* ultimo = _raiz;
            int i = 0, ultimoIndice = 0;
            vector<int> keys = _stringToVectorInt(clave);
            while(i<clave.size()){
                if(actual->hijosNoNulos.size()>1 || actual->definicion!=nullptr){
                    //Se va a quedar parado en el ultimo nodo que NO HAY QUE BORRAR de los que corresponden a la clave
                    ultimo = actual;
                    ultimoIndice = i;
                }
                //Seguimos avanzando hasta el nodo que tiene el significado de la clave que queremos borrar
                actual = actual->siguientes[keys[i]];
                i++;
            }
            //actual->definicion = nullptr;
            if(actual->hijosNoNulos.size()==0){
                //Actual es una hoja del Trie: tenemos que borrar los nodos posteriores al ultimo nodo

                //El nodo a partir del cual vamos a eliminar la clave no debe ser más hijo del ultimo nodo con más de un hijo
                _eliminarNodoHijo(ultimo->hijosNoNulos, keys[ultimoIndice]);

                ultimo = ultimo->siguientes[keys[ultimoIndice]];
                ultimo->padre->siguientes[keys[ultimoIndice]] = nullptr;
                while(ultimoIndice<clave.size()-1){

                    ultimoIndice++;//Lo llevamos a la parte de la clave que corresponde a los nodos que SI hay que borrar

                    ultimo = ultimo->siguientes[keys[ultimoIndice]];

                    if(ultimo->padre->definicion != nullptr){
                        delete ultimo->padre->definicion;
                    }

                    delete ultimo->padre;
                    //ultimoIndice++;
                }

                if(ultimo->definicion != nullptr){
                    delete ultimo->definicion;
                }

                delete ultimo;
            } else {
                delete actual->definicion;
                actual->definicion = nullptr;
            }
        }
    }
    _size--;
}

template <typename T>
void string_map<T>::_eliminarNodoHijo(vector<int>& v, int h){
    int posh = 0;
    for(int i=0; i<v.size();i++){
        if(v[i]==h){
            posh=i;
        }
    }
    v.erase(v.begin()+posh);
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return this->size()==0;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
   T i = -1;
   if(this->count(clave) == 0){
	   this->insert(make_pair(clave, i));
   }
   return this->at(clave);
}

