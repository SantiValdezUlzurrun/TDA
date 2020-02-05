#include "pruebasHeap.h"

using namespace std;

void pruebasHeap(){

	Tester * examinador = new Tester;

	examinador->hacerPrueba(DadoUnHeapVacio_CuandoSeCrea_estaVacio,
							"DadoUnHeapVacio_CuandoSeCrea_estaVacio");

	examinador->hacerPrueba(DadoUnHeapVacio_cuandoSeInsertaUnElemento_NoEstaVacio,
							"DadoUnHeapVacio_cuandoSeInsertaUnElemento_NoEstaVacio");

	examinador->hacerPrueba(DadoUnHeapVacio_CuandoSeInsertanElementos_SeMantieneElMinimo,
							"DadoUnHeapVacio_CuandoSeInsertanElementos_SeMantieneElMinimo");

	examinador->hacerPrueba(DadoUnHeapConElementos_CuandoSeEliminaElMinimo_ElMinimoEsDistinto,
							"DadoUnHeapConElementos_CuandoSeEliminaElMinimo_ElMinimoEsDistinto");

	examinador->veredicto();

	delete examinador;
}


bool DadoUnHeapVacio_CuandoSeCrea_estaVacio(){

	Heap<int> * heap = new Heap<int>;

	bool estaVacio = heap->estaVacio();

	delete heap;

	return estaVacio;

}

bool DadoUnHeapVacio_cuandoSeInsertaUnElemento_NoEstaVacio(){

	Heap<int> * heap = new Heap<int>;

	int numero = 25;

	heap->insertar(numero, numero);

	bool noEstaVacio = !heap->estaVacio();

	delete heap;

	return noEstaVacio;

}


bool DadoUnHeapVacio_CuandoSeInsertanElementos_SeMantieneElMinimo(){

	Heap<int> * heap = new Heap<int>;


	heap->insertar(25, 25);

	heap->insertar(3, 3);

	heap->insertar(4, 4);

	heap->insertar(67, 67);

	int minimo = heap->obtenerClaveMinima();

	bool sonIguales = (minimo == 3);

	delete heap;

	return sonIguales;

}

bool DadoUnHeapConElementos_CuandoSeEliminaElMinimo_ElMinimoEsDistinto(){

	Heap<int> * heap = new Heap<int>;

	heap->insertar(25, 25);

	heap->insertar(3, 3);

	heap->insertar(4, 4);

	heap->insertar(67, 67);

	heap->removerMinimo();

	int minimo = heap->obtenerClaveMinima();

	bool sonIguales = (minimo == 3);

	delete heap;

	return !sonIguales;

}







