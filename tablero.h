#ifndef TABLERO_H
#define TABLERO_H

#include <sstream>
using namespace std;

#include "casilla.h"

class tablero {
public:
    tablero(int, int);
    void reservarPosicion(int, int, ficha*);
    string toString() const;
    void rosado();
    void amarillo();
    void verde();
    void azul();
    virtual ~tablero();
//    void premiarPalabra(jugador*);
//    void premiarLetra(char);
private:
    int filas;
    int columnas;
    casilla*** casillas;
};
#endif /* TABLERO_H */