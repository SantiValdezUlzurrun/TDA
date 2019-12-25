#include "pruebasArbol.h"

using namespace std;

void pruebasArbol(){

	Tester examinador;

	examinador.hacerPrueba(DadoUnArbolVacio_CuandoSeAgregaUnElemento_ElElementoEstaEnElArbol,
						  "DadoUnArbolVacio_CuandoSeAgregaUnElemento_ElElementoEstaEnElArbol");

	examinador.hacerPrueba(DadoUnArbolVacio_CuandoSeAgregaUnElementoYLuegoSeLoBorra_ElElementoNoEstaEnElArbol,
						  "DadoUnArbolVacio_CuandoSeAgregaUnElementoYLuegoSeLoBorra_ElElementoNoEstaEnElArbol");

	examinador.hacerPrueba(DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_ElArbolNoEstaVacio,
						  "DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_ElArbolNoEstaVacio");

	examinador.hacerPrueba(DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_InorderDevuelveUnaListaEnOrden,
						  "DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_InorderDevuelveUnaListaEnOrden");

	examinador.veredicto();

}


bool DadoUnArbolVacio_CuandoSeAgregaUnElemento_ElElementoEstaEnElArbol(){

	int numeroAleatorio = rand() % 500 + 1;

	ABB<int> arbol;

	arbol.agregar(numeroAleatorio);

	return arbol.esta(numeroAleatorio);


}


bool DadoUnArbolVacio_CuandoSeAgregaUnElementoYLuegoSeLoBorra_ElElementoNoEstaEnElArbol(){

	int numeroAleatorio = rand() % 500 + 1;

	ABB<int> arbol;

	arbol.agregar(numeroAleatorio);

	arbol.borrar(numeroAleatorio);

	return (!arbol.esta(numeroAleatorio));


}



bool DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_ElArbolNoEstaVacio(){

	int numeroAleatorio1 = rand() % 500 + 1;
	int numeroAleatorio2 = rand() % 500 + 1;
	int numeroAleatorio3 = rand() % 500 + 1;

	ABB<int> arbol;

	arbol.agregar(numeroAleatorio1);

	arbol.agregar(numeroAleatorio2);

	arbol.agregar(numeroAleatorio3);

	return (!arbol.estaVacio());

}


bool DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_InorderDevuelveUnaListaEnOrden(){

	Lista<int> lista;

	lista.agregar(3);
	lista.agregar(4);
	lista.agregar(5);

	ABB<int> arbol;

	arbol.agregar(3);
	arbol.agregar(4);
	arbol.agregar(5);

	Lista<int> * listaArbol = new Lista<int>;

	arbol.inOrder(listaArbol);

	bool resultado = (lista.obtener(1) == listaArbol->obtener(1) &&
					  lista.obtener(1) == listaArbol->obtener(1) &&
					  lista.obtener(1) == listaArbol->obtener(1));

	delete listaArbol;
	return resultado;
}







