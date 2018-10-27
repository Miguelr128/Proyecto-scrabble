#ifndef TABLERO_H
#define TABLERO_H

#include <sstream>
using namespace std;

#include "casilla.h"

class tablero {
public:
    tablero(int, int);
    void reservarPosicion(int, int, ficha*);
    int contarPuntos(int, int);
    string toString() const;
    void rosado();
    void amarillo();
    void verde();
    void azul();
    void duplicarValorPalabra();
    virtual ~tablero();
private:
    int filas;
    int columnas;
    casilla*** casillas;
};
#endif /* TABLERO_H */