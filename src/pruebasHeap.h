#ifndef SRC_PRUEBASHEAP_H_
#define SRC_PRUEBASHEAP_H_

#include "Tester.h"
#include "Heap.h"

void pruebasHeap();

bool DadoUnHeapVacio_CuandoSeCrea_estaVacio();

bool DadoUnHeapVacio_cuandoSeInsertaUnElemento_NoEstaVacio();

bool DadoUnHeapVacio_CuandoSeInsertanElementos_SeMantieneElMinimo();

bool DadoUnHeapConElementos_CuandoSeEliminaElMinimo_ElMinimoEsDistinto();

#endif /* SRC_PRUEBASHEAP_H_ */
