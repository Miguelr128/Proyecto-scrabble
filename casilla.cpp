#include <cstdlib>

#include "casilla.h"

casilla::casilla(char _colorCasilla) : colorCasilla(_colorCasilla), fichaColocada(NULL) {
}

void casilla::setColor(char c){
    colorCasilla = c;
}

string casilla::toString(){
    stringstream s;
    s<<colorCasilla;
    return s.str();
}

casilla::~casilla() {
}