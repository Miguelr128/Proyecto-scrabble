#include "vectorfichajugador.h"

vectorfichajugador::vectorfichajugador() : tamano(7), cantidad (0) {
    for(int i = 0; i < tamano; i++)
        vector[i] = NULL;
}

vectorfichajugador::~vectorfichajugador() {
}

void vectorfichajugador::pasarFichas(vectorficha**& fichas) {
    int numero = rand() % 90;
    for (int i = 0; i < tamano; i++) {
        vector[i] = fichas[numero];
        vector[i] -> eliminarFicha(fichas[numero]);
    }
}