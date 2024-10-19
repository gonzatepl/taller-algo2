
template<class T>
ColaPrior<T>::ColaPrior() {
	_tam = 0;
}

template<class T>
int ColaPrior<T>::tam() const {
    return _tam;
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
	//LOS ELEMENTOS SIEMPRE SE AGREGAN AL FINAL POR LA PROPIEDAD DE IZQUIERDISTA Y UNA VEZ QUE SE AGREGAN HAY QUE VER SI QUEDAN
	//AHI O SI HAY QUE MOVERLOS HACIA ATRAS PARA QUE PRESERVEN EL INVARIANTE DE REPRESENTACION DE LA ESTRUCTURA DE HEAP

	//Respetamos el invariante del heap, agregamos el elemento siempre lo más a la izquierda que se pueda
    _heap.push_back(elem);
    _tam++;

    if (tam() > 1){
	    //Estamos agregando un elemento hijo, por lo tanto para respetar el invariante del heap debemos llevarlo al lugar que le
	    //corresponde

	    //La posicion del elemento que acabamos de agregar a la cola de prioridad en este punto es tam()-1
	    int pos_elem = tam()-1;

	    //EN LO SIGUIENTE FALTARIA AGREGARLE NIVELES DE ABSTRACCION DADO QUE ENTRE OTRAS COSAS SE ASUME QUE UN ELEMENTO YA NO
	    //TIENE PADRE SI LA POSICION DE ESTE ES -1

	    //Sift up
	    sift_up(pos_elem);
    }

}

template<class T>
const T& ColaPrior<T>::proximo() const {
	if(tam()>0){
	    return _heap[0];
	}
}

template<class T>
void ColaPrior<T>::desencolar() {
    if(tam()>0){

        //Reemplazar la raiz del arbol por el ultimo elemento, respetando la forma del heap.
        _heap[0] = _heap[tam()-1];

        //Borrar el ultimo elemento del heap
        _heap.pop_back();
        _tam--;

        //Debo acomodar la raiz de forma que se respete el invariante del heap: Empezando desde la raiz, mientras sea menor
        //que uno de sus hijos, intercambiarlo con el mayor de sus hijos.
        int pos_elem = 0;

        //Sift down
        sift_down(pos_elem);

    }

}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
    //heapify - Algoritmo de Floyd
    _tam = 0;
    for(T elem: elems){
        _heap.push_back(elem);
        _tam++;
    }
    for(int i = tam()/2; i >=0; i--){
        sift_down(i);
    }
}

template<class T>
const T& ColaPrior<T>::HIJO_IZQ(int i){
    int hijo_izq = 2 * i + 1;
    return _heap[hijo_izq];
}

template<class T>
const T& ColaPrior<T>::HIJO_DER(int i){
    int hijo_der = 2 * i + 2;
    return _heap[hijo_der];
}

template<class T>
const T& ColaPrior<T>::PADRE(int i){
    int padre = (i - 1)/2;
    return _heap[padre];
}

template<class T>
int ColaPrior<T>::pos_hijo_izq(int i) {
    int hijo_izq = 2 * i + 1;
    if (0 <= hijo_izq && hijo_izq < tam()){
        return hijo_izq;
    }
    return -1;
}

template<class T>
int ColaPrior<T>::pos_hijo_der(int i) {
    int hijo_der = 2 * i + 2;
    if (0 <= hijo_der && hijo_der < tam()){
        return hijo_der;
    }
    return -1;
}

template<class T>
int ColaPrior<T>::pos_padre(int i) {
    int padre = (i - 1)/2;
    if (0 <= padre && padre < tam()){
        return padre;
    }
    return -1;
}

template<class T>
int ColaPrior<T>::pos_max(int i, int j) {
    if(j == -1 || _heap[i] > _heap[j]){
        return i;
    }
    return j;
}

template<class T>
bool ColaPrior<T>::es_hoja(int pos){
    return pos_hijo_izq(pos) < 0 && pos_hijo_der(pos) < 0;
}

template<class T>
void ColaPrior<T>::swap(T & t1, T & t2) {
    T aux = t1;
    t1 = t2;
    t2 = aux;
}

template<class T>
void ColaPrior<T>::sift_up(int pos){
    while(pos_padre(pos) >= 0 && _heap[pos] > PADRE(pos)){

        //Intercambiamos los elementos de forma tal elem se ubique en la posicion de su padre y este en su posicion
        swap(_heap[pos], _heap[pos_padre(pos)]);

        //Actualizamos la posicion del elemento que acabamos de agregar para repetir este proceso de volver a cumplirse
        //la condicion que impide que se mantenga el invariante del heap
        pos = pos_padre(pos);
    }
}

template<class T>
void ColaPrior<T>::sift_down(int pos){
    int pos_max_hijo = pos_max(pos_hijo_izq(pos), pos_hijo_der(pos));
    while(!es_hoja(pos) && _heap[pos] < _heap[pos_max_hijo]){

        //Intercambiamos los elementos de forma tal elem se ubique en la posicion de su hijo maximo y este en su posicion
        swap(_heap[pos], _heap[pos_max_hijo]);

        //Actualizamos la posicion del elemento que acabamos de agregar para repetir este proceso de volver a cumplirse
        //la condicion que impide que se mantenga el invariante del heap
        pos = pos_max_hijo;
        pos_max_hijo = pos_max(pos_hijo_izq(pos), pos_hijo_der(pos));
    }
}