#include "diccionario.h"

diccionario::diccionario(int a): tamano(a), cantidad(0), palabras(new string[a]) {
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
    for (int i = 0; i < 1000; i++) {
        palabra = palabras[i];
        strcpy(letrasDiccionario, palabra.c_str());
        if (strcmp(letrasDiccionario, letrasComparando) == 0)
            return true;
    }
    return false;
}

diccionario::~diccionario() {
}