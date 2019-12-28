
#include "pruebasHash.h"
using namespace std;

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

	examinador->hacerPrueba(DadoUnHashConElementos_CuandoSeLlenaUnaLista_SonIguales,
							"DadoUnHashConElementos_CuandoSeLlenaUnaLista_SonIguales");

	examinador->veredicto();

	delete examinador;

}


static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{

    return alphanum[rand() % stringLength];
}

std::string randomStr(){

   std::string Str;
   for(unsigned int i = 0; i < 20; ++i)
   {
	   Str += genRandom();

   }
   return Str;
}



bool DadoUnHashVacio_CuandoSeCrea_EstaVacio(){


	Hash<int> * hash = new Hash<int>();

	bool estaVacio = hash->estaVacio();

	delete hash;

	return estaVacio;


}


bool DadoUnHashVacio_CuandoSeAgregaUnElemento_EstaEnElArbol(){

	int numeroAleatorio = rand() % 500 + 10;
	std::string clave = randomStr();

	Hash<int> * hash = new Hash<int>();

	hash->agregar(clave, numeroAleatorio);

	bool esta = hash->esta(clave);

	delete hash;

	return esta;


}


bool DadoUnHashConElementos_CuandoSeAgregaUnElemento_ElElementoBuscadoEsElMismo(){

	Hash<int> * hash = new Hash<int>();

	int numeroAleatorio = rand() % 500 + 1000;
	std::string clave = randomStr();


	for(int i = 0; i < numeroAleatorio; i++){

		int otroNumeroAleatorio = rand() % 500 + 10;
		std::string otraClave = randomStr();

		if(!hash->esta(otraClave))
			hash->agregar(otraClave, otroNumeroAleatorio);
	}

	hash->agregar(clave, numeroAleatorio);

	int numeroEncontrado = hash->buscar(clave);

	delete hash;

	return numeroEncontrado == numeroAleatorio;


}

bool DadoUnHashConElemento_CuandoSeBorraUnElemento_EsteYaNoEstaEnElArbol(){


	Hash<int> * hash = new Hash<int>();

	int numeroAleatorio = rand() % 500 + 1000;
	std::string clave = randomStr();


	for(int i = 0; i < numeroAleatorio; i++){

		int otroNumeroAleatorio = rand() % 500 + 10;
		std::string otraClave = randomStr();

		if(!hash->esta(otraClave))
			hash->agregar(otraClave, otroNumeroAleatorio);
	}

	hash->agregar(clave, numeroAleatorio);

	hash->borrar(clave);

	bool noEsta = !hash->esta(clave);

	delete hash;

	return noEsta;

}

bool DadoUnHashConElementos_CuandoSeLlenaUnaLista_SonIguales(){

	Hash<int> * hash = new Hash<int>();

	int primero = rand() % 500 + 1000;
	std::string clave1 = randomStr();

	int segundo = rand() % 500 + 1000;
	std::string clave2 = randomStr();

	int tercero = rand() % 500 + 1000;
	std::string clave3 = randomStr();

	hash->agregar(clave1,primero);

	hash->agregar(clave2,segundo);

	hash->agregar(clave3,tercero);

	Lista<int> * lista = new Lista<int>;

	hash->recorrer(lista);

	bool esta = lista->cantidadElementos() == 3;

	delete lista;
	delete hash;

	return esta;


}

