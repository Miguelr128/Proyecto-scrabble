#include "diccionario.h"

diccionario::diccionario(int a): tamano(a), cantidad(0), palabras(new string[a]), ptrTablero (new tablero***()) {
}

void diccionario::agregar(string pa){
    palabras[cantidad++] = pa;
}

string diccionario::toString(){
    stringstream s;
    for(int i = 0; i < cantidad; i++){
        s<<palabras[i]<<endl;
    }
    return s.str();
}

bool diccionario::validarPalabra(string comparando) {
    char letrasComparando [7];
    char letrasDiccionario [20];
    string palabra;
    strcpy(letrasComparando, comparando.c_str());
    for (int i = 0; i < cantidad; i++) {
        palabra = palabras[i];
        strcpy(letrasDiccionario, palabra.c_str());
        if (strcmp(letrasDiccionario, letrasComparando) == 0)
            return true;
    }
    return false;
}

bool diccionario::validarPalabraTablero() {
//    string aux = "";
//    for (int i=0; i<13; i++)
//        for (int e=0; e<13; e++)
//            if (ptrTablero[i][e] != NULL) {
//                for (int x=0; x<13; x++)
//                    if (ptrTablero[x][e] != NULL) {
//                        aux = aux + ptrTablero[x][e]->getCasillas()->getFicha()->getLetra();
//                    }
//            }
}

diccionario::~diccionario() {
}