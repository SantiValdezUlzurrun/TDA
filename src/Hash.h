#ifndef HASH_H_
#define HASH_H_

#include "ABB.h"
#include <iostream>
using namespace std;

const int NUMERO_PRIMO = 37;

template <class T> class Hash{

	private:

		ABB<T> ** tabla;
		unsigned int capacidad;
		unsigned int tamanio;

	public:

		/*
		 * Pre:
		 * Post: Crea un hash vacio
		 */
		Hash();

		//TODO REHASH
		/*
		 * Pre: El elemento no esta en el hash
		 * Post: Se ha agregado el elemento al hash
		 */
		void agregar(T elemento);

		/*
		 * Pre:
		 * Post: Devuelve true si el elemento esta en el hash
		 */
	    bool esta(T elemento);

		/*
		 * Pre:
		 * Post: Devuelve true si estaVacio
		 */
		bool estaVacio();

		/*
		 * Pre: El elemento esta en el hash
		 * Post: Se ha devuelto el elemento encontrado
		 */
		T buscar(T elemento);

		/*
		 * Pre:
		 * Post: Devuelve la cantidad de elementos presentes en el hash
		 */
		unsigned int obtenerTamanio();

		/*
		 * Pre: El elemento esta en el hash
		 * Post: Se ha borrado el elemento
		 */
		void borrar(T elemento);

		/*
		 * Pre:
		 * Post: Libera los recursos tomados por el hash
		 */
		~Hash();

	private:

		/*
		 * Pre:
		 * Post: Devuelve un numero entero entre [0 - capacidad]
		 */
		unsigned int funcionHash(T elemento);


};


template <class T>
Hash<T>::Hash(){

	this->capacidad = NUMERO_PRIMO;
	this->tamanio = 0;
	this->tabla = new ABB<T>*[this->capacidad];
	for(unsigned int i = 0; i < this->capacidad; i++){

		this->tabla[i] = NULL;

	}
}


template <class T>
unsigned int Hash<T>::funcionHash(T elemento){

	unsigned int clave = (unsigned int)(char)elemento % this->capacidad;

	return clave;

}


template <class T>
void Hash<T>::agregar(T elemento){


	unsigned int clave = this->funcionHash(elemento);
	ABB<T> * & lugarDeLaTabla = this->tabla[clave];

	if(lugarDeLaTabla == NULL)
		lugarDeLaTabla = new ABB<T>();

	lugarDeLaTabla->agregar(elemento);
	this->tamanio++;


}

template <class T>
T Hash<T>::buscar(T elemento){

	unsigned int clave = this->funcionHash(elemento);
	ABB<T> * lugarDeLaTabla = this->tabla[clave];

	if(lugarDeLaTabla == NULL)
		throw std::string("No esta el elemento al buscarlo");

	T encontrado = lugarDeLaTabla->buscar(elemento);
	return encontrado;

}

template <class T>
bool Hash<T>::esta(T elemento){

	unsigned int clave = this->funcionHash(elemento);
	ABB<T> * lugarDeLaTabla = this->tabla[clave];

	bool esta = false;

	if(lugarDeLaTabla != NULL)
		esta = lugarDeLaTabla->esta(elemento);

	return esta;

}

template <class T>
unsigned int Hash<T>::obtenerTamanio(){

	return this->tamanio;
}

template <class T>
bool Hash<T>::estaVacio(){

	return this->tamanio == 0;

}
template <class T>
void Hash<T>::borrar(T elemento){


	unsigned int clave = this->funcionHash(elemento);
	ABB<T> * & lugarDeLaTabla = this->tabla[clave];

	if (lugarDeLaTabla == NULL)
		throw std::string("No esta el elemento al borrarlo");

	lugarDeLaTabla->borrar(elemento);

}

template <class T>
Hash<T>::~Hash(){

	for(unsigned int i = 0; i < this->capacidad; i++){

		if(this->tabla[i] != NULL)
			delete this->tabla[i];

	}
	delete []this->tabla;

}


#endif /* HASH_H_ */
