#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include "jugador.h"

class archivo {
public:
    archivo();
    virtual ~archivo();
private:
    fstream fout;
};
#endif /* ARCHIVO_H */