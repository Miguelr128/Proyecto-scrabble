using namespace std;
#include "tablero.h"

tablero::tablero() : filas(13), columnas(13), casillas(new casilla**[13]) {
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

casilla*** tablero::getCasillas() {
    return casillas;
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

void tablero::duplicarValorPalabra() {
    int duplicado;
    int suma = 0;
    for (int i = 0; i < filas; i++)
        for (int e = 0; e < columnas; e++)
            if ((casillas[i][e] != NULL) && (casillas[i][e+1] != NULL) && (casillas[i][e] -> getColor() == 'B'))
                for (int x = 0; x < columnas; x++) {
                    while (casillas [i][e + x] != NULL) {
                    suma = suma + casillas [i][e + x] -> getFicha() -> getValorLetra();
                    duplicado = suma * 3;
                    }
                }
            else if ((casillas[i][e] != NULL) && (casillas[i][e - 1] != NULL) && (casillas[i][e] -> getColor() == 'B'))
                for (int x = e; x > 0; x--) {
                    while (casillas [i][e - (e - x)] != NULL) {
                        suma = suma + casillas [i][e - (e- x)] -> getFicha() -> getValorLetra();
                        duplicado = suma * 3;
                    }
                }
            else if ((casillas[i][e] != NULL) && (casillas[i+1][e] != NULL) && (casillas[i][e] -> getColor() == 'B'))
                for (int x = 0; x < filas; x++) {
                    while (casillas [i + x][e] != NULL) {
                        suma = suma + casillas [i + x][e] -> getFicha() -> getValorLetra();
                        duplicado = suma * 3;
                    }
                }
            else if ((casillas[i][e] != NULL) && (casillas[i - 1][e] != NULL) && (casillas[i][e] -> getColor() == 'B'))
                for (int x = 0; x < filas; x++) {
                    while (casillas [i - (i - x)][e] != NULL) {
                        suma = suma + casillas [i - (i - x)][e] -> getFicha() -> getValorLetra();
                        duplicado = suma * 3;
                    }
                }
            else if ((casillas[i][e] != NULL) && (casillas[i][e+1] != NULL) && (casillas[i][e] -> getColor() == 'V'))
                for (int x = 0; x < columnas; x++) {
                    while (casillas [i][e + x] != NULL) {
                    suma = suma + casillas [i][e + x] -> getFicha() -> getValorLetra();
                    duplicado = suma * 2;
                    }
                }
            else if ((casillas[i][e] != NULL) && (casillas[i][e - 1] != NULL) && (casillas[i][e] -> getColor() == 'V'))
                for (int x = e; x > 0; x--) {
                    while (casillas [i][e - (e - x)] != NULL) {
                        suma = suma + casillas [i][e - (e- x)] -> getFicha() -> getValorLetra();
                        duplicado = suma * 2;
                    }
                }
            else if ((casillas[i][e] != NULL) && (casillas[i+1][e] != NULL) && (casillas[i][e] -> getColor() == 'V'))
                for (int x = 0; x < filas; x++) {
                    while (casillas [i + x][e] != NULL) {
                        suma = suma + casillas [i + x][e] -> getFicha() -> getValorLetra();
                        duplicado = suma * 2;
                    }
                }
            else if ((casillas[i][e] != NULL) && (casillas[i - 1][e] != NULL) && (casillas[i][e] -> getColor() == 'V'))
                for (int x = 0; x < filas; x++) {
                    while (casillas [i - (i - x)][e] != NULL) {
                        suma = suma + casillas [i - (i - x)][e] -> getFicha() -> getValorLetra();
                        duplicado = suma * 2;
                    }
                }
}

tablero::~tablero() {
}

void tablero::reservarPosicion(int i, int j, ficha* f) {
    casillas[i][j]->setFicha(f);
}

int tablero::contarPuntos(int i, int j) {
    int fila = i, columna = j;
    int puntaje = casillas[fila][columna]->getPuntos();
    if (casillas[fila - 1][columna]->getFicha() != NULL) {
        while (casillas[fila - 1][columna]->getFicha() != NULL) {
            puntaje = puntaje + casillas[fila - 1][columna]->getPuntos();
            fila--;
        }
        fila = i;
    }
    if (casillas[fila + 1][columna]->getFicha() != NULL) {
        while (casillas[fila + 1][columna]->getFicha() != NULL) {
            puntaje = puntaje + casillas[fila + 1][columna]->getPuntos();
            fila++;
        }
        fila = i;
    }
    else{
        if(casillas[fila][columna - 1]->getFicha() != NULL){
            while(casillas[fila][columna - 1]->getFicha() != NULL){
                puntaje = puntaje + casillas[fila][columna - 1]->getPuntos();
                columna--;
            }
        columna = j;
        }
        if(casillas[fila][columna + 1]->getFicha() != NULL){
           while(casillas[fila][columna + 1]->getFicha() != NULL){
                puntaje = puntaje + casillas[fila][columna + 1]->getPuntos();
                columna++;
            } 
        }
    }
    return puntaje;
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