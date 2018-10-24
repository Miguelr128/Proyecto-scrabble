#include "vectorfichajugador.h"

vectorfichajugador::vectorfichajugador(int x, vectorficha* fi) :tamano(x), cantidad (x), fichasSistema(fi), vector(new ficha*[x]) {
    for(int i = 0; i < tamano; i++){
        vector[i] = NULL;
    }
}

vectorfichajugador::~vectorfichajugador() {
}

void vectorfichajugador::pasarFichas() {
    int numero, rango = 90;
    for (int i = 0; i < tamano; i++) {
        numero = rand() % rango;
        vector[i] = fichasSistema->getFicha(numero);
        fichasSistema->eliminarFicha(numero);
        rango = rango -1;
    }
}