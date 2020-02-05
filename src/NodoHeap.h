#ifndef SRC_NODOHEAP_H_
#define SRC_NODOHEAP_H_


template <class T> class NodoHeap{

	private:

		int clave;
		T valor;

	public:

		/*
		 * Pre:
		 * Post: Se ha creado un NodoHeap
		 */
		NodoHeap(int clave, T valor);

		/*
		 * Pre:
		 * Post: Devuelve la clave
		 */
		int obtenerClave() const;

		/*
		 * Pre:
		 * Post: Devuelve el valor
		 */
		T obtenerValor() const;

		/*
		 * Pre:
		 * Post: Se ha cambiado el valor
		 */
		void cambiarValor(T nuevoValor);

		bool operator< (const NodoHeap& derecha);

		NodoHeap& operator =(const NodoHeap& otro);

		/*
		 * Pre:
		 * Post: Se han liberado los recursos tomados por el NodoDiccionario
		 */
		~NodoHeap();

};

template <class T>
NodoHeap<T>::NodoHeap(int clave, T valor){

	this->clave = clave;
	this->valor = valor;

}

template <class T>
int NodoHeap<T>::obtenerClave() const{

	return this->clave;
}

template <class T>
T NodoHeap<T>::obtenerValor() const{

	return this->valor;
}


template <class T>
void NodoHeap<T>::cambiarValor(T nuevoValor){

	this->valor = nuevoValor;
}

template <class T>
NodoHeap<T>::~NodoHeap(){


}

template <class T>
bool NodoHeap<T>::operator< (const NodoHeap& derecha){

	return (this->obtenerClave() < derecha.obtenerClave());
}


template <class T>
NodoHeap<T>& NodoHeap<T>::operator =(const NodoHeap& otro){

	this->clave = otro.obtenerClave();
	this->valor = otro.obtenerValor();
	return (*this);

}



#endif /* SRC_NODOHEAP_H_ */
