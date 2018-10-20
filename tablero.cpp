#include "tablero.h"

tablero::tablero(int f, int c) : filas(f), columnas(c), casillas(new casilla**[f]) {
    for (int i = 0; i < filas; i++) {
        casillas[i] = new casilla*[columnas];
    }
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        casillas[i][j] = new casilla('G');
        }
    }
    rosado();
    amarillo();
    azul();
    verde();
}

void tablero::rosado(){
    casillas[0][0]->setColor('R');
    casillas[0][7]->setColor('R');
    casillas[0][11]->setColor('R');
    casillas[1][10]->setColor('R');
    casillas[2][9]->setColor('R');
    casillas[3][8]->setColor('R');
    casillas[5][6]->setColor('R');
    casillas[6][5]->setColor('R');
    casillas[7][4]->setColor('R');
}

void tablero::amarillo(){
    casillas[1][2]->setColor('A');
    casillas[2][3]->setColor('A');
    casillas[3][4]->setColor('A');
    casillas[4][5]->setColor('A');
    casillas[6][7]->setColor('A');
    casillas[7][8]->setColor('A');
}

void tablero::azul(){
    casillas[0][12]->setColor('B');
    casillas[3][10]->setColor('B');
    casillas[4][7]->setColor('B');
    casillas[5][4]->setColor('B');
    casillas[7][0]->setColor('B');
}

void tablero::verde(){
    casillas[1][4]->setColor('V');
    casillas[4][2]->setColor('V');
    casillas[7][12]->setColor('V');
}

tablero::~tablero() {
}

string tablero::toString() const {
    stringstream s;
    s << "";
    for (int m = 0; m < columnas; m++) {
        s << "\t " << m << "  ";
    }
    s << endl;
    for (int i = 0; i < filas; i++) {
        s << i << " ";
        for (int j = 0; j < columnas; j++) {
            s << "\t" << "[" << casillas[i][j]->toString() << "]";
        }
        s << endl;
    }
    return s.str();
}