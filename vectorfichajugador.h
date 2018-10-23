#ifndef VECTORFICHAJUGADOR_H
#define VECTORFICHAJUGADOR_H

#include <cstdlib>

#include "vectorficha.h"

class vectorfichajugador {
public:
    vectorfichajugador(int);
    virtual ~vectorfichajugador();
    void pasarFichas(vectorficha*);
private:
    int tamano;
    int cantidad;
    char* vector;
};
#endif /* VECTORFICHAJUGADOR_H */