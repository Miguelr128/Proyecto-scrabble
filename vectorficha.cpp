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

char vectorficha::getFicha(int i){
    return ptrFicha[i]->getLetra();
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

void vectorficha::eliminarFicha(int ficha) {
    if(ptrFicha[ficha] != NULL){
        for(int i = ficha; i < cantidad-1;i++){
            ptrFicha[i] = ptrFicha[i+1];
        }
        cantidad --;
    }
}