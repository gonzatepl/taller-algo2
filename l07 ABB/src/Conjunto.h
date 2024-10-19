#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;





private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v): valor(v), izq(nullptr), der(nullptr), padre(nullptr){}
            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo* der;
            // Para poder ir moviendome entre el arbol
            Nodo* padre;

        };

        // Puntero a la raiz del arbol
        Nodo* _raiz;

        //La idea es tener un atributo que almacene el cardinal del conjunto en cada momento
        unsigned int _cardinal;

        //FUNCIONES AUXILIARES

        //Requiere que el nodo n NO sea nullptr
        void _destruir(Nodo * n);

        //Requiere que nodo actual sea el que quiero borrar
        void _borroHoja(Nodo* actual);

        //Requiere que nodo actual sea el que quiero borrar
        void _borroPadreUnicoHijo(Nodo* actual);

        //Requiere que el nodo n NO sea nullptr
        void _mostrar(std::ostream&, Nodo * n);

};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
