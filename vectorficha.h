#ifndef VECTORFICHA_H
#define VECTORFICHA_H

#include "ficha.h"

class vectorficha {
public:
    vectorficha();
    virtual ~vectorficha();
    void setFicha(int, char);
    void setValor(int, int);
    char getFicha(int);
    string toString();
    void eliminarFicha(int);
private:
    int tamano;
    int cantidad;
    ficha** ptrFicha;
};
#endif /* VECTORFICHA_H */