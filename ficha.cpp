#include <cstdlib>

#include "ficha.h"

ficha::ficha(char letra, int valorLetra) : letra(letra), valorLetra(valorLetra), letraComodin(false) {
}

void ficha::setLetra(char le){
    letra = le;
}

void ficha::setLetraComodin(bool a){
    letraComodin = a;
}

void ficha::setValorLetra(int v){
    valorLetra = v;
}

string ficha::toString(){
    stringstream s;
    s<<"letra: "<<letra<<endl;
    s<<"valor: "<<valorLetra<<endl;
    return s.str();
}

ficha::~ficha() {
}