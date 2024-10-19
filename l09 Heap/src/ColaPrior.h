#ifndef _COLAPRIOR_H_
#define _COLAPRIOR_H_

#include <vector>

using namespace std;

/* La clase T debe tener definido un operator<
 * que implemente una relación de orden total. */
template<class T>
class ColaPrior {
public:
	ColaPrior();

	// Cantidad de elementos en la cola.
	int tam() const;

	// Encola un elemento.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	void encolar(const T& elem);

	// Devuelve el elemento de mayor prioridad.
	// Pre: tam() > 0
	const T& proximo() const;

	// Saca el elemento de mayor prioridad.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	// Pre: tam() > 0
	void desencolar();

	// Constructor que hace heapify.
	ColaPrior(const vector<T>& elems);

private:

    int _tam;
	vector<T> _heap;

    int pos_hijo_izq(int i);

    int pos_hijo_der(int i);

    int pos_padre(int i);

    //Dada una posicion de un elemento del heap indica si este no tiene hijos en el.
    bool es_hoja(int pos);

	//Dada una posicion correspondiente a un elemento del heap devuelve su hijo izquierdo.
	//La posicion debe ser valida
    const T& HIJO_IZQ(int i);

    //Dada una posicion correspondiente a un elemento del heap devuelve su hijo derecho.
    //La posicion debe ser valida
    const T& HIJO_DER(int i);

    //Dada una posicion correspondiente a un elemento del heap devuelve su Padre.
    //La posicion debe ser valida
    const T& PADRE(int i);

    //Dadas dos posiciones del heap, devuelve en cual de ellas se encuentra el elemento mayor.
    //Notar que j puede ser nulo, y en esta 'abstraccion' eso lo represento con el valor -1
    int pos_max(int i, int j);

    void swap(T & t1, T & t2);

    void sift_up(int pos);

    void sift_down(int pos);



};

#include "ColaPrior.hpp"

#endif /*_COLAPRIOR_H_*/
