#ifndef SRC_PRUEBASARBOL_H_
#define SRC_PRUEBASARBOL_H_


#include <cstdlib>
#include "ABB.h"
#include <iostream>
#include "Tester.h"

void pruebasArbol();

bool DadoUnArbolVacio_CuandoSeAgregaUnElemento_ElElementoEstaEnElArbol();

bool DadoUnArbolVacio_CuandoSeAgregaUnElementoYLuegoSeLoBorra_ElElementoNoEstaEnElArbol();

bool DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_ElArbolNoEstaVacio();

bool DadoUnArbolVacio_CuandoSeAgreganMuchosElementos_InorderDevuelveUnaListaEnOrden();

#endif /* SRC_PRUEBASARBOL_H_ */
