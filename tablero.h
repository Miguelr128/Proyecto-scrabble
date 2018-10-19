#ifndef TABLERO_H
#define TABLERO_H

#include "casilla.h"

#include <sstream>
using namespace std;

class tablero {
public:
    tablero(int, int);
    void reservarPosicion(int, int);
    string toString() const;
    virtual ~tablero();
private:
    int filas;
    int columnas;
    casilla*** casillas;
};
#endif /* TABLERO_H */