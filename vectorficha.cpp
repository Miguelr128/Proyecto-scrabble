#include <cstdlib>

#include "vectorficha.h"

vectorficha::vectorficha() : tamano(100), cantidad(100), ptrFicha(new ficha* [tamano]) {
    for (int i = 0; i < tamano; i++)
        ptrFicha[i] = new ficha(' ', 0);
}

void vectorficha::setFicha(int i, char c){
    ptrFicha[i]->setLetra(c);
}

void vectorficha::setValor(int i, int v){
    ptrFicha[i]->setValorLetra(v);
}

vectorficha::~vectorficha() {
}

string vectorficha::toString() {
    stringstream s;
    for(int i = 0; i < cantidad; i++){
        s<<ptrFicha[i]->toString()<<endl;
    }
    return s.str();
}

void vectorficha::eliminarFicha(ficha*& ficha) {
    if (buscarFicha(ficha) != false) {
        int posFicha = buscarFicha(ficha);
        for (int i = cantidad; i = posFicha; i--) {
            ptrFicha[cantidad - 1] = ptrFicha[cantidad];
            cantidad --;
        }
    }
}

int vectorficha::buscarFicha(ficha* fichaEnBusca) {
    for (int i = 0; i < cantidad; i++)
        if (fichaEnBusca == ptrFicha[i])
            return i;
        else
            return false;
}