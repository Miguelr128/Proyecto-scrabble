#include <cstdlib>

#include "ficha.h"

ficha::ficha(string letra, int valorLetra) : letra(letra), valorLetra(valorLetra), letraComodin(false) {
}

void ficha::setLetra(string le){
    letra = le;
}

void ficha::setLetraComodin(bool a){
    letraComodin = a;
}

void ficha::setValorLetra(int v){
    valorLetra = v;
}

string ficha::getLetra(){
    return letra;
}

string ficha::toString(){
    stringstream s;
    s<<"letra: "<<letra<<endl;
    s<<"valor: "<<valorLetra<<endl;
    return s.str();
}

ficha::~ficha() {
}