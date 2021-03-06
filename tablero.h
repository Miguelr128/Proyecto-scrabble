#ifndef TABLERO_H
#define TABLERO_H

#include <sstream>
using namespace std;

#include "casilla.h"

class tablero {
public:
    tablero();
    void reservarPosicion(int, int, ficha*);
    int contarPuntos(int, int);
    string toString() const;
    void rosado();
    void amarillo();
    void verde();
    void azul();
    void duplicarValorPalabra();
    ficha* getFicha(int, int);
    string getLetra(int, int);
    void eliminarPalabra(int, int, int, int);
    virtual ~tablero();
private:
    int filas;
    int columnas;
    casilla*** casillas;
};
#endif /* TABLERO_H */