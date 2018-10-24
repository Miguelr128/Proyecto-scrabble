#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "jugador.h"

class diccionario {
public:
    diccionario(int);
    virtual ~diccionario();
    void agregar(string);
    string toString();
//    bool validarPalabra();
private:
    string* palabras;
    int cantidad;
    int tamano;
    
//    jugador* palabra;
};
#endif /* DICCIONARIO_H */