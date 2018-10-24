#ifndef VECTORFICHAJUGADOR_H
#define VECTORFICHAJUGADOR_H

#include <cstdlib>

#include "ficha.h"
#include "vectorficha.h"

class vectorfichajugador {
public:
    vectorfichajugador(int, vectorficha*);
    virtual ~vectorfichajugador();
    void primerasFichas();
    void cambiar(int);
private:
    int tamano;
    int cantidad;
    ficha** vector;
    vectorficha* fichasSistema;
};
#endif /* VECTORFICHAJUGADOR_H */