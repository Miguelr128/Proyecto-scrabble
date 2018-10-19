#ifndef CASILLA_H
#define CASILLA_H

#include "ficha.h"

class casilla {
public:
    casilla(int);
    virtual ~casilla();
private:
    int valorCasilla;
    ficha* fichaColocada;
};
#endif /* CASILLA_H */