#ifndef CASILLA_H
#define CASILLA_H

#include <sstream>
using namespace std;

#include "ficha.h"

class casilla {
public:
    casilla(char);
    void setColor(char);
    string toString();
    virtual ~casilla();
private:
    char colorCasilla;
    ficha* fichaColocada;
};
#endif /* CASILLA_H */