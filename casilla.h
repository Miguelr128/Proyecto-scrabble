#ifndef CASILLA_H
#define CASILLA_H

#include <sstream>
using namespace std;

#include "ficha.h"

class casilla {
public:
    casilla(char);
    char getColor();
    ficha* getFicha();
    int getPuntos();
    string getLetra();
    void setColor(char);
    void setFicha(ficha*);
    void duplicarValorFicha();
    string toString();
    virtual ~casilla();
private:
    char colorCasilla;
    ficha* fichaColocada;
};
#endif /* CASILLA_H */