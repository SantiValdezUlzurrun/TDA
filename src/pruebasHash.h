#ifndef SRC_PRUEBASHASH_H_
#define SRC_PRUEBASHASH_H_

#include "Hash.h"
#include "Tester.h"
#include <stdlib.h>


void pruebasHash();

bool DadoUnHashVacio_CuandoSeCrea_EstaVacio();

bool DadoUnHashVacio_CuandoSeAgregaUnElemento_EstaEnElArbol();

bool DadoUnHashConElementos_CuandoSeAgregaUnElemento_ElElementoBuscadoEsElMismo();

bool DadoUnHashConElemento_CuandoSeBorraUnElemento_EsteYaNoEstaEnElArbol();

bool DadoUnHashConElementos_CuandoSeLlenaUnaLista_SonIguales();

#endif /* SRC_PRUEBASHASH_H_ */
