#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "jugador.h"
#include "tablero.h"

class diccionario {
public:
    diccionario(int);
    virtual ~diccionario();
    void agregar(string);
    string toString();
    bool validarPalabra(string);
    bool validarPalabraTablero();
private:
    string* palabras;
    int cantidad;
    int tamano;
    jugador* palabra;
    tablero**** ptrTablero;
};
#endif /* DICCIONARIO_H */