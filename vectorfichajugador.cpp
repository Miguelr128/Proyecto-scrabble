#include "vectorfichajugador.h"

vectorfichajugador::vectorfichajugador(int x) :tamano(x), cantidad (0), vector(new char[x]) {
}

vectorfichajugador::~vectorfichajugador() {
}

void vectorfichajugador::pasarFichas(vectorficha* fichas) {
    int numero;
    char c;
    for (int i = 0; i < tamano; i++) {
        numero = rand() % 90;
        c = fichas->getFicha(numero);
        vector[i] = c;
        cantidad++;
        fichas->eliminarFicha(numero);
    }
}