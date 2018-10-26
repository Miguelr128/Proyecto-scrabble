#include <cstdlib>

#include "casilla.h"

casilla::casilla(char _colorCasilla) : colorCasilla(_colorCasilla), fichaColocada(NULL) {
}

void casilla::setColor(char c){
    colorCasilla = c;
}

char casilla::getColor(){
    return colorCasilla;
}

ficha* casilla::getFicha(){
    return fichaColocada;
}

int casilla::getPuntos(){
    return fichaColocada->getValorLetra();
}

void casilla::setFicha(ficha* f){
    fichaColocada = f;
}

string casilla::toString(){
    stringstream s;
    if(fichaColocada == NULL){
        s<<"-";
    }
    else
        s<<fichaColocada->toString();
    return s.str();
}

void casilla::duplicarValorFicha(){
    int valor;
    if(colorCasilla == 'A'){
        valor = fichaColocada->getValorLetra()*3;
        fichaColocada->setValorLetra(valor);
    }
    else
        if(colorCasilla == 'R'){
            valor = fichaColocada->getValorLetra()*2;
        fichaColocada->setValorLetra(valor);
        }
}

void casilla::duplicarValorPalabra(){    
}

casilla::~casilla() {
}