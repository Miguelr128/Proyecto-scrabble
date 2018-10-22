#ifndef VECTORFICHAJUGADOR_H
#define VECTORFICHAJUGADOR_H

#include <cstdlib>

#include "vectorficha.h"

class vectorfichajugador {
public:
    vectorfichajugador();
    virtual ~vectorfichajugador();
    void pasarFichas(vectorficha**&);
private:
    int tamano;
    int cantidad;
    vectorficha* vector[7];
};
#endif /* VECTORFICHAJUGADOR_H */