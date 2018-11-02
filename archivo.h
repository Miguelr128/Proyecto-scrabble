#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
using namespace std;

#include "jugador.h"

class archivo {
public:
    archivo();
    virtual ~archivo();
    void guardarPalabras(string, jugador*);
    void guardarPuntaje(int, jugador*);
//    void leer();
};
#endif /* ARCHIVO_H */