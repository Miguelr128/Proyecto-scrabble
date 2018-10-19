#ifndef VECTORFICHA_H
#define VECTORFICHA_H

#include "ficha.h"

class vectorficha {
public:
    vectorficha();
    virtual ~vectorficha();
    vectorficha(int);
private:
    int tamano;
    int cantidad;
    ficha** ptrFicha;
};
#endif /* VECTORFICHA_H */