#include <cstdlib>

#include "vectorficha.h"

vectorficha::vectorficha() : tamano(100), cantidad(0), ptrFicha(new ficha* [tamano]) {
    for (int i = 0; i < tamano; i++)
        ptrFicha[i] = new ficha(NULL, 0);
}

vectorficha::~vectorficha() {
}

vectorficha::vectorficha(int tamano) : tamano(tamano), cantidad(0), ptrFicha(new ficha* [this->tamano]) {
}