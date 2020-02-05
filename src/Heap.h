#ifndef SRC_HEAP_H_
#define SRC_HEAP_H_

#include "NodoHeap.h"

template <class T> class Heap{

	private:

		unsigned int capacidad;
		unsigned int tamanio;
		NodoHeap<T> ** heap;

	public:

		/*
		 * Pre:
		 * Post: Se crea un heap vacio
		 */
		Heap();

		/*
		 * Pre:
		 * Post: Devuelve true si esta vacio
		 */
		bool estaVacio();

		/*
		 * Pre:
		 * Post: Se ha insertado un elemento
		 */
		void insertar(int clave, T elemento);

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Devuelve el elemento minimo
		 */
		T obtenerElementoMinimo();

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Devuelve la clave minima
		 */
		int obtenerClaveMinima();

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Se ha removido el minimo
		 */
		void removerMinimo();

		/*
		 * Pre:
		 * Post: Libera los recursos tomados por el Heap
		 */
		~Heap();

	private:

		/*
		 * Pre:
		 * Post: Se ha incrementado la capacidad del Heap
		 */
		void expandirHeap();

		/*
		 * Pre: Se ha insertado en el heap en el indiceDeInsercion
		 * Post: Se ha restaurado el heap
		 */
		void propagarParaArriba(unsigned int indiceDeInsercion);

		/*
		 * Pre: Se ha removido el elemento minimo
		 * Post: Se ha restaurado el heap
		 */
		void propagarParaAbajo(unsigned int indice);

		/*
		 * Pre:
		 * Post: Devuelve true si izquierda < derecha
		 */
		bool funcionDeComparacion(NodoHeap<T> * izquierda, NodoHeap<T> * derecha);
};


template <class T>
Heap<T>::Heap(){

	this->capacidad = 3;
	this->tamanio = 0;
	this->heap = new NodoHeap<T>*[this->capacidad];

}


template <class T>
bool Heap<T>::estaVacio(){

	return this->tamanio == 0;
}


template <class T>
T Heap<T>::obtenerElementoMinimo(){

	if(this->estaVacio()){

		throw std::string("No se puede obtener el minimo si el Heap esta vacio");
	}

	NodoHeap<T> * minimo = this->heap[0];
	return minimo->obtenerValor();
}


template <class T>
int Heap<T>::obtenerClaveMinima(){

	if(this->estaVacio()){

		throw std::string("No se puede obtener el minimo si el Heap esta vacio");
	}

	NodoHeap<T> * minimo = this->heap[0];
	return minimo->obtenerClave();
}


template <class T>
void Heap<T>::insertar(int clave, T elemento){


	if(tamanio == this->capacidad){

		this->expandirHeap();
	}

	NodoHeap<T> * aAgregar = new NodoHeap<T>(clave, elemento);

	this->heap[this->tamanio] = aAgregar;

	this->propagarParaArriba(this->tamanio);

	this->tamanio++;

}

template <class T>
void Heap<T>::expandirHeap(){


	NodoHeap<T> ** nuevoHeap = new NodoHeap<T>*[this->capacidad * 2];

	for(unsigned int i = 0; i < this->capacidad; i++){

		nuevoHeap[i] = this->heap[i];

	}

	this->capacidad = this->capacidad * 2;
	delete []this->heap;
	this->heap = nuevoHeap;

}

template <class T>
void Heap<T>::propagarParaArriba(unsigned int indiceDeInsercion){


	if(indiceDeInsercion == 0){
		return;
	}

	unsigned int indiceDelPadre;
	if(indiceDeInsercion % 2 == 0){

		indiceDelPadre = (indiceDeInsercion - 2) / 2;
	}else{

		indiceDelPadre = (indiceDeInsercion - 1) / 2;
	}

	NodoHeap<T> * hijo = this->heap[indiceDeInsercion];
	NodoHeap<T> * padre = this->heap[indiceDelPadre];

	bool esMenor = this->funcionDeComparacion(hijo, padre);

	if(esMenor){

		this->heap[indiceDelPadre] = hijo;
		this->heap[indiceDeInsercion] = padre;

		this->propagarParaArriba(indiceDelPadre);
	}

}


//TODO Probable error de fuera de rango
template <class T>
void Heap<T>::removerMinimo(){


	if(this->estaVacio()){

		throw std::string("No se puede obtener el minimo si el Heap esta vacio");

	}

	NodoHeap<T> * aRemover = this->heap[0];

	if(this->tamanio != 1){

		NodoHeap<T> * ultimo = this->heap[this->tamanio - 1];
		this->heap[0] = ultimo;
		this->heap[this->tamanio - 1] = NULL;
		this->propagarParaAbajo(0);
	}


	delete aRemover;
	this->tamanio--;
}


template <class T>
void Heap<T>::propagarParaAbajo(unsigned int indice){

	if(indice == this->tamanio - 1 ||
	   this->tamanio - 1 < (2 * indice) + 2){
		return;
	}

	NodoHeap<T> * padre = this->heap[indice];
	NodoHeap<T> * hijoIzquierdo = this->heap[(2 * indice) + 1];
	NodoHeap<T> * hijoDerecho = this->heap[(2 * indice) + 2];

	if(this->funcionDeComparacion(hijoIzquierdo, padre)){

		this->heap[indice] = hijoIzquierdo;
		this->heap[(2 * indice) + 1] = padre;
		this->propagarParaAbajo((2 * indice) + 1);

	}else if(this->funcionDeComparacion(hijoDerecho, padre)){

		this->heap[indice] = hijoDerecho;
		this->heap[(2 * indice) + 2] = padre;
		this->propagarParaAbajo((2 * indice) + 2);

	}

}


template <class T>
bool Heap<T>::funcionDeComparacion(NodoHeap<T> * izquierda, NodoHeap<T> * derecha){

	return (*izquierda < *derecha);
}


template <class T>
Heap<T>::~Heap(){


	for(unsigned int i = 0; i < this->tamanio; i++){

		delete this->heap[i];
	}

	delete []this->heap;
}

#endif /* SRC_HEAP_H_ */
