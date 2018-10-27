#ifndef VECTORFICHAJUGADOR_H
#define VECTORFICHAJUGADOR_H

#include <cstdlib>
#include <time.h>

#include "ficha.h"
#include "vectorficha.h"

class vectorfichajugador {
public:
    vectorfichajugador(int, vectorficha*);
    virtual ~vectorfichajugador();
    void primerasFichas();
    void nuevasFichas();
    void cambiar(int);
    void cambiarComodin(int, string);
    ficha* buscarFicha(int);
    string toString();
    void eliminar(int);
private:
    int tamano;
    int cantidad;
    ficha** vector;
    vectorficha* fichasSistema;
};
#endif /* VECTORFICHAJUGADOR_H */