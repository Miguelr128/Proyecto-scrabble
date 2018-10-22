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

string casilla::toString(){
    stringstream s;
    s<<colorCasilla;
    return s.str();
}

casilla::~casilla() {
}