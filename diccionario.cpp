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
    bool a = true;
    int i =0;
    while (a == true && i < 13) {
        for (i = 0; i < 13; i++)
            for (int e = 0; e < 13; e++)
                if (ptrTablero->getFicha(i, e) != NULL) {
                    for (int x = 0; x < 13; x++) {
                        if (ptrTablero->getFicha(x, e) != NULL && ptrTablero->getFicha(x + 1, e) != NULL) {
                            aux = aux + ptrTablero->getFicha(x, e)->getLetra();
                        }
                        cont = x;
                    }
                    aux = aux + ptrTablero->getFicha(cont, e)->getLetra();
                    if (validarPalabra(aux) == false)
                        a = false;
                }
    }
    return a;
}

bool diccionario::validarPalabraTableroI() {
    string aux = "";
    int cont = 0;
    bool a = true;
    int e =0;
    while (a == true && e < 13) {
        for (int i = 0; i < 13; i++)
            for (e = 0; e < 13; e++)
                if (ptrTablero->getFicha(i, e) != NULL) {
                    for (int x = 0; x < 13; x++) {
                        if (ptrTablero->getFicha(i, x) != NULL && ptrTablero->getFicha(i, x + 1) != NULL) {
                            aux = aux + ptrTablero->getFicha(i, x)->getLetra();
                        }
                        cont = x;
                    }
                    aux = aux + ptrTablero->getFicha(i, cont)->getLetra();
                    if (validarPalabra(aux) == false)
                        a = false;
                }
    }
    return a;
}

diccionario::~diccionario() {
}