#include "diccionario.h"

diccionario::diccionario(int a, tablero* tab): tamano(a), cantidad(0), palabras(new string[a]), ptrTablero(tab) {
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

bool diccionario::validarPalabraTableroA() {
    string aux = "";
    int cont = 0;
    for (int i = 0; i < 13; i++)
        for (int e = 0; e < 13; e++)
            if (ptrTablero->getFicha(i, e) != NULL) {
                for (int x = 0; x < 13; x++) {
                    if (ptrTablero->getFicha(x, e) != NULL && ptrTablero->getFicha(x + 1, e) != NULL) {
                        aux = aux + ptrTablero->getFicha(x, e)->getLetra();
                    }
                    cont = x;
                }
                aux = aux + ptrTablero->getFicha(cont, e)->getLetra();
                if (validarPalabra(aux) == true)
                    return true;
                int z = cont + 1;
                for (int z; z < 13; z++) {
                    if (ptrTablero->getFicha(z, e) != NULL && ptrTablero->getFicha(z + 1, e) != NULL) {
                        aux = aux + ptrTablero->getFicha(z, e)->getLetra();
                    }
                    cont = z;
                }
                aux = aux + ptrTablero->getFicha(cont, e)->getLetra();
                if (validarPalabra(aux) == true)
                    return true;
            }
    return false;
}

bool diccionario::validarPalabraTableroI() {
    string aux = "";
    int cont = 0;
    for (int i = 0; i < 13; i++)
        for (int e = 0; e < 13; e++)
            if (ptrTablero->getFicha(i, e) != NULL) {
                for (int x = 0; x < 13; x++) {
                    if (ptrTablero->getFicha(i, x) != NULL && ptrTablero->getFicha(i, x + 1) != NULL) {
                        aux = aux + ptrTablero->getFicha(i, x)->getLetra();
                    }
                    cont = x;
                }
                aux = aux + ptrTablero->getFicha(i, cont)->getLetra();
                if (validarPalabra(aux) == true)
                    return true;
                int z = cont + 1;
                for (int z; z < 13; z++) {
                    if (ptrTablero->getFicha(i, z) != NULL && ptrTablero->getFicha(i, z + 1) != NULL) {
                        aux = aux + ptrTablero->getFicha(i, z)->getLetra();
                    }
                    cont = z;
                }
                aux = aux + ptrTablero->getFicha(i, cont)->getLetra();
                if (validarPalabra(aux) == true)
                    return true;
            }
    return false;
}

diccionario::~diccionario() {
}