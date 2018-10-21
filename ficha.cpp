#include <cstdlib>

#include "ficha.h"

ficha::ficha(char letra, int valorLetra, int cantidadLetra) : letra(letra), valorLetra(valorLetra)
, cantidadLetra(cantidadLetra), letraComodin(false) {
}

ficha::~ficha() {
}