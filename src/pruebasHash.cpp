
#include "pruebasHash.h"

void pruebasHash(){

	Tester * examinador = new Tester;

	examinador->hacerPrueba(DadoUnHashVacio_CuandoSeCrea_EstaVacio,
							"DadoUnHashVacio_CuandoSeCrea_EstaVacio");

	examinador->hacerPrueba(DadoUnHashVacio_CuandoSeAgregaUnElemento_EstaEnElArbol,
							"DadoUnHashVacio_CuandoSeAgregaUnElemento_EstaEnElArbol");

	examinador->hacerPrueba(DadoUnHashConElementos_CuandoSeAgregaUnElemento_ElElementoBuscadoEsElMismo,
							"DadoUnHashConElementos_CuandoSeAgregaUnElemento_ElElementoBuscadoEsElMismo");

	examinador->hacerPrueba(DadoUnHashConElemento_CuandoSeBorraUnElemento_EsteYaNoEstaEnElArbol,
							"DadoUnHashConElemento_CuandoSeBorraUnElemento_EsteYaNoEstaEnElArbol");


	examinador->veredicto();

	delete examinador;

}


bool DadoUnHashVacio_CuandoSeCrea_EstaVacio(){


	Hash<int> * hash = new Hash<int>();

	bool estaVacio = hash->estaVacio();

	delete hash;

	return estaVacio;


}


bool DadoUnHashVacio_CuandoSeAgregaUnElemento_EstaEnElArbol(){

	int numeroAleatorio = rand() % 500 + 10;

	Hash<int> * hash = new Hash<int>();

	hash->agregar(numeroAleatorio);

	bool esta = hash->esta(numeroAleatorio);

	delete hash;

	return esta;


}


bool DadoUnHashConElementos_CuandoSeAgregaUnElemento_ElElementoBuscadoEsElMismo(){

	Hash<int> * hash = new Hash<int>();

	int numeroAleatorio = rand() % 500 + 1000;

	for(int i = 0; i < numeroAleatorio; i++){

		int otroNumeroAleatorio = rand() % 500 + 10;

		if(!hash->esta(otroNumeroAleatorio))
			hash->agregar(otroNumeroAleatorio);
	}

	hash->agregar(numeroAleatorio);

	int numeroEncontrado = hash->buscar(numeroAleatorio);

	delete hash;

	return numeroEncontrado == numeroAleatorio;


}

bool DadoUnHashConElemento_CuandoSeBorraUnElemento_EsteYaNoEstaEnElArbol(){


	Hash<int> * hash = new Hash<int>();

	int numeroAleatorio = rand() % 500 + 1000;

	for(int i = 0; i < numeroAleatorio; i++){

		int otroNumeroAleatorio = rand() % 500 + 10;

		if(!hash->esta(otroNumeroAleatorio))
			hash->agregar(otroNumeroAleatorio);
	}

	hash->agregar(numeroAleatorio);

	hash->borrar(numeroAleatorio);

	bool noEsta = !hash->esta(numeroAleatorio);

	delete hash;

	return noEsta;

}
