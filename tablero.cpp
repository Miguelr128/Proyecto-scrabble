#include "tablero.h"

tablero::tablero(int f, int c) : filas(f), columnas(c), casillas(new casilla**[f]) {
    for (int i = 0; i < f; i++) {
        casillas[i] = new casilla*[c];
    }

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            casillas[i][j] = new casilla();
        }
    }
}

tablero::~tablero() {
}

string tablero::toString() const {
    stringstream s;
    s << "";
    for (int m = 0; m < columnas; m++) {
        s << "\t " << m << "  ";
    }
    s << endl;
    for (int i = 0; i < filas; i++) {
        s << i << " ";
        for (int j = 0; j < columnas; j++) {
            s << "\t" << "[" << casillas[i][j] << "]";
        }
        s << endl;
    }
    return s.str();
}